#include "colorsystemfield.h"
#include "QDebug"

colorSystemField::colorSystemField(QWidget *parent, colorSystemSlider *control_slider, qreal _left, qreal _right, qreal _id) :
    QLineEdit(parent), fieldId(_id), leftThreshold(_left), rightThreshold(_right), slider(control_slider)
{
    slider -> setVisible(false);
    connect(this, &QLineEdit::returnPressed, this, &colorSystemField::EnterPressed);
    connect(this, &QLineEdit::textChanged, this, &colorSystemField::ChangeValueText);
    QString warningMessage = "This field must be in range [" + QString::number(leftThreshold) + "," + QString::number(rightThreshold) + "] with max two digits after comma";
    connect(this, &QLineEdit::inputRejected, this, [this, warningMessage](){QMessageBox::warning(this, "Error", warningMessage);});
    QDoubleValidator *val = new QDoubleValidator(leftThreshold, rightThreshold, 2, this);
    setValidator(val);
    ChangeValue(0);
}
void colorSystemField::EnterPressed()
{
    slider -> setVisible(false);
    clearFocus();
}
qreal colorSystemField::getValue() const
{
    return value;
}
void colorSystemField::ChangeValue(qreal newValue)
{
    value = newValue;
    blockSignals(true);
    QString s = QString::number((int)(value * 100) / 100.0);
    setText(s.replace('.', ','));
    if (slider -> GetActiveField() == this)
    {
        slider -> setValue((int)(value * 100));
    }
    blockSignals(false);
}
void colorSystemField::ChangeValueText(const QString& newValue)
{
    bool ok;
    double parsedDouble = newValue.toDouble(&ok);
    if (ok)
    {
        if (parsedDouble > rightThreshold)
        {
            parsedDouble = rightThreshold;
        }
        if (parsedDouble < leftThreshold)
        {
            parsedDouble = leftThreshold;
        }
        ChangeValue(parsedDouble);
        emit valueChanged(value, fieldId);
    }
}
void colorSystemField::ChangeValueFromSlider(int newValue)
{
    ChangeValue(newValue / 100.0);
    emit valueChanged(value, fieldId);
}
void colorSystemField::mousePressEvent(QMouseEvent *)
{
    if (slider -> GetActiveField())
    {
        slider -> ClearActiveField();
    }
    slider -> ChangeActiveField(this);
    slider -> setVisible(true);
    slider -> setRange((int)(leftThreshold * 100), (int)(rightThreshold * 100));
    slider -> setValue(value * 100);
    connect(slider, &QSlider::sliderReleased, this, &colorSystemField::setActive);
    connect(slider, &QSlider::valueChanged, this, &colorSystemField::ChangeValueFromSlider);
    emit sliderActivated();
}
void colorSystemField::setActive()
{
    setFocus();
}
colorSystemSlider::colorSystemSlider(QWidget *parent) : QSlider(Qt::Horizontal, parent)
{
    setTracking(true);
}
colorSystemField* colorSystemSlider::GetActiveField() const
{
    return activeField;
}
void colorSystemSlider::ClearActiveField()
{
    disconnect(this, &QSlider::sliderReleased, GetActiveField(), &colorSystemField::setActive);
    disconnect(this, &QSlider::valueChanged, GetActiveField(), &colorSystemField::ChangeValueFromSlider);
    activeField = nullptr;
}
void colorSystemSlider::ChangeActiveField(colorSystemField *new_field)
{
    activeField = new_field;
}
