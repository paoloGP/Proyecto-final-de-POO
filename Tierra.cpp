#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

map<TipoCaracter ,sf::Color> colores = {{'R',sf::Color::Red},{'G',sf::Color::Green},{'B',sf::Color::Blue},{'Y',sf::Color::Yellow}};
Tierra::Tierra() : altura{}, ancho{} {
    plano = nullptr;
}

Tierra::Tierra(TipoEntero _ancho, TipoEntero _altura) : altura{_altura}, ancho{_ancho} {
    plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
    delete plano;
}

void Tierra::adicionarObjeto() {
    TipoString    nombre;
    cout << "Ingrese Nombre : ";
    cin >> nombre;
    TipoCaracter color ;
    cout << "Ingrese color (Un caracter): ";
    cin >> color;
    TipoEntero num;
    cout << "Ingrese Figura (1.Museo, 2.Restaurante, 3.Hotel): ";
    cin >> num;
    cout << "Abra la ventana y haga click donde quiera posicionar el lugar: ";
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final - Presione [ESC] para salir... ");
    else
        plano->display();

    // Bucle principal
    TipoEntero x =0 , y = 0;
    while (plano->isOpen()) {
        sf::Event event;
        while (plano->pollEvent(event)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                x = event.mouseButton.x;
                y = event.mouseButton.y;
                cout << x << "  " << y << endl;
                if((x > 0 && x<600) || (y < 600 && y > 0)) {
                    plano->close();
                }
            }
        }
    }
    objetos.push_back(new Objeto(nombre,color,x,y,num));
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
    plano->clear();
    for (auto obj: objetos) {
        if(obj->getFigura()==1) {
            sf::CircleShape shape(10);
            shape.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
            shape.setFillColor(colores[obj->getColor()]);
            plano->draw(shape);
        }
        if(obj->getFigura() == 2){
            sf::RectangleShape shape(sf::Vector2f(10,20));
            shape.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
            shape.setFillColor(colores[obj->getColor()]);
            plano->draw(shape);
        }
        if(obj->getFigura() == 3){
            sf::RectangleShape shape(sf::Vector2f(15,15));
            shape.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
            shape.setFillColor(colores[obj->getColor()]);
            plano->draw(shape);
        }
    }
    plano->display();
}

void Tierra::dibujarTierra() {

    // Verifica si plano ha sido creado anteriormente
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final - Presione [ESC] para salir... ");
    else
        plano->display();

    // Bucle principal
    while (plano->isOpen()) {
        capturarEventos();
        actualizarTierra();
    }
}

TipoEntero Tierra::getAltura() {
    return plano->getSize().y;
}

TipoEntero Tierra::getAncho(){
    return plano->getSize().x;
}

TipoEntero Tierra::getCantidadObjectos() {
    return objetos.size();
}

void Tierra::capturarEventos() {
    sf::Event event{};

    while (plano->pollEvent(event)) {

        switch (event.type) {
            case sf::Event::Closed:
                plano->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    plano->close();
                break;
        }
    }
}
