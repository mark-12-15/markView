/********************************************************************************
** Form generated from reading UI file 'BCSettingDisplayInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDISPLAYINFODLG_H
#define UI_BCSETTINGDISPLAYINFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDisplayInfoDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *BCSettingDisplayInfoDlg)
    {
        if (BCSettingDisplayInfoDlg->objectName().isEmpty())
            BCSettingDisplayInfoDlg->setObjectName(QStringLiteral("BCSettingDisplayInfoDlg"));
        BCSettingDisplayInfoDlg->resize(754, 408);
        verticalLayout = new QVBoxLayout(BCSettingDisplayInfoDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        listView = new QListView(BCSettingDisplayInfoDlg);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEnabled(false);
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        listView->setDragEnabled(false);

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(BCSettingDisplayInfoDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(BCSettingDisplayInfoDlg);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BCSettingDisplayInfoDlg);

        QMetaObject::connectSlotsByName(BCSettingDisplayInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingDisplayInfoDlg)
    {
        BCSettingDisplayInfoDlg->setWindowTitle(QApplication::translate("BCSettingDisplayInfoDlg", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BCSettingDisplayInfoDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BCSettingDisplayInfoDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDisplayInfoDlg: public Ui_BCSettingDisplayInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDISPLAYINFODLG_H
