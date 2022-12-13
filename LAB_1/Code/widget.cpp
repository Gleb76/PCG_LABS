#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QColorDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui -> colorShowcase -> setAutoFillBackground(true);

    QHBoxLayout *h = new QHBoxLayout;
    QVBoxLayout *vr = new QVBoxLayout;

    controller = new colorSystemController(this, {ColorSystem::RGB, ColorSystem::LAB, ColorSystem::CMYK}, ui -> colorShowcase, ui -> statusbar);
    normalSize = QSize(740, 270);
    ui -> selectModel -> setCurrentIndex(0);
    vr -> addWidget(ui -> selectModel);
    vr -> addWidget(ui -> colorShowcase);
    vr -> addWidget(ui -> chooseColorButton);
    h -> addWidget(controller);
    h -> addLayout(vr);
    centralWidget() -> setLayout(h);
    setWindowTitle("Color systems");
    resize(normalSize);
}

Widget::~Widget()
{
    delete ui;
    delete controller;
}

void Widget::on_chooseColorButton_clicked()
{
    QColor color = QColorDialog::getColor(controller -> getMainColor());
    if (color.isValid())
    {
        controller -> setMainColor(color);
        controller -> OnChangeSystemValues({color.redF(), color.greenF(), color.blueF()}, -1);
    }
}

void Widget::on_selectModel_currentTextChanged(const QString &arg1)
{
    auto parts = arg1.split(" <-> ");
    std::vector<ColorSystem> v;
    for (const auto& x : parts)
    {
        if (x == "RGB")
        {
            v.push_back(ColorSystem::RGB);
        }
        if (x == "CMYK")
        {
            v.push_back(ColorSystem::CMYK);
        }
        if (x == "HLS")
        {
            v.push_back(ColorSystem::HSL);
        }
        if (x == "HSV")
        {
            v.push_back(ColorSystem::HSV);
        }
        if (x == "LAB")
        {
            v.push_back(ColorSystem::LAB);
        }
        if (x == "XYZ")
        {
            v.push_back(ColorSystem::XYZ);
        }
    }
    controller->ChangeSystems(v);
    resize(normalSize);
}
