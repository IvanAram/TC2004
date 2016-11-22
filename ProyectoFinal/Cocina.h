#pragma once
#include <iostream>
#include "Queue.h"
#include <vector>
#include "Orden.h"

class Cocina{
private:
	Cocina(){ load(); }
	static Cocina* cocina;
	Queue<Orden*> comandas;
	std::vector<Empleado*> cocineros;
public:
	~Cocina(){ save(); }
	static Cocina* getCocina();
	void addCocinero(Empleado* e);
	void addComanda(Orden* o);
	void quitarComanda();
	void verComandas();
	void save();
	void load();
};

void Cocina::save(){
	std::ofstream out;
	out.open("cocina.txt");
	out << cocineros.size() << std::endl;
	for(int i = 0; i < cocineros.size(); i++) out << cocineros[i]->getName() << " " << cocineros[i]->getSueldo() << std::endl;
	out.close();
}

void Cocina::load(){
	std::ifstream in;
	std::string n;
	int num;
	float s;
	Empleado* newCocinero;
	in.open("cocina.txt");
	if(in.is_open()){
		in >> num;
		for(int i = 0; i < num; i++){
			in >> n >> s;
			newCocinero = new Mesero(n,s);
        	addCocinero(newCocinero);
		}
		in.close();
	}
}

Cocina* Cocina::cocina = nullptr;

Cocina* Cocina::getCocina(){
	if(!cocina) cocina = new Cocina();
	return cocina;
}

void Cocina::addCocinero(Empleado* e){
	cocineros.push_back(e);
}

void Cocina::addComanda(Orden* o){
	comandas.push(o);
}

void Cocina::quitarComanda(){
    Node<Orden*>* element = comandas.pop();
    delete element;
}

void Cocina::verComandas(){
	for(int i = 0; i < comandas.size(); i++) std::cout << *comandas.at(i) << std::endl;
}