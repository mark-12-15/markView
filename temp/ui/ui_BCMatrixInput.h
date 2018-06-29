/********************************************************************************
** Form generated from reading UI file 'BCMatrixInput.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCMATRIXINPUT_H
#define UI_BCMATRIXINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCMatrixInput
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QCheckBox *checkBox;
    QListWidget *listWidget;

    void setupUi(QWidget *BCMatrixInput)
    {
        if (BCMatrixInput->objectName().isEmpty())
            BCMatrixInput->setObjectName(QStringLiteral("BCMatrixInput"));
        BCMatrixInput->resize(400, 300);
        gridLayout = new QGridLayout(BCMatrixInput);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frame = new QFrame(BCMatrixInput);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(6);
        gridLayout_2->setContentsMargins(0, 6, 0, 0);
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 1);

        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout_2->addWidget(toolButton, 0, 1, 1, 1);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_2->addWidget(checkBox, 1, 0, 1, 1);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_2->addWidget(listWidget, 2, 0, 1, 2);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BCMatrixInput);

        QMetaObject::connectSlotsByName(BCMatrixInput);
    } // setupUi

    void retranslateUi(QWidget *BCMatrixInput)
    {
        BCMatrixInput->setWindowTitle(QApplication::translate("BCMatrixInput", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("BCMatrixInput", "...", Q_NULLPTR));
        checkBox->setText(QApplication::translate("BCMatrixInput", "\351\237\263\350\247\206\351\242\221\345\220\214\346\255\245\345\210\207\346\215\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCMatrixInput: public Ui_BCMatrixInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCMATRIXINPUT_H
