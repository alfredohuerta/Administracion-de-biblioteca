/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Libro
    Esta clase construye la clase libro y su clase heredada revista además de estar conectada con la clase Ficha y Fila.
    Su función es crear los objetos que se albergarán en las filas.
*/

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
        //Constructor para la clase Libro y contiene datos de la clase Ficha.
        Libro(string gen, string col, int edad, Ficha datos, int ident);
        //Constructor que le heredará las características a la clase revista
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
        int id;
};

//Asignación de datos para el constructor de los libros que se liga con la clase Ficha
Libro :: Libro(string gen, string col, int edad, Ficha datos, int ident)
: genero(gen), color(col), edadMinima(edad), bibliografia(datos)
{
    id= ident;
    disponible= "Disponible";
}

//Asignación de datos para el constuctor que heredará a Revista
Libro :: Libro(string gen, string col, int edad)
{
    genero= gen;
    color= col;
    edadMinima= edad;
}

/*
* Función que muestra en pantalla las características de un libro.
* bibliografía liga esta clase con la clase ficha para mostrar los datos que se almacenan ahí
*/
void Libro :: consulDatos(){
    cout << "Género: " << genero << endl;
    cout << "Color del libro: " << color << endl;
    cout << "Edad mínima de lectura: " << edadMinima << " años" << endl;
    cout << "ID: " << id << endl;
    cout << "Bibliografía:  " << endl;
    bibliografia.consulCaracteristicas();
    cout << "Disponibilidad: " << disponible << endl;
    cout << "\n";
}

string Libro :: getDisponible(){
    return disponible;
}

void Libro :: setPrestado(){
    int random, folio;
    disponible = "No disponible";
    random= rand() % 200 + 100;
    folio= id + random;
    cout << "Su folio de préstamo es: " << folio << endl;
    cout << "\n";
}

//Clase Revista que hereda de Libro
class Revista: public Libro
{
    private:
        string editorial;
        string nombre;
        int edicion;
        string estatus;
        int id;
    public: 
        void consulDatos();
        void setPrestado(); //hacer igual que la clase de libro
        string getDisponibilidad();
        //Constructor que marcaqué datos se obtendrán de la clase padre
        Revista(string gen, string col, int edad, string edito, string nomb, int edici, int iden):Libro(gen, col, edad){
            editorial= edito;
            nombre= nomb;
            edicion= edici;
            id= iden;
            estatus= "Disponible";
        }
};

/*
* Esta función muestra los datos de una revista en pantalla y cumple la misma función 
* que su homonima en la clase libro.
*/
void Revista :: consulDatos(){
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

/*
* Esta función genera un folio aleatoriamente tras haber cambiado el estado del libro 
* de disponible a no disponible
*/
void Revista :: setPrestado(){
    int random, folio;
    estatus= "No disponible";
    random= rand() % 200 + 100;
    folio= id + random;
    cout << "Su folio de préstamo es: " << folio << endl;
    cout << "\n";
}

#endif
