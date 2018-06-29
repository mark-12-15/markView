/********************************************************************************
** Form generated from reading UI file 'BCSettingOtherDeviceControlDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGOTHERDEVICECONTROLDLG_H
#define UI_BCSETTINGOTHERDEVICECONTROLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSettingOtherDeviceControlDlg.h"

QT_BEGIN_NAMESPACE

class Ui_BCSettingOtherDeviceControlDlg
{
public:
    QWidget *m_pControlWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *m_pDisplayWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_pDisplayHDMIBtn;
    QPushButton *m_pDisplayDVIBtn;
    QPushButton *m_pDisplayVideo1Btn;
    QPushButton *m_pdisplayVIDEO2Btn;
    QPushButton *m_pDisplayVGABtn;
    QWidget *m_pAudioWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_pVedioOff1;
    QSlider *m_pAudioSlider1;
    QPushButton *m_pVedioOn1;
    QLabel *label;
    QWidget *m_pAudioWidget2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *m_pVedioOff2;
    QSlider *m_pAudioSlider2;
    QPushButton *m_pVedioOn2;
    QLabel *label_2;
    QWidget *m_pAudioWidget3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *m_pVedioOff3;
    QSlider *m_pAudioSlider3;
    QPushButton *m_pVedioOn3;
    QLabel *label_3;
    QWidget *m_pAudioWidget4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *m_pVedioOff4;
    QSlider *m_pAudioSlider4;
    QPushButton *m_pVedioOn4;
    QLabel *label_4;
    QWidget *m_pVedioWidget;
    QHBoxLayout *horizontalLayout_3;
    BCVedioBtn *m_pVedioBtn;
    QWidget *m_pPowerWidget;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *m_pPowerBtn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *m_pTVWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *m_pPowerBtn_30;
    QPushButton *m_pPowerBtn_34;
    QPushButton *m_pPowerBtn_21;
    QPushButton *m_pPowerBtn_22;
    QPushButton *m_pPowerBtn_23;
    QPushButton *m_pPowerBtn_26;
    QPushButton *m_pPowerBtn_25;
    QPushButton *m_pPowerBtn_24;
    QPushButton *m_pPowerBtn_29;
    QPushButton *m_pPowerBtn_28;
    QPushButton *m_pPowerBtn_27;
    QPushButton *m_pPowerBtn_32;
    QPushButton *m_pPowerBtn_36;
    QPushButton *m_pPowerBtn_33;
    QPushButton *m_pPowerBtn_35;
    QWidget *m_pLightWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_pVedioOff4_2;
    QSlider *m_pAudioSlider4_2;
    QPushButton *m_pVedioOn4_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *m_pVedioOff4_4;
    QSlider *m_pAudioSlider4_3;
    QPushButton *m_pVedioOn4_4;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *m_pVedioOff4_5;
    QSlider *m_pAudioSlider4_4;
    QPushButton *m_pVedioOn4_5;
    QLabel *label_7;
    QWidget *m_pContainWidget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *m_pVedioOff4_3;
    QPushButton *m_pVedioOn4_3;
    QPushButton *m_pVedioOn4_6;
    QComboBox *comboBox;
    QWidget *m_pHeaderWidget;
    QPushButton *m_pRoom1Btn;
    QPushButton *m_pRoom2Btn;
    QPushButton *m_pRoom3Btn;
    QPushButton *m_pRoom4Btn;
    QToolButton *m_pMainVedioBtn;
    QToolButton *m_pDisplayMainBtn;
    QToolButton *m_pMainAudioBtn;
    QToolButton *m_pMainTVBtn;
    QToolButton *m_pMainLightBtn;
    QToolButton *m_pMainCurtainBtn;

    void setupUi(QDialog *BCSettingOtherDeviceControlDlg)
    {
        if (BCSettingOtherDeviceControlDlg->objectName().isEmpty())
            BCSettingOtherDeviceControlDlg->setObjectName(QStringLiteral("BCSettingOtherDeviceControlDlg"));
        BCSettingOtherDeviceControlDlg->resize(770, 375);
        BCSettingOtherDeviceControlDlg->setMinimumSize(QSize(770, 375));
        BCSettingOtherDeviceControlDlg->setMaximumSize(QSize(770, 375));
        BCSettingOtherDeviceControlDlg->setAutoFillBackground(false);
        BCSettingOtherDeviceControlDlg->setStyleSheet(QLatin1String("QDialog {\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(98, 136, 167, 255), stop:1 rgba(34, 50, 83, 255));\n"
"}"));
        BCSettingOtherDeviceControlDlg->setSizeGripEnabled(false);
        m_pControlWidget = new QWidget(BCSettingOtherDeviceControlDlg);
        m_pControlWidget->setObjectName(QStringLiteral("m_pControlWidget"));
        m_pControlWidget->setGeometry(QRect(450, 80, 300, 290));
        m_pControlWidget->setMinimumSize(QSize(0, 290));
        m_pControlWidget->setMaximumSize(QSize(16777215, 290));
        m_pControlWidget->setStyleSheet(QLatin1String(".QWidget#m_pControlWidget{\n"
"background-color: rgb(229, 235, 235);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(m_pControlWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_pDisplayWidget = new QWidget(m_pControlWidget);
        m_pDisplayWidget->setObjectName(QStringLiteral("m_pDisplayWidget"));
        m_pDisplayWidget->setMinimumSize(QSize(0, 54));
        m_pDisplayWidget->setStyleSheet(QLatin1String(".QWidget#m_pDisplayWidget{\n"
"background-color: rgb(244,244,244);\n"
"}"));
        horizontalLayout = new QHBoxLayout(m_pDisplayWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 0, -1, 0);
        m_pDisplayHDMIBtn = new QPushButton(m_pDisplayWidget);
        m_pDisplayHDMIBtn->setObjectName(QStringLiteral("m_pDisplayHDMIBtn"));
        m_pDisplayHDMIBtn->setMinimumSize(QSize(37, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        m_pDisplayHDMIBtn->setFont(font);
        m_pDisplayHDMIBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(79,197,247);\n"
"    border-width: 2px;\n"
"    border-color: rgb(79,197,247);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(79,197,247);\n"
"    border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(79,197,247);\n"
"}"));

        horizontalLayout->addWidget(m_pDisplayHDMIBtn);

        m_pDisplayDVIBtn = new QPushButton(m_pDisplayWidget);
        m_pDisplayDVIBtn->setObjectName(QStringLiteral("m_pDisplayDVIBtn"));
        m_pDisplayDVIBtn->setMinimumSize(QSize(37, 18));
        m_pDisplayDVIBtn->setFont(font);
        m_pDisplayDVIBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(164,60,243);\n"
"    border-width: 2px;\n"
"    border-color: rgb(164,60,243);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(164,60,243);\n"
"    border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(164,60,243);\n"
"}"));

        horizontalLayout->addWidget(m_pDisplayDVIBtn);

        m_pDisplayVideo1Btn = new QPushButton(m_pDisplayWidget);
        m_pDisplayVideo1Btn->setObjectName(QStringLiteral("m_pDisplayVideo1Btn"));
        m_pDisplayVideo1Btn->setMinimumSize(QSize(37, 18));
        m_pDisplayVideo1Btn->setFont(font);
        m_pDisplayVideo1Btn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(230,76,100);\n"
"    border-width: 2px;\n"
"    border-color: rgb(230,76,100);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(230,76,100);\n"
"    border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(230,76,100);\n"
"}"));

        horizontalLayout->addWidget(m_pDisplayVideo1Btn);

        m_pdisplayVIDEO2Btn = new QPushButton(m_pDisplayWidget);
        m_pdisplayVIDEO2Btn->setObjectName(QStringLiteral("m_pdisplayVIDEO2Btn"));
        m_pdisplayVIDEO2Btn->setMinimumSize(QSize(37, 18));
        m_pdisplayVIDEO2Btn->setFont(font);
        m_pdisplayVIDEO2Btn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(33,185,199);\n"
"    border-width: 2px;\n"
"    border-color: rgb(33,185,199);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(33,185,199);\n"
"    border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(33,185,199);\n"
"}"));

        horizontalLayout->addWidget(m_pdisplayVIDEO2Btn);

        m_pDisplayVGABtn = new QPushButton(m_pDisplayWidget);
        m_pDisplayVGABtn->setObjectName(QStringLiteral("m_pDisplayVGABtn"));
        m_pDisplayVGABtn->setMinimumSize(QSize(37, 18));
        m_pDisplayVGABtn->setFont(font);
        m_pDisplayVGABtn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(94,170,222);\n"
"    border-width: 2px;\n"
"    border-color: rgb(94,170,222);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(94,170,222);\n"
"    border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(94,170,222);\n"
"}"));

        horizontalLayout->addWidget(m_pDisplayVGABtn);


        verticalLayout_2->addWidget(m_pDisplayWidget);

        m_pAudioWidget1 = new QWidget(m_pControlWidget);
        m_pAudioWidget1->setObjectName(QStringLiteral("m_pAudioWidget1"));
        m_pAudioWidget1->setMinimumSize(QSize(0, 54));
        m_pAudioWidget1->setStyleSheet(QLatin1String(".QWidget#m_pAudioWidget1{\n"
"background-color: rgb(244,244,244);\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(m_pAudioWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        m_pVedioOff1 = new QPushButton(m_pAudioWidget1);
        m_pVedioOff1->setObjectName(QStringLiteral("m_pVedioOff1"));
        m_pVedioOff1->setMinimumSize(QSize(32, 32));
        m_pVedioOff1->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/otherdevice/audiosilence48.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pVedioOff1->setIcon(icon);
        m_pVedioOff1->setIconSize(QSize(30, 30));

        horizontalLayout_4->addWidget(m_pVedioOff1);

        m_pAudioSlider1 = new QSlider(m_pAudioWidget1);
        m_pAudioSlider1->setObjectName(QStringLiteral("m_pAudioSlider1"));
        m_pAudioSlider1->setStyleSheet(QLatin1String("QSlider  \n"
"{   \n"
"}  \n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 5px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: rgb(237,123,112);  \n"
"    width: 5px;  \n"
"    height: 16px;  \n"
"    margin: -5px 0px -5px 0px;     \n"
"} \n"
"\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}"));
        m_pAudioSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(m_pAudioSlider1);

        m_pVedioOn1 = new QPushButton(m_pAudioWidget1);
        m_pVedioOn1->setObjectName(QStringLiteral("m_pVedioOn1"));
        m_pVedioOn1->setMinimumSize(QSize(32, 32));
        m_pVedioOn1->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/otherdevice/audioplus48.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pVedioOn1->setIcon(icon1);
        m_pVedioOn1->setIconSize(QSize(30, 30));

        horizontalLayout_4->addWidget(m_pVedioOn1);

        label = new QLabel(m_pAudioWidget1);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);


        verticalLayout_2->addWidget(m_pAudioWidget1);

        m_pAudioWidget2 = new QWidget(m_pControlWidget);
        m_pAudioWidget2->setObjectName(QStringLiteral("m_pAudioWidget2"));
        m_pAudioWidget2->setMinimumSize(QSize(0, 54));
        m_pAudioWidget2->setStyleSheet(QLatin1String(".QWidget#m_pAudioWidget2{\n"
"background-color: rgb(244,244,244);\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(m_pAudioWidget2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        m_pVedioOff2 = new QPushButton(m_pAudioWidget2);
        m_pVedioOff2->setObjectName(QStringLiteral("m_pVedioOff2"));
        m_pVedioOff2->setMinimumSize(QSize(32, 32));
        m_pVedioOff2->setMaximumSize(QSize(32, 32));
        m_pVedioOff2->setIcon(icon);
        m_pVedioOff2->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(m_pVedioOff2);

        m_pAudioSlider2 = new QSlider(m_pAudioWidget2);
        m_pAudioSlider2->setObjectName(QStringLiteral("m_pAudioSlider2"));
        m_pAudioSlider2->setStyleSheet(QLatin1String("QSlider  \n"
"{   \n"
"}  \n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 5px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: rgb(237,123,112);  \n"
"    width: 5px;  \n"
"    height: 16px;  \n"
"    margin: -5px 0px -5px 0px;     \n"
"} \n"
"\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}"));
        m_pAudioSlider2->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(m_pAudioSlider2);

        m_pVedioOn2 = new QPushButton(m_pAudioWidget2);
        m_pVedioOn2->setObjectName(QStringLiteral("m_pVedioOn2"));
        m_pVedioOn2->setMinimumSize(QSize(32, 32));
        m_pVedioOn2->setMaximumSize(QSize(32, 32));
        m_pVedioOn2->setIcon(icon1);
        m_pVedioOn2->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(m_pVedioOn2);

        label_2 = new QLabel(m_pAudioWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_5->addWidget(label_2);


        verticalLayout_2->addWidget(m_pAudioWidget2);

        m_pAudioWidget3 = new QWidget(m_pControlWidget);
        m_pAudioWidget3->setObjectName(QStringLiteral("m_pAudioWidget3"));
        m_pAudioWidget3->setMinimumSize(QSize(0, 54));
        m_pAudioWidget3->setStyleSheet(QLatin1String(".QWidget#m_pAudioWidget3{\n"
"background-color: rgb(244,244,244);\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(m_pAudioWidget3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        m_pVedioOff3 = new QPushButton(m_pAudioWidget3);
        m_pVedioOff3->setObjectName(QStringLiteral("m_pVedioOff3"));
        m_pVedioOff3->setMinimumSize(QSize(32, 32));
        m_pVedioOff3->setMaximumSize(QSize(32, 32));
        m_pVedioOff3->setIcon(icon);
        m_pVedioOff3->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(m_pVedioOff3);

        m_pAudioSlider3 = new QSlider(m_pAudioWidget3);
        m_pAudioSlider3->setObjectName(QStringLiteral("m_pAudioSlider3"));
        m_pAudioSlider3->setStyleSheet(QLatin1String("QSlider  \n"
"{   \n"
"}  \n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 5px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: rgb(237,123,112);  \n"
"    width: 5px;  \n"
"    height: 16px;  \n"
"    margin: -5px 0px -5px 0px;     \n"
"} \n"
"\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}"));
        m_pAudioSlider3->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(m_pAudioSlider3);

        m_pVedioOn3 = new QPushButton(m_pAudioWidget3);
        m_pVedioOn3->setObjectName(QStringLiteral("m_pVedioOn3"));
        m_pVedioOn3->setMinimumSize(QSize(32, 32));
        m_pVedioOn3->setMaximumSize(QSize(32, 32));
        m_pVedioOn3->setIcon(icon1);
        m_pVedioOn3->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(m_pVedioOn3);

        label_3 = new QLabel(m_pAudioWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_6->addWidget(label_3);


        verticalLayout_2->addWidget(m_pAudioWidget3);

        m_pAudioWidget4 = new QWidget(m_pControlWidget);
        m_pAudioWidget4->setObjectName(QStringLiteral("m_pAudioWidget4"));
        m_pAudioWidget4->setMinimumSize(QSize(0, 54));
        m_pAudioWidget4->setStyleSheet(QLatin1String(".QWidget#m_pAudioWidget4{\n"
"background-color: rgb(244,244,244);\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(m_pAudioWidget4);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        m_pVedioOff4 = new QPushButton(m_pAudioWidget4);
        m_pVedioOff4->setObjectName(QStringLiteral("m_pVedioOff4"));
        m_pVedioOff4->setMinimumSize(QSize(32, 32));
        m_pVedioOff4->setMaximumSize(QSize(32, 32));
        m_pVedioOff4->setIcon(icon);
        m_pVedioOff4->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(m_pVedioOff4);

        m_pAudioSlider4 = new QSlider(m_pAudioWidget4);
        m_pAudioSlider4->setObjectName(QStringLiteral("m_pAudioSlider4"));
        m_pAudioSlider4->setStyleSheet(QLatin1String("QSlider  \n"
"{   \n"
"}  \n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 5px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: rgb(237,123,112);  \n"
"    width: 5px;  \n"
"    height: 16px;  \n"
"    margin: -5px 0px -5px 0px;     \n"
"} \n"
"\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}"));
        m_pAudioSlider4->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(m_pAudioSlider4);

        m_pVedioOn4 = new QPushButton(m_pAudioWidget4);
        m_pVedioOn4->setObjectName(QStringLiteral("m_pVedioOn4"));
        m_pVedioOn4->setMinimumSize(QSize(32, 32));
        m_pVedioOn4->setMaximumSize(QSize(32, 32));
        m_pVedioOn4->setIcon(icon1);
        m_pVedioOn4->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(m_pVedioOn4);

        label_4 = new QLabel(m_pAudioWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_7->addWidget(label_4);


        verticalLayout_2->addWidget(m_pAudioWidget4);

        m_pVedioWidget = new QWidget(m_pControlWidget);
        m_pVedioWidget->setObjectName(QStringLiteral("m_pVedioWidget"));
        m_pVedioWidget->setMinimumSize(QSize(210, 210));
        horizontalLayout_3 = new QHBoxLayout(m_pVedioWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_pVedioBtn = new BCVedioBtn(m_pVedioWidget);
        m_pVedioBtn->setObjectName(QStringLiteral("m_pVedioBtn"));
        m_pVedioBtn->setMinimumSize(QSize(0, 0));
        m_pVedioBtn->setMaximumSize(QSize(210, 210));
        m_pVedioBtn->setStyleSheet(QStringLiteral("border-image: url(:/image/otherdevice/vediosource.png);"));

        horizontalLayout_3->addWidget(m_pVedioBtn);


        verticalLayout_2->addWidget(m_pVedioWidget);

        m_pPowerWidget = new QWidget(m_pControlWidget);
        m_pPowerWidget->setObjectName(QStringLiteral("m_pPowerWidget"));
        horizontalLayout_11 = new QHBoxLayout(m_pPowerWidget);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        m_pPowerBtn = new QPushButton(m_pPowerWidget);
        m_pPowerBtn->setObjectName(QStringLiteral("m_pPowerBtn"));
        m_pPowerBtn->setMinimumSize(QSize(100, 32));
        m_pPowerBtn->setMaximumSize(QSize(100, 32));
        m_pPowerBtn->setStyleSheet(QStringLiteral(""));
        m_pPowerBtn->setIconSize(QSize(150, 30));

        horizontalLayout_11->addWidget(m_pPowerBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(m_pPowerWidget);

        m_pTVWidget = new QWidget(m_pControlWidget);
        m_pTVWidget->setObjectName(QStringLiteral("m_pTVWidget"));
        m_pTVWidget->setMinimumSize(QSize(0, 285));
        m_pTVWidget->setMaximumSize(QSize(16777215, 285));
        m_pTVWidget->setStyleSheet(QLatin1String(".QWidget#m_pTVWidget {\n"
"background-color: rgb(118, 118, 118);\n"
"}"));
        layoutWidget = new QWidget(m_pTVWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(46, 1, 171, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        m_pPowerBtn_30 = new QPushButton(layoutWidget);
        m_pPowerBtn_30->setObjectName(QStringLiteral("m_pPowerBtn_30"));
        m_pPowerBtn_30->setMinimumSize(QSize(33, 14));
        m_pPowerBtn_30->setMaximumSize(QSize(41, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(8);
        m_pPowerBtn_30->setFont(font2);
        m_pPowerBtn_30->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(215,32,32);\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(215,32,32);\n"
"}"));
        m_pPowerBtn_30->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_30, 0, 0, 1, 1);

        m_pPowerBtn_34 = new QPushButton(layoutWidget);
        m_pPowerBtn_34->setObjectName(QStringLiteral("m_pPowerBtn_34"));
        m_pPowerBtn_34->setMinimumSize(QSize(33, 14));
        m_pPowerBtn_34->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_34->setFont(font2);
        m_pPowerBtn_34->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(0, 170, 0);\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(0, 170, 0);\n"
"}"));
        m_pPowerBtn_34->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_34, 0, 2, 1, 1);

        m_pPowerBtn_21 = new QPushButton(layoutWidget);
        m_pPowerBtn_21->setObjectName(QStringLiteral("m_pPowerBtn_21"));
        m_pPowerBtn_21->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_21->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_21->setFont(font);
        m_pPowerBtn_21->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_21->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_21, 1, 0, 1, 1);

        m_pPowerBtn_22 = new QPushButton(layoutWidget);
        m_pPowerBtn_22->setObjectName(QStringLiteral("m_pPowerBtn_22"));
        m_pPowerBtn_22->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_22->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_22->setFont(font);
        m_pPowerBtn_22->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_22->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_22, 1, 1, 1, 1);

        m_pPowerBtn_23 = new QPushButton(layoutWidget);
        m_pPowerBtn_23->setObjectName(QStringLiteral("m_pPowerBtn_23"));
        m_pPowerBtn_23->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_23->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_23->setFont(font);
        m_pPowerBtn_23->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_23->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_23, 1, 2, 1, 1);

        m_pPowerBtn_26 = new QPushButton(layoutWidget);
        m_pPowerBtn_26->setObjectName(QStringLiteral("m_pPowerBtn_26"));
        m_pPowerBtn_26->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_26->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_26->setFont(font);
        m_pPowerBtn_26->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_26->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_26, 2, 0, 1, 1);

        m_pPowerBtn_25 = new QPushButton(layoutWidget);
        m_pPowerBtn_25->setObjectName(QStringLiteral("m_pPowerBtn_25"));
        m_pPowerBtn_25->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_25->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_25->setFont(font);
        m_pPowerBtn_25->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_25->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_25, 2, 1, 1, 1);

        m_pPowerBtn_24 = new QPushButton(layoutWidget);
        m_pPowerBtn_24->setObjectName(QStringLiteral("m_pPowerBtn_24"));
        m_pPowerBtn_24->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_24->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_24->setFont(font);
        m_pPowerBtn_24->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_24->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_24, 2, 2, 1, 1);

        m_pPowerBtn_29 = new QPushButton(layoutWidget);
        m_pPowerBtn_29->setObjectName(QStringLiteral("m_pPowerBtn_29"));
        m_pPowerBtn_29->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_29->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_29->setFont(font);
        m_pPowerBtn_29->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_29->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_29, 3, 0, 1, 1);

        m_pPowerBtn_28 = new QPushButton(layoutWidget);
        m_pPowerBtn_28->setObjectName(QStringLiteral("m_pPowerBtn_28"));
        m_pPowerBtn_28->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_28->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_28->setFont(font);
        m_pPowerBtn_28->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_28->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_28, 3, 1, 1, 1);

        m_pPowerBtn_27 = new QPushButton(layoutWidget);
        m_pPowerBtn_27->setObjectName(QStringLiteral("m_pPowerBtn_27"));
        m_pPowerBtn_27->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_27->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_27->setFont(font);
        m_pPowerBtn_27->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_27->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_27, 3, 2, 1, 1);

        m_pPowerBtn_32 = new QPushButton(layoutWidget);
        m_pPowerBtn_32->setObjectName(QStringLiteral("m_pPowerBtn_32"));
        m_pPowerBtn_32->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_32->setMaximumSize(QSize(37, 91));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        m_pPowerBtn_32->setFont(font3);
        m_pPowerBtn_32->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 15;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_32->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_32, 4, 0, 2, 1);

        m_pPowerBtn_36 = new QPushButton(layoutWidget);
        m_pPowerBtn_36->setObjectName(QStringLiteral("m_pPowerBtn_36"));
        m_pPowerBtn_36->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_36->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_36->setFont(font);
        m_pPowerBtn_36->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_36->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_36, 4, 1, 1, 1);

        m_pPowerBtn_33 = new QPushButton(layoutWidget);
        m_pPowerBtn_33->setObjectName(QStringLiteral("m_pPowerBtn_33"));
        m_pPowerBtn_33->setMinimumSize(QSize(37, 18));
        m_pPowerBtn_33->setMaximumSize(QSize(37, 91));
        m_pPowerBtn_33->setFont(font3);
        m_pPowerBtn_33->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(249, 255, 243);\n"
"	border-color: rgb(237, 255, 252);\n"
"    border-width: 2px;\n"
"    border-style: solid;\n"
"    border-radius: 15;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(249, 255, 243);\n"
"}"));
        m_pPowerBtn_33->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_33, 4, 2, 2, 1);

        m_pPowerBtn_35 = new QPushButton(layoutWidget);
        m_pPowerBtn_35->setObjectName(QStringLiteral("m_pPowerBtn_35"));
        m_pPowerBtn_35->setMinimumSize(QSize(33, 14));
        m_pPowerBtn_35->setMaximumSize(QSize(41, 21));
        m_pPowerBtn_35->setFont(font2);
        m_pPowerBtn_35->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(215, 143, 5);\n"
"    border-style: solid;\n"
"    border-radius: 10;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(215, 143, 5);\n"
"}"));
        m_pPowerBtn_35->setIconSize(QSize(32, 32));

        gridLayout->addWidget(m_pPowerBtn_35, 5, 1, 1, 1);


        verticalLayout_2->addWidget(m_pTVWidget);

        m_pLightWidget = new QWidget(m_pControlWidget);
        m_pLightWidget->setObjectName(QStringLiteral("m_pLightWidget"));
        m_pLightWidget->setMinimumSize(QSize(0, 54));
        m_pLightWidget->setStyleSheet(QLatin1String(".QWidget#m_pAudioWidget4{\n"
"background-color: rgb(244,244,244);\n"
"}"));
        verticalLayout = new QVBoxLayout(m_pLightWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_pVedioOff4_2 = new QPushButton(m_pLightWidget);
        m_pVedioOff4_2->setObjectName(QStringLiteral("m_pVedioOff4_2"));
        m_pVedioOff4_2->setMinimumSize(QSize(32, 32));
        m_pVedioOff4_2->setMaximumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/otherdevice/lighton.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pVedioOff4_2->setIcon(icon2);
        m_pVedioOff4_2->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(m_pVedioOff4_2);

        m_pAudioSlider4_2 = new QSlider(m_pLightWidget);
        m_pAudioSlider4_2->setObjectName(QStringLiteral("m_pAudioSlider4_2"));
        m_pAudioSlider4_2->setStyleSheet(QLatin1String("QSlider  \n"
"{   \n"
"}  \n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 5px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: rgb(237,123,112);  \n"
"    width: 5px;  \n"
"    height: 16px;  \n"
"    margin: -5px 0px -5px 0px;     \n"
"} \n"
"\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}"));
        m_pAudioSlider4_2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(m_pAudioSlider4_2);

        m_pVedioOn4_2 = new QPushButton(m_pLightWidget);
        m_pVedioOn4_2->setObjectName(QStringLiteral("m_pVedioOn4_2"));
        m_pVedioOn4_2->setMinimumSize(QSize(32, 32));
        m_pVedioOn4_2->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/otherdevice/lightoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pVedioOn4_2->setIcon(icon3);
        m_pVedioOn4_2->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(m_pVedioOn4_2);

        label_5 = new QLabel(m_pLightWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_2->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        m_pVedioOff4_4 = new QPushButton(m_pLightWidget);
        m_pVedioOff4_4->setObjectName(QStringLiteral("m_pVedioOff4_4"));
        m_pVedioOff4_4->setMinimumSize(QSize(32, 32));
        m_pVedioOff4_4->setMaximumSize(QSize(32, 32));
        m_pVedioOff4_4->setIcon(icon2);
        m_pVedioOff4_4->setIconSize(QSize(30, 30));

        horizontalLayout_8->addWidget(m_pVedioOff4_4);

        m_pAudioSlider4_3 = new QSlider(m_pLightWidget);
        m_pAudioSlider4_3->setObjectName(QStringLiteral("m_pAudioSlider4_3"));
        m_pAudioSlider4_3->setStyleSheet(QLatin1String("QSlider  \n"
"{   \n"
"}  \n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 5px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: rgb(237,123,112);  \n"
"    width: 5px;  \n"
"    height: 16px;  \n"
"    margin: -5px 0px -5px 0px;     \n"
"} \n"
"\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}"));
        m_pAudioSlider4_3->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(m_pAudioSlider4_3);

        m_pVedioOn4_4 = new QPushButton(m_pLightWidget);
        m_pVedioOn4_4->setObjectName(QStringLiteral("m_pVedioOn4_4"));
        m_pVedioOn4_4->setMinimumSize(QSize(32, 32));
        m_pVedioOn4_4->setMaximumSize(QSize(32, 32));
        m_pVedioOn4_4->setIcon(icon3);
        m_pVedioOn4_4->setIconSize(QSize(30, 30));

        horizontalLayout_8->addWidget(m_pVedioOn4_4);

        label_6 = new QLabel(m_pLightWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_8->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        m_pVedioOff4_5 = new QPushButton(m_pLightWidget);
        m_pVedioOff4_5->setObjectName(QStringLiteral("m_pVedioOff4_5"));
        m_pVedioOff4_5->setMinimumSize(QSize(32, 32));
        m_pVedioOff4_5->setMaximumSize(QSize(32, 32));
        m_pVedioOff4_5->setIcon(icon2);
        m_pVedioOff4_5->setIconSize(QSize(30, 30));

        horizontalLayout_10->addWidget(m_pVedioOff4_5);

        m_pAudioSlider4_4 = new QSlider(m_pLightWidget);
        m_pAudioSlider4_4->setObjectName(QStringLiteral("m_pAudioSlider4_4"));
        m_pAudioSlider4_4->setStyleSheet(QLatin1String("QSlider  \n"
"{   \n"
"}  \n"
"  \n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 5px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: rgb(237,123,112);  \n"
"    width: 5px;  \n"
"    height: 16px;  \n"
"    margin: -5px 0px -5px 0px;     \n"
"} \n"
"\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}"));
        m_pAudioSlider4_4->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(m_pAudioSlider4_4);

        m_pVedioOn4_5 = new QPushButton(m_pLightWidget);
        m_pVedioOn4_5->setObjectName(QStringLiteral("m_pVedioOn4_5"));
        m_pVedioOn4_5->setMinimumSize(QSize(32, 32));
        m_pVedioOn4_5->setMaximumSize(QSize(32, 32));
        m_pVedioOn4_5->setIcon(icon3);
        m_pVedioOn4_5->setIconSize(QSize(30, 30));

        horizontalLayout_10->addWidget(m_pVedioOn4_5);

        label_7 = new QLabel(m_pLightWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        horizontalLayout_10->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_10);


        verticalLayout_2->addWidget(m_pLightWidget);

        m_pContainWidget = new QWidget(m_pControlWidget);
        m_pContainWidget->setObjectName(QStringLiteral("m_pContainWidget"));
        m_pContainWidget->setMinimumSize(QSize(0, 54));
        m_pContainWidget->setStyleSheet(QLatin1String(".QWidget#m_pAudioWidget4{\n"
"background-color: rgb(244,244,244);\n"
"}"));
        horizontalLayout_9 = new QHBoxLayout(m_pContainWidget);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        m_pVedioOff4_3 = new QPushButton(m_pContainWidget);
        m_pVedioOff4_3->setObjectName(QStringLiteral("m_pVedioOff4_3"));
        m_pVedioOff4_3->setMinimumSize(QSize(32, 32));
        m_pVedioOff4_3->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/otherdevice/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pVedioOff4_3->setIcon(icon4);
        m_pVedioOff4_3->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(m_pVedioOff4_3);

        m_pVedioOn4_3 = new QPushButton(m_pContainWidget);
        m_pVedioOn4_3->setObjectName(QStringLiteral("m_pVedioOn4_3"));
        m_pVedioOn4_3->setMinimumSize(QSize(32, 32));
        m_pVedioOn4_3->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/otherdevice/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pVedioOn4_3->setIcon(icon5);
        m_pVedioOn4_3->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(m_pVedioOn4_3);

        m_pVedioOn4_6 = new QPushButton(m_pContainWidget);
        m_pVedioOn4_6->setObjectName(QStringLiteral("m_pVedioOn4_6"));
        m_pVedioOn4_6->setMinimumSize(QSize(32, 32));
        m_pVedioOn4_6->setMaximumSize(QSize(32, 32));
        m_pVedioOn4_6->setIcon(icon5);
        m_pVedioOn4_6->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(m_pVedioOn4_6);


        verticalLayout_2->addWidget(m_pContainWidget);

        comboBox = new QComboBox(BCSettingOtherDeviceControlDlg);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(603, 9, 150, 54));
        comboBox->setMinimumSize(QSize(150, 54));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        comboBox->setFont(font4);
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setStyleSheet(QLatin1String("QComboBox {\n"
"	background-color: rgb(125, 129, 130);\n"
"    border: 0px solid rgb(255,255,255);\n"
"    color: rgb(255,255,255);\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	background-color: rgb(125, 129, 130);\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    border-left: 0px solid #333333;\n"
"    border-radius: 4px;\n"
"	height: 54;\n"
"}"));
        m_pHeaderWidget = new QWidget(BCSettingOtherDeviceControlDlg);
        m_pHeaderWidget->setObjectName(QStringLiteral("m_pHeaderWidget"));
        m_pHeaderWidget->setGeometry(QRect(20, 9, 571, 54));
        m_pHeaderWidget->setMinimumSize(QSize(0, 54));
        m_pHeaderWidget->setMaximumSize(QSize(16777215, 54));
        m_pHeaderWidget->setStyleSheet(QLatin1String(".QWidget#m_pHeaderWidget{\n"
"background-color: rgb(229, 235, 235);\n"
"}"));
        m_pRoom1Btn = new QPushButton(m_pHeaderWidget);
        m_pRoom1Btn->setObjectName(QStringLiteral("m_pRoom1Btn"));
        m_pRoom1Btn->setGeometry(QRect(0, 0, 100, 54));
        m_pRoom1Btn->setFont(font1);
        m_pRoom1Btn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(232, 72, 61);\n"
"    border-width: 2px;\n"
"    border-color: rgb(232, 72, 61);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(232, 72, 61);\n"
"    border-color: rgb(232, 72, 61);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(232, 72, 61);\n"
"}"));
        m_pRoom2Btn = new QPushButton(m_pHeaderWidget);
        m_pRoom2Btn->setObjectName(QStringLiteral("m_pRoom2Btn"));
        m_pRoom2Btn->setGeometry(QRect(100, 0, 100, 54));
        m_pRoom2Btn->setFont(font1);
        m_pRoom2Btn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(229, 235, 235);\n"
"    border-width: 2px;\n"
"    border-color: rgb(229, 235, 235);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(232, 72, 61);\n"
"    border-color: rgb(232, 72, 61);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(232, 72, 61);\n"
"}"));
        m_pRoom3Btn = new QPushButton(m_pHeaderWidget);
        m_pRoom3Btn->setObjectName(QStringLiteral("m_pRoom3Btn"));
        m_pRoom3Btn->setGeometry(QRect(200, 0, 100, 54));
        m_pRoom3Btn->setFont(font1);
        m_pRoom3Btn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(229, 235, 235);\n"
"    border-width: 2px;\n"
"    border-color: rgb(229, 235, 235);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(232, 72, 61);\n"
"    border-color: rgb(232, 72, 61);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(232, 72, 61);\n"
"}"));
        m_pRoom4Btn = new QPushButton(m_pHeaderWidget);
        m_pRoom4Btn->setObjectName(QStringLiteral("m_pRoom4Btn"));
        m_pRoom4Btn->setGeometry(QRect(300, 0, 100, 54));
        m_pRoom4Btn->setFont(font1);
        m_pRoom4Btn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgb(229, 235, 235);\n"
"    border-width: 2px;\n"
"    border-color: rgb(229, 235, 235);\n"
"    border-style: solid;\n"
"    border-radius: 0;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(232, 72, 61);\n"
"    border-color: rgb(232, 72, 61);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgb(232, 72, 61);\n"
"}"));
        m_pMainVedioBtn = new QToolButton(BCSettingOtherDeviceControlDlg);
        m_pMainVedioBtn->setObjectName(QStringLiteral("m_pMainVedioBtn"));
        m_pMainVedioBtn->setGeometry(QRect(50, 120, 97, 97));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pMainVedioBtn->setFont(font5);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/otherdevice/vedio.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pMainVedioBtn->setIcon(icon6);
        m_pMainVedioBtn->setIconSize(QSize(90, 70));
        m_pMainVedioBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pMainVedioBtn->setAutoRaise(true);
        m_pDisplayMainBtn = new QToolButton(BCSettingOtherDeviceControlDlg);
        m_pDisplayMainBtn->setObjectName(QStringLiteral("m_pDisplayMainBtn"));
        m_pDisplayMainBtn->setGeometry(QRect(167, 120, 97, 97));
        m_pDisplayMainBtn->setFont(font5);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/otherdevice/display.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pDisplayMainBtn->setIcon(icon7);
        m_pDisplayMainBtn->setIconSize(QSize(90, 70));
        m_pDisplayMainBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pDisplayMainBtn->setAutoRaise(true);
        m_pMainAudioBtn = new QToolButton(BCSettingOtherDeviceControlDlg);
        m_pMainAudioBtn->setObjectName(QStringLiteral("m_pMainAudioBtn"));
        m_pMainAudioBtn->setGeometry(QRect(290, 120, 97, 97));
        m_pMainAudioBtn->setFont(font5);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/otherdevice/audio.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pMainAudioBtn->setIcon(icon8);
        m_pMainAudioBtn->setIconSize(QSize(90, 70));
        m_pMainAudioBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pMainAudioBtn->setAutoRaise(true);
        m_pMainTVBtn = new QToolButton(BCSettingOtherDeviceControlDlg);
        m_pMainTVBtn->setObjectName(QStringLiteral("m_pMainTVBtn"));
        m_pMainTVBtn->setGeometry(QRect(50, 240, 97, 97));
        m_pMainTVBtn->setFont(font5);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/image/otherdevice/tv.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pMainTVBtn->setIcon(icon9);
        m_pMainTVBtn->setIconSize(QSize(90, 70));
        m_pMainTVBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pMainTVBtn->setAutoRaise(true);
        m_pMainLightBtn = new QToolButton(BCSettingOtherDeviceControlDlg);
        m_pMainLightBtn->setObjectName(QStringLiteral("m_pMainLightBtn"));
        m_pMainLightBtn->setGeometry(QRect(168, 240, 97, 97));
        m_pMainLightBtn->setFont(font5);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/image/otherdevice/light.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pMainLightBtn->setIcon(icon10);
        m_pMainLightBtn->setIconSize(QSize(90, 70));
        m_pMainLightBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pMainLightBtn->setAutoRaise(true);
        m_pMainCurtainBtn = new QToolButton(BCSettingOtherDeviceControlDlg);
        m_pMainCurtainBtn->setObjectName(QStringLiteral("m_pMainCurtainBtn"));
        m_pMainCurtainBtn->setGeometry(QRect(290, 240, 97, 97));
        m_pMainCurtainBtn->setFont(font5);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/image/otherdevice/Curtains.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pMainCurtainBtn->setIcon(icon11);
        m_pMainCurtainBtn->setIconSize(QSize(90, 70));
        m_pMainCurtainBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pMainCurtainBtn->setAutoRaise(true);

        retranslateUi(BCSettingOtherDeviceControlDlg);

        m_pPowerBtn->setDefault(true);
        m_pPowerBtn_30->setDefault(true);
        m_pPowerBtn_34->setDefault(true);
        m_pPowerBtn_21->setDefault(true);
        m_pPowerBtn_22->setDefault(true);
        m_pPowerBtn_23->setDefault(true);
        m_pPowerBtn_26->setDefault(true);
        m_pPowerBtn_25->setDefault(true);
        m_pPowerBtn_24->setDefault(true);
        m_pPowerBtn_29->setDefault(true);
        m_pPowerBtn_28->setDefault(true);
        m_pPowerBtn_27->setDefault(true);
        m_pPowerBtn_32->setDefault(true);
        m_pPowerBtn_36->setDefault(true);
        m_pPowerBtn_33->setDefault(true);
        m_pPowerBtn_35->setDefault(true);


        QMetaObject::connectSlotsByName(BCSettingOtherDeviceControlDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingOtherDeviceControlDlg)
    {
        BCSettingOtherDeviceControlDlg->setWindowTitle(QApplication::translate("BCSettingOtherDeviceControlDlg", "\344\270\255\346\216\247\350\256\276\347\275\256", Q_NULLPTR));
        m_pDisplayHDMIBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "HDMI", Q_NULLPTR));
        m_pDisplayDVIBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "DVI", Q_NULLPTR));
        m_pDisplayVideo1Btn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "VIDEO1", Q_NULLPTR));
        m_pdisplayVIDEO2Btn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "VIDEO2", Q_NULLPTR));
        m_pDisplayVGABtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "VGA", Q_NULLPTR));
        m_pVedioOff1->setText(QString());
        m_pVedioOn1->setText(QString());
        label->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "      \351\237\263\351\242\2211", Q_NULLPTR));
        m_pVedioOff2->setText(QString());
        m_pVedioOn2->setText(QString());
        label_2->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "      \351\237\263\351\242\2212", Q_NULLPTR));
        m_pVedioOff3->setText(QString());
        m_pVedioOn3->setText(QString());
        label_3->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "      \351\237\263\351\242\2213", Q_NULLPTR));
        m_pVedioOff4->setText(QString());
        m_pVedioOn4->setText(QString());
        label_4->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "      \351\237\263\351\242\2214", Q_NULLPTR));
        m_pVedioBtn->setText(QString());
        m_pPowerBtn->setText(QString());
        m_pPowerBtn_30->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\347\224\265\346\272\220", Q_NULLPTR));
        m_pPowerBtn_34->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\345\276\205\346\234\272", Q_NULLPTR));
        m_pPowerBtn_21->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "1", Q_NULLPTR));
        m_pPowerBtn_22->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "2", Q_NULLPTR));
        m_pPowerBtn_23->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "3", Q_NULLPTR));
        m_pPowerBtn_26->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "4", Q_NULLPTR));
        m_pPowerBtn_25->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "5", Q_NULLPTR));
        m_pPowerBtn_24->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "6", Q_NULLPTR));
        m_pPowerBtn_29->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "7", Q_NULLPTR));
        m_pPowerBtn_28->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "8", Q_NULLPTR));
        m_pPowerBtn_27->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "9", Q_NULLPTR));
        m_pPowerBtn_32->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "+\n"
"\351\242\221\351\201\223\n"
"-", Q_NULLPTR));
        m_pPowerBtn_36->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "0", Q_NULLPTR));
        m_pPowerBtn_33->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "+\n"
"\351\237\263\351\207\217\n"
"-", Q_NULLPTR));
        m_pPowerBtn_35->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\351\235\231\351\237\263", Q_NULLPTR));
        m_pVedioOff4_2->setText(QString());
        m_pVedioOn4_2->setText(QString());
        label_5->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "      \347\201\257\345\205\2111", Q_NULLPTR));
        m_pVedioOff4_4->setText(QString());
        m_pVedioOn4_4->setText(QString());
        label_6->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "      \347\201\257\345\205\2112", Q_NULLPTR));
        m_pVedioOff4_5->setText(QString());
        m_pVedioOn4_5->setText(QString());
        label_7->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "      \347\201\257\345\205\2113", Q_NULLPTR));
        m_pVedioOff4_3->setText(QString());
        m_pVedioOn4_3->setText(QString());
        m_pVedioOn4_6->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingOtherDeviceControlDlg", "\344\270\200\346\245\274", Q_NULLPTR)
         << QApplication::translate("BCSettingOtherDeviceControlDlg", "\344\272\214\346\245\274", Q_NULLPTR)
         << QApplication::translate("BCSettingOtherDeviceControlDlg", "\344\270\211\346\245\274", Q_NULLPTR)
         << QApplication::translate("BCSettingOtherDeviceControlDlg", "\345\233\233\346\245\274", Q_NULLPTR)
        );
        m_pRoom1Btn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\346\210\277\351\227\2641", Q_NULLPTR));
        m_pRoom2Btn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\346\210\277\351\227\2642", Q_NULLPTR));
        m_pRoom3Btn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\346\210\277\351\227\2643", Q_NULLPTR));
        m_pRoom4Btn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\346\210\277\351\227\2644", Q_NULLPTR));
        m_pMainVedioBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        m_pDisplayMainBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\345\261\217\345\271\225", Q_NULLPTR));
        m_pMainAudioBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\351\237\263\351\242\221", Q_NULLPTR));
        m_pMainTVBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\347\224\265\350\247\206\345\274\200\345\205\263", Q_NULLPTR));
        m_pMainLightBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\347\201\257\345\205\211\346\216\247\345\210\266", Q_NULLPTR));
        m_pMainCurtainBtn->setText(QApplication::translate("BCSettingOtherDeviceControlDlg", "\347\252\227\345\270\230\346\216\247\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingOtherDeviceControlDlg: public Ui_BCSettingOtherDeviceControlDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGOTHERDEVICECONTROLDLG_H
