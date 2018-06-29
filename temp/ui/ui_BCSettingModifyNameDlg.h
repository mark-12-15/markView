/********************************************************************************
** Form generated from reading UI file 'BCSettingModifyNameDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGMODIFYNAMEDLG_H
#define UI_BCSETTINGMODIFYNAMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSettingModifyNameDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_pNameLineEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingModifyNameDlg)
    {
        if (BCSettingModifyNameDlg->objectName().isEmpty())
            BCSettingModifyNameDlg->setObjectName(QStringLiteral("BCSettingModifyNameDlg"));
        BCSettingModifyNameDlg->resize(234, 91);
        gridLayout = new QGridLayout(BCSettingModifyNameDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingModifyNameDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pNameLineEdit = new QLineEdit(BCSettingModifyNameDlg);
        m_pNameLineEdit->setObjectName(QStringLiteral("m_pNameLineEdit"));
        m_pNameLineEdit->setFont(font);

        gridLayout->addWidget(m_pNameLineEdit, 0, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        m_pOKBtn = new QPushButton(BCSettingModifyNameDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        gridLayout->addWidget(m_pOKBtn, 2, 1, 1, 1);

        m_pCancelBtn = new QPushButton(BCSettingModifyNameDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        gridLayout->addWidget(m_pCancelBtn, 2, 2, 1, 1);


        retranslateUi(BCSettingModifyNameDlg);

        QMetaObject::connectSlotsByName(BCSettingModifyNameDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingModifyNameDlg)
    {
        BCSettingModifyNameDlg->setWindowTitle(QApplication::translate("BCSettingModifyNameDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingModifyNameDlg", "\345\220\215\347\247\260", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingModifyNameDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingModifyNameDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingModifyNameDlg: public Ui_BCSettingModifyNameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGMODIFYNAMEDLG_H
