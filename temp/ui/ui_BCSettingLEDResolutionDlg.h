/********************************************************************************
** Form generated from reading UI file 'BCSettingLEDResolutionDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGLEDRESOLUTIONDLG_H
#define UI_BCSETTINGLEDRESOLUTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "BCSettingLEDResolutionDlg.h"

QT_BEGIN_NAMESPACE

class Ui_BCSettingLEDResolutionDlg
{
public:
    QVBoxLayout *verticalLayout;
    BCSettingLEDResolutionView *m_pGraphicsView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *m_pSingleXLineEdit;
    QLabel *label_2;
    QLineEdit *m_pSingleYLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_pBatchSetBtn;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *m_pBatchStandXLineEdit;
    QLabel *label_4;
    QLineEdit *m_pBatchStandYLineEdit;
    QLabel *label_6;
    QLineEdit *m_pBatchNoStandXLineEdit;
    QLabel *label_5;
    QLineEdit *m_pBatchNoStandYLineEdit;
    QLabel *label_7;
    QComboBox *m_pBatchNoStandPosCombox;
    QPushButton *m_pBatchApplyBtn;
    QSpacerItem *verticalSpacer;
    QProgressBar *m_pCmdProgressBar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pSendCmdBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingLEDResolutionDlg)
    {
        if (BCSettingLEDResolutionDlg->objectName().isEmpty())
            BCSettingLEDResolutionDlg->setObjectName(QStringLiteral("BCSettingLEDResolutionDlg"));
        BCSettingLEDResolutionDlg->resize(412, 458);
        verticalLayout = new QVBoxLayout(BCSettingLEDResolutionDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pGraphicsView = new BCSettingLEDResolutionView(BCSettingLEDResolutionDlg);
        m_pGraphicsView->setObjectName(QStringLiteral("m_pGraphicsView"));
        m_pGraphicsView->setMinimumSize(QSize(0, 150));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pGraphicsView->setFont(font);

        verticalLayout->addWidget(m_pGraphicsView);

        groupBox = new QGroupBox(BCSettingLEDResolutionDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        m_pSingleXLineEdit = new QLineEdit(groupBox);
        m_pSingleXLineEdit->setObjectName(QStringLiteral("m_pSingleXLineEdit"));
        m_pSingleXLineEdit->setFont(font);

        horizontalLayout->addWidget(m_pSingleXLineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        m_pSingleYLineEdit = new QLineEdit(groupBox);
        m_pSingleYLineEdit->setObjectName(QStringLiteral("m_pSingleYLineEdit"));
        m_pSingleYLineEdit->setFont(font);

        horizontalLayout->addWidget(m_pSingleYLineEdit);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        m_pBatchSetBtn = new QPushButton(BCSettingLEDResolutionDlg);
        m_pBatchSetBtn->setObjectName(QStringLiteral("m_pBatchSetBtn"));
        m_pBatchSetBtn->setFont(font);

        horizontalLayout_3->addWidget(m_pBatchSetBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_2 = new QGroupBox(BCSettingLEDResolutionDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        m_pBatchStandXLineEdit = new QLineEdit(groupBox_2);
        m_pBatchStandXLineEdit->setObjectName(QStringLiteral("m_pBatchStandXLineEdit"));
        m_pBatchStandXLineEdit->setFont(font);

        gridLayout->addWidget(m_pBatchStandXLineEdit, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        m_pBatchStandYLineEdit = new QLineEdit(groupBox_2);
        m_pBatchStandYLineEdit->setObjectName(QStringLiteral("m_pBatchStandYLineEdit"));
        m_pBatchStandYLineEdit->setFont(font);

        gridLayout->addWidget(m_pBatchStandYLineEdit, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        m_pBatchNoStandXLineEdit = new QLineEdit(groupBox_2);
        m_pBatchNoStandXLineEdit->setObjectName(QStringLiteral("m_pBatchNoStandXLineEdit"));
        m_pBatchNoStandXLineEdit->setFont(font);

        gridLayout->addWidget(m_pBatchNoStandXLineEdit, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        m_pBatchNoStandYLineEdit = new QLineEdit(groupBox_2);
        m_pBatchNoStandYLineEdit->setObjectName(QStringLiteral("m_pBatchNoStandYLineEdit"));
        m_pBatchNoStandYLineEdit->setFont(font);

        gridLayout->addWidget(m_pBatchNoStandYLineEdit, 1, 3, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        m_pBatchNoStandPosCombox = new QComboBox(groupBox_2);
        m_pBatchNoStandPosCombox->setObjectName(QStringLiteral("m_pBatchNoStandPosCombox"));
        m_pBatchNoStandPosCombox->setFont(font);

        gridLayout->addWidget(m_pBatchNoStandPosCombox, 2, 1, 1, 1);

        m_pBatchApplyBtn = new QPushButton(groupBox_2);
        m_pBatchApplyBtn->setObjectName(QStringLiteral("m_pBatchApplyBtn"));
        m_pBatchApplyBtn->setFont(font);

        gridLayout->addWidget(m_pBatchApplyBtn, 2, 3, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        m_pCmdProgressBar = new QProgressBar(BCSettingLEDResolutionDlg);
        m_pCmdProgressBar->setObjectName(QStringLiteral("m_pCmdProgressBar"));
        m_pCmdProgressBar->setValue(24);

        verticalLayout->addWidget(m_pCmdProgressBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pSendCmdBtn = new QPushButton(BCSettingLEDResolutionDlg);
        m_pSendCmdBtn->setObjectName(QStringLiteral("m_pSendCmdBtn"));
        m_pSendCmdBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pSendCmdBtn);

        m_pCancelBtn = new QPushButton(BCSettingLEDResolutionDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(m_pSingleXLineEdit, m_pSingleYLineEdit);
        QWidget::setTabOrder(m_pSingleYLineEdit, m_pBatchSetBtn);
        QWidget::setTabOrder(m_pBatchSetBtn, m_pBatchStandXLineEdit);
        QWidget::setTabOrder(m_pBatchStandXLineEdit, m_pBatchStandYLineEdit);
        QWidget::setTabOrder(m_pBatchStandYLineEdit, m_pBatchNoStandXLineEdit);
        QWidget::setTabOrder(m_pBatchNoStandXLineEdit, m_pBatchNoStandYLineEdit);
        QWidget::setTabOrder(m_pBatchNoStandYLineEdit, m_pBatchNoStandPosCombox);
        QWidget::setTabOrder(m_pBatchNoStandPosCombox, m_pSendCmdBtn);
        QWidget::setTabOrder(m_pSendCmdBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pBatchApplyBtn);
        QWidget::setTabOrder(m_pBatchApplyBtn, m_pGraphicsView);

        retranslateUi(BCSettingLEDResolutionDlg);

        QMetaObject::connectSlotsByName(BCSettingLEDResolutionDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingLEDResolutionDlg)
    {
        BCSettingLEDResolutionDlg->setWindowTitle(QApplication::translate("BCSettingLEDResolutionDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingLEDResolutionDlg", "\346\241\206\351\200\211\350\256\276\347\275\256\345\261\217\345\271\225\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\345\210\206\350\276\250\347\216\207X", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\345\210\206\350\276\250\347\216\207Y", Q_NULLPTR));
        m_pBatchSetBtn->setText(QApplication::translate("BCSettingLEDResolutionDlg", ">>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCSettingLEDResolutionDlg", "\346\211\271\351\207\217\350\256\276\347\275\256\345\261\217\345\271\225\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\346\240\207\345\207\206\345\210\206\350\276\250\347\216\207X", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\346\240\207\345\207\206\345\210\206\350\276\250\347\216\207Y", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\351\235\236\346\240\207\345\207\206\345\210\206\350\276\250\347\216\207X", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\351\235\236\346\240\207\345\207\206\345\210\206\350\276\250\347\216\207Y", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\351\235\236\346\240\207\345\207\206\345\261\217\345\271\225\344\275\215\347\275\256", Q_NULLPTR));
        m_pBatchNoStandPosCombox->clear();
        m_pBatchNoStandPosCombox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingLEDResolutionDlg", "\345\267\246\344\270\212", Q_NULLPTR)
         << QApplication::translate("BCSettingLEDResolutionDlg", "\345\267\246\344\270\213", Q_NULLPTR)
         << QApplication::translate("BCSettingLEDResolutionDlg", "\345\217\263\344\270\212", Q_NULLPTR)
         << QApplication::translate("BCSettingLEDResolutionDlg", "\345\217\263\344\270\213", Q_NULLPTR)
        );
        m_pBatchApplyBtn->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        m_pSendCmdBtn->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingLEDResolutionDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingLEDResolutionDlg: public Ui_BCSettingLEDResolutionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGLEDRESOLUTIONDLG_H
