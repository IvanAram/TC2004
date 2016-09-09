#pragma once

#include <iostream>
#include "Builder.h"

class ACBuilder : public Builder{
public:
	void buildIngredientes();
};

void ACBuilder::buildIngredientes(){
	std::cout<<"Consiguiendo leche, huevo y mantequilla."<<std::endl;
}
