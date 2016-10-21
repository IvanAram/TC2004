#pragma once
#include <iostream>
#include "Presidente.h"
#include "Noticiero.h"

class Hilary :public Presidente{
private:
    std::string name;
public:
    Hilary(Noticiero* noticiero, std::string n) : name(n) { noticiero->addPresidente(this); }
    std::string getName(){ return name; }
};