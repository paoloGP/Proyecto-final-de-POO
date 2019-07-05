#ifndef GAME_RESTAURANTE_H
#define GAME_RESTAURANTE_H

#include "Objeto.h"
class Restaurante: public Objeto{
    TipoString tipo_de_comida;
    TipoString especial_del_dia;
public:
    Restaurante();
    Restaurante(TipoString& _tipo_de_comida, TipoString& _especial_del_dia, TipoString& _nombre, TipoCaracter& color,
                TipoEntero posX, TipoEntero posY, TipoEntero& _calificacion, TipoCaracter& _figura);
    void getInformacion_del_restaurante();
    void getCalificacion_de_restuarante_por_consumidor();
    TipoString getTipo_de_comida();
    TipoString getEspecial_del_dia();
    Restaurante operator<<(Restaurante*& emisor);
    virtual ~Restaurante();
};


#endif //GAME_RESTAURANTE_H
