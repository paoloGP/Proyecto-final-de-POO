#include "Museo.h"
Museo::Museo() {}

Museo::Museo(TipoString& _exposicion_actual, TipoString& _nombre, TipoCaracter& color,
TipoEntero posX, TipoEntero posY, TipoEntero& _calificacion, TipoCaracter& _figura):Objeto(_nombre,color,posX,posY,_calificacion,_figura){
    exposicion_actual = _exposicion_actual;
}

void Museo::getCalificacion_museo(){
    cout << "Calificacion de los visitantes: " << calificacion << endl;
}

TipoString Museo::getExposicionActual(){
    return exposicion_actual;
}

void Museo::getInformacion_de_museo(){
    cout << "Nombre: " << nombre << endl;
    cout << "Color: " << color << endl;
    Objeto::getDireccion();
    Museo::getCalificacion_museo();
    cout << "Exposicion actual: " << exposicion_actual << endl;
}

Museo Museo::operator<<(Museo*&emisor){
    TipoString nombre_ = emisor->getNombre();
    TipoCaracter  color_ = emisor->getColor();
    TipoEntero    posX_ = emisor->getPosY();
    TipoEntero    posY_ = emisor->getPosY();
    TipoEntero calificacion_ = emisor->getCalificacion();
    TipoCaracter figura_ = emisor->getFigura();
    TipoString expoactual_ = emisor->getExposicionActual();
    Museo receptor(expoactual_,nombre_,color_,posX_,posY_,calificacion_,figura_);
    return receptor;
}

Museo::~Museo()=default;