/********************************************************************************
** Form generated from reading UI file 'BCSettingCommunicationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGCOMMUNICATIONDLG_H
#define UI_BCSETTINGCOMMUNICATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingCommunicationDlg
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *m_pDeviceType;
    QCheckBox *m_pJointCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *m_pUseComConnectRadioBtn;
    QLabel *label_2;
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
    QLabel *label;
    QLineEdit *m_pNetIPLineEdit;
    QLabel *label_12;
    QLineEdit *m_pNetPortLineEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *m_pDeviceTableWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *m_pSearchDeviceBtn;
    QPushButton *m_pMoreSetBtn;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *m_pMoreSetGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_13;
    QLabel *label_3;
    QLabel *label_14;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *m_pSelectedNameLineEdit;
    QLineEdit *m_pSelectedIPLineEdit;
    QLineEdit *m_pSelectedPortLineEdit;
    QLineEdit *m_pSelectedMaskLineEdit;
    QLineEdit *m_pSelectedGatewayLineEdit;
    QLineEdit *m_pSelectedMacLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_pModifyDeviceConfigBtn;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *m_pPreviewComboBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pDemoModeBtn;
    QPushButton *m_pOkBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingCommunicationDlg)
    {
        if (BCSettingCommunicationDlg->objectName().isEmpty())
            BCSettingCommunicationDlg->setObjectName(QStringLiteral("BCSettingCommunicationDlg"));
        BCSettingCommunicationDlg->resize(505, 708);
        verticalLayout_3 = new QVBoxLayout(BCSettingCommunicationDlg);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_3 = new QGroupBox(BCSettingCommunicationDlg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox_3->setFont(font);
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        m_pDeviceType = new QComboBox(groupBox_3);
        m_pDeviceType->setObjectName(QStringLiteral("m_pDeviceType"));
        m_pDeviceType->setMinimumSize(QSize(120, 0));
        m_pDeviceType->setFont(font);
        m_pDeviceType->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_6->addWidget(m_pDeviceType);

        m_pJointCheckBox = new QCheckBox(groupBox_3);
        m_pJointCheckBox->setObjectName(QStringLiteral("m_pJointCheckBox"));

        horizontalLayout_6->addWidget(m_pJointCheckBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox = new QGroupBox(BCSettingCommunicationDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
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

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

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

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setFont(font);

        gridLayout->addWidget(label, 5, 0, 1, 1);

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


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BCSettingCommunicationDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_pDeviceTableWidget = new QTableWidget(groupBox_2);
        m_pDeviceTableWidget->setObjectName(QStringLiteral("m_pDeviceTableWidget"));
        m_pDeviceTableWidget->setEnabled(true);
        m_pDeviceTableWidget->setFont(font);

        verticalLayout_2->addWidget(m_pDeviceTableWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        m_pSearchDeviceBtn = new QPushButton(groupBox_2);
        m_pSearchDeviceBtn->setObjectName(QStringLiteral("m_pSearchDeviceBtn"));
        m_pSearchDeviceBtn->setMinimumSize(QSize(90, 24));
        m_pSearchDeviceBtn->setFont(font);

        horizontalLayout_5->addWidget(m_pSearchDeviceBtn);

        m_pMoreSetBtn = new QPushButton(groupBox_2);
        m_pMoreSetBtn->setObjectName(QStringLiteral("m_pMoreSetBtn"));
        m_pMoreSetBtn->setMinimumSize(QSize(90, 24));
        m_pMoreSetBtn->setFont(font);

        horizontalLayout_5->addWidget(m_pMoreSetBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        m_pMoreSetGroupBox = new QGroupBox(groupBox_2);
        m_pMoreSetGroupBox->setObjectName(QStringLiteral("m_pMoreSetGroupBox"));
        m_pMoreSetGroupBox->setFont(font);
        verticalLayout = new QVBoxLayout(m_pMoreSetGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_13 = new QLabel(m_pMoreSetGroupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        horizontalLayout_2->addWidget(label_13);

        label_3 = new QLabel(m_pMoreSetGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        label_14 = new QLabel(m_pMoreSetGroupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        horizontalLayout_2->addWidget(label_14);

        label_4 = new QLabel(m_pMoreSetGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(m_pMoreSetGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(m_pMoreSetGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        m_pSelectedNameLineEdit = new QLineEdit(m_pMoreSetGroupBox);
        m_pSelectedNameLineEdit->setObjectName(QStringLiteral("m_pSelectedNameLineEdit"));
        m_pSelectedNameLineEdit->setFont(font);

        horizontalLayout_3->addWidget(m_pSelectedNameLineEdit);

        m_pSelectedIPLineEdit = new QLineEdit(m_pMoreSetGroupBox);
        m_pSelectedIPLineEdit->setObjectName(QStringLiteral("m_pSelectedIPLineEdit"));
        m_pSelectedIPLineEdit->setFont(font);

        horizontalLayout_3->addWidget(m_pSelectedIPLineEdit);

        m_pSelectedPortLineEdit = new QLineEdit(m_pMoreSetGroupBox);
        m_pSelectedPortLineEdit->setObjectName(QStringLiteral("m_pSelectedPortLineEdit"));
        m_pSelectedPortLineEdit->setFont(font);

        horizontalLayout_3->addWidget(m_pSelectedPortLineEdit);

        m_pSelectedMaskLineEdit = new QLineEdit(m_pMoreSetGroupBox);
        m_pSelectedMaskLineEdit->setObjectName(QStringLiteral("m_pSelectedMaskLineEdit"));
        m_pSelectedMaskLineEdit->setFont(font);

        horizontalLayout_3->addWidget(m_pSelectedMaskLineEdit);

        m_pSelectedGatewayLineEdit = new QLineEdit(m_pMoreSetGroupBox);
        m_pSelectedGatewayLineEdit->setObjectName(QStringLiteral("m_pSelectedGatewayLineEdit"));
        m_pSelectedGatewayLineEdit->setFont(font);

        horizontalLayout_3->addWidget(m_pSelectedGatewayLineEdit);

        m_pSelectedMacLineEdit = new QLineEdit(m_pMoreSetGroupBox);
        m_pSelectedMacLineEdit->setObjectName(QStringLiteral("m_pSelectedMacLineEdit"));
        m_pSelectedMacLineEdit->setEnabled(false);
        m_pSelectedMacLineEdit->setFont(font);

        horizontalLayout_3->addWidget(m_pSelectedMacLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        m_pModifyDeviceConfigBtn = new QPushButton(m_pMoreSetGroupBox);
        m_pModifyDeviceConfigBtn->setObjectName(QStringLiteral("m_pModifyDeviceConfigBtn"));
        m_pModifyDeviceConfigBtn->setMinimumSize(QSize(0, 0));
        m_pModifyDeviceConfigBtn->setFont(font);

        horizontalLayout_4->addWidget(m_pModifyDeviceConfigBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(m_pMoreSetGroupBox);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(BCSettingCommunicationDlg);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        horizontalLayout_7 = new QHBoxLayout(groupBox_4);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_7->addWidget(label_16);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        m_pPreviewComboBox = new QComboBox(groupBox_4);
        m_pPreviewComboBox->setObjectName(QStringLiteral("m_pPreviewComboBox"));
        m_pPreviewComboBox->setMinimumSize(QSize(120, 0));
        m_pPreviewComboBox->setFocusPolicy(Qt::ClickFocus);
        m_pPreviewComboBox->setEditable(true);

        horizontalLayout_7->addWidget(m_pPreviewComboBox);


        verticalLayout_3->addWidget(groupBox_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pDemoModeBtn = new QPushButton(BCSettingCommunicationDlg);
        m_pDemoModeBtn->setObjectName(QStringLiteral("m_pDemoModeBtn"));
        m_pDemoModeBtn->setFont(font);

        horizontalLayout->addWidget(m_pDemoModeBtn);

        m_pOkBtn = new QPushButton(BCSettingCommunicationDlg);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        m_pOkBtn->setMinimumSize(QSize(0, 0));
        m_pOkBtn->setFont(font);

        horizontalLayout->addWidget(m_pOkBtn);

        m_pCancelBtn = new QPushButton(BCSettingCommunicationDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setMinimumSize(QSize(0, 0));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        verticalLayout_3->addLayout(horizontalLayout);

        QWidget::setTabOrder(m_pDemoModeBtn, m_pOkBtn);
        QWidget::setTabOrder(m_pOkBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pUseComConnectRadioBtn);
        QWidget::setTabOrder(m_pUseComConnectRadioBtn, m_pComComBox);
        QWidget::setTabOrder(m_pComComBox, m_pBaudRateComBox);
        QWidget::setTabOrder(m_pBaudRateComBox, m_pDataBitComBox);
        QWidget::setTabOrder(m_pDataBitComBox, m_pStopBitComBox);
        QWidget::setTabOrder(m_pStopBitComBox, m_pCheckBitComBox);
        QWidget::setTabOrder(m_pCheckBitComBox, m_pStreamCtrlComBox);
        QWidget::setTabOrder(m_pStreamCtrlComBox, m_pUseNetConnectRadioBtn);
        QWidget::setTabOrder(m_pUseNetConnectRadioBtn, m_pNetIPLineEdit);
        QWidget::setTabOrder(m_pNetIPLineEdit, m_pNetPortLineEdit);
        QWidget::setTabOrder(m_pNetPortLineEdit, m_pSearchDeviceBtn);
        QWidget::setTabOrder(m_pSearchDeviceBtn, m_pMoreSetBtn);
        QWidget::setTabOrder(m_pMoreSetBtn, m_pSelectedIPLineEdit);
        QWidget::setTabOrder(m_pSelectedIPLineEdit, m_pSelectedPortLineEdit);
        QWidget::setTabOrder(m_pSelectedPortLineEdit, m_pSelectedMaskLineEdit);
        QWidget::setTabOrder(m_pSelectedMaskLineEdit, m_pSelectedGatewayLineEdit);
        QWidget::setTabOrder(m_pSelectedGatewayLineEdit, m_pSelectedMacLineEdit);
        QWidget::setTabOrder(m_pSelectedMacLineEdit, m_pModifyDeviceConfigBtn);
        QWidget::setTabOrder(m_pModifyDeviceConfigBtn, m_pDeviceTableWidget);
        QWidget::setTabOrder(m_pDeviceTableWidget, m_pSelectedNameLineEdit);

        retranslateUi(BCSettingCommunicationDlg);

        QMetaObject::connectSlotsByName(BCSettingCommunicationDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingCommunicationDlg)
    {
        BCSettingCommunicationDlg->setWindowTitle(QApplication::translate("BCSettingCommunicationDlg", "Dialog", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("BCSettingCommunicationDlg", "\350\256\276\345\244\207\347\261\273\345\236\213", Q_NULLPTR));
        m_pDeviceType->clear();
        m_pDeviceType->insertItems(0, QStringList()
         << QApplication::translate("BCSettingCommunicationDlg", "VP2000", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "VP2000A", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "VP4000", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "Matrix", Q_NULLPTR)
        );
        m_pJointCheckBox->setText(QApplication::translate("BCSettingCommunicationDlg", "\346\230\257\345\220\246\347\237\251\351\230\265\350\201\224\346\216\247", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingCommunicationDlg", "\346\216\247\345\210\266\346\226\271\345\274\217", Q_NULLPTR));
        m_pUseComConnectRadioBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "COM", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingCommunicationDlg", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingCommunicationDlg", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        m_pBaudRateComBox->clear();
        m_pBaudRateComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingCommunicationDlg", "1200", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "2400", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "4800", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "9600", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "14400", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "19200", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "38400", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "56000", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "57600", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "115200", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("BCSettingCommunicationDlg", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        m_pDataBitComBox->clear();
        m_pDataBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingCommunicationDlg", "5", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "6", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "7", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "8", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("BCSettingCommunicationDlg", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        m_pStopBitComBox->clear();
        m_pStopBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingCommunicationDlg", "1", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "2", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "3", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("BCSettingCommunicationDlg", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        m_pCheckBitComBox->clear();
        m_pCheckBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingCommunicationDlg", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "Odd", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "Even", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "Mark", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "Space", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("BCSettingCommunicationDlg", "\346\265\201\346\216\247\345\210\266", Q_NULLPTR));
        m_pStreamCtrlComBox->clear();
        m_pStreamCtrlComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingCommunicationDlg", "Hardware", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "Software", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingCommunicationDlg", "Custom", Q_NULLPTR)
        );
        m_pUseNetConnectRadioBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "NET", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingCommunicationDlg", "IP\345\234\260\345\235\200", Q_NULLPTR));
        m_pNetIPLineEdit->setText(QString());
        label_12->setText(QApplication::translate("BCSettingCommunicationDlg", "\347\253\257\345\217\243", Q_NULLPTR));
        m_pNetPortLineEdit->setText(QString());
        groupBox_2->setTitle(QApplication::translate("BCSettingCommunicationDlg", "\345\234\250\347\272\277\350\256\276\345\244\207", Q_NULLPTR));
        m_pSearchDeviceBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "\345\210\267\346\226\260", Q_NULLPTR));
        m_pMoreSetBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "\347\275\221\347\273\234\350\256\276\347\275\256 >>", Q_NULLPTR));
        m_pMoreSetGroupBox->setTitle(QApplication::translate("BCSettingCommunicationDlg", "\347\275\221\347\273\234\351\205\215\347\275\256", Q_NULLPTR));
        label_13->setText(QApplication::translate("BCSettingCommunicationDlg", "\345\220\215\347\247\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingCommunicationDlg", "IP", Q_NULLPTR));
        label_14->setText(QApplication::translate("BCSettingCommunicationDlg", "\347\253\257\345\217\243", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingCommunicationDlg", "\345\255\220\347\275\221\346\216\251\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingCommunicationDlg", "\347\275\221\345\205\263", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingCommunicationDlg", "MAC", Q_NULLPTR));
        m_pModifyDeviceConfigBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "\344\277\256\346\224\271", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("BCSettingCommunicationDlg", "\345\234\250\347\272\277\345\233\236\346\230\276\350\256\276\345\244\207", Q_NULLPTR));
        label_16->setText(QApplication::translate("BCSettingCommunicationDlg", "IP\345\234\260\345\235\200", Q_NULLPTR));
        m_pDemoModeBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "\346\274\224\347\244\272\346\250\241\345\274\217", Q_NULLPTR));
        m_pOkBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingCommunicationDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingCommunicationDlg: public Ui_BCSettingCommunicationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGCOMMUNICATIONDLG_H
