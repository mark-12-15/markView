/********************************************************************************
** Form generated from reading UI file 'BCMonitorWidgetData.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCMONITORWIDGETDATA_H
#define UI_BCMONITORWIDGETDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCMonitorWidgetData
{
public:
    QGridLayout *gridLayout;
    QLabel *label_view;
    QLabel *label;

    void setupUi(QWidget *BCMonitorWidgetData)
    {
        if (BCMonitorWidgetData->objectName().isEmpty())
            BCMonitorWidgetData->setObjectName(QStringLiteral("BCMonitorWidgetData"));
        BCMonitorWidgetData->resize(223, 118);
        BCMonitorWidgetData->setMinimumSize(QSize(0, 0));
        BCMonitorWidgetData->setAutoFillBackground(false);
        BCMonitorWidgetData->setStyleSheet(QStringLiteral("background-color: rgb(152, 152, 152);"));
        gridLayout = new QGridLayout(BCMonitorWidgetData);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_view = new QLabel(BCMonitorWidgetData);
        label_view->setObjectName(QStringLiteral("label_view"));

        gridLayout->addWidget(label_view, 0, 0, 1, 1);

        label = new QLabel(BCMonitorWidgetData);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color: rgb(242, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(BCMonitorWidgetData);

        QMetaObject::connectSlotsByName(BCMonitorWidgetData);
    } // setupUi

    void retranslateUi(QWidget *BCMonitorWidgetData)
    {
        BCMonitorWidgetData->setWindowTitle(QApplication::translate("BCMonitorWidgetData", "Form", Q_NULLPTR));
        label_view->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCMonitorWidgetData: public Ui_BCMonitorWidgetData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCMONITORWIDGETDATA_H
