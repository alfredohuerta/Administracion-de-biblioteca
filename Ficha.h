#ifndef FICHA_H
#define FICHA_H

#include <iostream>
#include <string>

using namespace std;

class Ficha
{
    public:
        Ficha(string aut, string tit, string edit, string nacion, string lengua, int num, int ident);
        void consulCaracteristicas();
    private:
        string autor;
        string titulo; 
        string editorial; 
        string pais; 
        string idioma;
        int numPaginas; 
        int id;
};

Ficha :: Ficha(string aut, string tit, string edit, string nacion, string lengua, int num, int ident)
{
    autor= aut;
    titulo= tit;
    editorial= edit;
    pais= nacion;
    idioma= lengua;
    numPaginas= num;
    id= ident;

}

void Ficha :: consulCaracteristicas(){
    cout << "Número de identificación: " << id << endl;
    cout << "Autor: " << autor << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Pais: " << pais << endl;
    cout << "Idioma: " << idioma << endl;
    cout << "Número de páginas: " << numPaginas << endl;
}

#endif