#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
#include "Ficha.h"

using namespace std;

class Libro
{
    public:
        Libro(string gen, string col, int edad, Ficha datos);
        Libro(string gen, string col, int edad);
        void consulDatos();
        //void get_datos(); 
    private:
        string genero;
        string color;
        int edadMinima;
        Ficha bibliografia;
};

Libro :: Libro(string gen, string col, int edad, Ficha datos)
: genero(gen), color(col), edadMinima(edad), bibliografia(datos)
{
}

/*Libro :: Libro(string gen, string col, int edad)
{
    genero= gen;
    color= col;
    edadMinima= edad;
}*/

void Libro :: consulDatos(){
    cout << "Género: " << genero << endl;
    cout << "Color del libro: " << color << endl;
    cout << "Edad mínima de lectura: " << edadMinima << " años" << endl;
    cout << "Bibliografía  " << endl;
    bibliografia.consulCaracteristicas();
}

/*void Libro :: get_datos(string gen, string col, int edad){
    genero= gen;
    color= col;
    edadMinima= edad;
}*/

/*class Revista: public Libro
{
    private:
        string editorial;
        string nombre;
        int edicion;
    public: 
        void datosRevista();
        Revista(string gen, string col, int edad, string edito, string nomb, int edici):Libro(gen, col, edad){
            editorial= edito;
            nombre= nomb;
            edicion= edici;
        }
};

void Revista :: datosRevista(){
    cout << "Editorial: " << editorial << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edición #" << edicion << endl;
}*/

#endif