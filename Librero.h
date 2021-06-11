/*
* Erick Alfredo García Huerta
* A01708119
* 
* Proyecto Administración de Biblioteca -> clase Librero
* 
* La clase Librero almacena las filas que a su vez almacenan los textos. Ésta recibe un número de identificación y una 
* temática a cada librero para facilitar la navegación. Además incluye una función que permite construir fila a fila
* el librero e irlo llenando de libros.
*/

#ifndef LIBRERO_H
#define LIBRERO_H

#include <stdio.h>
#include <string>
#include <iostream>

#include "Texto.h"
#include "Fila.h"

using namespace std;

const int maxFilas= 6;

class Librero{
    private:
        string seccion;
        int noLibrero;
        int noFila;
        Fila *filas[maxFilas];
    public:
        Librero();
        Librero(int numeroLibrero, string nombreSeccion);
        ~Librero(){
            for(int i= 0; i<maxFilas; i++){
                delete filas[i];
            }
        }
        void crearEjemplos();
        void setPrestar();
        void getLibrosFila();
        void getRevistasFila();
        void getDisponiblesFila();
        void getPrestadosFila();
        void getDatos();
        void crearFila();
};

Librero :: Librero(){
    seccion= "";
    noFila= 0;
};

Librero :: Librero(int numeroLibrero, string nombreSeccion){
    noLibrero= numeroLibrero;
    seccion= nombreSeccion;
    noFila= 0;
};

/*
* crearEjemplos() crea una única fila con cuatro textos en su interior, esto sirve como caso de prueba y es una forma 
* rápida de aplicar las funciones.
* @param: 
* @return: fila.
*/
void Librero :: crearEjemplos(){
    filas[noFila]= new Fila(noFila);
    filas[noFila]->crearEjemplos();
    noFila++;
}

void Librero :: setPrestar(){
    int idFila;
    cout << "Ingrese el numero de fila al que quiere acceder: ";
    cin >> idFila;
    filas[idFila]->setPrestados();
}

void Librero :: getLibrosFila(){
    int idFila;
    cout << "Ingrese el numero de fila al que quiere acceder: ";
    cin >> idFila;
    filas[idFila]->getLibros();
}

void Librero :: getRevistasFila(){
    int idFila;
    cout << "Ingrese el numero de fila al que quiere acceder: ";
    cin >> idFila;
    filas[idFila]->getRevistas();
}

void Librero :: getDisponiblesFila(){
    int idFila;
    cout << "Ingrese el numero de fila al que quiere acceder: ";
    cin >> idFila;
    filas[idFila]->getDisponibles();
}

void Librero :: getPrestadosFila(){
    int idFila;
    cout << "Ingrese el numero de fila al que quiere acceder: ";
    cin >> idFila;
    filas[idFila]->getPrestados();
}

void Librero :: getDatos(){
    cout << "Numero de librero: " << noLibrero << endl;
    cout << "Tematica de la seccion: " << seccion << endl;
    cout << "\n"; 
    for(int i= 0 ; i<noFila ; i++){
        filas[i]->getDatos();
    }
}

/*
* crearFila se lleva a cabo a través de un ciclo while que permite crear múltiples filas, a su vez, conecta con la  
* función crearLibro() de Texto.h, para crear libros y revistas que se almacenarán automáticamente en la fila, al final
* de cada ciclo se le permite al usuario terminarlo antes o se acaba automáticamente una vez el número de filas alcanza
* el límite permitido, esto último como medida de seguridad.
* 
* param: 
* @return: fila[], textos[]
*/
void Librero :: crearFila(){
    bool flag= true;
    int continuar;

    const char *str1= "Bienvenido al llenado del filas\n"
                        "ADVERTENCIA! Se iniciara automaticamente el sistema de registro de textos, por favor ingrese \n"
                        "al menos un texto nuevo en la fila hasta un maximo de 10";
    puts(str1);

    while (flag)
    {
        filas[noFila]= new Fila(noFila);
        filas[noFila]->crearLibros();
        noFila++;

        cout << "Dese llenar otra fila? INGRESE 1 para continuar, INGRESE 2 para terminar: ";
        cin >> continuar;
        if (continuar == 2){
            flag= false;
        }
    }
}

#endif
