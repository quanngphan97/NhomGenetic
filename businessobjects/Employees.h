#ifndef _Employees_H
#define _Employees_H

#include <string>

using namespace std;

class Employees{
	int EmployeeID;
	string LastName, FirstName, BirthDate, Photo, Notes;
public:
	Employees();
	Employees(int EmployeeID, string LastName, string FirstName, string BirthDate, string Photo, string Notes);
};

#endif
