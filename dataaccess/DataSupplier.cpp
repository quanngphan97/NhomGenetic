/** @file DataSupplier.h
 *  @brief ProductsData stores all Products objects
 *  
 *  @author PhanBaQuang
 *  @bug No known bugs.
 */
#include "DataSupplier.h"
#include <fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DataSupplier::DataSupplier()
{
    maxID = 0 ;
    _data.resize(0) ;
}


DataSupplier::DataSupplier(string Filename) // write file
{
    maxID = 0;
    _data.resize(0);
    ifstream inFile(Filename);
    const int maxsize = 255;
    char buff[maxsize];
    while(inFile.getline(buff,maxsize) )
    {
        json j = json::parse(buff); // convert json
       Supplier S(
            j["SupplierID"],
            j["SupplierName"],
            j["ContactName"],
            j["Address"],
            j["City"],
            j["PostalCode"],
            j["Country"],
            j["Phone"] ); 
        _data.push_back(S);
    }
    inFile.close();
}
/** @brief Function add a Products object to the end of the list inside SupplierData.
 *  
 *  Function add a Products object to the end of the list inside SupplierData.
 *  @return maxId of Supplier object inside DataSupplier;
 */
int DataSupplier::Pushback(Supplier S)
{
    if (maxID < S.SupplierID ) maxID = S.SupplierID;
    _data.push_back(S);
    return maxID;
}
/** @brief Function updates a Supplier object at a position inside the list inside SupplierData.
 *  
 *  Function updates a Supplier object at a position inside the list inside SupplierData.
 *  @return maxId of Supplier object inside SupplierData;
 *  if fail, return -1;
 */
int  DataSupplier::Update(int i,Supplier S)
{
    if(i < -1 ) return -1;
    if(i>_data.size()) return -1;
    _data[i] = S;
    if(maxID < S.SupplierID) maxID = S.SupplierID;
    return maxID;
}
/** @brief Function return a Supplier object at a position inside the list inside SupplierData.
 *  
 *  Function return a Supplier object at a position inside the list inside SupplierData.
 *  @return Supplier object;
 *  if fail, return NULL;
 */
Supplier DataSupplier::get(int i)
{
 return _data[i]; 
}
Supplier* DataSupplier::getPointer(int i)
{
  Supplier *s = nullptr;
  if(i<-1) return s;
  if(i >= _data.size()) return s;
  s = &_data[i];
  return s;
 }
/** @brief Function return size of SupplierData.
 *  
 *  Function return size of SupplierData. This is the quantity of Products objects inside SupplierData.
 *  @return number of Products objects;
 */
int DataSupplier::GetSize(){
    return _data.size();
}
/** @brief Function write all data in ProductsData to file.
 *  
 *  Function write all data in ProductsData to file.
 *  @return 1 if success, 0 if fail;
 */
int DataSupplier::Exportofile(string Filename)
{
    ofstream OutFile(Filename,ios::out);
    if(!OutFile) return 0;
    for(Supplier s : _data)
    {
        OutFile << s.ToJson() << endl;
    }
    OutFile.close();
    return 1;
}