#include "Command.h"

template <class T, class F>
class Sum : public Command<T,F> {
    T execute(T*, int, F);
};

template <class T, class F>
T Sum<T,F>::execute(T* arr, int size, F func){
    T acum = 0;
    for (int i = 0; i < size; i++){
        acum += arr[i];
    }
    return acum;
}