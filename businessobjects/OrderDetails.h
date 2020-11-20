#pragma once

#ifndef _OrderDetails_h
#define _OrderDetails_h

#include <string>
#include <iostream>

using namespace std;

class OrderDetails
{
public:
	int OrderDetailID;
	int OrderID;
	int ProductID;
	int Quantity;

	OrderDetails();
	OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity);

};


#endif // !_OrderDetails_h


