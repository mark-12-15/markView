/********************************************************************************
** Form generated from reading UI file 'BCSettingJointMatrixChannelConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGJOINTMATRIXCHANNELCONFIGDLG_H
#define UI_BCSETTINGJOINTMATRIXCHANNELCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSettingJointMatrixChannelConfigDlg
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *m_pMatrixTreeWidget;
    QLabel *label;
    QTreeWidget *m_pVP4000TreeWidget;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingJointMatrixChannelConfigDlg)
    {
        if (BCSettingJointMatrixChannelConfigDlg->objectName().isEmpty())
            BCSettingJointMatrixChannelConfigDlg->setObjectName(QStringLiteral("BCSettingJointMatrixChannelConfigDlg"));
        BCSettingJointMatrixChannelConfigDlg->resize(429, 377);
        gridLayout = new QGridLayout(BCSettingJointMatrixChannelConfigDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_pMatrixTreeWidget = new QTreeWidget(BCSettingJointMatrixChannelConfigDlg);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pMatrixTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pMatrixTreeWidget->setObjectName(QStringLiteral("m_pMatrixTreeWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pMatrixTreeWidget->setFont(font);

        gridLayout->addWidget(m_pMatrixTreeWidget, 1, 1, 1, 1);

        label = new QLabel(BCSettingJointMatrixChannelConfigDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        m_pVP4000TreeWidget = new QTreeWidget(BCSettingJointMatrixChannelConfigDlg);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        m_pVP4000TreeWidget->setHeaderItem(__qtreewidgetitem1);
        m_pVP4000TreeWidget->setObjectName(QStringLiteral("m_pVP4000TreeWidget"));
        m_pVP4000TreeWidget->setFont(font);

        gridLayout->addWidget(m_pVP4000TreeWidget, 1, 0, 1, 1);

        label_2 = new QLabel(BCSettingJointMatrixChannelConfigDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingJointMatrixChannelConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingJointMatrixChannelConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);


        retranslateUi(BCSettingJointMatrixChannelConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingJointMatrixChannelConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingJointMatrixChannelConfigDlg)
    {
        BCSettingJointMatrixChannelConfigDlg->setWindowTitle(QApplication::translate("BCSettingJointMatrixChannelConfigDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingJointMatrixChannelConfigDlg", "\347\237\251\351\230\265\350\276\223\345\207\272\345\217\243", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingJointMatrixChannelConfigDlg", "\350\256\276\345\244\207\350\276\223\345\205\245\345\217\243", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingJointMatrixChannelConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingJointMatrixChannelConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingJointMatrixChannelConfigDlg: public Ui_BCSettingJointMatrixChannelConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGJOINTMATRIXCHANNELCONFIGDLG_H
