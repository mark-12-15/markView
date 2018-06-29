/********************************************************************************
** Form generated from reading UI file 'BCWarningLogWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCWARNINGLOGWINDOW_H
#define UI_BCWARNINGLOGWINDOW_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCWarningLogWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *UserName;
    QLabel *label_3;
    QLineEdit *Grades;
    QPushButton *QueryBut;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Event;
    QLabel *label_4;
    QLineEdit *Time;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;

    void setupUi(QDialog *BCWarningLogWindow)
    {
        if (BCWarningLogWindow->objectName().isEmpty())
            BCWarningLogWindow->setObjectName(QStringLiteral("BCWarningLogWindow"));
        BCWarningLogWindow->resize(471, 313);
        verticalLayout = new QVBoxLayout(BCWarningLogWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(BCWarningLogWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        UserName = new QLineEdit(groupBox_2);
        UserName->setObjectName(QStringLiteral("UserName"));

        horizontalLayout->addWidget(UserName);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(36, 0));
        label_3->setMaximumSize(QSize(36, 16777215));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        Grades = new QLineEdit(groupBox_2);
        Grades->setObjectName(QStringLiteral("Grades"));

        horizontalLayout->addWidget(Grades);

        QueryBut = new QPushButton(groupBox_2);
        QueryBut->setObjectName(QStringLiteral("QueryBut"));
        QueryBut->setFont(font);

        horizontalLayout->addWidget(QueryBut);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(36, 0));
        label_2->setMaximumSize(QSize(36, 16777215));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        Event = new QLineEdit(groupBox_2);
        Event->setObjectName(QStringLiteral("Event"));

        horizontalLayout_2->addWidget(Event);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(36, 0));
        label_4->setMaximumSize(QSize(36, 16777215));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        Time = new QLineEdit(groupBox_2);
        Time->setObjectName(QStringLiteral("Time"));

        horizontalLayout_2->addWidget(Time);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(BCWarningLogWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_3->addWidget(tableWidget);


        verticalLayout->addWidget(groupBox);


        retranslateUi(BCWarningLogWindow);

        QMetaObject::connectSlotsByName(BCWarningLogWindow);
    } // setupUi

    void retranslateUi(QDialog *BCWarningLogWindow)
    {
        BCWarningLogWindow->setWindowTitle(QApplication::translate("BCWarningLogWindow", "Dialog", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("BCWarningLogWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCWarningLogWindow", "\347\255\211\347\272\247", Q_NULLPTR));
        QueryBut->setText(QApplication::translate("BCWarningLogWindow", "\346\237\245\346\211\276", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCWarningLogWindow", "\344\272\213\344\273\266", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCWarningLogWindow", "\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BCWarningLogWindow", "\345\217\226\346\266\210", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCWarningLogWindow", "\346\212\245\350\255\246\346\227\245\345\277\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCWarningLogWindow: public Ui_BCWarningLogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCWARNINGLOGWINDOW_H
