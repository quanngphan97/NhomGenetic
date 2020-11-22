/** @file DataShippers.h
 *  @brief ProductsData stores all Products objects
 *  
 *  @author PhanBaQuang
 *  @bug No known bugs.
 */
#include "DataShippers.h"
#include <fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DataShippers::DataShippers()
{
    maxID = 0 ;
    _data.resize(0) ;
}


DataShippers::DataShippers(string Filename) // write file
{
    maxID = 0;
    _data.resize(0);
    ifstream inFile(Filename);
    const int maxsize = 255;
    char buff[maxsize];
    while(inFile.getline(buff,maxsize) )
    {
        json j = json::parse(buff); // convert json
        Shippers S(
            j["ShipperID"],
            j["ShipperName"],
            j["Phone"]); 
        _data.push_back(S);
    }
    inFile.close();
}
/** @brief Function add a Products object to the end of the list inside ShippersData.
 *  
 *  Function add a Products object to the end of the list inside ShippersData.
 *  @return maxId of Shippers object inside DataShippers;
 */
int DataShippers::Pushback(Shippers S)
{
    if (maxID < S.ShipperID ) maxID = S.ShipperID;
    _data.push_back(S);
    return maxID;
}
/** @brief Function updates a Shippers object at a position inside the list inside ShippersData.
 *  
 *  Function updates a Shippers object at a position inside the list inside ShippersData.
 *  @return maxId of Shippers object inside ShippersData;
 *  if fail, return -1;
 */
int  DataShippers::Update(int i,Shippers S)
{
    if(i < -1 ) return -1;
    if(i>_data.size()) return -1;
    _data[i] = S;
    if(maxID < S.ShipperID) maxID = S.ShipperID;
    return maxID;
}
/** @brief Function return a Shippers object at a position inside the list inside ShippersData.
 *  
 *  Function return a Shippers object at a position inside the list inside ShippersData.
 *  @return Shippers object;
 *  if fail, return NULL;
 */
Shippers DataShippers::get(int i)
{
 return _data[i]; 
}
Shippers* DataShippers::getPointer(int i)
{
  Shippers *s = nullptr;
  if(i<-1) return s;
  if(i >= _data.size()) return s;
  s = &_data[i];
  return s;
 }
/** @brief Function return size of ShippersData.
 *  
 *  Function return size of ShippersData. This is the quantity of Products objects inside ShippersData.
 *  @return number of Products objects;
 */
int DataShippers::GetSize(){
    return _data.size();
}
/** @brief Function write all data in ProductsData to file.
 *  
 *  Function write all data in ProductsData to file.
 *  @return 1 if success, 0 if fail;
 */
int DataShippers::Exportofile(string Filename)
{
    ofstream OutFile(Filename,ios::out);
    if(!OutFile) return 0;
    for(Shippers s : _data)
    {
        OutFile << s.ToJson() << endl;
    }
    OutFile.close();
    return 1;
}