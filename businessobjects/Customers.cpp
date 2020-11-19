#include "Customers.h"

using namespace std;

Customers::Customers(){
	
}
Customers::Customers(int CustomerID, string CustomerName, string ContactName, string Address, string City, string PostalCode, string Country){
	this->CustomerID = CustomerID;
	this->CustomerName = CustomerName;
	this->ContactName = ContactName;
	this->Address = Address;
	this->City = City;
	this->PostalCode = PostalCode;
	this->Country = Country;
}