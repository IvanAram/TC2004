#include "Command.h"

template <class T, class F>
class Resta : public Command<T,F> {
    T execute(T*, int, F);
};

template <class T, class F>
T Resta<T,F>::execute(T* arr, int size, F func){
    T acum = 0;
    for (int i = 0; i < size; i++){
        acum -= arr[i];
    }
    return acum;
}