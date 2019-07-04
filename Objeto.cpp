#include "Objeto.h"

Objeto::Objeto(): color{}, posX{}, posY{}, figura{}  {}

Objeto::Objeto(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY, TipoEntero fig):
        nombre{nombre}, color{color},
        posX{posX}, posY{posY}, figura{fig} {}

Objeto::~Objeto() {}

void Objeto::setNombre(const TipoString& _nombre) { this->nombre = _nombre; }
void Objeto::moverse(TipoEntero x, TipoEntero y) {} //--  por implementar

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoCaracter Objeto::getColor()  { return color; }
TipoEntero   Objeto::getFigura() { return figura;}

TipoString Objeto::mostrarPosicion() {
    return "X = " + to_string(posX) + " Y = " + to_string(posY);
}
