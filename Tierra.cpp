#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>

map<char,sf::Color> colores = {{'R',sf::Color::Red},{'G',sf::Color::Green},{'B',sf::Color::Blue},{'Y',sf::Color::Yellow}};

using namespace std;

Tierra::Tierra() {
    plano = new sf::RenderWindow(sf::VideoMode(600,600),"Proyecto Final");
//    plano.resize(ALTURA);
//    for (auto& item: plano)
//        item.resize(ANCHO);
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) {
    plano = new sf::RenderWindow(sf::VideoMode(ancho,altura),"Proyecto Final");
//    plano.resize(altura);
//    for (auto& item: plano)
//        item.resize(ancho);
}

Tierra::~Tierra() {}

void Tierra::adicionarObjeto() {
    auto    nombre = input<TipoString>("Ingrese Nombre : ");
    auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");
    TipoEntero x;
    TipoEntero y;
    while (plano->isOpen())
    {
        sf::Event event;
        while (plano->pollEvent(event))
        {
            plano->clear();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.mouseButton.x < 600 && event.mouseButton.y < 600){
                TipoEntero x = event.mouseButton.x;
                TipoEntero y = event.mouseButton.y;
                plano->close();
            }
        }
        actualizarTierra();
        plano->display();
    }
    TipoEntero num = input<TipoEntero>("Ingrese Figura (1.circulo, 2.rectangulo, 3.cuadrado): ");
    while(num < 0 || num >3){
        cout << "Figura invalida" << endl;
        num = input<TipoEntero>("Ingrese Figura (1.circulo, 2.rectangulo, 3.cuadrado): ");
    }
    objetos.emplace_back(new Objeto(nombre,color,x,y,num));
}

Objeto* Tierra::removerObjeto(string& nombre) {
    // Buscando objeto
    if (objetos.size() == 0)
        return nullptr;

    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter == end(objetos))
        return nullptr;
    // Eliminando objeto
    objetos.erase(iter);
    //-- si encuentra al objeto lo separa del vector, pero no mata al objeto, esto se hara en el menu.
    return *iter;
}

void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto& item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}

void Tierra::actualizarTierra() {
    for(auto& item : objetos) {
        if(item->getFigura()== 1) {
            sf::CircleShape circulo(10);
            circulo.setFillColor(colores[item->getColor()]);
            circulo.setPosition(item->getPosX(), item->getPosY());
            plano->draw(circulo);
        }
        if(item->getFigura()== 2) {
            sf::RectangleShape rect(sf::Vector2f(10,20));
            rect.setFillColor(colores[item->getColor()]);
            rect.setPosition(item->getPosX(), item->getPosY());
            plano->draw(rect);
        }
        if(item->getFigura()== 3) {
            sf::RectangleShape cua(sf::Vector2f(15,15));
            cua.setFillColor(colores[item->getColor()]);
            cua.setPosition(item->getPosX(), item->getPosY());
            plano->draw(cua);
        }
    }
//    for (auto &row : plano)
//        for (auto &cell: row)
//            cell = COLOR;
//
//    for (auto& item: objetos)
//        plano[item->getPosX()][item->getPosY()]
//                = item->getColor();
}

void Tierra::dibujarTierra() {
    if(plano == nullptr) return;
    while (plano->isOpen())
    {
        sf::Event event;
        while (plano->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                plano->close();
        }

        plano->clear();
        actualizarTierra();
        plano->display();
    }
}

TipoEntero Tierra::getAltura() {
    return plano->getPosition().y;
}

TipoEntero Tierra::getAncho(){
    return plano->getPosition().x;
}
