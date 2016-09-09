#pragma once

#include "Pastel.h"

template <class T,class S>
class Clon : public Pastel{
public:
	using T::T;
	
	virtual T* clone(){ return new S(dynamic_cast<S&>(*this)); }
};
