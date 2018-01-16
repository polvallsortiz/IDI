/********************************************************************************
** Form generated from reading UI file 'myform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QDial *dial;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(671, 549);
        verticalLayout_4 = new QVBoxLayout(MyForm);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(MyForm);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_2->addWidget(spinBox);

        dial = new QDial(MyForm);
        dial->setObjectName(QStringLiteral("dial"));

        horizontalLayout_2->addWidget(dial);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color:#0F0"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color:#00f"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(MyForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color:#f00"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lcdNumber = new QLCDNumber(MyForm);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setStyleSheet(QStringLiteral("background-color:#0F0;color:#fff"));
        lcdNumber->setDigitCount(10);
        lcdNumber->setMode(QLCDNumber::Bin);

        verticalLayout->addWidget(lcdNumber);

        lcdNumber_2 = new QLCDNumber(MyForm);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setStyleSheet(QStringLiteral("background-color:#00F;color:#fff"));
        lcdNumber_2->setDigitCount(10);
        lcdNumber_2->setMode(QLCDNumber::Oct);

        verticalLayout->addWidget(lcdNumber_2);

        lcdNumber_3 = new QLCDNumber(MyForm);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setStyleSheet(QStringLiteral("background-color:#f00;color:#fff"));
        lcdNumber_3->setDigitCount(10);
        lcdNumber_3->setMode(QLCDNumber::Hex);

        verticalLayout->addWidget(lcdNumber_3);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(MyForm);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("MyForm", "Binari", Q_NULLPTR));
        label_2->setText(QApplication::translate("MyForm", "Octal", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyForm", "Hexadecimal", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyForm", "Surt", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
