#ifndef GAME_TIERRA_H
#define GAME_TIERRA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <limits>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"
using namespace std;

class Tierra {
private:
    TipoEntero altura;
    TipoEntero ancho;
    sf::RenderWindow* plano;
    vector<Objeto*> objetos;
public:
    Tierra();
    Tierra(TipoEntero _ancho, TipoEntero _altura);
    virtual ~Tierra();
    void adicionarObjeto();
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjectos();
    void actualizarTierra();
    void capturarEventos();
    void dibujarTierra();
};
#endif //GAME_TIERRA_H
