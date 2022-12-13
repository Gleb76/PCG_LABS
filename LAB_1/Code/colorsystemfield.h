#pragma once

#include <QWidget>
#include <QSlider>
#include <QLineEdit>
#include <QValidator>
#include <QMessageBox>

class colorSystemField;

class colorSystemSlider : public QSlider
{
    Q_OBJECT
public:
    explicit colorSystemSlider(QWidget *parent = nullptr);
    void ChangeActiveField(colorSystemField *new_field);
    void ClearActiveField();
    colorSystemField* GetActiveField() const;
    virtual ~colorSystemSlider(){}
private:
    colorSystemField *activeField = nullptr;
};

class colorSystemField : public QLineEdit
{
    Q_OBJECT
public:
    explicit colorSystemField(QWidget *parent = nullptr, colorSystemSlider *control_slider = nullptr, qreal _left = 0, qreal _right = 100, qreal _id = 0);
    qreal getValue() const;
    void ChangeValue(qreal newValue);
    void setActive();
    virtual ~colorSystemField(){}
public slots:
    void EnterPressed();
    void ChangeValueText(const QString& newValue);
    void ChangeValueFromSlider(int newValue);

signals:
    void valueChanged(qreal newValue, int fieldId);
    void sliderActivated();
private:
    int fieldId;
    qreal leftThreshold, rightThreshold;
    qreal value;
    colorSystemSlider *slider;
    void mousePressEvent(QMouseEvent *) override;
};

