/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca
*/

#include <iostream>
#include <string>
#include <sstream>

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

int main() {

    Librero librero1(1, "Poesía");
    librero1.llenarLibrero();
    librero1.mostrarDatosLibrero();
    
    cout << "\n";

    Mesa mesa1(1);
    mesa1.ocuparSilla();
    mesa1.desocuparSilla();
    mesa1.datosMesa();
    mesa1.apartarMesa();
    mesa1.vaciarMesa();
    mesa1.cambiarEstatus();
    
    cout << "\n";

    Escritorio escritorio1(1, true);
    escritorio1.computo();
    escritorio1.asignarCompu();
    escritorio1.ocuparEscritorio();
    escritorio1.datosEscritorio();
    escritorio1.solicitarAyuda();
    
    cout << "\n";
    
    Escritorio escritorio2(2, false);
    escritorio2.computo();
    escritorio2.asignarCompu();
    escritorio2.ocuparEscritorio();
    escritorio2.datosEscritorio();

    cout << "\n";
    
    Recepcion central;
    central.creaBibliotecarios();
    cout << "------------" << endl;
    cout << "getDatosRecepcion" << endl;
    central.getDatosRecepcion();
    cout << "------------" << endl;
    cout << "llamarBibliotecario" << endl;
    central.llamarBibliotecario();
    cout << "------------" << endl;
    cout << "getDatosRecepcion" << endl;
    central.getDatosRecepcion();
    cout << "------------" << endl;
    cout << "regresoBibliotecario" << endl;
    central.regresoBibliotecario();
    cout << "------------" << endl;
    cout << "getDatosRecepcion" << endl;
    central.getDatosRecepcion();
    cout << "------------" << endl;
}
