#include <iostream>
#include "Pena.h"
#include "Hilary.h"
#include "Trump.h"
#include "MVS.h"
#include "Televisa.h"
#include "TVAzteca.h"
#include "RadioFormula.h"
#include "CNNnoticias.h"

int main(){
    Noticiero* mvs = new MVS();
    Presidente* pena = new Pena(mvs, "Pena Nieto");
    mvs->setNoticia("Infracstuctochor");
    mvs->publicar();
    
}