/********************************************************************************
** Form generated from reading UI file 'BCSignalListWidgetData.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSIGNALLISTWIDGETDATA_H
#define UI_BCSIGNALLISTWIDGETDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSignalListWidgetData
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_view;
    QLabel *label;

    void setupUi(QWidget *BCSignalListWidgetData)
    {
        if (BCSignalListWidgetData->objectName().isEmpty())
            BCSignalListWidgetData->setObjectName(QStringLiteral("BCSignalListWidgetData"));
        BCSignalListWidgetData->resize(213, 165);
        BCSignalListWidgetData->setStyleSheet(QStringLiteral("background-color: rgb(152, 152, 152);"));
        verticalLayout = new QVBoxLayout(BCSignalListWidgetData);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_view = new QLabel(BCSignalListWidgetData);
        label_view->setObjectName(QStringLiteral("label_view"));

        verticalLayout->addWidget(label_view);

        label = new QLabel(BCSignalListWidgetData);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color: rgb(242, 255, 255);"));
        label->setMidLineWidth(0);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(BCSignalListWidgetData);

        QMetaObject::connectSlotsByName(BCSignalListWidgetData);
    } // setupUi

    void retranslateUi(QWidget *BCSignalListWidgetData)
    {
        label->setText(QApplication::translate("BCSignalListWidgetData", "\345\272\217\345\217\267", Q_NULLPTR));
        Q_UNUSED(BCSignalListWidgetData);
    } // retranslateUi

};

namespace Ui {
    class BCSignalListWidgetData: public Ui_BCSignalListWidgetData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSIGNALLISTWIDGETDATA_H
