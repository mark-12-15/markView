/********************************************************************************
** Form generated from reading UI file 'BCScene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSCENE_H
#define UI_BCSCENE_H

#include <BCSceneMatrixTreeWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BCScene
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QWidget *m_pNomalWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *m_pSelectAllBtn;
    QLabel *label;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QTabWidget *m_pSceneTabWidget;
    QWidget *tab;
    BCSceneMatrixTreeWidget *m_pMatrixTreeWidget;

    void setupUi(QWidget *BCScene)
    {
        if (BCScene->objectName().isEmpty())
            BCScene->setObjectName(QStringLiteral("BCScene"));
        BCScene->resize(295, 259);
        gridLayout = new QGridLayout(BCScene);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frame = new QFrame(BCScene);
        frame->setObjectName(QStringLiteral("frame"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        frame->setFont(font);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        m_pNomalWidget = new QWidget(frame);
        m_pNomalWidget->setObjectName(QStringLiteral("m_pNomalWidget"));
        verticalLayout_3 = new QVBoxLayout(m_pNomalWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_pSelectAllBtn = new QToolButton(m_pNomalWidget);
        m_pSelectAllBtn->setObjectName(QStringLiteral("m_pSelectAllBtn"));

        horizontalLayout_2->addWidget(m_pSelectAllBtn);

        label = new QLabel(m_pNomalWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        spinBox = new QSpinBox(m_pNomalWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMaximumSize(QSize(16777215, 16777215));
        spinBox->setFont(font);
        spinBox->setMinimum(1);
        spinBox->setMaximum(9999);

        horizontalLayout_2->addWidget(spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        comboBox = new QComboBox(m_pNomalWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 0));
        comboBox->setMaximumSize(QSize(150, 16777215));
        comboBox->setFont(font);

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        m_pSceneTabWidget = new QTabWidget(m_pNomalWidget);
        m_pSceneTabWidget->setObjectName(QStringLiteral("m_pSceneTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        m_pSceneTabWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(m_pSceneTabWidget);


        verticalLayout_4->addWidget(m_pNomalWidget);

        m_pMatrixTreeWidget = new BCSceneMatrixTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_pMatrixTreeWidget->setHeaderItem(__qtreewidgetitem);
        m_pMatrixTreeWidget->setObjectName(QStringLiteral("m_pMatrixTreeWidget"));

        verticalLayout_4->addWidget(m_pMatrixTreeWidget);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BCScene);

        m_pSceneTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BCScene);
    } // setupUi

    void retranslateUi(QWidget *BCScene)
    {
        BCScene->setWindowTitle(QApplication::translate("BCScene", "Form", Q_NULLPTR));
        m_pSelectAllBtn->setText(QApplication::translate("BCScene", "\345\205\250\351\200\211", Q_NULLPTR));
        label->setText(QApplication::translate("BCScene", "\350\275\256\345\267\241\346\227\266\351\227\264", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("BCScene", "\345\210\227\350\241\250", Q_NULLPTR)
         << QApplication::translate("BCScene", "\351\242\204\350\247\210\346\250\241\345\274\217", Q_NULLPTR)
        );
        m_pSceneTabWidget->setTabText(m_pSceneTabWidget->indexOf(tab), QApplication::translate("BCScene", "+", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCScene: public Ui_BCScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSCENE_H
