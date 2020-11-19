#include "Shippers.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
Shippers::Shippers()
{
}
Shippers::Shippers(int ShipperID,string ShipperName,string Phone)
{
	this->ShipperID = ShipperID;
	this->ShipperName = ShipperName;
	this->Phone = Phone;
}
