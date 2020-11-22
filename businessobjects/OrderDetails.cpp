#include "OrderDetails.h"

OrderDetails::OrderDetails() {

}

OrderDetails::OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity) {
	this->OrderDetailID = OrderDetailID;
	this->OrderID = OrderID;
	this->ProductID = ProductID;
	this->Quantity = Quantity;
}

string OrderDetails::toString() {
	string s;

	s += to_string(OrderDetailID) + ", ";
	s += to_string(OrderID) + ", ";
	s += to_string(ProductID) + ", ";
	s += to_string(Quantity);

	return s;
}


json OrderDetails::toJson() {
	json j;

	j["ProductID"] = OrderDetailID;
	j["ProductName"] = OrderID;
	j["SupplyID"] = ProductID;
	j["CategoryID"] = Quantity;

	return j;
}
