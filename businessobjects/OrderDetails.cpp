/*
* -----NGUYEN_THANH_TRA------
*
* FileName: OrderDetails.cpp
* Function:
*
*
*/


/*
* include OrderDetails.h clarify the constructions and the methods of this library
*/
#include "OrderDetails.h"


/*
* Construction OrderDetails(): Default construction for OrderDetails
* Is used to create a OrderDetails Object
* 
*/
OrderDetails::OrderDetails() {

}

/*
* Construction OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity): OrderDetails construction with 4 Properties
*	-OrderDetails
*	-OrderID
*	-ProductID
*	-Quantity
* 
* Is used to create a OrderDetails Object
*
*/
OrderDetails::OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity) {
	this->OrderDetailID = OrderDetailID;
	this->OrderID = OrderID;
	this->ProductID = ProductID;
	this->Quantity = Quantity;
}

/*
* Method toString(): is used to convert OrderDetails'S propertiesto string type
*/
string OrderDetails::toString() {
	string s;

	s += to_string(OrderDetailID) + ", ";
	s += to_string(OrderID) + ", ";
	s += to_string(ProductID) + ", ";
	s += to_string(Quantity);

	return s;
}

/*
* Method toString(): is used to convert OrderDetails'S propertiesto json type
*/
json OrderDetails::toJson() {
	json j;

	j["OrderDetailID"] = OrderDetailID;
	j["OrderID"] = OrderID;
	j["ProductID"] = ProductID;
	j["Quantity"] = Quantity;

	return j;
}
