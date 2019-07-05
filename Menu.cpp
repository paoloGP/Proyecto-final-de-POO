#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

enum class Opciones { Agregar=1, Remover, Mostrar, MasCercano, Tmejores, Mejores};


void limpiar() {
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void esperar() {
    char w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

Menu::Menu(TipoEntero _ancho, TipoEntero _altura): tierra(_ancho, _altura), opcion{} {}

void Menu::masCercano(){
    tierra.masCercano();
}

void Menu::tmejores(){
    tierra.tmejores();
}

void Menu::mejores(){

}

void Menu::mostrarMenu() {
    limpiar();
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n";
    cout << "4. Los tres lugares mas cercanos\n";
    cout << "5. Los tres mejores de cada tipo\n";
    cout << "6. Los tres mejores\n\n";
    cout << "0. Para Salir\n\n";
}


void Menu::agregarObjeto() {
    auto nombre = input<TipoString>("Ingresar nombre: ");
    cout << endl;
    auto color = input<TipoCaracter>("Ingresar color(solo un caracter) : ");
    cout << endl;
    auto lugar = input<TipoCaracter>("Ingrese el tipo de lugar(M = Museo, R = Restaurante, H = Hotel): ");
    cout << endl;
    auto calificacion = input<TipoEntero>("Ingrese su grado de satisfaccion del 1 al 10: ");
    cout << "Abra la ventana y haga click donde quiera posicionar el lugar: ";
    tierra.adicionarObjeto(nombre,color,lugar,calificacion);
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
    tierra.imprimirObjetos();
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
        case  Opciones::MasCercano: // muestra los 3 mas cercanos
            masCercano();
            break;
        case  Opciones::Tmejores: // muestra los mejores
            tmejores();
            break;
    }
}

Menu::~Menu() = default;
