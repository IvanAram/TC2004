#pragma once
#include <iostream>
#include "Presidente.h"
#include "Noticiero.h"

class Pena : public Presidente{
private:
    std::string name;
public:
    Pena(Noticiero* noticiero, std::string n) : name(n) {noticiero->addPresidente(this); }
    std::string getName(){ return name; }
    void update(std::string noticia){ std::cout << "Se publico " << noticia << " de " << name << std::endl; }
};