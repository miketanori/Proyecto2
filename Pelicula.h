//
//  Pelicula.h
//  Proyecto2
//
//  Created by Miguel Tánori on 24/04/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h
#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;
class Pelicula
{
public:
    void setNumPeli(int n){ numPeli = n;};
    int getNumPeli(){ return numPeli;};
    void setTitulo(string t){ titulo = t;};
    string getTitulo(){ return titulo;};
    void setAño(int a){ año = a;};
    int getAño(){ return año;};
    void setDuracion(int d){ duracion = d;};
    int getDuracion(){ return duracion;};
    void setGenero(string g){ genero = g;};
    int getCantActores(){return cantActores;};
    string getGenero(){ return genero;};
    Actor getActor(int l){ return listaActores[l];};
    Pelicula();
    Pelicula(int, string, int, int, string, int);
    bool AgregarActor(Actor);
    
private:
    int numPeli, año, duracion, cantActores;
    string titulo, genero;
    Actor listaActores[10];
};

Pelicula :: Pelicula(int np, string t, int a, int d, string g, int ca){
    numPeli = np;
    titulo = t;
    año = a;
    duracion = d;
    genero = g;
    cantActores = ca;
}

Pelicula :: Pelicula(){
    numPeli = 0;
    titulo = "-";
    año = 0;
    duracion = 0;
    genero = "-";
    cantActores = 0;
}

bool Pelicula :: AgregarActor(Actor a){
    bool o = false;
    for(int x = 0; x<11; x++){
        if (getActor(x).getId() == a.getId()){
            o = false;
        }
        else if (getActor(x).getId() != 0){
            o = false;
        }
        else if (getActor(x).getId() == 0){
            listaActores[x] = a;
            cantActores = getCantActores()+1;
            return true;
        }
    }
    return o;
}

#endif /* Pelicula_h */
