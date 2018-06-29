/********************************************************************************
** Form generated from reading UI file 'BCSettingDisplaySwitchRoomWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDISPLAYSWITCHROOMWIDGET_H
#define UI_BCSETTINGDISPLAYSWITCHROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDisplaySwitchRoomWidget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *m_pUseComConnectRadioBtn;
    QLabel *label_5;
    QComboBox *m_pComComBox;
    QLabel *label_7;
    QComboBox *m_pBaudRateComBox;
    QLabel *label_8;
    QComboBox *m_pDataBitComBox;
    QLabel *label_9;
    QComboBox *m_pStopBitComBox;
    QLabel *label_10;
    QComboBox *m_pCheckBitComBox;
    QLabel *label_11;
    QComboBox *m_pStreamCtrlComBox;
    QRadioButton *m_pUseNetConnectRadioBtn;
    QLabel *label_6;
    QLineEdit *m_pNetIPLineEdit;
    QLabel *label_12;
    QLineEdit *m_pNetPortLineEdit;
    QLabel *m_pRoomLabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *m_pCommandTypeCombox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *m_pOpenCmdLineEdit;
    QLineEdit *m_pCloseCmdLineEdit;
    QLabel *label;
    QComboBox *m_pDisplayMakerComboBox;

    void setupUi(QWidget *BCSettingDisplaySwitchRoomWidget)
    {
        if (BCSettingDisplaySwitchRoomWidget->objectName().isEmpty())
            BCSettingDisplaySwitchRoomWidget->setObjectName(QStringLiteral("BCSettingDisplaySwitchRoomWidget"));
        BCSettingDisplaySwitchRoomWidget->resize(354, 335);
        gridLayout_2 = new QGridLayout(BCSettingDisplaySwitchRoomWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(BCSettingDisplaySwitchRoomWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_pUseComConnectRadioBtn = new QRadioButton(groupBox);
        m_pUseComConnectRadioBtn->setObjectName(QStringLiteral("m_pUseComConnectRadioBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(false);
        font1.setWeight(50);
        m_pUseComConnectRadioBtn->setFont(font1);

        gridLayout->addWidget(m_pUseComConnectRadioBtn, 0, 0, 1, 4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        m_pComComBox = new QComboBox(groupBox);
        m_pComComBox->setObjectName(QStringLiteral("m_pComComBox"));
        m_pComComBox->setMinimumSize(QSize(0, 0));
        m_pComComBox->setFont(font);
        m_pComComBox->setEditable(true);

        gridLayout->addWidget(m_pComComBox, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        m_pBaudRateComBox = new QComboBox(groupBox);
        m_pBaudRateComBox->setObjectName(QStringLiteral("m_pBaudRateComBox"));
        m_pBaudRateComBox->setMinimumSize(QSize(0, 0));
        m_pBaudRateComBox->setFont(font);
        m_pBaudRateComBox->setEditable(true);

        gridLayout->addWidget(m_pBaudRateComBox, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        m_pDataBitComBox = new QComboBox(groupBox);
        m_pDataBitComBox->setObjectName(QStringLiteral("m_pDataBitComBox"));
        m_pDataBitComBox->setMinimumSize(QSize(0, 0));
        m_pDataBitComBox->setFont(font);
        m_pDataBitComBox->setEditable(true);

        gridLayout->addWidget(m_pDataBitComBox, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 2, 2, 1, 1);

        m_pStopBitComBox = new QComboBox(groupBox);
        m_pStopBitComBox->setObjectName(QStringLiteral("m_pStopBitComBox"));
        m_pStopBitComBox->setMinimumSize(QSize(0, 0));
        m_pStopBitComBox->setFont(font);
        m_pStopBitComBox->setEditable(true);

        gridLayout->addWidget(m_pStopBitComBox, 2, 3, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 3, 0, 1, 1);

        m_pCheckBitComBox = new QComboBox(groupBox);
        m_pCheckBitComBox->setObjectName(QStringLiteral("m_pCheckBitComBox"));
        m_pCheckBitComBox->setMinimumSize(QSize(0, 0));
        m_pCheckBitComBox->setFont(font);
        m_pCheckBitComBox->setEditable(true);

        gridLayout->addWidget(m_pCheckBitComBox, 3, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 3, 2, 1, 1);

        m_pStreamCtrlComBox = new QComboBox(groupBox);
        m_pStreamCtrlComBox->setObjectName(QStringLiteral("m_pStreamCtrlComBox"));
        m_pStreamCtrlComBox->setMinimumSize(QSize(0, 0));
        m_pStreamCtrlComBox->setFont(font);
        m_pStreamCtrlComBox->setEditable(true);

        gridLayout->addWidget(m_pStreamCtrlComBox, 3, 3, 1, 1);

        m_pUseNetConnectRadioBtn = new QRadioButton(groupBox);
        m_pUseNetConnectRadioBtn->setObjectName(QStringLiteral("m_pUseNetConnectRadioBtn"));
        m_pUseNetConnectRadioBtn->setFont(font1);

        gridLayout->addWidget(m_pUseNetConnectRadioBtn, 4, 0, 1, 4);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        m_pNetIPLineEdit = new QLineEdit(groupBox);
        m_pNetIPLineEdit->setObjectName(QStringLiteral("m_pNetIPLineEdit"));
        m_pNetIPLineEdit->setEnabled(true);
        m_pNetIPLineEdit->setFont(font);
        m_pNetIPLineEdit->setReadOnly(false);

        gridLayout->addWidget(m_pNetIPLineEdit, 5, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 0));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 5, 2, 1, 1);

        m_pNetPortLineEdit = new QLineEdit(groupBox);
        m_pNetPortLineEdit->setObjectName(QStringLiteral("m_pNetPortLineEdit"));
        m_pNetPortLineEdit->setFont(font);
        m_pNetPortLineEdit->setReadOnly(false);

        gridLayout->addWidget(m_pNetPortLineEdit, 5, 3, 1, 1);


        gridLayout_2->addWidget(groupBox, 4, 0, 1, 3);

        m_pRoomLabel = new QLabel(BCSettingDisplaySwitchRoomWidget);
        m_pRoomLabel->setObjectName(QStringLiteral("m_pRoomLabel"));
        m_pRoomLabel->setFont(font);

        gridLayout_2->addWidget(m_pRoomLabel, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        m_pCommandTypeCombox = new QComboBox(BCSettingDisplaySwitchRoomWidget);
        m_pCommandTypeCombox->setObjectName(QStringLiteral("m_pCommandTypeCombox"));
        m_pCommandTypeCombox->setFont(font);

        gridLayout_2->addWidget(m_pCommandTypeCombox, 0, 2, 1, 1);

        label_2 = new QLabel(BCSettingDisplaySwitchRoomWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(BCSettingDisplaySwitchRoomWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        m_pOpenCmdLineEdit = new QLineEdit(BCSettingDisplaySwitchRoomWidget);
        m_pOpenCmdLineEdit->setObjectName(QStringLiteral("m_pOpenCmdLineEdit"));
        m_pOpenCmdLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pOpenCmdLineEdit, 1, 1, 1, 2);

        m_pCloseCmdLineEdit = new QLineEdit(BCSettingDisplaySwitchRoomWidget);
        m_pCloseCmdLineEdit->setObjectName(QStringLiteral("m_pCloseCmdLineEdit"));
        m_pCloseCmdLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pCloseCmdLineEdit, 2, 1, 1, 2);

        label = new QLabel(BCSettingDisplaySwitchRoomWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        m_pDisplayMakerComboBox = new QComboBox(BCSettingDisplaySwitchRoomWidget);
        m_pDisplayMakerComboBox->setObjectName(QStringLiteral("m_pDisplayMakerComboBox"));
        m_pDisplayMakerComboBox->setFont(font);

        gridLayout_2->addWidget(m_pDisplayMakerComboBox, 3, 2, 1, 1);


        retranslateUi(BCSettingDisplaySwitchRoomWidget);

        QMetaObject::connectSlotsByName(BCSettingDisplaySwitchRoomWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSettingDisplaySwitchRoomWidget)
    {
        BCSettingDisplaySwitchRoomWidget->setWindowTitle(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\346\216\247\345\210\266\346\226\271\345\274\217", Q_NULLPTR));
        m_pUseComConnectRadioBtn->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "COM", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        m_pBaudRateComBox->clear();
        m_pBaudRateComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "1200", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "2400", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "4800", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "9600", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "14400", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "19200", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "38400", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "56000", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "57600", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "115200", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        m_pDataBitComBox->clear();
        m_pDataBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "5", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "6", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "7", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "8", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        m_pStopBitComBox->clear();
        m_pStopBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "1", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "2", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "3", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        m_pCheckBitComBox->clear();
        m_pCheckBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Odd", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Even", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Mark", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Space", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\346\265\201\346\216\247\345\210\266", Q_NULLPTR));
        m_pStreamCtrlComBox->clear();
        m_pStreamCtrlComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Hardware", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Software", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Custom", Q_NULLPTR)
        );
        m_pUseNetConnectRadioBtn->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "NET", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "IP\345\234\260\345\235\200", Q_NULLPTR));
        m_pNetIPLineEdit->setText(QString());
        label_12->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        m_pNetPortLineEdit->setText(QString());
        m_pRoomLabel->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\346\213\274\346\216\245\345\231\250", Q_NULLPTR));
        m_pCommandTypeCombox->clear();
        m_pCommandTypeCombox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "16\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplaySwitchRoomWidget", "Ascll\347\240\201", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        m_pCommandTypeCombox->setToolTip(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "16\350\277\233\345\210\266\346\214\207\344\273\244\351\234\200\350\246\201\347\224\250\347\251\272\346\240\274\345\210\206\345\274\200\357\274\214\345\246\202: 01 FF FA...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\346\211\223\345\274\200\346\214\207\344\273\244", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\345\205\263\351\227\255\346\214\207\344\273\244", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        m_pOpenCmdLineEdit->setToolTip(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\345\246\20216\350\277\233\345\210\266\350\257\267\347\224\250\347\251\272\346\240\274\345\260\206\346\214\207\344\273\244\345\210\206\345\274\200\n"
"\345\246\202\357\274\23201 00 AE FF", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_pCloseCmdLineEdit->setToolTip(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\345\246\20216\350\277\233\345\210\266\350\257\267\347\224\250\347\251\272\346\240\274\345\260\206\346\214\207\344\273\244\345\210\206\345\274\200\n"
"\345\246\202\357\274\23201 00 AE FF", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("BCSettingDisplaySwitchRoomWidget", "\345\277\253\346\215\267\346\214\207\344\273\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDisplaySwitchRoomWidget: public Ui_BCSettingDisplaySwitchRoomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDISPLAYSWITCHROOMWIDGET_H
