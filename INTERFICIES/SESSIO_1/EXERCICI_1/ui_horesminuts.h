/********************************************************************************
** Form generated from reading UI file 'horesminuts.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HORESMINUTS_H
#define UI_HORESMINUTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoresMinuts
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QDial *dial;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QDial *dial_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *HoresMinuts)
    {
        if (HoresMinuts->objectName().isEmpty())
            HoresMinuts->setObjectName(QString::fromUtf8("HoresMinuts"));
        HoresMinuts->resize(400, 300);
        horizontalLayout_3 = new QHBoxLayout(HoresMinuts);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(HoresMinuts);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(HoresMinuts);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        verticalLayout->addWidget(lcdNumber);

        dial = new QDial(HoresMinuts);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMaximum(23);

        verticalLayout->addWidget(dial);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(HoresMinuts);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lcdNumber_2 = new QLCDNumber(HoresMinuts);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        verticalLayout_2->addWidget(lcdNumber_2);

        dial_2 = new QDial(HoresMinuts);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setMaximum(59);

        verticalLayout_2->addWidget(dial_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(HoresMinuts);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);


        retranslateUi(HoresMinuts);
        QObject::connect(dial_2, SIGNAL(sliderMoved(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), HoresMinuts, SLOT(close()));

        QMetaObject::connectSlotsByName(HoresMinuts);
    } // setupUi

    void retranslateUi(QWidget *HoresMinuts)
    {
        HoresMinuts->setWindowTitle(QApplication::translate("HoresMinuts", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HoresMinuts", "Hores", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HoresMinuts", "Minuts", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("HoresMinuts", "Tancar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HoresMinuts: public Ui_HoresMinuts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HORESMINUTS_H
