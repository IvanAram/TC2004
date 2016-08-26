#pragma once

#include <iostream>
#include "Avion.h"

class Builder{
protected:
	Avion* avion;
public:
	Avion* getAvion(){ return avion; }
	void createAvion(){ avion = new Avion; }

	virtual void buildAlas() = 0;
	virtual void buildMotor() = 0;
	virtual void buildModelo() = 0;
	virtual void buildNumSerie() = 0;
	virtual void buildMarca() = 0;
};