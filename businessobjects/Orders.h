#pragma once


#ifndef _Oders_h
#define _Oders_h

#include <string>	//used for string
#include <iostream>
#include <vector>
#include <fstream>	//used for filestream

#include "Products.h"
#include "./libs/json.hpp"

using namespace std;	//using std namespace
using json = nlohmann::json;

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


