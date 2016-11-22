#pragma once
# include <fstream>
#include "Almacen.h"
#include "Administrador.h"
#include "Cocina.h"

class Restaurante{
private:
    void menuAdmin();
    void menuAlmacenista();
    void menuCocinero();
    void menuMesero();
    static Restaurante* restaurante;
    void addMesero(Empleado* e);
    std::vector<Empleado*> meseros;
    Restaurante(){ load(); }
public:
	~Restaurante(){ 
		delete Cocina::getCocina();
		delete Almacen::getAlmacen();
		save(); 
	}
	void save();
	void load();
    void menuPrincipal();
    static Restaurante* getRestaurante();
};

void Restaurante::save(){
	std::ofstream out;
	out.open("restaurante.txt");
	out << meseros.size() << std::endl;
	for(int i = 0; i < meseros.size(); i++) out << meseros[i]->getName() << " " << meseros[i]->getSueldo() << std::endl;
	out.close();
}

void Restaurante::load(){
	std::ifstream in;
	std::string n;
	int num;
	float s;
	Empleado* newMesero;
	in.open("restaurante.txt");
	if(in.is_open()){
		in >> num;
		for(int i = 0; i < num; i++){
			in >> n >> s;
			newMesero = new Mesero(n,s);
        	addMesero(newMesero);
		}
		in.close();
	}
}

Restaurante* Restaurante::restaurante = nullptr;

Restaurante* Restaurante::getRestaurante(){
	if(!restaurante) restaurante = new Restaurante();
	return restaurante;
}

void Restaurante::addMesero(Empleado* e)
{
    meseros.push_back(e);
}

void Restaurante::menuAdmin()
{
    Empleado* admin = new Administrador();
    while(true){
        int op;
        std::cout << "Que desea hacer?\n\t1. Contratar\n\t2. Agregar Receta\n\t3. Pedir producto a almacen\n\t4. Salir" << std::endl;
        std::cin>>op;
        std::cout << "-----------------------------" << std::endl;
        if(op == 1){
            int option;
            std::cout << "1. Mesero\n2. Cocinero\n3. Almacenista" << std::endl;
            std::cin >> option;
            if(option == 1){
                std::string n;
                std::cout << "Ingrese nombre de nuevo cocinero: " << std::endl;
        		std::cin >> n;
        		Empleado* newMesero = new Mesero(n,7000);
        		addMesero(newMesero);
            }
            else if(option == 2 || option == 3) admin->contratar(option);
            else std::cout << "Error" << std::endl;
        }
        else if(op == 2){
            Recetario menu;
            std::string name;
            float costo;
            std::cout << "Ingrese nombre del nuevo platillo: " << std::endl;
            std::cin >> name;
            std::cout << "Ingrese costo del nuevo platillo: " << std::endl;
            std::cin >> costo;
            menu.recetas[name] = costo;
        }
        else if(op == 3){
            int c, i;
            std::cout << "ID del producto: " << std::endl;
            std::cin >> i;
            std::cout << "Cuanto desea pedir: " << std::endl;
            std::cin >> c;
            Almacen::getAlmacen()->salidaProducto(i,c);
        }
        else if(op == 4) break;
    }
}

void Restaurante::menuAlmacenista()
{
	Almacen::getAlmacen()->alertaCaducidad();
	Almacen::getAlmacen()->alertaStock();
    while(true)
    {

       int op;
       std::cout<<"Que desea hacer?\n\t1. Buscar productos\n\t2. Agregar Producto\n\t3. Salida Producto\n\t4. Entrada Producto\n\t5. Ver productos\n\t6. Salir"<<std::endl;
       std::cin >> op;
       std::cout << "-----------------------------" << std::endl;
       if(op == 1) 
       {
           int idprod;
           std::cout<<"Id del producto: ";
           std::cin >> idprod;
           std::cout<< std::endl;
           Almacen::getAlmacen()->buscarProducto(idprod);
       }
       else if (op == 2) 
       {
           Almacen::getAlmacen()->anadirProducto();
       }
       else if(op == 3)
       {
           int idprod, cant;
           std::cout<<"ID Producto: ";
           std::cin>>idprod;
           std::cout<< std::endl;
           std::cout<<"Cantidad: ";
           std::cin>>cant;
           std::cout<< std::endl;
           Almacen::getAlmacen()->salidaProducto(idprod,cant);
       }
       else if(op == 4) {
       	   int idprod, cant;
           std::cout<<"ID Producto: ";
           std::cin>>idprod;
           std::cout<< std::endl;
           std::cout<<"Cantidad: ";
           std::cin>>cant;
           std::cout<< std::endl;
           Almacen::getAlmacen()->entradaProducto(idprod,cant);
       }
       else if(op == 5){
       	   Almacen::getAlmacen()->verProductos();
       }
       else if(op == 6) break;
   }
}

void Restaurante::menuCocinero()
{
	while(true)
	{
	   int op;
	   std::cout<<"Que desea hacer?\n\t1. Terminar comanda\n\t2. Ver comandas\n\t3. Salir"<<std::endl;
	   std::cin>>op;
	   std::cout << "-----------------------------" << std::endl;
	   if(op == 1) 
	        Cocina::getCocina()->quitarComanda();
	   else if(op == 2) 
	        Cocina::getCocina()->verComandas();
	   else if(op == 3)
	        break;
	}
}

void Restaurante::menuMesero()
{
   Empleado* mesero = new Mesero("MESERO",0);
   while(true)
   {
       int op;
       std::cout << "Que desea hacer?\n\t1. Agregar Orden\n\t2. Terminar Orden\n\t3. Ver menu\n\t4. Salir" << std::endl;
       std::cin >> op;
       if(op==1)
            Cocina::getCocina()->addComanda(mesero->tomarOrden());
       else if(op==2)
            mesero->cobrarOrden();
       else if(op == 3)
       		mesero->verMenu();
       else if(op==4) break;
   }        
}

void Restaurante::menuPrincipal()
{
    while(true){
    	int op;
    	std::cout << "Bienvenido.\nQuien es usted?" << std::endl;
    	std::cout << "\t1. Administrador\n\t2. Almacenista\n\t3. Cocinero\n\t4. Mesero\n\t5. Salir" << std::endl;
        std::cin >> op;
        if(op == 5) break;
        std::cout << "-----------------------------" << std::endl;
        switch(op){
            case 1:
                menuAdmin();
                break;
            case 2:
                menuAlmacenista();
                break;
            case 3:
                menuCocinero();
                break;
            case 4:
                menuMesero();
                break;
            default:
                std::cout << "Opcion Invalida" << std::endl;
                break;
        }
    }
}