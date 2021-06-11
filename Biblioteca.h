/*
* Erick Alfredo García Huerta
* A01708119
* 
* Proyecto Administración de Biblioteca -> clase Biblioteca
* 
* Es la clase principal del proyecto, lleva a cabo dos funciones básicas pero clave para el funcionamiento del sistema
* de administración. El primero es la construcción de los elementos de la biblioteca y el segundo es la visualización 
* de la interfaz del usuario, la cual será la que permita a los usuarios navegar por el sistema y conectar con las otras 
* funciones del programa.
*/

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <string>
#include <iostream>

#include "Texto.h"
#include "Fila.h"
#include "Librero.h"

using namespace std;

const int maxLibreros= 100;

class Biblioteca
{
    private:
        Librero *libreros[maxLibreros];
        int numLibreros;
        string nombreBiblioteca;
    public:
        Biblioteca();
        Biblioteca(string nombre);
        ~Biblioteca(){
            for(int i= 0; i<maxLibreros; i++){
                delete libreros[i];
            }
        };
        void crearBiblioteca();
        void menuUsuario();
};

Biblioteca :: Biblioteca(){
    numLibreros= 0;
    nombreBiblioteca= "";
}

Biblioteca :: Biblioteca(string nombre){
    numLibreros= 0;
    nombreBiblioteca= nombre;
}

/*
* crearBiblioteca() genera casos de prueba que sólo sirven de ejemplo para el usuario del funcionamiento de la biblioteca
* se generará un librero con dos filas y cuatro libros en cada uno.
* Sin embargo, el usuario también puede escoger comenzar a construir la biblioteca antes de iniciar el menú, el número 
* de objetos puede incrementarse más tarde en el menú.
*
* @param:
* @return: Libreros[]
*/
void Biblioteca :: crearBiblioteca(){
    int respuesta;
    const char *str0= "Bienvenido al sistema de construcción de la biblioteca, por favor escoja una de las siguientes opciones\n"
                        "1. Iniciar la construccion automatica.\n"
                        "2. Comenzar a construir manualmente.\n"
                        "AVISO! Independientemente de su respuesta, puede expandir la biblioteca de forma manual en el \n"
                        "menu de usuario que se iniciara automaticamente tras finalizar el proceso de construccion.";
    puts(str0);
    cout << "Escoja su opcion: ";
    cin >> respuesta;
    cout << "\n";

    switch (respuesta)
    {
    case 1:
        libreros[numLibreros]= new Librero(numLibreros, "Ejemplo");
        libreros[numLibreros]->crearEjemplos();
        numLibreros++;
        break;
    case 2:
        {
            bool flag= true;
            int continuar;
            while(flag){
                string tema;
                cout << "Escriba la tematica general del librero: ";
                cin >> tema;

                libreros[numLibreros]= new Librero(numLibreros, tema);
                cout << "Construccion exitos, valide sus datos: " << endl;
                libreros[numLibreros]->getDatos();

                cout << "Ingrese las especificaciones internas del librero, debe crear al menos una fila y un texto" << endl;
                libreros[numLibreros]->crearFila();

                cout << "Desea crear otro librero? INGRESE 1 para crear otro, INGRESE 2 para terminar: ";
                cin >> continuar;

                if(continuar == 2){
                    flag = false;
                }else{
                    numLibreros++;
                }
            }
        }
            break;
    default:
        break;
    }
    
}

/*
* menuUsuario() permite al usuario navegar por las distintas opciones de los objetos así como seguir incrementando la
* biblioteca.
* 
* @param:
* @return: libreros[], filas[], textos[]
*/
void Biblioteca :: menuUsuario(){
    int respuesta;
    bool menu= true;
    const char *str1= "Bienvenido al menu de adminsitracion de la biblioteca.\n"
                        "1. Navegar en los libreros.\n"
                        "2. Crear nueva seccion de libreros.\n";
    while (menu)
    {
        puts(str1);

        cout << "Que desea hacer? ";
        cin >> respuesta;

        switch (respuesta)
        {
        case 1:
            {
                int idLibrero, opcion;
                cout << "Bienvenido a la seccion de libreros. A continuacion se le presentara nuestra oferta" << endl;
                for (int i= 0; i<=numLibreros; i++){
                    libreros[i]->getDatos();
                }

                cout << "Para continuar ingrese el numero de librero al que quiere acceder: ";
                cin >> idLibrero;
                cout << "\n";
                const char *str2= "Seleccione una de las siguientes opciones: \n"
                                    "1. Pedir prestado un libro o revista.\n"
                                    "2. Mostrar todos los libros de una fila.\n"
                                    "3. Mostrar todos las revistas de una fila.\n"
                                    "4. Mostrar todos los textos disponibles de una fila.\n"
                                    "5. Mostrar todos los textos prestados de una fila.\n"
                                    "6. Volver a mostrar todos los datos del librero.\n";
                puts(str2);

                cout << "Que desea hacer?: ";
                cin >> opcion;
                cout << "\n";

                switch (opcion)
                {
                case 1:
                    libreros[idLibrero]->setPrestar();
                    break;
                case 2:
                    libreros[idLibrero]->getLibrosFila();
                    break;
                case 3:
                    libreros[idLibrero]->getRevistasFila();
                    break;
                case 4:
                    libreros[idLibrero]->getDisponiblesFila();
                    break;
                case 5:
                    libreros[idLibrero]->getPrestadosFila();
                    break;
                case 6: 
                    libreros[idLibrero]->getDatos();
                    break;
                default:
                    break;
                }

                int finalizar;
                cout << "Si desea volver al menu INGRESE 1, INGRESE 2 para finalizar el programa: ";
                cin >> finalizar;
                if (finalizar == 2){
                    menu= false;
                }
            }
            break;
        case 2:
            {
                bool flag= true;
                int continuar;
                while(flag){
                    string tema;
                    cout << "Escriba la tematica general del librero: ";
                    cin >> tema;

                    libreros[numLibreros]= new Librero(numLibreros, tema);
                    cout << "Construccion exitos, valide sus datos: " << endl;
                    libreros[numLibreros]->getDatos();

                    cout << "Ingrese las especificaciones internas del librero, debe crear al menos una fila y un texto" << endl;
                    libreros[numLibreros]->crearFila();

                    cout << "Desea crear otro librero? INGRESE 1 para crear otro, INGRESE 2 para terminar: ";
                    cin >> continuar;

                    if(continuar == 2){
                        flag = false;
                    }else{
                        numLibreros++;
                    }
                }

                int finalizar;
                cout << "Si desea volver al menu principal INGRESE 1, INGRESE 2 para finalizar el programa: ";
                cin >> finalizar;
                if (finalizar == 2){
                    menu= false;
                }
            }
            break;
        default:
            break;
        }
    }
}

#endif
