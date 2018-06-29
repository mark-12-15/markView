/********************************************************************************
** Form generated from reading UI file 'BCSettingDebugDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDEBUGDLG_H
#define UI_BCSETTINGDEBUGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDebugDlg
{
public:
    QGridLayout *gridLayout;
    QTextEdit *m_pRecvTextEdit;
    QTextEdit *m_pSendTextEdit;
    QPushButton *m_pSendBtn;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *m_pClearBtn;

    void setupUi(QDialog *BCSettingDebugDlg)
    {
        if (BCSettingDebugDlg->objectName().isEmpty())
            BCSettingDebugDlg->setObjectName(QStringLiteral("BCSettingDebugDlg"));
        BCSettingDebugDlg->resize(372, 413);
        gridLayout = new QGridLayout(BCSettingDebugDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_pRecvTextEdit = new QTextEdit(BCSettingDebugDlg);
        m_pRecvTextEdit->setObjectName(QStringLiteral("m_pRecvTextEdit"));
        m_pRecvTextEdit->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pRecvTextEdit->setFont(font);
        m_pRecvTextEdit->setReadOnly(true);

        gridLayout->addWidget(m_pRecvTextEdit, 1, 0, 1, 2);

        m_pSendTextEdit = new QTextEdit(BCSettingDebugDlg);
        m_pSendTextEdit->setObjectName(QStringLiteral("m_pSendTextEdit"));
        m_pSendTextEdit->setMaximumSize(QSize(16777215, 80));
        m_pSendTextEdit->setFont(font);

        gridLayout->addWidget(m_pSendTextEdit, 2, 0, 1, 1);

        m_pSendBtn = new QPushButton(BCSettingDebugDlg);
        m_pSendBtn->setObjectName(QStringLiteral("m_pSendBtn"));
        m_pSendBtn->setFont(font);

        gridLayout->addWidget(m_pSendBtn, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(BCSettingDebugDlg);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        horizontalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(BCSettingDebugDlg);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setFont(font);

        horizontalLayout->addWidget(checkBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pClearBtn = new QToolButton(BCSettingDebugDlg);
        m_pClearBtn->setObjectName(QStringLiteral("m_pClearBtn"));
        m_pClearBtn->setFont(font);

        horizontalLayout->addWidget(m_pClearBtn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        QWidget::setTabOrder(m_pSendTextEdit, m_pSendBtn);
        QWidget::setTabOrder(m_pSendBtn, m_pClearBtn);
        QWidget::setTabOrder(m_pClearBtn, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, m_pRecvTextEdit);

        retranslateUi(BCSettingDebugDlg);

        QMetaObject::connectSlotsByName(BCSettingDebugDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingDebugDlg)
    {
        BCSettingDebugDlg->setWindowTitle(QApplication::translate("BCSettingDebugDlg", "Dialog", Q_NULLPTR));
        m_pSendBtn->setText(QApplication::translate("BCSettingDebugDlg", "\345\217\221\351\200\201", Q_NULLPTR));
        checkBox->setText(QApplication::translate("BCSettingDebugDlg", "\346\214\207\344\273\244\344\277\241\346\201\257", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("BCSettingDebugDlg", "\350\260\203\350\257\225\344\277\241\346\201\257", Q_NULLPTR));
        m_pClearBtn->setText(QApplication::translate("BCSettingDebugDlg", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDebugDlg: public Ui_BCSettingDebugDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDEBUGDLG_H
