#pragma once

#include <iostream>

class Pastel{
protected:
	std::string name;
public:
	virtual void crearPastel() = 0;
	virtual std::string getName() = 0;
	virtual void setName(std::string) = 0;
};