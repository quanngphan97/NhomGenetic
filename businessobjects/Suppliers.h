#ifndef _Supplies_H
#define _Supplies_H

#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Supplier
{
	public:
		int SupplierID;
		string SupplierName;
		string ContactName;
        string Address;
        string City;
        string PostalCode;
        string Country;
        string Phone;

	public:
		Supplier();
		Supplier(int SupplierID,string SupplierName,string ContactName,string Address,string City,string PostalCode, string Country, string Phone);
		json ToJson();
		string Tostring();
};
#endif

