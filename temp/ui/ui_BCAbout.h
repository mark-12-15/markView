/********************************************************************************
** Form generated from reading UI file 'BCAbout.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCABOUT_H
#define UI_BCABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCAbout
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *m_pVersionLabel;
    QLabel *m_pWebLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *BCAbout)
    {
        if (BCAbout->objectName().isEmpty())
            BCAbout->setObjectName(QStringLiteral("BCAbout"));
        BCAbout->resize(320, 136);
        BCAbout->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(BCAbout);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        widget_2 = new QWidget(BCAbout);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        verticalSpacer = new QSpacerItem(20, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        m_pVersionLabel = new QLabel(widget_2);
        m_pVersionLabel->setObjectName(QStringLiteral("m_pVersionLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pVersionLabel->setFont(font);
        m_pVersionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_pVersionLabel);

        m_pWebLabel = new QLabel(widget_2);
        m_pWebLabel->setObjectName(QStringLiteral("m_pWebLabel"));
        m_pWebLabel->setFont(font);

        verticalLayout_2->addWidget(m_pWebLabel);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(BCAbout);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(493, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(60, 16777215));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(widget);


        retranslateUi(BCAbout);

        QMetaObject::connectSlotsByName(BCAbout);
    } // setupUi

    void retranslateUi(QDialog *BCAbout)
    {
        BCAbout->setWindowTitle(QApplication::translate("BCAbout", "Dialog", Q_NULLPTR));
        m_pVersionLabel->setText(QApplication::translate("BCAbout", "Ver:3.11.48", Q_NULLPTR));
        m_pWebLabel->setText(QApplication::translate("BCAbout", "Web:www.brillview.com", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BCAbout", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCAbout: public Ui_BCAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCABOUT_H
