#pragma once
#include <iostream>
#include "Presidente.h"
#include "Noticiero.h"

class Trump : public Presidente{
private:
    std::string name;
public:
    Trump(Noticiero* noticiero, std::string n) : name(n) { noticiero->addPresidente(); }
    std::string getName(){ return name; }
};