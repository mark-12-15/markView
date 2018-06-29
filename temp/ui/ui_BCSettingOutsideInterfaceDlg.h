/********************************************************************************
** Form generated from reading UI file 'BCSettingOutsideInterfaceDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGOUTSIDEINTERFACEDLG_H
#define UI_BCSETTINGOUTSIDEINTERFACEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingOutsideInterfaceDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_16;
    QComboBox *m_pComComBox1;
    QLabel *label_17;
    QComboBox *m_pBaudRateComBox1;
    QLabel *label_14;
    QComboBox *m_pDataBitComBox1;
    QLabel *label_18;
    QComboBox *m_pStopBitComBox1;
    QLabel *label_15;
    QComboBox *m_pCheckBitComBox1;
    QLabel *label_13;
    QComboBox *m_pStreamCtrlComBox1;
    QLabel *m_pStatusLabel1;
    QPushButton *m_pConnectBtn1;

    void setupUi(QDialog *BCSettingOutsideInterfaceDlg)
    {
        if (BCSettingOutsideInterfaceDlg->objectName().isEmpty())
            BCSettingOutsideInterfaceDlg->setObjectName(QStringLiteral("BCSettingOutsideInterfaceDlg"));
        BCSettingOutsideInterfaceDlg->resize(305, 202);
        verticalLayout = new QVBoxLayout(BCSettingOutsideInterfaceDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BCSettingOutsideInterfaceDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        m_pComComBox1 = new QComboBox(groupBox);
        m_pComComBox1->setObjectName(QStringLiteral("m_pComComBox1"));
        m_pComComBox1->setMinimumSize(QSize(0, 0));
        m_pComComBox1->setFont(font);
        m_pComComBox1->setEditable(true);

        gridLayout->addWidget(m_pComComBox1, 0, 1, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        gridLayout->addWidget(label_17, 0, 2, 1, 1);

        m_pBaudRateComBox1 = new QComboBox(groupBox);
        m_pBaudRateComBox1->setObjectName(QStringLiteral("m_pBaudRateComBox1"));
        m_pBaudRateComBox1->setMinimumSize(QSize(0, 0));
        m_pBaudRateComBox1->setFont(font);
        m_pBaudRateComBox1->setEditable(true);

        gridLayout->addWidget(m_pBaudRateComBox1, 0, 3, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        m_pDataBitComBox1 = new QComboBox(groupBox);
        m_pDataBitComBox1->setObjectName(QStringLiteral("m_pDataBitComBox1"));
        m_pDataBitComBox1->setMinimumSize(QSize(0, 0));
        m_pDataBitComBox1->setFont(font);
        m_pDataBitComBox1->setEditable(true);

        gridLayout->addWidget(m_pDataBitComBox1, 1, 1, 1, 1);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        gridLayout->addWidget(label_18, 1, 2, 1, 1);

        m_pStopBitComBox1 = new QComboBox(groupBox);
        m_pStopBitComBox1->setObjectName(QStringLiteral("m_pStopBitComBox1"));
        m_pStopBitComBox1->setMinimumSize(QSize(0, 0));
        m_pStopBitComBox1->setFont(font);
        m_pStopBitComBox1->setEditable(true);

        gridLayout->addWidget(m_pStopBitComBox1, 1, 3, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 2, 0, 1, 1);

        m_pCheckBitComBox1 = new QComboBox(groupBox);
        m_pCheckBitComBox1->setObjectName(QStringLiteral("m_pCheckBitComBox1"));
        m_pCheckBitComBox1->setMinimumSize(QSize(0, 0));
        m_pCheckBitComBox1->setFont(font);
        m_pCheckBitComBox1->setEditable(true);

        gridLayout->addWidget(m_pCheckBitComBox1, 2, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 2, 2, 1, 1);

        m_pStreamCtrlComBox1 = new QComboBox(groupBox);
        m_pStreamCtrlComBox1->setObjectName(QStringLiteral("m_pStreamCtrlComBox1"));
        m_pStreamCtrlComBox1->setMinimumSize(QSize(0, 0));
        m_pStreamCtrlComBox1->setFont(font);
        m_pStreamCtrlComBox1->setEditable(true);

        gridLayout->addWidget(m_pStreamCtrlComBox1, 2, 3, 1, 1);

        m_pStatusLabel1 = new QLabel(groupBox);
        m_pStatusLabel1->setObjectName(QStringLiteral("m_pStatusLabel1"));

        gridLayout->addWidget(m_pStatusLabel1, 3, 0, 1, 3);

        m_pConnectBtn1 = new QPushButton(groupBox);
        m_pConnectBtn1->setObjectName(QStringLiteral("m_pConnectBtn1"));

        gridLayout->addWidget(m_pConnectBtn1, 3, 3, 1, 1);


        verticalLayout->addWidget(groupBox);


        retranslateUi(BCSettingOutsideInterfaceDlg);

        QMetaObject::connectSlotsByName(BCSettingOutsideInterfaceDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingOutsideInterfaceDlg)
    {
        BCSettingOutsideInterfaceDlg->setWindowTitle(QApplication::translate("BCSettingOutsideInterfaceDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingOutsideInterfaceDlg", "\346\216\245\346\224\266\347\253\257\351\205\215\347\275\256", Q_NULLPTR));
        label_16->setText(QApplication::translate("BCSettingOutsideInterfaceDlg", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        label_17->setText(QApplication::translate("BCSettingOutsideInterfaceDlg", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        m_pBaudRateComBox1->clear();
        m_pBaudRateComBox1->insertItems(0, QStringList()
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "1200", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "2400", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "4800", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "9600", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "14400", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "19200", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "38400", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "56000", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "57600", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "115200", Q_NULLPTR)
        );
        label_14->setText(QApplication::translate("BCSettingOutsideInterfaceDlg", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        m_pDataBitComBox1->clear();
        m_pDataBitComBox1->insertItems(0, QStringList()
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "5", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "6", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "7", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "8", Q_NULLPTR)
        );
        label_18->setText(QApplication::translate("BCSettingOutsideInterfaceDlg", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        m_pStopBitComBox1->clear();
        m_pStopBitComBox1->insertItems(0, QStringList()
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "1", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "2", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "3", Q_NULLPTR)
        );
        label_15->setText(QApplication::translate("BCSettingOutsideInterfaceDlg", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        m_pCheckBitComBox1->clear();
        m_pCheckBitComBox1->insertItems(0, QStringList()
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "Odd", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "Even", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "Mark", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "Space", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("BCSettingOutsideInterfaceDlg", "\346\265\201\346\216\247\345\210\266", Q_NULLPTR));
        m_pStreamCtrlComBox1->clear();
        m_pStreamCtrlComBox1->insertItems(0, QStringList()
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "Hardware", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "Software", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "None", Q_NULLPTR)
         << QApplication::translate("BCSettingOutsideInterfaceDlg", "Custom", Q_NULLPTR)
        );
        m_pStatusLabel1->setText(QString());
        m_pConnectBtn1->setText(QApplication::translate("BCSettingOutsideInterfaceDlg", "\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingOutsideInterfaceDlg: public Ui_BCSettingOutsideInterfaceDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGOUTSIDEINTERFACEDLG_H
