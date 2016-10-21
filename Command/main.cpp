#include <iostream>
#include "Operaciones.h"

int main(){
    Operaciones<double, int> op;
    double* arrD = new double[5]{2.1,3.5,2.3,4.3,1.4};
    Command<double,int>* c = op.getOp("suma");
    cout << c->execute(arrD, 5, 0) << endl;
    op.push("resta", );
}