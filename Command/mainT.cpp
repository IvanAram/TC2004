//LOS QUE NO TERMINEN EN T SON LOS QUE NO SON CON APUNTADORES A FUNC
#include <iostream>
#include "CommandT.h"
using namespace std;

template <class T>
T sum(T* arr, int size){
    T acum = 0;
    for(int i=0; i<size; i++) acum += arr[i];
    return acum;
    
    
}

typedef int(*signature)(int*, int);

int main(){
    double* arrD = new double[5]{2.1,3.5,2.3,4.3,};
    char* arrC = new char[4]{'I','V','A','N'};
    int* arrI = new int[2]{12, 22};
    CommandT c;
    
    cout << c.execute<double, double(*)(double*, int)> (arrD, 5, sum) << endl;
    
    cout << c.execute<char, char(*)(char*, int)> (arrC, 4, sum) << endl;
    
    cout << c.execute<int, signature> (arrI, 2, sum) <<endl;
    
    //ejemplo apuntadores a funciones
    signature f = &sum<int>;
    cout << f(arrI, 2) << endl;
}