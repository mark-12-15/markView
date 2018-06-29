/********************************************************************************
** Form generated from reading UI file 'BCSignal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSIGNAL_H
#define UI_BCSIGNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BCSignalTreeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCSignal
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFrame *m_pBodyFrame;
    QVBoxLayout *verticalLayout_4;
    QWidget *m_pHeaderWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_pShowVedioCheckBox;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QComboBox *m_pShowModeComboBox;
    BCSignalTreeWidget *m_pInputChannelTextTreeWidget;
    QTabWidget *m_pInputChannelVedioTabWidget;
    QWidget *tab;

    void setupUi(QWidget *BCSignal)
    {
        if (BCSignal->objectName().isEmpty())
            BCSignal->setObjectName(QStringLiteral("BCSignal"));
        BCSignal->resize(217, 311);
        verticalLayout_2 = new QVBoxLayout(BCSignal);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        m_pBodyFrame = new QFrame(BCSignal);
        m_pBodyFrame->setObjectName(QStringLiteral("m_pBodyFrame"));
        m_pBodyFrame->setFrameShape(QFrame::Box);
        m_pBodyFrame->setFrameShadow(QFrame::Sunken);
        verticalLayout_4 = new QVBoxLayout(m_pBodyFrame);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, 0, -1);
        m_pHeaderWidget = new QWidget(m_pBodyFrame);
        m_pHeaderWidget->setObjectName(QStringLiteral("m_pHeaderWidget"));
        m_pHeaderWidget->setMinimumSize(QSize(0, 20));
        m_pHeaderWidget->setMaximumSize(QSize(16777215, 20));
        horizontalLayout = new QHBoxLayout(m_pHeaderWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        m_pShowVedioCheckBox = new QCheckBox(m_pHeaderWidget);
        m_pShowVedioCheckBox->setObjectName(QStringLiteral("m_pShowVedioCheckBox"));
        m_pShowVedioCheckBox->setMaximumSize(QSize(1, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pShowVedioCheckBox->setFont(font);

        horizontalLayout->addWidget(m_pShowVedioCheckBox);

        label = new QLabel(m_pHeaderWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pShowModeComboBox = new QComboBox(m_pHeaderWidget);
        m_pShowModeComboBox->setObjectName(QStringLiteral("m_pShowModeComboBox"));
        m_pShowModeComboBox->setMinimumSize(QSize(100, 0));
        m_pShowModeComboBox->setMaximumSize(QSize(100, 16777215));
        m_pShowModeComboBox->setFont(font);
        m_pShowModeComboBox->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(m_pShowModeComboBox);


        verticalLayout_4->addWidget(m_pHeaderWidget);

        m_pInputChannelTextTreeWidget = new BCSignalTreeWidget(m_pBodyFrame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pInputChannelTextTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pInputChannelTextTreeWidget->setObjectName(QStringLiteral("m_pInputChannelTextTreeWidget"));

        verticalLayout_4->addWidget(m_pInputChannelTextTreeWidget);

        m_pInputChannelVedioTabWidget = new QTabWidget(m_pBodyFrame);
        m_pInputChannelVedioTabWidget->setObjectName(QStringLiteral("m_pInputChannelVedioTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        m_pInputChannelVedioTabWidget->addTab(tab, QString());

        verticalLayout_4->addWidget(m_pInputChannelVedioTabWidget);


        verticalLayout_2->addWidget(m_pBodyFrame);


        retranslateUi(BCSignal);

        QMetaObject::connectSlotsByName(BCSignal);
    } // setupUi

    void retranslateUi(QWidget *BCSignal)
    {
        BCSignal->setWindowTitle(QApplication::translate("BCSignal", "Form", Q_NULLPTR));
        m_pShowVedioCheckBox->setText(QApplication::translate("BCSignal", "\346\230\276\347\244\272\350\247\206\351\242\221", Q_NULLPTR));
        label->setText(QApplication::translate("BCSignal", "\346\230\276\347\244\272\346\250\241\345\274\217", Q_NULLPTR));
        m_pInputChannelVedioTabWidget->setTabText(m_pInputChannelVedioTabWidget->indexOf(tab), QApplication::translate("BCSignal", "Tab 1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSignal: public Ui_BCSignal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSIGNAL_H
