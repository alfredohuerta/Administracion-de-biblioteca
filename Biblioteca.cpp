/*
Alumno: Erick Alfredo García Huerta
Matrícula: A01708119
*/

#include <iostream>
#include <string>

#include "Libro.h"
#include "Ficha.h"
#include "Fila.h"
#include "Librero.h"

using namespace std;

int main() {
    Librero librero1(1, "Poesía");
    librero1.llenarLibrero();
    librero1.mostrarDatosLibrero();
}
