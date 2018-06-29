/********************************************************************************
** Form generated from reading UI file 'BCSettingWindowCopyConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGWINDOWCOPYCONFIGDLG_H
#define UI_BCSETTINGWINDOWCOPYCONFIGDLG_H

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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSettingWindowCopyConfigDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_pOpenWindowCopyBtn;
    QPushButton *m_pCloseWindowCopyBtn;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *m_pPCCopyCountLineEdit;
    QLabel *label_2;
    QLineEdit *m_pVideoCopyCountLineEdit;
    QLabel *m_pStatusLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;
    QProgressBar *progressBar;

    void setupUi(QDialog *BCSettingWindowCopyConfigDlg)
    {
        if (BCSettingWindowCopyConfigDlg->objectName().isEmpty())
            BCSettingWindowCopyConfigDlg->setObjectName(QStringLiteral("BCSettingWindowCopyConfigDlg"));
        BCSettingWindowCopyConfigDlg->resize(302, 238);
        gridLayout = new QGridLayout(BCSettingWindowCopyConfigDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_pOpenWindowCopyBtn = new QPushButton(BCSettingWindowCopyConfigDlg);
        m_pOpenWindowCopyBtn->setObjectName(QStringLiteral("m_pOpenWindowCopyBtn"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pOpenWindowCopyBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOpenWindowCopyBtn);

        m_pCloseWindowCopyBtn = new QPushButton(BCSettingWindowCopyConfigDlg);
        m_pCloseWindowCopyBtn->setObjectName(QStringLiteral("m_pCloseWindowCopyBtn"));
        m_pCloseWindowCopyBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCloseWindowCopyBtn);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 3);

        label_3 = new QLabel(BCSettingWindowCopyConfigDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        label = new QLabel(BCSettingWindowCopyConfigDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 2);

        m_pPCCopyCountLineEdit = new QLineEdit(BCSettingWindowCopyConfigDlg);
        m_pPCCopyCountLineEdit->setObjectName(QStringLiteral("m_pPCCopyCountLineEdit"));
        m_pPCCopyCountLineEdit->setFont(font);

        gridLayout->addWidget(m_pPCCopyCountLineEdit, 2, 2, 1, 1);

        label_2 = new QLabel(BCSettingWindowCopyConfigDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 2);

        m_pVideoCopyCountLineEdit = new QLineEdit(BCSettingWindowCopyConfigDlg);
        m_pVideoCopyCountLineEdit->setObjectName(QStringLiteral("m_pVideoCopyCountLineEdit"));
        m_pVideoCopyCountLineEdit->setFont(font);

        gridLayout->addWidget(m_pVideoCopyCountLineEdit, 3, 2, 1, 1);

        m_pStatusLabel = new QLabel(BCSettingWindowCopyConfigDlg);
        m_pStatusLabel->setObjectName(QStringLiteral("m_pStatusLabel"));
        m_pStatusLabel->setFont(font);
        m_pStatusLabel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(m_pStatusLabel, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(115, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingWindowCopyConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingWindowCopyConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 3);

        progressBar = new QProgressBar(BCSettingWindowCopyConfigDlg);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 7, 0, 1, 3);


        retranslateUi(BCSettingWindowCopyConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingWindowCopyConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingWindowCopyConfigDlg)
    {
        BCSettingWindowCopyConfigDlg->setWindowTitle(QApplication::translate("BCSettingWindowCopyConfigDlg", "Dialog", Q_NULLPTR));
        m_pOpenWindowCopyBtn->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "\346\211\223\345\274\200\345\244\215\345\210\266\345\212\237\350\203\275", Q_NULLPTR));
        m_pCloseWindowCopyBtn->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "\345\205\263\351\227\255\345\244\215\345\210\266\345\212\237\350\203\275", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "\346\217\220\347\244\272\357\274\232\351\207\215\345\220\257\350\256\276\345\244\207\347\224\237\346\225\210", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "PC(\344\270\252/\350\267\257)", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "Video(\344\270\252/\350\267\257)", Q_NULLPTR));
        m_pStatusLabel->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "\346\217\220\347\244\272\357\274\232", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingWindowCopyConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingWindowCopyConfigDlg: public Ui_BCSettingWindowCopyConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGWINDOWCOPYCONFIGDLG_H
