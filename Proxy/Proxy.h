#pragma once
#include <iostream>
using namespace std;

class ArrayPositiveInts;

class Proxy{
private:
    ArrayPositiveInts& arr;
    int idx;
public:
    Proxy();
    Proxy(ArrayPositiveInts& arr, int idx) : arr(arr), idx(idx)  {}
    Proxy& operator=(int value);
};