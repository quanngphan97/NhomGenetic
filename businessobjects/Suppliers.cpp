#include "Suppliers.h"
using namespace std;
Suppliers::Suppliers()
{
}
Suppliers::Suppliers(int SupplierID,string SupplierName,string Address,string City,string PostalCode,string Phone)
{
	this->SupplierID = SupplierID;
	this->SupplierName  = SupplierName;
	this->Address = Address;
	this-> City  =  City;
	this->PostalCode=PostalCode;
	this->Phone=Phone;
}
