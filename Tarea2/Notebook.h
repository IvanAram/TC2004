#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Clon.h"

class Notebook : public Clon<Computer, Notebook>{
private:
	Notebook(){}
public:
	void selecComp(){
		std::cout<<"Seleccionando componentes de Notebook.\nListo."<<std::endl;
	}
	void ensamComp(){
		std::cout<<"\nEnsamblando componentes de Notebook.\nListo."<<std::endl;
	}
	void instSoft(){
		std::cout<<"\nInstalando y configurando el software.\nListo."<<std::endl;
	}
	void empaqComp(){
		std::cout<<"\nEmpaquetando Notebook.\nListo.\n"<<std::endl;
	}
	static Notebook* getNotebook(){ return new Notebook; }
};

#endif
