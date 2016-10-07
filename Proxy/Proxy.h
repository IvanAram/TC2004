#pragma once
#include <iostream>
#include "ArregloPositivo.h"

class Proxy{
private:
	ArregloPositivo& arreglo;
	int idx;
public:
	friend class ArregloPositivo;
	Proxy(const ArregloPositivo& _arreglo, int number):arreglo(_arreglo),idx(number){}
	Proxy& operator= (int val);
	int getArr(int i){ return *(arreglo.values + i); }
	int getIdx(){ return idx; }
	friend std::ostream& operator<<(std::ostream& out,const Proxy& obj);
};

Proxy& Proxy::operator= (int val){
	if(val >= 0) 
		*(arreglo.values + idx) = val;
	else 
		std::cout << "Error." << std::endl;
	return *this;
}

std::ostream& operator<< (std::ostream& out,const Proxy& obj){
	out << obj.arreglo.get(obj.getIdx);
	return out;
}
