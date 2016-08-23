#ifndef DESKTOP_H
#define DESKTOP_H

#include "Clon.h"

class Desktop : public Clon<Computer, Desktop>{
private:
	Desktop(){}
public:
	void selecComp(){
		std::cout<<"Seleccionando componentes de Desktop.\nListo."<<std::endl;
	}
	void ensamComp(){
		std::cout<<"\nEnsamblando componentes de Desktop.\nListo."<<std::endl;
	}
	void instSoft(){
		std::cout<<"\nInstalando y configurando el software.\nListo."<<std::endl;
	}
	void empaqComp(){
		std::cout<<"\nEmpaquetando Desktop.\nListo.\n"<<std::endl;
	}
	static Desktop* getDesktop(){ return new Desktop; }
};

#endif
