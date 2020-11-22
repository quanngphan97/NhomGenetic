#include "OrdersData.h"
#include <fstream>
#include "../libs/json.hpp"

OrdersData::OrdersData() {
	IDMax = 0;
	dataVector.resize(0);
}

OrdersData::OrdersData(string inFileName) {
	IDMax = 0;
	dataVector.resize(0);

	ifstream insFile(inFileName);
	const int maxSize = 255;

	char buff[maxSize];

	while (insFile.getline(buff, maxSize)) {
		json j = json::parse(buff);

		Orders o(
			j["OrderID"],
			j["CustomerID"],
			j["EmployeeID"],
			j["OrderDate"],
			j["ShipperID"]
			);

		dataVector.push_back(o);
	}

	insFile.close();
}

int OrdersData::pushBack(Orders p) {
	if (IDMax < p.OrderID) {
		IDMax = p.OrderID;
	}

	dataVector.push_back(p);
	return IDMax;
}


int OrdersData::update(int i, Orders p) {
	if (i < 0) {
		return -1;
	}

	if (i >= dataVector.size()) {
		return -1;
	}

	dataVector[i] = p;

	if (IDMax < p.OrderID) {
		IDMax = p.OrderID;
	}

	return IDMax;
}

Orders OrdersData::get(int i) {
	return dataVector[i];
}

Orders* OrdersData::getP(int i) {

	Orders* p = nullptr;
	if (i < 0) return p;
	if (i >= dataVector.size()) return p;
	p = &dataVector[i];
	return p;
}

int OrdersData::getSize() {
	return dataVector.size();
}

int OrdersData::exportToFile(string outFileName) {
	ofstream productOutFile(outFileName, ios::out);
	if (!productOutFile) return 0;
	for (Orders p : dataVector) {
		productOutFile << p.toJson() << endl;
	}
	productOutFile.close();

	return 1;
}

