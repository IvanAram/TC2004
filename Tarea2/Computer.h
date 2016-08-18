#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>

class Computer{
public:	
	virtual void selecComp() = 0;
	virtual void ensamComp() = 0;
	virtual void instSoft() = 0;
	virtual void empaqComp() = 0;
};

#endif
