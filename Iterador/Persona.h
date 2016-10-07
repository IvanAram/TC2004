#pragma once

#include <iostream>

class Persona{
private:
	int edad;
public:
	Persona(){}
	Persona(int e) : edad(e) {}
	int getEdad() { return edad; }
	bool operator== (const Persona& _other){ return (edad == _other.edad); }
	bool operator!= (const Persona& _other){ return !(edad == _other.edad); }
};