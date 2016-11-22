#pragma once
#include <iostream>
#include "Empleado.h"
#include "Orden.h"
#include "Recetario.h"

class Mesero : public Empleado{
public:
	Mesero(std::string _name, float _sueldo) : Empleado(_name, _sueldo) {}
	Orden* tomarOrden();
	void pagarOrden();
	void cobrarOrden();
	void verMenu();
};

Orden* Mesero::tomarOrden(){
	Orden* orden = new Orden();
	std::string platillo;
	Recetario menu;
	while(1){
		std::cout << "Que desea ordenar (exit = salir): ";
		std::cin >> platillo;
		if(platillo == "exit") break;
		if((menu.it = menu.recetas.find(platillo)) != menu.recetas.end()){
			orden->addPlatillo(platillo,menu.it->second);
		}
	}
	return orden;
}

void Mesero::cobrarOrden(){
	std::cout << "Se cobro exitosamente!" << std::endl;
}

void Mesero::verMenu(){
	Recetario menu;
	std::cout << menu << std::endl;
}