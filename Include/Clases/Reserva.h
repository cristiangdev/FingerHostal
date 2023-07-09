#ifndef RESERVA
#define RESERVA

#include <string>
using namespace std;

#include "Habitacion.h"
#include "Huesped.h"
#include "Estadia.h"

#include "../dataTypes/DTFecha.h"
#include "../dataTypes/DTEstado.h"
#include "../dataTypes/DataReserva.h"
#include "../dataTypes/DataReservaIndividual.h"
#include "../dataTypes/DataReservaGrupal.h"
#include "../dataTypes/DataEstadia.h"
#include "../dataTypes/DataCalificacion.h"

class Reserva{
	protected:
		int codigo;
		DTFecha checkIn, checkOut;
		DTEstado estado;
		Habitacion* habitacion;
		Huesped* huesped;
	public:
		Reserva(int, DTFecha, DTFecha);
		int getCodigo();
		DTEstado getEstado();
		DTFecha getCheckIn();
		DTFecha getCheckOut();
		Huesped* getHuesped();
		virtual Estadia* getEstadia(string) = 0;
		virtual DataReserva* getDataReserva() = 0;
		virtual DataEstadia* getDataEstadia(string, string) = 0;
		void asignarHabitacion(Habitacion*);
		void asignarHuesped(Huesped*);
		void cerrarReserva();
		virtual void finalizar(DTFecha, string) = 0;
		virtual float calcularCosto() = 0;
		virtual void asignarEstadia(Estadia*, string) = 0;
		virtual void calificar(string, int, string) = 0;
		virtual void borrarEstadias() = 0;
		virtual DataCalificacion* getCalificacion(string) = 0;
		bool habitacionOcupadaEntre(DTFecha, DTFecha);
		int getNroHabitacion();
};

#endif
