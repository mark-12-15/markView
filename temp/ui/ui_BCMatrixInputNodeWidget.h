/********************************************************************************
** Form generated from reading UI file 'BCMatrixInputNodeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCMATRIXINPUTNODEWIDGET_H
#define UI_BCMATRIXINPUTNODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCMatrixInputNodeWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *m_pNodeWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *m_pNodeIconLabel1;
    QSpacerItem *horizontalSpacer;
    QLabel *m_pStatusLabel1;
    QWidget *m_pNodeWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_pNodeIconLabel2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *m_pStatusLabel2;

    void setupUi(QWidget *BCMatrixInputNodeWidget)
    {
        if (BCMatrixInputNodeWidget->objectName().isEmpty())
            BCMatrixInputNodeWidget->setObjectName(QStringLiteral("BCMatrixInputNodeWidget"));
        BCMatrixInputNodeWidget->resize(401, 100);
        horizontalLayout_3 = new QHBoxLayout(BCMatrixInputNodeWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        m_pNodeWidget1 = new QWidget(BCMatrixInputNodeWidget);
        m_pNodeWidget1->setObjectName(QStringLiteral("m_pNodeWidget1"));
        horizontalLayout = new QHBoxLayout(m_pNodeWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pNodeIconLabel1 = new QLabel(m_pNodeWidget1);
        m_pNodeIconLabel1->setObjectName(QStringLiteral("m_pNodeIconLabel1"));
        m_pNodeIconLabel1->setMinimumSize(QSize(64, 64));
        m_pNodeIconLabel1->setMaximumSize(QSize(64, 64));
        m_pNodeIconLabel1->setStyleSheet(QStringLiteral("border-image: url(:/image/matrix/input.png);"));

        horizontalLayout->addWidget(m_pNodeIconLabel1);

        horizontalSpacer = new QSpacerItem(209, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pStatusLabel1 = new QLabel(m_pNodeWidget1);
        m_pStatusLabel1->setObjectName(QStringLiteral("m_pStatusLabel1"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pStatusLabel1->setFont(font);

        horizontalLayout->addWidget(m_pStatusLabel1);


        horizontalLayout_3->addWidget(m_pNodeWidget1);

        m_pNodeWidget2 = new QWidget(BCMatrixInputNodeWidget);
        m_pNodeWidget2->setObjectName(QStringLiteral("m_pNodeWidget2"));
        horizontalLayout_2 = new QHBoxLayout(m_pNodeWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_pNodeIconLabel2 = new QLabel(m_pNodeWidget2);
        m_pNodeIconLabel2->setObjectName(QStringLiteral("m_pNodeIconLabel2"));
        m_pNodeIconLabel2->setMinimumSize(QSize(64, 64));
        m_pNodeIconLabel2->setMaximumSize(QSize(64, 64));
        m_pNodeIconLabel2->setStyleSheet(QStringLiteral("border-image: url(:/image/matrix/input.png);"));

        horizontalLayout_2->addWidget(m_pNodeIconLabel2);

        horizontalSpacer_5 = new QSpacerItem(209, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        m_pStatusLabel2 = new QLabel(m_pNodeWidget2);
        m_pStatusLabel2->setObjectName(QStringLiteral("m_pStatusLabel2"));
        m_pStatusLabel2->setFont(font);

        horizontalLayout_2->addWidget(m_pStatusLabel2);


        horizontalLayout_3->addWidget(m_pNodeWidget2);


        retranslateUi(BCMatrixInputNodeWidget);

        QMetaObject::connectSlotsByName(BCMatrixInputNodeWidget);
    } // setupUi

    void retranslateUi(QWidget *BCMatrixInputNodeWidget)
    {
        m_pNodeIconLabel1->setText(QString());
        m_pStatusLabel1->setText(QApplication::translate("BCMatrixInputNodeWidget", "\350\276\223\345\205\2451", Q_NULLPTR));
        m_pNodeIconLabel2->setText(QString());
        m_pStatusLabel2->setText(QApplication::translate("BCMatrixInputNodeWidget", "\350\276\223\345\205\2451", Q_NULLPTR));
        Q_UNUSED(BCMatrixInputNodeWidget);
    } // retranslateUi

};

namespace Ui {
    class BCMatrixInputNodeWidget: public Ui_BCMatrixInputNodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCMATRIXINPUTNODEWIDGET_H
