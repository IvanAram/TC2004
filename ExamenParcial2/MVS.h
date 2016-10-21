#pragma once
#include <iostream>
#include "Noticiero.h"

template <class T>
class MVS : public Noticiero{
public:
    MVS() {}
    void publicar(){
        for(int i = 0; i < presidentes.getLength(); i++){
            presidentes.at(i)->getData()->update(noticia);
            std::cout << "por el noticiero MVS"
        }
    }
    void addPresidente(Presidente* p){ presidentes->insertTail(p); }
};