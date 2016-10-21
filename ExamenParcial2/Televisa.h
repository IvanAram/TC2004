#pragma once
#include <iostream>
#include "Noticiero.h"

class Televisa : public Noticiero{
public:
    Televisa(){}
    void publicar(){
        for(int i = 0; i < presidentes.getLength(); i++){
            presidentes.at(i)->getData()->update(noticia);
            std::cout << "por el noticiero Televisa" << std::endl;
        }
    }
    void addPresidente(Presidente* p){ presidentes.insertTail(p); }
};