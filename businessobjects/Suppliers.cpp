#include "Suppliers.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Supplier::Supplier()
{
}
Supplier::Supplier(int SupplierID,string SupplierName,string ContactName,string Address,string City,string PostalCode, string Country, string Phone)
{
	this->SupplierID = SupplierID;
	this->SupplierName = SupplierName;
    this->ContactName = ContactName;
    this->Address = Address;
    this->City = City;
    this->Country =Country;
	this->Phone = Phone;
}
/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: p1(1, "Speedy Express","(503) 555-9831") -> {"ShipperID":1,"ShipperName":"Speedy Express","Phone : (503) 555-9831"}
 */
json Supplier::ToJson(){
    json j;
    j["SupplierID"] = SupplierID;
    j["SupplierName"] = SupplierName;
    j[" ContactName"] =  ContactName; 
    j["Address"] = Address;
    j["City"] = City;
    j["PostalCode"] = PostalCode;
    j["Country"] = Country;
    j["Phone"] = Phone;
    return j;
}
string Supplier::Tostring()
{
    string s;
    s += "{";
    s += to_string(SupplierID) + ", ";
    s += SupplierName + ", ";
    s += ContactName + ", ";
    s += SupplierName + ", ";
    s += City + ", ";
    s += PostalCode + ", ";
    s += Country + ", ";
    s += Phone + ", ";
    s += "}";
    return s;
}