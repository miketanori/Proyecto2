//
//  Actor.h
//  Proyecto2
//
//  Created by Miguel Tánori on 24/04/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//

#ifndef Actor_h
#define Actor_h
#include <iostream>
#include <string>
using namespace std;

class Actor
{
public:
    void setId(int i) { Id = i;};
    int getId() { return Id; };
    void setNombre(string n) { nombre = n;};
    string getNombre() { return nombre; };
    Actor();
    Actor(int, string);
    void muestra();
    
private:
    int Id;
    string nombre;
};

Actor :: Actor(int i, string n){
    Id = i;
    nombre = n;
}

Actor :: Actor(){
    Id = 0;
    nombre = "-";
}

Actor :: muestra(){
    cout << "Nombre: " << getNombre() << endl << "ID: " << getId() << endl;
    
}

#endif /* Actor_h */
