/********************************************************************************
** Form generated from reading UI file 'BCSettingCutInputChannelDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGCUTINPUTCHANNELDLG_H
#define UI_BCSETTINGCUTINPUTCHANNELDLG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingCutInputChannelDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_pTopLineEdit;
    QLabel *label_2;
    QLineEdit *m_pBottomLineEdit;
    QLabel *label_3;
    QLineEdit *m_pLeftLineEdit;
    QLabel *label_4;
    QLineEdit *m_pRightLineEdit;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOkBtn;
    QPushButton *m_pCancelBtn;
    QPushButton *m_pApplyBtn;

    void setupUi(QDialog *BCSettingCutInputChannelDlg)
    {
        if (BCSettingCutInputChannelDlg->objectName().isEmpty())
            BCSettingCutInputChannelDlg->setObjectName(QStringLiteral("BCSettingCutInputChannelDlg"));
        BCSettingCutInputChannelDlg->resize(307, 144);
        verticalLayout = new QVBoxLayout(BCSettingCutInputChannelDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingCutInputChannelDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pTopLineEdit = new QLineEdit(BCSettingCutInputChannelDlg);
        m_pTopLineEdit->setObjectName(QStringLiteral("m_pTopLineEdit"));
        m_pTopLineEdit->setFont(font);

        gridLayout->addWidget(m_pTopLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(BCSettingCutInputChannelDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        m_pBottomLineEdit = new QLineEdit(BCSettingCutInputChannelDlg);
        m_pBottomLineEdit->setObjectName(QStringLiteral("m_pBottomLineEdit"));
        m_pBottomLineEdit->setFont(font);

        gridLayout->addWidget(m_pBottomLineEdit, 0, 3, 1, 1);

        label_3 = new QLabel(BCSettingCutInputChannelDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        m_pLeftLineEdit = new QLineEdit(BCSettingCutInputChannelDlg);
        m_pLeftLineEdit->setObjectName(QStringLiteral("m_pLeftLineEdit"));
        m_pLeftLineEdit->setFont(font);

        gridLayout->addWidget(m_pLeftLineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(BCSettingCutInputChannelDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        m_pRightLineEdit = new QLineEdit(BCSettingCutInputChannelDlg);
        m_pRightLineEdit->setObjectName(QStringLiteral("m_pRightLineEdit"));
        m_pRightLineEdit->setFont(font);

        gridLayout->addWidget(m_pRightLineEdit, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_5 = new QLabel(BCSettingCutInputChannelDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOkBtn = new QPushButton(BCSettingCutInputChannelDlg);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        m_pOkBtn->setFont(font);

        horizontalLayout->addWidget(m_pOkBtn);

        m_pCancelBtn = new QPushButton(BCSettingCutInputChannelDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);

        m_pApplyBtn = new QPushButton(BCSettingCutInputChannelDlg);
        m_pApplyBtn->setObjectName(QStringLiteral("m_pApplyBtn"));
        m_pApplyBtn->setFont(font);

        horizontalLayout->addWidget(m_pApplyBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BCSettingCutInputChannelDlg);

        QMetaObject::connectSlotsByName(BCSettingCutInputChannelDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingCutInputChannelDlg)
    {
        BCSettingCutInputChannelDlg->setWindowTitle(QApplication::translate("BCSettingCutInputChannelDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\344\270\212\350\276\271", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\344\270\213\350\276\271", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\345\267\246\350\276\271", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\345\217\263\350\276\271", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\346\263\250: \345\210\207\350\276\271\350\214\203\345\233\264x(0-960) y(0-540)", Q_NULLPTR));
        m_pOkBtn->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        m_pApplyBtn->setText(QApplication::translate("BCSettingCutInputChannelDlg", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingCutInputChannelDlg: public Ui_BCSettingCutInputChannelDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGCUTINPUTCHANNELDLG_H
