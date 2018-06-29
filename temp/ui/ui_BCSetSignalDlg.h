/********************************************************************************
** Form generated from reading UI file 'BCSetSignalDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETSIGNALDLG_H
#define UI_BCSETSIGNALDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSetSignalDlg
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOkBtn;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QTreeWidget *m_pGroupChannelTreeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_pAddGroupInputChannelBtn;
    QPushButton *m_pDelGroupInputChannelBtn;
    QPushButton *m_pClearGroupInputChannelBtn;
    QPushButton *m_pModifyInputChannelBtn;
    QSpacerItem *horizontalSpacer_4;
    QTreeWidget *m_pInputChannelTreeWidget;
    QLabel *label_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QListWidget *m_pSignalSourceListWidget;
    QPushButton *m_pResetSignalSourceBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSetSignalDlg)
    {
        if (BCSetSignalDlg->objectName().isEmpty())
            BCSetSignalDlg->setObjectName(QStringLiteral("BCSetSignalDlg"));
        BCSetSignalDlg->resize(499, 481);
        gridLayout = new QGridLayout(BCSetSignalDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(419, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        m_pOkBtn = new QPushButton(BCSetSignalDlg);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pOkBtn->setFont(font);

        gridLayout->addWidget(m_pOkBtn, 1, 1, 1, 1);

        tabWidget = new QTabWidget(BCSetSignalDlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        m_pGroupChannelTreeWidget = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pGroupChannelTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pGroupChannelTreeWidget->setObjectName(QStringLiteral("m_pGroupChannelTreeWidget"));
        m_pGroupChannelTreeWidget->setFont(font);
        m_pGroupChannelTreeWidget->setFrameShape(QFrame::StyledPanel);
        m_pGroupChannelTreeWidget->setHeaderHidden(true);

        gridLayout_3->addWidget(m_pGroupChannelTreeWidget, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pAddGroupInputChannelBtn = new QPushButton(tab);
        m_pAddGroupInputChannelBtn->setObjectName(QStringLiteral("m_pAddGroupInputChannelBtn"));
        m_pAddGroupInputChannelBtn->setFont(font);

        horizontalLayout->addWidget(m_pAddGroupInputChannelBtn);

        m_pDelGroupInputChannelBtn = new QPushButton(tab);
        m_pDelGroupInputChannelBtn->setObjectName(QStringLiteral("m_pDelGroupInputChannelBtn"));
        m_pDelGroupInputChannelBtn->setFont(font);

        horizontalLayout->addWidget(m_pDelGroupInputChannelBtn);

        m_pClearGroupInputChannelBtn = new QPushButton(tab);
        m_pClearGroupInputChannelBtn->setObjectName(QStringLiteral("m_pClearGroupInputChannelBtn"));
        m_pClearGroupInputChannelBtn->setFont(font);

        horizontalLayout->addWidget(m_pClearGroupInputChannelBtn);

        m_pModifyInputChannelBtn = new QPushButton(tab);
        m_pModifyInputChannelBtn->setObjectName(QStringLiteral("m_pModifyInputChannelBtn"));
        m_pModifyInputChannelBtn->setFont(font);

        horizontalLayout->addWidget(m_pModifyInputChannelBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout_3->addLayout(horizontalLayout, 3, 0, 1, 2);

        m_pInputChannelTreeWidget = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        m_pInputChannelTreeWidget->setHeaderItem(__qtreewidgetitem1);
        m_pInputChannelTreeWidget->setObjectName(QStringLiteral("m_pInputChannelTreeWidget"));
        m_pInputChannelTreeWidget->setFont(font);
        m_pInputChannelTreeWidget->setFrameShape(QFrame::StyledPanel);
        m_pInputChannelTreeWidget->setHeaderHidden(true);

        gridLayout_3->addWidget(m_pInputChannelTreeWidget, 2, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        m_pSignalSourceListWidget = new QListWidget(tab_2);
        m_pSignalSourceListWidget->setObjectName(QStringLiteral("m_pSignalSourceListWidget"));

        gridLayout_2->addWidget(m_pSignalSourceListWidget, 0, 0, 1, 4);

        m_pResetSignalSourceBtn = new QPushButton(tab_2);
        m_pResetSignalSourceBtn->setObjectName(QStringLiteral("m_pResetSignalSourceBtn"));

        gridLayout_2->addWidget(m_pResetSignalSourceBtn, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 3);

        m_pCancelBtn = new QPushButton(BCSetSignalDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        gridLayout->addWidget(m_pCancelBtn, 1, 2, 1, 1);

        QWidget::setTabOrder(m_pAddGroupInputChannelBtn, m_pClearGroupInputChannelBtn);
        QWidget::setTabOrder(m_pClearGroupInputChannelBtn, m_pModifyInputChannelBtn);
        QWidget::setTabOrder(m_pModifyInputChannelBtn, m_pOkBtn);
        QWidget::setTabOrder(m_pOkBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pInputChannelTreeWidget);
        QWidget::setTabOrder(m_pInputChannelTreeWidget, m_pGroupChannelTreeWidget);
        QWidget::setTabOrder(m_pGroupChannelTreeWidget, tabWidget);
        QWidget::setTabOrder(tabWidget, m_pSignalSourceListWidget);
        QWidget::setTabOrder(m_pSignalSourceListWidget, m_pResetSignalSourceBtn);

        retranslateUi(BCSetSignalDlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BCSetSignalDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSetSignalDlg)
    {
        BCSetSignalDlg->setWindowTitle(QApplication::translate("BCSetSignalDlg", "\344\277\241\345\217\267\346\272\220\350\256\276\347\275\256", Q_NULLPTR));
        m_pOkBtn->setText(QApplication::translate("BCSetSignalDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSetSignalDlg", "\345\217\257\347\224\250\344\277\241\345\217\267\346\272\220\345\210\227\350\241\250", Q_NULLPTR));
        m_pAddGroupInputChannelBtn->setText(QApplication::translate("BCSetSignalDlg", "\346\226\260\345\273\272\345\210\206\347\273\204", Q_NULLPTR));
        m_pDelGroupInputChannelBtn->setText(QApplication::translate("BCSetSignalDlg", "\345\210\240\351\231\244\345\210\206\347\273\204", Q_NULLPTR));
        m_pClearGroupInputChannelBtn->setText(QApplication::translate("BCSetSignalDlg", "\346\270\205\347\251\272\345\210\206\347\273\204", Q_NULLPTR));
        m_pModifyInputChannelBtn->setText(QApplication::translate("BCSetSignalDlg", "\344\277\256\346\224\271\345\220\215\347\247\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSetSignalDlg", "\350\207\252\345\256\232\344\271\211\344\277\241\345\217\267\346\272\220\345\210\227\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BCSetSignalDlg", "\344\277\241\345\217\267\346\272\220\345\210\227\350\241\250", Q_NULLPTR));
        m_pResetSignalSourceBtn->setText(QApplication::translate("BCSetSignalDlg", "\346\201\242\345\244\215\351\273\230\350\256\244", Q_NULLPTR));
        label->setText(QApplication::translate("BCSetSignalDlg", "\346\263\250\357\274\232\351\274\240\346\240\207\345\267\246\351\224\256\347\202\271\345\207\273\346\213\226\346\213\275\350\277\233\350\241\214\346\216\222\345\272\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BCSetSignalDlg", "\351\235\242\346\235\277\346\216\247\345\210\266", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSetSignalDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSetSignalDlg: public Ui_BCSetSignalDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETSIGNALDLG_H
