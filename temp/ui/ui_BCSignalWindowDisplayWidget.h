/********************************************************************************
** Form generated from reading UI file 'BCSignalWindowDisplayWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSIGNALWINDOWDISPLAYWIDGET_H
#define UI_BCSIGNALWINDOWDISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSignalWindowDisplayWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *m_pHeaderWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *m_pWindowTitleLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *m_pSubTitleLabel;
    QToolButton *m_pRemoteBtn;
    QToolButton *m_pLockBtn;
    QToolButton *m_pFullscreenBtn;
    QToolButton *m_pWindowShowBtn;
    QToolButton *m_pCloseBtn;
    QWidget *m_pBodyWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *m_pGenaralBodyWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_pWindowFlagLabel;
    QSpacerItem *verticalSpacer;
    QWidget *m_pIPVBodyWidget;

    void setupUi(QWidget *BCSignalWindowDisplayWidget)
    {
        if (BCSignalWindowDisplayWidget->objectName().isEmpty())
            BCSignalWindowDisplayWidget->setObjectName(QStringLiteral("BCSignalWindowDisplayWidget"));
        BCSignalWindowDisplayWidget->resize(276, 154);
        verticalLayout = new QVBoxLayout(BCSignalWindowDisplayWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 0, 3, 3);
        m_pHeaderWidget = new QWidget(BCSignalWindowDisplayWidget);
        m_pHeaderWidget->setObjectName(QStringLiteral("m_pHeaderWidget"));
        m_pHeaderWidget->setMinimumSize(QSize(0, 24));
        m_pHeaderWidget->setMaximumSize(QSize(16777215, 24));
        m_pHeaderWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(m_pHeaderWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 2, 6, 2);
        m_pWindowTitleLabel = new QLabel(m_pHeaderWidget);
        m_pWindowTitleLabel->setObjectName(QStringLiteral("m_pWindowTitleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pWindowTitleLabel->setFont(font);

        horizontalLayout->addWidget(m_pWindowTitleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pSubTitleLabel = new QLabel(m_pHeaderWidget);
        m_pSubTitleLabel->setObjectName(QStringLiteral("m_pSubTitleLabel"));
        m_pSubTitleLabel->setMinimumSize(QSize(16, 16));
        m_pSubTitleLabel->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(m_pSubTitleLabel);

        m_pRemoteBtn = new QToolButton(m_pHeaderWidget);
        m_pRemoteBtn->setObjectName(QStringLiteral("m_pRemoteBtn"));
        m_pRemoteBtn->setMinimumSize(QSize(20, 20));
        m_pRemoteBtn->setMaximumSize(QSize(20, 20));
        m_pRemoteBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pRemoteBtn);

        m_pLockBtn = new QToolButton(m_pHeaderWidget);
        m_pLockBtn->setObjectName(QStringLiteral("m_pLockBtn"));
        m_pLockBtn->setMinimumSize(QSize(20, 20));
        m_pLockBtn->setMaximumSize(QSize(20, 20));
        m_pLockBtn->setStyleSheet(QStringLiteral(""));
        m_pLockBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pLockBtn);

        m_pFullscreenBtn = new QToolButton(m_pHeaderWidget);
        m_pFullscreenBtn->setObjectName(QStringLiteral("m_pFullscreenBtn"));
        m_pFullscreenBtn->setMinimumSize(QSize(20, 20));
        m_pFullscreenBtn->setMaximumSize(QSize(20, 20));
        m_pFullscreenBtn->setStyleSheet(QStringLiteral(""));
        m_pFullscreenBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pFullscreenBtn);

        m_pWindowShowBtn = new QToolButton(m_pHeaderWidget);
        m_pWindowShowBtn->setObjectName(QStringLiteral("m_pWindowShowBtn"));
        m_pWindowShowBtn->setMinimumSize(QSize(20, 20));
        m_pWindowShowBtn->setMaximumSize(QSize(20, 20));
        m_pWindowShowBtn->setStyleSheet(QStringLiteral(""));
        m_pWindowShowBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pWindowShowBtn);

        m_pCloseBtn = new QToolButton(m_pHeaderWidget);
        m_pCloseBtn->setObjectName(QStringLiteral("m_pCloseBtn"));
        m_pCloseBtn->setMinimumSize(QSize(20, 20));
        m_pCloseBtn->setMaximumSize(QSize(20, 20));
        m_pCloseBtn->setStyleSheet(QStringLiteral(""));
        m_pCloseBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pCloseBtn);


        verticalLayout->addWidget(m_pHeaderWidget);

        m_pBodyWidget = new QWidget(BCSignalWindowDisplayWidget);
        m_pBodyWidget->setObjectName(QStringLiteral("m_pBodyWidget"));
        verticalLayout_3 = new QVBoxLayout(m_pBodyWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_pGenaralBodyWidget = new QWidget(m_pBodyWidget);
        m_pGenaralBodyWidget->setObjectName(QStringLiteral("m_pGenaralBodyWidget"));
        verticalLayout_2 = new QVBoxLayout(m_pGenaralBodyWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        m_pWindowFlagLabel = new QLabel(m_pGenaralBodyWidget);
        m_pWindowFlagLabel->setObjectName(QStringLiteral("m_pWindowFlagLabel"));
        m_pWindowFlagLabel->setFont(font);

        verticalLayout_2->addWidget(m_pWindowFlagLabel);

        verticalSpacer = new QSpacerItem(20, 76, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addWidget(m_pGenaralBodyWidget);

        m_pIPVBodyWidget = new QWidget(m_pBodyWidget);
        m_pIPVBodyWidget->setObjectName(QStringLiteral("m_pIPVBodyWidget"));

        verticalLayout_3->addWidget(m_pIPVBodyWidget);


        verticalLayout->addWidget(m_pBodyWidget);


        retranslateUi(BCSignalWindowDisplayWidget);

        QMetaObject::connectSlotsByName(BCSignalWindowDisplayWidget);
    } // setupUi

    void retranslateUi(QWidget *BCSignalWindowDisplayWidget)
    {
        BCSignalWindowDisplayWidget->setWindowTitle(QApplication::translate("BCSignalWindowDisplayWidget", "Form", Q_NULLPTR));
        m_pWindowTitleLabel->setText(QApplication::translate("BCSignalWindowDisplayWidget", "\347\252\227\345\217\2431", Q_NULLPTR));
        m_pSubTitleLabel->setText(QString());
        m_pRemoteBtn->setText(QString());
        m_pLockBtn->setText(QString());
        m_pFullscreenBtn->setText(QString());
        m_pWindowShowBtn->setText(QString());
        m_pCloseBtn->setText(QString());
        m_pWindowFlagLabel->setText(QApplication::translate("BCSignalWindowDisplayWidget", "\347\252\227\345\217\243\346\240\207\350\257\206\357\274\2320", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSignalWindowDisplayWidget: public Ui_BCSignalWindowDisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSIGNALWINDOWDISPLAYWIDGET_H
