#pragma once
#include <iostream>
#include "Empleado.h"
#include "Orden.h"
#include "Cocina.h"

class Cocinero : public Empleado{
public:
	Cocinero(std::string _name, float _sueldo) : Empleado(_name, _sueldo) {}
	void atenderComanda();
};

void Cocinero::atenderComanda(){
	Cocina::getCocina()->quitarComanda();
}