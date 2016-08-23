#ifndef TABLET_H
#define TABLET_H

#include "Clon.h"

class Tablet : public Clon<Computer, Tablet>{
private:
	Tablet(){}
public:
	void selecComp(){
		std::cout<<"Seleccionando componentes de Tablet.\nListo."<<std::endl;
	}
	void ensamComp(){
		std::cout<<"\nEnsamblando componentes de Tablet.\nListo."<<std::endl;
	}
	void instSoft(){
		std::cout<<"\nInstalando y configurando el software.\nListo."<<std::endl;
	}
	void empaqComp(){
		std::cout<<"\nEmpaquetando Tablet.\nListo.\n"<<std::endl;
	}
	static Tablet* getTablet(){ return new Tablet; }
};

#endif
