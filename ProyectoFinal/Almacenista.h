#pragma once
#include <iostream>
#include "Empleado.h"

class Almacenista : public Empleado{
public:
	Almacenista(std::string _name, float _sueldo) : Empleado(_name, _sueldo) {}
};