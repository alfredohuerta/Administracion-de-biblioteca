/*
* Erick Alfredo García Huerta
* A01708119
* 
* Proyecto Administración de Biblioteca -> clase Texto
* 
* Esta clase genera objetos de tipo texto, los cuales le heredan características a
* los objetos hijos libro y revista, además de que se aplica polimorfismo a la hora
* de crear los métodos que sirven de getter y setters, además de que la clase Libro
* está unida por medio de composición a la clase Ficha, lo que le permite adquirir
* nuevas características.
*/

#ifndef TEXTO_H
#define TEXTO_H

#include <stdio.h>
#include <string>
#include <iostream>

#include "Ficha.h"

using namespace std;

class Texto
{
    protected:
        string genero;
        int edadMinima;
        string color;
        int id;
        string tipo;
        string disponibilidad;
    public:
        Texto();
        Texto(string gene, int edad, string croma, string dip, int ide, string type);
        virtual string getDisponible() = 0; //clase abstracta
        virtual void getDatos() = 0;
        virtual void setPrestado() = 0;
        virtual string getTipo() = 0;
};

Texto :: Texto(){
    genero= "";
    edadMinima= 0;
    color = "";
    disponibilidad= "diponible";
    id= 0;
    tipo= "";
};

Texto :: Texto(string gene, int edad, string croma, string dip, int ide, string type){
    genero= gene;
    edadMinima= edad;
    color= croma;
    disponibilidad= dip;
    id= ide;
    tipo= type;
};

//La clase libro hereda de Texto
class Libro : public Texto
{
    private:
        Ficha bibliografia;
    public: 
        // constructor por default
        Libro() : Texto("", 0, "", "disponible", 0, "libro"){ 
            Ficha bibliografia(); //nexo de la clase Ficha con Libro
        };
        //constructor de la clase Libro con su asignación de datos
        Libro(string gene, int edad, string croma, string disp, int ide, string type, Ficha datos):
            Texto(gene, edad, croma, disp, ide, "libro"){
            bibliografia = datos;
        };
        //sobre escritura de clase
        string getDisponible();
        void getDatos();
        void setPrestado();
        string getTipo();
};

string Libro :: getDisponible(){
    return disponibilidad;
}

/*
* Esta clase devuelve en pantalla los datos almacenados en Ficha así como los datos del
* libro.
* 
* @param: 
* @return: bibliografia, genero, edadMinima, color, dipsonibilidad.
*/
void Libro :: getDatos(){
    cout << "Ficha bibliografica: " << endl;
    bibliografia.getFicha();
    cout << "Datos generales: " << endl;
    cout << "ID: " << id << endl;
    cout << "Genero: " << genero << endl;
    cout << "Edad Minima recomendada: " << edadMinima << " anos" << endl;
    cout << "Color: " << color << endl;
    cout << "Disponibilidad: " << disponibilidad << endl;
}

void Libro :: setPrestado(){
    if (disponibilidad == "disponible"){
        cout << "Por favor, cuide del libro" << endl;
        disponibilidad = "prestado";
    }else{
        cout << "El libro ya fue prestado." << endl;
    }
    
}

string Libro :: getTipo(){
    return tipo;
}

//La clase revista hereda de texto
class Revista : public Texto{
    private: 
        string editorial;
        string nombre;
        int edicion;
    public:
        //constructor por default
        Revista():Texto("", 0, "", "disponible", 0, "revista"){
            editorial = "";
            nombre= "";
            edicion= 0;
        };
        //constructor de revista con asignación de datos.
        Revista(string gene, int edad, string croma, string disp, int ide, string type, string editora, string nomb, 
            int edi):
            Texto(gene, edad, croma, disp, ide, "revista"){
            editorial= editora;
            nombre= nomb;
            edicion= edi;
        };
        //redefinición de las clases abstractas.
        string getDisponible();
        void getDatos();
        void setPrestado();
        string getTipo();
};

string Revista :: getDisponible(){
    return disponibilidad;
}

/*
* Esta clase devuelve en pantalla los datos almacenados en la clase Revista
* 
* @param: 
* @return: nombre, genero, edadMinima, color, disponibilidad, editorial, edicion.
*/
void Revista :: getDatos(){
    cout << "\nNombre: " << nombre << endl;
    cout << "ID: " << id << endl;
    cout << "Genero: " << genero << endl;
    cout << "Edad Minima recomendada: " << edadMinima << " años" << endl;
    cout << "Color: " << color << endl;
    cout << "Disponibilidad: " << disponibilidad << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Edicion #" << edicion << endl;
    cout << "\n";
}

void Revista :: setPrestado(){
    if (disponibilidad == "disponible"){
        cout << "Por favor, cuide de la revista" << endl;
        disponibilidad = "prestado";
    }else{
        cout << "La revista ya fue prestada." << endl;
    }
}

string Revista :: getTipo(){
    return tipo;
}

#endif
