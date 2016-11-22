#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "Producto.h"
#include "Almacenista.h"
#include <fstream>

class Almacen{
private:
	Almacen(){ load(); }
	static Almacen* almacen;
	std::vector <Producto*> productos;
	Empleado* admin;
public:
	~Almacen(){ save(); }
	static Almacen* getAlmacen();
	Empleado* getEmpleado(){ return admin; }
	void setEmpleado(Empleado* e){ admin = e; }
	void buscarProducto(int _id);
	void salidaProducto(int _id, int _cantidad);
	void entradaProducto(int _id, int _cantidad);
	void anadirProducto();
	void alertaCaducidad();
	void alertaStock();
	void alertaStock(Producto* prod);
	void verProductos();
	void save();
	void load();
};

Almacen* Almacen::almacen = nullptr;

void Almacen::buscarProducto(int _id){
	for(int i = 0; i < productos.size(); i++){
		if(productos[i]->getID() == _id){
			std::cout << *productos[i] << std::endl;
			return;
		}
	}
	std::cout << "No se encontro el producto buscado." << std::endl;
}

void Almacen::entradaProducto(int _id, int _cantidad){
	Producto* current = nullptr;
	for(int i = 0; i < productos.size(); i++){
		if(productos[i]->getID() == _id){
			current = productos[i];	
			break;
		}
	}
	if(!current){
		std::cout << "No existe ese producto en el almacen." << std::endl;
		return;
	}
	current->setCantidad(current->getCantidad() + _cantidad);
	alertaStock(current);
}

void Almacen::salidaProducto(int _id, int _cantidad){
	Producto* current = nullptr;
	for(int i = 0; i < productos.size(); i++){
		if(productos[i]->getID() == _id){
			current = productos[i];	
			break;
		}
	}
	if(!current){
		std::cout << "No existe ese producto en el almacen." << std::endl;
		return;
	}
	if(_cantidad > current->getCantidad()){
		std::cout << "No hay suficiente producto." << std::endl;
		return;
	}
	current->setCantidad(current->getCantidad() - _cantidad);
	alertaStock(current);
	current = nullptr;
}

void Almacen::anadirProducto(){
	char op;
	std::string _nombre;
	int _cantidad, _id;
	std::cout << "Nombre: " << std::endl;
	std::cin >> _nombre;
	std::cout << "Cantidad: " << std::endl;
	std::cin >> _cantidad;
	if(productos.size() == 0) _id = 1;
	else _id = productos.back()->getID() + 1;
	productos.push_back(Producto::newProduct(_id, _nombre, _cantidad));
}

Almacen* Almacen::getAlmacen(){
	if(!almacen) almacen = new Almacen();
	return almacen;
}

void Almacen::alertaCaducidad(){
	time_t now = time(0);
	tm* lt = localtime(&now);
	date hoy(lt->tm_mday, 1 + lt->tm_mon, 1900 + lt->tm_year);
	for(int i = 0; i < productos.size(); i++) productos[i]->checarCaducidad(hoy);
}

void Almacen::alertaStock(){
	for(int i = 0; i < productos.size(); i++){
		if(productos[i]->getCantidad() <= 10) std::cout << "Quedan menos de 10 unidades de: " << productos[i]->getNombre() << std::endl;
	}
}

void Almacen::alertaStock(Producto* prod){
	if(prod->getCantidad() <= 10) std::cout << "Quedan menos de 10 unidades de: " << prod->getNombre() << std::endl;
}

void Almacen::verProductos(){
	for(int i = 0; i < productos.size(); i++){
		std::cout << *productos[i] << std::endl;
	}
}

void Almacen::save(){
	std::ofstream out;
	out.open("almacen.txt");
	out << admin->getName() << " " << admin->getSueldo() << std::endl;
	out << productos.size() << std::endl;
	for(int i = 0; i < productos.size(); i++){
		out << productos[i]->getID() << " " << productos[i]->getNombre() << " " << productos[i]->getCantidad() << " ";
		out << productos[i]->getDate().day << " " << productos[i]->getDate().month << " " << productos[i]->getDate().year << std::endl;
	}
	out.close();
}

void Almacen::load(){
	std::ifstream in;
	in.open("almacen.txt");
	if(in.is_open()){
		Producto* prod;
		std::string n, _nombre;
		int d, m, y, num, _id, _cantidad;
		date fecha;
		float s;
		in >> n >> s;
		admin = new Almacenista(n,s);
		in >> num;
		for(int i = 0; i < num; i++){
			in >> _id >> _nombre >> _cantidad >> d >> m >> y;
			productos.push_back(Producto::newProduct(_id, _nombre, _cantidad, '0'));
			fecha.set(d,m,y);
			productos[i]->setDate(fecha);
		}
		in.close();
	}
}
