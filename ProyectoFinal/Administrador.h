#pragma once
#include <iostream>
#include "Almacen.h"
#include "Mesero.h"
#include "Cocina.h"
#include "Cocinero.h"
#include "Almacenista.h"
#include "Empleado.h"


class Administrador : public Empleado{
public:
	Administrador() {}
	
	void contratar(int op);
};

void Administrador::contratar(int op){
	std::string n;
	if(op == 2){
		std::cout << "Ingrese nombre de nuevo cocinero: ";
		std::cin >> n;
		Empleado* newCocinero = new Cocinero(n,4000);
		Cocina::getCocina()->addCocinero(newCocinero);
	}
	if(op == 3){
		std::cout << "Ingrese nombre de nuevo almacenista: ";
		std::cin >> n;
		Empleado* newAlmacenista = new Almacenista(n,5000);
		Almacen::getAlmacen()->setEmpleado(newAlmacenista);
	}
}