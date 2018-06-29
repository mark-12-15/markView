/********************************************************************************
** Form generated from reading UI file 'BCSettingPasswordStyle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGPASSWORDSTYLE_H
#define UI_BCSETTINGPASSWORDSTYLE_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingPasswordStyle
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *m_pOldLineEdit;
    QLabel *label_4;
    QLineEdit *m_pNewLineEdit;
    QLabel *label_5;
    QLineEdit *m_pReNewLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingPasswordStyle)
    {
        if (BCSettingPasswordStyle->objectName().isEmpty())
            BCSettingPasswordStyle->setObjectName(QStringLiteral("BCSettingPasswordStyle"));
        BCSettingPasswordStyle->resize(275, 153);
        verticalLayout = new QVBoxLayout(BCSettingPasswordStyle);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(BCSettingPasswordStyle);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        m_pOldLineEdit = new QLineEdit(BCSettingPasswordStyle);
        m_pOldLineEdit->setObjectName(QStringLiteral("m_pOldLineEdit"));
        m_pOldLineEdit->setFont(font);

        gridLayout->addWidget(m_pOldLineEdit, 0, 1, 1, 1);

        label_4 = new QLabel(BCSettingPasswordStyle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        m_pNewLineEdit = new QLineEdit(BCSettingPasswordStyle);
        m_pNewLineEdit->setObjectName(QStringLiteral("m_pNewLineEdit"));
        m_pNewLineEdit->setFont(font);

        gridLayout->addWidget(m_pNewLineEdit, 1, 1, 1, 1);

        label_5 = new QLabel(BCSettingPasswordStyle);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        m_pReNewLineEdit = new QLineEdit(BCSettingPasswordStyle);
        m_pReNewLineEdit->setObjectName(QStringLiteral("m_pReNewLineEdit"));
        m_pReNewLineEdit->setFont(font);

        gridLayout->addWidget(m_pReNewLineEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        m_pOKBtn = new QPushButton(BCSettingPasswordStyle);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pOKBtn->setFont(font1);

        horizontalLayout_4->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingPasswordStyle);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font1);

        horizontalLayout_4->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(BCSettingPasswordStyle);

        QMetaObject::connectSlotsByName(BCSettingPasswordStyle);
    } // setupUi

    void retranslateUi(QDialog *BCSettingPasswordStyle)
    {
        BCSettingPasswordStyle->setWindowTitle(QApplication::translate("BCSettingPasswordStyle", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingPasswordStyle", "\346\227\247\345\257\206\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingPasswordStyle", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingPasswordStyle", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingPasswordStyle", "\347\241\256\350\256\244", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingPasswordStyle", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingPasswordStyle: public Ui_BCSettingPasswordStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGPASSWORDSTYLE_H
