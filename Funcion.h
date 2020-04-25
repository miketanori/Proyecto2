//
//  Funcion.h
//  Proyecto2
//
//  Created by Miguel Tánori on 24/04/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//

#ifndef Funcion_h
#define Funcion_h
#include <iostream>
#include <string>
#include "Hora.h"
using namespace std;

class Funcion
{
public:
    void setNumPeli(int n) { numPeli = n;};
    int getNumPeli() { return numPeli; };
    void setSala(int s) { sala = s;};
    int getSala() { return sala; };
    void setCveFuncion(string c) { cveFuncion = c;};
    string getCveFuncion() { return cveFuncion; };
    void setHora(Hora h) { hora = h;};
    Hora getHora() { return hora; };
    Funcion();
    Funcion(int, int, string, Hora);
    void muestra();
    
private:
    int numPeli, sala;
    string cveFuncion;
    Hora hora;
};

Funcion :: Funcion(int n, int s, string c, Hora h){
    numPeli = n;
    sala = s;
    cveFuncion = c;
    hora = h;
}

Funcion :: Funcion(){
    numPeli = 0;
    sala = 0;
    cveFuncion = "-";
    Hora h;
    hora = h;
}

void Funcion :: muestra(){
    cout << "Numero de Pelicula: " << getNumPeli();
    cout << "\nSala: " << getSala();
    cout << "\nClave: " << getCveFuncion();
    cout << "\nHora: ";
    hora.muestra();
    cout << endl;
}

#endif /* Funcion_h */
