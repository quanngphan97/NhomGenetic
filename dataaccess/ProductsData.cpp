#include "ProductsData.h"
#include <fstream>
#include "./libs/json.hpp"

ProductsData:: ProductsData() {
	IDMax = 0;
	dataVector.resize(0);
}

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

int ProductsData::pushBack(Products p) {
	if (IDMax < p.ProductID) {
		IDMax = p.ProductID;
	}

	dataVector.push_back(p);
	return IDMax;
}


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

Products ProductsData::get(int i) {
	return dataVector[i];
}

Products* ProductsData::getP(int i) {

	Products* p = nullptr;
	if (i < 0) return p;
	if (i >= dataVector.size()) return p;
	p = &dataVector[i];
	return p;
}

int ProductsData::getSize() {
	return dataVector.size();
}

int ProductsData::exportToFile(string outFileName) {
	ofstream productOutFile(outFileName, ios::app);
	if (!productOutFile) return 0;

	for (Products p : dataVector) {
		productOutFile << p.toJson() << endl;
	}
	productOutFile.close();

	return 1;
}

