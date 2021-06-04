/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Computadora
    Esta clase se enfoca en construir y configurar las computadoras 
    que están ligadas a los escritorios.
*/

#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <string>

using namespace std;

class Computadora
{
    private:
        int idComputadora;
        bool ayuda;
        string encendida;
    public:
        void encenderCompu();
        void apagarCompu();
        void solApoyo();
        void getDatos();
        Computadora(int ide);
};

Computadora :: Computadora(int ide){
    idComputadora= ide;
    ayuda= false;
    encendida= "apagada";
}

void Computadora :: encenderCompu(){
    encendida= "encendida";
    cout << "La computadora se encuentra "<< encendida << endl;
}

void Computadora :: apagarCompu(){
    encendida= "apagada";
    cout << "La computadora se encuentra " << encendida << endl;
}

void Computadora :: getDatos(){
    cout << "ID Computadora: " << idComputadora << endl;
    cout << "Estado: " << encendida << endl;
}

//Cambio del valor booleano de ayuda.
void Computadora :: solApoyo(){
    ayuda= true;
    cout << "El técnico va en camino." << endl;
}

#endif