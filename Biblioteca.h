/*
* Erick Alfredo García Huerta
* A01708119
* Clase Biblioteca, en esta se almacena el grueso del programa, lleva a cabo la creación de la biblioteca
* y presenta el menú del usuario.
*/

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>
#include <stdio.h>

#include "Ficha.h"
#include "Libro.h"
#include "Fila.h"
#include "Librero.h"
#include "Mesa.h"
#include "Computadora.h"
#include "Escritorio.h"
#include "Bibliotecario.h"
#include "Recepcion.h"

using namespace std;

const int maxLibreros= 1, maxMesas= 1, maxEscritorios= 2;

class Biblioteca
{
    private:
        int num= 0, noLibrero= 0, noMesa= 0, noEscritorio= 0;
        string nombre;
        Librero *libreros[maxLibreros];
        Mesa *mesas[maxMesas];
        Escritorio *escritorios[maxEscritorios];
        Recepcion central;
    public:
        Biblioteca(string nom);
        void crearBiblioteca();
        void menuBiblioteca();
        ~Biblioteca(){ //Destructor de los objetos en el heap.
            for (int i = 0; i < maxLibreros; i++){
                delete libreros[i];
            }
            for (int i = 0; i < maxMesas; i++){
                delete mesas[i];
            }
            for (int i = 0; i < maxEscritorios; i++){
                delete escritorios[i];
            }
        };
};

Biblioteca :: Biblioteca(string nom){
    nombre= nom;
}

/*
* Función que almacena la creacion de los arreglos de objetos además de que inicializa algunas 
*  de las características de los mismos.
*/
void Biblioteca :: crearBiblioteca(){
    libreros[num]= new Librero (num, "Poesía");
    libreros[num]->llenarLibrero();

    mesas[noMesa]= new Mesa (noMesa);

    escritorios[noEscritorio]= new Escritorio (noEscritorio, true);
    escritorios[noEscritorio]->asignarCompu();
    noEscritorio++;
    escritorios[noEscritorio]= new Escritorio (noEscritorio, false);

    central.creaBibliotecarios();
}

