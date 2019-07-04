#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"


int main(){
    TipoEntero altura , ancho;
    cout << "Ingresar altura de ventana: ";
    cin >> altura;
    cout << endl;
    cout << "Ingresar ancho de ventana: ";
    cin >> ancho;
    Menu menu(ancho,altura);
    menu.ejecutar();
    return 0;
}

/*
int main(){

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            int x =0 , y = 0;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                x = event.mouseButton.x;
                y = event.mouseButton.y;
                cout << x << "  " << y << endl;
                if((x > 0 && x<600) || (y < 600 && y > 0)) {
                    window.close();
                }
            }
            window.display();
        }
    }
    return 0;
}*/
