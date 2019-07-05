#include "Objeto.h"

Objeto::Objeto(): nombre{}, color{}, posX{}, posY{},calificacion{}, figura{}{}

Objeto::Objeto(TipoString& nombre, TipoCaracter& color,
               TipoEntero posX, TipoEntero posY, TipoEntero& calificacion,TipoCaracter& _figura):
        nombre{nombre}, color{color},
        posX{posX}, posY{posY}, calificacion{calificacion}, figura{_figura} {}

Objeto::~Objeto() = default;

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoCaracter Objeto::getColor()  { return color; }
TipoEntero  Objeto::getCalificacion() {return calificacion;}
TipoCaracter Objeto::getFigura() { return figura;}

void Objeto::getDireccion() {
    cout << "Direccion:  " << "X= " << getPosX() << " Y= " << getPosY() << endl;
}
