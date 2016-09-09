#pragma once

#include <iostream>
#include "Factory.h"
#include "Imposible.h"
#include "TresLeches.h"
#include "Sacher.h"

class ConcreteFactory : public Factory{
private:
	ConcreteFactory(){}
	static ConcreteFactory* factory;
public:
	Pastel* factoryMethod(std::string tipo);
	static ConcreteFactory* getFactory();
};

Pastel* ConcreteFactory::factoryMethod(std::string tipo){
	if(tipo=="TresLeches") return new TresLeches; 
	else if(tipo=="Sacher") return new Sacher;
	else if(tipo=="Imposible") return new Imposible;
	else return nullptr;
}


ConcreteFactory* ConcreteFactory::factory = nullptr;

ConcreteFactory* ConcreteFactory::getFactory(){
	if(!factory) factory = new ConcreteFactory;
	return factory;
}
