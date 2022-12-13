#include "colorsystemcontroller.h"
#include <QDebug>
#include <QtMath>

colorSystemController::colorSystemController(QWidget *parent, const std::vector<ColorSystem>& data, QWidget *displayWidget, QStatusBar *_statusBar):
    QWidget(parent), colorDisplayWidget(displayWidget), statusBar(_statusBar)
{
    selectedColorPalette = new QPalette;
    setMainColor(Qt::white);
    vLayout = nullptr;
    for (int i = 0; i < 3; i++)
    {
        systems[i] = nullptr;
    }
    mainXYZvalues = {95.047, 100, 108.883};
    ChangeSystems(data);
}
void colorSystemController::ChangeSystems(const std::vector<ColorSystem>& data)
{
    if (vLayout)
        delete vLayout;
    vLayout = new QVBoxLayout(this);
    for (int i = 0; i < 3; i++)
    {
        if (systems[i])
        {
            disconnect(systems[i], &colorSystem::systemValueChanged, this, &colorSystemController::OnChangeSystemValues);
            disconnect(systems[i], &colorSystem::systemSliderActivated, this, &colorSystemController::OnSystemSliderActivated);
            delete systems[i];
        }
        switch (data[i])
        {
            case ColorSystem::RGB:
                systems[i] = new RGBSystem(this, i);
            break;
            case ColorSystem::CMYK:
                systems[i] = new CMYKSystem(this, i);
            break;
            case ColorSystem::HSV:
                systems[i] = new HSVSystem(this, i);
            break;
            case ColorSystem::HSL:
                systems[i] = new HSLSystem(this, i);
            break;
            case ColorSystem::XYZ:
                systems[i] = new XYZSystem(this, i);
            break;
            case ColorSystem::LAB:
                systems[i] = new LABSystem(this, i);
        }
        vLayout->addWidget(systems[i]);
        connect(systems[i], &colorSystem::systemValueChanged, this, &colorSystemController::OnChangeSystemValues);
        connect(systems[i], &colorSystem::systemSliderActivated, this, &colorSystemController::OnSystemSliderActivated);
    }
    QColor color = getMainColor();
    OnChangeSystemValues({color.redF(), color.greenF(), color.blueF()}, -1);
}
QColor colorSystemController::getMainColor() const
{
    auto mainRGBvalues = fromXYZtoRGB(mainXYZvalues);
    QColor c;
    c.setRgbF(mainRGBvalues[0], mainRGBvalues[1], mainRGBvalues[2]);
    return c;
}
void colorSystemController::OnSystemSliderActivated(int systemId)
{
    for(int i = 0; i < 3; i++)
    {
        if (i != systemId)
        {
            systems[i] -> DisableSlider();
        }
    }
}
//accepts rgb values in range [0.1]
std::vector<qreal> colorSystemController::fromRGBtoXYZ(const std::vector<qreal> &rgbValues) const
{
    qreal R = rgbValues[0], G = rgbValues[1], B = rgbValues[2];
    auto F = [](qreal x)
    {
      if (x > 0.04045)
      {
          return qPow((x + 0.055) / 1.055, 2.4);
      }
      else return x / 12.92;
    };
    qreal Rn = F(R) * 100, Gn = F(G) * 100, Bn = F(B) * 100;
    qreal X, Y, Z;
    X = 0.412453 * Rn + 0.357580 * Gn + 0.180423 * Bn;
    Y = 0.212671 * Rn + 0.715160 * Gn + 0.072169 * Bn;
    Z = 0.019334 * Rn + 0.119193 * Gn + 0.950227 * Bn;
    return {X, Y, Z};
}
std::vector<qreal> colorSystemController::fromXYZtoRGB(const std::vector<qreal> &xyzValues) const
{
    qreal X = xyzValues[0] / 100, Y = xyzValues[1] / 100, Z = xyzValues[2] / 100;
    auto F = [](qreal x)
    {
      if (x >= 0.0031308)
      {
          return qPow(x, 1 / 2.4) * 1.055 - 0.055;
      }
      else return x * 12.92;
    };
    qreal Rn = 3.2406 * X - 1.5372 * Y - 0.4986 * Z;
    qreal Gn = -0.9689 * X + 1.8758 * Y + 0.0415 * Z;
    qreal Bn = 0.0557 * X - 0.2040 * Y + 1.0570 * Z;
    qreal R = F(Rn), G = F(Gn), B = F(Bn);
    qreal eps = 10e-4;
    auto N = [this, eps](qreal &x, const QString& component)
    {
        if (x - 1 > eps)
        {
            statusBar -> showMessage(component + " component of this RGB color represantation is out of displayable range. Maximal value is used instead", 4000);
            return 1.0;
        }
        if (x < -eps)
        {
            statusBar -> showMessage(component + " component of this RGB color representation is out of displayable range. Minimal value is used instead", 4000);
            return 0.0;
        }
        return x;
    };
    return {N(R, "Red"), N(G, "Green"), N(B, "Blue")};
}
std::vector<qreal> colorSystemController::fromLABtoXYZ(const std::vector<qreal>& labValues) const
{
    qreal L = labValues[0], A = labValues[1], B = labValues[2];
    auto F = [](qreal x)
    {
        if (x * x * x >= 0.008856)
        {
            return x * x * x;
        }
        else
        {
            return (x - 16.0 / 116) / 7.787;
        }
    };
    qreal Xw = 95.047, Yw = 100, Zw = 108.883;
    qreal X, Y, Z;
    X = F(A / 500.0 + (L + 16.0) / 116.0) * Xw;
    Y = F((L + 16) / 116.0) * Yw;
    Z = F((L + 16) / 116.0 - B / 200.0) * Zw;
    return {X, Y, Z};
}
std::vector<qreal> colorSystemController::fromXYZtoLAB(const std::vector<qreal>& xyzValues) const
{
    qreal X = xyzValues[0], Y = xyzValues[1], Z = xyzValues[2];
    auto F = [](qreal x)
    {
        if (x >= 0.008856)
        {
            return qPow(x, 1.0 / 3);
        }
        else
        {
            return 7.787 * x + 16.0 / 116;
        }
    };
    qreal Xw = 95.047, Yw = 100, Zw = 108.883;
    qreal L, A, B;
    L = 116 * F(Y / Yw) - 16;
    A = 500 * (F(X / Xw) - F(Y / Yw));
    B = 200 * (F(Y / Yw) - F(Z / Zw));
    //qDebug() << fromLABtoXYZ({L, A, B});
    return {L, A, B};
}
void colorSystemController::ChangeSystemValues(const std::vector<qreal> &newXYZvalues, int systemId)
{
    auto newRGBValuesF = fromXYZtoRGB(newXYZvalues);
    QColor newColor;
    newColor.setRgbF(newRGBValuesF[0], newRGBValuesF[1], newRGBValuesF[2]);
    colorSystem *currentSystem = systems[systemId];
    switch (currentSystem->getSystemType())
    {
    case ColorSystem::RGB:
        currentSystem -> ChangeFieldValue(newColor.redF() * 255, 0);
        currentSystem -> ChangeFieldValue(newColor.greenF() * 255, 1);
        currentSystem -> ChangeFieldValue(newColor.blueF() * 255, 2);
        break;
    case ColorSystem::CMYK:
        currentSystem -> ChangeFieldValue(newColor.cyanF() * 255, 0);
        currentSystem -> ChangeFieldValue(newColor.magentaF() * 255, 1);
        currentSystem -> ChangeFieldValue(newColor.yellowF() * 255, 2);
        currentSystem -> ChangeFieldValue(newColor.blackF() * 255, 3);
        break;
    case ColorSystem::HSL:
        currentSystem -> ChangeFieldValue(newColor.hslHueF()  * 360, 0);
        currentSystem -> ChangeFieldValue(newColor.hslSaturationF() * 255, 1);
        currentSystem -> ChangeFieldValue(newColor.lightnessF() * 255, 2);
        break;
    case ColorSystem::HSV:
        currentSystem -> ChangeFieldValue(newColor.hueF() * 360, 0);
        currentSystem -> ChangeFieldValue(newColor.saturationF() * 255, 1);
        currentSystem -> ChangeFieldValue(newColor.valueF() * 255, 2);
        break;
    case ColorSystem::XYZ:
    {
        currentSystem -> ChangeFieldValue(newXYZvalues[0], 0);
        currentSystem -> ChangeFieldValue(newXYZvalues[1], 1);
        currentSystem -> ChangeFieldValue(newXYZvalues[2], 2);
        break;
    }
    case ColorSystem::LAB:
    {
        auto labValues = fromXYZtoLAB(newXYZvalues);
        currentSystem -> ChangeFieldValue(labValues[0], 0);
        currentSystem -> ChangeFieldValue(labValues[1], 1);
        currentSystem -> ChangeFieldValue(labValues[2], 2);
        break;
    }
    }
}
void colorSystemController::OnChangeSystemValues(const std::vector<qreal>& newValues, int systemId)
{
    QColor newColor;
    std::vector<qreal> newXYZvalues;
    if (systemId != -1)
    {
        switch (systems[systemId]->getSystemType())
        {
        case ColorSystem::RGB:
            newColor.setRgbF(newValues[0] / 255, newValues[1] / 255, newValues[2] / 255);
            newXYZvalues = fromRGBtoXYZ({newColor.redF(), newColor.greenF(), newColor.blueF()});
            break;
        case ColorSystem::CMYK:
            newColor.setCmykF(newValues[0] / 255, newValues[1] / 255, newValues[2] / 255, newValues[3] / 255);
            newXYZvalues = fromRGBtoXYZ({newColor.redF(), newColor.greenF(), newColor.blueF()});
            break;
        case ColorSystem::HSL:
            newColor.setHslF(newValues[0] / 360, newValues[1] / 255, newValues[2] / 255);
            newXYZvalues = fromRGBtoXYZ({newColor.redF(), newColor.greenF(), newColor.blueF()});
            break;
        case ColorSystem::HSV:
            newColor.setHsvF(newValues[0] / 360, newValues[1] / 255, newValues[2] / 255);
            newXYZvalues = fromRGBtoXYZ({newColor.redF(), newColor.greenF(), newColor.blueF()});
            break;
        case ColorSystem::XYZ:
        {
            newXYZvalues = newValues;
            break;
        }
        case ColorSystem::LAB:
        {
            newXYZvalues = fromLABtoXYZ({newValues[0], newValues[1], newValues[2]});
            break;
        }
        }
    }
    else
    {
        newXYZvalues = fromRGBtoXYZ(newValues);
    }
    for (int i = 0; i < 3; i++)
    {
        if (i != systemId)
        {
            ChangeSystemValues(newXYZvalues, i);
        }
    }
    mainXYZvalues = newXYZvalues;
    auto rgbValues = fromXYZtoRGB(newXYZvalues);
    newColor.setRgbF(rgbValues[0], rgbValues[1], rgbValues[2]);
    setMainColor(newColor);
}
void colorSystemController::setMainColor(const QColor &newColor)
{
    if (newColor.isValid())
    {
        selectedColorPalette -> setColor(QPalette::Window, newColor);
        mainXYZvalues = fromRGBtoXYZ({newColor.redF(), newColor.greenF(), newColor.blueF()});
        colorDisplayWidget -> setPalette(*selectedColorPalette);
    }
}
colorSystemController::~colorSystemController()
{
    delete vLayout;
    for (int i = 0; i < 3; i++)
    {
        delete systems[i];
    }
    delete selectedColorPalette;
}
