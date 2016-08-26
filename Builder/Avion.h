#pragma once

#include <iostream>
#include "Motor.h"
#include "Alas.h"
#include "Piloto.h"

class Avion{
private:
	int numSerie;
	std::string marca;
	std::string modelo;
	Motor* motor;
	Alas* alas;
	Piloto* piloto;
public:
	Avion(){}
	
	void setNumSerie(int n) { numSerie = n; }
	int getNumSerie() { return numSerie; }
	void setMarca(std::string m) { marca = m; }
	std::string getMarca() { return marca; }
	void setModelo(std::string m) { modelo = m; }
	std::string getModelo() { return modelo; }
	void setMotor(Motor* m) { motor = m; }
	Motor* getMotor() { return motor; }
	void setAlas(Alas* a) { alas = a; }
	Alas* getAlas() { return alas; }
	void setPiloto(Piloto* p) { piloto = p; }
	Piloto* getPiloto() { return piloto; }
};