/*
	Ivan Aram Gonzalez Su
	A01022584
*/

#pragma once
#include <iostream>

class Computer{
private:
	std::string type;
	void procesoCreacion();
public:
	Computer(){}
	Computer(std::string _type):type(_type){}
	Computer* create();
};

void Computer::procesoCreacion(){
	std::cout<<"\nSeleccionando componentes...\nListo.\n"<<std::endl;
	std::cout<<"Ensamblando componentes...\nListo.\n"<<std::endl;
	std::cout<<"Instalando Software...\nListo.\n"<<std::endl;
	std::cout<<"Configurando el Software...\nListo.\n"<<std::endl;
	std::cout<<"Empaquetando computadora...\nListo.\n"<<std::endl;
}

Computer* Computer::create(){
	procesoCreacion();
	if(type == "Laptop"){
		std::cout<<"La laptop se creó exitosamente.\n"<<std::endl;
		Computer* laptop = new Computer("Laptop");
		return laptop;
	}
	else if(type == "Desktop"){
		std::cout<<"La Desktop se creó exitosamente.\n"<<std::endl;
		Computer* desktop = new Computer("Desktop");
		return desktop;
	}
	else if(type == "Notebook"){
		std::cout<<"La Notebook se creó exitosamente.\n"<<std::endl;
		Computer* notebook = new Computer("Notebook");
		return notebook;
	}
	else if(type == "Tablet"){
		std::cout<<"La Tablet se creó exitosamente.\n"<<std::endl;
		Computer* tablet = new Computer("Tablet");
		return tablet;
	}
	else return nullptr;
}
