/********************************************************************************
** Form generated from reading UI file 'BCControl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCCONTROL_H
#define UI_BCCONTROL_H

#include <BCControlTreeWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCControl
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *m_pBodyFrame;
    QVBoxLayout *verticalLayout_5;
    QWidget *m_pHeaderWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_pShowVedioCheckBox;
    QSpacerItem *horizontalSpacer;
    QComboBox *m_pShowModeComboBox;
    QTabWidget *m_pInputChannelTextTabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    BCControlTreeWidget *m_pInputChannelTextListWidget1;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    BCControlTreeWidget *m_pInputChannelTextListWidget2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_6;
    BCControlTreeWidget *m_pInputChannelTextListWidget4;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    BCControlTreeWidget *m_pInputChannelTextListWidget3;
    QListWidget *m_pInputChannelVedioListWidget;

    void setupUi(QWidget *BCControl)
    {
        if (BCControl->objectName().isEmpty())
            BCControl->setObjectName(QStringLiteral("BCControl"));
        BCControl->resize(230, 316);
        gridLayout = new QGridLayout(BCControl);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        m_pBodyFrame = new QFrame(BCControl);
        m_pBodyFrame->setObjectName(QStringLiteral("m_pBodyFrame"));
        m_pBodyFrame->setFrameShape(QFrame::Box);
        m_pBodyFrame->setFrameShadow(QFrame::Sunken);
        verticalLayout_5 = new QVBoxLayout(m_pBodyFrame);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, -1, 0, -1);
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

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pShowModeComboBox = new QComboBox(m_pHeaderWidget);
        m_pShowModeComboBox->setObjectName(QStringLiteral("m_pShowModeComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pShowModeComboBox->sizePolicy().hasHeightForWidth());
        m_pShowModeComboBox->setSizePolicy(sizePolicy);
        m_pShowModeComboBox->setMinimumSize(QSize(100, 0));
        m_pShowModeComboBox->setMaximumSize(QSize(100, 16777215));
        m_pShowModeComboBox->setFont(font);
        m_pShowModeComboBox->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(m_pShowModeComboBox);


        verticalLayout_5->addWidget(m_pHeaderWidget);

        m_pInputChannelTextTabWidget = new QTabWidget(m_pBodyFrame);
        m_pInputChannelTextTabWidget->setObjectName(QStringLiteral("m_pInputChannelTextTabWidget"));
        m_pInputChannelTextTabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_pInputChannelTextListWidget1 = new BCControlTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pInputChannelTextListWidget1->setHeaderItem(__qtreewidgetitem);
        m_pInputChannelTextListWidget1->setObjectName(QStringLiteral("m_pInputChannelTextListWidget1"));

        verticalLayout_2->addWidget(m_pInputChannelTextListWidget1);

        m_pInputChannelTextTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_pInputChannelTextListWidget2 = new BCControlTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        m_pInputChannelTextListWidget2->setHeaderItem(__qtreewidgetitem1);
        m_pInputChannelTextListWidget2->setObjectName(QStringLiteral("m_pInputChannelTextListWidget2"));

        verticalLayout_3->addWidget(m_pInputChannelTextListWidget2);

        m_pInputChannelTextTabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_6 = new QVBoxLayout(tab_4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        m_pInputChannelTextListWidget4 = new BCControlTreeWidget(tab_4);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        m_pInputChannelTextListWidget4->setHeaderItem(__qtreewidgetitem2);
        m_pInputChannelTextListWidget4->setObjectName(QStringLiteral("m_pInputChannelTextListWidget4"));

        verticalLayout_6->addWidget(m_pInputChannelTextListWidget4);

        m_pInputChannelTextTabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        m_pInputChannelTextListWidget3 = new BCControlTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setText(0, QStringLiteral("1"));
        m_pInputChannelTextListWidget3->setHeaderItem(__qtreewidgetitem3);
        m_pInputChannelTextListWidget3->setObjectName(QStringLiteral("m_pInputChannelTextListWidget3"));

        verticalLayout_4->addWidget(m_pInputChannelTextListWidget3);

        m_pInputChannelTextTabWidget->addTab(tab_3, QString());

        verticalLayout_5->addWidget(m_pInputChannelTextTabWidget);

        m_pInputChannelVedioListWidget = new QListWidget(m_pBodyFrame);
        m_pInputChannelVedioListWidget->setObjectName(QStringLiteral("m_pInputChannelVedioListWidget"));

        verticalLayout_5->addWidget(m_pInputChannelVedioListWidget);


        gridLayout->addWidget(m_pBodyFrame, 1, 0, 1, 1);


        retranslateUi(BCControl);

        m_pInputChannelTextTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BCControl);
    } // setupUi

    void retranslateUi(QWidget *BCControl)
    {
        BCControl->setWindowTitle(QApplication::translate("BCControl", "Form", Q_NULLPTR));
        m_pShowVedioCheckBox->setText(QApplication::translate("BCControl", "\346\230\276\347\244\272\350\247\206\351\242\221", Q_NULLPTR));
        m_pInputChannelTextTabWidget->setTabText(m_pInputChannelTextTabWidget->indexOf(tab), QApplication::translate("BCControl", "\347\224\265\350\204\221", Q_NULLPTR));
        m_pInputChannelTextTabWidget->setTabText(m_pInputChannelTextTabWidget->indexOf(tab_2), QApplication::translate("BCControl", "IPVideo", Q_NULLPTR));
        m_pInputChannelTextTabWidget->setTabText(m_pInputChannelTextTabWidget->indexOf(tab_4), QApplication::translate("BCControl", "Video", Q_NULLPTR));
        m_pInputChannelTextTabWidget->setTabText(m_pInputChannelTextTabWidget->indexOf(tab_3), QApplication::translate("BCControl", "\351\253\230\346\270\205", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCControl: public Ui_BCControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCCONTROL_H
