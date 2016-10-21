#include "Sum.h"
#include "Resta.h"
using namespace std;

template <class T, class F>
class Operaciones{
private:
    map<string, Command<T, F>*> operaciones;
    
    map<string, F> operacionesConAp;
public:
    Operaciones();
    Command<T, F>* getOp(string);
    Command<T, F>* getOpAp(string);
    void push(string, F func);
};

template<class T,class F>
Operaciones<T, F>::Operaciones(){
    operaciones.insert(make_pair("suma", new Sum<T,F>() ));
    operaciones.insert(make_pair("resta", new Resta<T,F>() ));
}

template<class T,class F>
Command<T, F>* Operaciones<T, F>::getOp(string op){
    typename map<string, Command<T, F>*>::iterator it;
    it = operaciones.find(op);
    if(it != operaciones.end()){
        return it->second;
    }
    else return NULL;
}

template <class T,class F>
void Operaciones<T,F>::push(string s, F func){
    operacionesConAp.insert(make_pair(s,func));
}

template<class T,class F>
Command<T, F>* Operaciones<T, F>::getOpAp(string op){
    typename map<string, Command<T, F>*>::iterator it;
    it = operacionesConAp.find(op);
    if(it != operaciones.end()){
        return it->second;
    }
    else return NULL;
}