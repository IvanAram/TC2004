#pragma once 

#include <iostream>

class Piloto{
private:
	std::string nombre;
public:
	Piloto(){}
	//Piloto(std::string n) : nombre(n) {}
	
	void setNombre(std::string n){ nombre = n; }
	std::string getNombre(){ return nombre; }
};