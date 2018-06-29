/********************************************************************************
** Form generated from reading UI file 'BCSettingRemoveShadowDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGREMOVESHADOWDLG_H
#define UI_BCSETTINGREMOVESHADOWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSettingRemoveShadowDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_pXLineEdit;
    QLabel *label_2;
    QLineEdit *m_pYLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingRemoveShadowDlg)
    {
        if (BCSettingRemoveShadowDlg->objectName().isEmpty())
            BCSettingRemoveShadowDlg->setObjectName(QStringLiteral("BCSettingRemoveShadowDlg"));
        BCSettingRemoveShadowDlg->resize(240, 124);
        gridLayout = new QGridLayout(BCSettingRemoveShadowDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingRemoveShadowDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pXLineEdit = new QLineEdit(BCSettingRemoveShadowDlg);
        m_pXLineEdit->setObjectName(QStringLiteral("m_pXLineEdit"));
        m_pXLineEdit->setFont(font);

        gridLayout->addWidget(m_pXLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(BCSettingRemoveShadowDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_pYLineEdit = new QLineEdit(BCSettingRemoveShadowDlg);
        m_pYLineEdit->setObjectName(QStringLiteral("m_pYLineEdit"));
        m_pYLineEdit->setFont(font);

        gridLayout->addWidget(m_pYLineEdit, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingRemoveShadowDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingRemoveShadowDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);


        retranslateUi(BCSettingRemoveShadowDlg);

        QMetaObject::connectSlotsByName(BCSettingRemoveShadowDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingRemoveShadowDlg)
    {
        BCSettingRemoveShadowDlg->setWindowTitle(QApplication::translate("BCSettingRemoveShadowDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingRemoveShadowDlg", "\346\260\264\345\271\263\345\203\217\347\264\240", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingRemoveShadowDlg", "\345\236\202\347\233\264\345\203\217\347\264\240", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingRemoveShadowDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingRemoveShadowDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingRemoveShadowDlg: public Ui_BCSettingRemoveShadowDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGREMOVESHADOWDLG_H
