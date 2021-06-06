/*
    Erick Alfredo García Huerta
    A01708119
    Proyecto Administración de una biblioteca Clase Ficha
    Esta clase define las características bibliográficas de los libros y revistas
    se implementa por medio de composicióna la clase Libro y su clase heredada Revista.
*/

#ifndef FICHA_H
#define FICHA_H

#include <iostream>
#include <string>

using namespace std;

//Declaración de la clase ficha que contiene los datos bibliográficos de los libros.
class Ficha
{
    public:
        //Constructor para clase libros.
        Ficha(string aut, string tit, string edit, string nacion, string lengua, int num);
        //Constructor por defautl para clase Revistas
        Ficha(){
            autor = " ";
            titulo= " ";
            editorial= " ";
            pais= " ";
            idioma= " ";
            numPaginas= 0;
        }
        void consulCaracteristicas();
    private:
        string autor;
        string titulo; 
        string editorial; 
        string pais; 
        string idioma;
        int numPaginas; 
};

Ficha :: Ficha(string aut, string tit, string edit, string nacion, string lengua, int num)
{
    autor= aut;
    titulo= tit;
    editorial= edit;
    pais= nacion;
    idioma= lengua;
    numPaginas= num;
}

void Ficha :: consulCaracteristicas(){
    cout << "Autor: " << autor << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Pais: " << pais << endl;
    cout << "Idioma: " << idioma << endl;
    cout << "Número de páginas: " << numPaginas << endl;
}

#endif
