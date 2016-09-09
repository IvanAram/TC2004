#pragma once

#include <iostream>
#include "Aggregate.h"

template <class T>
class Iterator{
public:
	Iterator(const Aggregate<T>& _lista){
		lista = _lista; // 2 apuntadores a la misma variable
	}
	bool hasNext() { return (pos < lista.getLista()->getLength()); }
	T currentItem();
	T next();
	T first() { return lista.getLista()->getHead()->getData(); }
private:
	Iterator(){}
	Aggregate<T> lista;
	int pos = 0;
};

template <class T>
T Iterator<T>::currentItem(){
	Node<T>* tmp = lista.getLista()->getHead();
	for(int i=0; i<pos; i++) tmp = tmp->getNext();
	return tmp->getData();
}

template <class T>
T Iterator<T>::next(){
	if(pos == 0){
		pos++;
		return lista.getLista()->getHead()->getData();
	}
	Node<T>* tmp = lista.getLista()->getHead();
	for(int i=1; i<pos; i++) tmp = tmp->getNext();
	if(tmp->getNext() != nullptr) {
		pos++;
		return tmp->getNext()->getData();
	}
	else return *(new T);
	
}