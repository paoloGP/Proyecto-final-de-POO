#ifndef GAME_MENU_H
#define GAME_MENU_H

#include <iostream>
#include "Tierra.h"
#include "Tipos.h"

class Menu {
    TipoEntero opcion;
    Tierra tierra;
    static void mostrarMenu();
    void seleccionarOpcion();
    void agregarObjeto();
    void removerObjeto();
    void dibujarMapa();
    void masCercano();
    void tmejores();
    void mejores();
public:
    Menu(TipoEntero _ancho, TipoEntero _altura);
    virtual ~Menu();
    void ejecutar();
};


#endif //GAME_MENU_H
