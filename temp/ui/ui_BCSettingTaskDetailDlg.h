/********************************************************************************
** Form generated from reading UI file 'BCSettingTaskDetailDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGTASKDETAILDLG_H
#define UI_BCSETTINGTASKDETAILDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSettingTaskDetailDlg.h"

QT_BEGIN_NAMESPACE

class Ui_BCSettingTaskDetailDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *m_pTaskTypeCombBox;
    QDateTimeEdit *m_pTaskTimeEdit;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    BCDateButton *m_pMondayBtn;
    BCDateButton *m_pTuesdayBtn;
    BCDateButton *m_pWednesdayBtn;
    BCDateButton *m_pThursdayBtn;
    BCDateButton *m_pFridayBtn;
    BCDateButton *m_pSaturdayBtn;
    BCDateButton *m_pSundayBtn;
    QGroupBox *m_pParaGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *m_pRoomCombBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *m_pSceneLable;
    QComboBox *m_pSceneIDComboBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QWidget *BCSettingTaskDetailDlg)
    {
        if (BCSettingTaskDetailDlg->objectName().isEmpty())
            BCSettingTaskDetailDlg->setObjectName(QStringLiteral("BCSettingTaskDetailDlg"));
        BCSettingTaskDetailDlg->resize(630, 234);
        verticalLayout = new QVBoxLayout(BCSettingTaskDetailDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pTaskTypeCombBox = new QComboBox(BCSettingTaskDetailDlg);
        m_pTaskTypeCombBox->setObjectName(QStringLiteral("m_pTaskTypeCombBox"));
        m_pTaskTypeCombBox->setMinimumSize(QSize(150, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pTaskTypeCombBox->setFont(font);

        horizontalLayout->addWidget(m_pTaskTypeCombBox);

        m_pTaskTimeEdit = new QDateTimeEdit(BCSettingTaskDetailDlg);
        m_pTaskTimeEdit->setObjectName(QStringLiteral("m_pTaskTimeEdit"));
        m_pTaskTimeEdit->setMaximumSize(QSize(130, 16777215));
        m_pTaskTimeEdit->setFont(font);

        horizontalLayout->addWidget(m_pTaskTimeEdit);

        horizontalSpacer = new QSpacerItem(170, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(BCSettingTaskDetailDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(200, 0));
        groupBox->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_pMondayBtn = new BCDateButton(groupBox);
        m_pMondayBtn->setObjectName(QStringLiteral("m_pMondayBtn"));
        m_pMondayBtn->setFont(font);
        m_pMondayBtn->setFlat(true);

        horizontalLayout_2->addWidget(m_pMondayBtn);

        m_pTuesdayBtn = new BCDateButton(groupBox);
        m_pTuesdayBtn->setObjectName(QStringLiteral("m_pTuesdayBtn"));
        m_pTuesdayBtn->setFont(font);
        m_pTuesdayBtn->setFlat(true);

        horizontalLayout_2->addWidget(m_pTuesdayBtn);

        m_pWednesdayBtn = new BCDateButton(groupBox);
        m_pWednesdayBtn->setObjectName(QStringLiteral("m_pWednesdayBtn"));
        m_pWednesdayBtn->setFont(font);
        m_pWednesdayBtn->setFlat(true);

        horizontalLayout_2->addWidget(m_pWednesdayBtn);

        m_pThursdayBtn = new BCDateButton(groupBox);
        m_pThursdayBtn->setObjectName(QStringLiteral("m_pThursdayBtn"));
        m_pThursdayBtn->setFont(font);
        m_pThursdayBtn->setFlat(true);

        horizontalLayout_2->addWidget(m_pThursdayBtn);

        m_pFridayBtn = new BCDateButton(groupBox);
        m_pFridayBtn->setObjectName(QStringLiteral("m_pFridayBtn"));
        m_pFridayBtn->setFont(font);
        m_pFridayBtn->setFlat(true);

        horizontalLayout_2->addWidget(m_pFridayBtn);

        m_pSaturdayBtn = new BCDateButton(groupBox);
        m_pSaturdayBtn->setObjectName(QStringLiteral("m_pSaturdayBtn"));
        m_pSaturdayBtn->setFont(font);
        m_pSaturdayBtn->setFlat(true);

        horizontalLayout_2->addWidget(m_pSaturdayBtn);

        m_pSundayBtn = new BCDateButton(groupBox);
        m_pSundayBtn->setObjectName(QStringLiteral("m_pSundayBtn"));
        m_pSundayBtn->setFont(font);
        m_pSundayBtn->setFlat(true);

        horizontalLayout_2->addWidget(m_pSundayBtn);


        verticalLayout->addWidget(groupBox);

        m_pParaGroupBox = new QGroupBox(BCSettingTaskDetailDlg);
        m_pParaGroupBox->setObjectName(QStringLiteral("m_pParaGroupBox"));
        m_pParaGroupBox->setFont(font);
        horizontalLayout_4 = new QHBoxLayout(m_pParaGroupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(m_pParaGroupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        m_pRoomCombBox = new QComboBox(m_pParaGroupBox);
        m_pRoomCombBox->setObjectName(QStringLiteral("m_pRoomCombBox"));
        m_pRoomCombBox->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(m_pRoomCombBox);

        horizontalSpacer_3 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        m_pSceneLable = new QLabel(m_pParaGroupBox);
        m_pSceneLable->setObjectName(QStringLiteral("m_pSceneLable"));

        horizontalLayout_4->addWidget(m_pSceneLable);

        m_pSceneIDComboBox = new QComboBox(m_pParaGroupBox);
        m_pSceneIDComboBox->setObjectName(QStringLiteral("m_pSceneIDComboBox"));
        m_pSceneIDComboBox->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(m_pSceneIDComboBox);


        verticalLayout->addWidget(m_pParaGroupBox);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        m_pOKBtn = new QPushButton(BCSettingTaskDetailDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_3->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingTaskDetailDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_3->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(BCSettingTaskDetailDlg);

        QMetaObject::connectSlotsByName(BCSettingTaskDetailDlg);
    } // setupUi

    void retranslateUi(QWidget *BCSettingTaskDetailDlg)
    {
        BCSettingTaskDetailDlg->setWindowTitle(QApplication::translate("BCSettingTaskDetailDlg", "\344\273\273\345\212\241\346\230\216\347\273\206", Q_NULLPTR));
        m_pTaskTypeCombBox->clear();
        m_pTaskTypeCombBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingTaskDetailDlg", "\345\274\200\346\234\272", Q_NULLPTR)
         << QApplication::translate("BCSettingTaskDetailDlg", "\345\205\263\346\234\272", Q_NULLPTR)
         << QApplication::translate("BCSettingTaskDetailDlg", "\346\211\223\345\274\200\345\234\272\346\231\257\350\275\256\345\267\241", Q_NULLPTR)
         << QApplication::translate("BCSettingTaskDetailDlg", "\345\205\263\351\227\255\345\234\272\346\231\257\350\275\256\345\267\241", Q_NULLPTR)
         << QApplication::translate("BCSettingTaskDetailDlg", "\350\260\203\347\224\250\345\234\272\346\231\257", Q_NULLPTR)
        );
        m_pTaskTimeEdit->setDisplayFormat(QApplication::translate("BCSettingTaskDetailDlg", "H:mm", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingTaskDetailDlg", "\351\207\215\345\244\215", Q_NULLPTR));
        m_pMondayBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\221\250\344\270\200", Q_NULLPTR));
        m_pTuesdayBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\221\250\344\272\214", Q_NULLPTR));
        m_pWednesdayBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\221\250\344\270\211", Q_NULLPTR));
        m_pThursdayBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\221\250\345\233\233", Q_NULLPTR));
        m_pFridayBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\221\250\344\272\224", Q_NULLPTR));
        m_pSaturdayBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\221\250\345\205\255", Q_NULLPTR));
        m_pSundayBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\221\250\346\227\245", Q_NULLPTR));
        m_pParaGroupBox->setTitle(QApplication::translate("BCSettingTaskDetailDlg", "\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingTaskDetailDlg", "\346\210\277\351\227\264", Q_NULLPTR));
        m_pSceneLable->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\234\272\346\231\257\345\272\217\345\217\267", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingTaskDetailDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingTaskDetailDlg: public Ui_BCSettingTaskDetailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGTASKDETAILDLG_H
