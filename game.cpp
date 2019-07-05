#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"


int main(){
    TipoEntero altura , ancho;
    cout << "Ingresar altura de ventana: ";
    cin >> altura;
    cout << "Ingresar ancho de ventana: ";
    cin >> ancho;
    Menu menu(ancho,altura);
    menu.ejecutar();
    return 0;
}
