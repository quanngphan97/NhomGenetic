#pragma once

/*
* -----NGUYEN THANH TRA-----
*
* FileName: ProductsData.h
* Function:
*
*
*/
#ifndef _ProductsData_h
#define _ProductsData_h


/*
* include string to use string type and functions
* include vector  to use vector and vector function
* include Products.h to create Products.h objects and Products.h object features
*/
#include <vector>
#include <string>
#include "../businessobjects/Products.h"


/*
* using name space std to do something
* using json functions
*/
using json = nlohmann::json;
using namespace std;

/*
* Create ProductsData class to save Products Object and handle Products Objects:
*	-int IDMax: to sava the ID Max of all Products Objects in Vector "dataVector"
*	-vector<Products> dataVector: to save all Products Objects to vector dataVector
*
* Have 2 constructions of OrderDetails:
*	-ProductsData(); -> Default construction
*	-ProductsData(string) -> Construction with 1 properties of ProductsData (FileName to save Products Object)
*
* Have 6 methods of ProductsData:
*	-int pushBack(Products): to add Products Object to ProductsData Vector
    -int update(int, Products): to Update Products Object to ProductsData Vector
    -Products get(int): to get Products Object from ProductsData Vector
    -Products* getP(int): to get Products Object (Pointer) from ProductsData Vector
    -int getSize(): to get size of ProductsData Vector
    -int exportToFile(string): to Export ProductsData Vector to fileName (string type)
*/
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
    int remove(int);
    Products get(int);
    Products* getP(int);
    int getSize();
    int exportToFile(string);

};

#endif // !_ProductsData_h


