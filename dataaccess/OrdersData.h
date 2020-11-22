#pragma once
#ifndef OrderData_h
#define OrderData_h


#include <vector>
#include <string>
#include "../businessobjects/Orders.h"

using json = nlohmann::json;
using namespace std;

class OrdersData
{

public:
    int IDMax;

private:
    vector<Orders> dataVector;

public:
    OrdersData();
    OrdersData(string);

    int pushBack(Orders);
    int update(int, Orders);
    Orders get(int);
    Orders* getP(int);
    int getSize();
    int exportToFile(string);

};

#endif // !OrderData_h

