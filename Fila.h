/*
* Erick Alfredo García Huerta
* A01708119
* 
* Proyecto Administración de Biblioteca -> clase Fila
* 
* Esta clase genera objetos de tipo fila que puede almacenar cantidades que oscilan entre los 1 y 10 textos por fila
* permite obtener los datos de los textos almacenados en ellas, así como cambiar sus estados de disponibilidad, también
* permite crear desde cero un libro o revista para su almacenamiento en la fila o la creación de un set de ejemplo
*/

#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <string>
#include <iostream>

#include "Texto.h"

using namespace std;

const int maxTextos= 10;

class Fila
{
    private:
        Texto *textos[maxTextos];
        int numFila;
        int numTextos;
    public:
        Fila();
        Fila(int filaID);
        ~Fila(){
            for (int i= 0; i<maxTextos ; i++){
                delete textos[i];
            }
        }
        void crearEjemplos();
        void getDatos();
        void getLibros();
        void getRevistas();
        void getDisponibles();
        void getPrestados();
        void setPrestados();
        void crearLibros();
};

Fila :: Fila(){
    numFila= 0;
    numTextos= 0;
};

Fila :: Fila(int filaID){
    numFila= filaID;
    numTextos= 0;
};

/*
* Esta función crea una par de objetos revista y libro como caso de prueba, no pueden ser
* modificados y su única función es permitir corroborar que el programa funcione correctamente.
* @param:
* @return: Libro, Ficha, Revista.
*/
void Fila :: crearEjemplos(){

    textos[numTextos]= new Libro("Poesia", 15, "verde oliva", "disponible", numTextos, "libro", 
        Ficha("Xavier Villaurrutia", "Nostalgia de la muerte", "Fondo de Cultura Econímica", 300, "mexico", "espanol"));
    numTextos++;

    textos[numTextos]= new Revista("Ciencias", 15, "amarillo", "disponible", numTextos, 
        "revista", "NatGeo", "National Geographic", 15);
    numTextos++;

    textos[numTextos]= new Libro("Mitologia", 10, "beige", "prestado", numTextos, "libro", 
    Ficha("Homero", "La Hiliada", "Porrua", 120, "grecia", "español"));
    numTextos++;

    textos[numTextos]= new Revista("Ciencias", 10, "rojo", "prestado", numTextos, "revista", 
        "Muy Interesante mx", "Muy Interesante Kids", 10);
    numTextos++;
}

void Fila :: getDatos(){
    cout << "Fila #" << numFila << endl;
    cout << "Textos almacenados: \n" << endl;
    for(int i= 0; i<numTextos; i++){
        textos[i]->getDatos();
    }
}

void Fila :: getLibros(){
    cout << "\nLibros en la coleccion: " << endl;
    for (int i=0; i<numTextos; i++){
        if(textos[i]->getTipo() == "libro"){
            textos[i]->getDatos();
            cout << "\n";
        }
    }
}

void Fila :: getRevistas(){
    cout << "\nRevistas en la coleccion: " << endl;
    for (int i=0; i<numTextos; i++){
        if(textos[i]->getTipo() == "revista"){
            textos[i]->getDatos();
            cout << "\n";
        }
    }
}

void Fila :: getDisponibles(){
    cout << "\nArtículos disponibles: " << endl;
    for (int i=0; i<numTextos; i++){
        if(textos[i]->getDisponible() == "disponible"){
            textos[i]->getDatos();
            cout << "\n";
        }else {
            cout << "\n";
        }
    }
}

void Fila :: getPrestados(){
    cout << "\nArtículos prestados: " << endl;
    for (int i=0; i<numTextos; i++){
        if(textos[i]->getDisponible() == "prestado"){
            textos[i]->getDatos();
            cout << "\n";
        }
    }
}

void Fila :: setPrestados(){
    int iDPrestado;
    cout << "Ingrese la ID del articulo que quiere pedir prestado: ";
    cin >> iDPrestado;
    cout << "funciona" << endl;
    textos[iDPrestado]->setPrestado();
}

