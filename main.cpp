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
Actor act;
Hora fun;
static int contf, s, contp, contA;
static string linea;

void menu(){
    char o = ' ';
    while (o != 't'){
        cout << "\nBienvenido\nTeclee A para Consultar todos los actores que están en la lista\nTeclee B para Consultar todas las películas que están en la lista\nTeclee C para Consultar todas las funciones disponibles\nTeclee D para Consultar funciones por hora\nTeclee E para Consultar funcione por clave de función\nTeclee F para Consultar películas en las que participa un actor\nTeclee T para Terminar\n";
        cin >> o;
        switch(tolower(o)){
            case 'a':
                cout << "Actores en la lista:\n\nID Nombre\n";
                for(int x=0; x<contA; x++){
                    cout << actores[x].getId() << " " << actores[x].getNombre() << endl;
                }
                break;
            case 'b':
                cout << "Peliculas en la lista:\n";
                for(int x=0; x<contp; x++){
                    cout << "Número de película: " << peliculas[x].getNumPeli();
                    cout << "\nAño: " << peliculas[x].getAño();
                    cout << "\nDuración: " << peliculas[x].getDuracion();
                    cout << "\nGénero: " << peliculas[x].getGenero();
                    cout << "\nLista de Actores: \n";
                    for (int y = 0; y < peliculas[x].getCantActores(); y++){
                     act= peliculas[x].getActor(y);
                        cout << act.getNombre()<<endl;
                    }
                    cout << "Título: " << peliculas[x].getTitulo() << endl << endl;
                }
                break;
            case 'c':
                cout << "\n\nFunciones del dia\n\n";
                for(int x=0; x < contf; x++){
                    funciones[x].muestra();
                    cout << endl;
                }
                break;
            case 'd':
                cout << "\n\nConsulta de funciones por hora\n\n";
                int h,m;
                while (true) {
                    cout << "Ingrese Hora (En formato 24 hrs):\n";
                    cin >> h;
                    cout << "Ingrese Minutos:\n";
                    cin >> m;
                    if(h>0 && h<25 && m>0 && m<61){
                        break;
                    }
                    else{
                        cout << "Hora inválida\n";
                    }
                }
                fun.setHh(h);
                fun.setMm(m);
                for(int x=0; x < contf; x++){
                    if(funciones[x].getHora().getHh() == fun.getHh() && funciones[x].getHora().getMm() == fun.getMm()){
                        funciones[x].muestra();
                    }
                    else{
                        cout <<"No hay funciones disponibles a esa hora";
                    }
                }
                break;
            case 'e':
                cout << "\n\nConsulta de funciones por clave\n\n";
                while (true) {
                    cout << "Ingrese Clave de funcion:\n";
                    cin >> linea;
                    for(int x=0; x < contf; x++){
                        if(funciones[x].getCveFuncion() == linea){
                            funciones[x].muestra();
                            break;
                        }
                        else{
                            cout <<"No hay funciones con esa clave";
                        }
                    }
                }
                break;
            case 'f':
                cout << "\n\nConsulta de peliculas por actor\n\n";
                    while (true) {
                       cout << "Ingrese ID del actor:\n";
                       cin >> s;
                       for(int x=0; x < contA; x++){
                           if(actores[x].getId() == s){
                               cout << "Nombre: " << actores[x].getNombre() << endl;
                               cout << "\nPeliculas: \n";
                               
                               for(int y=0; y < contp; y++){
                                   for(int w = 0; w<peliculas[y].getCantActores();w++){
                                       if(peliculas[y].getActor(w).getId() == actores[x].getId()){
                                           cout << "Titulo: " << peliculas[y].getTitulo() << "\nAño: " << peliculas[y].getAño() << endl;
                                       }
                                   }
                               }
                               break;
                            }
                       }
                        break;
                    }
                
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

void cargaDatos(){
    ifstream entActores, entPeliculas;
    //Carga los datos al arreglo actores de actores.txt
    entActores.open("/Users/migueltanori/Desktop/actores.txt");
    contA = 0;
    while(getline(entActores, linea)){
        actores[contA].setId(stoi(linea));
        linea = linea.erase(0,3);
        actores[contA].setNombre(linea);
        contA++;
    }
    entActores.close();
    //Carga los datos al arreglo peliculas de peliculas.txt
    entPeliculas.open("/Users/migueltanori/Desktop/peliculas.txt");
    contp = 0;
    Actor act;
    while(entPeliculas >> linea){
        peliculas[contp].setNumPeli(stoi(linea));
        entPeliculas >> linea;
        peliculas[contp].setAño(stoi(linea));
        entPeliculas >> linea;
        peliculas[contp].setDuracion(stoi(linea));
        entPeliculas >> linea;
        peliculas[contp].setGenero(linea);
        entPeliculas >> s;
        for (int x = 0; x < s; x++){
            entPeliculas >> linea;
            for (int y = 0; y < contA; y++){
                if(actores[y].getId() == stoi(linea)){
                    peliculas[contp].AgregarActor(actores[y]);
                }
            }
        }
        getline(entPeliculas, linea);
        linea = linea.erase(0,1);
        peliculas[contp].setTitulo(linea);
        contp++;
    }
    entPeliculas.close();
    contf = 0;
    Funcion a;
    Hora h;
    cout << "Funciones del Dia\n";
    for(int x=0; x<20; x++){
            cout << "\nIngrese Número de Pelicula" << endl;
            cin >> linea;
            a.setNumPeli(stoi(linea));
            cout << "Ingrese Número de Sala" << endl;
            cin >> linea;
            a.setSala(stoi(linea));
            cout << "Ingrese Clave de la Función" << endl;
            cin >> linea;
            a.setCveFuncion(linea);
            cout << "Horario\nIngrese Hora (formato 24 hrs)" << endl;
            cin >> linea;
            h.setHh(stoi(linea));
            cout << "Horario\nIngrese Minutos" << endl;
            cin >> linea;
            h.setMm(stoi(linea));
            a.setHora(h);
            funciones[x] = a;
            cout << "\nFunción agregada:\n\nNúmero de Pelicula: " << a.getNumPeli() << "\nNúmero de Sala: " << a.getSala() << "\nClave de la Función: " << a.getCveFuncion() << "\nHora: ";
            h.muestra();
            contf++;
        do{
            cout << "\n\n Desea agregar otra película? (Quedan " << 19-x << " espacios disponibles)\nTeclee SI para SI\tTeclee NO para NO\n";
            cin >> linea;
            if(linea == "NO"){
                x=20;
                break;
            }
            if(linea == "SI"){
                break;
            }
        }while(linea != "SI" || linea != "NO");
    }
}



int main(int argc, const char * argv[]) {
    cargaDatos();
    menu();
    return 0;
}
