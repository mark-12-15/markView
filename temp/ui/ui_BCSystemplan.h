/********************************************************************************
** Form generated from reading UI file 'BCSystemplan.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSYSTEMPLAN_H
#define UI_BCSYSTEMPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSystemplan
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QTreeWidget *m_pTreeWidget;

    void setupUi(QWidget *BCSystemplan)
    {
        if (BCSystemplan->objectName().isEmpty())
            BCSystemplan->setObjectName(QStringLiteral("BCSystemplan"));
        BCSystemplan->resize(400, 300);
        gridLayout = new QGridLayout(BCSystemplan);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frame = new QFrame(BCSystemplan);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        m_pTreeWidget = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pTreeWidget->setObjectName(QStringLiteral("m_pTreeWidget"));

        gridLayout_2->addWidget(m_pTreeWidget, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BCSystemplan);

        QMetaObject::connectSlotsByName(BCSystemplan);
    } // setupUi

    void retranslateUi(QWidget *BCSystemplan)
    {
        BCSystemplan->setWindowTitle(QApplication::translate("BCSystemplan", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSystemplan: public Ui_BCSystemplan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSYSTEMPLAN_H
