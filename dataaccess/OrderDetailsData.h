#pragma once

/*
* -----NGUYEN THANH TRA-----
*
* FileName: OrderDetailData.h
* Function:
*
*
*/

#ifndef _OrderDetailsData_h
#define _OrderDetailsData_h

/*
* include string to use string type and functions
* include vector  to use vector and vector function
* include OrderDetails.h to create OrderDetails.h objects and OrderDetails.h object features
*/
#include <vector>
#include <string>
#include "../businessobjects/OrderDetails.h"

/*
* using name space std to do something
* using json functions
*/
using json = nlohmann::json;
using namespace std;

/*
* Create OrderDetailsData class to save OrderDetails Object and handle OrderDetail Objects:
*	-int IDMax: to sava the ID Max of all OrderDetail Objects
*	-vector<OrderDetails> dataVector: to save all OrderDetail Objects to vector dataVector
*
* Have 2 constructions of OrderDetails:
*	-OrderDetailsData() -> Default construction
*	-OrderDetailsData(string) -> Construction with 1 properties of OrderDetailsData (FileName to save OrderDetails Object)
*
* Have 6 methods of OrderDetailsData:
*	-int pushBack(OrderDetails): to add OrderDetails Object to OrderDetailsData Vector
    -int update(int, OrderDetails): to Update OrderDetails Object to OrderDetailsData Vector
    -OrderDetails get(int): to get OrderDetails Object from OrderDetailsData Vector
    -OrderDetails* getP(int): to get OrderDetails Object (Pointer) from OrderDetailsData Vector
    -int getSize(): to get size of OrderDetailsData Vector
    -int exportToFile(string): to Export OrderDetailsData Vector to fileName (string type)
*/
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
    int getLastId();
};

#endif // !_OrderDetailsData_h




