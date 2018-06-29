/********************************************************************************
** Form generated from reading UI file 'BCSettingTaskPlanningDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGTASKPLANNINGDLG_H
#define UI_BCSETTINGTASKPLANNINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingTaskPlanningDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *m_pAddBtn;
    QToolButton *m_pModifyBtn;
    QToolButton *m_pRemoveBtn;
    QToolButton *m_pClearBtn;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QDialog *BCSettingTaskPlanningDlg)
    {
        if (BCSettingTaskPlanningDlg->objectName().isEmpty())
            BCSettingTaskPlanningDlg->setObjectName(QStringLiteral("BCSettingTaskPlanningDlg"));
        BCSettingTaskPlanningDlg->resize(514, 303);
        verticalLayout = new QVBoxLayout(BCSettingTaskPlanningDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pAddBtn = new QToolButton(BCSettingTaskPlanningDlg);
        m_pAddBtn->setObjectName(QStringLiteral("m_pAddBtn"));
        m_pAddBtn->setMinimumSize(QSize(24, 24));
        m_pAddBtn->setMaximumSize(QSize(24, 24));
        m_pAddBtn->setIconSize(QSize(16, 16));
        m_pAddBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pAddBtn);

        m_pModifyBtn = new QToolButton(BCSettingTaskPlanningDlg);
        m_pModifyBtn->setObjectName(QStringLiteral("m_pModifyBtn"));
        m_pModifyBtn->setMinimumSize(QSize(24, 24));
        m_pModifyBtn->setMaximumSize(QSize(24, 24));
        m_pModifyBtn->setIconSize(QSize(16, 16));
        m_pModifyBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pModifyBtn);

        m_pRemoveBtn = new QToolButton(BCSettingTaskPlanningDlg);
        m_pRemoveBtn->setObjectName(QStringLiteral("m_pRemoveBtn"));
        m_pRemoveBtn->setMinimumSize(QSize(24, 24));
        m_pRemoveBtn->setMaximumSize(QSize(24, 24));
        m_pRemoveBtn->setIconSize(QSize(16, 16));
        m_pRemoveBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pRemoveBtn);

        m_pClearBtn = new QToolButton(BCSettingTaskPlanningDlg);
        m_pClearBtn->setObjectName(QStringLiteral("m_pClearBtn"));
        m_pClearBtn->setMinimumSize(QSize(24, 24));
        m_pClearBtn->setMaximumSize(QSize(24, 24));
        m_pClearBtn->setIconSize(QSize(16, 16));
        m_pClearBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pClearBtn);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(BCSettingTaskPlanningDlg);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(tableWidget);

        QWidget::setTabOrder(m_pAddBtn, m_pModifyBtn);
        QWidget::setTabOrder(m_pModifyBtn, m_pRemoveBtn);
        QWidget::setTabOrder(m_pRemoveBtn, m_pClearBtn);
        QWidget::setTabOrder(m_pClearBtn, tableWidget);

        retranslateUi(BCSettingTaskPlanningDlg);

        QMetaObject::connectSlotsByName(BCSettingTaskPlanningDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingTaskPlanningDlg)
    {
        BCSettingTaskPlanningDlg->setWindowTitle(QApplication::translate("BCSettingTaskPlanningDlg", "Dialog", Q_NULLPTR));
        m_pAddBtn->setText(QString());
        m_pModifyBtn->setText(QString());
        m_pRemoveBtn->setText(QString());
        m_pClearBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCSettingTaskPlanningDlg: public Ui_BCSettingTaskPlanningDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGTASKPLANNINGDLG_H
