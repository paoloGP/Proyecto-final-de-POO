#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>

map<char,sf::Color> colores = {{'R',sf::Color::Red},{'G',sf::Color::Green},{'B',sf::Color::Blue}};
using namespace std;

Tierra::Tierra() {
    plano = nullptr;
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

void Tierra::adicionarObjeto(Objeto* objeto) {
    objetos.emplace_back(objeto);
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
        sf::CircleShape shape(10);
        shape.setFillColor(colores[item->getColor()]);
        shape.setPosition(item->getPosX(), item->getPosY());
        plano->draw(shape);
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
