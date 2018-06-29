/********************************************************************************
** Form generated from reading UI file 'BCSettingIPVSignalWindowLoopConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGIPVSIGNALWINDOWLOOPCONFIGDLG_H
#define UI_BCSETTINGIPVSIGNALWINDOWLOOPCONFIGDLG_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSettingIPVSignalWindowLoopConfigDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;
    QTreeWidget *m_pCameraTreeWidget;
    QLabel *label;
    QSpinBox *m_pIntervalSpinBox;

    void setupUi(QDialog *BCSettingIPVSignalWindowLoopConfigDlg)
    {
        if (BCSettingIPVSignalWindowLoopConfigDlg->objectName().isEmpty())
            BCSettingIPVSignalWindowLoopConfigDlg->setObjectName(QStringLiteral("BCSettingIPVSignalWindowLoopConfigDlg"));
        BCSettingIPVSignalWindowLoopConfigDlg->resize(261, 305);
        gridLayout = new QGridLayout(BCSettingIPVSignalWindowLoopConfigDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingIPVSignalWindowLoopConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingIPVSignalWindowLoopConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);

        m_pCameraTreeWidget = new QTreeWidget(BCSettingIPVSignalWindowLoopConfigDlg);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pCameraTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pCameraTreeWidget->setObjectName(QStringLiteral("m_pCameraTreeWidget"));
        m_pCameraTreeWidget->setFont(font);
        m_pCameraTreeWidget->setColumnCount(1);
        m_pCameraTreeWidget->header()->setVisible(false);

        gridLayout->addWidget(m_pCameraTreeWidget, 1, 0, 1, 3);

        label = new QLabel(BCSettingIPVSignalWindowLoopConfigDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pIntervalSpinBox = new QSpinBox(BCSettingIPVSignalWindowLoopConfigDlg);
        m_pIntervalSpinBox->setObjectName(QStringLiteral("m_pIntervalSpinBox"));
        m_pIntervalSpinBox->setFont(font);

        gridLayout->addWidget(m_pIntervalSpinBox, 0, 2, 1, 1);


        retranslateUi(BCSettingIPVSignalWindowLoopConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingIPVSignalWindowLoopConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingIPVSignalWindowLoopConfigDlg)
    {
        BCSettingIPVSignalWindowLoopConfigDlg->setWindowTitle(QApplication::translate("BCSettingIPVSignalWindowLoopConfigDlg", "Dialog", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingIPVSignalWindowLoopConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingIPVSignalWindowLoopConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingIPVSignalWindowLoopConfigDlg", "\350\275\256\345\267\241\346\227\266\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingIPVSignalWindowLoopConfigDlg: public Ui_BCSettingIPVSignalWindowLoopConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGIPVSIGNALWINDOWLOOPCONFIGDLG_H
