/********************************************************************************
** Form generated from reading UI file 'BCSettingLanguageDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGLANGUAGEDLG_H
#define UI_BCSETTINGLANGUAGEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingLanguageDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *m_pSelectLanguageLabel;
    QComboBox *comboBox;
    QRadioButton *m_pLastSetRadioBtn;
    QRadioButton *m_pDefaultChineseRadioBtn;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_pOkBtn;
    QPushButton *m_pCancelBtn;
    QPushButton *m_pApplyBtn;

    void setupUi(QDialog *BCSettingLanguageDlg)
    {
        if (BCSettingLanguageDlg->objectName().isEmpty())
            BCSettingLanguageDlg->setObjectName(QStringLiteral("BCSettingLanguageDlg"));
        BCSettingLanguageDlg->resize(323, 130);
        verticalLayout = new QVBoxLayout(BCSettingLanguageDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pSelectLanguageLabel = new QLabel(BCSettingLanguageDlg);
        m_pSelectLanguageLabel->setObjectName(QStringLiteral("m_pSelectLanguageLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        m_pSelectLanguageLabel->setFont(font);

        horizontalLayout->addWidget(m_pSelectLanguageLabel);

        comboBox = new QComboBox(BCSettingLanguageDlg);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        m_pLastSetRadioBtn = new QRadioButton(BCSettingLanguageDlg);
        m_pLastSetRadioBtn->setObjectName(QStringLiteral("m_pLastSetRadioBtn"));
        m_pLastSetRadioBtn->setMinimumSize(QSize(0, 0));
        m_pLastSetRadioBtn->setFont(font);

        verticalLayout->addWidget(m_pLastSetRadioBtn);

        m_pDefaultChineseRadioBtn = new QRadioButton(BCSettingLanguageDlg);
        m_pDefaultChineseRadioBtn->setObjectName(QStringLiteral("m_pDefaultChineseRadioBtn"));
        m_pDefaultChineseRadioBtn->setFont(font);
        m_pDefaultChineseRadioBtn->setChecked(true);

        verticalLayout->addWidget(m_pDefaultChineseRadioBtn);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        m_pOkBtn = new QPushButton(BCSettingLanguageDlg);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pOkBtn->setFont(font1);

        horizontalLayout_4->addWidget(m_pOkBtn);

        m_pCancelBtn = new QPushButton(BCSettingLanguageDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font1);

        horizontalLayout_4->addWidget(m_pCancelBtn);

        m_pApplyBtn = new QPushButton(BCSettingLanguageDlg);
        m_pApplyBtn->setObjectName(QStringLiteral("m_pApplyBtn"));
        m_pApplyBtn->setFont(font1);

        horizontalLayout_4->addWidget(m_pApplyBtn);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(BCSettingLanguageDlg);

        QMetaObject::connectSlotsByName(BCSettingLanguageDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingLanguageDlg)
    {
        BCSettingLanguageDlg->setWindowTitle(QApplication::translate("BCSettingLanguageDlg", "Dialog", Q_NULLPTR));
        m_pSelectLanguageLabel->setText(QApplication::translate("BCSettingLanguageDlg", "\351\200\211\346\213\251\350\257\255\350\250\200", Q_NULLPTR));
        m_pLastSetRadioBtn->setText(QApplication::translate("BCSettingLanguageDlg", "\351\273\230\350\256\244\344\270\212\346\254\241\350\256\276\347\275\256", Q_NULLPTR));
        m_pDefaultChineseRadioBtn->setText(QApplication::translate("BCSettingLanguageDlg", "\351\273\230\350\256\244\344\270\255\346\226\207", Q_NULLPTR));
        m_pOkBtn->setText(QApplication::translate("BCSettingLanguageDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingLanguageDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        m_pApplyBtn->setText(QApplication::translate("BCSettingLanguageDlg", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingLanguageDlg: public Ui_BCSettingLanguageDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGLANGUAGEDLG_H
