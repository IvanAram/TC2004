#pragma once
#include <iostream>
#include <fstream>
#include <map>

class Recetario{
public:
	Recetario(){ load(); }
	~Recetario(){ save(); }
	std::map<std::string, float> recetas;
	std::map<std::string, float>::iterator it;
	void save();
	void load();

	friend std::ostream& operator<< (std::ostream& stream, const Recetario& menu);
};

void Recetario::save(){
	std::ofstream out;
	out.open("recetas.txt");
	out << recetas.size() << std::endl;
	for (it = recetas.begin(); it!=recetas.end(); it++) out << it->first << " " << it->second << std::endl;
	out.close();
}

void Recetario::load(){
	std::ifstream in;
	in.open("recetas.txt");
	if(in.is_open()){
		int numR;
		std::string plato;
		float costo;
		in >> numR;
		for(int i = 0; i < numR; i++){
			in >> plato >> costo;
			recetas[plato] = costo;
		}
		in.close();
	}
}

std::ostream& operator<< (std::ostream& stream, const Recetario& recetario){
	std::map<std::string, float> menu = recetario.recetas;
	for(std::map<std::string, float>::iterator it = menu.begin(); it != menu.end(); it++) 
		stream << "Platillo: " << it->first << "\t| Costo: " << it->second << std::endl;
	return stream;
}