#include "../../Include/Clases/HoraDelSistema.h"


HoraDelSistema* HoraDelSistema::instancia = NULL;

HoraDelSistema::HoraDelSistema() : fechaSistema{fechaSistema}{};


HoraDelSistema* HoraDelSistema::getInstance(){
    if(instancia == NULL) {
        instancia = new HoraDelSistema();
        instancia->fechaSistema = *new DTFecha(4, 12, 6, 2022);
    }
	return instancia;
}

DTFecha HoraDelSistema::getFechaSistema(){
    
    return fechaSistema;
}

void HoraDelSistema::setFechaSistema(DTFecha nuevaFecha){
    fechaSistema = nuevaFecha;
}