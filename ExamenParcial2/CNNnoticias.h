#pragma once
#include <iostream>
#include "Noticiero.h"

class CNNnoticias : public Noticiero{
public:
    CNNnoticias() {}
    void publicar(){
        for(int i = 0; i < presidentes.getLength(); i++){
            presidentes.at(i)->getData()->update(noticia);
            std::cout << "por el noticiero CNN Noticias" << std::endl;
        }
    }
    void addPresidente(Presidente* p){ if(p->getName() != "Pena Nieto") presidentes.insertTail(p); }
};