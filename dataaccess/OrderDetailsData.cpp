#include "OrderDetailsData.h"
#include <fstream>
#include "./libs/json.hpp"

OrderDetailsData::OrderDetailsData() {
	IDMax = 0;
	dataVector.resize(0);
}

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

