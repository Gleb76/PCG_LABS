/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *centralwidget;
    QComboBox *selectModel;
    QPushButton *chooseColorButton;
    QFrame *colorShowcase;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        centralwidget = new QWidget(Widget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        selectModel = new QComboBox(centralwidget);
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->addItem(QString());
        selectModel->setObjectName(QString::fromUtf8("selectModel"));
        selectModel->setGeometry(QRect(510, 80, 221, 41));
        QFont font;
        font.setPointSize(10);
        selectModel->setFont(font);
        chooseColorButton = new QPushButton(centralwidget);
        chooseColorButton->setObjectName(QString::fromUtf8("chooseColorButton"));
        chooseColorButton->setGeometry(QRect(560, 360, 131, 41));
        chooseColorButton->setFont(font);
        colorShowcase = new QFrame(centralwidget);
        colorShowcase->setObjectName(QString::fromUtf8("colorShowcase"));
        colorShowcase->setGeometry(QRect(510, 180, 221, 161));
        colorShowcase->setFrameShape(QFrame::Box);
        colorShowcase->setFrameShadow(QFrame::Raised);
        Widget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Widget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Widget->setMenuBar(menubar);
        statusbar = new QStatusBar(Widget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Widget->setStatusBar(statusbar);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QMainWindow *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        selectModel->setItemText(0, QCoreApplication::translate("Widget", "RGB <-> LAB <-> CMYK", nullptr));
        selectModel->setItemText(1, QCoreApplication::translate("Widget", "RGB <-> CMYK <-> HLS", nullptr));
        selectModel->setItemText(2, QCoreApplication::translate("Widget", "RGB <-> XYZ <-> LAB", nullptr));
        selectModel->setItemText(3, QCoreApplication::translate("Widget", "RGB <-> HSV <-> LAB", nullptr));
        selectModel->setItemText(4, QCoreApplication::translate("Widget", "CMYK <-> LAB <-> HSV", nullptr));
        selectModel->setItemText(5, QCoreApplication::translate("Widget", "CMYK <-> RGB <-> HLS", nullptr));
        selectModel->setItemText(6, QCoreApplication::translate("Widget", "CMYK <-> RGB <-> HSV", nullptr));
        selectModel->setItemText(7, QCoreApplication::translate("Widget", "RGB <-> XYZ <-> HSV", nullptr));
        selectModel->setItemText(8, QCoreApplication::translate("Widget", "HSV <-> XYZ <-> LAB", nullptr));
        selectModel->setItemText(9, QCoreApplication::translate("Widget", "CMYK <-> LAB <-> RGB", nullptr));
        selectModel->setItemText(10, QCoreApplication::translate("Widget", "XYZ <-> LAB <-> HLS", nullptr));
        selectModel->setItemText(11, QCoreApplication::translate("Widget", "RGB <-> XYZ <-> HLS", nullptr));
        selectModel->setItemText(12, QCoreApplication::translate("Widget", "RGB <-> XYZ <-> CMYK", nullptr));
        selectModel->setItemText(13, QCoreApplication::translate("Widget", "CMYK <-> LAB <-> XYZ", nullptr));
        selectModel->setItemText(14, QCoreApplication::translate("Widget", "RGB <-> CMYK <-> HSV", nullptr));
        selectModel->setItemText(15, QCoreApplication::translate("Widget", "CMYK <-> HLS <-> XYZ", nullptr));
        selectModel->setItemText(16, QCoreApplication::translate("Widget", "RGB <-> HLS <-> LAB", nullptr));
        selectModel->setItemText(17, QCoreApplication::translate("Widget", "CMYK <-> XYZ <-> RGB", nullptr));

        chooseColorButton->setText(QCoreApplication::translate("Widget", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
