/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Librero
    Esta clase crea las filas donde se almacenarán las filas y se mostrarán sus datos.
*/

#ifndef LIBRERO_H
#define LIBRERO_H

#include <iostream>
#include <string>

#include "Ficha.h"
#include "Libro.h"
#include "Fila.h"

using namespace std;

const int maxFilas= 6;

class Librero 
{
    public:
        Librero(int id, string sector);
        Librero();
        //Destructor de objetos
        ~Librero(){
            for (int i = 0; i < noFila; i++){
                delete filas[i];
            }
        };
        virtual void llenarLibrero();
        virtual void mostrarDatosLibrero();
        virtual void getPrestarLibros();
        virtual void getPrestarRevistas();
        virtual void getDatosFila();
        void getLibreros();

    private:
        string seccion;
        int noLibrero;
        int noFila;
        int capacidad;
        Fila *filas[maxFilas];

};

Librero :: Librero(int id, string sector)
: noLibrero(id), seccion(sector)
{
    noFila= 0;
    *filas[noFila];
    capacidad= 6;
}

/*
* Función que devuelve los datos del librero en la  clase Biblioteca
*/
void Librero :: getLibreros(){
    cout << "Sección: " << seccion << endl;
    cout << "Número de librero: " << noLibrero << endl;
}

/*
* Esta función genera objetos tipo Fila y objetos tipo Libro que se asignarán al arreglo de la fila
* para modificar los libros que aparecen, se deben modificar el contructor en la clase fila
*/
void Librero :: llenarLibrero(){
    filas[noFila]= new Fila(noFila);
    filas[noFila]->llenarFila(); 
    noFila++;
}

/*
* Esta función muestra los datos que se almacenan en el librero mediante un ciclo for
* sólo sirve para visualizar en pantalla lo que almacena la fila.
*/
void Librero :: mostrarDatosLibrero(){
    cout << "Sección: " << seccion << endl;
    for (int i = 0; i < noFila; i++){
        filas[i]->mostrarDatos();
    }
}

/*
* Esta función es un intermediario para mostrar los datos específicos de un libro.
* Apunta a un apuntador en la clase libro.
*/
void Librero :: getDatosFila(){
    int fila;
    cout << "Ingrese la fila: ";
    cin >> fila;
    filas[fila]->mostrarDatosIndv();
}

void Librero :: getPrestarLibros(){
    int fila;
    cout << "Ingrese el número de fila: ";
    cin >> fila;
    filas[fila]->getPrestarLibros();
}

void Librero :: getPrestarRevistas(){
    int fila;
    cout << "Ingrese el número de fila: ";
    cin >> fila;
    filas[fila]->getPrestarRevista();
}

#endif
