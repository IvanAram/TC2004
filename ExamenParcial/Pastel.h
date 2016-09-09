#pragma once

#include <iostream>

class Pastel{
protected:
	std::string name;
public:
	virtual void crearPastel() = 0;
};