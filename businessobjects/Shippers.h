#ifndef _Shippers_H
#define _Shippers_H

#include <string>
using namespace std;
class Shippers
{
	protected:
		int ShipperID;
		string ShipperName;
		string Phone;
	public:
		Shippers();
		Shippers(int ShipperID,string ShipperName,string Phone);
};
#endif

