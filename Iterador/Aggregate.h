#pragma once

#include <iostream>
#include "Iterator.h"
#include "LinkedList.h"

template <class T>
class Iterator;

template <class T>
class Aggregate{
public:	
	Aggregate() : lista(new LinkedList<T>) {}
	~Aggregate(){ delete lista; }
	LinkedList<T>* getLista(){ return lista; }
	void add(T item) { lista->insertTail(item); }
	int find(T item) { return lista->searchIterative(item); }
	void errase(T item);
	Iterator<T>* getIterator(){ return new Iterator<T>(*this); }
private:
	LinkedList<T>* lista;
};

template <class T>
void Aggregate<T>::errase(T item){
	LinkedList<T>* tmp = lista->deleteFromPosition(lista->searchIterative(item));
	delete tmp;
}