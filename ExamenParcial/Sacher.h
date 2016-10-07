#pragma once

#include <iostream>

#include "Clon.h"

class Sacher : public Clon<Pastel, Sacher>{
public:
	void crearPastel();
	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }
};

void Sacher::crearPastel(){
	std::cout<<"Batiendo masa.\nListo."<<std::endl;
	std::cout<<"Amasando masa.\nListo."<<std::endl;
	std::cout<<"Horneando pastel.\nListo."<<std::endl;
	std::cout<<"Decorando pastel.\nListo."<<std::endl;
	std::cout<<"Empacando Sacher.\nListo."<<std::endl;
}