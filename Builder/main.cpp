#include <iostream>
#include "Director.h"
#include "BoeingBuilder.h"

int main(){
	Director* dir = new Director;
	dir->setBuilder(new BoeingBuilder);
	dir->construct();
	Avion* plane = dir->getAvion();
	std::cout<<plane->getModelo()<<std::endl;
}