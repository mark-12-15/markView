/********************************************************************************
** Form generated from reading UI file 'BCSettingSignalWindowPropertyDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGSIGNALWINDOWPROPERTYDLG_H
#define UI_BCSETTINGSIGNALWINDOWPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSettingSignalWindowPropertyDlg
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *m_pTitleLineEdit;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *m_pPoxXLineEdit;
    QLabel *label_3;
    QLineEdit *m_pPoxYLineEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *m_pWidthLineEdit;
    QLabel *label_5;
    QLineEdit *m_pHeightLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOkBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingSignalWindowPropertyDlg)
    {
        if (BCSettingSignalWindowPropertyDlg->objectName().isEmpty())
            BCSettingSignalWindowPropertyDlg->setObjectName(QStringLiteral("BCSettingSignalWindowPropertyDlg"));
        BCSettingSignalWindowPropertyDlg->resize(247, 241);
        gridLayout = new QGridLayout(BCSettingSignalWindowPropertyDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(BCSettingSignalWindowPropertyDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        m_pTitleLineEdit = new QLineEdit(groupBox);
        m_pTitleLineEdit->setObjectName(QStringLiteral("m_pTitleLineEdit"));

        horizontalLayout_3->addWidget(m_pTitleLineEdit);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(BCSettingSignalWindowPropertyDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        m_pPoxXLineEdit = new QLineEdit(groupBox_2);
        m_pPoxXLineEdit->setObjectName(QStringLiteral("m_pPoxXLineEdit"));

        horizontalLayout_2->addWidget(m_pPoxXLineEdit);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        m_pPoxYLineEdit = new QLineEdit(groupBox_2);
        m_pPoxYLineEdit->setObjectName(QStringLiteral("m_pPoxYLineEdit"));

        horizontalLayout_2->addWidget(m_pPoxYLineEdit);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 3);

        groupBox_3 = new QGroupBox(BCSettingSignalWindowPropertyDlg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        m_pWidthLineEdit = new QLineEdit(groupBox_3);
        m_pWidthLineEdit->setObjectName(QStringLiteral("m_pWidthLineEdit"));

        horizontalLayout->addWidget(m_pWidthLineEdit);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        m_pHeightLineEdit = new QLineEdit(groupBox_3);
        m_pHeightLineEdit->setObjectName(QStringLiteral("m_pHeightLineEdit"));

        horizontalLayout->addWidget(m_pHeightLineEdit);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        m_pOkBtn = new QPushButton(BCSettingSignalWindowPropertyDlg);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        m_pOkBtn->setFont(font);

        gridLayout->addWidget(m_pOkBtn, 3, 1, 1, 1);

        m_pCancelBtn = new QPushButton(BCSettingSignalWindowPropertyDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        gridLayout->addWidget(m_pCancelBtn, 3, 2, 1, 1);


        retranslateUi(BCSettingSignalWindowPropertyDlg);

        QMetaObject::connectSlotsByName(BCSettingSignalWindowPropertyDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingSignalWindowPropertyDlg)
    {
        BCSettingSignalWindowPropertyDlg->setWindowTitle(QApplication::translate("BCSettingSignalWindowPropertyDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingSignalWindowPropertyDlg", "\347\252\227\345\217\243\346\240\207\351\242\230", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingSignalWindowPropertyDlg", "\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCSettingSignalWindowPropertyDlg", "\347\252\227\345\217\243\345\235\220\346\240\207", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingSignalWindowPropertyDlg", "X", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingSignalWindowPropertyDlg", "Y", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("BCSettingSignalWindowPropertyDlg", "\347\252\227\345\217\243\345\260\272\345\257\270", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingSignalWindowPropertyDlg", "W", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingSignalWindowPropertyDlg", "H", Q_NULLPTR));
        m_pOkBtn->setText(QApplication::translate("BCSettingSignalWindowPropertyDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingSignalWindowPropertyDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingSignalWindowPropertyDlg: public Ui_BCSettingSignalWindowPropertyDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGSIGNALWINDOWPROPERTYDLG_H
