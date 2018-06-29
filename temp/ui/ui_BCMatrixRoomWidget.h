/********************************************************************************
** Form generated from reading UI file 'BCMatrixRoomWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCMATRIXROOMWIDGET_H
#define UI_BCMATRIXROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCMatrixRoomWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *m_pInputScrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *m_pOutputScrollArea;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *BCMatrixRoomWidget)
    {
        if (BCMatrixRoomWidget->objectName().isEmpty())
            BCMatrixRoomWidget->setObjectName(QStringLiteral("BCMatrixRoomWidget"));
        BCMatrixRoomWidget->resize(956, 637);
        horizontalLayout = new QHBoxLayout(BCMatrixRoomWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pInputScrollArea = new QScrollArea(BCMatrixRoomWidget);
        m_pInputScrollArea->setObjectName(QStringLiteral("m_pInputScrollArea"));
        m_pInputScrollArea->setStyleSheet(QStringLiteral("background-color: transparent;"));
        m_pInputScrollArea->setFrameShape(QFrame::NoFrame);
        m_pInputScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 466, 619));
        m_pInputScrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(m_pInputScrollArea);

        m_pOutputScrollArea = new QScrollArea(BCMatrixRoomWidget);
        m_pOutputScrollArea->setObjectName(QStringLiteral("m_pOutputScrollArea"));
        m_pOutputScrollArea->setStyleSheet(QStringLiteral("background-color: transparent;"));
        m_pOutputScrollArea->setFrameShape(QFrame::NoFrame);
        m_pOutputScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 466, 619));
        m_pOutputScrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(m_pOutputScrollArea);


        retranslateUi(BCMatrixRoomWidget);

        QMetaObject::connectSlotsByName(BCMatrixRoomWidget);
    } // setupUi

    void retranslateUi(QWidget *BCMatrixRoomWidget)
    {
        BCMatrixRoomWidget->setWindowTitle(QApplication::translate("BCMatrixRoomWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCMatrixRoomWidget: public Ui_BCMatrixRoomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCMATRIXROOMWIDGET_H
