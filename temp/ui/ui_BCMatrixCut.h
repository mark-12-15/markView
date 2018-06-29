/********************************************************************************
** Form generated from reading UI file 'BCMatrixCut.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCMATRIXCUT_H
#define UI_BCMATRIXCUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCMatrixCut
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton;
    QSpinBox *spinBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QComboBox *comboBox;

    void setupUi(QWidget *BCMatrixCut)
    {
        if (BCMatrixCut->objectName().isEmpty())
            BCMatrixCut->setObjectName(QStringLiteral("BCMatrixCut"));
        BCMatrixCut->resize(330, 182);
        gridLayout = new QGridLayout(BCMatrixCut);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frame = new QFrame(BCMatrixCut);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 6, -1, -1);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(toolButton, 1, 1, 1, 1);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(256);

        gridLayout_2->addWidget(spinBox, 2, 0, 1, 1);

        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 2, 1, 1, 1);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_2->addWidget(checkBox, 3, 0, 1, 1);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BCMatrixCut);

        QMetaObject::connectSlotsByName(BCMatrixCut);
    } // setupUi

    void retranslateUi(QWidget *BCMatrixCut)
    {
        BCMatrixCut->setWindowTitle(QApplication::translate("BCMatrixCut", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("BCMatrixCut", "...", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BCMatrixCut", "\345\210\207\346\215\242\350\207\263\350\276\223\345\207\272", Q_NULLPTR));
        checkBox->setText(QApplication::translate("BCMatrixCut", "\351\237\263\350\247\206\351\242\221\345\220\214\346\255\245\345\210\207\346\215\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCMatrixCut: public Ui_BCMatrixCut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCMATRIXCUT_H
