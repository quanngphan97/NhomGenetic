#pragma once

#ifndef _OrderDetails_h
#define _OrderDetails_h

#include <string>	//used for string
#include <iostream>
#include <vector>
#include <fstream>	//used for filestream

#include "Products.h"
#include "./libs/json.hpp"

using namespace std;	//using std namespace
using json = nlohmann::json;

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


