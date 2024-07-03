#include "portfolio.h"

//---------------------投资管理类Portfolio------------------------
Portfolio::Portfolio()
{

}

void Portfolio::addStock(Stock& stock, int quantity){
    //功能待实现
    //用户买入该股票，并且进入用户名下
}

void Portfolio::removeStock(Stock& stock, int quantity){
    //功能待实现
    //用户卖出股票，名下股票相应删去
}

std::map<int, int> Portfolio::getHoldings(){
    return this->holdings;
}

double Portfolio::getTotalValue(){
    double d;
    //功能待实现
    //已声明变量可调整
    //计算出用户当前持有股票总价？股票具体内涵交给你们来，大概这个意思。
    return d;
}
