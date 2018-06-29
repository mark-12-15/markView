/********************************************************************************
** Form generated from reading UI file 'BCScreenName.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSCREENNAME_H
#define UI_BCSCREENNAME_H

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

QT_BEGIN_NAMESPACE

class Ui_BCScreenName
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCScreenName)
    {
        if (BCScreenName->objectName().isEmpty())
            BCScreenName->setObjectName(QStringLiteral("BCScreenName"));
        BCScreenName->resize(218, 69);
        gridLayout = new QGridLayout(BCScreenName);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(BCScreenName);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(BCScreenName);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(35, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        m_pOKBtn = new QPushButton(BCScreenName);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        gridLayout->addWidget(m_pOKBtn, 1, 1, 1, 1);

        m_pCancelBtn = new QPushButton(BCScreenName);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        gridLayout->addWidget(m_pCancelBtn, 1, 2, 1, 1);


        retranslateUi(BCScreenName);

        QMetaObject::connectSlotsByName(BCScreenName);
    } // setupUi

    void retranslateUi(QDialog *BCScreenName)
    {
        BCScreenName->setWindowTitle(QApplication::translate("BCScreenName", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCScreenName", "TextLabel", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCScreenName", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCScreenName", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCScreenName: public Ui_BCScreenName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSCREENNAME_H
