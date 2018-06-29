/********************************************************************************
** Form generated from reading UI file 'BCSettingMainPanelStyle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGMAINPANELSTYLE_H
#define UI_BCSETTINGMAINPANELSTYLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BCSettingMainPanelStyle
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QRadioButton *m_pQuitToTrayRadioBtn;
    QRadioButton *m_pQuitRadioBtn;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingMainPanelStyle)
    {
        if (BCSettingMainPanelStyle->objectName().isEmpty())
            BCSettingMainPanelStyle->setObjectName(QStringLiteral("BCSettingMainPanelStyle"));
        BCSettingMainPanelStyle->resize(277, 122);
        verticalLayout = new QVBoxLayout(BCSettingMainPanelStyle);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(BCSettingMainPanelStyle);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        m_pQuitToTrayRadioBtn = new QRadioButton(BCSettingMainPanelStyle);
        m_pQuitToTrayRadioBtn->setObjectName(QStringLiteral("m_pQuitToTrayRadioBtn"));
        m_pQuitToTrayRadioBtn->setFont(font);

        verticalLayout->addWidget(m_pQuitToTrayRadioBtn);

        m_pQuitRadioBtn = new QRadioButton(BCSettingMainPanelStyle);
        m_pQuitRadioBtn->setObjectName(QStringLiteral("m_pQuitRadioBtn"));
        m_pQuitRadioBtn->setFont(font);

        verticalLayout->addWidget(m_pQuitRadioBtn);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingMainPanelStyle);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(false);
        font1.setWeight(50);
        m_pOKBtn->setFont(font1);

        horizontalLayout_2->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingMainPanelStyle);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font1);

        horizontalLayout_2->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BCSettingMainPanelStyle);

        QMetaObject::connectSlotsByName(BCSettingMainPanelStyle);
    } // setupUi

    void retranslateUi(QDialog *BCSettingMainPanelStyle)
    {
        BCSettingMainPanelStyle->setWindowTitle(QApplication::translate("BCSettingMainPanelStyle", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingMainPanelStyle", "\345\205\263\351\227\255\351\235\242\346\235\277\346\227\266:", Q_NULLPTR));
        m_pQuitToTrayRadioBtn->setText(QApplication::translate("BCSettingMainPanelStyle", "\351\232\220\350\227\217\345\210\260\344\273\273\345\212\241\346\240\217", Q_NULLPTR));
        m_pQuitRadioBtn->setText(QApplication::translate("BCSettingMainPanelStyle", "\351\200\200\345\207\272\347\250\213\345\272\217", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingMainPanelStyle", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingMainPanelStyle", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingMainPanelStyle: public Ui_BCSettingMainPanelStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGMAINPANELSTYLE_H
