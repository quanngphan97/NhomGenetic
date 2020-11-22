#pragma once

/*
* -----NGUYEN THANH TRA-----
*
* FileName: Products.h
* Function:
*
*
*/
#ifndef _Products_h
#define _Products_h

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
*	-ProductID
*	-ProductName
*	-SupplyID
*	-CategoryID
*	-Unit
*	-Price
*
* Have 2 constructions of OrderDetails:
*	-Products() -> Default construction
*	-Products(int ProductID, string ProductName, int SupplyID, int CategoryID, int Unit, double Price) -> Construction with 6 properties of Products.
*
* Have 2 methods of Products:
*	-toString() -> Convert Products properties to string type
*	-json toJson()	-> Convert Products properties to json type
*/
class Products
{

public:
	int ProductID;
	string ProductName;
	int SupplyID;
	int CategoryID;
	int Unit;
	double Price;

	Products();
	Products(int ProductID, string ProductName, int SupplyID, int CategoryID, int Unit, double Price);

	string toString();
	json toJson();
	
};

#endif // !_Product_h




