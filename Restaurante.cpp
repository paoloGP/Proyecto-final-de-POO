#include "Restaurante.h"

Restaurante::Restaurante(){}

Restaurante::Restaurante(TipoString& _tipo_de_comida,
TipoString& _especial_del_dia, TipoString& _nombre, TipoCaracter& color,
        TipoEntero posX, TipoEntero posY, TipoEntero& _calificacion, TipoCaracter& _figura):Objeto(_nombre, color,posX,posY,_calificacion,_figura){
    tipo_de_comida = _tipo_de_comida;
    especial_del_dia = _especial_del_dia;
}

void Restaurante::getCalificacion_de_restuarante_por_consumidor(){
    cout << "Calificacion de los clientes: " << calificacion << endl;
}

TipoString Restaurante::getTipo_de_comida(){
    return tipo_de_comida;
}
TipoString Restaurante::getEspecial_del_dia() {
    return especial_del_dia;
}

void Restaurante::getInformacion_del_restaurante(){
    cout << "Nombre: " << nombre << endl;
    cout << "Color: " << color << endl;
    Objeto::getDireccion();
    Restaurante::getCalificacion_de_restuarante_por_consumidor();
    cout << "Tipo de comida que ofrece el restaurante: " << tipo_de_comida << endl;
    cout << "Especial del dia: " << especial_del_dia;
}

Restaurante Restaurante::operator<<(Restaurante*& emisor){
    TipoString nombre_ = emisor->getNombre();
    TipoCaracter  color_ = emisor->getColor();
    TipoEntero    posX_ = emisor->getPosY();
    TipoEntero    posY_ = emisor->getPosY();
    TipoEntero calificacion_ = emisor->getCalificacion();
    TipoCaracter figura_ = emisor->getFigura();
    TipoString tipo_de_comida_ = emisor->getTipo_de_comida();
    TipoString especial_del_dia_= emisor->getEspecial_del_dia();

    Restaurante receptor(tipo_de_comida_,especial_del_dia_,nombre_,color_,posX_,posY_,calificacion_,figura_);
    return receptor;
}

Restaurante::~Restaurante()= default;