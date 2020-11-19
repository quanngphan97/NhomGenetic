#ifndef _Suppliers_H
#define _Suppliers_H
#include <iostream>
#include <string>
using namespace std;

class Suppliers
{
		protected:
		int SupplierID;
		string SupplierName;
		string Address;
		string City;
		string PostalCode;
		string Country;
		string Phone;
	public:
		Suppliers();
		Suppliers(int SupplierID,string SupplierName,string Address,string City,string PostalCode,string Phone);
};
#endif
