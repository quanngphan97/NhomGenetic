#include "Shippers.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Shippers::Shippers()
{
}
Shippers::Shippers(int ShipperID,string ShipperName,string Phone)
{
	this->ShipperID = ShipperID;
	this->ShipperName = ShipperName;
	this->Phone = Phone;
}
/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: p1(1, "Speedy Express","(503) 555-9831") -> {"ShipperID":1,"ShipperName":"Speedy Express","Phone : (503) 555-9831"}
 */
json Shippers::ToJson(){
    json j;
    j["ShipperID"] = ShipperID;
    j["ShipperName"] = ShipperName;
    j["Phone"] = Phone;
    return j;
}
string Shippers::Tostring()
{
    string s;
    s += "{";
    s += to_string(ShipperID) + ", ";
    s += ShipperName + ", ";
    s += Phone + ", ";
    s += "}";
    return s;
}