/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Escritorio
    Esta clase almacena a la clase computadora, además de que crea 
    y configura los escritorios de la biblioteca.
*/

#ifndef ESCRITORIO_H
#define ESCRITORIO_H

#include <iostream>
#include <string>

#include "Computadora.h"

using namespace std;

const int maxComp= 1;

class Escritorio
{
    public:
        Escritorio(int idEsc, bool compu);
        //destructor de los objetos new.
        ~Escritorio(){
            delete compus[noComputadora];
        };
        void ocuparEscritorio();
        void computo();
        virtual void asignarCompu();
        virtual void solicitarAyuda();
        void datosEscritorio();
    private:
    Computadora *compus[maxComp];
    string estado;
    int idEscritorio;
    bool computadora;
    int noComputadora;
};

Escritorio :: Escritorio(int idEsc, bool compu){
    idEscritorio= idEsc;
    estado= "libre";
    computadora= compu;
    noComputadora= 0;
}

void Escritorio :: ocuparEscritorio(){
    estado= "ocupado";
    cout << "El escritorio se encuentra " << estado << " por usted." << endl;
}

//Validación por medio de un if de la presencia de computadoras
void Escritorio :: computo(){
    if (computadora == true){
        cout << "Este escritorio cuenta con una computadora." << endl;
    } else {
        cout << "Este escritorio no cuenta con computadora." << endl;
    }
}

//Creación de computadora dentro de la clase escritorio, no todos los escritorios tienen computadoras, así que debe validar.
void Escritorio :: asignarCompu(){
    if (computadora == true){
        compus[noComputadora]= new Computadora(noComputadora);
    } else{
        cout << "Este escritorio no puede albergar computadoras." << endl;
    }
}

//Devuelve las especificacionesdel objeto, aunque también valida si hay o no computadora en el escritorio.
void Escritorio :: datosEscritorio(){
    cout << "Id de escritorio: " << idEscritorio << endl;
    cout << "Estado: " << estado << endl;
    if (computadora == true){
        cout << "Tiene computadora." << endl;
        cout << "Datos de la computadora: " << endl;
        compus[noComputadora]->getDatos();
    } else{
        cout << "No tiene computadora." << endl;
    }
}

void Escritorio :: solicitarAyuda(){
    compus[noComputadora]->solApoyo();
}

#endif