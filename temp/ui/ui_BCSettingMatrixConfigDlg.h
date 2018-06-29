/********************************************************************************
** Form generated from reading UI file 'BCSettingMatrixConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGMATRIXCONFIGDLG_H
#define UI_BCSETTINGMATRIXCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BCSettingMatrixConfigDlg
{
public:
    QGridLayout *gridLayout;
    QListWidget *m_pListWidget;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *m_pNameLineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *m_pIPLineEdit;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *m_pPortLineEdit;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;
    QSpinBox *m_pInputSpinBox;
    QSpinBox *m_pOutputSpinBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_pAddBtn;
    QPushButton *m_pDelBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *BCSettingMatrixConfigDlg)
    {
        if (BCSettingMatrixConfigDlg->objectName().isEmpty())
            BCSettingMatrixConfigDlg->setObjectName(QStringLiteral("BCSettingMatrixConfigDlg"));
        BCSettingMatrixConfigDlg->resize(349, 331);
        gridLayout = new QGridLayout(BCSettingMatrixConfigDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_pListWidget = new QListWidget(BCSettingMatrixConfigDlg);
        m_pListWidget->setObjectName(QStringLiteral("m_pListWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pListWidget->setFont(font);

        gridLayout->addWidget(m_pListWidget, 0, 0, 1, 5);

        label = new QLabel(BCSettingMatrixConfigDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        m_pNameLineEdit = new QLineEdit(BCSettingMatrixConfigDlg);
        m_pNameLineEdit->setObjectName(QStringLiteral("m_pNameLineEdit"));
        m_pNameLineEdit->setFont(font);

        gridLayout->addWidget(m_pNameLineEdit, 2, 3, 1, 2);

        label_2 = new QLabel(BCSettingMatrixConfigDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        m_pIPLineEdit = new QLineEdit(BCSettingMatrixConfigDlg);
        m_pIPLineEdit->setObjectName(QStringLiteral("m_pIPLineEdit"));
        m_pIPLineEdit->setFont(font);

        gridLayout->addWidget(m_pIPLineEdit, 3, 3, 1, 2);

        label_3 = new QLabel(BCSettingMatrixConfigDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 2, 1, 1);

        m_pPortLineEdit = new QLineEdit(BCSettingMatrixConfigDlg);
        m_pPortLineEdit->setObjectName(QStringLiteral("m_pPortLineEdit"));
        m_pPortLineEdit->setFont(font);

        gridLayout->addWidget(m_pPortLineEdit, 4, 3, 1, 2);

        label_4 = new QLabel(BCSettingMatrixConfigDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 2, 2, 1);

        label_5 = new QLabel(BCSettingMatrixConfigDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 7, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        m_pOKBtn = new QPushButton(BCSettingMatrixConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingMatrixConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout_2, 9, 0, 1, 5);

        m_pInputSpinBox = new QSpinBox(BCSettingMatrixConfigDlg);
        m_pInputSpinBox->setObjectName(QStringLiteral("m_pInputSpinBox"));
        m_pInputSpinBox->setFont(font);

        gridLayout->addWidget(m_pInputSpinBox, 5, 3, 1, 2);

        m_pOutputSpinBox = new QSpinBox(BCSettingMatrixConfigDlg);
        m_pOutputSpinBox->setObjectName(QStringLiteral("m_pOutputSpinBox"));
        m_pOutputSpinBox->setFont(font);

        gridLayout->addWidget(m_pOutputSpinBox, 6, 3, 2, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pAddBtn = new QPushButton(BCSettingMatrixConfigDlg);
        m_pAddBtn->setObjectName(QStringLiteral("m_pAddBtn"));
        m_pAddBtn->setFont(font);

        horizontalLayout->addWidget(m_pAddBtn);

        m_pDelBtn = new QPushButton(BCSettingMatrixConfigDlg);
        m_pDelBtn->setObjectName(QStringLiteral("m_pDelBtn"));
        m_pDelBtn->setFont(font);

        horizontalLayout->addWidget(m_pDelBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 5);


        retranslateUi(BCSettingMatrixConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingMatrixConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingMatrixConfigDlg)
    {
        BCSettingMatrixConfigDlg->setWindowTitle(QApplication::translate("BCSettingMatrixConfigDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\345\220\215\345\255\227", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingMatrixConfigDlg", "IP", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\347\253\257\345\217\243", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\350\276\223\345\205\245\346\225\260\351\207\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\350\276\223\345\207\272\346\225\260\351\207\217", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        m_pAddBtn->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\346\267\273\345\212\240", Q_NULLPTR));
        m_pDelBtn->setText(QApplication::translate("BCSettingMatrixConfigDlg", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingMatrixConfigDlg: public Ui_BCSettingMatrixConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGMATRIXCONFIGDLG_H
