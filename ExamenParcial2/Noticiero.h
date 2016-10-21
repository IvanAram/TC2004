#pragma once
#include <iostream>
#include "Presidente.h"
#include "LinkedList.h"

class Noticiero{
protected:
    std::string noticia;
    LinkedList<Presidente*> presidentes;
public:
    virtual void publicar();
    void setNoticia(std::string n) { noticia = n; }
    virtual void addPresidente(Presidente*);
};