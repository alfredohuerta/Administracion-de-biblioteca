/*
* Erick Alfredo García Huerta
* A01708119
* 
* Proyecto Administración de Biblioteca
*/

#include <iostream>
#include <string>
#include <stdio.h>

#include "Ficha.h"
#include "Texto.h"
#include "Fila.h"
#include "Librero.h"
#include "Biblioteca.h"

using namespace std;

int main(){
    string nombre;
    cout << "Ingrese el nombre de la biblioteca: ";
    cin >> nombre; 
    cout << "\n";
    
    Biblioteca central("nombre");
    central.crearBiblioteca();
    central.menuUsuario();

}
