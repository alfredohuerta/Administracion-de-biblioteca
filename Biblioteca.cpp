#include "Libro.h"
#include "Ficha.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Ficha nostalgia("Xavier Villaurrutia", "Nostalgia de la muerte", "Fondo de cultura económica", "México", "Español", 317, 001);
    Libro libro1("Poesía", "Verde oliva", 15, nostalgia);
    libro1.consulDatos();
    //Revista natGeo("Ciencias naturales", "negro", 10, "National geographic", "National Geograpchic", 15);
    //natGeo.datosRevista();
}