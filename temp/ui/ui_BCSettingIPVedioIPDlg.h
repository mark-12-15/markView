/********************************************************************************
** Form generated from reading UI file 'BCSettingIPVedioIPDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGIPVEDIOIPDLG_H
#define UI_BCSETTINGIPVEDIOIPDLG_H

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

class Ui_BCSettingIPVedioIPDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *m_pOKBtn;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pCancelBtn;
    QLineEdit *m_pIPLineEdit;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *m_pMaskLineEdit;
    QLineEdit *m_pGatewayLineEdit;
    QLabel *label_5;
    QLineEdit *m_pMacLineEdit;

    void setupUi(QDialog *BCSettingIPVedioIPDlg)
    {
        if (BCSettingIPVedioIPDlg->objectName().isEmpty())
            BCSettingIPVedioIPDlg->setObjectName(QStringLiteral("BCSettingIPVedioIPDlg"));
        BCSettingIPVedioIPDlg->resize(241, 182);
        gridLayout = new QGridLayout(BCSettingIPVedioIPDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(BCSettingIPVedioIPDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_pOKBtn = new QPushButton(BCSettingIPVedioIPDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        gridLayout->addWidget(m_pOKBtn, 5, 1, 1, 1);

        label = new QLabel(BCSettingIPVedioIPDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

        m_pCancelBtn = new QPushButton(BCSettingIPVedioIPDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        gridLayout->addWidget(m_pCancelBtn, 5, 2, 1, 1);

        m_pIPLineEdit = new QLineEdit(BCSettingIPVedioIPDlg);
        m_pIPLineEdit->setObjectName(QStringLiteral("m_pIPLineEdit"));
        m_pIPLineEdit->setFont(font);

        gridLayout->addWidget(m_pIPLineEdit, 0, 1, 1, 2);

        label_4 = new QLabel(BCSettingIPVedioIPDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 24));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(label_4, 4, 0, 1, 3);

        label_3 = new QLabel(BCSettingIPVedioIPDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        m_pMaskLineEdit = new QLineEdit(BCSettingIPVedioIPDlg);
        m_pMaskLineEdit->setObjectName(QStringLiteral("m_pMaskLineEdit"));
        m_pMaskLineEdit->setFont(font);

        gridLayout->addWidget(m_pMaskLineEdit, 1, 1, 1, 2);

        m_pGatewayLineEdit = new QLineEdit(BCSettingIPVedioIPDlg);
        m_pGatewayLineEdit->setObjectName(QStringLiteral("m_pGatewayLineEdit"));
        m_pGatewayLineEdit->setFont(font);

        gridLayout->addWidget(m_pGatewayLineEdit, 2, 1, 1, 2);

        label_5 = new QLabel(BCSettingIPVedioIPDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        m_pMacLineEdit = new QLineEdit(BCSettingIPVedioIPDlg);
        m_pMacLineEdit->setObjectName(QStringLiteral("m_pMacLineEdit"));
        m_pMacLineEdit->setFont(font);

        gridLayout->addWidget(m_pMacLineEdit, 3, 1, 1, 2);


        retranslateUi(BCSettingIPVedioIPDlg);

        QMetaObject::connectSlotsByName(BCSettingIPVedioIPDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingIPVedioIPDlg)
    {
        BCSettingIPVedioIPDlg->setWindowTitle(QApplication::translate("BCSettingIPVedioIPDlg", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingIPVedioIPDlg", "\345\255\220\347\275\221\346\216\251\347\240\201", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingIPVedioIPDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingIPVedioIPDlg", "IP\345\234\260\345\235\200", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingIPVedioIPDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingIPVedioIPDlg", "\346\217\220\347\244\272\357\274\232\351\207\215\345\220\257\346\234\272\345\231\250\345\220\216\347\224\237\346\225\210", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingIPVedioIPDlg", "\347\275\221\345\205\263", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingIPVedioIPDlg", "Mac\345\234\260\345\235\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingIPVedioIPDlg: public Ui_BCSettingIPVedioIPDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGIPVEDIOIPDLG_H
