#include <map>
#include <string>
#include <iostream>

template <class T, class F>
class Command{
public:
    virtual T execute(T*, int, F) = 0;
};