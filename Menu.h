//
// Created by utec on 21/06/19.
//

#ifndef GAME_MENU_H
#define GAME_MENU_H

#include <limits>
#include <iostream>
#include "Tierra.h"
#include "Tipos.h"

class Menu {
    TipoEntero opcion;
    Tierra tierra;
    void imprimirMenu();
    void seleccionarOpcion();
    void agregarObjeto();
    void removerObjeto();
    void dibujarMapa();
public:
    Menu(): opcion{} {}
    void ejecutar();
};


#endif //GAME_MENU_H
