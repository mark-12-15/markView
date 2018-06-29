/********************************************************************************
** Form generated from reading UI file 'BCSettingBatchSubTitlesDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGBATCHSUBTITLESDLG_H
#define UI_BCSETTINGBATCHSUBTITLESDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_BCSettingBatchSubTitlesDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_3;
    QLineEdit *m_pSubTitlesTextLineEdit;
    QLabel *label_4;
    QLineEdit *m_pSubTitlesPosXLineEdit;
    QLabel *label_5;
    QLineEdit *m_pSubTitlesPosYLineEdit;
    QToolButton *m_pSubTitlesPosApplyBtn;
    QLabel *label_6;
    QPushButton *m_pSubTitlesColorBtn;
    QToolButton *m_pSubTitlesColorApplyBtn;
    QLabel *label_7;
    QComboBox *m_pSubTitlesVisibleCombox;
    QToolButton *m_pSubTitlesVisibleApplyBtn;
    QLineEdit *m_pEndChannelIDLineEdit;
    QLineEdit *m_pBeginChannelIDLineEdit;
    QToolButton *m_pSubTitlesTextApplyBtn;

    void setupUi(QDialog *BCSettingBatchSubTitlesDlg)
    {
        if (BCSettingBatchSubTitlesDlg->objectName().isEmpty())
            BCSettingBatchSubTitlesDlg->setObjectName(QStringLiteral("BCSettingBatchSubTitlesDlg"));
        BCSettingBatchSubTitlesDlg->resize(260, 226);
        gridLayout = new QGridLayout(BCSettingBatchSubTitlesDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BCSettingBatchSubTitlesDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(BCSettingBatchSubTitlesDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        line = new QFrame(BCSettingBatchSubTitlesDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setFont(font);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 3);

        label_3 = new QLabel(BCSettingBatchSubTitlesDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 2, 1);

        m_pSubTitlesTextLineEdit = new QLineEdit(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesTextLineEdit->setObjectName(QStringLiteral("m_pSubTitlesTextLineEdit"));
        m_pSubTitlesTextLineEdit->setFont(font);

        gridLayout->addWidget(m_pSubTitlesTextLineEdit, 3, 1, 2, 1);

        label_4 = new QLabel(BCSettingBatchSubTitlesDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        m_pSubTitlesPosXLineEdit = new QLineEdit(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesPosXLineEdit->setObjectName(QStringLiteral("m_pSubTitlesPosXLineEdit"));
        m_pSubTitlesPosXLineEdit->setFont(font);

        gridLayout->addWidget(m_pSubTitlesPosXLineEdit, 5, 1, 1, 1);

        label_5 = new QLabel(BCSettingBatchSubTitlesDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        m_pSubTitlesPosYLineEdit = new QLineEdit(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesPosYLineEdit->setObjectName(QStringLiteral("m_pSubTitlesPosYLineEdit"));
        m_pSubTitlesPosYLineEdit->setFont(font);

        gridLayout->addWidget(m_pSubTitlesPosYLineEdit, 6, 1, 1, 1);

        m_pSubTitlesPosApplyBtn = new QToolButton(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesPosApplyBtn->setObjectName(QStringLiteral("m_pSubTitlesPosApplyBtn"));
        m_pSubTitlesPosApplyBtn->setMinimumSize(QSize(0, 23));
        m_pSubTitlesPosApplyBtn->setFont(font);

        gridLayout->addWidget(m_pSubTitlesPosApplyBtn, 6, 2, 1, 1);

        label_6 = new QLabel(BCSettingBatchSubTitlesDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        m_pSubTitlesColorBtn = new QPushButton(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesColorBtn->setObjectName(QStringLiteral("m_pSubTitlesColorBtn"));
        m_pSubTitlesColorBtn->setFont(font);

        gridLayout->addWidget(m_pSubTitlesColorBtn, 7, 1, 1, 1);

        m_pSubTitlesColorApplyBtn = new QToolButton(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesColorApplyBtn->setObjectName(QStringLiteral("m_pSubTitlesColorApplyBtn"));
        m_pSubTitlesColorApplyBtn->setMinimumSize(QSize(0, 23));
        m_pSubTitlesColorApplyBtn->setFont(font);

        gridLayout->addWidget(m_pSubTitlesColorApplyBtn, 7, 2, 1, 1);

        label_7 = new QLabel(BCSettingBatchSubTitlesDlg);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        m_pSubTitlesVisibleCombox = new QComboBox(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesVisibleCombox->setObjectName(QStringLiteral("m_pSubTitlesVisibleCombox"));
        m_pSubTitlesVisibleCombox->setFont(font);

        gridLayout->addWidget(m_pSubTitlesVisibleCombox, 8, 1, 1, 1);

        m_pSubTitlesVisibleApplyBtn = new QToolButton(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesVisibleApplyBtn->setObjectName(QStringLiteral("m_pSubTitlesVisibleApplyBtn"));
        m_pSubTitlesVisibleApplyBtn->setMinimumSize(QSize(0, 23));
        m_pSubTitlesVisibleApplyBtn->setFont(font);

        gridLayout->addWidget(m_pSubTitlesVisibleApplyBtn, 8, 2, 1, 1);

        m_pEndChannelIDLineEdit = new QLineEdit(BCSettingBatchSubTitlesDlg);
        m_pEndChannelIDLineEdit->setObjectName(QStringLiteral("m_pEndChannelIDLineEdit"));
        m_pEndChannelIDLineEdit->setFont(font);

        gridLayout->addWidget(m_pEndChannelIDLineEdit, 1, 1, 1, 2);

        m_pBeginChannelIDLineEdit = new QLineEdit(BCSettingBatchSubTitlesDlg);
        m_pBeginChannelIDLineEdit->setObjectName(QStringLiteral("m_pBeginChannelIDLineEdit"));
        m_pBeginChannelIDLineEdit->setFont(font);

        gridLayout->addWidget(m_pBeginChannelIDLineEdit, 0, 1, 1, 2);

        m_pSubTitlesTextApplyBtn = new QToolButton(BCSettingBatchSubTitlesDlg);
        m_pSubTitlesTextApplyBtn->setObjectName(QStringLiteral("m_pSubTitlesTextApplyBtn"));
        m_pSubTitlesTextApplyBtn->setMinimumSize(QSize(0, 23));
        m_pSubTitlesTextApplyBtn->setFont(font);

        gridLayout->addWidget(m_pSubTitlesTextApplyBtn, 3, 2, 2, 1);


        retranslateUi(BCSettingBatchSubTitlesDlg);

        QMetaObject::connectSlotsByName(BCSettingBatchSubTitlesDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingBatchSubTitlesDlg)
    {
        BCSettingBatchSubTitlesDlg->setWindowTitle(QApplication::translate("BCSettingBatchSubTitlesDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\350\265\267\345\247\213\351\200\232\351\201\223", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\347\273\210\346\255\242\351\200\232\351\201\223", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\255\227\345\271\225\346\226\207\346\234\254", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\255\227\345\271\225\344\275\215\347\275\256X", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\255\227\345\271\225\344\275\215\347\275\256Y", Q_NULLPTR));
        m_pSubTitlesPosApplyBtn->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\255\227\345\271\225\351\242\234\350\211\262", Q_NULLPTR));
        m_pSubTitlesColorBtn->setText(QString());
        m_pSubTitlesColorApplyBtn->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        label_7->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\346\230\257\345\220\246\346\230\276\347\244\272", Q_NULLPTR));
        m_pSubTitlesVisibleCombox->clear();
        m_pSubTitlesVisibleCombox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\220\246", Q_NULLPTR)
         << QApplication::translate("BCSettingBatchSubTitlesDlg", "\346\230\257", Q_NULLPTR)
        );
        m_pSubTitlesVisibleApplyBtn->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        m_pSubTitlesTextApplyBtn->setText(QApplication::translate("BCSettingBatchSubTitlesDlg", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingBatchSubTitlesDlg: public Ui_BCSettingBatchSubTitlesDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGBATCHSUBTITLESDLG_H
