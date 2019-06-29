#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"

int main() {
    Menu menu;
    menu.ejecutar();
    return 0;
}

//int main(){
//
//    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
//    while (window.isOpen()){
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//                cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
//                sf::RectangleShape shape(sf::Vector2f(50,50));
//                shape.setFillColor(sf::Color(24,65,3,255));
//                shape.setPosition(event.mouseButton.x,event.mouseButton.y);
//                window.clear();
//                window.draw(shape);
//            }
//            if (event.type == sf::Event::Closed)
//                window.close();
//            window.display();
//        }
//    }
//    return 0;
//}
