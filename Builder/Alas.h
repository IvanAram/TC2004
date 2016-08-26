#pragma once

#include <iostream>

class Alas{
private:
	std::string marca;
	int numSerie;
	float hipersustentador;
	std::string modelo;
public:
	Alas(){}
	Alas(std::string _marca, std::string _modelo, int _numSerie, float _hiper) : marca(_marca),modelo(_modelo),numSerie(_numSerie),hipersustentador(_hiper) {}
	
	void setMarca(std::string m){ marca = m; }
	std::string getMarca(){ return marca; }
	void setModelo(std::string m){ modelo = m; }
	std::string getModelo(){ return modelo; }
	void setNumSerie(int n){ numSerie = n; }
	int getNumSerie(){ return numSerie; }
	void setHiper(float h){ hipersustentador = h; }
	float getHiper(){ return hipersustentador; }
};