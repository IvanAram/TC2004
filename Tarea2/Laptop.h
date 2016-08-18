#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computer.h"

class Laptop : public Computer{
private:
	Laptop(){}
public:
	void selecComp(){
		std::cout<<"Seleccionando componentes de Laptop.\nListo."<<std::endl;
	}
	void ensamComp(){
		std::cout<<"\nEnsamblando componentes de Laptop.\nListo."<<std::endl;
	}
	void instSoft(){
		std::cout<<"\nInstalando y configurando el software.\nListo."<<std::endl;
	}
	void empaqComp(){
		std::cout<<"\nEmpaquetando Laptop.\nListo.\n"<<std::endl;
	}
	static Laptop* getLaptop(){ return new Laptop; }
};

#endif
