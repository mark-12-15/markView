/********************************************************************************
** Form generated from reading UI file 'BCSettingModifyEDIDDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGMODIFYEDIDDIALOG_H
#define UI_BCSETTINGMODIFYEDIDDIALOG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingModifyEDIDDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *m_pXLineEdit;
    QLabel *label_2;
    QLineEdit *m_pYLineEdit;
    QLabel *label_3;
    QLineEdit *m_pHzLineEdit;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingModifyEDIDDialog)
    {
        if (BCSettingModifyEDIDDialog->objectName().isEmpty())
            BCSettingModifyEDIDDialog->setObjectName(QStringLiteral("BCSettingModifyEDIDDialog"));
        BCSettingModifyEDIDDialog->resize(281, 112);
        verticalLayout = new QVBoxLayout(BCSettingModifyEDIDDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(BCSettingModifyEDIDDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        m_pXLineEdit = new QLineEdit(BCSettingModifyEDIDDialog);
        m_pXLineEdit->setObjectName(QStringLiteral("m_pXLineEdit"));
        m_pXLineEdit->setFont(font);

        horizontalLayout->addWidget(m_pXLineEdit);

        label_2 = new QLabel(BCSettingModifyEDIDDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        m_pYLineEdit = new QLineEdit(BCSettingModifyEDIDDialog);
        m_pYLineEdit->setObjectName(QStringLiteral("m_pYLineEdit"));
        m_pYLineEdit->setFont(font);

        horizontalLayout->addWidget(m_pYLineEdit);

        label_3 = new QLabel(BCSettingModifyEDIDDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        m_pHzLineEdit = new QLineEdit(BCSettingModifyEDIDDialog);
        m_pHzLineEdit->setObjectName(QStringLiteral("m_pHzLineEdit"));
        m_pHzLineEdit->setFont(font);

        horizontalLayout->addWidget(m_pHzLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        label_4 = new QLabel(BCSettingModifyEDIDDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingModifyEDIDDialog);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingModifyEDIDDialog);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BCSettingModifyEDIDDialog);

        QMetaObject::connectSlotsByName(BCSettingModifyEDIDDialog);
    } // setupUi

    void retranslateUi(QDialog *BCSettingModifyEDIDDialog)
    {
        BCSettingModifyEDIDDialog->setWindowTitle(QApplication::translate("BCSettingModifyEDIDDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingModifyEDIDDialog", "X:", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingModifyEDIDDialog", "Y:", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingModifyEDIDDialog", "Hz:", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingModifyEDIDDialog", "\346\263\250:\350\257\267\345\205\210\346\213\224\344\270\213\346\210\226\345\205\263\351\227\255\344\277\241\345\217\267\346\272\220\345\206\215\350\277\233\350\241\214\346\223\215\344\275\234!", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingModifyEDIDDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingModifyEDIDDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingModifyEDIDDialog: public Ui_BCSettingModifyEDIDDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGMODIFYEDIDDIALOG_H
