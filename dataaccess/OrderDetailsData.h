#pragma once
#ifndef _OrderDetailsData_h
#define _OrderDetailsData_h

#include <vector>
#include <string>
#include "OrderDetails.h"

using json = nlohmann::json;
using namespace std;

class OrderDetailsData
{

public:
    int IDMax;

private:
    vector<OrderDetails> dataVector;

public:
    OrderDetailsData();
    OrderDetailsData(string);

    int pushBack(OrderDetails);
    int update(int, OrderDetails);
    OrderDetails get(int);
    OrderDetails* getP(int);
    int getSize();
    int exportToFile(string);

};

#endif // !_OrderDetailsData_h




