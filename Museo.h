#ifndef GAME_MUSEO_H
#define GAME_MUSEO_H

#include "Objeto.h"

class Museo:public Objeto{
TipoString exposicion_actual;
public:
    Museo();
    Museo(TipoString& _exposicion_actual, TipoString& _nombre, TipoCaracter& color,
            TipoEntero posX, TipoEntero posY, TipoEntero& _calificacion, TipoCaracter& _figura);
    void getInformacion_de_museo();
    void getCalificacion_museo();
    TipoString getExposicionActual();
    Museo operator<<(Museo*& emisor);
    virtual ~Museo();
};


#endif //GAME_MUSEO_H
