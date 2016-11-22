#pragma once
#include <iostream>
#include "date.h"

class Producto{
private:
	int id;
	std::string nombre;
	int cantidad;
	std::string descripcion;
	date caducidad;
	Producto(int i, std::string n, int c, char l) : id(i), nombre(n), cantidad(c) {}
	Producto(int _id, std::string _nombre, int _cantidad) : id(_id), nombre(_nombre), cantidad(_cantidad) { setDate(); }
	Producto(int _id, std::string _nombre, int _cantidad, std::string _descripcion) : id(_id), nombre(_nombre), cantidad(_cantidad), descripcion(_descripcion) { setDate(); }
public:
	static Producto* newProduct(int _id, std::string _nombre, int _cantidad, char l){ return new Producto(_id, _nombre, _cantidad, l); }
	static Producto* newProduct(int _id, std::string _nombre, int _cantidad){ return new Producto(_id, _nombre, _cantidad); }
	static Producto* newProduct(int _id, std::string _nombre, int _cantidad, std::string _descripcion){ return new Producto(_id, _nombre, _cantidad, _descripcion); }
	int getID(){ return id; }
	void setID(int _id){ id = _id; }
	std::string getNombre(){ return nombre; }
	void setNombre(std::string _nombre){ nombre = _nombre; }
	int getCantidad(){ return cantidad; }
	void setCantidad(int _cantidad){ cantidad = _cantidad; }
	std::string getDescripcion(){ return descripcion; }
	void setDescripcion(std::string _descripcion){ descripcion = _descripcion; }
	void setDate();
	void setDate(date d){ caducidad = d; }
	date getDate(){ return caducidad; }
	void checarCaducidad(date dia);

	friend std::ostream& operator<< (std::ostream& stream, const Producto& other);
};

void Producto::setDate(){
	std::cout << "Ingrese fecha de caducidad.\nDIA [dd]: ";
	std::cin >> caducidad.day;
	std::cout << "\nMES [mm]: ";
	std::cin >> caducidad.month;
	std::cout << "\nYEAR [yyyy]: ";
	std::cin >> caducidad.year;
	std::cout << "\nRegistrado." << std::endl;
}

std::ostream& operator<< (std::ostream& stream, const Producto& other){
	stream << "ID: " << other.id << "\nNombre: " << other.nombre << "\nCantidad: " << other.cantidad;
	stream << "\nDescripcion: " << other.descripcion << "\nFecha de caducidad: " << other.caducidad;
	return stream;
}

void Producto::checarCaducidad(date dia){
	if((caducidad.year == dia.year && caducidad.month - 1 == dia.month) || (caducidad.year - 1 == dia.year && caducidad.month == 1 && dia.month == 12))
		std::cout << "El producto: " << nombre << " esta proximo a caducar!" << std::endl;
}