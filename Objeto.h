#ifndef GAME_OBJETO_H
#define GAME_OBJETO_H

#include <iostream>
#include "Tipos.h"

using namespace std;
class Objeto {

private:
    string  nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoEntero  figura;
public:
    Objeto();
    Objeto(const TipoString& _nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY,TipoEntero fig);
    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    char getColor();
    TipoEntero getFigura();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
};


#endif //GAME_OBJETO_H
