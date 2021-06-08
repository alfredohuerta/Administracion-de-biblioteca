/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Librero
    Esta clase crea las filas donde se almacenarán las filas y se mostrarán sus datos.
*/

#ifndef RECEPCION_H
#define RECEPCION_H

#include "Bibliotecario.h"

#include <iostream>
#include <string>

using namespace std;

const int maxBilios= 2;

class Recepcion
{
    private:
        Bibliotecario *bibliotecario[maxBilios];
        int personas;
        int noBibliotecarios;
        int id;
    public:
        Recepcion();
        ~Recepcion(){
            for (int i = 0; i < maxBilios; i++){
                delete bibliotecario[i];
            }
        };
        virtual void creaBibliotecarios();
        void llamarBibliotecario();
        void getDatosRecepcion();
        void regresoBibliotecario();
        int getPersonas();
};

Recepcion :: Recepcion(){
    id= 1;
    personas = 2;
    noBibliotecarios= 0;
    *bibliotecario[noBibliotecarios];
}

int Recepcion :: getPersonas(){
    return personas;
}

/*
* Crea arreglos de objetos bibliotecarios para almacenarlos en la Recepción.
*/
void Recepcion :: creaBibliotecarios(){
    bibliotecario[noBibliotecarios]= new Bibliotecario("Alberto", id, "Recepción", true);
    id++;
    noBibliotecarios++;
    bibliotecario[noBibliotecarios]= new Bibliotecario("Amanda", id, "Libreros", false);
}

/*
* Devuelve los datos específicos de la recepción además de que usa apuntadores y un cliclo for
* para mostrar los datos de los bibliotecarios que se encuentran en ella.
*/
void Recepcion :: getDatosRecepcion(){
    cout << "Bibliotecarios disponibles: " << personas << endl;
    cout << "Datos de los bibliotecarios: " << endl;
    for (int i = 0; i < maxBilios; i++){
        cout << "ID: " << bibliotecario[i]->getId() << endl;
        cout << "Nombre: " << bibliotecario[i]->getNombre() << endl;
        cout << "Ubicación: " << bibliotecario[i]->getSitio() << endl;
        bibliotecario[i]->getDisponibilidad();
        cout << "\n";
    }
}

/*
* La función valida si hay bibliotecarios disponibles y en base a eso muestra aquellos que cumplen las
* características, para después reducir el número de bibliotecarios disponibles y llamar a la función que
*  cambia el sitio de los bibliotecarios y los manda al sitio donde el usuario los necesita.
*/
void Recepcion :: llamarBibliotecario(){
    if (personas >= 0){
        cout << "Bibliotecarios disponibles: " << endl;
        for (int i = 0; i < maxBilios; i++){    
            if (bibliotecario[i]->getDisp() == true){
                cout << bibliotecario[i]->getNombre() << endl;
                bibliotecario[i]->setOcupado();
                personas= personas-1;
                bibliotecario[i]->setSitio();
            }else {
                i++;
            }
        }
    } else{
        cout << "Todos los bibliotecarios están ocupados." << endl;
    }
}

/*
* Esta función vuelve a cambiar el estado del bibliotecario a desocupado después de validar que había un
* bibliotecario ocupado, además de que incrementa el número de personas presentes en la recepción.
*/
void Recepcion :: regresoBibliotecario(){
    if (personas <= 0 ){
        for (int i = 0; i < maxBilios; i++){    
            if (bibliotecario[i]->getDisp() == false){
                bibliotecario[i]->setDesocupado();
                personas++;
            }
        }    
    }
}

#endif
