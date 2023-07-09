#ifndef CONTROLADORHOSTAL
#define CONTROLADORHOSTAL

#include "IControladorHostal.h"

#include "ColHostales.h"
#include "ColUsuarios.h"
#include "Hostal.h"
#include "Empleado.h"

class ControladorHostal:public IControladorHostal{
	private:
		static ControladorHostal* instancia; 		//Singleton
		ControladorHostal(); 						//Singleton
		DataHostal* dataHostalRegistrar;
		DataHabitacion* dataHabitacionRegistrar;
		string hostalGuardado;
		string empleadoGuardado;
	public:
		static ControladorHostal* getInstance(); 	//Singleton
		int ingresarDatosHostal(DataHostal);
		void confirmarAltaHostal();
		set<DataHostal*> listarHostales();
		int seleccionarHostal(string);
		set<DataReserva*> listarReservas();
		int ingresarDatosHabitacion(DataHabitacion);
		void cancelarAltaHabitacion();
		void confirmarAltaHabitacion();
		set<DataUsuario*> listarEmpleadosNoAsignadosHostal();
		int seleccionarEmpleadoAsignar(string, DTCargo);
		void confirmarAsignarEmpleadoHostal();
		void cancelarAsignarEmpleadoHostal();
		DataHostal* getDataHostalRegistrar();
		DataHabitacion* getDataHabitacionRegistrar();
		list<DataHostal> listarTop3Hostales();
		set<DataHabitacion*> listarHabitaciones();
		set<DataCalificacion*> listarCalificaciones();
		string getHostalGuardado();
		string getEmpleadoGuardado();
};

#endif
