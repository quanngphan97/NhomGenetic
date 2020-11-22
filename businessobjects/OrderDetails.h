#pragma once
/*
* -----NGUYEN THANH TRA-----
* 
* FileName: OrderDetails.h
* Function:
* 
* 
*/

#ifndef _OrderDetails_h
#define _OrderDetails_h

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
*	-OrderDetailID
*	-OrderID
*	-ProductID
*	-Quantity
* 
* Have 2 constructions of OrderDetails:
*	-OrderDetails() -> Default construction
*	-OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity) -> Construction with 4 properties of OrderDetails.
* 
* Have 2 methods of OrderDetails:
*	-toString() -> Convert OrderDetails properties to string type
*	-json toJson()	-> Convert OrderDetails properties to json type
*/
class OrderDetails
{
public:
	int OrderDetailID;
	int OrderID;
	int ProductID;
	int Quantity;

	OrderDetails();
	OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity);

	string toString();
	json toJson();
};


#endif // !_OrderDetails_h


