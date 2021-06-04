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
        Bibliotecario(string nom, int Ide, string lugar);
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

Bibliotecario :: Bibliotecario(string nom, int ide, string lugar){
    nombre= nom;
    id= ide;
    sitio= lugar;
    disponibilidad= true;
}

/*
Los getters y setters que se plantean a continuación son para su imprementación en la 
clase Recepción y el main.
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

void Bibliotecario :: setSitio(){
    cout << "Ingrese su posición: ";
    cin >> sitio;
    cout << "Su nueva posición es: " << sitio << endl;
}

void Bibliotecario :: getDisponibilidad(){
    if (disponibilidad == true){
        cout << "Disponible" << endl;
    } else{
        cout << "Ocupado" << endl;
    }
}

void Bibliotecario :: setOcupado(){
    cout << "¿A dónde se dirige? ";
    cin >> sitio;
    disponibilidad= false;
}

void Bibliotecario :: setDesocupado(){
    disponibilidad= true;
}

#endif