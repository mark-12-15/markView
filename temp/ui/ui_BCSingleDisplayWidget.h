/********************************************************************************
** Form generated from reading UI file 'BCSingleDisplayWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSINGLEDISPLAYWIDGET_H
#define UI_BCSINGLEDISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSingleDisplayWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *m_pNameLabel;

    void setupUi(QWidget *BCSingleDisplayWidget)
    {
        if (BCSingleDisplayWidget->objectName().isEmpty())
            BCSingleDisplayWidget->setObjectName(QStringLiteral("BCSingleDisplayWidget"));
        BCSingleDisplayWidget->resize(358, 282);
        BCSingleDisplayWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(BCSingleDisplayWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pNameLabel = new QLabel(BCSingleDisplayWidget);
        m_pNameLabel->setObjectName(QStringLiteral("m_pNameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        m_pNameLabel->setFont(font);
        m_pNameLabel->setLayoutDirection(Qt::LeftToRight);
        m_pNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(m_pNameLabel);


        retranslateUi(BCSingleDisplayWidget);

        QMetaObject::connectSlotsByName(BCSingleDisplayWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSingleDisplayWidget)
    {
        BCSingleDisplayWidget->setWindowTitle(QApplication::translate("BCSingleDisplayWidget", "Form", Q_NULLPTR));
        m_pNameLabel->setText(QApplication::translate("BCSingleDisplayWidget", "000", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSingleDisplayWidget: public Ui_BCSingleDisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSINGLEDISPLAYWIDGET_H
