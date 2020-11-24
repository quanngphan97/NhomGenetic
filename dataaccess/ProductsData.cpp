/*
* -----NGUYEN THANH TRA-----
*
* FileName: ProductsData.cpp
* Function:
*
*/


/*
* include ProductsData.h to clarify the constructions and the methods of this library
* include <fstream> to use the fileStream functions
* include "../libs/json.hpp" to use json functions
*/
#include "ProductsData.h"
#include <fstream>
#include "../libs/json.hpp"


/*
* Constructions ProductsData(): default construction
* Is used to create new ProductsData object
* IDMax = 0: set IDMax = 0 when create new ProductsData (Vector of orderDetails)
* dataVector.resize(0): set 0 for size of new dataVector
* dataVector is a vector and it is used to save dataDetails Objects
*/
ProductsData:: ProductsData() {
	IDMax = 0;
	dataVector.resize(0);
}


/*
* Constructor ProductsData(string inFileName) -> Constructor with inFileName (inFileName: file is used to save ProductsData (Products Objects)
* Is used to create new ProductsData object
*
* IDMax = 0 -> set IDMax = 0 when create new ProductsData (Vector of orderDetails)
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
*/
ProductsData::ProductsData(string InFileName) {
	IDMax = 0;
	dataVector.resize(0);

	ifstream productInsFile(InFileName);
	const int maxSize = 255;

	char buff[maxSize];

	while (productInsFile.getline(buff, maxSize)) {
		json j = json::parse(buff);

		Products p(
			j["ProductID"],
			j["ProductName"],
			j["SupplyID"],
			j["CategoryID"],
			j["Unit"],
			j["Price"]
		);

		dataVector.push_back(p);
	}

	productInsFile.close();
}

/*
* pushback Products Object to ProductsData Vector (dataVector)
*/
int ProductsData::pushBack(Products p) {
	if (IDMax < p.ProductID) {
		IDMax = p.ProductID;
	}

	dataVector.push_back(p);
	return IDMax;
}


/*
* update Products Object to ProductsData Vector (dataVector) with th position int i
*/
int ProductsData::update(int i, Products p) {
	if (i < 0) {
		return -1;
	}	

	if (i >= dataVector.size()) {
		return -1;
	}

	dataVector[i] = p;

	if (IDMax < p.ProductID) {
		IDMax = p.ProductID;
	}

	return IDMax;
}


/*
* remove Products Object to ProductsData Vector (dataVector) with th position int i
*/
int ProductsData::remove(int i) {

	dataVector.erase(dataVector.begin() + i);

	return i;
}

/*
* get Products Object from ProductsData Vector (dataVector) with position int i
*/
Products ProductsData::get(int i) {
	return dataVector[i];
}


/*
* get Products Object (pointer) from ProductsData Vector (dataVector) with position int i
*/
Products* ProductsData::getP(int i) {

	Products* p = nullptr;
	if (i < 0) return p;
	if (i >= dataVector.size()) return p;
	p = &dataVector[i];
	return p;
}


/*
* get the size ProductsData Vector (dataVector): How many objects in dataVector
*/
int ProductsData::getSize() {
	return dataVector.size();
}


/*
* Export ProductsData Vector (dataVector) to file
* #outFileName is the name of file
*
*/
int ProductsData::exportToFile(string outFileName) {
	ofstream productOutFile(outFileName, ios::out);
	if (!productOutFile) return 0;

	for (Products p : dataVector) {
		productOutFile << p.toJson() << endl;
	}
	
	productOutFile.close();

	return 1;
}

