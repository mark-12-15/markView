/********************************************************************************
** Form generated from reading UI file 'BCSettingModifyVP2000IPDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGMODIFYVP2000IPDLG_H
#define UI_BCSETTINGMODIFYVP2000IPDLG_H

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

class Ui_BCSettingModifyVP2000IPDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_pIPLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingModifyVP2000IPDlg)
    {
        if (BCSettingModifyVP2000IPDlg->objectName().isEmpty())
            BCSettingModifyVP2000IPDlg->setObjectName(QStringLiteral("BCSettingModifyVP2000IPDlg"));
        BCSettingModifyVP2000IPDlg->resize(244, 107);
        gridLayout = new QGridLayout(BCSettingModifyVP2000IPDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingModifyVP2000IPDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pIPLineEdit = new QLineEdit(BCSettingModifyVP2000IPDlg);
        m_pIPLineEdit->setObjectName(QStringLiteral("m_pIPLineEdit"));
        m_pIPLineEdit->setFont(font);

        gridLayout->addWidget(m_pIPLineEdit, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingModifyVP2000IPDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingModifyVP2000IPDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(BCSettingModifyVP2000IPDlg);

        QMetaObject::connectSlotsByName(BCSettingModifyVP2000IPDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingModifyVP2000IPDlg)
    {
        BCSettingModifyVP2000IPDlg->setWindowTitle(QApplication::translate("BCSettingModifyVP2000IPDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingModifyVP2000IPDlg", "\344\277\256\346\224\271\350\256\276\345\244\207IP", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingModifyVP2000IPDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingModifyVP2000IPDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingModifyVP2000IPDlg: public Ui_BCSettingModifyVP2000IPDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGMODIFYVP2000IPDLG_H
