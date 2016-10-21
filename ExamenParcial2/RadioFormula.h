#pragma once
#include <iostream>
#include "Noticiero.h"

class RadioFormula : public Noticiero{
public:
    RadioFormula(){}
    void publicar(){
        for(int i = 0; i < presidentes.getLength(); i++){
            presidentes.at(i)->getData()->update(noticia);
            std::cout << "por el noticiero Radio Formula" << std::endl;
        }
    }
    void addPresidente(Presidente* p){ presidentes.insertTail(p); }
};