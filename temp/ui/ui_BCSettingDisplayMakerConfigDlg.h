/********************************************************************************
** Form generated from reading UI file 'BCSettingDisplayMakerConfigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDISPLAYMAKERCONFIGDLG_H
#define UI_BCSETTINGDISPLAYMAKERCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDisplayMakerConfigDlg
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *m_pListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_pAddBtn;
    QPushButton *m_pDelBtn;
    QPushButton *m_pModifyBtn;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QComboBox *m_pCmdTypeComboBox;
    QLabel *label_2;
    QLineEdit *m_pOnCmdLineEdit;
    QLabel *label_3;
    QLineEdit *m_pOffCmdLineEdit;
    QLabel *label_4;
    QLineEdit *m_pMakerLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingDisplayMakerConfigDlg)
    {
        if (BCSettingDisplayMakerConfigDlg->objectName().isEmpty())
            BCSettingDisplayMakerConfigDlg->setObjectName(QStringLiteral("BCSettingDisplayMakerConfigDlg"));
        BCSettingDisplayMakerConfigDlg->resize(342, 304);
        verticalLayout = new QVBoxLayout(BCSettingDisplayMakerConfigDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pListWidget = new QListWidget(BCSettingDisplayMakerConfigDlg);
        m_pListWidget->setObjectName(QStringLiteral("m_pListWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pListWidget->setFont(font);

        verticalLayout->addWidget(m_pListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pAddBtn = new QPushButton(BCSettingDisplayMakerConfigDlg);
        m_pAddBtn->setObjectName(QStringLiteral("m_pAddBtn"));
        m_pAddBtn->setFont(font);

        horizontalLayout->addWidget(m_pAddBtn);

        m_pDelBtn = new QPushButton(BCSettingDisplayMakerConfigDlg);
        m_pDelBtn->setObjectName(QStringLiteral("m_pDelBtn"));
        m_pDelBtn->setFont(font);

        horizontalLayout->addWidget(m_pDelBtn);

        m_pModifyBtn = new QPushButton(BCSettingDisplayMakerConfigDlg);
        m_pModifyBtn->setObjectName(QStringLiteral("m_pModifyBtn"));
        m_pModifyBtn->setFont(font);

        horizontalLayout->addWidget(m_pModifyBtn);

        horizontalSpacer = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(113, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        label = new QLabel(BCSettingDisplayMakerConfigDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        m_pCmdTypeComboBox = new QComboBox(BCSettingDisplayMakerConfigDlg);
        m_pCmdTypeComboBox->setObjectName(QStringLiteral("m_pCmdTypeComboBox"));
        m_pCmdTypeComboBox->setFont(font);

        gridLayout->addWidget(m_pCmdTypeComboBox, 1, 2, 1, 1);

        label_2 = new QLabel(BCSettingDisplayMakerConfigDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        m_pOnCmdLineEdit = new QLineEdit(BCSettingDisplayMakerConfigDlg);
        m_pOnCmdLineEdit->setObjectName(QStringLiteral("m_pOnCmdLineEdit"));
        m_pOnCmdLineEdit->setFont(font);

        gridLayout->addWidget(m_pOnCmdLineEdit, 2, 1, 1, 2);

        label_3 = new QLabel(BCSettingDisplayMakerConfigDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        m_pOffCmdLineEdit = new QLineEdit(BCSettingDisplayMakerConfigDlg);
        m_pOffCmdLineEdit->setObjectName(QStringLiteral("m_pOffCmdLineEdit"));
        m_pOffCmdLineEdit->setFont(font);

        gridLayout->addWidget(m_pOffCmdLineEdit, 3, 1, 1, 2);

        label_4 = new QLabel(BCSettingDisplayMakerConfigDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        m_pMakerLineEdit = new QLineEdit(BCSettingDisplayMakerConfigDlg);
        m_pMakerLineEdit->setObjectName(QStringLiteral("m_pMakerLineEdit"));
        m_pMakerLineEdit->setFont(font);

        gridLayout->addWidget(m_pMakerLineEdit, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(129, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        m_pOKBtn = new QPushButton(BCSettingDisplayMakerConfigDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingDisplayMakerConfigDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(m_pListWidget, m_pAddBtn);
        QWidget::setTabOrder(m_pAddBtn, m_pDelBtn);
        QWidget::setTabOrder(m_pDelBtn, m_pModifyBtn);
        QWidget::setTabOrder(m_pModifyBtn, m_pMakerLineEdit);
        QWidget::setTabOrder(m_pMakerLineEdit, m_pCmdTypeComboBox);
        QWidget::setTabOrder(m_pCmdTypeComboBox, m_pOnCmdLineEdit);
        QWidget::setTabOrder(m_pOnCmdLineEdit, m_pOffCmdLineEdit);
        QWidget::setTabOrder(m_pOffCmdLineEdit, m_pOKBtn);
        QWidget::setTabOrder(m_pOKBtn, m_pCancelBtn);

        retranslateUi(BCSettingDisplayMakerConfigDlg);

        QMetaObject::connectSlotsByName(BCSettingDisplayMakerConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingDisplayMakerConfigDlg)
    {
        BCSettingDisplayMakerConfigDlg->setWindowTitle(QApplication::translate("BCSettingDisplayMakerConfigDlg", "Dialog", Q_NULLPTR));
        m_pAddBtn->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\346\267\273\345\212\240", Q_NULLPTR));
        m_pDelBtn->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\345\210\240\351\231\244", Q_NULLPTR));
        m_pModifyBtn->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\344\277\256\346\224\271", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\346\214\207\344\273\244\347\261\273\345\236\213", Q_NULLPTR));
        m_pCmdTypeComboBox->clear();
        m_pCmdTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDisplayMakerConfigDlg", "16\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("BCSettingDisplayMakerConfigDlg", "Ascll\347\240\201", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\346\211\223\345\274\200\346\214\207\344\273\244", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\345\205\263\351\227\255\346\214\207\344\273\244", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\345\216\202\345\256\266", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingDisplayMakerConfigDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDisplayMakerConfigDlg: public Ui_BCSettingDisplayMakerConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDISPLAYMAKERCONFIGDLG_H
