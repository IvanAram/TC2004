#include <iostream>
#include "Restaurante.h"



int main()
{
    Restaurante* r = Restaurante::getRestaurante();
    r->menuPrincipal();
    delete r;
}

