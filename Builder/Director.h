#pragma once 

#include <iostream>
#include "Builder.h"

class Director{
private:
	Builder* builder;
public:
	void setBuilder(Builder* bd){ builder = bd; }
	Avion* getAvion(){ return builder->getAvion(); }
	void construct();
};

void Director::construct(){
	builder->createAvion();
	builder->buildAlas();
	builder->buildModelo();
	builder->buildModelo();
	builder->buildMarca();
	builder->buildNumSerie();
}