/********************************************************************************
** Form generated from reading UI file 'BCSettingRoomVirtualResolutionDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGROOMVIRTUALRESOLUTIONDLG_H
#define UI_BCSETTINGROOMVIRTUALRESOLUTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingRoomVirtualResolutionDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_pHeightLineEdit;
    QLabel *label_4;
    QLineEdit *m_pWidthLineEdit;
    QCheckBox *m_pUseVirtualArrayCheckBox;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *m_pArrayYLineEdit;
    QLineEdit *m_pArrayXLineEdit;
    QCheckBox *m_pUseVirtualResolutionCheckBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pApplyBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingRoomVirtualResolutionDlg)
    {
        if (BCSettingRoomVirtualResolutionDlg->objectName().isEmpty())
            BCSettingRoomVirtualResolutionDlg->setObjectName(QStringLiteral("BCSettingRoomVirtualResolutionDlg"));
        BCSettingRoomVirtualResolutionDlg->resize(331, 182);
        verticalLayout = new QVBoxLayout(BCSettingRoomVirtualResolutionDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingRoomVirtualResolutionDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        m_pHeightLineEdit = new QLineEdit(BCSettingRoomVirtualResolutionDlg);
        m_pHeightLineEdit->setObjectName(QStringLiteral("m_pHeightLineEdit"));
        m_pHeightLineEdit->setFont(font);

        gridLayout->addWidget(m_pHeightLineEdit, 1, 3, 1, 1);

        label_4 = new QLabel(BCSettingRoomVirtualResolutionDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 2, 1, 1);

        m_pWidthLineEdit = new QLineEdit(BCSettingRoomVirtualResolutionDlg);
        m_pWidthLineEdit->setObjectName(QStringLiteral("m_pWidthLineEdit"));
        m_pWidthLineEdit->setFont(font);

        gridLayout->addWidget(m_pWidthLineEdit, 1, 1, 1, 1);

        m_pUseVirtualArrayCheckBox = new QCheckBox(BCSettingRoomVirtualResolutionDlg);
        m_pUseVirtualArrayCheckBox->setObjectName(QStringLiteral("m_pUseVirtualArrayCheckBox"));
        m_pUseVirtualArrayCheckBox->setFont(font);

        gridLayout->addWidget(m_pUseVirtualArrayCheckBox, 2, 0, 1, 4);

        label_3 = new QLabel(BCSettingRoomVirtualResolutionDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(BCSettingRoomVirtualResolutionDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        m_pArrayYLineEdit = new QLineEdit(BCSettingRoomVirtualResolutionDlg);
        m_pArrayYLineEdit->setObjectName(QStringLiteral("m_pArrayYLineEdit"));
        m_pArrayYLineEdit->setFont(font);

        gridLayout->addWidget(m_pArrayYLineEdit, 3, 3, 1, 1);

        m_pArrayXLineEdit = new QLineEdit(BCSettingRoomVirtualResolutionDlg);
        m_pArrayXLineEdit->setObjectName(QStringLiteral("m_pArrayXLineEdit"));
        m_pArrayXLineEdit->setFont(font);

        gridLayout->addWidget(m_pArrayXLineEdit, 3, 1, 1, 1);

        m_pUseVirtualResolutionCheckBox = new QCheckBox(BCSettingRoomVirtualResolutionDlg);
        m_pUseVirtualResolutionCheckBox->setObjectName(QStringLiteral("m_pUseVirtualResolutionCheckBox"));
        m_pUseVirtualResolutionCheckBox->setFont(font);

        gridLayout->addWidget(m_pUseVirtualResolutionCheckBox, 0, 0, 1, 4);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pApplyBtn = new QPushButton(BCSettingRoomVirtualResolutionDlg);
        m_pApplyBtn->setObjectName(QStringLiteral("m_pApplyBtn"));
        m_pApplyBtn->setFont(font);

        horizontalLayout->addWidget(m_pApplyBtn);

        m_pCancelBtn = new QPushButton(BCSettingRoomVirtualResolutionDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BCSettingRoomVirtualResolutionDlg);

        QMetaObject::connectSlotsByName(BCSettingRoomVirtualResolutionDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingRoomVirtualResolutionDlg)
    {
        BCSettingRoomVirtualResolutionDlg->setWindowTitle(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\345\261\217\345\271\225\346\200\273\345\256\275\345\272\246", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\345\261\217\345\271\225\346\216\222\345\210\227Y", Q_NULLPTR));
        m_pUseVirtualArrayCheckBox->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\346\230\257\345\220\246\344\275\277\347\224\250\350\231\232\346\213\237\345\210\206\345\211\262", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\345\261\217\345\271\225\346\216\222\345\210\227X", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\345\261\217\345\271\225\346\200\273\351\253\230\345\272\246", Q_NULLPTR));
        m_pUseVirtualResolutionCheckBox->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\346\230\257\345\220\246\344\275\277\347\224\250\350\231\232\346\213\237\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        m_pApplyBtn->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingRoomVirtualResolutionDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingRoomVirtualResolutionDlg: public Ui_BCSettingRoomVirtualResolutionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGROOMVIRTUALRESOLUTIONDLG_H
