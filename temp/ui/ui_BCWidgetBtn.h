/********************************************************************************
** Form generated from reading UI file 'BCWidgetBtn.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCWIDGETBTN_H
#define UI_BCWIDGETBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCWidgetBtn
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_left;
    QLabel *label_text;
    QLabel *label_right;

    void setupUi(QWidget *BCWidgetBtn)
    {
        if (BCWidgetBtn->objectName().isEmpty())
            BCWidgetBtn->setObjectName(QStringLiteral("BCWidgetBtn"));
        BCWidgetBtn->resize(240, 30);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BCWidgetBtn->sizePolicy().hasHeightForWidth());
        BCWidgetBtn->setSizePolicy(sizePolicy);
        BCWidgetBtn->setMinimumSize(QSize(0, 30));
        BCWidgetBtn->setMaximumSize(QSize(16777215, 30));
        gridLayout_2 = new QGridLayout(BCWidgetBtn);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(BCWidgetBtn);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 0, 0, 0);
        label_left = new QLabel(frame);
        label_left->setObjectName(QStringLiteral("label_left"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_left->sizePolicy().hasHeightForWidth());
        label_left->setSizePolicy(sizePolicy1);
        label_left->setMaximumSize(QSize(24, 16777215));

        gridLayout->addWidget(label_left, 0, 0, 1, 1);

        label_text = new QLabel(frame);
        label_text->setObjectName(QStringLiteral("label_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_text->setFont(font);

        gridLayout->addWidget(label_text, 0, 1, 1, 1);

        label_right = new QLabel(frame);
        label_right->setObjectName(QStringLiteral("label_right"));
        sizePolicy1.setHeightForWidth(label_right->sizePolicy().hasHeightForWidth());
        label_right->setSizePolicy(sizePolicy1);
        label_right->setMinimumSize(QSize(24, 24));
        label_right->setMaximumSize(QSize(24, 24));

        gridLayout->addWidget(label_right, 0, 2, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(BCWidgetBtn);

        QMetaObject::connectSlotsByName(BCWidgetBtn);
    } // setupUi

    void retranslateUi(QWidget *BCWidgetBtn)
    {
        BCWidgetBtn->setWindowTitle(QApplication::translate("BCWidgetBtn", "Form", Q_NULLPTR));
        label_left->setText(QString());
        label_text->setText(QApplication::translate("BCWidgetBtn", "TextLabel", Q_NULLPTR));
        label_right->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BCWidgetBtn: public Ui_BCWidgetBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCWIDGETBTN_H
