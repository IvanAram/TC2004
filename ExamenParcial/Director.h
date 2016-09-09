#pragma once 

#include <iostream>
#include "Clon.h"
#include "Builder.h"

class Director{
private:
	Builder* builder;
public:
	void setBuilder(Builder* bd){ builder = bd; }
	Pastel* getPastel(std::string tipo) { return builder->getFactory()->createPastel(tipo); }
	void construct();
};

void Director::construct(){
	builder->createFactory();
	builder->buildIngredientes();
}