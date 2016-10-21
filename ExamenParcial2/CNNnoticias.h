#pragma once
#include <iostream>
#include "Noticiero.h"

class CNNnoticias : public Noticiero{
public:
    CNNnoticias() {}
    void publicar(){
        for(int i = 0; i < presidentes.getLength(); i++){
            presidentes.at(i)->getData()->update(noticia);
            std::cout << "por el noticiero CNN Noticias"
        }
    }
    void addPresidente(Presidente* p){ if(p->getName() != "Peña Nieto") presidentes->insertTail(p); }
};