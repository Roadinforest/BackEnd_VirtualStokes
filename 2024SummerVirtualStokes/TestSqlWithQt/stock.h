#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include<string>
#include<map>
using namespace std;

class Stock{
private:
    double singlePrice;     //单支价格
    int companyId;          //公司id
    long volume;            //股票容量
    int year;               //年份
    int month;              //月份

public:
    Stock(double _price,int _companyId,long _volume, int year, int month);//constuctor

    Stock();

    double GetSinglePrice()const;

    int GetCompanyId();

    long GetVolumn();

    int GetYear();

    int GetMonth();
};

#endif // STOCK_H
