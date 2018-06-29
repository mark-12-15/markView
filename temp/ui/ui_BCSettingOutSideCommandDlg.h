/********************************************************************************
** Form generated from reading UI file 'BCSettingOutSideCommandDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGOUTSIDECOMMANDDLG_H
#define UI_BCSETTINGOUTSIDECOMMANDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSettingOutSideCommandDlg
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *m_pCodeWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_pGetCodeBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *m_pConfigFileLineEdit;
    QToolButton *m_pSelectConfigFileBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *m_pMd5FileLineEdit;
    QToolButton *m_pSelectMd5FileBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *m_pStatus;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pExecBtn;

    void setupUi(QDialog *BCSettingOutSideCommandDlg)
    {
        if (BCSettingOutSideCommandDlg->objectName().isEmpty())
            BCSettingOutSideCommandDlg->setObjectName(QStringLiteral("BCSettingOutSideCommandDlg"));
        BCSettingOutSideCommandDlg->resize(276, 169);
        verticalLayout = new QVBoxLayout(BCSettingOutSideCommandDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pCodeWidget = new QWidget(BCSettingOutSideCommandDlg);
        m_pCodeWidget->setObjectName(QStringLiteral("m_pCodeWidget"));
        horizontalLayout = new QHBoxLayout(m_pCodeWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(m_pCodeWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(27, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(m_pCodeWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(27, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        m_pGetCodeBtn = new QPushButton(m_pCodeWidget);
        m_pGetCodeBtn->setObjectName(QStringLiteral("m_pGetCodeBtn"));
        m_pGetCodeBtn->setFont(font);

        horizontalLayout->addWidget(m_pGetCodeBtn);


        verticalLayout->addWidget(m_pCodeWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(BCSettingOutSideCommandDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        m_pConfigFileLineEdit = new QLineEdit(BCSettingOutSideCommandDlg);
        m_pConfigFileLineEdit->setObjectName(QStringLiteral("m_pConfigFileLineEdit"));
        m_pConfigFileLineEdit->setFont(font);

        horizontalLayout_2->addWidget(m_pConfigFileLineEdit);

        m_pSelectConfigFileBtn = new QToolButton(BCSettingOutSideCommandDlg);
        m_pSelectConfigFileBtn->setObjectName(QStringLiteral("m_pSelectConfigFileBtn"));
        m_pSelectConfigFileBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pSelectConfigFileBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(BCSettingOutSideCommandDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        m_pMd5FileLineEdit = new QLineEdit(BCSettingOutSideCommandDlg);
        m_pMd5FileLineEdit->setObjectName(QStringLiteral("m_pMd5FileLineEdit"));
        m_pMd5FileLineEdit->setFont(font);

        horizontalLayout_3->addWidget(m_pMd5FileLineEdit);

        m_pSelectMd5FileBtn = new QToolButton(BCSettingOutSideCommandDlg);
        m_pSelectMd5FileBtn->setObjectName(QStringLiteral("m_pSelectMd5FileBtn"));
        m_pSelectMd5FileBtn->setFont(font);

        horizontalLayout_3->addWidget(m_pSelectMd5FileBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        m_pStatus = new QLabel(BCSettingOutSideCommandDlg);
        m_pStatus->setObjectName(QStringLiteral("m_pStatus"));
        m_pStatus->setFont(font);

        horizontalLayout_4->addWidget(m_pStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        m_pExecBtn = new QPushButton(BCSettingOutSideCommandDlg);
        m_pExecBtn->setObjectName(QStringLiteral("m_pExecBtn"));
        m_pExecBtn->setFont(font);

        horizontalLayout_4->addWidget(m_pExecBtn);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(BCSettingOutSideCommandDlg);

        QMetaObject::connectSlotsByName(BCSettingOutSideCommandDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingOutSideCommandDlg)
    {
        BCSettingOutSideCommandDlg->setWindowTitle(QApplication::translate("BCSettingOutSideCommandDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingOutSideCommandDlg", "\346\223\215\344\275\234\347\240\201:", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingOutSideCommandDlg", "*****", Q_NULLPTR));
        m_pGetCodeBtn->setText(QApplication::translate("BCSettingOutSideCommandDlg", "\350\216\267\345\217\226\346\223\215\344\275\234\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingOutSideCommandDlg", "\351\205\215\347\275\256\346\226\207\344\273\266", Q_NULLPTR));
        m_pSelectConfigFileBtn->setText(QApplication::translate("BCSettingOutSideCommandDlg", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingOutSideCommandDlg", "\346\240\241\351\252\214\346\226\207\344\273\266", Q_NULLPTR));
        m_pSelectMd5FileBtn->setText(QApplication::translate("BCSettingOutSideCommandDlg", "...", Q_NULLPTR));
        m_pStatus->setText(QString());
        m_pExecBtn->setText(QApplication::translate("BCSettingOutSideCommandDlg", "\346\211\247\350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingOutSideCommandDlg: public Ui_BCSettingOutSideCommandDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGOUTSIDECOMMANDDLG_H
