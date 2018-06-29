/********************************************************************************
** Form generated from reading UI file 'BCSettingCameraWidgetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSETTINGCAMERAWIDGETDLG_H
#define UI_BCSETTINGCAMERAWIDGETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCSettingCameraWidgetDlg
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *widget_left;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_CameraNames;
    QPushButton *pushButton_CameraLink;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QTreeWidget *treeWidgetChannelsrc;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit_start;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_stop;
    QPushButton *pushButton_VideoSelect;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QTreeWidget *treeWidgetVideoFile;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    QGridLayout *gridLayout_6;
    QToolButton *toolButton_leftUP;
    QToolButton *toolButton_up;
    QToolButton *toolButton_rightUp;
    QToolButton *toolButton_left;
    QToolButton *toolButton_stop;
    QToolButton *toolButton_right;
    QToolButton *toolButton_leftDown;
    QToolButton *toolButton_Down;
    QToolButton *toolButton_rightDown;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QToolButton *toolButton_ZoomIn;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButton_ZoomOut;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_riget;
    QGridLayout *gridLayout_8;
    QWidget *widget_rightChild;
    QGridLayout *gridLayout_9;

    void setupUi(QDialog *BCSettingCameraWidgetDlg)
    {
        if (BCSettingCameraWidgetDlg->objectName().isEmpty())
            BCSettingCameraWidgetDlg->setObjectName(QStringLiteral("BCSettingCameraWidgetDlg"));
        BCSettingCameraWidgetDlg->resize(1710, 958);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        BCSettingCameraWidgetDlg->setFont(font);
        gridLayout = new QGridLayout(BCSettingCameraWidgetDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(BCSettingCameraWidgetDlg);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_left = new QWidget(splitter);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        widget_left->setMinimumSize(QSize(350, 0));
        widget_left->setMaximumSize(QSize(300, 16777215));
        gridLayout_7 = new QGridLayout(widget_left);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 9);
        groupBox_3 = new QGroupBox(widget_left);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        treeWidget = new QTreeWidget(groupBox_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("\351\242\204\350\247\210\346\250\241\345\274\217"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout_2->addWidget(treeWidget, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(widget_left);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox_CameraNames = new QComboBox(groupBox_4);
        comboBox_CameraNames->setObjectName(QStringLiteral("comboBox_CameraNames"));

        horizontalLayout_2->addWidget(comboBox_CameraNames);

        pushButton_CameraLink = new QPushButton(groupBox_4);
        pushButton_CameraLink->setObjectName(QStringLiteral("pushButton_CameraLink"));
        pushButton_CameraLink->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(pushButton_CameraLink);


        gridLayout_7->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox = new QGroupBox(widget_left);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 180));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        treeWidgetChannelsrc = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("\350\276\223\345\205\245\346\272\220"));
        treeWidgetChannelsrc->setHeaderItem(__qtreewidgetitem1);
        treeWidgetChannelsrc->setObjectName(QStringLiteral("treeWidgetChannelsrc"));

        gridLayout_3->addWidget(treeWidgetChannelsrc, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget_left);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_4 = new QWidget(groupBox_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_5 = new QGridLayout(widget_4);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label = new QLabel(widget_4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        dateTimeEdit_start = new QDateTimeEdit(widget_4);
        dateTimeEdit_start->setObjectName(QStringLiteral("dateTimeEdit_start"));

        gridLayout_5->addWidget(dateTimeEdit_start, 0, 1, 1, 1);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        dateTimeEdit_stop = new QDateTimeEdit(widget_4);
        dateTimeEdit_stop->setObjectName(QStringLiteral("dateTimeEdit_stop"));

        gridLayout_5->addWidget(dateTimeEdit_stop, 1, 1, 1, 1);

        pushButton_VideoSelect = new QPushButton(widget_4);
        pushButton_VideoSelect->setObjectName(QStringLiteral("pushButton_VideoSelect"));

        gridLayout_5->addWidget(pushButton_VideoSelect, 1, 2, 1, 1);


        verticalLayout->addWidget(widget_4);

        widget_3 = new QWidget(groupBox_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        treeWidgetVideoFile = new QTreeWidget(widget_3);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QString::fromUtf8("\345\275\225\345\203\217\346\226\207\344\273\266"));
        treeWidgetVideoFile->setHeaderItem(__qtreewidgetitem2);
        treeWidgetVideoFile->setObjectName(QStringLiteral("treeWidgetVideoFile"));

        gridLayout_4->addWidget(treeWidgetVideoFile, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_3);


        gridLayout_7->addWidget(groupBox_2, 3, 0, 1, 1);

        groupBox_5 = new QGroupBox(widget_left);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout = new QHBoxLayout(groupBox_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_5 = new QWidget(groupBox_5);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_6 = new QGridLayout(widget_5);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        toolButton_leftUP = new QToolButton(widget_5);
        toolButton_leftUP->setObjectName(QStringLiteral("toolButton_leftUP"));
        toolButton_leftUP->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_leftUP, 0, 0, 1, 1);

        toolButton_up = new QToolButton(widget_5);
        toolButton_up->setObjectName(QStringLiteral("toolButton_up"));
        toolButton_up->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_up, 0, 1, 1, 1);

        toolButton_rightUp = new QToolButton(widget_5);
        toolButton_rightUp->setObjectName(QStringLiteral("toolButton_rightUp"));
        toolButton_rightUp->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_rightUp, 0, 2, 1, 1);

        toolButton_left = new QToolButton(widget_5);
        toolButton_left->setObjectName(QStringLiteral("toolButton_left"));
        toolButton_left->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_left, 1, 0, 1, 1);

        toolButton_stop = new QToolButton(widget_5);
        toolButton_stop->setObjectName(QStringLiteral("toolButton_stop"));
        toolButton_stop->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_stop, 1, 1, 1, 1);

        toolButton_right = new QToolButton(widget_5);
        toolButton_right->setObjectName(QStringLiteral("toolButton_right"));
        toolButton_right->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_right, 1, 2, 1, 1);

        toolButton_leftDown = new QToolButton(widget_5);
        toolButton_leftDown->setObjectName(QStringLiteral("toolButton_leftDown"));
        toolButton_leftDown->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_leftDown, 2, 0, 1, 1);

        toolButton_Down = new QToolButton(widget_5);
        toolButton_Down->setObjectName(QStringLiteral("toolButton_Down"));
        toolButton_Down->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_Down, 2, 1, 1, 1);

        toolButton_rightDown = new QToolButton(widget_5);
        toolButton_rightDown->setObjectName(QStringLiteral("toolButton_rightDown"));
        toolButton_rightDown->setMinimumSize(QSize(50, 50));

        gridLayout_6->addWidget(toolButton_rightDown, 2, 2, 1, 1);


        horizontalLayout->addWidget(widget_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_6 = new QWidget(groupBox_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        toolButton_ZoomIn = new QToolButton(widget_6);
        toolButton_ZoomIn->setObjectName(QStringLiteral("toolButton_ZoomIn"));
        toolButton_ZoomIn->setMinimumSize(QSize(50, 50));

        verticalLayout_2->addWidget(toolButton_ZoomIn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        toolButton_ZoomOut = new QToolButton(widget_6);
        toolButton_ZoomOut->setObjectName(QStringLiteral("toolButton_ZoomOut"));
        toolButton_ZoomOut->setMinimumSize(QSize(50, 50));

        verticalLayout_2->addWidget(toolButton_ZoomOut);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(widget_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_7->addWidget(groupBox_5, 4, 0, 1, 1);

        splitter->addWidget(widget_left);
        widget_riget = new QWidget(splitter);
        widget_riget->setObjectName(QStringLiteral("widget_riget"));
        gridLayout_8 = new QGridLayout(widget_riget);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        widget_rightChild = new QWidget(widget_riget);
        widget_rightChild->setObjectName(QStringLiteral("widget_rightChild"));
        QFont font1;
        font1.setPointSize(9);
        widget_rightChild->setFont(font1);
        gridLayout_9 = new QGridLayout(widget_rightChild);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));

        gridLayout_8->addWidget(widget_rightChild, 0, 0, 1, 1);

        splitter->addWidget(widget_riget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(BCSettingCameraWidgetDlg);

        QMetaObject::connectSlotsByName(BCSettingCameraWidgetDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSettingCameraWidgetDlg)
    {
        BCSettingCameraWidgetDlg->setWindowTitle(QApplication::translate("BCSettingCameraWidgetDlg", "\347\241\254\347\233\230\345\275\225\345\203\217\346\234\272", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("BCSettingCameraWidgetDlg", "\345\210\206\345\211\262\346\250\241\345\274\217", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("BCSettingCameraWidgetDlg", "\347\224\273\351\235\242-01", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem1->setText(0, QApplication::translate("BCSettingCameraWidgetDlg", "\347\224\273\351\235\242-04", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem2->setText(0, QApplication::translate("BCSettingCameraWidgetDlg", "\347\224\273\351\235\242-09", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem3->setText(0, QApplication::translate("BCSettingCameraWidgetDlg", "\347\224\273\351\235\242-16", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        groupBox_4->setTitle(QApplication::translate("BCSettingCameraWidgetDlg", "\345\275\225\345\203\217\346\234\272", Q_NULLPTR));
        pushButton_CameraLink->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\347\231\273\345\275\225", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCSettingCameraWidgetDlg", "\350\276\223\345\205\245\346\272\220", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BCSettingCameraWidgetDlg", "\345\275\225\345\203\217\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\350\265\267\345\247\213\346\227\266\351\227\264:", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\347\273\223\346\235\237\346\227\266\351\227\264:", Q_NULLPTR));
        pushButton_VideoSelect->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\346\237\245\350\257\242", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("BCSettingCameraWidgetDlg", "\344\272\221\345\217\260\346\216\247\345\210\266", Q_NULLPTR));
        toolButton_leftUP->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\345\267\246\344\270\212", Q_NULLPTR));
        toolButton_up->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\344\270\212", Q_NULLPTR));
        toolButton_rightUp->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\345\217\263\344\270\212", Q_NULLPTR));
        toolButton_left->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\345\267\246", Q_NULLPTR));
        toolButton_stop->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\345\201\234\346\255\242", Q_NULLPTR));
        toolButton_right->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\345\217\263\350\276\271", Q_NULLPTR));
        toolButton_leftDown->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\345\267\246\344\270\213", Q_NULLPTR));
        toolButton_Down->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\344\270\213", Q_NULLPTR));
        toolButton_rightDown->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\345\217\263\344\270\213", Q_NULLPTR));
        toolButton_ZoomIn->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\346\213\211\350\277\221", Q_NULLPTR));
        toolButton_ZoomOut->setText(QApplication::translate("BCSettingCameraWidgetDlg", "\346\216\250\350\277\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSettingCameraWidgetDlg: public Ui_BCSettingCameraWidgetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSETTINGCAMERAWIDGETDLG_H
