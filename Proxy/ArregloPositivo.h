#pragma once
#include <iostream>

class Proxy;

class ArregloPositivo {
private:
	Proxy& proxy;
	int* values;
	int size;
public:
	friend class Proxy;
	ArregloPositivo():size(100),values(new int[size]){}
	Proxy& operator[] (int number);
};

Proxy& ArregloPositivo::operator[] (int number){
	return Proxy(*this, number);
}