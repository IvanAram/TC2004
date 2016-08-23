#ifndef CLON_H
#define CLON_H

#include "Computer.h"

template <class T,class S>
class Clon : public Computer{
public:
	using T::T;
	
	virtual T* clone(){ return new S(dynamic_cast<S&>(*this)); }
};

#endif