/*
* creaLibros() recibe datos para crear objetos Libros o revistas dependiendo de las necesidades del usuario, está 
* dominado por un ciclo while que termina cuando el usuario decide dejar de registrar textos o alcanza el límite 
* estipulado en el contador.
* @param: 
* @return: libros y revistas.
*/
void Fila :: crearLibros(){
    int respuesta, continuar;
    bool flag= true;


    while (flag)
    {
        const char *str0= "Bienvenido al menu de registro de libros, por favor seleccione una de las siguientes opciones\n"
                        "ADVERTENCIA! Solo puede crear hasta un maximo de 10 textos por fila, el menu se cerrara al \n"
                        "llegar al limite\n"
                        "1. Registrar un libro.\n"
                        "2. Registrar una revista.\n";
        puts(str0);
        cout << "Que desea hacer?: ";
        cin >> respuesta;

        switch (respuesta)
        {
        case 1: //constructor de libros.
            {
            string generoL, colorL, disponiblilidadL, tipoL, autorL, nombreObraL, editoria_L, paisL, idiomaL;
            int edadL, numPaginasL;

            disponiblilidadL= "disponible";
            tipoL= "libro";

            cout << "\nIngrese los datos que se le piden: " << endl;
            cout << "Genero: ";
            cin >> generoL;
            cout << "\n";

            cout << "Edad minima recomendada (numero entero): ";
            cin >> edadL;
            cout << "\n";

            cout << "Color: ";
            cin >> colorL;
            cout << "\n";

            cout << "Autor: ";
            cin >> autorL;
            cout << "\n";

            cout << "Nombre de la obra: ";
            cin >> nombreObraL;
            cout << "\n";

            cout << "Editorial: ";
            cin >> editoria_L;
            cout << "\n";

            cout << "Numero de paginas (numero entero): ";
            cin >> numPaginasL;
            cout << "\n";

            cout << "Pais de origen: ";
            cin >> paisL;
            cout << "\n";

            cout << "Idioma del libro: ";
            cin >> idiomaL;
            cout << "\n";

            textos[numTextos]= new Libro(generoL, edadL, colorL, disponiblilidadL, numTextos, tipoL, 
                Ficha(autorL, nombreObraL, editoria_L, numPaginasL, paisL, idiomaL));

            cout << "\nLibro registrado con exito, valide sus resultados" << endl;
            textos[numTextos]->getDatos();

            cout << "Si sus datos son correctos, INGRESE 1, si se equivoco INGRESE 2 para borrar el ultimo registro: ";
            cin >> continuar;

            if(continuar == 2){
                delete textos[numTextos];
                cout << "Vuelva a intentarlo." << endl;
            }else{
                numTextos++;
            }

            }
            break;
        
        case 2: //constructor de revistas.
            {
            string nombreR, generoR, colorR, disponiblilidadR, tipoR, editoria_R;
            int edadR, edicionR;

            disponiblilidadR= "disponible";
            tipoR= "revista";

            cout << "\nIngrese los datos que se le piden: " << endl;
            cout << "Nombre: ";
            cin >> nombreR;
            cout << "\n";
            
            cout << "Genero: ";
            cin >> generoR;
            cout << "\n";

            cout << "Edad minima recomendada (numero entero): ";
            cin >> edadR;
            cout << "\n";

            cout << "Color: ";
            cin >> colorR;
            cout << "\n";

            cout << "Editorial: ";
            cin >> editoria_R;
            cout << "\n";

            cout << "Numero de edicion: ";
            cin >> edicionR;
            cout << "\n";

            textos[numTextos]= new Revista(generoR,edadR, colorR, disponiblilidadR, numTextos, tipoR, editoria_R, 
                nombreR, edicionR);

            cout << "\nRevista registrada con exito, valide sus resultados" << endl;
            textos[numTextos]->getDatos();

            cout << "Si sus datos son correctos, INGRESE 1, si se equivoco INGRESE 2 para borrar el ultimo registro: ";
            cin >> continuar;

            if(continuar == 2){
                delete textos[numTextos];
                cout << "Vuelva a intentarlo." << endl;
            }else{
                numTextos++;
            }

            }
            break;
        default:
            break;
        }

        cout << "Si desea detener el registro, INRESE 1. De lo contrario, INGRESE 2: ";
        cin >> continuar;

        if(continuar == 1){
            flag= false;
        }
        if(numTextos == maxTextos){
            flag= false;
        }
    }
}

#endif
