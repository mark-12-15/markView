/********************************************************************************
** Form generated from reading UI file 'BCOtherDeviceControlDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCOTHERDEVICECONTROLDLG_H
#define UI_BCOTHERDEVICECONTROLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCOtherDeviceControlDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *m_pDisplayOnBtn;
    QToolButton *m_pDisplayOffBtn;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *m_pLightingOnBtn;
    QToolButton *m_pLightingOffBtn;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *m_pAudioPlusBtn;
    QToolButton *m_pAudioReduceBtn;
    QToolButton *m_pAudioSilenceBtn;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QToolButton *m_pVedioZoomOnBtn;
    QToolButton *m_pVedioZoomOffBtn;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QToolButton *m_pVedioFocusOnBtn;
    QToolButton *m_pVedioFocusOffBtn;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QToolButton *m_pVedioLeftTopBtn;
    QToolButton *m_pVedioTopBtn;
    QToolButton *m_pVedioRightTopBtn;
    QToolButton *m_pVedioLeftBtn;
    QToolButton *m_pVedioStopBtn;
    QToolButton *m_pVedioRightBtn;
    QToolButton *m_pVedioLeftBottomBtn;
    QToolButton *m_pVedioBottomBtn;
    QToolButton *m_pVedioRightBottomBtn;

    void setupUi(QDialog *BCOtherDeviceControlDlg)
    {
        if (BCOtherDeviceControlDlg->objectName().isEmpty())
            BCOtherDeviceControlDlg->setObjectName(QStringLiteral("BCOtherDeviceControlDlg"));
        BCOtherDeviceControlDlg->resize(369, 494);
        BCOtherDeviceControlDlg->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(BCOtherDeviceControlDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BCOtherDeviceControlDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(293, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pDisplayOnBtn = new QToolButton(groupBox);
        m_pDisplayOnBtn->setObjectName(QStringLiteral("m_pDisplayOnBtn"));
        m_pDisplayOnBtn->setMinimumSize(QSize(50, 50));
        m_pDisplayOnBtn->setMaximumSize(QSize(50, 50));
        m_pDisplayOnBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pDisplayOnBtn);

        m_pDisplayOffBtn = new QToolButton(groupBox);
        m_pDisplayOffBtn->setObjectName(QStringLiteral("m_pDisplayOffBtn"));
        m_pDisplayOffBtn->setMinimumSize(QSize(50, 50));
        m_pDisplayOffBtn->setMaximumSize(QSize(50, 50));
        m_pDisplayOffBtn->setAutoRaise(true);

        horizontalLayout->addWidget(m_pDisplayOffBtn);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BCOtherDeviceControlDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 80));
        groupBox_2->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(293, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        m_pLightingOnBtn = new QToolButton(groupBox_2);
        m_pLightingOnBtn->setObjectName(QStringLiteral("m_pLightingOnBtn"));
        m_pLightingOnBtn->setMinimumSize(QSize(50, 50));
        m_pLightingOnBtn->setMaximumSize(QSize(50, 50));
        m_pLightingOnBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(m_pLightingOnBtn);

        m_pLightingOffBtn = new QToolButton(groupBox_2);
        m_pLightingOffBtn->setObjectName(QStringLiteral("m_pLightingOffBtn"));
        m_pLightingOffBtn->setMinimumSize(QSize(50, 50));
        m_pLightingOffBtn->setMaximumSize(QSize(50, 50));
        m_pLightingOffBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(m_pLightingOffBtn);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(BCOtherDeviceControlDlg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 80));
        groupBox_3->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(237, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        m_pAudioPlusBtn = new QToolButton(groupBox_3);
        m_pAudioPlusBtn->setObjectName(QStringLiteral("m_pAudioPlusBtn"));
        m_pAudioPlusBtn->setMinimumSize(QSize(50, 50));
        m_pAudioPlusBtn->setMaximumSize(QSize(50, 50));
        m_pAudioPlusBtn->setAutoRaise(true);

        horizontalLayout_3->addWidget(m_pAudioPlusBtn);

        m_pAudioReduceBtn = new QToolButton(groupBox_3);
        m_pAudioReduceBtn->setObjectName(QStringLiteral("m_pAudioReduceBtn"));
        m_pAudioReduceBtn->setMinimumSize(QSize(50, 50));
        m_pAudioReduceBtn->setMaximumSize(QSize(50, 50));
        m_pAudioReduceBtn->setAutoRaise(true);

        horizontalLayout_3->addWidget(m_pAudioReduceBtn);

        m_pAudioSilenceBtn = new QToolButton(groupBox_3);
        m_pAudioSilenceBtn->setObjectName(QStringLiteral("m_pAudioSilenceBtn"));
        m_pAudioSilenceBtn->setMinimumSize(QSize(50, 50));
        m_pAudioSilenceBtn->setMaximumSize(QSize(50, 50));
        m_pAudioSilenceBtn->setAutoRaise(true);

        horizontalLayout_3->addWidget(m_pAudioSilenceBtn);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(BCOtherDeviceControlDlg);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(50, 50));
        groupBox_4->setFont(font);
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 52, 108));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_pVedioZoomOnBtn = new QToolButton(layoutWidget1);
        m_pVedioZoomOnBtn->setObjectName(QStringLiteral("m_pVedioZoomOnBtn"));
        m_pVedioZoomOnBtn->setMinimumSize(QSize(50, 50));
        m_pVedioZoomOnBtn->setMaximumSize(QSize(50, 50));
        m_pVedioZoomOnBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(m_pVedioZoomOnBtn);

        m_pVedioZoomOffBtn = new QToolButton(layoutWidget1);
        m_pVedioZoomOffBtn->setObjectName(QStringLiteral("m_pVedioZoomOffBtn"));
        m_pVedioZoomOffBtn->setMinimumSize(QSize(50, 50));
        m_pVedioZoomOffBtn->setMaximumSize(QSize(50, 50));
        m_pVedioZoomOffBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(m_pVedioZoomOffBtn);

        layoutWidget2 = new QWidget(groupBox_4);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(90, 30, 52, 108));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_pVedioFocusOnBtn = new QToolButton(layoutWidget2);
        m_pVedioFocusOnBtn->setObjectName(QStringLiteral("m_pVedioFocusOnBtn"));
        m_pVedioFocusOnBtn->setMinimumSize(QSize(50, 50));
        m_pVedioFocusOnBtn->setMaximumSize(QSize(50, 50));
        m_pVedioFocusOnBtn->setAutoRaise(true);

        verticalLayout_3->addWidget(m_pVedioFocusOnBtn);

        m_pVedioFocusOffBtn = new QToolButton(layoutWidget2);
        m_pVedioFocusOffBtn->setObjectName(QStringLiteral("m_pVedioFocusOffBtn"));
        m_pVedioFocusOffBtn->setMinimumSize(QSize(50, 50));
        m_pVedioFocusOffBtn->setMaximumSize(QSize(50, 50));
        m_pVedioFocusOffBtn->setAutoRaise(true);

        verticalLayout_3->addWidget(m_pVedioFocusOffBtn);

        layoutWidget3 = new QWidget(groupBox_4);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(171, 31, 164, 164));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        m_pVedioLeftTopBtn = new QToolButton(layoutWidget3);
        m_pVedioLeftTopBtn->setObjectName(QStringLiteral("m_pVedioLeftTopBtn"));
        m_pVedioLeftTopBtn->setMinimumSize(QSize(50, 50));
        m_pVedioLeftTopBtn->setMaximumSize(QSize(50, 50));
        m_pVedioLeftTopBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioLeftTopBtn, 0, 0, 1, 1);

        m_pVedioTopBtn = new QToolButton(layoutWidget3);
        m_pVedioTopBtn->setObjectName(QStringLiteral("m_pVedioTopBtn"));
        m_pVedioTopBtn->setMinimumSize(QSize(50, 50));
        m_pVedioTopBtn->setMaximumSize(QSize(50, 50));
        m_pVedioTopBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioTopBtn, 0, 1, 1, 1);

        m_pVedioRightTopBtn = new QToolButton(layoutWidget3);
        m_pVedioRightTopBtn->setObjectName(QStringLiteral("m_pVedioRightTopBtn"));
        m_pVedioRightTopBtn->setMinimumSize(QSize(50, 50));
        m_pVedioRightTopBtn->setMaximumSize(QSize(50, 50));
        m_pVedioRightTopBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioRightTopBtn, 0, 2, 1, 1);

        m_pVedioLeftBtn = new QToolButton(layoutWidget3);
        m_pVedioLeftBtn->setObjectName(QStringLiteral("m_pVedioLeftBtn"));
        m_pVedioLeftBtn->setMinimumSize(QSize(50, 50));
        m_pVedioLeftBtn->setMaximumSize(QSize(50, 50));
        m_pVedioLeftBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioLeftBtn, 1, 0, 1, 1);

        m_pVedioStopBtn = new QToolButton(layoutWidget3);
        m_pVedioStopBtn->setObjectName(QStringLiteral("m_pVedioStopBtn"));
        m_pVedioStopBtn->setMinimumSize(QSize(50, 50));
        m_pVedioStopBtn->setMaximumSize(QSize(50, 50));
        m_pVedioStopBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioStopBtn, 1, 1, 1, 1);

        m_pVedioRightBtn = new QToolButton(layoutWidget3);
        m_pVedioRightBtn->setObjectName(QStringLiteral("m_pVedioRightBtn"));
        m_pVedioRightBtn->setMinimumSize(QSize(50, 50));
        m_pVedioRightBtn->setMaximumSize(QSize(50, 50));
        m_pVedioRightBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioRightBtn, 1, 2, 1, 1);

        m_pVedioLeftBottomBtn = new QToolButton(layoutWidget3);
        m_pVedioLeftBottomBtn->setObjectName(QStringLiteral("m_pVedioLeftBottomBtn"));
        m_pVedioLeftBottomBtn->setMinimumSize(QSize(50, 50));
        m_pVedioLeftBottomBtn->setMaximumSize(QSize(50, 50));
        m_pVedioLeftBottomBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioLeftBottomBtn, 2, 0, 1, 1);

        m_pVedioBottomBtn = new QToolButton(layoutWidget3);
        m_pVedioBottomBtn->setObjectName(QStringLiteral("m_pVedioBottomBtn"));
        m_pVedioBottomBtn->setMinimumSize(QSize(50, 50));
        m_pVedioBottomBtn->setMaximumSize(QSize(50, 50));
        m_pVedioBottomBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioBottomBtn, 2, 1, 1, 1);

        m_pVedioRightBottomBtn = new QToolButton(layoutWidget3);
        m_pVedioRightBottomBtn->setObjectName(QStringLiteral("m_pVedioRightBottomBtn"));
        m_pVedioRightBottomBtn->setMinimumSize(QSize(50, 50));
        m_pVedioRightBottomBtn->setMaximumSize(QSize(50, 50));
        m_pVedioRightBottomBtn->setAutoRaise(true);

        gridLayout->addWidget(m_pVedioRightBottomBtn, 2, 2, 1, 1);


        verticalLayout->addWidget(groupBox_4);


        retranslateUi(BCOtherDeviceControlDlg);

        QMetaObject::connectSlotsByName(BCOtherDeviceControlDlg);
    } // setupUi

    void retranslateUi(QDialog *BCOtherDeviceControlDlg)
    {
        BCOtherDeviceControlDlg->setWindowTitle(QApplication::translate("BCOtherDeviceControlDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCOtherDeviceControlDlg", "\346\266\262\346\231\266\345\261\217\345\271\225\345\274\200\345\205\263\346\216\247\345\210\266", Q_NULLPTR));
        m_pDisplayOnBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\274\200", Q_NULLPTR));
        m_pDisplayOffBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\205\263", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCOtherDeviceControlDlg", "\347\201\257\345\205\211\346\216\247\345\210\266\345\231\250", Q_NULLPTR));
        m_pLightingOnBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\274\200", Q_NULLPTR));
        m_pLightingOffBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\205\263", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("BCOtherDeviceControlDlg", "\351\237\263\347\256\261\351\237\263\351\207\217\346\216\247\345\210\266", Q_NULLPTR));
        m_pAudioPlusBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\244\247", Q_NULLPTR));
        m_pAudioReduceBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\260\217", Q_NULLPTR));
        m_pAudioSilenceBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\351\235\231", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("BCOtherDeviceControlDlg", "SONY\344\274\232\350\256\256\347\263\273\347\273\237\347\220\203\346\234\272\346\216\247\345\210\266", Q_NULLPTR));
        m_pVedioZoomOnBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\346\224\276\345\244\247", Q_NULLPTR));
        m_pVedioZoomOffBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\347\274\251\345\260\217", Q_NULLPTR));
        m_pVedioFocusOnBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\350\201\232\347\204\246", Q_NULLPTR));
        m_pVedioFocusOffBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\346\225\243\347\204\246", Q_NULLPTR));
        m_pVedioLeftTopBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\267\246\344\270\212", Q_NULLPTR));
        m_pVedioTopBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\344\270\212", Q_NULLPTR));
        m_pVedioRightTopBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\217\263\344\270\212", Q_NULLPTR));
        m_pVedioLeftBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\267\246", Q_NULLPTR));
        m_pVedioStopBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\201\234", Q_NULLPTR));
        m_pVedioRightBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\217\263", Q_NULLPTR));
        m_pVedioLeftBottomBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\267\246\344\270\213", Q_NULLPTR));
        m_pVedioBottomBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\344\270\213", Q_NULLPTR));
        m_pVedioRightBottomBtn->setText(QApplication::translate("BCOtherDeviceControlDlg", "\345\217\263\344\270\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCOtherDeviceControlDlg: public Ui_BCOtherDeviceControlDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCOTHERDEVICECONTROLDLG_H
