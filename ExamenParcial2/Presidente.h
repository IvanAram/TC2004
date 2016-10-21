#pragma once
#include <iostream>

class Presidente{
public:
    virtual void update(std::string noticia) = 0;
    virtual std::string getName() = 0;
};