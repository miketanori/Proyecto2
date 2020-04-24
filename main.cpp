//
//  main.cpp
//  Proyecto2
//
//  Created by Miguel Tánori on 24/04/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Pelicula.h"
#include "Funcion.h"

using namespace std;
Actor actores[20];
Funcion funciones[20];
Pelicula peliculas[20];
static int cont;
static string linea;

void cargaDatos(){
    ifstream entActores, entPeliculas;
    //Carga los datos al arreglo actores de actores.txt
    entActores.open("/Users/migueltanori/Desktop/Proyecto2/actores.txt");
    for(int x=0; x<21; x++){
        cont = 0;
        while (entActores >> linea){
            switch(cont){
                case 0:
                    actores[x].setId(stoi(linea));
                    break;
                case 1:
                    actores[x].setNombre(linea);
                    break;
                case 2:
                    linea = actores[x].getNombre() + " " + linea;
                    actores[x].setNombre(linea);
                    break;
                case 3:
                linea = actores[x].getNombre() + " " + linea;
                actores[x].setNombre(linea);
                break;
            }
            cont++;
            // Los "Stage Names" de actores se limitan a 3 palabras. Cuando llega el contador a 4 empieza la siguiente linea
            if (cont == 4){
                break;
            }
        }
    }
    entActores.close();
    
    //Carga los datos al arreglo peliculas de peliculas.txt
    entPeliculas.open("/Users/migueltanori/Desktop/Proyecto2/peliculas.txt");
    for(int x=0; x<21; x++){
        cont = 0;
        while (entPeliculas >> linea){
            switch(cont){
                case 0:
                    peliculas[x].setNumPeli(stoi(linea));
                    break;
                case 1:
                    peliculas[x].setAño(stoi(linea));
                    break;
                case 2:
                    peliculas[x].setDuracion(stoi(linea));
                    break;
                case 3:
                    peliculas[x].setGenero(linea);
                    break;
// Actores/////////////////////////////////////////////////////////////////////////////////////////////
                /*case 4:
                    peliculas[x].setActores(linea);
                    peliculas[x].AgregarActor(a)
                    break;*/
            }
            cont++;
            if (cont == 4){
                break;
            }
        }
    }
    entPeliculas.close();
}

void menu(){
    char o = ' ';
    while (o != 't'){
        cout << "Bienvenido\nTeclee A para Consultar todos los actores que están en la lista\nTeclee B para Consultar todas las películas que están en la lista\nTeclee C para Consultar todas las funciones disponibles\nTeclee D para Consultar funciones por hora\nTeclee E para Consultar funcione por clave de función\nTeclee F para Consultar películas en las que participa un actor\nTeclee T para Terminar\n";
        cin >> o;
        switch(tolower(o)){
            case 'a':
                //ModificarSF(e,y);
                break;
            case 'b':
                //ModificarSH(e,y);
                break;
            case 'c':
                //RegistrarHrsT(e,y);
                break;
            case 'd':
                //CalcularPagoE(e,y);
                break;
            case 'e':
                //VerListaEmpleados(e,y);
                break;
            case 'f':
                //VerListaEmpleados(e,y);
                break;
            case 't':
                cout << "Hasta luego" << endl;
                break;
            default:
                cout << "\nIntroduzca una opción válida\n\n";
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    cargaDatos();
    menu();
    return 0;
}
