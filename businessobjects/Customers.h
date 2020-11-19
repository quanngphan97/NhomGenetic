#ifndef _Customers_H
#define _Customers_H

#include <string>

using namespace std;

class Customers{
protected:
	int CustomerID;
	string CustomerName, ContactName, Address, City, PostalCode, Country;
public:
	Customers();
	Customers(int CustomerID, string CustomerName, string ContactName, string Address, string City, string PostalCode, string Country);
};

#endif
