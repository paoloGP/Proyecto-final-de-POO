#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

enum class Opciones { Agregar=1, Remover, Mostrar};


void limpiar() {
#ifndef WIN32
    cout << "\033[2J\033[0;0H";
#else
    system("cls");
#endif
}

void esperar() {
    char w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

Menu::Menu(TipoEntero _ancho, TipoEntero _altura): tierra(_ancho, _altura), opcion{} {}

void Menu::mostrarMenu() {
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n\n";
    cout << "0. Para Salir\n\n";
}


void Menu::agregarObjeto() {

    tierra.adicionarObjeto();
}

void Menu::removerObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    Objeto* obj = tierra.removerObjeto(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    esperar();
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.dibujarTierra();
}

void Menu::ejecutar() {
    do {
        mostrarMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
    }
}

Menu::~Menu() = default;
