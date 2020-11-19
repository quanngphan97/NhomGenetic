#include "Employees.h"

using namespace std;

Employees::Employees(){
	
}
Employees::Employees(int EmployeeID, string LastName, string FirstName, string BirthDate, string Photo, string Notes){
	this->EmployeeID = EmployeeID;
	this->LastName = LastName;
	this->FirstName = FirstName;
    this->BirthDate = BirthDate;
	this->Photo = Photo;
    this->Notes = Notes;
}