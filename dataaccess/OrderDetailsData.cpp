/*
* -----NGUYEN THANH TRA-----
*
* FileName: OrderDetails.cpp
* Function:
*
*/

/*
* include OrderDetailsData.h to clarify the constructions and the methods of this library
* include <fstream> to use the fileStream functions 
* include "../libs/json.hpp" to use json functions
*/
#include "OrderDetailsData.h"
#include <fstream>
#include "../libs/json.hpp"

/*
* Constructions OrderDetailsData(): default construction
* Is used to create new OrderDetailsData object
* IDMax = 0: set IDMax = 0 when create new OrderDetailsData (Vector of orderDetails)
* dataVector.resize(0): set 0 for size of new dataVector
* dataVector is a vector and it is used to save dataDetails Objects
*/
OrderDetailsData::OrderDetailsData() {
	IDMax = 0;
	dataVector.resize(0);
}

/*
* Constructor OrderDetailsData(string inFileName) -> Constructor with inFileName (inFileName: file is used to save OrderDetailsData (OrderDetails Objects)
* Is used to create new OrderDetailsData object
* 
* IDMax = 0 -> set IDMax = 0 when create new OrderDetailsData (Vector of orderDetails)
* 
* dataVector.resize(0) -> set 0 for size of new dataVector
* 
* dataVector is a vector and it is used to save dataDetails Objects
* 
* ifstream insFile(inFileName); -> open a file and the name of file is inFileName's value
* 
* 
* const int maxSize = 255;
* char buff[maxSize];			-> create a char array name buff and the size of buff is maxSize = 255
* 
* 
* 
*/
OrderDetailsData::OrderDetailsData(string inFileName) {
	IDMax = 0;
	dataVector.resize(0);

	ifstream insFile(inFileName);

	const int maxSize = 255;
	char buff[maxSize];

	while (insFile.getline(buff, maxSize)) {
		json j = json::parse(buff);

		OrderDetails o(
			j["OrderDetailID"],
			j["OrderID"],
			j["ProductID"],
			j["Quantity"]
		);

		dataVector.push_back(o);
	}

	insFile.close();
}

int OrderDetailsData::pushBack(OrderDetails p) {
	if (IDMax < p.OrderID) {
		IDMax = p.OrderID;
	}

	dataVector.push_back(p);
	return IDMax;
}


int OrderDetailsData::update(int i, OrderDetails p) {
	if (i < 0) {
		return -1;
	}

	if (i >= dataVector.size()) {
		return -1;
	}

	dataVector[i] = p;

	if (IDMax < p.OrderDetailID) {
		IDMax = p.OrderDetailID;
	}

	return IDMax;
}

OrderDetails OrderDetailsData::get(int i) {
	return dataVector[i];
}

OrderDetails* OrderDetailsData::getP(int i) {

	OrderDetails* p = nullptr;
	if (i < 0) return p;
	if (i >= dataVector.size()) return p;
	p = &dataVector[i];
	return p;
}

int OrderDetailsData::getSize() {
	return dataVector.size();
}

int OrderDetailsData::exportToFile(string outFileName) {
	ofstream productOutFile(outFileName, ios::out);
	if (!productOutFile) return 0;
	for (OrderDetails p : dataVector) {
		productOutFile << p.toJson() << endl;
	}
	productOutFile.close();

	return 1;
}

int OrderDetailsData::getLastId(){
	return dataVector.back().OrderDetailID;
}