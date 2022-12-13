/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *a_StepByStep;
    QAction *a_Bresenham;
    QAction *a_DDA;
    QAction *a_circle;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *doubleSpinBox;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *doubleSpinBox_3;
    QSlider *horizontalSlider_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_6;
    QDoubleSpinBox *doubleSpinBox_2;
    QSlider *horizontalSlider_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_7;
    QDoubleSpinBox *doubleSpinBox_4;
    QSlider *horizontalSlider_5;
    QHBoxLayout *horizontalLayout_12;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        a_StepByStep = new QAction(MainWindow);
        a_StepByStep->setObjectName(QString::fromUtf8("a_StepByStep"));
        a_Bresenham = new QAction(MainWindow);
        a_Bresenham->setObjectName(QString::fromUtf8("a_Bresenham"));
        a_DDA = new QAction(MainWindow);
        a_DDA->setObjectName(QString::fromUtf8("a_DDA"));
        a_circle = new QAction(MainWindow);
        a_circle->setObjectName(QString::fromUtf8("a_circle"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_9 = new QVBoxLayout(centralwidget);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 780, 410));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_9->addWidget(scrollArea);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(15, 16777215));

        horizontalLayout->addWidget(label_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimum(-100.000000000000000);

        verticalLayout_2->addWidget(doubleSpinBox);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(6, 0));
        label_3->setMaximumSize(QSize(15, 16777215));
        label_3->setSizeIncrement(QSize(1, 0));
        label_3->setBaseSize(QSize(6, 0));

        horizontalLayout_3->addWidget(label_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        doubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setMinimum(-100.000000000000000);

        verticalLayout_5->addWidget(doubleSpinBox_3);

        horizontalSlider_3 = new QSlider(centralwidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_3);


        horizontalLayout_3->addLayout(verticalLayout_5);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(15, 16777215));

        horizontalLayout_4->addWidget(label_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setMinimum(-100.000000000000000);

        verticalLayout_6->addWidget(doubleSpinBox_2);

        horizontalSlider_4 = new QSlider(centralwidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(horizontalSlider_4);


        horizontalLayout_4->addLayout(verticalLayout_6);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(15, 16777215));

        horizontalLayout_5->addWidget(label_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        doubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setMinimum(-100.000000000000000);

        verticalLayout_7->addWidget(doubleSpinBox_4);

        horizontalSlider_5 = new QSlider(centralwidget);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(horizontalSlider_5);


        horizontalLayout_5->addLayout(verticalLayout_7);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_12->addWidget(comboBox);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_12->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout_12->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_12);


        verticalLayout_9->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        a_StepByStep->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\210\320\260\320\263\320\276\320\262\321\213\320\271", nullptr));
        a_Bresenham->setText(QCoreApplication::translate("MainWindow", " \320\221\321\200\320\265\320\267\320\265\320\275\321\205\321\215\320\274\320\260", nullptr));
        a_DDA->setText(QCoreApplication::translate("MainWindow", "\320\246\320\224\320\220", nullptr));
        a_circle->setText(QCoreApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\321\215\320\274\320\260(\320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "x1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "y1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "y2", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\276\321\210\320\260\320\263\320\276\320\262\321\213\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\246\320\224\320\220", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 ", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 (\320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214)", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Scale Up", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Scale Down", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
