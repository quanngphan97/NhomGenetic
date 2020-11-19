#include "Categories.h"

using namespace std;

Categories::Categories(){
	
}
Categories::Categories(int CategoryID, string CategoryName, string Description){
	this->CategoryID = CategoryID;
	this->CategoryName = CategoryName;
	this->Description = Description;
}
