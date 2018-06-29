/********************************************************************************
** Form generated from reading UI file 'BCLocationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCLOCATIONDLG_H
#define UI_BCLOCATIONDLG_H

#include <BCLocationSegmentationWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include "BCLocationGroupWidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCLocationDlg
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    BCLocationGroupWidget *m_pLocationGroupWidget;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    BCLocationSegmentationWidget *m_pLocationWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *m_pRadioBtn1;
    QRadioButton *m_pRadioBtn4;
    QRadioButton *m_pRadioBtn6;
    QRadioButton *m_pRadioBtn8;
    QRadioButton *m_pRadioBtn9;
    QRadioButton *m_pRadioBtn12;
    QRadioButton *m_pRadioBtn16;

    void setupUi(QDialog *BCLocationDlg)
    {
        if (BCLocationDlg->objectName().isEmpty())
            BCLocationDlg->setObjectName(QStringLiteral("BCLocationDlg"));
        BCLocationDlg->resize(846, 258);
        horizontalLayout_2 = new QHBoxLayout(BCLocationDlg);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(BCLocationDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        m_pLocationGroupWidget = new BCLocationGroupWidget(groupBox);
        m_pLocationGroupWidget->setObjectName(QStringLiteral("m_pLocationGroupWidget"));
        m_pLocationGroupWidget->setMinimumSize(QSize(430, 200));

        verticalLayout_2->addWidget(m_pLocationGroupWidget);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BCLocationDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        m_pLocationWidget = new BCLocationSegmentationWidget(groupBox_2);
        m_pLocationWidget->setObjectName(QStringLiteral("m_pLocationWidget"));
        m_pLocationWidget->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(m_pLocationWidget);


        horizontalLayout_2->addWidget(groupBox_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pRadioBtn1 = new QRadioButton(BCLocationDlg);
        m_pRadioBtn1->setObjectName(QStringLiteral("m_pRadioBtn1"));
        m_pRadioBtn1->setFont(font);

        verticalLayout->addWidget(m_pRadioBtn1);

        m_pRadioBtn4 = new QRadioButton(BCLocationDlg);
        m_pRadioBtn4->setObjectName(QStringLiteral("m_pRadioBtn4"));
        m_pRadioBtn4->setFont(font);

        verticalLayout->addWidget(m_pRadioBtn4);

        m_pRadioBtn6 = new QRadioButton(BCLocationDlg);
        m_pRadioBtn6->setObjectName(QStringLiteral("m_pRadioBtn6"));
        m_pRadioBtn6->setFont(font);

        verticalLayout->addWidget(m_pRadioBtn6);

        m_pRadioBtn8 = new QRadioButton(BCLocationDlg);
        m_pRadioBtn8->setObjectName(QStringLiteral("m_pRadioBtn8"));
        m_pRadioBtn8->setFont(font);

        verticalLayout->addWidget(m_pRadioBtn8);

        m_pRadioBtn9 = new QRadioButton(BCLocationDlg);
        m_pRadioBtn9->setObjectName(QStringLiteral("m_pRadioBtn9"));
        m_pRadioBtn9->setFont(font);

        verticalLayout->addWidget(m_pRadioBtn9);

        m_pRadioBtn12 = new QRadioButton(BCLocationDlg);
        m_pRadioBtn12->setObjectName(QStringLiteral("m_pRadioBtn12"));
        m_pRadioBtn12->setFont(font);

        verticalLayout->addWidget(m_pRadioBtn12);

        m_pRadioBtn16 = new QRadioButton(BCLocationDlg);
        m_pRadioBtn16->setObjectName(QStringLiteral("m_pRadioBtn16"));
        m_pRadioBtn16->setFont(font);

        verticalLayout->addWidget(m_pRadioBtn16);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(BCLocationDlg);

        QMetaObject::connectSlotsByName(BCLocationDlg);
    } // setupUi

    void retranslateUi(QDialog *BCLocationDlg)
    {
        BCLocationDlg->setWindowTitle(QApplication::translate("BCLocationDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCLocationDlg", "\345\277\253\351\200\237\345\274\200\347\252\227", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCLocationDlg", "\347\275\221\346\240\274\345\256\232\344\275\215", Q_NULLPTR));
        m_pRadioBtn1->setText(QApplication::translate("BCLocationDlg", "\346\225\264\345\261\217", Q_NULLPTR));
        m_pRadioBtn4->setText(QApplication::translate("BCLocationDlg", "\345\233\233\345\210\206\345\211\262", Q_NULLPTR));
        m_pRadioBtn6->setText(QApplication::translate("BCLocationDlg", "\345\205\255\345\210\206\345\211\262", Q_NULLPTR));
        m_pRadioBtn8->setText(QApplication::translate("BCLocationDlg", "\345\205\253\345\210\206\345\211\262", Q_NULLPTR));
        m_pRadioBtn9->setText(QApplication::translate("BCLocationDlg", "\344\271\235\345\210\206\345\211\262", Q_NULLPTR));
        m_pRadioBtn12->setText(QApplication::translate("BCLocationDlg", "\345\215\201\344\272\214\345\210\206\345\211\262", Q_NULLPTR));
        m_pRadioBtn16->setText(QApplication::translate("BCLocationDlg", "\345\215\201\345\205\255\345\210\206\345\211\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCLocationDlg: public Ui_BCLocationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCLOCATIONDLG_H
