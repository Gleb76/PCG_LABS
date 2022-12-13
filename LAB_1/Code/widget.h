#pragma once

#include <QMainWindow>
#include "colorsystemcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_chooseColorButton_clicked();

    void on_selectModel_currentTextChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    colorSystemController *controller;
    QSize normalSize;
};
