#ifndef EMPLEADO
#define EMPLEADO

#include <set>

#include "Usuario.h"
#include "Suscriptor.h"
#include "Respuesta.h"

#include "../../Include/dataTypes/DataNotificacion.h"

class Empleado:public Usuario, public Suscriptor{
	private:
		DTCargo cargo;
		set<Respuesta*> respuestas;
		set<DataNotificacion*> notificaciones;
		
	public:
		Empleado(string, string, string);
		DTCargo getCargo();
		void nuevaRespuesta(Respuesta*);
		void setCargo(DTCargo);
		DataUsuario* getDataUsuario();
		string getRespuesta(string);
		set<DataNotificacion*> getNotificaciones();
		void notificar(string, int, string, DTFecha);
};

#endif
