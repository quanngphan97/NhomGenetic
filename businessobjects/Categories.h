#ifndef _Categories_H
#define _Categories_H

#include <string>

using namespace std;

class Categories{
	int CategoryID;
	string CategoryName, Description;
public:
	Categories();
	Categories(int CategoryID, string CategoryName, string Description);
};

#endif
