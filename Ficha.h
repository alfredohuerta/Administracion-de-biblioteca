/*
* Erick Alfredo García Huerta
* A01708119
* 
* Proyecto Administración de Biblioteca -> clase Ficha
* 
* Esta clase genera las fichas bibliográficas que se atarán a los libros, contienen
* datos como el autor, el nombre de la obra, la editorial que publica la obra, el 
* número de páginas, el país y el idioma original de la obra
*/

#ifndef FICHA_H
#define FICHA_H

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Ficha
{
    private:
        string autor;
        string nombreObra;
        string editorial;
        int numPaginas;
        string pais;
        string idioma;
    public: 
        Ficha();
        Ficha(string escritor, string obra, string editora, int paginas, string nacion, string lengua);
        void getFicha();
};

Ficha :: Ficha(){
    autor= "";
    nombreObra= "";
    editorial= "";
    numPaginas= 0;
    pais= "";
    idioma= "";
}

Ficha :: Ficha(string escritor, string obra, string editora, int paginas, string nacion, string lengua){
    autor= escritor;
    nombreObra= obra;
    editorial= editora;
    numPaginas= paginas;
    pais= nacion;
    idioma= lengua;
}

/*
* Esta función devuelve en pantalla los datos de la ficha bibliográfica del libro.
* 
* @param: 
* @return: autor, nombreObra, editorial, numPaginas, pais, idioma.
*/

void Ficha :: getFicha(){
    cout << "Autor: " << autor << endl;
    cout << "Nombre obra: " << nombreObra << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Numero de paginas: " << numPaginas << endl;
    cout << "Pais de publicacion: " << pais << endl;
    cout << "Idioma del libro: " << idioma << endl;
}

#endif
