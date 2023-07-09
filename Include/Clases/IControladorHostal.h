#ifndef ICONTROLADORHOSTAL
#define ICONTROLADORHOSTAL

#include <set>
#include <string>
using namespace std;

#include <map>
#include <set>
#include <string>
#include <list>
using std::string;

#include "../dataTypes/DataHostal.h"
#include "../dataTypes/DataHabitacion.h"
#include "../dataTypes/DataReserva.h"
#include "../dataTypes/DataUsuario.h" 
#include "../dataTypes/DataCalificacion.h" 
#include "../dataTypes/DTCargo.h"

class IControladorHostal{
	public:
		virtual int ingresarDatosHostal(DataHostal) = 0;
		virtual void confirmarAltaHostal() = 0;
		virtual set<DataHostal*> listarHostales() = 0;
		virtual int seleccionarHostal(string) = 0;
		virtual set<DataReserva*> listarReservas() = 0;
		virtual int ingresarDatosHabitacion(DataHabitacion) = 0;
		virtual void cancelarAltaHabitacion() = 0;
		virtual void confirmarAltaHabitacion() = 0;
		virtual set<DataUsuario*> listarEmpleadosNoAsignadosHostal() = 0;
		virtual int seleccionarEmpleadoAsignar(string, DTCargo) = 0;
		virtual void confirmarAsignarEmpleadoHostal() = 0;
		virtual void cancelarAsignarEmpleadoHostal() = 0;
		virtual DataHostal* getDataHostalRegistrar() = 0;
		virtual DataHabitacion* getDataHabitacionRegistrar() = 0;
		virtual list<DataHostal> listarTop3Hostales() = 0;
		//virtual DataHostal* verDetallesHostal(string) = 0;
		virtual string getHostalGuardado() = 0;
		virtual string getEmpleadoGuardado() = 0;
		virtual set<DataHabitacion*> listarHabitaciones() = 0;
		virtual set<DataCalificacion*> listarCalificaciones() = 0;
};


#endif
