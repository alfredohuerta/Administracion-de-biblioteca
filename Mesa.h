/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Mesa
    Esta clase construye la clase mesa y permite hacer uso de las sillas,
     apartarse y cambiar de estatus de disponibilidad
*/

#ifndef MESA_H
#define MESA_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Mesa
{
    public:
        Mesa(int ident);
        void ocuparSilla();
        void desocuparSilla();
        void apartarMesa();
        string datosMesa();
        void vaciarMesa();
        void cambiarEstatus();
    private:
        int idMesa;
        string limpieza;
        int numSillas;
        int numOcupados;
        int numLibres;
        string estatus;
};

Mesa :: Mesa(int ident){
    idMesa= ident;
    limpieza= "Limpia";
    numSillas= 10;
    numOcupados= 0;
    numLibres= 10;
    estatus= "Libre";
}

void Mesa :: ocuparSilla(){
    if (numLibres <= numSillas){
        numLibres= numLibres-1;
        numOcupados++;
        cout << "Sillas ocupadas: " << numOcupados << endl;
        cout << "Sillas desocupadas: " << numLibres << endl;
    } else {
        cout << "Todas las sillas están ocupadas" << endl;
    }
}

void Mesa :: desocuparSilla(){
    if (numLibres <= numSillas){
        numOcupados= numOcupados-1;
        numLibres++;
        cout << "Sillas ocupadas: " << numOcupados << endl;
        cout << "Sillas desocupadas: " << numLibres << endl;
    } else{
        cout << "Todas las sillas están desocupadas" << endl;
    }
}

//Función que marcará TODAS las sillas como ocupadas.
void Mesa :: apartarMesa(){
    int temp;
    cout << "Ingrese la ID de la mesa: ";
    cin >> temp;
    if (temp == idMesa){
        numLibres= 0;
        estatus= "Ocupada";
    } else{
        cout<< "ID inválida." << endl;
    }
}

//Visualización de los datos de la mesa por medio de un stringstream.
string Mesa :: datosMesa(){
    stringstream aux;
    aux << "ID de mesa: " << idMesa << "\nEstado: " << estatus << "\nEstado de limpieza: " << limpieza << 
    "\nSillas ocupadas: " << numOcupados << "\nSillas Libres: " << numLibres << endl;
    return aux.str();
}

//Para vaciar la mesa primero hay que señalar la ID de la mesa como medida de seguridad.
void Mesa :: vaciarMesa(){
    int temp;
    cout << "Ingrese la ID de la mesa: ";
    cin >> temp;
    if (temp == idMesa){
        numOcupados= 0;
        estatus= "Libre";
    } else{
        cout<< "ID inválida." << endl;
    }
}

void Mesa :: cambiarEstatus(){
    if (numLibres >= numSillas){
        estatus= "Libre";
    } else {
        estatus= "Ocupado";
    }
}

#endif