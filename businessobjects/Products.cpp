#include "Products.h"

Products::Products() {
}

Products::Products(int ProductID, string ProductName, int SupplyID, int CategoryID, int Unit, double Price) {
	this->ProductID = ProductID;
	this->ProductName = ProductName;
	this->SupplyID = SupplyID;
	this->CategoryID = CategoryID;
	this->Unit = Unit;
	this->Price = Price;
}

string Products::toString() {
	string s;
	
	s += to_string(ProductID) + ", ";
	s += ProductName + ", ";
	s += to_string(SupplyID) + ", ";
	s += to_string(CategoryID) + ", ";
	s += to_string(Unit) + ", ";
	s += to_string(Price);

	return s;
}


json Products::toJson() {
	json j;

	j["ProductID"] = ProductID;
	j["ProductName"] = ProductName;
	j["SupplyID"] = SupplyID;
	j["CategoryID"] = CategoryID;
	j["Unit"] = Unit;
	j["Price"] = Price;

	return j;
}
