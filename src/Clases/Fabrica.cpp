#include "../../Include/Clases/Fabrica.h"



Fabrica* Fabrica::instancia = NULL;

Fabrica:: Fabrica(){};


Fabrica* Fabrica::getInstance(){
    if(instancia == NULL) {
        instancia = new Fabrica();
    }
	return instancia;
}

IControladorUsuario* Fabrica :: getIControladorUsuario() {
    IControladorUsuario* res = dynamic_cast<IControladorUsuario*> (ControladorUsuario::getInstance());
    return res;
}

IControladorHostal* Fabrica :: getIControladorHostal() {
    IControladorHostal* res = dynamic_cast<IControladorHostal*> (ControladorHostal::getInstance());
    return res;
}

IControladorReserva* Fabrica :: getIControladorReserva() {
    IControladorReserva* res = dynamic_cast<IControladorReserva*> (ControladorReserva::getInstance());
    return res;
}

IControladorEstadia* Fabrica :: getIControladorEstadia() {
    IControladorEstadia* res = dynamic_cast<IControladorEstadia*> (ControladorEstadia::getInstance());
    return res;
}
