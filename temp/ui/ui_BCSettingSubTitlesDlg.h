/********************************************************************************
** Form generated from reading UI file 'BCSettingSubTitlesDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGSUBTITLESDLG_H
#define UI_BCSETTINGSUBTITLESDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSettingSubTitlesDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOkBtn;
    QPushButton *m_pCancelBtn;
    QPushButton *m_pApplyBtn;
    QComboBox *m_pVisibleCombBox;
    QPushButton *m_pColorBtn;
    QLineEdit *m_pPosYLineEdit;
    QLineEdit *m_pPosXLineEdit;
    QLineEdit *m_pTextLineEdit;

    void setupUi(QDialog *BCSettingSubTitlesDlg)
    {
        if (BCSettingSubTitlesDlg->objectName().isEmpty())
            BCSettingSubTitlesDlg->setObjectName(QStringLiteral("BCSettingSubTitlesDlg"));
        BCSettingSubTitlesDlg->resize(317, 190);
        gridLayout = new QGridLayout(BCSettingSubTitlesDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingSubTitlesDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(BCSettingSubTitlesDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_5 = new QLabel(BCSettingSubTitlesDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_3 = new QLabel(BCSettingSubTitlesDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(BCSettingSubTitlesDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

        m_pOkBtn = new QPushButton(BCSettingSubTitlesDlg);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        m_pOkBtn->setFont(font);

        gridLayout->addWidget(m_pOkBtn, 5, 1, 1, 1);

        m_pCancelBtn = new QPushButton(BCSettingSubTitlesDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        gridLayout->addWidget(m_pCancelBtn, 5, 2, 1, 1);

        m_pApplyBtn = new QPushButton(BCSettingSubTitlesDlg);
        m_pApplyBtn->setObjectName(QStringLiteral("m_pApplyBtn"));
        m_pApplyBtn->setFont(font);

        gridLayout->addWidget(m_pApplyBtn, 5, 3, 1, 1);

        m_pVisibleCombBox = new QComboBox(BCSettingSubTitlesDlg);
        m_pVisibleCombBox->setObjectName(QStringLiteral("m_pVisibleCombBox"));
        m_pVisibleCombBox->setFont(font);

        gridLayout->addWidget(m_pVisibleCombBox, 4, 1, 1, 3);

        m_pColorBtn = new QPushButton(BCSettingSubTitlesDlg);
        m_pColorBtn->setObjectName(QStringLiteral("m_pColorBtn"));
        m_pColorBtn->setFont(font);

        gridLayout->addWidget(m_pColorBtn, 3, 1, 1, 3);

        m_pPosYLineEdit = new QLineEdit(BCSettingSubTitlesDlg);
        m_pPosYLineEdit->setObjectName(QStringLiteral("m_pPosYLineEdit"));
        m_pPosYLineEdit->setFont(font);

        gridLayout->addWidget(m_pPosYLineEdit, 2, 1, 1, 3);

        m_pPosXLineEdit = new QLineEdit(BCSettingSubTitlesDlg);
        m_pPosXLineEdit->setObjectName(QStringLiteral("m_pPosXLineEdit"));
        m_pPosXLineEdit->setFont(font);

        gridLayout->addWidget(m_pPosXLineEdit, 1, 1, 1, 3);

        m_pTextLineEdit = new QLineEdit(BCSettingSubTitlesDlg);
        m_pTextLineEdit->setObjectName(QStringLiteral("m_pTextLineEdit"));
        m_pTextLineEdit->setFont(font);

        gridLayout->addWidget(m_pTextLineEdit, 0, 1, 1, 3);

        QWidget::setTabOrder(m_pTextLineEdit, m_pPosXLineEdit);
        QWidget::setTabOrder(m_pPosXLineEdit, m_pPosYLineEdit);
        QWidget::setTabOrder(m_pPosYLineEdit, m_pColorBtn);
        QWidget::setTabOrder(m_pColorBtn, m_pVisibleCombBox);
        QWidget::setTabOrder(m_pVisibleCombBox, m_pOkBtn);
        QWidget::setTabOrder(m_pOkBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pApplyBtn);

        retranslateUi(BCSettingSubTitlesDlg);

        QMetaObject::connectSlotsByName(BCSettingSubTitlesDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingSubTitlesDlg)
    {
        BCSettingSubTitlesDlg->setWindowTitle(QApplication::translate("BCSettingSubTitlesDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingSubTitlesDlg", "\345\255\227\345\271\225\346\226\207\346\234\254", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingSubTitlesDlg", "\345\255\227\345\271\225\344\275\215\347\275\256X", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingSubTitlesDlg", "\345\255\227\345\271\225\344\275\215\347\275\256Y", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingSubTitlesDlg", "\345\255\227\345\271\225\351\242\234\350\211\262", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingSubTitlesDlg", "\346\230\257\345\220\246\346\230\276\347\244\272", Q_NULLPTR));
        m_pOkBtn->setText(QApplication::translate("BCSettingSubTitlesDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingSubTitlesDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        m_pApplyBtn->setText(QApplication::translate("BCSettingSubTitlesDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        m_pVisibleCombBox->clear();
        m_pVisibleCombBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingSubTitlesDlg", "\345\220\246", Q_NULLPTR)
         << QApplication::translate("BCSettingSubTitlesDlg", "\346\230\257", Q_NULLPTR)
        );
        m_pColorBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCSettingSubTitlesDlg: public Ui_BCSettingSubTitlesDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGSUBTITLESDLG_H
