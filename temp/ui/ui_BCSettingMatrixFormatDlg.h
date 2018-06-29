/********************************************************************************
** Form generated from reading UI file 'BCSettingMatrixFormatDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGMATRIXFORMATDLG_H
#define UI_BCSETTINGMATRIXFORMATDLG_H

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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingMatrixFormatDlg
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *m_pListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_pAddBtn;
    QPushButton *m_pRemoveBtn;
    QPushButton *m_pModifyBtn;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *m_pLoadLineEdit;
    QLineEdit *m_pSwitchCmdLineEdit;
    QCheckBox *m_pJointCheckBox;
    QLabel *label_2;
    QComboBox *m_pCmdTypeComboBox;
    QPushButton *m_pJointWithVP4000ConfigBtn;
    QLabel *m_pSaveLabel;
    QLineEdit *m_pInCountLineEdit;
    QComboBox *m_pRoomComboBox;
    QLabel *m_pSwitchCmdLabel;
    QLineEdit *m_pNameLineEdit;
    QLabel *label;
    QCheckBox *m_pJointSceneCheckBox;
    QLabel *m_pLoadLabel;
    QCheckBox *m_pJointWithVP4000CheckBox;
    QLabel *label_13;
    QLineEdit *m_pOutCountLineEdit;
    QLineEdit *m_pSaveLineEdit;
    QLabel *label_3;
    QSpinBox *m_pStartIDSpinBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_12;
    QLineEdit *m_pNetIPLineEdit;
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
    QLineEdit *m_pNetPortLineEdit;
    QRadioButton *m_pUseComConnectRadioBtn;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingMatrixFormatDlg)
    {
        if (BCSettingMatrixFormatDlg->objectName().isEmpty())
            BCSettingMatrixFormatDlg->setObjectName(QStringLiteral("BCSettingMatrixFormatDlg"));
        BCSettingMatrixFormatDlg->resize(456, 694);
        verticalLayout = new QVBoxLayout(BCSettingMatrixFormatDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pListWidget = new QListWidget(BCSettingMatrixFormatDlg);
        m_pListWidget->setObjectName(QStringLiteral("m_pListWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pListWidget->setFont(font);

        verticalLayout->addWidget(m_pListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pAddBtn = new QPushButton(BCSettingMatrixFormatDlg);
        m_pAddBtn->setObjectName(QStringLiteral("m_pAddBtn"));
        m_pAddBtn->setFont(font);

        horizontalLayout->addWidget(m_pAddBtn);

        m_pRemoveBtn = new QPushButton(BCSettingMatrixFormatDlg);
        m_pRemoveBtn->setObjectName(QStringLiteral("m_pRemoveBtn"));
        m_pRemoveBtn->setFont(font);

        horizontalLayout->addWidget(m_pRemoveBtn);

        m_pModifyBtn = new QPushButton(BCSettingMatrixFormatDlg);
        m_pModifyBtn->setObjectName(QStringLiteral("m_pModifyBtn"));
        m_pModifyBtn->setFont(font);

        horizontalLayout->addWidget(m_pModifyBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_14 = new QLabel(BCSettingMatrixFormatDlg);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout_2->addWidget(label_14, 8, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(17, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        m_pLoadLineEdit = new QLineEdit(BCSettingMatrixFormatDlg);
        m_pLoadLineEdit->setObjectName(QStringLiteral("m_pLoadLineEdit"));
        m_pLoadLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pLoadLineEdit, 5, 2, 1, 1);

        m_pSwitchCmdLineEdit = new QLineEdit(BCSettingMatrixFormatDlg);
        m_pSwitchCmdLineEdit->setObjectName(QStringLiteral("m_pSwitchCmdLineEdit"));
        m_pSwitchCmdLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pSwitchCmdLineEdit, 4, 2, 1, 1);

        m_pJointCheckBox = new QCheckBox(BCSettingMatrixFormatDlg);
        m_pJointCheckBox->setObjectName(QStringLiteral("m_pJointCheckBox"));
        m_pJointCheckBox->setFont(font);

        gridLayout_2->addWidget(m_pJointCheckBox, 0, 0, 1, 1);

        label_2 = new QLabel(BCSettingMatrixFormatDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        m_pCmdTypeComboBox = new QComboBox(BCSettingMatrixFormatDlg);
        m_pCmdTypeComboBox->setObjectName(QStringLiteral("m_pCmdTypeComboBox"));
        m_pCmdTypeComboBox->setFont(font);

        gridLayout_2->addWidget(m_pCmdTypeComboBox, 3, 2, 1, 1);

        m_pJointWithVP4000ConfigBtn = new QPushButton(BCSettingMatrixFormatDlg);
        m_pJointWithVP4000ConfigBtn->setObjectName(QStringLiteral("m_pJointWithVP4000ConfigBtn"));
        m_pJointWithVP4000ConfigBtn->setFont(font);

        gridLayout_2->addWidget(m_pJointWithVP4000ConfigBtn, 10, 2, 1, 1);

        m_pSaveLabel = new QLabel(BCSettingMatrixFormatDlg);
        m_pSaveLabel->setObjectName(QStringLiteral("m_pSaveLabel"));
        m_pSaveLabel->setFont(font);

        gridLayout_2->addWidget(m_pSaveLabel, 6, 0, 1, 1);

        m_pInCountLineEdit = new QLineEdit(BCSettingMatrixFormatDlg);
        m_pInCountLineEdit->setObjectName(QStringLiteral("m_pInCountLineEdit"));
        m_pInCountLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pInCountLineEdit, 7, 2, 1, 1);

        m_pRoomComboBox = new QComboBox(BCSettingMatrixFormatDlg);
        m_pRoomComboBox->setObjectName(QStringLiteral("m_pRoomComboBox"));
        m_pRoomComboBox->setFont(font);

        gridLayout_2->addWidget(m_pRoomComboBox, 9, 2, 1, 1);

        m_pSwitchCmdLabel = new QLabel(BCSettingMatrixFormatDlg);
        m_pSwitchCmdLabel->setObjectName(QStringLiteral("m_pSwitchCmdLabel"));
        m_pSwitchCmdLabel->setFont(font);

        gridLayout_2->addWidget(m_pSwitchCmdLabel, 4, 0, 1, 1);

        m_pNameLineEdit = new QLineEdit(BCSettingMatrixFormatDlg);
        m_pNameLineEdit->setObjectName(QStringLiteral("m_pNameLineEdit"));
        m_pNameLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pNameLineEdit, 1, 2, 1, 1);

        label = new QLabel(BCSettingMatrixFormatDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        m_pJointSceneCheckBox = new QCheckBox(BCSettingMatrixFormatDlg);
        m_pJointSceneCheckBox->setObjectName(QStringLiteral("m_pJointSceneCheckBox"));
        m_pJointSceneCheckBox->setFont(font);

        gridLayout_2->addWidget(m_pJointSceneCheckBox, 9, 0, 1, 1);

        m_pLoadLabel = new QLabel(BCSettingMatrixFormatDlg);
        m_pLoadLabel->setObjectName(QStringLiteral("m_pLoadLabel"));
        m_pLoadLabel->setFont(font);

        gridLayout_2->addWidget(m_pLoadLabel, 5, 0, 1, 1);

        m_pJointWithVP4000CheckBox = new QCheckBox(BCSettingMatrixFormatDlg);
        m_pJointWithVP4000CheckBox->setObjectName(QStringLiteral("m_pJointWithVP4000CheckBox"));
        m_pJointWithVP4000CheckBox->setFont(font);

        gridLayout_2->addWidget(m_pJointWithVP4000CheckBox, 10, 0, 1, 1);

        label_13 = new QLabel(BCSettingMatrixFormatDlg);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout_2->addWidget(label_13, 7, 0, 1, 1);

        m_pOutCountLineEdit = new QLineEdit(BCSettingMatrixFormatDlg);
        m_pOutCountLineEdit->setObjectName(QStringLiteral("m_pOutCountLineEdit"));
        m_pOutCountLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pOutCountLineEdit, 8, 2, 1, 1);

        m_pSaveLineEdit = new QLineEdit(BCSettingMatrixFormatDlg);
        m_pSaveLineEdit->setObjectName(QStringLiteral("m_pSaveLineEdit"));
        m_pSaveLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pSaveLineEdit, 6, 2, 1, 1);

        label_3 = new QLabel(BCSettingMatrixFormatDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        m_pStartIDSpinBox = new QSpinBox(BCSettingMatrixFormatDlg);
        m_pStartIDSpinBox->setObjectName(QStringLiteral("m_pStartIDSpinBox"));
        m_pStartIDSpinBox->setFont(font);

        gridLayout_2->addWidget(m_pStartIDSpinBox, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        groupBox = new QGroupBox(BCSettingMatrixFormatDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 0));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 5, 2, 1, 1);

        m_pNetIPLineEdit = new QLineEdit(groupBox);
        m_pNetIPLineEdit->setObjectName(QStringLiteral("m_pNetIPLineEdit"));
        m_pNetIPLineEdit->setEnabled(true);
        m_pNetIPLineEdit->setFont(font);
        m_pNetIPLineEdit->setReadOnly(false);

        gridLayout->addWidget(m_pNetIPLineEdit, 5, 1, 1, 1);

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
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(false);
        font1.setWeight(50);
        m_pUseNetConnectRadioBtn->setFont(font1);

        gridLayout->addWidget(m_pUseNetConnectRadioBtn, 4, 0, 1, 4);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        m_pNetPortLineEdit = new QLineEdit(groupBox);
        m_pNetPortLineEdit->setObjectName(QStringLiteral("m_pNetPortLineEdit"));
        m_pNetPortLineEdit->setFont(font);
        m_pNetPortLineEdit->setReadOnly(false);

        gridLayout->addWidget(m_pNetPortLineEdit, 5, 3, 1, 1);

        m_pUseComConnectRadioBtn = new QRadioButton(groupBox);
        m_pUseComConnectRadioBtn->setObjectName(QStringLiteral("m_pUseComConnectRadioBtn"));
        m_pUseComConnectRadioBtn->setFont(font1);

        gridLayout->addWidget(m_pUseComConnectRadioBtn, 0, 0, 1, 4);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        m_pOKBtn = new QPushButton(BCSettingMatrixFormatDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingMatrixFormatDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(m_pAddBtn, m_pRemoveBtn);
        QWidget::setTabOrder(m_pRemoveBtn, m_pModifyBtn);
        QWidget::setTabOrder(m_pModifyBtn, m_pNameLineEdit);
        QWidget::setTabOrder(m_pNameLineEdit, m_pSwitchCmdLineEdit);
        QWidget::setTabOrder(m_pSwitchCmdLineEdit, m_pLoadLineEdit);
        QWidget::setTabOrder(m_pLoadLineEdit, m_pSaveLineEdit);
        QWidget::setTabOrder(m_pSaveLineEdit, m_pInCountLineEdit);
        QWidget::setTabOrder(m_pInCountLineEdit, m_pOutCountLineEdit);
        QWidget::setTabOrder(m_pOutCountLineEdit, m_pJointSceneCheckBox);
        QWidget::setTabOrder(m_pJointSceneCheckBox, m_pRoomComboBox);
        QWidget::setTabOrder(m_pRoomComboBox, m_pJointWithVP4000CheckBox);
        QWidget::setTabOrder(m_pJointWithVP4000CheckBox, m_pJointWithVP4000ConfigBtn);
        QWidget::setTabOrder(m_pJointWithVP4000ConfigBtn, m_pUseComConnectRadioBtn);
        QWidget::setTabOrder(m_pUseComConnectRadioBtn, m_pComComBox);
        QWidget::setTabOrder(m_pComComBox, m_pBaudRateComBox);
        QWidget::setTabOrder(m_pBaudRateComBox, m_pDataBitComBox);
        QWidget::setTabOrder(m_pDataBitComBox, m_pStopBitComBox);
        QWidget::setTabOrder(m_pStopBitComBox, m_pCheckBitComBox);
        QWidget::setTabOrder(m_pCheckBitComBox, m_pStreamCtrlComBox);
        QWidget::setTabOrder(m_pStreamCtrlComBox, m_pUseNetConnectRadioBtn);
        QWidget::setTabOrder(m_pUseNetConnectRadioBtn, m_pNetIPLineEdit);
        QWidget::setTabOrder(m_pNetIPLineEdit, m_pNetPortLineEdit);
        QWidget::setTabOrder(m_pNetPortLineEdit, m_pOKBtn);
        QWidget::setTabOrder(m_pOKBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pListWidget);

        retranslateUi(BCSettingMatrixFormatDlg);

        QMetaObject::connectSlotsByName(BCSettingMatrixFormatDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingMatrixFormatDlg)
    {
        BCSettingMatrixFormatDlg->setWindowTitle(QApplication::translate("BCSettingMatrixFormatDlg", "Dialog", Q_NULLPTR));
        m_pAddBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\346\267\273\345\212\240", Q_NULLPTR));
        m_pRemoveBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\210\240\351\231\244", Q_NULLPTR));
        m_pModifyBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\344\277\256\346\224\271", Q_NULLPTR));
        label_14->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\207\272\345\217\243\346\225\260\351\207\217", Q_NULLPTR));
        m_pJointCheckBox->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\346\230\257\345\220\246\347\237\251\351\230\265\350\201\224\346\216\247", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\346\214\207\344\273\244\346\240\274\345\274\217", Q_NULLPTR));
        m_pCmdTypeComboBox->clear();
        m_pCmdTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingMatrixFormatDlg", "16\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "ASCII\347\240\201", Q_NULLPTR)
        );
        m_pJointWithVP4000ConfigBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\347\272\247\350\201\224\350\256\276\347\275\256", Q_NULLPTR));
        m_pSaveLabel->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\344\277\235\345\255\230\345\234\272\346\231\257\346\214\207\344\273\244(%1:\345\234\272\346\231\257ID;\345\246\202[%1,])", Q_NULLPTR));
        m_pSwitchCmdLabel->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\210\207\346\215\242\346\214\207\344\273\244(%1:\345\205\245\345\217\243ID,%2:\345\207\272\345\217\243ID;\345\246\202[%1b%2.])", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\220\215\347\247\260", Q_NULLPTR));
        m_pJointSceneCheckBox->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\234\272\346\231\257\350\201\224\346\216\247", Q_NULLPTR));
        m_pLoadLabel->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\350\260\203\347\224\250\345\234\272\346\231\257\346\214\207\344\273\244(%1:\345\234\272\346\231\257ID;\345\246\202[%1.])", Q_NULLPTR));
        m_pJointWithVP4000CheckBox->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\347\272\247\350\201\224", Q_NULLPTR));
        label_13->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\205\245\345\217\243\346\225\260\351\207\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\350\265\267\345\247\213\351\200\232\351\201\223ID", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingMatrixFormatDlg", "\346\216\247\345\210\266\346\226\271\345\274\217", Q_NULLPTR));
        label_12->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        m_pNetIPLineEdit->setText(QString());
        label_5->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        m_pBaudRateComBox->clear();
        m_pBaudRateComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingMatrixFormatDlg", "1200", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "2400", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "4800", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "9600", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "14400", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "19200", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "38400", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "56000", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "57600", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "115200", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        m_pDataBitComBox->clear();
        m_pDataBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingMatrixFormatDlg", "5", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "6", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "7", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "8", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        m_pStopBitComBox->clear();
        m_pStopBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingMatrixFormatDlg", "1", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "2", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "3", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        m_pCheckBitComBox->clear();
        m_pCheckBitComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingMatrixFormatDlg", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "Odd", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "Even", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "Mark", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "Space", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\346\265\201\346\216\247\345\210\266", Q_NULLPTR));
        m_pStreamCtrlComBox->clear();
        m_pStreamCtrlComBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingMatrixFormatDlg", "Hardware", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "Software", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingMatrixFormatDlg", "Custom", Q_NULLPTR)
        );
        m_pUseNetConnectRadioBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "NET", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingMatrixFormatDlg", "IP\345\234\260\345\235\200", Q_NULLPTR));
        m_pNetPortLineEdit->setText(QString());
        m_pUseComConnectRadioBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "COM", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingMatrixFormatDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingMatrixFormatDlg: public Ui_BCSettingMatrixFormatDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGMATRIXFORMATDLG_H
