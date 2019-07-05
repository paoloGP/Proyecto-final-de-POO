#include "Hotel.h"

Hotel::Hotel(){}

Hotel::Hotel(TipoEntero _estrellas, TipoString& _disponibilidad, TipoString& _nombre, TipoCaracter& color,
        TipoEntero posX, TipoEntero posY, TipoEntero& _calificacion,TipoCaracter& _figura):Objeto(_nombre,color,posX,posY,_calificacion,_figura){
    estrellas = _estrellas;
    disponibilidad = _disponibilidad;
}

void Hotel::getCalificacion_de_hotel_por_huesped(){
    cout << "Calificacion de los huespedes: " << calificacion << endl;
}

TipoEntero Hotel::getEstrellas(){
    return estrellas;
}

TipoString Hotel::getDisponibilidad() {
    return disponibilidad;
}

void Hotel::getInformacion_de_hotel(){
    cout << "Nombre: " << nombre << endl;
    cout << "Color: " << color << endl;
    Objeto::getDireccion();
    Hotel::getCalificacion_de_hotel_por_huesped();
    cout << "Estrellas: " << Hotel::getEstrellas() << endl;
    cout << "Disponibilidad: " << Hotel::getDisponibilidad() << endl;
}
Hotel Hotel::operator<<(Hotel*&emisor){
    TipoString nombre_ = emisor->getNombre();
    TipoCaracter  color_ = emisor->getColor();
    TipoEntero    posX_ = emisor->getPosY();
    TipoEntero    posY_ = emisor->getPosY();
    TipoEntero calificacion_ = emisor->getCalificacion();
    TipoCaracter figura_ = emisor->getFigura();
    TipoEntero estrellas_ = emisor->getEstrellas();
    TipoString disponible_ = emisor->getDisponibilidad();
    Hotel receptor(estrellas_,disponible_,nombre_,color_,posX_,posY_,calificacion_,figura_);
    return receptor;
}

Hotel::~Hotel(){}