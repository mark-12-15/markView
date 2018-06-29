/********************************************************************************
** Form generated from reading UI file 'BCScreenDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSCREENDLG_H
#define UI_BCSCREENDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BCScreenDlg
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_poll;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cannel;

    void setupUi(QDialog *BCScreenDlg)
    {
        if (BCScreenDlg->objectName().isEmpty())
            BCScreenDlg->setObjectName(QStringLiteral("BCScreenDlg"));
        BCScreenDlg->resize(437, 167);
        gridLayout_3 = new QGridLayout(BCScreenDlg);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(BCScreenDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_poll = new QCheckBox(groupBox);
        checkBox_poll->setObjectName(QStringLiteral("checkBox_poll"));
        sizePolicy.setHeightForWidth(checkBox_poll->sizePolicy().hasHeightForWidth());
        checkBox_poll->setSizePolicy(sizePolicy);
        checkBox_poll->setFont(font);

        gridLayout->addWidget(checkBox_poll, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setFont(font);
        spinBox->setMaximum(65535);

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BCScreenDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(BCScreenDlg);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setFont(font);

        horizontalLayout->addWidget(pushButton_ok);

        pushButton_cannel = new QPushButton(BCScreenDlg);
        pushButton_cannel->setObjectName(QStringLiteral("pushButton_cannel"));
        pushButton_cannel->setFont(font);

        horizontalLayout->addWidget(pushButton_cannel);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 2);


        retranslateUi(BCScreenDlg);

        QMetaObject::connectSlotsByName(BCScreenDlg);
    } // setupUi

    void retranslateUi(QDialog *BCScreenDlg)
    {
        BCScreenDlg->setWindowTitle(QApplication::translate("BCScreenDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCScreenDlg", "\345\234\272\346\231\257\350\256\276\347\275\256", Q_NULLPTR));
        checkBox->setText(QApplication::translate("BCScreenDlg", "\346\240\207\351\242\230\351\232\217\345\212\250\347\274\226\345\217\267", Q_NULLPTR));
        checkBox_poll->setText(QApplication::translate("BCScreenDlg", "\345\234\272\346\231\257\350\275\256\345\267\241", Q_NULLPTR));
        label->setText(QApplication::translate("BCScreenDlg", "\345\234\272\346\231\257\347\274\226\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCScreenDlg", "\345\234\272\346\231\257\345\220\215\347\247\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCScreenDlg", "\345\234\272\346\231\257\350\257\264\346\230\216", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("BCScreenDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_cannel->setText(QApplication::translate("BCScreenDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCScreenDlg: public Ui_BCScreenDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSCREENDLG_H
