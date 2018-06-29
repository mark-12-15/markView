/********************************************************************************
** Form generated from reading UI file 'LogQueryDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGQUERYDIALOG_H
#define UI_LOGQUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LogQueryDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *beginTime;
    QLabel *label_2;
    QLineEdit *endTime;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *userName;
    QLabel *label_4;
    QLineEdit *event;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *LogQueryDialog)
    {
        if (LogQueryDialog->objectName().isEmpty())
            LogQueryDialog->setObjectName(QStringLiteral("LogQueryDialog"));
        LogQueryDialog->resize(710, 361);
        verticalLayout_2 = new QVBoxLayout(LogQueryDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(LogQueryDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        beginTime = new QLineEdit(groupBox);
        beginTime->setObjectName(QStringLiteral("beginTime"));

        horizontalLayout->addWidget(beginTime);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        endTime = new QLineEdit(groupBox);
        endTime->setObjectName(QStringLiteral("endTime"));

        horizontalLayout->addWidget(endTime);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        userName = new QLineEdit(groupBox);
        userName->setObjectName(QStringLiteral("userName"));

        horizontalLayout_2->addWidget(userName);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        event = new QLineEdit(groupBox);
        event->setObjectName(QStringLiteral("event"));

        horizontalLayout_2->addWidget(event);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox);

        tableWidget = new QTableWidget(LogQueryDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_2->addWidget(tableWidget);


        retranslateUi(LogQueryDialog);

        QMetaObject::connectSlotsByName(LogQueryDialog);
    } // setupUi

    void retranslateUi(QDialog *LogQueryDialog)
    {
        LogQueryDialog->setWindowTitle(QApplication::translate("LogQueryDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("LogQueryDialog", "\350\265\267\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        beginTime->setText(QString());
        label_2->setText(QApplication::translate("LogQueryDialog", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LogQueryDialog", "\346\237\245\350\257\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("LogQueryDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("LogQueryDialog", "\344\272\213\344\273\266", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LogQueryDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogQueryDialog: public Ui_LogQueryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGQUERYDIALOG_H
