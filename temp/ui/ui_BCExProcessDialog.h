/********************************************************************************
** Form generated from reading UI file 'BCExProcessDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCEXPROCESSDIALOG_H
#define UI_BCEXPROCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCExProcessDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCExProcessDialog)
    {
        if (BCExProcessDialog->objectName().isEmpty())
            BCExProcessDialog->setObjectName(QStringLiteral("BCExProcessDialog"));
        BCExProcessDialog->resize(454, 454);
        verticalLayout = new QVBoxLayout(BCExProcessDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_1 = new QPushButton(BCExProcessDialog);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        pushButton_1->setFont(font);

        horizontalLayout->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(BCExProcessDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(BCExProcessDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(BCExProcessDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setFont(font);

        horizontalLayout->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(BCExProcessDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCExProcessDialog);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCExProcessDialog);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BCExProcessDialog);

        QMetaObject::connectSlotsByName(BCExProcessDialog);
    } // setupUi

    void retranslateUi(QDialog *BCExProcessDialog)
    {
        BCExProcessDialog->setWindowTitle(QApplication::translate("BCExProcessDialog", "\345\244\226\351\203\250\345\267\245\345\205\267\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("BCExProcessDialog", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BCExProcessDialog", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("BCExProcessDialog", "\344\270\212\347\247\273", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("BCExProcessDialog", "\344\270\213\347\247\273", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCExProcessDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCExProcessDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCExProcessDialog: public Ui_BCExProcessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCEXPROCESSDIALOG_H
