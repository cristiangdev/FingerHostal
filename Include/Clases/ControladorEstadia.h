#ifndef CONTROLADORESTADIA
#define CONTROLADORESTADIA

#include <set>

#include "ColHostales.h"
#include "ColUsuarios.h"
#include "Estadia.h"
#include "Hostal.h"
#include "HoraDelSistema.h"
#include "Respuesta.h"
#include "Calificacion.h"

#include "IControladorEstadia.h"

class ControladorEstadia: public IControladorEstadia{
	private:
		static ControladorEstadia* instancia; 		//Singleton
		ControladorEstadia(); 						//Singleton
		string hostalGuardado;
		string huespedGuardado;
		string empleadoGuardado;
		int reservaGuardada;
		string calificacionGuardada;
	public:
		static ControladorEstadia* getInstance(); 	//Singleton
		set<DataHostal*> listarHostales();
		int seleccionarHostal(string);
		int seleccionarHuesped(string);
		int seleccionarEmpleado(string);
		set<DataEstadia*> listarEstadiasFinalizadasHuesped();
		set<DataEstadia*> listarEstadiasSinFinalizarHuesped();
		set<DataEstadia*> listarEstadias();
		set<DataReserva*> listarReservasNoCanceladasHuesped();
		set<DataCalificacion*> listarCalificacionesSinResponder();
		void responderCalificacion(string);
		int seleccionarReserva(int);
		void registrarEstadia();
		void calificarEstadia(string, int);
		void finalizarEstadia();
		DataCalificacion* verCalificacion();
		string verRespuesta();
		DataReserva* infoReserva();
		set<DataUsuario*> listarEmpleados();
		void suscribirEmpleado();
		set<DataNotificacion*> listarNotificaciones();
		void eliminarSuscripcion();
};

#endif
