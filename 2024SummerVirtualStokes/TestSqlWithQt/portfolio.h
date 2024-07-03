#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include<QString>
#include<string>
#include<map>
#include"stock.h"
using namespace std;

//投资管理类
class Portfolio {

private:
    std::map<int, int> holdings; // Map of stock symbol to quantity
    //即第一个int(key)代表公司/股票id，第二个代表持有数量

public:
    Portfolio();

    void addStock(Stock& stock, int quantity);

    void removeStock(Stock& stock, int quantity);

    std::map<int, int> getHoldings();

    double getTotalValue();

};

#endif // PORTFOLIO_H
