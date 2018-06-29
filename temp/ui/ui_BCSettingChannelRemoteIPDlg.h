/********************************************************************************
** Form generated from reading UI file 'BCSettingChannelRemoteIPDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGCHANNELREMOTEIPDLG_H
#define UI_BCSETTINGCHANNELREMOTEIPDLG_H

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

class Ui_BCSettingChannelRemoteIPDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingChannelRemoteIPDlg)
    {
        if (BCSettingChannelRemoteIPDlg->objectName().isEmpty())
            BCSettingChannelRemoteIPDlg->setObjectName(QStringLiteral("BCSettingChannelRemoteIPDlg"));
        BCSettingChannelRemoteIPDlg->resize(205, 82);
        verticalLayout = new QVBoxLayout(BCSettingChannelRemoteIPDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(BCSettingChannelRemoteIPDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(BCSettingChannelRemoteIPDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingChannelRemoteIPDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingChannelRemoteIPDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BCSettingChannelRemoteIPDlg);

        QMetaObject::connectSlotsByName(BCSettingChannelRemoteIPDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingChannelRemoteIPDlg)
    {
        BCSettingChannelRemoteIPDlg->setWindowTitle(QApplication::translate("BCSettingChannelRemoteIPDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingChannelRemoteIPDlg", "\350\277\234\347\250\213\346\216\247\345\210\266IP", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingChannelRemoteIPDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingChannelRemoteIPDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingChannelRemoteIPDlg: public Ui_BCSettingChannelRemoteIPDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGCHANNELREMOTEIPDLG_H
