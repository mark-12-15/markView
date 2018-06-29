/********************************************************************************
** Form generated from reading UI file 'BCMatrix.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCMATRIX_H
#define UI_BCMATRIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCMatrix
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *m_pTabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *BCMatrix)
    {
        if (BCMatrix->objectName().isEmpty())
            BCMatrix->setObjectName(QStringLiteral("BCMatrix"));
        BCMatrix->resize(350, 293);
        BCMatrix->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(BCMatrix);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frame = new QFrame(BCMatrix);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_pTabWidget = new QTabWidget(frame);
        m_pTabWidget->setObjectName(QStringLiteral("m_pTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        m_pTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        m_pTabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(m_pTabWidget);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BCMatrix);

        m_pTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BCMatrix);
    } // setupUi

    void retranslateUi(QWidget *BCMatrix)
    {
        BCMatrix->setWindowTitle(QApplication::translate("BCMatrix", "Form", Q_NULLPTR));
        m_pTabWidget->setTabText(m_pTabWidget->indexOf(tab), QApplication::translate("BCMatrix", "Tab 1", Q_NULLPTR));
        m_pTabWidget->setTabText(m_pTabWidget->indexOf(tab_2), QApplication::translate("BCMatrix", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCMatrix: public Ui_BCMatrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCMATRIX_H
