/********************************************************************************
** Form generated from reading UI file 'BCVideoControl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCVIDEOCONTROL_H
#define UI_BCVIDEOCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCVideoControl
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_divIP;
    QLineEdit *lineEdit_divName;
    QLineEdit *lineEdit_divUser;
    QLabel *label_5;
    QLineEdit *lineEdit_divPort;
    QLineEdit *lineEdit_divPasswd;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;

    void setupUi(QWidget *BCVideoControl)
    {
        if (BCVideoControl->objectName().isEmpty())
            BCVideoControl->setObjectName(QStringLiteral("BCVideoControl"));
        BCVideoControl->resize(279, 380);
        verticalLayout_2 = new QVBoxLayout(BCVideoControl);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        frame = new QFrame(BCVideoControl);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 6, 2, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 5, 2, 1, 1);

        lineEdit_divIP = new QLineEdit(frame);
        lineEdit_divIP->setObjectName(QStringLiteral("lineEdit_divIP"));
        lineEdit_divIP->setFont(font);

        gridLayout->addWidget(lineEdit_divIP, 1, 2, 1, 1);

        lineEdit_divName = new QLineEdit(frame);
        lineEdit_divName->setObjectName(QStringLiteral("lineEdit_divName"));
        lineEdit_divName->setFont(font);

        gridLayout->addWidget(lineEdit_divName, 0, 2, 1, 1);

        lineEdit_divUser = new QLineEdit(frame);
        lineEdit_divUser->setObjectName(QStringLiteral("lineEdit_divUser"));
        lineEdit_divUser->setFont(font);

        gridLayout->addWidget(lineEdit_divUser, 3, 2, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        lineEdit_divPort = new QLineEdit(frame);
        lineEdit_divPort->setObjectName(QStringLiteral("lineEdit_divPort"));
        lineEdit_divPort->setFont(font);

        gridLayout->addWidget(lineEdit_divPort, 2, 2, 1, 1);

        lineEdit_divPasswd = new QLineEdit(frame);
        lineEdit_divPasswd->setObjectName(QStringLiteral("lineEdit_divPasswd"));
        lineEdit_divPasswd->setFont(font);

        gridLayout->addWidget(lineEdit_divPasswd, 4, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 2, 1, 1);


        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(BCVideoControl);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(0, 100));

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);


        verticalLayout_2->addWidget(frame_2);

        QWidget::setTabOrder(lineEdit_divName, lineEdit_divIP);
        QWidget::setTabOrder(lineEdit_divIP, lineEdit_divPort);
        QWidget::setTabOrder(lineEdit_divPort, lineEdit_divUser);
        QWidget::setTabOrder(lineEdit_divUser, lineEdit_divPasswd);
        QWidget::setTabOrder(lineEdit_divPasswd, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, listWidget);

        retranslateUi(BCVideoControl);

        QMetaObject::connectSlotsByName(BCVideoControl);
    } // setupUi

    void retranslateUi(QWidget *BCVideoControl)
    {
        BCVideoControl->setWindowTitle(QApplication::translate("BCVideoControl", "Form", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BCVideoControl", "\350\277\224\345\233\236", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BCVideoControl", "\344\277\235\345\255\230", Q_NULLPTR));
        label_5->setText(QApplication::translate("BCVideoControl", "\345\257\206\347\240\201:", Q_NULLPTR));
        label->setText(QApplication::translate("BCVideoControl", "\345\220\215\347\247\260:", Q_NULLPTR));
        label_4->setText(QApplication::translate("BCVideoControl", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCVideoControl", "\347\253\257\345\217\243\345\217\267:", Q_NULLPTR));
        label_2->setText(QApplication::translate("BCVideoControl", "IP\345\234\260\345\235\200:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCVideoControl: public Ui_BCVideoControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCVIDEOCONTROL_H
