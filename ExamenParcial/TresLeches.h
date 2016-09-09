#pragma once

#include <iostream>

#include "Clon.h"

class TresLeches : public Clon<Pastel, TresLeches>{
public:
	void crearPastel();
};

void TresLeches::crearPastel(){
	std::cout<<"Batiendo masa.\nListo."<<std::endl;
	std::cout<<"Amasando masa.\nListo."<<std::endl;
	std::cout<<"Horneando pastel.\nListo."<<std::endl;
	std::cout<<"Decorando pastel.\nListo."<<std::endl;
	std::cout<<"Empacando TresLeches.\nListo."<<std::endl;
}