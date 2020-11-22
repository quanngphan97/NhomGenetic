#ifndef _Datashipper_h
#define _Datashipper_h
#include <vector>
#include "../businessobjects/Shippers.h"

class DataShippers
{
public:
    int maxID;
private:
    vector<Shippers> _data;
public:
    DataShippers(); 
    DataShippers(string); 
    int Pushback(Shippers) ; 
    int Update(int,Shippers); 
    Shippers get(int) ; 
    Shippers* getPointer(int i);
    int GetSize();
    int Exportofile(string);
};
#endif