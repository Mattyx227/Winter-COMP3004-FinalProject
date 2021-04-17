/********************************************************************************
** Form generated from reading UI file 'mct_simulator.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCT_SIMULATOR_H
#define UI_MCT_SIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MCT_Simulator
{
public:
    QWidget *centralWidget;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *okButton;
    QPushButton *returnButton;
    QPushButton *menuButton;
    QPushButton *powerButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *batteryText;
    QListWidget *listWidget;
    QSlider *batterySlider;
    QTextBrowser *textBrowser;
    QCheckBox *contactBox;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MCT_Simulator)
    {
        if (MCT_Simulator->objectName().isEmpty())
            MCT_Simulator->setObjectName(QString::fromUtf8("MCT_Simulator"));
        MCT_Simulator->resize(840, 555);
        centralWidget = new QWidget(MCT_Simulator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        leftButton = new QPushButton(centralWidget);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        leftButton->setGeometry(QRect(70, 300, 51, 51));
        rightButton = new QPushButton(centralWidget);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        rightButton->setGeometry(QRect(210, 300, 51, 51));
        upButton = new QPushButton(centralWidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(140, 230, 51, 51));
        downButton = new QPushButton(centralWidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(140, 370, 51, 51));
        okButton = new QPushButton(centralWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(140, 300, 51, 51));
        returnButton = new QPushButton(centralWidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(70, 230, 51, 51));
        menuButton = new QPushButton(centralWidget);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setGeometry(QRect(210, 230, 51, 51));
        powerButton = new QPushButton(centralWidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(140, 430, 51, 51));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(49, 90, 231, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        batteryText = new QLabel(verticalLayoutWidget);
        batteryText->setObjectName(QString::fromUtf8("batteryText"));
        batteryText->setScaledContents(false);
        batteryText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(batteryText);

        listWidget = new QListWidget(verticalLayoutWidget);
        QBrush brush(QColor(52, 101, 164, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(239, 41, 41, 255));
        brush1.setStyle(Qt::NoBrush);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignCenter);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setTextAlignment(Qt::AlignCenter);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"rgb(239, 41, 41)\n"
"}"));

        verticalLayout->addWidget(listWidget);

        batterySlider = new QSlider(centralWidget);
        batterySlider->setObjectName(QString::fromUtf8("batterySlider"));
        batterySlider->setGeometry(QRect(350, 260, 381, 41));
        batterySlider->setMaximum(100);
        batterySlider->setValue(100);
        batterySlider->setSliderPosition(100);
        batterySlider->setOrientation(Qt::Horizontal);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(430, 230, 221, 31));
        contactBox = new QCheckBox(centralWidget);
        contactBox->setObjectName(QString::fromUtf8("contactBox"));
        contactBox->setEnabled(true);
        contactBox->setGeometry(QRect(480, 310, 111, 23));
        contactBox->setChecked(true);
        MCT_Simulator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MCT_Simulator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 840, 22));
        MCT_Simulator->setMenuBar(menuBar);
        statusBar = new QStatusBar(MCT_Simulator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MCT_Simulator->setStatusBar(statusBar);

        retranslateUi(MCT_Simulator);
        QObject::connect(batterySlider, SIGNAL(rangeChanged(int,int)), batteryText, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MCT_Simulator);
    } // setupUi

    void retranslateUi(QMainWindow *MCT_Simulator)
    {
        MCT_Simulator->setWindowTitle(QCoreApplication::translate("MCT_Simulator", "MCT_Simulator", nullptr));
        leftButton->setText(QString());
        rightButton->setText(QString());
        upButton->setText(QString());
        downButton->setText(QString());
        okButton->setText(QString());
        returnButton->setText(QString());
        menuButton->setText(QString());
        powerButton->setText(QString());
        batteryText->setText(QCoreApplication::translate("MCT_Simulator", "100%", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MCT_Simulator", "Main Menu", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MCT_Simulator", "Programs", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MCT_Simulator", "Frequency", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MCT_Simulator", "History", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MCT_Simulator", "Recording Setting", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        textBrowser->setHtml(QCoreApplication::translate("MCT_Simulator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Current Battery/Battery Control</p></body></html>", nullptr));
        contactBox->setText(QCoreApplication::translate("MCT_Simulator", "Skin Contant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MCT_Simulator: public Ui_MCT_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCT_SIMULATOR_H
