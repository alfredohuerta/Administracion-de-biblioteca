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
        void datosMesa();
        void vaciarMesa();
        void setLimpieza();
        string getLimpieza();
        string getEstatus();
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

/*
* Esta función maraca como ocupada una silla de la mesa, pero para hacerlo debe validar que primero
* haya sillas desocupadas, de lo contrario no hará nada más que lanzar un mensaje en pantalla.
*/
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

/*
* Esta función marca como desocupada una silla de la mesa, primero debe validar que haya sillas 
* ocupadas, de lo contrario no hace nada más que mandar un mensaje a la pantalla.
*/
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
    cout << "Para confirmar, ingrese la ID de la mesa: ";
    cin >> temp;
    if (temp == idMesa){
        numLibres= 0;
        estatus= "Ocupada";
    } else{
        cout<< "ID inválida." << endl;
    }
}

//Visualización de los datos de la mesa
void Mesa :: datosMesa(){
    cout << "ID de mesa: " << idMesa << endl;
    cout << "Estado: " << estatus << endl;
    cout << "Estado de limpieza: " << limpieza << endl;
    cout << "Sillas ocupadas: " << numOcupados << endl;
    cout << "Sillas Libres: " << numLibres << endl;
    cout << "\n";
}

/*
* Para vaciar la mesa primero hay que señalar la ID de la mesa como medida de seguridad,
* marcará todas las sillas como desocupadas tras validar que la ID fue ingresada correctamente.
*/
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

/*
* Esta función marca la mesa como necesitada de limpieza, además de que la marca como 
* ocupada.
*/
void Mesa :: setLimpieza(){
    limpieza = "Sucio";
    estatus = "Ocupado";
    cout << "En breve un miembro de intendencia irá a limpiar" << endl;
}

string Mesa :: getLimpieza(){
    return limpieza;
}

string Mesa :: getEstatus(){
    return estatus;
}

#endif
