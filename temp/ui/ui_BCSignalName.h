/********************************************************************************
** Form generated from reading UI file 'BCSignalName.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSIGNALNAME_H
#define UI_BCSIGNALNAME_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSignalName
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *BCSignalName)
    {
        if (BCSignalName->objectName().isEmpty())
            BCSignalName->setObjectName(QStringLiteral("BCSignalName"));
        BCSignalName->resize(219, 70);
        gridLayout = new QGridLayout(BCSignalName);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(BCSignalName);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(BCSignalName);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(36, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(BCSignalName);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(BCSignalName);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);


        retranslateUi(BCSignalName);

        QMetaObject::connectSlotsByName(BCSignalName);
    } // setupUi

    void retranslateUi(QDialog *BCSignalName)
    {
        BCSignalName->setWindowTitle(QApplication::translate("BCSignalName", "\344\277\256\346\224\271\345\220\215\347\247\260", Q_NULLPTR));
        label->setText(QApplication::translate("BCSignalName", "\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BCSignalName", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BCSignalName", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSignalName: public Ui_BCSignalName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSIGNALNAME_H
