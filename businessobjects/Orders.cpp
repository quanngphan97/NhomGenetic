#include "Orders.h"

Orders::Orders() {}

Orders::Orders(int OrderID, int CustomerID, int EmployeeID, string OrderDate, int ShipperID) {
	this->OrderID = OrderID;
	this->CustomerID = CustomerID;
	this->EmployeeID = EmployeeID;
	this->OrderDate = OrderDate;
	this->ShipperID = ShipperID;
}

string Orders::toString() {
	string s;

	s += to_string(OrderID) + ", ";
	s += to_string(CustomerID) + ", ";
	s += to_string(EmployeeID) + ", ";
	s += OrderDate + ", ";
	s += to_string(ShipperID);

	return s;
}


json Orders::toJson() {
	json j;

	j["OrderID"] = OrderID;
	j["CustomerID"] = CustomerID;
	j["EmployeeID"] = EmployeeID;
	j["OrderDate"] = OrderDate;
	j["ShipperID"] = ShipperID;

	return j;
}

