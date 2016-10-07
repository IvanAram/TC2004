#include <iostream>
#include "Director.h"
#include "DFBuilder.h"
#include "ACBuilder.h"
#include "Iterator.h"
#include "ConcreteFactory.h"

int main(){
	Director* DF = new Director;
	Director* AC = new Director;
	
	DF->setBuilder(new DFBuilder);
	AC->setBuilder(new ACBuilder);
	
	DF->construct();
	AC->construct();
	
	Pastel* p1 = DF->getPastel("Imposible");
	Pastel* p2 = AC->getPastel("TresLeches");
	
	p1->setName("A");
	p2->setName("B");
	
	std::cout<<"Pastel 1: "<<p1->getName()<<", pastel 2: "<<p2->getName()<<std::endl;
}