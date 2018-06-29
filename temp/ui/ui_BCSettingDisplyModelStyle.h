/********************************************************************************
** Form generated from reading UI file 'BCSettingDisplyModelStyle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDISPLYMODELSTYLE_H
#define UI_BCSETTINGDISPLYMODELSTYLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDisplyModelStyle
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;
    QLabel *label_2;
    QRadioButton *m_pRadioBtn1;
    QLineEdit *m_pWLineEdit;
    QLabel *label_4;
    QLineEdit *m_pHLineEdit;
    QRadioButton *m_pRadioBtn2;
    QRadioButton *m_pRadioBtn3;
    QRadioButton *m_pRadioBtn4;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;

    void setupUi(QDialog *BCSettingDisplyModelStyle)
    {
        if (BCSettingDisplyModelStyle->objectName().isEmpty())
            BCSettingDisplyModelStyle->setObjectName(QStringLiteral("BCSettingDisplyModelStyle"));
        BCSettingDisplyModelStyle->resize(326, 201);
        gridLayout = new QGridLayout(BCSettingDisplyModelStyle);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingDisplyModelStyle);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pOKBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingDisplyModelStyle);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        gridLayout->addLayout(horizontalLayout_2, 6, 0, 1, 6);

        label_2 = new QLabel(BCSettingDisplyModelStyle);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        m_pRadioBtn1 = new QRadioButton(BCSettingDisplyModelStyle);
        m_pRadioBtn1->setObjectName(QStringLiteral("m_pRadioBtn1"));
        m_pRadioBtn1->setFont(font1);

        gridLayout->addWidget(m_pRadioBtn1, 1, 0, 1, 1);

        m_pWLineEdit = new QLineEdit(BCSettingDisplyModelStyle);
        m_pWLineEdit->setObjectName(QStringLiteral("m_pWLineEdit"));
        m_pWLineEdit->setFont(font1);

        gridLayout->addWidget(m_pWLineEdit, 1, 3, 1, 1);

        label_4 = new QLabel(BCSettingDisplyModelStyle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 1, 4, 1, 1);

        m_pHLineEdit = new QLineEdit(BCSettingDisplyModelStyle);
        m_pHLineEdit->setObjectName(QStringLiteral("m_pHLineEdit"));
        m_pHLineEdit->setFont(font1);

        gridLayout->addWidget(m_pHLineEdit, 1, 5, 1, 1);

        m_pRadioBtn2 = new QRadioButton(BCSettingDisplyModelStyle);
        m_pRadioBtn2->setObjectName(QStringLiteral("m_pRadioBtn2"));
        m_pRadioBtn2->setFont(font);

        gridLayout->addWidget(m_pRadioBtn2, 2, 0, 1, 6);

        m_pRadioBtn3 = new QRadioButton(BCSettingDisplyModelStyle);
        m_pRadioBtn3->setObjectName(QStringLiteral("m_pRadioBtn3"));
        m_pRadioBtn3->setMinimumSize(QSize(0, 0));
        m_pRadioBtn3->setMaximumSize(QSize(16777215, 16777215));
        m_pRadioBtn3->setFont(font1);

        gridLayout->addWidget(m_pRadioBtn3, 3, 0, 1, 6);

        m_pRadioBtn4 = new QRadioButton(BCSettingDisplyModelStyle);
        m_pRadioBtn4->setObjectName(QStringLiteral("m_pRadioBtn4"));
        m_pRadioBtn4->setMinimumSize(QSize(0, 0));
        m_pRadioBtn4->setMaximumSize(QSize(16777215, 16777215));
        m_pRadioBtn4->setFont(font1);

        gridLayout->addWidget(m_pRadioBtn4, 4, 0, 1, 6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        label_3 = new QLabel(BCSettingDisplyModelStyle);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        QWidget::setTabOrder(m_pRadioBtn1, m_pWLineEdit);
        QWidget::setTabOrder(m_pWLineEdit, m_pHLineEdit);
        QWidget::setTabOrder(m_pHLineEdit, m_pRadioBtn2);
        QWidget::setTabOrder(m_pRadioBtn2, m_pRadioBtn3);
        QWidget::setTabOrder(m_pRadioBtn3, m_pRadioBtn4);
        QWidget::setTabOrder(m_pRadioBtn4, m_pOKBtn);
        QWidget::setTabOrder(m_pOKBtn, m_pCancelBtn);

        retranslateUi(BCSettingDisplyModelStyle);

        QMetaObject::connectSlotsByName(BCSettingDisplyModelStyle);
    } // setupUi

    void retranslateUi(QDialog *BCSettingDisplyModelStyle)
    {
        BCSettingDisplyModelStyle->setWindowTitle(QApplication::translate("BCSettingDisplyModelStyle", "Dialog", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingDisplyModelStyle", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingDisplyModelStyle", "\345\217\226\346\266\210", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingDisplyModelStyle", "\345\210\235\345\247\213\345\214\226\346\230\276\347\244\272\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        m_pRadioBtn1->setText(QApplication::translate("BCSettingDisplyModelStyle", "\346\255\243\345\270\270", Q_NULLPTR));
        m_pWLineEdit->setText(QApplication::translate("BCSettingDisplyModelStyle", "1000", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingDisplyModelStyle", "\351\253\230\345\272\246\357\274\232", Q_NULLPTR));
        m_pHLineEdit->setText(QApplication::translate("BCSettingDisplyModelStyle", "600", Q_NULLPTR));
        m_pRadioBtn2->setText(QApplication::translate("BCSettingDisplyModelStyle", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
        m_pRadioBtn3->setText(QApplication::translate("BCSettingDisplyModelStyle", "\346\234\200\345\244\247\345\214\226", Q_NULLPTR));
        m_pRadioBtn4->setText(QApplication::translate("BCSettingDisplyModelStyle", "\345\205\250\345\261\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingDisplyModelStyle", "\345\256\275\345\272\246\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDisplyModelStyle: public Ui_BCSettingDisplyModelStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDISPLYMODELSTYLE_H
