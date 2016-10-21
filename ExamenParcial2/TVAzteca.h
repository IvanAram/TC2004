#pragma once
#include <iostream>
#include "Noticiero.h"

class TVAzteca : public Noticiero{
public:
    TVAzteca(){}
    void publicar(){
        for(int i = 0; i < presidentes.getLength(); i++){
            presidentes.at(i)->getData()->update(noticia);
            std::cout << "por el noticiero TVAzteca"
        }
    }
    void addPresidente(Presidente* p){ presidentes->insertTail(p); }
};