#ifndef CONTROLADORRESERVA
#define CONTROLADORRESERVA

#include <map>
#include <set>

#include "ColHostales.h"
#include "ColUsuarios.h"
#include "Reserva.h"
#include "ReservaIndividual.h"
#include "ReservaGrupal.h"
#include "Hostal.h"
#include "Usuario.h"
#include "Huesped.h"
#include "IControladorReserva.h"

class ControladorReserva: public IControladorReserva{
	private:
		static ControladorReserva* instancia; 		//Singleton
		ControladorReserva(); 						//Singleton
		string hostalGuardado;
		string huespedGuardado;
		int reservaGuardada;
		int habitacionGuardada;
		int codigoRegistrar;
		DTFecha* checkInRegistrar;
		DTFecha* checkOutRegistrar;
		bool esGrupalRegistrar;
		map<string, Huesped*> grupoRegistrar;
	public:
		static ControladorReserva* getInstance(); 	//Singleton
		set<DataReserva*> listarReservas();
		set<DataHostal*> listarHostales();
		int seleccionarHostal(string);
		int seleccionarReserva(int);
		void ingresarDatosReserva(int, DTFecha, DTFecha, bool);
		set<DataHabitacion*> listarHabitacionesDisponibles();
		int seleccionarHabitacion(int);
		set<DataUsuario*> listarHuespedes();
		int seleccionarHuesped(string);
		int incluirHuespedEnReservaGrupal(string);
		void confirmarReserva();
		void confirmarBaja();
		
};

#endif
