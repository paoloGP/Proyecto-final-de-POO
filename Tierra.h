#ifndef GAME_TIERRA_H
#define GAME_TIERRA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"
using namespace std;

// Valores constantes
const TipoEntero ALTURA = 21;
const TipoEntero ANCHO  = 21;
const TipoCaracter COLOR ='.';


template <typename T>
T input(string label) {
    T value;
    cout << label;
    cin >> value;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return value;
}

/*
//--- Esta seria la funcion para leer un string,
//--- esta funcion si se quiere generalizar para colocar un label
//--- y leer cualquier tipo de dato se tendria que convertir al template anterior

string&& input(string label) {
  string value;
  cout << label;
  cin >> value;
  return move(value);
}
 */


class Tierra {
private:
    sf::RenderWindow* plano;
    vector<Objeto*> objetos;
public:
    Tierra();
    Tierra(TipoEntero altura, TipoEntero ancho);
    virtual ~Tierra();
    void adicionarObjeto();
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjectos();
    void dibujarTierra();
    void actualizarTierra();
};
#endif //GAME_TIERRA_H
