#include <iostream>
#include "Tipos.h"

using namespace std;
class Objeto {

protected:
    TipoString nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoEntero calificacion;
    TipoCaracter figura;
public:
    Objeto();
    Objeto( TipoString& _nombre, TipoCaracter& color,TipoEntero posX, TipoEntero posY, TipoEntero& _calificacion,TipoCaracter& _figura);
    virtual ~Objeto();
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    TipoCaracter getColor();
    TipoEntero getCalificacion();
    TipoCaracter getFigura();
    void getDireccion();
};


#endif //GAME_OBJETO_H
