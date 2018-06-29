/********************************************************************************
** Form generated from reading UI file 'BCSettingDeviceFormatDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGDEVICEFORMATDLG_H
#define UI_BCSETTINGDEVICEFORMATDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSettingDeviceFormatDlg
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_pAddGroupBtn;
    QPushButton *m_pRemoveGroupBtn;
    QSpacerItem *horizontalSpacer;
    QListWidget *m_pListWidget;
    QSpinBox *m_pStartChannelLineEdit;
    QProgressBar *progressBar;
    QSpinBox *m_pArrayYLineEdit;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *m_pCustomResolutionLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *m_pResolutionCombbox;
    QWidget *m_pCustomResolutionWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_pAddResolutionBtn;
    QPushButton *m_pDelResolutionBtn;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *m_pModifyResolutionBtn;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *m_pGroupTypeCombox;
    QLineEdit *m_pNameLineEdit;
    QLabel *label_7;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_11;
    QSpinBox *m_pGroupIDSpinBox;
    QPushButton *m_pCancelBtn;
    QSpinBox *m_pArrayXLineEdit;
    QPushButton *m_pApplyBtn;
    QLabel *label_2;
    QPushButton *m_pOKBtn;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *BCSettingDeviceFormatDlg)
    {
        if (BCSettingDeviceFormatDlg->objectName().isEmpty())
            BCSettingDeviceFormatDlg->setObjectName(QStringLiteral("BCSettingDeviceFormatDlg"));
        BCSettingDeviceFormatDlg->resize(391, 570);
        gridLayout_2 = new QGridLayout(BCSettingDeviceFormatDlg);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(BCSettingDeviceFormatDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pAddGroupBtn = new QPushButton(BCSettingDeviceFormatDlg);
        m_pAddGroupBtn->setObjectName(QStringLiteral("m_pAddGroupBtn"));
        m_pAddGroupBtn->setFont(font);

        horizontalLayout->addWidget(m_pAddGroupBtn);

        m_pRemoveGroupBtn = new QPushButton(BCSettingDeviceFormatDlg);
        m_pRemoveGroupBtn->setObjectName(QStringLiteral("m_pRemoveGroupBtn"));
        m_pRemoveGroupBtn->setFont(font);

        horizontalLayout->addWidget(m_pRemoveGroupBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 6);

        m_pListWidget = new QListWidget(BCSettingDeviceFormatDlg);
        m_pListWidget->setObjectName(QStringLiteral("m_pListWidget"));
        m_pListWidget->setFont(font);

        gridLayout_2->addWidget(m_pListWidget, 0, 0, 1, 6);

        m_pStartChannelLineEdit = new QSpinBox(BCSettingDeviceFormatDlg);
        m_pStartChannelLineEdit->setObjectName(QStringLiteral("m_pStartChannelLineEdit"));
        m_pStartChannelLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pStartChannelLineEdit, 5, 4, 1, 2);

        progressBar = new QProgressBar(BCSettingDeviceFormatDlg);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximumSize(QSize(16777215, 5));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);

        gridLayout_2->addWidget(progressBar, 11, 0, 1, 6);

        m_pArrayYLineEdit = new QSpinBox(BCSettingDeviceFormatDlg);
        m_pArrayYLineEdit->setObjectName(QStringLiteral("m_pArrayYLineEdit"));
        m_pArrayYLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pArrayYLineEdit, 7, 4, 1, 2);

        label_5 = new QLabel(BCSettingDeviceFormatDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 7, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 6, 1, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 4, 1, 1, 3);

        horizontalSpacer_7 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 7, 1, 1, 3);

        groupBox = new QGroupBox(BCSettingDeviceFormatDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pCustomResolutionLabel = new QLabel(groupBox);
        m_pCustomResolutionLabel->setObjectName(QStringLiteral("m_pCustomResolutionLabel"));

        verticalLayout->addWidget(m_pCustomResolutionLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        m_pResolutionCombbox = new QComboBox(groupBox);
        m_pResolutionCombbox->setObjectName(QStringLiteral("m_pResolutionCombbox"));
        m_pResolutionCombbox->setMinimumSize(QSize(135, 0));
        m_pResolutionCombbox->setMaximumSize(QSize(135, 16777215));
        m_pResolutionCombbox->setFont(font);

        horizontalLayout_4->addWidget(m_pResolutionCombbox);


        verticalLayout->addLayout(horizontalLayout_4);

        m_pCustomResolutionWidget = new QWidget(groupBox);
        m_pCustomResolutionWidget->setObjectName(QStringLiteral("m_pCustomResolutionWidget"));
        horizontalLayout_2 = new QHBoxLayout(m_pCustomResolutionWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_pAddResolutionBtn = new QPushButton(m_pCustomResolutionWidget);
        m_pAddResolutionBtn->setObjectName(QStringLiteral("m_pAddResolutionBtn"));

        horizontalLayout_2->addWidget(m_pAddResolutionBtn);

        m_pDelResolutionBtn = new QPushButton(m_pCustomResolutionWidget);
        m_pDelResolutionBtn->setObjectName(QStringLiteral("m_pDelResolutionBtn"));

        horizontalLayout_2->addWidget(m_pDelResolutionBtn);

        horizontalSpacer_8 = new QSpacerItem(107, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        m_pModifyResolutionBtn = new QPushButton(m_pCustomResolutionWidget);
        m_pModifyResolutionBtn->setObjectName(QStringLiteral("m_pModifyResolutionBtn"));

        horizontalLayout_2->addWidget(m_pModifyResolutionBtn);


        verticalLayout->addWidget(m_pCustomResolutionWidget);


        gridLayout_2->addWidget(groupBox, 8, 0, 1, 6);

        horizontalSpacer_2 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 1, 1, 3);

        m_pGroupTypeCombox = new QComboBox(BCSettingDeviceFormatDlg);
        m_pGroupTypeCombox->setObjectName(QStringLiteral("m_pGroupTypeCombox"));
        m_pGroupTypeCombox->setFont(font);

        gridLayout_2->addWidget(m_pGroupTypeCombox, 2, 4, 1, 2);

        m_pNameLineEdit = new QLineEdit(BCSettingDeviceFormatDlg);
        m_pNameLineEdit->setObjectName(QStringLiteral("m_pNameLineEdit"));
        m_pNameLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pNameLineEdit, 4, 4, 1, 2);

        label_7 = new QLabel(BCSettingDeviceFormatDlg);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 5, 0, 1, 1);

        label_4 = new QLabel(BCSettingDeviceFormatDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(99, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 5, 1, 1, 3);

        label_11 = new QLabel(BCSettingDeviceFormatDlg);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        gridLayout_2->addWidget(label_11, 3, 0, 1, 1);

        m_pGroupIDSpinBox = new QSpinBox(BCSettingDeviceFormatDlg);
        m_pGroupIDSpinBox->setObjectName(QStringLiteral("m_pGroupIDSpinBox"));
        m_pGroupIDSpinBox->setFont(font);

        gridLayout_2->addWidget(m_pGroupIDSpinBox, 3, 4, 1, 2);

        m_pCancelBtn = new QPushButton(BCSettingDeviceFormatDlg);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));
        m_pCancelBtn->setFont(font);

        gridLayout_2->addWidget(m_pCancelBtn, 10, 3, 1, 2);

        m_pArrayXLineEdit = new QSpinBox(BCSettingDeviceFormatDlg);
        m_pArrayXLineEdit->setObjectName(QStringLiteral("m_pArrayXLineEdit"));
        m_pArrayXLineEdit->setFont(font);

        gridLayout_2->addWidget(m_pArrayXLineEdit, 6, 4, 1, 2);

        m_pApplyBtn = new QPushButton(BCSettingDeviceFormatDlg);
        m_pApplyBtn->setObjectName(QStringLiteral("m_pApplyBtn"));
        m_pApplyBtn->setFont(font);

        gridLayout_2->addWidget(m_pApplyBtn, 10, 5, 1, 1);

        label_2 = new QLabel(BCSettingDeviceFormatDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 4, 0, 1, 1);

        m_pOKBtn = new QPushButton(BCSettingDeviceFormatDlg);
        m_pOKBtn->setObjectName(QStringLiteral("m_pOKBtn"));
        m_pOKBtn->setFont(font);

        gridLayout_2->addWidget(m_pOKBtn, 10, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(143, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 9, 2, 1, 1);

        QWidget::setTabOrder(m_pOKBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pApplyBtn);
        QWidget::setTabOrder(m_pApplyBtn, m_pListWidget);
        QWidget::setTabOrder(m_pListWidget, m_pAddGroupBtn);
        QWidget::setTabOrder(m_pAddGroupBtn, m_pRemoveGroupBtn);
        QWidget::setTabOrder(m_pRemoveGroupBtn, m_pGroupTypeCombox);
        QWidget::setTabOrder(m_pGroupTypeCombox, m_pGroupIDSpinBox);
        QWidget::setTabOrder(m_pGroupIDSpinBox, m_pNameLineEdit);
        QWidget::setTabOrder(m_pNameLineEdit, m_pStartChannelLineEdit);
        QWidget::setTabOrder(m_pStartChannelLineEdit, m_pArrayXLineEdit);
        QWidget::setTabOrder(m_pArrayXLineEdit, m_pArrayYLineEdit);
        QWidget::setTabOrder(m_pArrayYLineEdit, m_pResolutionCombbox);
        QWidget::setTabOrder(m_pResolutionCombbox, m_pAddResolutionBtn);
        QWidget::setTabOrder(m_pAddResolutionBtn, m_pDelResolutionBtn);
        QWidget::setTabOrder(m_pDelResolutionBtn, m_pModifyResolutionBtn);

        retranslateUi(BCSettingDeviceFormatDlg);

        QMetaObject::connectSlotsByName(BCSettingDeviceFormatDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingDeviceFormatDlg)
    {
        BCSettingDeviceFormatDlg->setWindowTitle(QApplication::translate("BCSettingDeviceFormatDlg", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\261\217\347\273\204\347\261\273\345\236\213", Q_NULLPTR));
        m_pAddGroupBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\346\267\273\345\212\240", Q_NULLPTR));
        m_pRemoveGroupBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\210\240\351\231\244", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\347\272\265\345\220\221\346\216\222\345\210\227(\350\241\214)", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingDeviceFormatDlg", "\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        m_pCustomResolutionLabel->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\350\207\252\345\256\232\344\271\211\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\261\217\345\271\225\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        m_pResolutionCombbox->clear();
        m_pResolutionCombbox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDeviceFormatDlg", "1920*1080", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "1400*1050", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "1366*768", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "1280*720", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "1024*768", Q_NULLPTR)
        );
        m_pAddResolutionBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\346\267\273\345\212\240", Q_NULLPTR));
        m_pDelResolutionBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\210\240\351\231\244", Q_NULLPTR));
        m_pModifyResolutionBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\347\274\226\350\276\221", Q_NULLPTR));
        m_pGroupTypeCombox->clear();
        m_pGroupTypeCombox->insertItems(0, QStringList()
         << QApplication::translate("BCSettingDeviceFormatDlg", "LCD", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "LED", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "\346\212\225\345\275\261", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "4K", Q_NULLPTR)
         << QApplication::translate("BCSettingDeviceFormatDlg", "Matrix", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\350\265\267\345\247\213\351\200\232\351\201\223(\344\273\2160\345\274\200\345\247\213)", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\346\250\252\345\220\221\346\216\222\345\210\227(\345\210\227)", Q_NULLPTR));
        label_11->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\261\217\347\273\204ID", Q_NULLPTR));
        m_pCancelBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\217\226\346\266\210", Q_NULLPTR));
        m_pApplyBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\272\224\347\224\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\345\261\217\345\271\225\345\220\215\347\247\260", Q_NULLPTR));
        m_pOKBtn->setText(QApplication::translate("BCSettingDeviceFormatDlg", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingDeviceFormatDlg: public Ui_BCSettingDeviceFormatDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGDEVICEFORMATDLG_H
