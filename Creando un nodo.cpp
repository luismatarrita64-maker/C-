#include <iostream>
#include <string.h>
using namespace std;

struct nodo {
   //parte 1 : datos

   int numero;

   //parte 2 : enlace
    nodo* enlace;

};

int main(int argc, char const *argv[]) {
    
    //declarar variable 
    int x = 10; 

    string mensaje; 

    // declarcion de punteros
    int* ptr1 = &x; 

    // imprimir mensaje
    cout << "Este es un mensaje :" ; 

    // leer mensaje
    cin >> mensaje; 
    
    cout << "El mensaje es: " << mensaje << endl;
    
    cout << "El valor de x es: " << x << endl ;

    cout << "El valor del puntero ptr1 es: " << ptr1 << endl ;

    cout << "El valor que hay en la direccion del puntero ptr1 es: " << *ptr1 << endl;

nodo nuevoNodo;
nuevoNodo.numero = 5;
nuevoNodo.enlace = nullptr;


return 0;
}
