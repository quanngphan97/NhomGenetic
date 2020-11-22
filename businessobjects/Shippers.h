#ifndef _Shippers_H
#define _Shippers_H

#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;
class Shippers
{
	public:
		int ShipperID;
		string ShipperName;
		string Phone;
	public:
		Shippers();
		Shippers(int ShipperID,string ShipperName,string Phone);
		json ToJson();
		string Tostring();
};
#endif
