/********************************************************************************
** Form generated from reading UI file 'BCSettingPerviewDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGPERVIEWDLG_H
#define UI_BCSETTINGPERVIEWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingPerviewDlg
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout;
    QLabel *userName;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *userNameEdit;
    QLabel *password;
    QLineEdit *passwordEdit;
    QComboBox *m_pUserPreviewComboBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addBut;
    QPushButton *removeBut;
    QPushButton *m_pModifyBtn;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *m_pFilterDeviceCheckBox;
    QLineEdit *m_pFilterDeviceLineEdit;
    QCheckBox *m_pFilterPreviewCheckBox;
    QLineEdit *m_pFilterPreviewLineEdit;
    QLabel *label_2;
    QTreeWidget *m_pGroupDisplayTreeWidget;
    QLabel *label_3;
    QTreeWidget *m_pMainToolBarTreeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_pModifyPerviewBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pResetDefaultMainToolBarBtn;

    void setupUi(QDialog *BCSettingPerviewDlg)
    {
        if (BCSettingPerviewDlg->objectName().isEmpty())
            BCSettingPerviewDlg->setObjectName(QStringLiteral("BCSettingPerviewDlg"));
        BCSettingPerviewDlg->resize(620, 421);
        horizontalLayout_2 = new QHBoxLayout(BCSettingPerviewDlg);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(BCSettingPerviewDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        userName = new QLabel(groupBox);
        userName->setObjectName(QStringLiteral("userName"));

        gridLayout->addWidget(userName, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        userNameEdit = new QLineEdit(groupBox);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));

        gridLayout->addWidget(userNameEdit, 0, 2, 1, 1);

        password = new QLabel(groupBox);
        password->setObjectName(QStringLiteral("password"));

        gridLayout->addWidget(password, 1, 0, 1, 1);

        passwordEdit = new QLineEdit(groupBox);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));

        gridLayout->addWidget(passwordEdit, 1, 2, 1, 1);

        m_pUserPreviewComboBox = new QComboBox(groupBox);
        m_pUserPreviewComboBox->setObjectName(QStringLiteral("m_pUserPreviewComboBox"));

        gridLayout->addWidget(m_pUserPreviewComboBox, 2, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        addBut = new QPushButton(groupBox);
        addBut->setObjectName(QStringLiteral("addBut"));

        horizontalLayout_3->addWidget(addBut);

        removeBut = new QPushButton(groupBox);
        removeBut->setObjectName(QStringLiteral("removeBut"));

        horizontalLayout_3->addWidget(removeBut);

        m_pModifyBtn = new QPushButton(groupBox);
        m_pModifyBtn->setObjectName(QStringLiteral("m_pModifyBtn"));

        horizontalLayout_3->addWidget(m_pModifyBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BCSettingPerviewDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        groupBox_2->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pFilterDeviceCheckBox = new QCheckBox(groupBox_2);
        m_pFilterDeviceCheckBox->setObjectName(QStringLiteral("m_pFilterDeviceCheckBox"));

        verticalLayout->addWidget(m_pFilterDeviceCheckBox);

        m_pFilterDeviceLineEdit = new QLineEdit(groupBox_2);
        m_pFilterDeviceLineEdit->setObjectName(QStringLiteral("m_pFilterDeviceLineEdit"));

        verticalLayout->addWidget(m_pFilterDeviceLineEdit);

        m_pFilterPreviewCheckBox = new QCheckBox(groupBox_2);
        m_pFilterPreviewCheckBox->setObjectName(QStringLiteral("m_pFilterPreviewCheckBox"));

        verticalLayout->addWidget(m_pFilterPreviewCheckBox);

        m_pFilterPreviewLineEdit = new QLineEdit(groupBox_2);
        m_pFilterPreviewLineEdit->setObjectName(QStringLiteral("m_pFilterPreviewLineEdit"));

        verticalLayout->addWidget(m_pFilterPreviewLineEdit);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        m_pGroupDisplayTreeWidget = new QTreeWidget(groupBox_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pGroupDisplayTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pGroupDisplayTreeWidget->setObjectName(QStringLiteral("m_pGroupDisplayTreeWidget"));

        verticalLayout->addWidget(m_pGroupDisplayTreeWidget);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        m_pMainToolBarTreeWidget = new QTreeWidget(groupBox_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        m_pMainToolBarTreeWidget->setHeaderItem(__qtreewidgetitem1);
        m_pMainToolBarTreeWidget->setObjectName(QStringLiteral("m_pMainToolBarTreeWidget"));

        verticalLayout->addWidget(m_pMainToolBarTreeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pModifyPerviewBtn = new QPushButton(groupBox_2);
        m_pModifyPerviewBtn->setObjectName(QStringLiteral("m_pModifyPerviewBtn"));

        horizontalLayout->addWidget(m_pModifyPerviewBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pResetDefaultMainToolBarBtn = new QPushButton(groupBox_2);
        m_pResetDefaultMainToolBarBtn->setObjectName(QStringLiteral("m_pResetDefaultMainToolBarBtn"));
        m_pResetDefaultMainToolBarBtn->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(m_pResetDefaultMainToolBarBtn);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBox_2);


        retranslateUi(BCSettingPerviewDlg);

        QMetaObject::connectSlotsByName(BCSettingPerviewDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingPerviewDlg)
    {
        BCSettingPerviewDlg->setWindowTitle(QApplication::translate("BCSettingPerviewDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingPerviewDlg", "\347\224\250\346\210\267\345\210\227\350\241\250", Q_NULLPTR));
        userName->setText(QApplication::translate("BCSettingPerviewDlg", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        password->setText(QApplication::translate("BCSettingPerviewDlg", "\345\257\206   \347\240\201", Q_NULLPTR));
        m_pUserPreviewComboBox->clear();
        m_pUserPreviewComboBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingPerviewDlg", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR)
         << QApplication::translate("BCSettingPerviewDlg", "\346\223\215\344\275\234\345\221\230", Q_NULLPTR)
         << QApplication::translate("BCSettingPerviewDlg", "\347\224\250\346\210\267", Q_NULLPTR)
        );
        label->setText(QApplication::translate("BCSettingPerviewDlg", "\346\235\203   \351\231\220", Q_NULLPTR));
        addBut->setText(QApplication::translate("BCSettingPerviewDlg", "\346\267\273\345\212\240\347\224\250\346\210\267", Q_NULLPTR));
        removeBut->setText(QApplication::translate("BCSettingPerviewDlg", "\345\210\240\351\231\244\347\224\250\346\210\267", Q_NULLPTR));
        m_pModifyBtn->setText(QApplication::translate("BCSettingPerviewDlg", "\344\277\256\346\224\271\347\224\250\346\210\267", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCSettingPerviewDlg", "\346\235\203\351\231\220\347\256\241\347\220\206", Q_NULLPTR));
        m_pFilterDeviceCheckBox->setText(QApplication::translate("BCSettingPerviewDlg", "\350\277\207\346\273\244\350\256\276\345\244\207\345\210\227\350\241\250", Q_NULLPTR));
        m_pFilterPreviewCheckBox->setText(QApplication::translate("BCSettingPerviewDlg", "\350\277\207\346\273\244\351\242\204\347\233\221\345\233\236\346\230\276\345\210\227\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingPerviewDlg", "\345\217\257\346\216\247\345\261\217\347\273\204\346\235\203\351\231\220", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingPerviewDlg", "\344\270\273\345\267\245\345\205\267\346\235\241\345\212\237\350\203\275\346\235\203\351\231\220", Q_NULLPTR));
        m_pModifyPerviewBtn->setText(QApplication::translate("BCSettingPerviewDlg", "\344\277\256\346\224\271", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        m_pResetDefaultMainToolBarBtn->setToolTip(QApplication::translate("BCSettingPerviewDlg", "\344\273\216\345\244\226\351\203\250\345\212\240\350\275\275\347\256\241\347\220\206\345\221\230\346\235\203\351\231\220\357\274\214\351\207\215\346\226\260\345\220\257\345\212\250\350\275\257\344\273\266\347\224\237\346\225\210", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        m_pResetDefaultMainToolBarBtn->setText(QApplication::translate("BCSettingPerviewDlg", "\345\210\235\345\247\213\345\214\226\346\235\203\351\231\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingPerviewDlg: public Ui_BCSettingPerviewDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGPERVIEWDLG_H
