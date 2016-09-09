#pragma once

#include <iostream>
#include "Builder.h"

class DFBuilder : public Builder{
public:
	void buildIngredientes();
};

void DFBuilder::buildIngredientes(){
	std::cout<<"Consiguiendo chocolate, frutas y merengues."<<std::endl;
}
