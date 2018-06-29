/********************************************************************************
** Form generated from reading UI file 'BCAutoDateDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCAUTODATEDLG_H
#define UI_BCAUTODATEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BCAutoDateDlg
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_down;
    QPushButton *pushButton_2;
    QPushButton *pushButton_exit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_version;
    QLabel *label_size;
    QLabel *label_3;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *BCAutoDateDlg)
    {
        if (BCAutoDateDlg->objectName().isEmpty())
            BCAutoDateDlg->setObjectName(QStringLiteral("BCAutoDateDlg"));
        BCAutoDateDlg->resize(352, 145);
        gridLayout_2 = new QGridLayout(BCAutoDateDlg);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_down = new QPushButton(BCAutoDateDlg);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_down->sizePolicy().hasHeightForWidth());
        pushButton_down->setSizePolicy(sizePolicy);
        pushButton_down->setMaximumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(pushButton_down);

        pushButton_2 = new QPushButton(BCAutoDateDlg);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMaximumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_exit = new QPushButton(BCAutoDateDlg);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        sizePolicy.setHeightForWidth(pushButton_exit->sizePolicy().hasHeightForWidth());
        pushButton_exit->setSizePolicy(sizePolicy);
        pushButton_exit->setMaximumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(pushButton_exit);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        groupBox = new QGroupBox(BCAutoDateDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_version = new QLabel(groupBox);
        label_version->setObjectName(QStringLiteral("label_version"));
        label_version->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_version, 0, 1, 1, 1);

        label_size = new QLabel(groupBox);
        label_size->setObjectName(QStringLiteral("label_size"));
        label_size->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_size, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_3->addWidget(progressBar, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(BCAutoDateDlg);

        QMetaObject::connectSlotsByName(BCAutoDateDlg);
    } // setupUi

    void retranslateUi(QDialog *BCAutoDateDlg)
    {
        BCAutoDateDlg->setWindowTitle(QApplication::translate("BCAutoDateDlg", "\350\275\257\344\273\266\346\233\264\346\226\260", Q_NULLPTR));
        pushButton_down->setText(QApplication::translate("BCAutoDateDlg", "\344\270\213\350\275\275", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BCAutoDateDlg", "\346\232\202\345\201\234", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("BCAutoDateDlg", "\351\200\200\345\207\272", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BCAutoDateDlg", "\344\270\213\350\275\275\350\277\233\345\272\246\346\235\241", Q_NULLPTR));
        label->setText(QApplication::translate("BCAutoDateDlg", "\345\275\223\345\211\215\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        label_version->setText(QApplication::translate("BCAutoDateDlg", "\347\211\210\346\234\254\345\217\267", Q_NULLPTR));
        label_size->setText(QApplication::translate("BCAutoDateDlg", "size", Q_NULLPTR));
        label_3->setText(QApplication::translate("BCAutoDateDlg", "\345\275\223\345\211\215\344\270\213\350\275\275\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCAutoDateDlg: public Ui_BCAutoDateDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCAUTODATEDLG_H
