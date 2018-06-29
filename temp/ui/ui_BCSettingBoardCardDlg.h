/********************************************************************************
** Form generated from reading UI file 'BCSettingBoardCardDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGBOARDCARDDLG_H
#define UI_BCSETTINGBOARDCARDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "BCSettingBoardCardDlg.h"

QT_BEGIN_NAMESPACE

class Ui_BCSettingBoardCardDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *m_pBoardGroupBox;
    QVBoxLayout *verticalLayout_3;
    BCSettingBoardCardGraphicsView *m_pGraphicsView;
    QGroupBox *m_pSetGroupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLineEdit *m_pGroupLineEdit;
    QLineEdit *m_pPortLineEdit;
    QLineEdit *m_pPortNameLineEdit;
    QLabel *m_pCardTypeLabel;
    QLabel *m_pPortLabel;
    QLabel *m_pGroupLabel;
    QLineEdit *m_pCardTypeLineEdit;
    QLabel *m_pPortNameLabel;
    QLabel *m_pXXLabel;
    QLineEdit *m_pYYLineEdit;
    QLineEdit *m_pArrayYLineEdit;
    QLabel *m_pYYLabel;
    QLabel *m_pArrayPosYLabel;
    QLineEdit *m_pArrayPosYLineEdit;
    QLineEdit *m_pXXLineEdit;
    QLabel *m_pArrayPosXLabel;
    QLineEdit *m_pArrayPosXLineEdit;
    QLabel *m_pArrayYLabel;
    QLineEdit *m_pArrayXLineEdit;
    QLabel *m_pArrayXLabel;
    QLineEdit *m_pTypeLineEdit;
    QLabel *m_pTypeLabel;
    QLabel *m_pWarningLabel;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_pApplyBtn;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QLabel *label_17;
    QLineEdit *m_pVoltageOfDeviceLineEdit;
    QLabel *label_20;
    QLineEdit *m_RotationSpeedOfFan1LineEdit;
    QLabel *label_21;
    QLineEdit *m_RotationSpeedOfFan2LineEdit;
    QLabel *label_16;
    QLineEdit *m_RotationSpeedOfFan3LineEdit;
    QLabel *label_15;
    QLineEdit *m_RotationSpeedOfFan4LineEdit;
    QLabel *label_22;
    QLineEdit *m_pElectricityOfDeviceLineEdit;
    QLabel *label_19;
    QLineEdit *m_RotationSpeedOfFan5LineEdit;
    QLabel *label_14;
    QLineEdit *m_RotationSpeedOfFan6LineEdit;
    QLabel *label_18;
    QLineEdit *m_RotationSpeedOfFan7LineEdit;
    QLabel *label_13;
    QLineEdit *m_RotationSpeedOfFan8LineEdit;
    QGroupBox *m_pBoardCardGB;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *m_pCoreVoltageOfChip1LineEdit;
    QLabel *label_7;
    QLineEdit *m_pRoundVoltageOfChip1LineEdit;
    QLabel *label_2;
    QLineEdit *m_pCoreElectricityOfChip1LineEdit;
    QLabel *label_8;
    QLineEdit *m_pRoundElectricityOfChip1LineEdit;
    QLabel *label_3;
    QLineEdit *m_pCoreVoltageOfChip2LineEdit;
    QLabel *label_9;
    QLineEdit *m_pRoundVoltageOfChip2LineEdit;
    QLabel *label_4;
    QLineEdit *m_pCoreElectricityOfChip2LineEdit;
    QLabel *label_10;
    QLineEdit *m_pRoundElectricityOfChip2LineEdit;
    QLabel *label_5;
    QLineEdit *m_pVoltageOfMemorizerLineEdit;
    QLabel *label_11;
    QLineEdit *m_pElectricityOfMemorizerLineEdit;
    QLabel *label_6;
    QLineEdit *m_pVoltageOfInputLineEdit;
    QLabel *label_12;
    QLineEdit *m_pElectricityOfInputLineEdit;

    void setupUi(QDialog *BCSettingBoardCardDlg)
    {
        if (BCSettingBoardCardDlg->objectName().isEmpty())
            BCSettingBoardCardDlg->setObjectName(QStringLiteral("BCSettingBoardCardDlg"));
        BCSettingBoardCardDlg->resize(1144, 648);
        verticalLayout = new QVBoxLayout(BCSettingBoardCardDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pBoardGroupBox = new QGroupBox(BCSettingBoardCardDlg);
        m_pBoardGroupBox->setObjectName(QStringLiteral("m_pBoardGroupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pBoardGroupBox->setFont(font);
        verticalLayout_3 = new QVBoxLayout(m_pBoardGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        m_pGraphicsView = new BCSettingBoardCardGraphicsView(m_pBoardGroupBox);
        m_pGraphicsView->setObjectName(QStringLiteral("m_pGraphicsView"));

        verticalLayout_3->addWidget(m_pGraphicsView);


        horizontalLayout->addWidget(m_pBoardGroupBox);

        m_pSetGroupBox = new QGroupBox(BCSettingBoardCardDlg);
        m_pSetGroupBox->setObjectName(QStringLiteral("m_pSetGroupBox"));
        m_pSetGroupBox->setMaximumSize(QSize(200, 16777215));
        m_pSetGroupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(m_pSetGroupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        m_pGroupLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pGroupLineEdit->setObjectName(QStringLiteral("m_pGroupLineEdit"));
        m_pGroupLineEdit->setMinimumSize(QSize(0, 0));
        m_pGroupLineEdit->setMaximumSize(QSize(16777215, 16777215));
        m_pGroupLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pGroupLineEdit, 0, 2, 2, 2);

        m_pPortLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pPortLineEdit->setObjectName(QStringLiteral("m_pPortLineEdit"));
        m_pPortLineEdit->setEnabled(false);
        m_pPortLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pPortLineEdit, 5, 2, 1, 2);

        m_pPortNameLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pPortNameLineEdit->setObjectName(QStringLiteral("m_pPortNameLineEdit"));
        m_pPortNameLineEdit->setEnabled(false);
        m_pPortNameLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pPortNameLineEdit, 4, 2, 1, 2);

        m_pCardTypeLabel = new QLabel(m_pSetGroupBox);
        m_pCardTypeLabel->setObjectName(QStringLiteral("m_pCardTypeLabel"));
        m_pCardTypeLabel->setFont(font);

        gridLayout_3->addWidget(m_pCardTypeLabel, 3, 0, 1, 2);

        m_pPortLabel = new QLabel(m_pSetGroupBox);
        m_pPortLabel->setObjectName(QStringLiteral("m_pPortLabel"));
        m_pPortLabel->setFont(font);

        gridLayout_3->addWidget(m_pPortLabel, 5, 0, 1, 2);

        m_pGroupLabel = new QLabel(m_pSetGroupBox);
        m_pGroupLabel->setObjectName(QStringLiteral("m_pGroupLabel"));
        m_pGroupLabel->setFont(font);

        gridLayout_3->addWidget(m_pGroupLabel, 0, 0, 2, 2);

        m_pCardTypeLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pCardTypeLineEdit->setObjectName(QStringLiteral("m_pCardTypeLineEdit"));
        m_pCardTypeLineEdit->setEnabled(false);
        m_pCardTypeLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pCardTypeLineEdit, 3, 2, 1, 2);

        m_pPortNameLabel = new QLabel(m_pSetGroupBox);
        m_pPortNameLabel->setObjectName(QStringLiteral("m_pPortNameLabel"));
        m_pPortNameLabel->setFont(font);

        gridLayout_3->addWidget(m_pPortNameLabel, 4, 0, 1, 2);

        m_pXXLabel = new QLabel(m_pSetGroupBox);
        m_pXXLabel->setObjectName(QStringLiteral("m_pXXLabel"));
        m_pXXLabel->setFont(font);

        gridLayout_3->addWidget(m_pXXLabel, 6, 0, 1, 2);

        m_pYYLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pYYLineEdit->setObjectName(QStringLiteral("m_pYYLineEdit"));
        m_pYYLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pYYLineEdit, 7, 2, 1, 2);

        m_pArrayYLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pArrayYLineEdit->setObjectName(QStringLiteral("m_pArrayYLineEdit"));
        m_pArrayYLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pArrayYLineEdit, 9, 2, 1, 2);

        m_pYYLabel = new QLabel(m_pSetGroupBox);
        m_pYYLabel->setObjectName(QStringLiteral("m_pYYLabel"));
        m_pYYLabel->setFont(font);

        gridLayout_3->addWidget(m_pYYLabel, 7, 0, 1, 2);

        m_pArrayPosYLabel = new QLabel(m_pSetGroupBox);
        m_pArrayPosYLabel->setObjectName(QStringLiteral("m_pArrayPosYLabel"));
        m_pArrayPosYLabel->setFont(font);

        gridLayout_3->addWidget(m_pArrayPosYLabel, 11, 0, 1, 2);

        m_pArrayPosYLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pArrayPosYLineEdit->setObjectName(QStringLiteral("m_pArrayPosYLineEdit"));
        m_pArrayPosYLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pArrayPosYLineEdit, 11, 2, 1, 2);

        m_pXXLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pXXLineEdit->setObjectName(QStringLiteral("m_pXXLineEdit"));
        m_pXXLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pXXLineEdit, 6, 2, 1, 2);

        m_pArrayPosXLabel = new QLabel(m_pSetGroupBox);
        m_pArrayPosXLabel->setObjectName(QStringLiteral("m_pArrayPosXLabel"));
        m_pArrayPosXLabel->setFont(font);

        gridLayout_3->addWidget(m_pArrayPosXLabel, 10, 0, 1, 2);

        m_pArrayPosXLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pArrayPosXLineEdit->setObjectName(QStringLiteral("m_pArrayPosXLineEdit"));
        m_pArrayPosXLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pArrayPosXLineEdit, 10, 2, 1, 2);

        m_pArrayYLabel = new QLabel(m_pSetGroupBox);
        m_pArrayYLabel->setObjectName(QStringLiteral("m_pArrayYLabel"));
        m_pArrayYLabel->setFont(font);

        gridLayout_3->addWidget(m_pArrayYLabel, 9, 0, 1, 2);

        m_pArrayXLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pArrayXLineEdit->setObjectName(QStringLiteral("m_pArrayXLineEdit"));
        m_pArrayXLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pArrayXLineEdit, 8, 2, 1, 2);

        m_pArrayXLabel = new QLabel(m_pSetGroupBox);
        m_pArrayXLabel->setObjectName(QStringLiteral("m_pArrayXLabel"));
        m_pArrayXLabel->setFont(font);

        gridLayout_3->addWidget(m_pArrayXLabel, 8, 0, 1, 2);

        m_pTypeLineEdit = new QLineEdit(m_pSetGroupBox);
        m_pTypeLineEdit->setObjectName(QStringLiteral("m_pTypeLineEdit"));
        m_pTypeLineEdit->setEnabled(false);
        m_pTypeLineEdit->setFont(font);

        gridLayout_3->addWidget(m_pTypeLineEdit, 2, 2, 1, 2);

        m_pTypeLabel = new QLabel(m_pSetGroupBox);
        m_pTypeLabel->setObjectName(QStringLiteral("m_pTypeLabel"));
        m_pTypeLabel->setFont(font);

        gridLayout_3->addWidget(m_pTypeLabel, 2, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout_3);

        m_pWarningLabel = new QLabel(m_pSetGroupBox);
        m_pWarningLabel->setObjectName(QStringLiteral("m_pWarningLabel"));
        m_pWarningLabel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        m_pWarningLabel->setTextFormat(Qt::AutoText);
        m_pWarningLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        m_pWarningLabel->setWordWrap(true);

        verticalLayout_2->addWidget(m_pWarningLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        m_pApplyBtn = new QPushButton(m_pSetGroupBox);
        m_pApplyBtn->setObjectName(QStringLiteral("m_pApplyBtn"));
        m_pApplyBtn->setMinimumSize(QSize(0, 0));
        m_pApplyBtn->setFont(font);

        horizontalLayout_4->addWidget(m_pApplyBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(m_pSetGroupBox);


        verticalLayout->addLayout(horizontalLayout);

        groupBox_5 = new QGroupBox(BCSettingBoardCardDlg);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(16777215, 100));
        groupBox_5->setFont(font);
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        gridLayout->addWidget(label_17, 0, 0, 1, 1);

        m_pVoltageOfDeviceLineEdit = new QLineEdit(groupBox_5);
        m_pVoltageOfDeviceLineEdit->setObjectName(QStringLiteral("m_pVoltageOfDeviceLineEdit"));
        m_pVoltageOfDeviceLineEdit->setFont(font);

        gridLayout->addWidget(m_pVoltageOfDeviceLineEdit, 0, 1, 1, 1);

        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        gridLayout->addWidget(label_20, 0, 2, 1, 1);

        m_RotationSpeedOfFan1LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan1LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan1LineEdit"));
        m_RotationSpeedOfFan1LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan1LineEdit, 0, 3, 1, 1);

        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        gridLayout->addWidget(label_21, 0, 4, 1, 1);

        m_RotationSpeedOfFan2LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan2LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan2LineEdit"));
        m_RotationSpeedOfFan2LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan2LineEdit, 0, 5, 1, 1);

        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        gridLayout->addWidget(label_16, 0, 6, 1, 1);

        m_RotationSpeedOfFan3LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan3LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan3LineEdit"));
        m_RotationSpeedOfFan3LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan3LineEdit, 0, 7, 1, 1);

        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 0, 8, 1, 1);

        m_RotationSpeedOfFan4LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan4LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan4LineEdit"));
        m_RotationSpeedOfFan4LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan4LineEdit, 0, 9, 1, 1);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font);

        gridLayout->addWidget(label_22, 1, 0, 1, 1);

        m_pElectricityOfDeviceLineEdit = new QLineEdit(groupBox_5);
        m_pElectricityOfDeviceLineEdit->setObjectName(QStringLiteral("m_pElectricityOfDeviceLineEdit"));
        m_pElectricityOfDeviceLineEdit->setFont(font);

        gridLayout->addWidget(m_pElectricityOfDeviceLineEdit, 1, 1, 1, 1);

        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        gridLayout->addWidget(label_19, 1, 2, 1, 1);

        m_RotationSpeedOfFan5LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan5LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan5LineEdit"));
        m_RotationSpeedOfFan5LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan5LineEdit, 1, 3, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 1, 4, 1, 1);

        m_RotationSpeedOfFan6LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan6LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan6LineEdit"));
        m_RotationSpeedOfFan6LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan6LineEdit, 1, 5, 1, 1);

        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        gridLayout->addWidget(label_18, 1, 6, 1, 1);

        m_RotationSpeedOfFan7LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan7LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan7LineEdit"));
        m_RotationSpeedOfFan7LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan7LineEdit, 1, 7, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 1, 8, 1, 1);

        m_RotationSpeedOfFan8LineEdit = new QLineEdit(groupBox_5);
        m_RotationSpeedOfFan8LineEdit->setObjectName(QStringLiteral("m_RotationSpeedOfFan8LineEdit"));
        m_RotationSpeedOfFan8LineEdit->setFont(font);

        gridLayout->addWidget(m_RotationSpeedOfFan8LineEdit, 1, 9, 1, 1);


        verticalLayout->addWidget(groupBox_5);

        m_pBoardCardGB = new QGroupBox(BCSettingBoardCardDlg);
        m_pBoardCardGB->setObjectName(QStringLiteral("m_pBoardCardGB"));
        m_pBoardCardGB->setMaximumSize(QSize(16777215, 120));
        m_pBoardCardGB->setFont(font);
        gridLayout_2 = new QGridLayout(m_pBoardCardGB);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(m_pBoardCardGB);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(78, 0));
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        m_pCoreVoltageOfChip1LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pCoreVoltageOfChip1LineEdit->setObjectName(QStringLiteral("m_pCoreVoltageOfChip1LineEdit"));
        m_pCoreVoltageOfChip1LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pCoreVoltageOfChip1LineEdit, 0, 1, 1, 1);

        label_7 = new QLabel(m_pBoardCardGB);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(78, 0));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        m_pRoundVoltageOfChip1LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pRoundVoltageOfChip1LineEdit->setObjectName(QStringLiteral("m_pRoundVoltageOfChip1LineEdit"));
        m_pRoundVoltageOfChip1LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pRoundVoltageOfChip1LineEdit, 0, 3, 1, 1);

        label_2 = new QLabel(m_pBoardCardGB);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(54, 0));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 4, 1, 1);

        m_pCoreElectricityOfChip1LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pCoreElectricityOfChip1LineEdit->setObjectName(QStringLiteral("m_pCoreElectricityOfChip1LineEdit"));
        m_pCoreElectricityOfChip1LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pCoreElectricityOfChip1LineEdit, 0, 5, 1, 1);

        label_8 = new QLabel(m_pBoardCardGB);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(78, 0));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 0, 6, 1, 1);

        m_pRoundElectricityOfChip1LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pRoundElectricityOfChip1LineEdit->setObjectName(QStringLiteral("m_pRoundElectricityOfChip1LineEdit"));
        m_pRoundElectricityOfChip1LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pRoundElectricityOfChip1LineEdit, 0, 7, 1, 1);

        label_3 = new QLabel(m_pBoardCardGB);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(78, 0));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        m_pCoreVoltageOfChip2LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pCoreVoltageOfChip2LineEdit->setObjectName(QStringLiteral("m_pCoreVoltageOfChip2LineEdit"));
        m_pCoreVoltageOfChip2LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pCoreVoltageOfChip2LineEdit, 1, 1, 1, 1);

        label_9 = new QLabel(m_pBoardCardGB);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(78, 0));
        label_9->setFont(font);

        gridLayout_2->addWidget(label_9, 1, 2, 1, 1);

        m_pRoundVoltageOfChip2LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pRoundVoltageOfChip2LineEdit->setObjectName(QStringLiteral("m_pRoundVoltageOfChip2LineEdit"));
        m_pRoundVoltageOfChip2LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pRoundVoltageOfChip2LineEdit, 1, 3, 1, 1);

        label_4 = new QLabel(m_pBoardCardGB);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(54, 0));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 1, 4, 1, 1);

        m_pCoreElectricityOfChip2LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pCoreElectricityOfChip2LineEdit->setObjectName(QStringLiteral("m_pCoreElectricityOfChip2LineEdit"));
        m_pCoreElectricityOfChip2LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pCoreElectricityOfChip2LineEdit, 1, 5, 1, 1);

        label_10 = new QLabel(m_pBoardCardGB);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(78, 0));
        label_10->setFont(font);

        gridLayout_2->addWidget(label_10, 1, 6, 1, 1);

        m_pRoundElectricityOfChip2LineEdit = new QLineEdit(m_pBoardCardGB);
        m_pRoundElectricityOfChip2LineEdit->setObjectName(QStringLiteral("m_pRoundElectricityOfChip2LineEdit"));
        m_pRoundElectricityOfChip2LineEdit->setFont(font);

        gridLayout_2->addWidget(m_pRoundElectricityOfChip2LineEdit, 1, 7, 1, 1);

        label_5 = new QLabel(m_pBoardCardGB);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(78, 0));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        m_pVoltageOfMemorizerLineEdit = new QLineEdit(m_pBoardCardGB);
        m_pVoltageOfMemorizerLineEdit->setObjectName(QStringLiteral("m_pVoltageOfMemorizerLineEdit"));
        m_pVoltageOfMemorizerLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pVoltageOfMemorizerLineEdit, 2, 1, 1, 1);

        label_11 = new QLabel(m_pBoardCardGB);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(78, 0));
        label_11->setFont(font);

        gridLayout_2->addWidget(label_11, 2, 2, 1, 1);

        m_pElectricityOfMemorizerLineEdit = new QLineEdit(m_pBoardCardGB);
        m_pElectricityOfMemorizerLineEdit->setObjectName(QStringLiteral("m_pElectricityOfMemorizerLineEdit"));
        m_pElectricityOfMemorizerLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pElectricityOfMemorizerLineEdit, 2, 3, 1, 1);

        label_6 = new QLabel(m_pBoardCardGB);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(54, 0));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 2, 4, 1, 1);

        m_pVoltageOfInputLineEdit = new QLineEdit(m_pBoardCardGB);
        m_pVoltageOfInputLineEdit->setObjectName(QStringLiteral("m_pVoltageOfInputLineEdit"));
        m_pVoltageOfInputLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pVoltageOfInputLineEdit, 2, 5, 1, 1);

        label_12 = new QLabel(m_pBoardCardGB);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(78, 0));
        label_12->setFont(font);

        gridLayout_2->addWidget(label_12, 2, 6, 1, 1);

        m_pElectricityOfInputLineEdit = new QLineEdit(m_pBoardCardGB);
        m_pElectricityOfInputLineEdit->setObjectName(QStringLiteral("m_pElectricityOfInputLineEdit"));
        m_pElectricityOfInputLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pElectricityOfInputLineEdit, 2, 7, 1, 1);


        verticalLayout->addWidget(m_pBoardCardGB);


        retranslateUi(BCSettingBoardCardDlg);

        QMetaObject::connectSlotsByName(BCSettingBoardCardDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingBoardCardDlg)
    {
        BCSettingBoardCardDlg->setWindowTitle(QApplication::translate("BCSettingBoardCardDlg", "Dialog", Q_NULLPTR));
        m_pBoardGroupBox->setTitle(QApplication::translate("BCSettingBoardCardDlg", "\346\235\277\346\247\275", Q_NULLPTR));
        m_pSetGroupBox->setTitle(QApplication::translate("BCSettingBoardCardDlg", "\350\256\276\347\275\256", Q_NULLPTR));
        m_pCardTypeLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\216\245\345\217\243\345\210\206\347\261\273", Q_NULLPTR));
        m_pPortLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\235\277\344\275\215\344\275\215\347\275\256", Q_NULLPTR));
        m_pGroupLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\210\206\347\273\204\345\272\217\345\217\267", Q_NULLPTR));
        m_pPortNameLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\347\211\251\347\220\206\345\272\217\345\217\267", Q_NULLPTR));
        m_pXXLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\210\206\350\276\250\347\216\207XX", Q_NULLPTR));
        m_pYYLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\210\206\350\276\250\347\216\207YY", Q_NULLPTR));
        m_pArrayPosYLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\216\222\345\210\227\344\275\215\347\275\256Y", Q_NULLPTR));
        m_pArrayPosXLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\216\222\345\210\227\344\275\215\347\275\256X", Q_NULLPTR));
        m_pArrayYLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\216\222\345\210\227Y", Q_NULLPTR));
        m_pArrayXLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\216\222\345\210\227X", Q_NULLPTR));
        m_pTypeLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\216\245\345\217\243\347\261\273\345\236\213", Q_NULLPTR));
        m_pWarningLabel->setText(QApplication::translate("BCSettingBoardCardDlg", "\346\217\220\347\244\272\357\274\232\345\217\252\346\234\211\351\205\215\345\257\271\347\232\204\350\276\223\345\207\272\350\212\202\347\202\271\345\217\257\347\274\226\350\276\221", Q_NULLPTR));
        m_pApplyBtn->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("BCSettingBoardCardDlg", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        label_17->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\256\276\345\244\207\347\224\265\345\216\213", Q_NULLPTR));
        label_20->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2071\350\275\254\351\200\237", Q_NULLPTR));
        label_21->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2072\350\275\254\351\200\237", Q_NULLPTR));
        label_16->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2073\350\275\254\351\200\237", Q_NULLPTR));
        label_15->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2074\350\275\254\351\200\237", Q_NULLPTR));
        label_22->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\256\276\345\244\207\347\224\265\346\265\201", Q_NULLPTR));
        label_19->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2075\350\275\254\351\200\237", Q_NULLPTR));
        label_14->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2076\350\275\254\351\200\237", Q_NULLPTR));
        label_18->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2077\350\275\254\351\200\237", Q_NULLPTR));
        label_13->setText(QApplication::translate("BCSettingBoardCardDlg", "\351\243\216\346\211\2078\350\275\254\351\200\237", Q_NULLPTR));
        m_pBoardCardGB->setTitle(QApplication::translate("BCSettingBoardCardDlg", "\346\235\277\345\215\241\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2071\346\240\270\345\277\203\347\224\265\345\216\213", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2071\345\244\226\345\233\264\347\224\265\345\216\213", Q_NULLPTR));
        m_pRoundVoltageOfChip1LineEdit->setText(QString());
        label_2->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2071\347\224\265\346\265\201", Q_NULLPTR));
        m_pCoreElectricityOfChip1LineEdit->setText(QString());
        label_8->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2071\345\244\226\345\233\264\347\224\265\346\265\201", Q_NULLPTR));
        m_pRoundElectricityOfChip1LineEdit->setText(QString());
        label_3->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2072\346\240\270\345\277\203\347\224\265\345\216\213", Q_NULLPTR));
        label_9->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2072\345\244\226\345\233\264\347\224\265\345\216\213", Q_NULLPTR));
        m_pRoundVoltageOfChip2LineEdit->setText(QString());
        label_4->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2072\347\224\265\346\265\201", Q_NULLPTR));
        m_pCoreElectricityOfChip2LineEdit->setText(QString());
        label_10->setText(QApplication::translate("BCSettingBoardCardDlg", "\350\212\257\347\211\2072\345\244\226\345\233\264\347\224\265\346\265\201", Q_NULLPTR));
        m_pRoundElectricityOfChip2LineEdit->setText(QString());
        label_5->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\255\230\345\202\250\345\231\250\347\224\265\345\216\213", Q_NULLPTR));
        label_11->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\255\230\345\202\250\345\231\250\347\224\265\346\265\201", Q_NULLPTR));
        m_pElectricityOfMemorizerLineEdit->setText(QString());
        label_6->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\205\245\345\217\243\347\224\265\345\216\213", Q_NULLPTR));
        m_pVoltageOfInputLineEdit->setText(QString());
        label_12->setText(QApplication::translate("BCSettingBoardCardDlg", "\345\205\245\345\217\243\347\224\265\346\265\201", Q_NULLPTR));
        m_pElectricityOfInputLineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCSettingBoardCardDlg: public Ui_BCSettingBoardCardDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGBOARDCARDDLG_H
