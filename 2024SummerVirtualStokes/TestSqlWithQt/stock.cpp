#include "stock.h"

//---------------股票类Stock-----------------
//构造函数和接口，接口返回private成员即可
Stock::Stock(double _price,int _companyId,long _volume, int _year, int _month){
    Stock::singlePrice = _price;
    Stock::companyId = _companyId;
    Stock::volume = _volume;
    Stock::year = _year;
    Stock::month = _month;
}

Stock::Stock()
{
    singlePrice=100.0;
    companyId=12;
    volume=199;
    year=2004;
    month=12;
}

double Stock:: GetSinglePrice()const{
    return Stock::singlePrice;
}

int Stock:: GetCompanyId(){
    return Stock::companyId;
}

long Stock:: GetVolumn(){
    return Stock::volume;
}

int Stock:: GetYear(){
    return Stock::year;
}

int Stock::GetMonth(){
    return Stock::month;
}
