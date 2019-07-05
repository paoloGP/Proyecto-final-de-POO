#ifndef GAME_TIERRA_H
#define GAME_TIERRA_H

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <limits>
#include <vector>
#include "Tipos.h"
#include "Museo.h"
#include "Restaurante.h"
#include "Hotel.h"


template <typename T>
T input(const string& label) {
    T value;
    cout << label;
    cin >> value;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return value;
}

using namespace std;

class Tierra {
private:
    TipoEntero altura;
    TipoEntero ancho;
    sf::RenderWindow* plano;
    vector<Hotel*> hoteles;
    vector<Restaurante*> restaurantes;
    vector<Museo*> museos;
public:
    Tierra();
    Tierra(TipoEntero& _ancho, TipoEntero& _altura);
    virtual ~Tierra();
    void adicionarObjeto(TipoString& _nombre, TipoCaracter& _color, TipoCaracter& _lugar,  TipoEntero& _cali);
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    TipoEntero getCantidadHoteles();
    TipoEntero getCantidadMuseos();
    TipoEntero getCantidadRestaurantes();
    void masCercano();
    void tmejores();
    void mejores();
    void actualizarTierra();
    void capturarEventos();
    void dibujarTierra();
};
#endif //GAME_TIERRA_H
