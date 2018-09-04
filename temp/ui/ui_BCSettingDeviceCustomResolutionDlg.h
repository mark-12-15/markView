/********************************************************************************
** Form generated from reading UI file 'BCSettingDeviceCustomResolutionDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDEVICECUSTOMRESOLUTIONDLG_H
#define UI_BCSETTINGDEVICECUSTOMRESOLUTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDeviceCustomResolutionDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *m_pPreWSpinBox;
    QLabel *label_2;
    QSpinBox *m_pSyncWSpinBox;
    QLabel *label_5;
    QLabel *label_4;
    QSpinBox *m_pLiveWSpinBox;
    QLabel *label_3;
    QSpinBox *m_pLiveHSpinBox;
    QSpinBox *m_pPreHSpinBox;
    QLabel *label_6;
    QLabel *label_8;
    QSpinBox *m_pTotalHSpinBox;
    QLabel *label_9;
    QLabel *label_7;
    QSpinBox *m_pTotalWSpinBox;
    QSpinBox *m_pSyncHSpinBox;
    QLabel *label_10;
    QComboBox *m_pPolarityWCombBox;
    QComboBox *m_pPolarityHCombBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QSpinBox *m_pHertzSpinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingDeviceCustomResolutionDlg)
    {
        if (BCSettingDeviceCustomResolutionDlg->objectName().isEmpty())
            BCSettingDeviceCustomResolutionDlg->setObjectName(QStringLiteral("BCSettingDeviceCustomResolutionDlg"));
        BCSettingDeviceCustomResolutionDlg->resize(420, 430);
        verticalLayout = new QVBoxLayout(BCSettingDeviceCustomResolutionDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BCSettingDeviceCustomResolutionDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pPreWSpinBox = new QSpinBox(groupBox);
        m_pPreWSpinBox->setObjectName(QStringLiteral("m_pPreWSpinBox"));
        m_pPreWSpinBox->setMaximum(999);

        gridLayout->addWidget(m_pPreWSpinBox, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        m_pSyncWSpinBox = new QSpinBox(groupBox);
        m_pSyncWSpinBox->setObjectName(QStringLiteral("m_pSyncWSpinBox"));
        m_pSyncWSpinBox->setMaximum(999);

        gridLayout->addWidget(m_pSyncWSpinBox, 5, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        m_pLiveWSpinBox = new QSpinBox(groupBox);
        m_pLiveWSpinBox->setObjectName(QStringLiteral("m_pLiveWSpinBox"));
        m_pLiveWSpinBox->setMaximum(3840);

        gridLayout->addWidget(m_pLiveWSpinBox, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        m_pLiveHSpinBox = new QSpinBox(groupBox);
        m_pLiveHSpinBox->setObjectName(QStringLiteral("m_pLiveHSpinBox"));
        m_pLiveHSpinBox->setMaximum(2160);

        gridLayout->addWidget(m_pLiveHSpinBox, 1, 1, 1, 1);

        m_pPreHSpinBox = new QSpinBox(groupBox);
        m_pPreHSpinBox->setObjectName(QStringLiteral("m_pPreHSpinBox"));
        m_pPreHSpinBox->setMaximum(999);

        gridLayout->addWidget(m_pPreHSpinBox, 3, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 1, 1, 1);

        m_pTotalHSpinBox = new QSpinBox(groupBox);
        m_pTotalHSpinBox->setObjectName(QStringLiteral("m_pTotalHSpinBox"));
        m_pTotalHSpinBox->setMaximum(2160);

        gridLayout->addWidget(m_pTotalHSpinBox, 7, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        m_pTotalWSpinBox = new QSpinBox(groupBox);
        m_pTotalWSpinBox->setObjectName(QStringLiteral("m_pTotalWSpinBox"));
        m_pTotalWSpinBox->setMaximum(3840);

        gridLayout->addWidget(m_pTotalWSpinBox, 7, 0, 1, 1);

        m_pSyncHSpinBox = new QSpinBox(groupBox);
        m_pSyncHSpinBox->setObjectName(QStringLiteral("m_pSyncHSpinBox"));
        m_pSyncHSpinBox->setMaximum(999);

        gridLayout->addWidget(m_pSyncHSpinBox, 5, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 8, 1, 1, 1);

        m_pPolarityWCombBox = new QComboBox(groupBox);
        m_pPolarityWCombBox->setObjectName(QStringLiteral("m_pPolarityWCombBox"));

        gridLayout->addWidget(m_pPolarityWCombBox, 9, 0, 1, 1);

        m_pPolarityHCombBox = new QComboBox(groupBox);
        m_pPolarityHCombBox->setObjectName(QStringLiteral("m_pPolarityHCombBox"));

        gridLayout->addWidget(m_pPolarityHCombBox, 9, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BCSettingDeviceCustomResolutionDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);

        m_pHertzSpinBox = new QSpinBox(groupBox_2);
        m_pHertzSpinBox->setObjectName(QStringLiteral("m_pHertzSpinBox"));

        horizontalLayout->addWidget(m_pHertzSpinBox);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingDeviceCustomResolutionDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingDeviceCustomResolutionDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BCSettingDeviceCustomResolutionDlg);

        QMetaObject::connectSlotsByName(BCSettingDeviceCustomResolutionDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingDeviceCustomResolutionDlg)
    {
        BCSettingDeviceCustomResolutionDlg->setWindowTitle(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\237\272\347\241\200\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\346\264\273\345\212\250\346\260\264\345\271\263\345\203\217\347\264\240", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\346\264\273\345\212\250\345\236\202\347\233\264\345\203\217\347\264\240", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\346\260\264\345\271\263\345\220\214\346\255\245\345\256\275\345\272\246", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\236\202\347\233\264\345\211\215\346\262\277", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\346\260\264\345\271\263\345\211\215\346\262\277", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\236\202\347\233\264\345\220\214\346\255\245\345\256\275\345\272\246", Q_NULLPTR));
        label_8->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\236\202\347\233\264\346\200\273\346\225\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\346\260\264\345\271\263\345\220\214\346\255\245\346\236\201\346\200\247", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\346\260\264\345\271\263\346\200\273\346\225\260", Q_NULLPTR));
        label_10->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\236\202\347\233\264\345\220\214\346\255\245\346\236\201\346\200\247", Q_NULLPTR));
        m_pPolarityWCombBox->clear();
        m_pPolarityWCombBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDeviceCustomResolutionDlg", "+", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceCustomResolutionDlg", "-", Q_NULLPTR)
        );
        m_pPolarityHCombBox->clear();
        m_pPolarityHCombBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDeviceCustomResolutionDlg", "+", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceCustomResolutionDlg", "-", Q_NULLPTR)
        );
        groupBox_2->setTitle(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\210\267\346\226\260\345\217\202\346\225\260", Q_NULLPTR));
        label_11->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\210\267\346\226\260\351\242\221\347\216\207", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingDeviceCustomResolutionDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDeviceCustomResolutionDlg: public Ui_BCSettingDeviceCustomResolutionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDEVICECUSTOMRESOLUTIONDLG_H
