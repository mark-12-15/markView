/********************************************************************************
** Form generated from reading UI file 'BCLoginDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCLOGINDLG_H
#define UI_BCLOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCLoginDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *m_pBackGroudPixmapWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *m_pCloseBtn;
    QSpacerItem *verticalSpacer;
    QWidget *m_pLoginWidget;
    QToolButton *m_pSetBtn;
    QLabel *m_pUserLabel;
    QLineEdit *m_pPasswordLineEdit;
    QToolButton *m_pLoginBtn;
    QLabel *m_pPasswordLabel;
    QComboBox *m_pUserCombox;
    QWidget *m_pSetWidget;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *m_pIPLineEdit;
    QLineEdit *m_pPortLineEdit;
    QToolButton *m_pOkBtn;
    QToolButton *m_pCancelBtn;
    QCheckBox *m_pConnectServerCheckBox;

    void setupUi(QDialog *BCLoginDlg)
    {
        if (BCLoginDlg->objectName().isEmpty())
            BCLoginDlg->setObjectName(QStringLiteral("BCLoginDlg"));
        BCLoginDlg->resize(320, 350);
        verticalLayout_2 = new QVBoxLayout(BCLoginDlg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_pBackGroudPixmapWidget = new QWidget(BCLoginDlg);
        m_pBackGroudPixmapWidget->setObjectName(QStringLiteral("m_pBackGroudPixmapWidget"));
        m_pBackGroudPixmapWidget->setMinimumSize(QSize(320, 100));
        m_pBackGroudPixmapWidget->setMaximumSize(QSize(320, 100));
        m_pBackGroudPixmapWidget->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(m_pBackGroudPixmapWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(m_pBackGroudPixmapWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 24));
        widget->setMaximumSize(QSize(16777215, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(189, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pCloseBtn = new QToolButton(widget);
        m_pCloseBtn->setObjectName(QStringLiteral("m_pCloseBtn"));
        m_pCloseBtn->setMinimumSize(QSize(24, 24));
        m_pCloseBtn->setMaximumSize(QSize(24, 24));
        m_pCloseBtn->setIconSize(QSize(22, 22));
        m_pCloseBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pCloseBtn);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addWidget(m_pBackGroudPixmapWidget);

        m_pLoginWidget = new QWidget(BCLoginDlg);
        m_pLoginWidget->setObjectName(QStringLiteral("m_pLoginWidget"));
        m_pLoginWidget->setMinimumSize(QSize(0, 125));
        m_pLoginWidget->setMaximumSize(QSize(16777215, 125));
        m_pLoginWidget->setAutoFillBackground(false);
        m_pLoginWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 242, 249);\n"
"font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        m_pSetBtn = new QToolButton(m_pLoginWidget);
        m_pSetBtn->setObjectName(QStringLiteral("m_pSetBtn"));
        m_pSetBtn->setGeometry(QRect(188, 92, 75, 24));
        m_pSetBtn->setMinimumSize(QSize(0, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        m_pSetBtn->setFont(font);
        m_pSetBtn->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(140,140,140));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/  \n"
"}  \n"
"QToolButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(120,120,120));  \n"
"border:1px;  \n"
"border-radius:"
                        "5px;padding:2px 4px;  \n"
"}  \n"
"QToolButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;  \n"
"}  \n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;pa"
                        "dding:2px 4px;  \n"
"}  "));
        m_pUserLabel = new QLabel(m_pLoginWidget);
        m_pUserLabel->setObjectName(QStringLiteral("m_pUserLabel"));
        m_pUserLabel->setGeometry(QRect(64, 28, 21, 21));
        m_pPasswordLineEdit = new QLineEdit(m_pLoginWidget);
        m_pPasswordLineEdit->setObjectName(QStringLiteral("m_pPasswordLineEdit"));
        m_pPasswordLineEdit->setGeometry(QRect(104, 58, 160, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pPasswordLineEdit->setFont(font1);
        m_pLoginBtn = new QToolButton(m_pLoginWidget);
        m_pLoginBtn->setObjectName(QStringLiteral("m_pLoginBtn"));
        m_pLoginBtn->setGeometry(QRect(104, 92, 75, 24));
        m_pLoginBtn->setMinimumSize(QSize(75, 24));
        m_pLoginBtn->setFont(font);
        m_pLoginBtn->setStyleSheet(QString::fromUtf8("QToolButton{  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(140,140,140));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/  \n"
"}  \n"
"QToolButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(120,120,120));  \n"
"border:1px;  \n"
"border-radius:5px;p"
                        "adding:2px 4px;  \n"
"}  \n"
"QToolButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;  \n"
"}  \n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;padding"
                        ":2px 4px;  \n"
"}  "));
        m_pPasswordLabel = new QLabel(m_pLoginWidget);
        m_pPasswordLabel->setObjectName(QStringLiteral("m_pPasswordLabel"));
        m_pPasswordLabel->setGeometry(QRect(64, 58, 21, 21));
        m_pPasswordLabel->setAutoFillBackground(false);
        m_pUserCombox = new QComboBox(m_pLoginWidget);
        m_pUserCombox->setObjectName(QStringLiteral("m_pUserCombox"));
        m_pUserCombox->setGeometry(QRect(104, 28, 160, 24));
        m_pUserCombox->setFont(font1);

        verticalLayout_2->addWidget(m_pLoginWidget);

        m_pSetWidget = new QWidget(BCLoginDlg);
        m_pSetWidget->setObjectName(QStringLiteral("m_pSetWidget"));
        m_pSetWidget->setMinimumSize(QSize(0, 125));
        m_pSetWidget->setMaximumSize(QSize(16777215, 125));
        m_pSetWidget->setStyleSheet(QStringLiteral("background-color: rgb(235, 242, 249);"));
        label_3 = new QLabel(m_pSetWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(4, 31, 91, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(false);
        font2.setWeight(50);
        label_3->setFont(font2);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(m_pSetWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(4, 61, 91, 20));
        label_4->setFont(font2);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_pIPLineEdit = new QLineEdit(m_pSetWidget);
        m_pIPLineEdit->setObjectName(QStringLiteral("m_pIPLineEdit"));
        m_pIPLineEdit->setGeometry(QRect(104, 28, 160, 24));
        m_pIPLineEdit->setFont(font1);
        m_pPortLineEdit = new QLineEdit(m_pSetWidget);
        m_pPortLineEdit->setObjectName(QStringLiteral("m_pPortLineEdit"));
        m_pPortLineEdit->setGeometry(QRect(104, 58, 160, 24));
        m_pPortLineEdit->setFont(font1);
        m_pOkBtn = new QToolButton(m_pSetWidget);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        m_pOkBtn->setGeometry(QRect(104, 92, 75, 24));
        m_pOkBtn->setMinimumSize(QSize(0, 24));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(true);
        font3.setWeight(75);
        m_pOkBtn->setFont(font3);
        m_pOkBtn->setStyleSheet(QString::fromUtf8("QToolButton{  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(140,140,140));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/  \n"
"}  \n"
"QToolButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(120,120,120));  \n"
"border:1px;  \n"
"border-radius:5px;p"
                        "adding:2px 4px;  \n"
"}  \n"
"QToolButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;  \n"
"}  \n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;padding"
                        ":2px 4px;  \n"
"}  "));
        m_pCancelBtn = new QToolButton(m_pSetWidget);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setGeometry(QRect(188, 92, 75, 24));
        m_pCancelBtn->setMinimumSize(QSize(0, 24));
        m_pCancelBtn->setFont(font3);
        m_pCancelBtn->setStyleSheet(QString::fromUtf8("QToolButton{  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(140,140,140));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/  \n"
"}  \n"
"QToolButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(160,160,160),  \n"
"                              stop: 1 rgb(120,120,120));  \n"
"border:1px;  \n"
"border-radius:5px;p"
                        "adding:2px 4px;  \n"
"}  \n"
"QToolButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;padding:2px 4px;  \n"
"}  \n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:20;  \n"
"border-style:solid;  \n"
"border-top-left-radius:2px;  \n"
"border-top-right-radius:2px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:1px;  \n"
"border-radius:5px;padding"
                        ":2px 4px;  \n"
"}  "));
        m_pConnectServerCheckBox = new QCheckBox(m_pSetWidget);
        m_pConnectServerCheckBox->setObjectName(QStringLiteral("m_pConnectServerCheckBox"));
        m_pConnectServerCheckBox->setGeometry(QRect(58, 7, 131, 16));
        m_pConnectServerCheckBox->setFont(font3);

        verticalLayout_2->addWidget(m_pSetWidget);

        QWidget::setTabOrder(m_pPasswordLineEdit, m_pLoginBtn);
        QWidget::setTabOrder(m_pLoginBtn, m_pSetBtn);
        QWidget::setTabOrder(m_pSetBtn, m_pConnectServerCheckBox);
        QWidget::setTabOrder(m_pConnectServerCheckBox, m_pIPLineEdit);
        QWidget::setTabOrder(m_pIPLineEdit, m_pPortLineEdit);
        QWidget::setTabOrder(m_pPortLineEdit, m_pOkBtn);
        QWidget::setTabOrder(m_pOkBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pCloseBtn);

        retranslateUi(BCLoginDlg);

        QMetaObject::connectSlotsByName(BCLoginDlg);
    } // setupUi

    void retranslateUi(QDialog *BCLoginDlg)
    {
        BCLoginDlg->setWindowTitle(QApplication::translate("BCLoginDlg", "Dialog", Q_NULLPTR));
        m_pCloseBtn->setText(QString());
        m_pSetBtn->setText(QApplication::translate("BCLoginDlg", "\350\256\276\347\275\256", Q_NULLPTR));
        m_pUserLabel->setText(QString());
        m_pLoginBtn->setText(QApplication::translate("BCLoginDlg", "\347\231\273\345\275\225", Q_NULLPTR));
        m_pPasswordLabel->setText(QString());
        label_3->setText(QApplication::translate("BCLoginDlg", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCLoginDlg", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        m_pOkBtn->setText(QApplication::translate("BCLoginDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCLoginDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        m_pConnectServerCheckBox->setText(QApplication::translate("BCLoginDlg", "\346\230\257\345\220\246\345\244\232\347\253\257\346\216\247\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCLoginDlg: public Ui_BCLoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCLOGINDLG_H
