/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca
*/

#include <iostream>
#include <string>
#include <stdio.h>

#include "Ficha.h"
#include "Libro.h"
#include "Fila.h"
#include "Librero.h"
#include "Mesa.h"
#include "Computadora.h"
#include "Escritorio.h"
#include "Bibliotecario.h"
#include "Recepcion.h"
#include "Biblioteca.h"

using namespace std;

int main() {
    Biblioteca alfa("Alfa"); //Se crea el objeto biblioteca.
    alfa.crearBiblioteca(); //Se crean los componentes de la biblioteca.
    alfa.menuBiblioteca(); //Se llaman el menu de usuario para que se pueda navegar en ella.
}
