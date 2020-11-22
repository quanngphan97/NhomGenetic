#pragma once
/*
* -----NGUYEN THANH TRA-----
*
* FileName: Orders.h
* Function:
*
*
*/

#ifndef _Oders_h
#define _Oders_h

/*
* include string to use string type and functions
* include iostream to use iostream functions: cin, cout.
* include vector  to use vector and vector function
* include fstream  to use file_stream function
* include Products.h to create product objects and product object features
* include json to save object to json type
*/
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../businessobjects/Products.h"
#include "../libs/json.hpp"

/*
* using name space std to do something
* using json functions
*/
using namespace std;
using json = nlohmann::json;

/*
* Create OrderDetails class to save OrderDetails properties:
*	-OrderID
*	-CustomerID
*	-EmployeeID
*	-OrderDate
*	-ShipperID
*
* Have 2 constructions of OrderDetails:
*	-Orders() -> Default construction
*	-Orders(int OrderID, int CustomerID, int EmployeeID, string OrderDate, int ShipperID) -> Construction with 4 properties of Orders.
*
* Have 2 methods of OrderDetails:
*	-toString() -> Convert Orders properties to string type
*	-json toJson()	-> Convert Orders properties to json type
*/
class Orders
{
public:
	int OrderID;
	int CustomerID;
	int EmployeeID;
	string OrderDate;
	int ShipperID;

	Orders();
	Orders(int OrderID, int CustomerID, int EmployeeID, string OrderDate, int ShipperID);

	string toString();
	json toJson();

};

#endif // !_Oders_h


