/********************************************************************************
** Form generated from reading UI file 'BCSettingDisplaySwitchConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDISPLAYSWITCHCONFIGDLG_H
#define UI_BCSETTINGDISPLAYSWITCHCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDisplaySwitchConfigDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *m_pRoomGroupBox;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *m_pScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pDisplayMakerBtn;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingDisplaySwitchConfigDlg)
    {
        if (BCSettingDisplaySwitchConfigDlg->objectName().isEmpty())
            BCSettingDisplaySwitchConfigDlg->setObjectName(QStringLiteral("BCSettingDisplaySwitchConfigDlg"));
        BCSettingDisplaySwitchConfigDlg->resize(528, 437);
        verticalLayout = new QVBoxLayout(BCSettingDisplaySwitchConfigDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pRoomGroupBox = new QGroupBox(BCSettingDisplaySwitchConfigDlg);
        m_pRoomGroupBox->setObjectName(QStringLiteral("m_pRoomGroupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pRoomGroupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(m_pRoomGroupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        m_pScrollArea = new QScrollArea(m_pRoomGroupBox);
        m_pScrollArea->setObjectName(QStringLiteral("m_pScrollArea"));
        m_pScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 504, 363));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_3->addWidget(widget);

        m_pScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(m_pScrollArea);


        verticalLayout->addWidget(m_pRoomGroupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pDisplayMakerBtn = new QPushButton(BCSettingDisplaySwitchConfigDlg);
        m_pDisplayMakerBtn->setObjectName(QStringLiteral("m_pDisplayMakerBtn"));
        m_pDisplayMakerBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pDisplayMakerBtn);

        m_pOKBtn = new QPushButton(BCSettingDisplaySwitchConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingDisplaySwitchConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(m_pDisplayMakerBtn, m_pOKBtn);
        QWidget::setTabOrder(m_pOKBtn, m_pCancelBtn);

        retranslateUi(BCSettingDisplaySwitchConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingDisplaySwitchConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingDisplaySwitchConfigDlg)
    {
        BCSettingDisplaySwitchConfigDlg->setWindowTitle(QApplication::translate("BCSettingDisplaySwitchConfigDlg", "Dialog", Q_NULLPTR));
        m_pRoomGroupBox->setTitle(QApplication::translate("BCSettingDisplaySwitchConfigDlg", "\346\210\277\351\227\264\345\210\227\350\241\250", Q_NULLPTR));
        m_pDisplayMakerBtn->setText(QApplication::translate("BCSettingDisplaySwitchConfigDlg", "\346\267\273\345\212\240\345\215\217\350\256\256", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingDisplaySwitchConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingDisplaySwitchConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDisplaySwitchConfigDlg: public Ui_BCSettingDisplaySwitchConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDISPLAYSWITCHCONFIGDLG_H
