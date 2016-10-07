#include <iostream>
#include "Persona.h"
#include "Iterator.h"

int main(){
	Persona p1(20);
	Persona p2(25);
	Persona p3(17);
	Persona p4(18);
	
	Aggregate<Persona> lista;
	
	lista.add(p1);
	lista.add(p2);
	lista.add(p3);
	lista.add(p4);
	
	for(Iterator<Persona>* i = lista.getIterator(); i->hasNext(); i->next()) std::cout<< i->currentItem().getEdad()<<std::endl;
	//for(Iterator<Persona>* i = lista.getIterator(); i->hasNext(); ) 
	//	std::cout<< i->next().getEdad()<<std::endl;
}