#include <iostream>
#include <QCoreApplication>
#include "backdb.h"
#include "chartspline.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    ChartSpline a;
    MainWindow main;
    main.setWindowTitle("MainWindow");
    main.show();
//    a.show();

    return app.exec();

}


//int main(int argc, char *argv[])
//{
//    QCoreApplication app(argc, argv);

//    BackDB test;


//        test.showQuery("SELECT YEAR(timestamp) AS year,\
//       AVG((high + low) / 2) AS mean_value FROM stock_data_monthly \
//WHERE CompanyName = 'IBM'AND MONTH(timestamp) = 12 \
//GROUP BY YEAR(timestamp) ORDER BY year;");


//    return     app.exec();

//}


