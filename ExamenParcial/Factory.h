#pragma once

#include <iostream>
#include "Clon.h"

class Factory{
protected:
	Factory(){}
public:
	virtual Pastel* factoryMethod(std::string tipo) = 0;
	Pastel* createPastel(std::string tipo);
};

Pastel* Factory::createPastel(std::string tipo){
	Pastel* pastel = factoryMethod(tipo);
	pastel->crearPastel();
	return pastel;
}