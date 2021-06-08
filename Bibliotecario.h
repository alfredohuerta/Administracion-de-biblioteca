/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Bibliotecario
    Esta clase crea los empleados de la biblioteca que pueden cambiar de posisción y disponibilidad a través de los métodos
    set ocupado 
*/

#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

#include <iostream>
#include <string>

using namespace std;

class Bibliotecario
{
    public:
        Bibliotecario(string nom, int Ide, string lugar, bool disponible);
        int getId();
        string getSitio();
        void setSitio();
        void getDisponibilidad();
        void setOcupado();
        bool getDisp();
        string getNombre();
        void setDesocupado();
    private:
        string nombre;
        int id;
        string sitio;
        bool disponibilidad;
};

Bibliotecario :: Bibliotecario(string nom, int ide, string lugar, bool disponible){
    nombre= nom;
    id= ide;
    sitio= lugar;
    disponibilidad= disponible;
}

/*
Los getters y setters que se plantean a continuación son para su imprementación en la 
clase Recepción y en la clase Biblioteca.
*/

string Bibliotecario :: getNombre(){
    return nombre;
}

int Bibliotecario :: getId(){
    return id;
}

string Bibliotecario :: getSitio(){
    return sitio;
}

bool Bibliotecario :: getDisp(){
    return disponibilidad;
}

/*
* Esta función cambia la variable sitio de los bibliotecarios además de que señala a dónde ha sido enviado
*/
void Bibliotecario :: setSitio(){
    cout << "En donde necesita la ayuda? (Escriba el nombre de su ubicacion): ";
    cin >> sitio;
    cout << nombre << " se dirige a: " << sitio << endl;
}

void Bibliotecario :: getDisponibilidad(){
    if (disponibilidad == true){
        cout << "Disponible" << endl;
    } else{
        cout << "Ocupado" << endl;
    }
}

void Bibliotecario :: setOcupado(){
    disponibilidad= false;
}

void Bibliotecario :: setDesocupado(){
    disponibilidad= true;
}

#endif
