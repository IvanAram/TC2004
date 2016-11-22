#pragma once
#include <iostream>
#include "Orden.h"

class Empleado{
protected:
	std::string name;
	float sueldo;
public:
	Empleado(){}
	Empleado(std::string _name, float _sueldo) : name(_name), sueldo(_sueldo) {}
	std::string getName(){ return name; }
	void setName(std::string _name){ name = _name; }
	float getSueldo(){ return sueldo; }
	void setSueldo(float _sueldo){ sueldo = _sueldo; }
	virtual void contratar(int op){ std::cout << "Tu no eres administrador!" << std::endl; }
	virtual Orden* tomarOrden(){
		std::cout << "Tu no eres mesero!" << std::endl;
		return nullptr;
	}
	virtual void atenderComanda(){ std::cout << "Tu no eres cocinero!" << std::endl; }
	virtual void cobrarOrden(){ std::cout << "Tu no eres cocinero!" << std::endl; }
	virtual void verMenu(){ std::cout << "Tu no eres mesero!" << std::endl; }
};