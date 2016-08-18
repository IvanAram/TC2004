#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H

#include "Factory.h"
#include "Laptop.h"
#include "Desktop.h"
#include "Notebook.h"
#include "Tablet.h"

class ConcreteFactory : public Factory{
private:
	ConcreteFactory(){}
	static ConcreteFactory* factory;
public:
	Computer* factoryMethod(std::string tipo);
	static ConcreteFactory* getFactory();
};

Computer* ConcreteFactory::factoryMethod(std::string tipo){
	if(tipo=="Laptop" || tipo=="laptop") return Laptop::getLaptop(); 
	else if(tipo=="Desktop" || tipo=="desktop") return Desktop::getDesktop();
	else if(tipo=="Notebook" || tipo=="notebook") return Notebook::getNotebook();
	else if(tipo=="Tablet" || tipo=="tablet") return Tablet::getTablet();
	else return nullptr;
}

ConcreteFactory* ConcreteFactory::factory = nullptr;

ConcreteFactory* ConcreteFactory::getFactory(){
	if(!factory) factory = new ConcreteFactory;
	return factory;
}

#endif
