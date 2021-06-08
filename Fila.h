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
        virtual void getPrestarLibros();
        virtual void llenarFila();
        virtual void mostrarDatos();
        virtual void getPrestarRevista();
        virtual void mostrarDatosIndv();
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
    fichas[numfichas];
    libros[numlibros];
    revistas[numrevistas];
}

/*
* Crea arreglos de objetos libro, revista y fichas bibliográficas para almacenarlos en las filas.
* Se implementa a la par que la función llenarlibrero en la clase librero. Estos obketos son casos de prueba
* por loque no pueden agregarse más sin modificar el código, para crear exitosamente un libro se debe
* crear una ficha bibliográfica y después añadirsela al objeto libro.
*/
void Fila :: llenarFila(){
    fichas[numfichas]= new Ficha("Xavier Villaurrutia", "Nostalgia de la muerte", 
        "Fondo de cultura económica", "México", "Español", 317);
    numfichas++;
    libros[numlibros]= new Libro("Poesía", "Verde oliva", 15, *fichas[numlibros], numlibros);
    numlibros++;
    fichas[numfichas]= new Ficha("Efraín Huerta", "Poesía completa", "Fondo de cultura económica",
        "México", "Español", 500);
    numfichas++;
    libros[numlibros]= new Libro("Poesía", "Blanco", 15, *fichas[numlibros], numlibros);
    numlibros++;
    revistas[numrevistas]= new Revista("Ciencias naturales", "negro", 10, 
        "National geographic", "National Geograpchic", 15, numrevistas);
    numrevistas++;
    revistas[numrevistas]= new Revista("Ciencias naturales", "rojo", 15, 
        "Muy Interesante Mx", "Muy interesante", 3, numrevistas);
}

/*
* Muestra en pantalla los datos de los arreglos de libros y revistas mediante un ciclo for
*/
void Fila :: mostrarDatos(){
    cout << "Libros: " << endl;
    for (int i = 0; i < numlibros; i++){
        libros[i]->consulDatos();
    }
    cout << "\nRevistas: " << endl;
    for (int i = 0; i < numlibros; i++){
        revistas[i]->consulDatos();
    }
}

/*
* MUestra los datos individuales de libros o revistas, para recibir la respuesta se debe ingresar
* el número de identificación del libro o revista.
*/
void Fila :: mostrarDatosIndv(){
    int no, respuesta;
    cout << "\nSi desea encontrar un libro, INGRESE 1" << endl;
    cout << "Si desea encontrar una revista, INGRESE 2" << endl;
    cout << "¿Qué desea?: ";
    cin >> respuesta;
    switch (respuesta)
    {
    case 1:
        cout << "Ingrese la ID del libro: ";
        cin >> no;
        cout << "\n";
        libros[no]->consulDatos();
        break;
    case 2:
        cout << "Ingrese la ID de la revista: ";
        cin >> no;
        cout << "\n";
        revistas[no]->consulDatos();
        break;
    default:
        break;
    }
}

void Fila :: getPrestarLibros(){
    int libro;
    cout << "Ingrese la ID del libro: ";
    cin >> libro;
    libros[libro]->setPrestado();
}

void Fila :: getPrestarRevista(){
    int revista;
    cout << "Ingrese la ID de la revista: ";
    cin >> revista;
    revistas[revista]->setPrestado();
}

#endif
