#include "Computer.h"
#include "ConcreteFactory.h"

int main(){
	std::string computer;
	std::cout<<"Que computadora quiere: ";
	std::cin>>computer;
	Computer* pedido = ConcreteFactory::getFactory()->createComp(computer);
}
