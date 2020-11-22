#pragma once

/*
* -----NGUYEN THANH TRA-----
*
* FileName: OrdersData.h
* Function:
*
*
*/
#ifndef OrderData_h
#define OrderData_h


/*
* include string to use string type and functions
* include vector  to use vector and vector function
* include Orders.h to create Orders.h objects and Orders.h object features
*/
#include <vector>
#include <string>
#include "../businessobjects/Orders.h"


/*
* using name space std to do something
* using json functions
*/
using json = nlohmann::json;
using namespace std;

/*
* Create OrdersData class to save Orders Object and handle Orders Objects:
*	-int IDMax: to sava the ID Max of all Orders Objects in Vector
*	-vector<Orders> dataVector: to save all Orders Objects to vector dataVector
*
* Have 2 constructions of OrderDetails:
*	-OrdersData(); -> Default construction
*	-OrdersData(string) -> Construction with 1 properties of OrdersData (FileName to save Orders Object)
*
* Have 6 methods of OrdersData:
*	-int pushBack(Orders): to add Orders Object to OrdersData Vector
    -int update(int, Orders): to Update Orders Object to OrdersData Vector
    -Orders get(int): to get Orders Object from OrdersData Vector
    -Orders* getP(int): to get Orders Object (Pointer) from OrdersData Vector
    -int getSize(): to get size of OrdersData Vector
    -int exportToFile(string): to Export OrdersData Vector to fileName (string type)
*/
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

