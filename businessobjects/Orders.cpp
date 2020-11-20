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
	s += ShipperID + ", ";

	return s;
}


json Orders::toJson() {
	json j;

	j["ProductID"] = OrderID;
	j["ProductName"] = CustomerID;
	j["SupplyID"] = EmployeeID;
	j["CategoryID"] = OrderDate;
	j["Unit"] = ShipperID;

	return j;
}

