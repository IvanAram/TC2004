#pragma once

#include <iostream>

class Motor{
private:
	std::string marca;
	int numSerie;
	float potencia;
	std::string modelo;
public:
	Motor(){}
	Motor(std::string _marca, std::string _modelo, int _numSerie, float _potencia) : marca(_marca),modelo(_modelo),numSerie(_numSerie),potencia(_potencia) {}
	
	void setMarca(std::string m){ marca = m; }
	std::string getMarca(){ return marca; }
	void setModelo(std::string m){ modelo = m; }
	std::string getModelo(){ return modelo; }
	void setNumSerie(int n){ numSerie = n; }
	int getNumSerie(){ return numSerie; }
	void setPotencia(float p){ potencia = p; }
	float getPotencia(){ return potencia; }
};