#pragma once

/*
* Nguyen Thanh Tra
* 
* file Products.h and Products.cpp contain attributes and methods of Products
* 
* Create "Vetor product" to save the Products into The vector 
* 
* Create class Products to define the features of Products: ProductID, ProductName, SuppplyID, CategoryID, Unit, Price.
* 
* Varianle "productsIDMax" is used to save the maximum ID of all Products
* 
* Constructor Products()
* And Constructor Products(int ProductID, string ProductName, int SupplyID, int CategoryID, int Unit, double Price)
* are used to define the product object
* 
* Method "pushBackProduct(Products)" is used to save product into vector "productsFileOut"
*/

#ifndef _Products_h
#define _Products_h

#include <string>	//used for string
#include <iostream>
#include <vector>
#include <fstream>	//used for filestream

#include "../businessobjects/Products.h"
#include "../libs/json.hpp"

using namespace std;	//using std namespace
using json = nlohmann::json;

class Products
{

public:
	int ProductID;
	string ProductName;
	int SupplyID;
	int CategoryID;
	int Unit;
	double Price;

	Products();
	Products(int ProductID, string ProductName, int SupplyID, int CategoryID, int Unit, double Price);

	string toString();
	json toJson();
	
};

#endif // !_Product_h




