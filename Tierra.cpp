#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

map<TipoCaracter ,sf::Color> colores = {{'R',sf::Color::Red},{'G',sf::Color::Green},{'B',sf::Color::Blue},{'Y',sf::Color::Yellow}};
Tierra::Tierra() : altura{}, ancho{} {
    plano = nullptr;
}

Tierra::Tierra(TipoEntero& _ancho, TipoEntero& _altura) : altura{_altura}, ancho{_ancho} {
    plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
    delete plano;
}

void Tierra::masCercano(){
    TipoString lugar1, lugar2,lugar3;
    double distancia1=1000000,distancia2=1000000,distancia3=1000000;
    TipoEntero a =0 , b = 0;
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final");
    else
        plano->display();
    while (plano->isOpen()) {
        sf::Event event{};
        actualizarTierra();
        while (plano->pollEvent(event)){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                a = event.mouseButton.x;
                b = event.mouseButton.y;
                cout << "El punto seleccionado es X= " << a << " Y= " << b << endl;
                if((a > 0 && a<600) || (b < 600 && b > 0)) {
                    plano->close();
                }
            }
            plano->display();
        }
    }
    if (museos.empty() && restaurantes.empty() && hoteles.empty())
        cout << "No hay lugares cercanos a el punto seleccionado." << endl;
    for (auto item: museos) {
        double d, x, y;
        TipoString lugar = item->getNombre();
        x = item->getPosX();
        y = item->getPosY();
        d = sqrt((a-x)*(a-x)+(b-y)*(b-y));
        if (d < distancia3) {
            if (d < distancia2) {
                if (d < distancia1) {
                    distancia3 = distancia2;
                    distancia2 = distancia1;
                    distancia1 = d;
                    lugar3 = lugar2;
                    lugar2 = lugar1;
                    lugar1 = lugar;
                }
                else {
                    distancia3 = distancia2;
                    distancia2 = d;
                    lugar3 = lugar2;
                    lugar2 = lugar;
                }
            }
            else {
                distancia3 = d;
                lugar3 = lugar;
            }
        }
    }
    for (auto item: restaurantes) {
        double d, x, y;
        TipoString lugar = item->getNombre();
        x = item->getPosX();
        y = item->getPosY();
        d = sqrt((a-x)*(a-x)+(b-y)*(b-y));
        if (d < distancia3) {
            if (d < distancia2) {
                if (d < distancia1) {
                    distancia3 = distancia2;
                    distancia2 = distancia1;
                    distancia1 = d;
                    lugar3 = lugar2;
                    lugar2 = lugar1;
                    lugar1 = lugar;
                }
                else {
                    distancia3 = distancia2;
                    distancia2 = d;
                    lugar3 = lugar2;
                    lugar2 = lugar;
                }
            }
            else {
                distancia3 = d;
                lugar3 = lugar;
            }
        }
    }
    for (auto item: hoteles) {
        double d,x, y;
        TipoString lugar = item->getNombre();
        x = item->getPosX();
        y = item->getPosY();
        d = sqrt((a-x)*(a-x)+(b-y)*(b-y));
        if (d < distancia3) {
            if (d < distancia2) {
                if (d < distancia1) {
                    distancia3 = distancia2;
                    distancia2 = distancia1;
                    distancia1 = d;
                    lugar3 = lugar2;
                    lugar2 = lugar1;
                    lugar1 = lugar;
                }
                else {
                    distancia3 = distancia2;
                    distancia2 = d;
                    lugar3 = lugar2;
                    lugar2 = lugar;
                }
            }
            else {
                distancia3 = d;
                lugar3 = lugar;
            }
        }
    }
    cout << "Las distancias mas pequenas: \n";
    if(distancia1<1000000)
        cout << "Ha "<< distancia1 << " se encuentra " << lugar1 << ".\n";
    if(distancia2<1000000)
        cout << "Ha "<< distancia2 << " se encuentra " << lugar2 << ".\n";
    if(distancia3<1000000)
        cout << "Ha "<< distancia3 << " se encuentra " << lugar3 << ".\n";
    dibujarTierra();
}

void Tierra::tmejores(){
    TipoEntero caliH =0, caliM = 0,caliR = 0;
    TipoString lugarH, lugarM,lugarR;
    if (museos.empty() && restaurantes.empty() && hoteles.empty())
        cout << "No hay lugares cercanos a el punto seleccionado." << endl;
    for (auto item: museos) {
        TipoEntero cali = item->getCalificacion();
        TipoString lugar = item->getNombre();
        if (cali > caliM) {
            caliM = cali;
            lugarM = lugar;
        }
    }
    for (auto item: restaurantes) {
        TipoEntero cali = item->getCalificacion();
        TipoString lugar = item->getNombre();
        if (cali > caliR) {
            caliR = cali;
            lugarR = lugar;
        }
    }
    for (auto item: hoteles) {
        TipoEntero cali = item->getCalificacion();
        TipoString lugar = item->getNombre();
        if (cali > caliH) {
            caliH = cali;
            lugarH = lugar;
        }
    }
    cout << "Los mejores lugares: \n";
    if(caliH > 0)
        cout << "El hotel "<< lugarH << " es el mejor calificado por los huespedes. Calificacion: " << caliH << ".\n";
    if(caliR > 0)
        cout << "El restaurante  "<< lugarR << " es el mejor calificado por los clientes. Calificacion: " << caliR << ".\n";
    if(caliM > 0)
        cout << "El museo "<< lugarM << " es el mejor calificado por los visitantes. Calificacion: " << caliM << ".\n";
    dibujarTierra();
}
void Tierra::mejores(){

}

