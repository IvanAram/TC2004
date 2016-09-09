#pragma once

#include <iostream>
#include "ConcreteFactory.h"

class Builder{
protected:
	ConcreteFactory* factory;
public:
	Factory* getFactory(){ return factory; }
	void createFactory(){ factory = ConcreteFactory::getFactory(); }

	virtual void buildIngredientes() = 0;
};