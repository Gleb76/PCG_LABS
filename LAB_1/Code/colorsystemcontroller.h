#pragma once
#include "colorsystem.h"
#include <QBoxLayout>
#include <QStatusBar>

class colorSystemController : public QWidget
{
    Q_OBJECT
public:
    colorSystemController(QWidget *parent, const std::vector<ColorSystem>& data, QWidget *displayWidget, QStatusBar *_statusBar);
    QColor getMainColor() const;
    void setMainColor(const QColor& newColor);
    void updateMainColor();
    void ChangeSystems(const std::vector<ColorSystem>& data);
    void ChangeSystemValues(const std::vector<qreal>& newValues, int systemId);
    ~colorSystemController();
public slots:
    void OnChangeSystemValues(const std::vector<qreal>& newValues, int systemId);
    void OnSystemSliderActivated(int systemId);
private:
    std::vector<qreal> fromXYZtoRGB(const std::vector<qreal>& xyzValues) const;
    std::vector<qreal> fromRGBtoXYZ(const std::vector<qreal>& rgbValues) const;
    std::vector<qreal> fromLABtoXYZ(const std::vector<qreal>& labValues) const;
    std::vector<qreal> fromXYZtoLAB(const std::vector<qreal>& xyzValues) const;
    std::vector<qreal> mainXYZvalues;
    QWidget *colorDisplayWidget;
    QStatusBar *statusBar;
    QVBoxLayout *vLayout = nullptr;
    colorSystem *systems[3];
    QPalette *selectedColorPalette;
};

