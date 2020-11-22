#ifndef _Datasupplier_h
#define _Datasupplier_h
#include <vector>
#include "../Suppliers/Supplier.h"

class DataSupplier
{
public:
    int maxID;
private:
    vector<Supplier> _data;
public:
    DataSupplier(); 
    DataSupplier(string); 
    int Pushback(Supplier) ; 
    int Update(int,Supplier); 
    Supplier get(int) ; 
    Supplier* getPointer(int i);
    int GetSize();
    int Exportofile(string);
};
#endif