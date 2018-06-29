/********************************************************************************
** Form generated from reading UI file 'BCSettingRepeatApplicationWarningDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGREPEATAPPLICATIONWARNINGDLG_H
#define UI_BCSETTINGREPEATAPPLICATIONWARNINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingRepeatApplicationWarningDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_pTextLabel;
    QLabel *m_pIconLabel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;

    void setupUi(QDialog *BCSettingRepeatApplicationWarningDlg)
    {
        if (BCSettingRepeatApplicationWarningDlg->objectName().isEmpty())
            BCSettingRepeatApplicationWarningDlg->setObjectName(QStringLiteral("BCSettingRepeatApplicationWarningDlg"));
        BCSettingRepeatApplicationWarningDlg->resize(271, 84);
        verticalLayout = new QVBoxLayout(BCSettingRepeatApplicationWarningDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_pTextLabel = new QLabel(BCSettingRepeatApplicationWarningDlg);
        m_pTextLabel->setObjectName(QStringLiteral("m_pTextLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pTextLabel->setFont(font);

        horizontalLayout_2->addWidget(m_pTextLabel);

        m_pIconLabel = new QLabel(BCSettingRepeatApplicationWarningDlg);
        m_pIconLabel->setObjectName(QStringLiteral("m_pIconLabel"));
        m_pIconLabel->setMinimumSize(QSize(16, 16));
        m_pIconLabel->setMaximumSize(QSize(16, 16));
        m_pIconLabel->setFont(font);

        horizontalLayout_2->addWidget(m_pIconLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingRepeatApplicationWarningDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BCSettingRepeatApplicationWarningDlg);

        QMetaObject::connectSlotsByName(BCSettingRepeatApplicationWarningDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingRepeatApplicationWarningDlg)
    {
        BCSettingRepeatApplicationWarningDlg->setWindowTitle(QApplication::translate("BCSettingRepeatApplicationWarningDlg", "Dialog", Q_NULLPTR));
        m_pTextLabel->setText(QApplication::translate("BCSettingRepeatApplicationWarningDlg", "\346\217\220\347\244\272\357\274\232\350\275\257\344\273\266\345\267\262\346\211\223\345\274\200\357\274\214\350\257\267\345\234\250\344\273\273\345\212\241\346\240\217\344\270\255\347\202\271\345\207\273", Q_NULLPTR));
        m_pIconLabel->setText(QString());
        m_pOKBtn->setText(QApplication::translate("BCSettingRepeatApplicationWarningDlg", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingRepeatApplicationWarningDlg: public Ui_BCSettingRepeatApplicationWarningDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGREPEATAPPLICATIONWARNINGDLG_H
