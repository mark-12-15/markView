/********************************************************************************
** Form generated from reading UI file 'BCSettingAddIPVedioTreeWidgetItemDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGADDIPVEDIOTREEWIDGETITEMDLG_H
#define UI_BCSETTINGADDIPVEDIOTREEWIDGETITEMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_BCSettingAddIPVedioTreeWidgetItemDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *m_pPosLabel;
    QComboBox *m_pPosCombBox;
    QLabel *label;
    QLineEdit *m_pNameLineEdit;
    QLabel *label_2;
    QLineEdit *m_pUrlLineEdit;
    QLabel *label_3;
    QComboBox *m_pDecoderComboBox;
    QLabel *label_4;
    QLineEdit *m_pResolutionXLineEdit;
    QLineEdit *m_pResolutionYLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOKBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QDialog *BCSettingAddIPVedioTreeWidgetItemDlg)
    {
        if (BCSettingAddIPVedioTreeWidgetItemDlg->objectName().isEmpty())
            BCSettingAddIPVedioTreeWidgetItemDlg->setObjectName(QStringLiteral("BCSettingAddIPVedioTreeWidgetItemDlg"));
        BCSettingAddIPVedioTreeWidgetItemDlg->resize(204, 234);
        verticalLayout = new QVBoxLayout(BCSettingAddIPVedioTreeWidgetItemDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_pPosLabel = new QLabel(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pPosLabel->setObjectName(QStringLiteral("m_pPosLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pPosLabel->setFont(font);

        gridLayout->addWidget(m_pPosLabel, 0, 0, 1, 1);

        m_pPosCombBox = new QComboBox(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pPosCombBox->setObjectName(QStringLiteral("m_pPosCombBox"));
        m_pPosCombBox->setFont(font);

        gridLayout->addWidget(m_pPosCombBox, 0, 1, 1, 1);

        label = new QLabel(BCSettingAddIPVedioTreeWidgetItemDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        m_pNameLineEdit = new QLineEdit(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pNameLineEdit->setObjectName(QStringLiteral("m_pNameLineEdit"));
        m_pNameLineEdit->setFont(font);

        gridLayout->addWidget(m_pNameLineEdit, 1, 1, 1, 1);

        label_2 = new QLabel(BCSettingAddIPVedioTreeWidgetItemDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        m_pUrlLineEdit = new QLineEdit(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pUrlLineEdit->setObjectName(QStringLiteral("m_pUrlLineEdit"));
        m_pUrlLineEdit->setFont(font);

        gridLayout->addWidget(m_pUrlLineEdit, 2, 1, 1, 1);

        label_3 = new QLabel(BCSettingAddIPVedioTreeWidgetItemDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        m_pDecoderComboBox = new QComboBox(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pDecoderComboBox->setObjectName(QStringLiteral("m_pDecoderComboBox"));
        m_pDecoderComboBox->setFont(font);

        gridLayout->addWidget(m_pDecoderComboBox, 3, 1, 1, 1);

        label_4 = new QLabel(BCSettingAddIPVedioTreeWidgetItemDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        m_pResolutionXLineEdit = new QLineEdit(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pResolutionXLineEdit->setObjectName(QStringLiteral("m_pResolutionXLineEdit"));
        m_pResolutionXLineEdit->setFont(font);

        gridLayout->addWidget(m_pResolutionXLineEdit, 4, 1, 1, 1);

        m_pResolutionYLineEdit = new QLineEdit(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pResolutionYLineEdit->setObjectName(QStringLiteral("m_pResolutionYLineEdit"));
        m_pResolutionYLineEdit->setFont(font);

        gridLayout->addWidget(m_pResolutionYLineEdit, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOKBtn = new QPushButton(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        horizontalLayout->addWidget(m_pOKBtn);

        m_pCancelBtn = new QPushButton(BCSettingAddIPVedioTreeWidgetItemDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        horizontalLayout->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(m_pPosCombBox, m_pNameLineEdit);
        QWidget::setTabOrder(m_pNameLineEdit, m_pUrlLineEdit);
        QWidget::setTabOrder(m_pUrlLineEdit, m_pDecoderComboBox);
        QWidget::setTabOrder(m_pDecoderComboBox, m_pResolutionXLineEdit);
        QWidget::setTabOrder(m_pResolutionXLineEdit, m_pResolutionYLineEdit);
        QWidget::setTabOrder(m_pResolutionYLineEdit, m_pOKBtn);
        QWidget::setTabOrder(m_pOKBtn, m_pCancelBtn);

        retranslateUi(BCSettingAddIPVedioTreeWidgetItemDlg);

        QMetaObject::connectSlotsByName(BCSettingAddIPVedioTreeWidgetItemDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingAddIPVedioTreeWidgetItemDlg)
    {
        BCSettingAddIPVedioTreeWidgetItemDlg->setWindowTitle(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "Dialog", Q_NULLPTR));
        m_pPosLabel->setText(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "\344\275\215\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "\345\220\215\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "URL", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "\347\274\226\347\240\201", Q_NULLPTR));
        m_pDecoderComboBox->clear();
        m_pDecoderComboBox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "H264", Q_NULLPTR)
         << QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "H265", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingAddIPVedioTreeWidgetItemDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingAddIPVedioTreeWidgetItemDlg: public Ui_BCSettingAddIPVedioTreeWidgetItemDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGADDIPVEDIOTREEWIDGETITEMDLG_H
