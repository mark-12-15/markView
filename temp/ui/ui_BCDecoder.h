/********************************************************************************
** Form generated from reading UI file 'BCDecoder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCDECODER_H
#define UI_BCDECODER_H

#include <BCDecoderTreeWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCDecoder
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_pFilterLineEdit;
    QPushButton *m_pSelectFileBtn;
    QPushButton *m_pExportBtn;
    BCDecoderTreeWidget *m_pDecoderTreeWidget;

    void setupUi(QWidget *BCDecoder)
    {
        if (BCDecoder->objectName().isEmpty())
            BCDecoder->setObjectName(QStringLiteral("BCDecoder"));
        BCDecoder->resize(255, 290);
        gridLayout = new QGridLayout(BCDecoder);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frame = new QFrame(BCDecoder);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_pFilterLineEdit = new QLineEdit(frame);
        m_pFilterLineEdit->setObjectName(QStringLiteral("m_pFilterLineEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_pFilterLineEdit->setFont(font);

        horizontalLayout->addWidget(m_pFilterLineEdit);

        m_pSelectFileBtn = new QPushButton(frame);
        m_pSelectFileBtn->setObjectName(QStringLiteral("m_pSelectFileBtn"));
        m_pSelectFileBtn->setFont(font);

        horizontalLayout->addWidget(m_pSelectFileBtn);

        m_pExportBtn = new QPushButton(frame);
        m_pExportBtn->setObjectName(QStringLiteral("m_pExportBtn"));
        m_pExportBtn->setFont(font);

        horizontalLayout->addWidget(m_pExportBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        m_pDecoderTreeWidget = new BCDecoderTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pDecoderTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pDecoderTreeWidget->setObjectName(QStringLiteral("m_pDecoderTreeWidget"));
        m_pDecoderTreeWidget->setFont(font);

        verticalLayout_2->addWidget(m_pDecoderTreeWidget);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BCDecoder);

        QMetaObject::connectSlotsByName(BCDecoder);
    } // setupUi

    void retranslateUi(QWidget *BCDecoder)
    {
        BCDecoder->setWindowTitle(QApplication::translate("BCDecoder", "Form", Q_NULLPTR));
        m_pSelectFileBtn->setText(QApplication::translate("BCDecoder", "\345\257\274\345\205\245", Q_NULLPTR));
        m_pExportBtn->setText(QApplication::translate("BCDecoder", "\345\257\274\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCDecoder: public Ui_BCDecoder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCDECODER_H
