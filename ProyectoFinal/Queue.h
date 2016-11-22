#include <iostream>
#include "Node.h"


template <class T>
class Queue{
private:
	Node<T> * head = nullptr;
	Node<T> * tail = nullptr;
	int length = 0;
public:
	Queue () {}
	Queue (Node<T> * new_node) { head = new_node; tail = new_node; length++; }
	~Queue() { clear(); }

	int size(){ return length; }
	bool isEmpty() { return head == nullptr; }
	Node<T> * top() { return head; }
	Node<T> * pop();
	void push(T data);
	void push(Node<T> * new_node);
	void clear();
	T at(int idx);
};

template <class T>
Node<T> *Queue<T>::pop()
{
	if(head == nullptr)
		return head;
        
    Node<T>* item = head;
    // Update the head in the list
    head = head->getNext();
    // Break the connection to the list
    item->setNext(nullptr);
    // Update the length of the list
    length--;
    return item;
}


template <class T>
void Queue<T>::push(T data)
{
	Node<T> * new_item = new Node<T>(data);
	push(new_item);
}

template <class T>
void Queue<T>::push(Node<T> * new_node)
{
	if(tail == nullptr)
	{
		tail = new_node;
		head = new_node;
	}
	else{
	// Add the new node at the tail
		tail->setNext(new_node);
	// Update the pointer
		tail = new_node;
	}
	length++;
}

template <class T>
void Queue<T>::clear(){
 	Node<T> * item = head;
    while (item != nullptr)
    {
        head = item->getNext();
        delete item;
        item = head;
    }
    length = 0;
    tail = nullptr;
}

template <class T>
T Queue<T>::at(int idx){
	Node<T>* element = head;
	for(int i = 0; i < idx; i++) element = element->getNext();
	return element->getData();
}