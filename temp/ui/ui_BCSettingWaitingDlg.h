/********************************************************************************
** Form generated from reading UI file 'BCSettingWaitingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGWAITINGDLG_H
#define UI_BCSETTINGWAITINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_BCSettingWaitingDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *BCSettingWaitingDlg)
    {
        if (BCSettingWaitingDlg->objectName().isEmpty())
            BCSettingWaitingDlg->setObjectName(QStringLiteral("BCSettingWaitingDlg"));
        BCSettingWaitingDlg->resize(645, 56);
        horizontalLayout = new QHBoxLayout(BCSettingWaitingDlg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(BCSettingWaitingDlg);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(22);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        retranslateUi(BCSettingWaitingDlg);

        QMetaObject::connectSlotsByName(BCSettingWaitingDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingWaitingDlg)
    {
        BCSettingWaitingDlg->setWindowTitle(QApplication::translate("BCSettingWaitingDlg", "\346\217\220\347\244\272", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingWaitingDlg", "\347\263\273\347\273\237\346\255\243\345\234\250\345\212\240\350\275\275\346\225\260\346\215\256,\350\257\267\347\250\215\345\220\216...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingWaitingDlg: public Ui_BCSettingWaitingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGWAITINGDLG_H
