/********************************************************************************
** Form generated from reading UI file 'BCSettingAutoReadInputChannelConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGAUTOREADINPUTCHANNELCONFIGDLG_H
#define UI_BCSETTINGAUTOREADINPUTCHANNELCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSettingAutoReadInputChannelConfigDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_pPCCountLineEdit;
    QLabel *label_2;
    QLineEdit *m_pPCBeginIDLineEdit;
    QLabel *label_4;
    QLineEdit *m_pIPVedioCountLineEdit;
    QLabel *label_3;
    QLineEdit *m_pIPVedioBeginIDLineEdit;
    QLabel *label_6;
    QLineEdit *m_pVedioCountLineEdit;
    QLabel *label_5;
    QLineEdit *m_pVedioBeginIDLineEdit;
    QLabel *label_8;
    QLineEdit *m_pHDCountLineEdit;
    QLabel *label_7;
    QLineEdit *m_pHDBeginIDLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;
    QCheckBox *m_pIsUseCheckBox;

    void setupUi(QDialog *BCSettingAutoReadInputChannelConfigDlg)
    {
        if (BCSettingAutoReadInputChannelConfigDlg->objectName().isEmpty())
            BCSettingAutoReadInputChannelConfigDlg->setObjectName(QStringLiteral("BCSettingAutoReadInputChannelConfigDlg"));
        BCSettingAutoReadInputChannelConfigDlg->resize(426, 214);
        gridLayout = new QGridLayout(BCSettingAutoReadInputChannelConfigDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        m_pPCCountLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pPCCountLineEdit->setObjectName(QStringLiteral("m_pPCCountLineEdit"));
        m_pPCCountLineEdit->setFont(font);

        gridLayout->addWidget(m_pPCCountLineEdit, 1, 1, 1, 2);

        label_2 = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        m_pPCBeginIDLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pPCBeginIDLineEdit->setObjectName(QStringLiteral("m_pPCBeginIDLineEdit"));
        m_pPCBeginIDLineEdit->setFont(font);

        gridLayout->addWidget(m_pPCBeginIDLineEdit, 1, 4, 1, 1);

        label_4 = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        m_pIPVedioCountLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pIPVedioCountLineEdit->setObjectName(QStringLiteral("m_pIPVedioCountLineEdit"));
        m_pIPVedioCountLineEdit->setFont(font);

        gridLayout->addWidget(m_pIPVedioCountLineEdit, 2, 1, 1, 2);

        label_3 = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 3, 1, 1);

        m_pIPVedioBeginIDLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pIPVedioBeginIDLineEdit->setObjectName(QStringLiteral("m_pIPVedioBeginIDLineEdit"));
        m_pIPVedioBeginIDLineEdit->setFont(font);

        gridLayout->addWidget(m_pIPVedioBeginIDLineEdit, 2, 4, 1, 1);

        label_6 = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        m_pVedioCountLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pVedioCountLineEdit->setObjectName(QStringLiteral("m_pVedioCountLineEdit"));
        m_pVedioCountLineEdit->setFont(font);

        gridLayout->addWidget(m_pVedioCountLineEdit, 3, 1, 1, 2);

        label_5 = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 3, 3, 1, 1);

        m_pVedioBeginIDLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pVedioBeginIDLineEdit->setObjectName(QStringLiteral("m_pVedioBeginIDLineEdit"));
        m_pVedioBeginIDLineEdit->setFont(font);

        gridLayout->addWidget(m_pVedioBeginIDLineEdit, 3, 4, 1, 1);

        label_8 = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        m_pHDCountLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pHDCountLineEdit->setObjectName(QStringLiteral("m_pHDCountLineEdit"));
        m_pHDCountLineEdit->setFont(font);

        gridLayout->addWidget(m_pHDCountLineEdit, 4, 1, 1, 2);

        label_7 = new QLabel(BCSettingAutoReadInputChannelConfigDlg);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 4, 3, 1, 1);

        m_pHDBeginIDLineEdit = new QLineEdit(BCSettingAutoReadInputChannelConfigDlg);
        m_pHDBeginIDLineEdit->setObjectName(QStringLiteral("m_pHDBeginIDLineEdit"));
        m_pHDBeginIDLineEdit->setFont(font);

        gridLayout->addWidget(m_pHDBeginIDLineEdit, 4, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingAutoReadInputChannelConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingAutoReadInputChannelConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 5);

        m_pIsUseCheckBox = new QCheckBox(BCSettingAutoReadInputChannelConfigDlg);
        m_pIsUseCheckBox->setObjectName(QStringLiteral("m_pIsUseCheckBox"));
        m_pIsUseCheckBox->setFont(font);

        gridLayout->addWidget(m_pIsUseCheckBox, 0, 0, 1, 5);

        QWidget::setTabOrder(m_pIsUseCheckBox, m_pPCCountLineEdit);
        QWidget::setTabOrder(m_pPCCountLineEdit, m_pPCBeginIDLineEdit);
        QWidget::setTabOrder(m_pPCBeginIDLineEdit, m_pIPVedioCountLineEdit);
        QWidget::setTabOrder(m_pIPVedioCountLineEdit, m_pIPVedioBeginIDLineEdit);
        QWidget::setTabOrder(m_pIPVedioBeginIDLineEdit, m_pVedioCountLineEdit);
        QWidget::setTabOrder(m_pVedioCountLineEdit, m_pVedioBeginIDLineEdit);
        QWidget::setTabOrder(m_pVedioBeginIDLineEdit, m_pHDCountLineEdit);
        QWidget::setTabOrder(m_pHDCountLineEdit, m_pHDBeginIDLineEdit);
        QWidget::setTabOrder(m_pHDBeginIDLineEdit, m_pOKBtn);
        QWidget::setTabOrder(m_pOKBtn, m_pCancelBtn);

        retranslateUi(BCSettingAutoReadInputChannelConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingAutoReadInputChannelConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingAutoReadInputChannelConfigDlg)
    {
        BCSettingAutoReadInputChannelConfigDlg->setWindowTitle(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "\347\224\265\350\204\221\346\225\260\351\207\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "\347\224\265\350\204\221\350\265\267\345\247\213ID", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "IPVideo\346\225\260\351\207\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "IPVideo\350\265\267\345\247\213ID", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "Video\346\225\260\351\207\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "Video\350\265\267\345\247\213ID", Q_NULLPTR));
        label_8->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "\351\253\230\346\270\205\346\225\260\351\207\217", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "\351\253\230\346\270\205\350\265\267\345\247\213ID", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        m_pIsUseCheckBox->setText(QApplication::translate("BCSettingAutoReadInputChannelConfigDlg", "\350\207\252\345\212\250\346\243\200\346\265\213\350\276\223\345\205\245\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingAutoReadInputChannelConfigDlg: public Ui_BCSettingAutoReadInputChannelConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGAUTOREADINPUTCHANNELCONFIGDLG_H
