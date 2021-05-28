#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Ficha.h"

using namespace std;


class Libro
{
    public:
        Libro(string gen, string col, int edad, Ficha datos);
        Libro(string gen, string col, int edad);
        void consulDatos();
        string getDisponible();
        void setPrestado();
    private:
        string genero;
        string color;
        int edadMinima;
        string disponible;
        Ficha bibliografia;
};

Libro :: Libro(string gen, string col, int edad, Ficha datos)
: genero(gen), color(col), edadMinima(edad), bibliografia(datos)
{
    disponible= "Disponible";
}

Libro :: Libro(string gen, string col, int edad)
{
    genero= gen;
    color= col;
    edadMinima= edad;
}

void Libro :: consulDatos(){
    cout << "Género: " << genero << endl;
    cout << "Color del libro: " << color << endl;
    cout << "Edad mínima de lectura: " << edadMinima << " años" << endl;
    cout << "Bibliografía:  " << endl;
    bibliografia.consulCaracteristicas();
    cout << "\nDisponibilidad: " << disponible << endl;
}

string Libro :: getDisponible(){
    return disponible;
}

void Libro :: setPrestado(){
    int random, ide, folio;
    disponible = "No disponible";
    random= rand() % 200 + 100;
    ide = bibliografia.getId();
    folio= ide + random;
    cout << "Su folio de préstamo es: " << folio << endl;
    cout << "\n";
}

class Revista: public Libro
{
    private:
        string editorial;
        string nombre;
        int edicion;
        string estatus;
        int id;
    public: 
        void datosRevista();
        void setPrestamo();
        string getDisponibilidad();
        Revista(string gen, string col, int edad, string edito, string nomb, int edici, int iden):Libro(gen, col, edad){
            editorial= edito;
            nombre= nomb;
            edicion= edici;
            id= iden;
            estatus= "Disponible";
        }
};

void Revista :: datosRevista(){
    cout << "ID: " << id << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edición #" << edicion << endl;
    cout << "Estatus: " << estatus << endl;
    cout << "\n";
}

string Revista :: getDisponibilidad(){
    return estatus;
}

void Revista :: setPrestamo(){
    int random, folio;
    estatus= "No disponible";
    random= rand() % 200 + 100;
    folio= id + random;
    cout << "Su folio de préstamo es: " << folio << endl;
    cout << "\n";
}

#endif
