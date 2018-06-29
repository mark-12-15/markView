/********************************************************************************
** Form generated from reading UI file 'BCPlanMapDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCPLANMAPDLG_H
#define UI_BCPLANMAPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCPlanMapGraphicsView.h"
#include "BCPlanMapTreeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCPlanMapDlg
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *pBtnZoomOut;
    QToolButton *pBtnZoomIn;
    QToolButton *pBtnZoomFitBest;
    QToolButton *pBtnZoomOriginal;
    QSpacerItem *horizontalSpacer;
    BCPlanMapGraphicsView *pMapView;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    BCPlanMapTreeWidget *pPlanTreeWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *pButtonTableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pSelectMap;
    QPushButton *pClearMap;
    QPushButton *pDeleteButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pOk;
    QPushButton *pCancel;

    void setupUi(QDialog *BCPlanMapDlg)
    {
        if (BCPlanMapDlg->objectName().isEmpty())
            BCPlanMapDlg->setObjectName(QStringLiteral("BCPlanMapDlg"));
        BCPlanMapDlg->resize(926, 610);
        horizontalLayout_6 = new QHBoxLayout(BCPlanMapDlg);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pBtnZoomOut = new QToolButton(BCPlanMapDlg);
        pBtnZoomOut->setObjectName(QStringLiteral("pBtnZoomOut"));
        pBtnZoomOut->setMinimumSize(QSize(28, 28));
        pBtnZoomOut->setMaximumSize(QSize(28, 28));
        pBtnZoomOut->setAutoRaise(true);

        horizontalLayout->addWidget(pBtnZoomOut);

        pBtnZoomIn = new QToolButton(BCPlanMapDlg);
        pBtnZoomIn->setObjectName(QStringLiteral("pBtnZoomIn"));
        pBtnZoomIn->setMinimumSize(QSize(28, 28));
        pBtnZoomIn->setMaximumSize(QSize(28, 28));
        pBtnZoomIn->setAutoRaise(true);

        horizontalLayout->addWidget(pBtnZoomIn);

        pBtnZoomFitBest = new QToolButton(BCPlanMapDlg);
        pBtnZoomFitBest->setObjectName(QStringLiteral("pBtnZoomFitBest"));
        pBtnZoomFitBest->setMinimumSize(QSize(28, 28));
        pBtnZoomFitBest->setMaximumSize(QSize(28, 28));
        pBtnZoomFitBest->setAutoRaise(true);

        horizontalLayout->addWidget(pBtnZoomFitBest);

        pBtnZoomOriginal = new QToolButton(BCPlanMapDlg);
        pBtnZoomOriginal->setObjectName(QStringLiteral("pBtnZoomOriginal"));
        pBtnZoomOriginal->setMinimumSize(QSize(28, 28));
        pBtnZoomOriginal->setMaximumSize(QSize(28, 28));
        pBtnZoomOriginal->setAutoRaise(true);

        horizontalLayout->addWidget(pBtnZoomOriginal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        pMapView = new BCPlanMapGraphicsView(BCPlanMapDlg);
        pMapView->setObjectName(QStringLiteral("pMapView"));

        verticalLayout->addWidget(pMapView);


        horizontalLayout_6->addLayout(verticalLayout);

        widget = new QWidget(BCPlanMapDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pPlanTreeWidget = new BCPlanMapTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        pPlanTreeWidget->setHeaderItem(__qtreewidgetitem);
        pPlanTreeWidget->setObjectName(QStringLiteral("pPlanTreeWidget"));

        horizontalLayout_4->addWidget(pPlanTreeWidget);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pButtonTableWidget = new QTableWidget(groupBox_2);
        pButtonTableWidget->setObjectName(QStringLiteral("pButtonTableWidget"));

        verticalLayout_3->addWidget(pButtonTableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pSelectMap = new QPushButton(groupBox_2);
        pSelectMap->setObjectName(QStringLiteral("pSelectMap"));

        horizontalLayout_2->addWidget(pSelectMap);

        pClearMap = new QPushButton(groupBox_2);
        pClearMap->setObjectName(QStringLiteral("pClearMap"));

        horizontalLayout_2->addWidget(pClearMap);

        pDeleteButton = new QPushButton(groupBox_2);
        pDeleteButton->setObjectName(QStringLiteral("pDeleteButton"));

        horizontalLayout_2->addWidget(pDeleteButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pOk = new QPushButton(widget);
        pOk->setObjectName(QStringLiteral("pOk"));

        horizontalLayout_3->addWidget(pOk);

        pCancel = new QPushButton(widget);
        pCancel->setObjectName(QStringLiteral("pCancel"));

        horizontalLayout_3->addWidget(pCancel);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_6->addWidget(widget);


        retranslateUi(BCPlanMapDlg);

        QMetaObject::connectSlotsByName(BCPlanMapDlg);
    } // setupUi

    void retranslateUi(QDialog *BCPlanMapDlg)
    {
        BCPlanMapDlg->setWindowTitle(QApplication::translate("BCPlanMapDlg", "\347\224\265\345\255\220\345\234\260\345\233\276", Q_NULLPTR));
        pBtnZoomOut->setText(QString());
        pBtnZoomIn->setText(QString());
        pBtnZoomFitBest->setText(QString());
        pBtnZoomOriginal->setText(QString());
        groupBox->setTitle(QApplication::translate("BCPlanMapDlg", "\347\263\273\347\273\237\351\242\204\346\241\210\345\210\227\350\241\250", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCPlanMapDlg", "\345\234\260\345\233\276\346\214\211\351\222\256\345\210\227\350\241\250", Q_NULLPTR));
        pSelectMap->setText(QApplication::translate("BCPlanMapDlg", "\351\200\211\346\213\251\345\234\260\345\233\276", Q_NULLPTR));
        pClearMap->setText(QApplication::translate("BCPlanMapDlg", "\346\270\205\347\251\272\345\234\260\345\233\276", Q_NULLPTR));
        pDeleteButton->setText(QApplication::translate("BCPlanMapDlg", "\345\210\240\351\231\244\346\214\211\351\222\256", Q_NULLPTR));
        pOk->setText(QApplication::translate("BCPlanMapDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        pCancel->setText(QApplication::translate("BCPlanMapDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCPlanMapDlg: public Ui_BCPlanMapDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCPLANMAPDLG_H
