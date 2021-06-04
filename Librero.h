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
        //Destructor de objetos
        ~Librero(){
            for (int i = 0; i < noFila; i++){
                delete filas[i];
            }
        };
        virtual void llenarLibrero();
        virtual void mostrarDatosLibrero();

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

void Librero :: llenarLibrero(){
    filas[noFila]= new Fila(1);
    filas[noFila]->llenarFila(); 
    noFila++;
}

void Librero :: mostrarDatosLibrero(){
    cout << "Sección: " << seccion << endl;
    for (int i = 0; i < noFila; i++){
        filas[i]->mostrarDatos();
    }
}

#endif
