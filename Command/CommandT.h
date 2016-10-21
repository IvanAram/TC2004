#pragma once
#include <iostream>

class CommandT{
public:
    template <class T, class Func>
    T execute(T* arr, int size, Func f){
        return f(arr, size);
    }
};