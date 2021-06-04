/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Fila
    Esta clase crea las filas donde se almacenarán libros y revistas para después ser almacenada en libreros.
    Usa apuntadores para ligarse a la clase Libro.
*/

#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>

#include "Libro.h"
#include "Ficha.h"

using namespace std;

const int maxFichas= 2;
const int maxLibros= 2;
const int maxRevistas= 2;

class Fila
{
    public:
        //Clases abstractas que funcionan con apuntadores
        virtual void llenarFila();
        virtual void mostrarDatos();
        Fila (int numF);
        //Destructor de los objetos en el heap.
        ~Fila(){
            for (int i = 0; i < numfichas; i++){
                delete fichas[i];
            }
            for (int i = 0; i < numlibros; i++){
                delete libros[i];
            }
            for (int i = 0; i < numrevistas; i++){
                delete revistas[i];
            }
        };
    private:
        int numFila;
        int numfichas;
        int numlibros;
        int numrevistas;
        Ficha *fichas[maxFichas];
        Libro *libros[maxLibros];
        Revista *revistas[maxRevistas];
};

Fila :: Fila (int numF){
    numFila= numF;
    numfichas= 0;
    numlibros= 0;
    numrevistas= 0;
}

//Llenado de la fila  con casos de prueba
void Fila :: llenarFila(){
    fichas[numfichas]= new Ficha("Xavier Villaurrutia", "Nostalgia de la muerte", 
        "Fondo de cultura económica", "México", "Español", 317, numfichas);
    numfichas++;
    libros[numlibros]= new Libro("Poesía", "Verde oliva", 15, *fichas[numlibros]);
    numlibros++;
    revistas[numrevistas]= new Revista("Ciencias naturales", "negro", 10, 
        "National geographic", "National Geograpchic", 15, numrevistas);
    numrevistas++;
}

void Fila :: mostrarDatos(){
    cout << "Libros: " << endl;
    for (int i = 0; i < numlibros; i++){
        libros[i]->consulDatos();
    }
    cout << "\nRevistas: " << endl;
    for (int i = 0; i < numlibros; i++){
        revistas[i]->datosRevista();
    }
}

#endif
