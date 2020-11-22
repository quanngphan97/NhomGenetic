#pragma once
#ifndef _ProductsData_h
#define _ProductsData_h

#include <vector>
#include <string>
#include "../businessobjects/Products.h"

using json = nlohmann::json;
using namespace std;

class ProductsData
{

public:
    int IDMax;

private:
    vector<Products> dataVector;

public:
    ProductsData();
    ProductsData(string);

    int pushBack(Products);
    int update(int, Products);
    Products get(int);
    Products* getP(int);
    int getSize();
    int exportToFile(string);

};

#endif // !_ProductsData_h


