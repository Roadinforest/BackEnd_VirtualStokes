/********************************************************************************
** Form generated from reading UI file 'chartspline.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTSPLINE_H
#define UI_CHARTSPLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartSpline
{
public:
    QPushButton *QuitSpline;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *ChartSpline)
    {
        if (ChartSpline->objectName().isEmpty())
            ChartSpline->setObjectName("ChartSpline");
        ChartSpline->resize(727, 516);
        QuitSpline = new QPushButton(ChartSpline);
        QuitSpline->setObjectName("QuitSpline");
        QuitSpline->setGeometry(QRect(220, 420, 211, 31));
        horizontalLayoutWidget = new QWidget(ChartSpline);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(110, 100, 451, 251));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(ChartSpline);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 25, 151, 51));

        retranslateUi(ChartSpline);

        QMetaObject::connectSlotsByName(ChartSpline);
    } // setupUi

    void retranslateUi(QWidget *ChartSpline)
    {
        ChartSpline->setWindowTitle(QCoreApplication::translate("ChartSpline", "Form", nullptr));
        QuitSpline->setText(QCoreApplication::translate("ChartSpline", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("ChartSpline", "Helloworld", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartSpline: public Ui_ChartSpline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTSPLINE_H
