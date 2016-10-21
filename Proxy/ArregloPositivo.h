#pragma once
#include "Proxy.h"
#include <iostream>

class ArrayPositiveInts{
private:
    Proxy* temp;
    int* values;
    int size;
public:
    friend class Proxy;
    ArrayPositiveInts()
    {
        size = 100;
        values = new int[size];
    }
    int& operator[](int idx)
    {
        temp = new Proxy(*this, idx);
        return values[idx];
    }
};

Proxy& Proxy::operator=(int value){
    if(value>=0){
        *(arr.values + idx) = value;
        *this;
    }
    else{
        cout << "error" << endl;
        return *this;
    }
}
