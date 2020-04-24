//
//  Hora.h
//  Proyecto2
//
//  Created by Miguel Tánori on 24/04/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//

#ifndef Hora_h
#define Hora_h
#include <iostream>
#include <iomanip> // lbreria para usar setw y setfill en el metodo muestra
using namespace std;

class Hora
{
public:
    void setHh(int h) { hh = h;};
    int getHh() { return hh; };
    void setMm(int m) { mm = m;};
    int getMm() { return mm; };
    Hora();
    Hora(int, int);
    void muestra();
    
private:
    int hh, mm;
};

Hora :: Hora(int h, int m){
    hh = h;
    mm = m;
}

Hora :: Hora(){
    hh = 0;
    mm = 0;
}

Hora :: muestra(){
    cout << setw(2) << setfill('0') << getHh() << ":" << setw(2) << setfill('0') << getMm() << endl;
}

#endif /* Hora_h */