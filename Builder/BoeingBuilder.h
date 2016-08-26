#pragma once

#include <iostream>
#include "Builder.h"
#include "Alas.h"
#include "Motor.h"

class BoeingBuilder : public Builder{
public:
	void buildAlas();
	void buildMotor();
	void buildModelo();
	void buildNumSerie();
	void buildMarca();
};

void BoeingBuilder::buildAlas(){
	avion->setAlas(new Alas("Ivan Corp","Boeing",291,38.0f));
}

void BoeingBuilder::buildMotor(){
	avion->setMotor(new Motor("Ivan Corp","Boeing",747,120000.0f));
}

void BoeingBuilder::buildModelo(){
	avion->setModelo("Boeing");
}

void BoeingBuilder::buildNumSerie(){
	avion->setNumSerie(117);
}

void BoeingBuilder::buildMarca(){
	avion->setMarca("Ivan Corp");
}