/*
* Esta función es la interfáz que verá el usuario, contiene switches que se activarán
* dependiendo de las preferencias del usuario y llevarán a cabo las acciones con otras clases y objetos.
* Esta función no crea nada, sólamente sirve para llamar a los apuntadores y presentar en pantalla
* la información que necesite el usuario dependiendo de qué ingrese en la variable respuesta.
* El programa finaliza una vez el usario ha terminado de responder a los switches o ingresa un valor inválido.
*/
void Biblioteca :: menuBiblioteca(){
    int respuesta, id;

    const char *str0= "Bienvenido al servicio de administracion de la biblioteca \n"
                        "Si desea recibir informacion sobre nuestra oferta en libros, INGRESE 1\n"
                        "Si desea recibir informacion sobre nuestros espacios de estudio, INGRESE 2\n"
                        "Si desea ir a nuestros escritorios, INGRESE 3\n"
                        "Si desea hablar con uno de nuestros bibliotecarios, INGRESE 4\n";
    puts(str0);
    cout << "Que desea hacer?: ";

    cin >> respuesta;
    cout <<"\n";

    switch (respuesta)
    {
    case 1: //libreros, libros, revistas, fichas bibliográficas.
        {
        const char *str1= "\nBienvenido a los libreros \n"
                            "Libreros disponibles: \n";

        puts(str1);
        for (int i= 0; i<maxLibreros; i++){
            libreros[i]->getLibreros();
        }
        cout << "\nIngrese el librero al que quiere acceder: ";
        cin >> noLibrero;
        cout <<"\n";
        
        const char *str2= "\nSi desea pedir prestado un libro, INGRESE 1\n"
                            "Si desea pedir prestado una revista, INGRESE 2\n"
                            "Si desea ver de nuevo los datos del librero, INGRESE 3\n"
                            "Si desea buscar los datos de un libro o revista, INGRESE 4\n";
        puts(str2);
        cout << "¿Qué desea hacer?: ";

        cin >> respuesta;
        cout <<"\n";

        switch (respuesta)
        {
        case 1:
            libreros[noLibrero]->getPrestarLibros();
            break;
        case 2:
            libreros[noLibrero]->getPrestarRevistas();
            break;     
        case 3:
            libreros[noLibrero]->mostrarDatosLibrero();
            break;  
        case 4:
            libreros[noLibrero]->getDatosFila();
            break;  
        default:
            cout << "Ingrese un valor valido" << endl;
            break;
        }
        }
        break;
    case 2: //mesas
        {
        int mesa;
        const char *str3= "Bienvenido a la sección de espacios de trabajo y estudio\n"
                            "Estas son las mesas disponibles:\n";
        puts(str3);
        
        for (int i = 0; i<maxMesas; i++){
            mesas[i]->datosMesa();
        }
        cout << "\n";

        const char *str4= "Si desea seleccionar una mesa, INGRESE 1\n"
                            "Si desea volver a visualizar todas las mesas, INGRESE 2\n"
                            "Si desea apartar una mesa, INGRESE 3\n";
        puts(str4);
        cout << "Que desea hacer?: ";
    
        cin >> respuesta;
        cout <<"\n";

        switch (respuesta)
        {
        case 1:
            {
            cout << "\nIngrese la ID de la mesa: " << endl;
            cin >> mesa;
            cout << "Datos de la mesa: " << endl;
            mesas[mesa]->datosMesa();

            const char *str5= "Si desea sentarse, INGRESE 1\n"
                                "Si desea llamar al servicio de limpieza, INGRESE 2\n"
                                "Si desea vaciar la mesa, INGRESE 3\n";
            puts(str5);

            cout << "Que dese hacer? ";
            cin >> respuesta;
            cout <<"\n";

            switch (respuesta)
            {
            case 1:
                mesas[mesa]->ocuparSilla();
                cout << "Desea seguir sentado? (1 para si/2 para no)";
                cin >> respuesta;
                if (respuesta == 1){
                    cout << "Se quedo dormido hasta que cerro la biblioteca." << endl;
                } else{
                    mesas[mesa]->desocuparSilla();
                }
                break;
            case 2:
                mesa[mesas]->setLimpieza();
                break;
            case 3:
                cout << "Al llamar al servicio de limpieza, todos deben abandonar la mesa" << endl;
                mesas[mesa]->vaciarMesa();
                break;
            default:
                cout << "Ingrese un valor valido" << endl;
                break;
            }
            }
            break;
        case 2:
            for (int i = 0; i<maxMesas; i++){
            mesas[i]->datosMesa();
            }
            cout << "\n";
            break;
        case 3:
            int mesa; 
            cout << "Que mesa desea ocupar? (ingrese la ID) ";
            cin >> mesa;
            mesas[mesa]->apartarMesa();
            break;
        default:
        cout << "Ingrese un valor valido" << endl;
            break;
        }
        }
        break;
    case 3: //escritorios
        {
            int escritorio;

            const char *str6 = "Bienvenido a la seccion de escritorios\n"
                                "Estos son los escritorios disponibles:\n";
            puts(str6);

            for (int i= 0; i<maxEscritorios; i++ ){
                escritorios[i]->datosEscritorio();
            }

            cout << "Ingrese la ID del escritorio que desea usar: ";
            cin >> escritorio;
            escritorios[escritorio]->ocuparEscritorio();
            cout << "\n";

            const char *str7 = "Para abandonar el escritorio, INGRESE 1\n"
                                "ADVERTENCIA: Las siguientes funciones solo están disponibles si el escritorio cuenta con computadora\n"
                                "Para usar la computadora del escritorio, INGRESE 2 \n"
                                "Para solicitar la ayuda de un técnico, INGRESE 3\n";
            puts(str7);

            cout << "Que dese hacer? ";
            cin >> respuesta;
            cout << "\n";

            switch (respuesta)
            {
            case 1:
                escritorios[escritorio]->setDesocupado();
                break;
            case 2:
                if (escritorios[escritorio]->getComputo() == true){
                    escritorios[escritorio]->getDatosComputadora();
                }else {
                    cout << "No cuenta con computadora" << endl;
                }
            case 3:
                if (escritorios[escritorio]->getComputo() == true){
                    escritorios[escritorio]->solicitarAyuda();
                }else{
                    cout << "Usted no cuenta con computadora" << endl;
                }
            default:
                cout << "Ingrese un valor valido" << endl;
                break;
            }
        }
        break;
    case 4:
        {
        const char *str8= "Bienvenido al menu de atencion al usuario\n"
                            "A continuacion se mostraran nuestros bibliotecarios disponibles:\n";
        puts(str8);
        
        central.getDatosRecepcion();
        
        const char *str9= "Si desea llamar a un bibliotecario, INGRESE 1\n"
                            "Si ha terminado de hacer uso del programa, INGRESE  2\n";
        puts(str9);

        cout << "Que dese hacer? ";
        cin >> respuesta;
        cout << "\n";

        switch (1)
        {
        case 1:
            central.llamarBibliotecario();
            cout << "Cuando termine de hablar con el bibliotecario, INGRESE 1" << endl;
            int servicio;
            cin >> servicio;
            if (servicio == 1){
                central.regresoBibliotecario();
                cout << "Gracias por usar el servicio de atencion." << endl;
            }
            break;
        case 2:
            cout << "Gracias por hacer uso del sistema de la biblioteca" << endl;
            break;
        default:
            break;
        }
                            
        }
        break;
    default:
        cout << "Ingrese un valor válido" << endl;
        break;
    }
}

#endif
