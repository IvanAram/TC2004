#pragma once
#include <iostream>
#include <vector>

class Orden{
private:
	float costo;
	std::vector<std::string> platillos;
	std::vector<float> costoIndividual;
public:
	Orden(){}
	void addPlatillo(std::string nombre, float precio);
	void quitarPlatillo(std::string nombre);
	
	friend std::ostream& operator<< (std::ostream& stream, const Orden& other);
};

void Orden::addPlatillo(std::string nombre, float precio){
	platillos.push_back(nombre);
	costoIndividual.push_back(precio);
	costo += precio;
}

void Orden::quitarPlatillo(std::string nombre){
	for(int i = 0; i < platillos.size(); i++){
		if(platillos[i] == nombre){
			platillos.erase(platillos.begin() + i);
			costo -= costoIndividual[i];
			costoIndividual.erase(costoIndividual.begin() + i);
			return;
		}
	}
}

std::ostream& operator<< (std::ostream& stream, const Orden& other){
	for(int i = 0; i < other.platillos.size(); i++) stream << "Platillo: " << other.platillos[i] << " \t| Costo: " << other.costoIndividual[i] << std::endl;
	return stream;
}