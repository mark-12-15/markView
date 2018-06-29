/********************************************************************************
** Form generated from reading UI file 'AlarmManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMMANAGEMENT_H
#define UI_ALARMMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AlarmManagement
{
public:
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *AlarmManagement)
    {
        if (AlarmManagement->objectName().isEmpty())
            AlarmManagement->setObjectName(QStringLiteral("AlarmManagement"));
        AlarmManagement->resize(506, 241);
        AlarmManagement->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(AlarmManagement);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidget = new QTreeWidget(AlarmManagement);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(0, 120));

        horizontalLayout->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(AlarmManagement);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(AlarmManagement);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(AlarmManagement);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(AlarmManagement);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(AlarmManagement);

        QMetaObject::connectSlotsByName(AlarmManagement);
    } // setupUi

    void retranslateUi(QDialog *AlarmManagement)
    {
        AlarmManagement->setWindowTitle(QApplication::translate("AlarmManagement", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AlarmManagement", "\345\205\250\351\200\211", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AlarmManagement", "\345\205\250\344\270\215\351\200\211", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("AlarmManagement", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("AlarmManagement", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AlarmManagement: public Ui_AlarmManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMMANAGEMENT_H
