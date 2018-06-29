/********************************************************************************
** Form generated from reading UI file 'BCSettingOutOfDateDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGOUTOFDATEDLG_H
#define UI_BCSETTINGOUTOFDATEDLG_H

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

class Ui_BCSettingOutOfDateDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pUnlockBtn;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *BCSettingOutOfDateDlg)
    {
        if (BCSettingOutOfDateDlg->objectName().isEmpty())
            BCSettingOutOfDateDlg->setObjectName(QStringLiteral("BCSettingOutOfDateDlg"));
        BCSettingOutOfDateDlg->resize(483, 89);
        verticalLayout = new QVBoxLayout(BCSettingOutOfDateDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(BCSettingOutOfDateDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pUnlockBtn = new QPushButton(BCSettingOutOfDateDlg);
        m_pUnlockBtn->setObjectName(QStringLiteral("m_pUnlockBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pUnlockBtn->setFont(font1);

        horizontalLayout->addWidget(m_pUnlockBtn);

        pushButton = new QPushButton(BCSettingOutOfDateDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BCSettingOutOfDateDlg);

        QMetaObject::connectSlotsByName(BCSettingOutOfDateDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingOutOfDateDlg)
    {
        BCSettingOutOfDateDlg->setWindowTitle(QApplication::translate("BCSettingOutOfDateDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingOutOfDateDlg", "\345\275\223\345\211\215\350\256\276\345\244\207\345\267\262\350\277\207\346\234\237\357\274\214\350\257\267\345\260\275\345\277\253\350\201\224\347\263\273\345\216\202\345\256\266\347\264\242\350\246\201\350\256\270\345\217\257", Q_NULLPTR));
        m_pUnlockBtn->setText(QApplication::translate("BCSettingOutOfDateDlg", "\347\253\213\345\215\263\350\256\244\350\257\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BCSettingOutOfDateDlg", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingOutOfDateDlg: public Ui_BCSettingOutOfDateDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGOUTOFDATEDLG_H
