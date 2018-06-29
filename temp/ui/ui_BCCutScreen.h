/********************************************************************************
** Form generated from reading UI file 'BCCutScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCCUTSCREEN_H
#define UI_BCCUTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCCutScreen
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QListView *listView;

    void setupUi(QWidget *BCCutScreen)
    {
        if (BCCutScreen->objectName().isEmpty())
            BCCutScreen->setObjectName(QStringLiteral("BCCutScreen"));
        BCCutScreen->resize(400, 300);
        gridLayout = new QGridLayout(BCCutScreen);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frame = new QFrame(BCCutScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        listView = new QListView(frame);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_2->addWidget(listView, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BCCutScreen);

        QMetaObject::connectSlotsByName(BCCutScreen);
    } // setupUi

    void retranslateUi(QWidget *BCCutScreen)
    {
        BCCutScreen->setWindowTitle(QApplication::translate("BCCutScreen", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCCutScreen: public Ui_BCCutScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCCUTSCREEN_H
