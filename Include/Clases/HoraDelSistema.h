#ifndef HORADELSISTEMA
#define HORADELSISTEMA

#include "../dataTypes/DTFecha.h"


class HoraDelSistema {
    private:
           static HoraDelSistema* instancia; //Singleton
           HoraDelSistema(); //Singleton
           DTFecha fechaSistema;               
    public:
         static HoraDelSistema* getInstance(); //Singleton
         DTFecha getFechaSistema();
         void setFechaSistema(DTFecha nuevaFecha);
};

#endif