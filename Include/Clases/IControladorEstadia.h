#ifndef ICONTROLADORESTADIA
#define ICONTROLADORESTADIA

#include <set>
#include <string>
using namespace std;

#include "../dataTypes/DataEstadia.h"
#include "../dataTypes/DataCalificacion.h"
#include "../dataTypes/DataReserva.h"
#include "../dataTypes/DataHostal.h"
#include "../dataTypes/DataUsuario.h"
#include "../dataTypes/DataNotificacion.h"
#include "../dataTypes/DTFecha.h"

class IControladorEstadia {
    public:
            virtual set<DataHostal*> listarHostales() = 0;
            virtual int seleccionarHostal(string) = 0;
            virtual int seleccionarHuesped(string) = 0;
            virtual int seleccionarEmpleado(string) = 0;
            virtual set<DataEstadia*> listarEstadiasFinalizadasHuesped() = 0;
		    virtual set<DataEstadia*> listarEstadiasSinFinalizarHuesped() = 0;
		    virtual set<DataEstadia*> listarEstadias() = 0;
		    virtual set<DataReserva*> listarReservasNoCanceladasHuesped() = 0;
		    virtual set<DataCalificacion*> listarCalificacionesSinResponder() = 0;
		    virtual void responderCalificacion(string) = 0;
		    virtual int seleccionarReserva(int) = 0;
		    virtual void registrarEstadia() = 0;
		    virtual void calificarEstadia(string, int) = 0;
		    virtual void finalizarEstadia() = 0;
    		virtual DataCalificacion* verCalificacion() = 0;
		    virtual string verRespuesta() = 0;
		    virtual DataReserva* infoReserva() = 0;
		    virtual set<DataUsuario*> listarEmpleados() = 0;
			virtual void suscribirEmpleado() = 0;
			virtual set<DataNotificacion*> listarNotificaciones() = 0;
			virtual void eliminarSuscripcion() =0;
};





#endif 
