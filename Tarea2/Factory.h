#ifndef FACTORY_H
#define FACTORY_H

#include "Clon.h"

class Factory{
protected:
	Factory(){}
public:
	virtual Computer* factoryMethod(std::string tipo) = 0;
	Computer* createComp(std::string tipo);
};

Computer* Factory::createComp(std::string tipo){
	Computer* computadora = factoryMethod(tipo);
	computadora->selecComp();
	computadora->ensamComp();
	computadora->instSoft();
	computadora->empaqComp();
	return computadora;
}

#endif
