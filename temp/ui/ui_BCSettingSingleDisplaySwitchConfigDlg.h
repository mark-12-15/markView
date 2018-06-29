/********************************************************************************
** Form generated from reading UI file 'BCSettingSingleDisplaySwitchConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGSINGLEDISPLAYSWITCHCONFIGDLG_H
#define UI_BCSETTINGSINGLEDISPLAYSWITCHCONFIGDLG_H

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

class Ui_BCSettingSingleDisplaySwitchConfigDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_pSwitchOnLineEdit;
    QLabel *label_2;
    QLineEdit *m_pSwitchOffLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingSingleDisplaySwitchConfigDlg)
    {
        if (BCSettingSingleDisplaySwitchConfigDlg->objectName().isEmpty())
            BCSettingSingleDisplaySwitchConfigDlg->setObjectName(QStringLiteral("BCSettingSingleDisplaySwitchConfigDlg"));
        BCSettingSingleDisplaySwitchConfigDlg->resize(283, 150);
        gridLayout = new QGridLayout(BCSettingSingleDisplaySwitchConfigDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingSingleDisplaySwitchConfigDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pSwitchOnLineEdit = new QLineEdit(BCSettingSingleDisplaySwitchConfigDlg);
        m_pSwitchOnLineEdit->setObjectName(QStringLiteral("m_pSwitchOnLineEdit"));
        m_pSwitchOnLineEdit->setFont(font);

        gridLayout->addWidget(m_pSwitchOnLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(BCSettingSingleDisplaySwitchConfigDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_pSwitchOffLineEdit = new QLineEdit(BCSettingSingleDisplaySwitchConfigDlg);
        m_pSwitchOffLineEdit->setObjectName(QStringLiteral("m_pSwitchOffLineEdit"));
        m_pSwitchOffLineEdit->setFont(font);

        gridLayout->addWidget(m_pSwitchOffLineEdit, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingSingleDisplaySwitchConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingSingleDisplaySwitchConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);


        retranslateUi(BCSettingSingleDisplaySwitchConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingSingleDisplaySwitchConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingSingleDisplaySwitchConfigDlg)
    {
        BCSettingSingleDisplaySwitchConfigDlg->setWindowTitle(QApplication::translate("BCSettingSingleDisplaySwitchConfigDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingSingleDisplaySwitchConfigDlg", "\346\211\223\345\274\200\346\214\207\344\273\244", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingSingleDisplaySwitchConfigDlg", "\345\205\263\351\227\255\346\214\207\344\273\244", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingSingleDisplaySwitchConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingSingleDisplaySwitchConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingSingleDisplaySwitchConfigDlg: public Ui_BCSettingSingleDisplaySwitchConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGSINGLEDISPLAYSWITCHCONFIGDLG_H
