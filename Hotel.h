#ifndef GAME_HOTEL_H
#define GAME_HOTEL_H

#include "Objeto.h"

class Hotel: public Objeto{
TipoEntero estrellas;
TipoString disponibilidad;

public:
    Hotel();
    Hotel(TipoEntero _estrellas, TipoString& _disponibilidad, TipoString& _nombre, TipoCaracter& color,
            TipoEntero posX, TipoEntero posY, TipoEntero& _calificacion,TipoCaracter& _figura);
    void getInformacion_de_hotel();
    void getCalificacion_de_hotel_por_huesped();
    TipoEntero getEstrellas();
    TipoString getDisponibilidad();
    Hotel operator<<(Hotel*& emisor);
    virtual ~Hotel();
};


#endif //GAME_HOTEL_H