void Tierra::adicionarObjeto(TipoString& _nombre, TipoCaracter& _color, TipoCaracter& _lugar, TipoEntero& _cali) {
    TipoEntero x =0 , y = 0;
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final");
    else
        plano->display();
    while (plano->isOpen()) {
        sf::Event event{};
        Tierra::actualizarTierra();
        while (plano->pollEvent(event)){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                x = event.mouseButton.x;
                y = event.mouseButton.y;
                cout << x << "  " << y << endl;
                if((x > 0 && x<600) || (y < 600 && y > 0)) {
                    plano->close();
                }
            }
            plano->display();
        }
    }
    if(_lugar == 'H'){
        auto estrellas = input<TipoEntero>("Ingresar la cantidad de estrellas del hotel(del 1 al 5) : ");
        auto disponible = input<TipoString>("Ingresar la disponibilidad del hotel(De tal hora a tal hora) : ");
        hoteles.push_back(new Hotel(estrellas,disponible,_nombre,_color,x,y,_cali,_lugar));
    }
    if(_lugar == 'R'){
        auto tipocomida = input<TipoString>("Ingrese el tipo de comida que se sirve en el restaurante: ");
        auto espcialdeldia = input<TipoString>("Ingrese el especial del dia: ");
        restaurantes.push_back(new Restaurante(tipocomida,espcialdeldia,_nombre,_color,x,y,_cali,_lugar));
    }
    if(_lugar == 'M'){
        auto expoactual = input<TipoString> ("Ingrese la exposicion actual: ");
        museos.push_back(new Museo(expoactual,_nombre,_color,x,y,_cali,_lugar));
    }
}

Objeto* Tierra::removerObjeto(string& nombre) {

    if (museos.empty() && restaurantes.empty() && hoteles.empty())
        return nullptr;

    auto iter1 = find_if(begin(museos), end(museos),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter1 == end(museos)){
        auto iter2 = find_if(begin(restaurantes), end(restaurantes),
                            [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
        if (iter2 == end(restaurantes)){
            auto iter3 = find_if(begin(hoteles), end(hoteles),
                                [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
            if (iter3 == end(hoteles))
                return nullptr;
            else {
                // Eliminando objeto
                hoteles.erase(iter3);
                //-- si encuentra al objeto lo separa del vector, pero no mata al objeto, esto se hara en el menu.
                return *iter3;
            }
        }
        else {
            // Eliminando objeto
            restaurantes.erase(iter2);
            //-- si encuentra al objeto lo separa del vector, pero no mata al objeto, esto se hara en el menu.
            return *iter2;
        }
    }
    else {
        // Eliminando objeto
        museos.erase(iter1);
        //-- si encuentra al objeto lo separa del vector, pero no mata al objeto, esto se hara en el menu.
        return *iter1;
    }
}

void Tierra::imprimirObjetos() {
    int i = 0;
    int j = 0;
    int g = 0;
    cout << "Cantidad de museos: "<< Tierra::getCantidadMuseos() << '\n'
    << "Cantidad de restaurantes: " << Tierra::getCantidadRestaurantes() << '\n'
    << "Cantidad de hoteles: " << Tierra::getCantidadHoteles()<< "\n\n";
    for (auto& item: museos) {
        cout << "Museo " << i+1 << " : " << endl;
        item->getInformacion_de_museo();
        cout << endl;
        i= i+1;
    }
    cout << endl;
    cout << endl;
    for (auto& item:restaurantes) {
        cout << "Restaurant " << g+1 << " : " << endl;
        item->getInformacion_del_restaurante();
        g=g+1;
        cout << endl;
    }
    cout << endl;
    cout << endl;
    for (auto& item: hoteles) {
        cout << "Hotel " << j+1 << " : " << endl;
        item->getInformacion_de_hotel();
        j = j+1;
        cout << endl;
    }
}

void Tierra::actualizarTierra() {
    for (auto obj: museos) {
        sf::CircleShape shape(10);
        shape.setPosition(obj->getPosX(), obj->getPosY());
        shape.setFillColor(colores[obj->getColor()]);
        plano->draw(shape);
    }
    for (auto obj: restaurantes){
        sf::RectangleShape shape(sf::Vector2f(10,20));
        shape.setPosition(obj->getPosX(), obj->getPosY());
        shape.setFillColor(colores[obj->getColor()]);
        plano->draw(shape);
    }
    for (auto obj: hoteles){
        sf::RectangleShape shape(sf::Vector2f(15,15));
        shape.setPosition(obj->getPosX(), obj->getPosY());
        shape.setFillColor(colores[obj->getColor()]);
        plano->draw(shape);
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
    while (plano->isOpen()){
        actualizarTierra();
        capturarEventos();
    }
}

TipoEntero Tierra::getCantidadHoteles() {
    return hoteles.size();
}

TipoEntero Tierra::getCantidadMuseos(){
    return museos.size();
}
TipoEntero Tierra::getCantidadRestaurantes(){
    return restaurantes.size();
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
