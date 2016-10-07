#pragma once

#include <iostream>

#include "Clon.h"

class Imposible : public Clon<Pastel, Imposible>{
public:
	void crearPastel();
	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }
};

void Imposible::crearPastel(){
	std::cout<<"Batiendo masa.\nListo."<<std::endl;
	std::cout<<"Amasando masa.\nListo."<<std::endl;
	std::cout<<"Horneando pastel.\nListo."<<std::endl;
	std::cout<<"Decorando pastel.\nListo."<<std::endl;
	std::cout<<"Empacando Imposible.\nListo."<<std::endl;
}