#ifndef HOSTAL
#define HOSTAL

#include <map>
#include <set>
#include <string>
using namespace std;

#include "Habitacion.h"
#include "Reserva.h"
#include "ReservaGrupal.h"
#include "ReservaIndividual.h"
#include "Empleado.h"
#include "Estadia.h"

#include "../dataTypes/DataHostal.h"
#include "../dataTypes/DataHabitacion.h"
#include "../dataTypes/DataReserva.h"
#include "../dataTypes/DataEstadia.h"
#include "../dataTypes/DataCalificacion.h"

class Hostal{
	private:
		string nombre, direccion;
		int telefono;
		map<int, Habitacion*> habitaciones;
		map<int, Reserva*> reservas;
		map<string, Empleado*> empleados;
	public:
		Hostal(string, string, int);
		string getNombre();
		string getDireccion();
		int getTelefono();
		bool HabitacionEnHostal(int);
		bool existeRes(int);
		void registrarHabitacion(DataHabitacion);
		map<string, Empleado*> getEmpleados();
		void asignarEmpleado(Usuario*);
		set<DataReserva*> listarReservas();
		void calificarEstadia(string, int, int, string);
		set<DataHabitacion*> getHabitacionesDisponibles(DTFecha, DTFecha);
		Habitacion* getHabitacion(int);
		void registrarReserva(Reserva*);
		void borrarReserva(int);
		void registrarEstadia(int, Estadia*, string);
		void finalizarEstadia(DTFecha, int, string);
		set<DataReserva*> listarReservasHuesped(string);
		set<DataEstadia*> listarEstadiasFinalizadasHuesped(string);
		set<DataEstadia*> listarEstadiasSinFinalizarHuesped(string);
		set<DataEstadia*> listarEstadias();
		set<DataReserva*> listarReservasNoCanceladasHuesped(string);
		set<DataCalificacion*> listarCalificacionesSinResponder();
		DataCalificacion* verCalificacionEstadia(int, string);
		DataHostal* getDataHostal();
		DataReserva* infoReserva(int);
		float calcularPromedioCalif();
		set<DataHabitacion*> listarHabitaciones();
		set<DataCalificacion*> listarCalificaciones();
};

#endif
