#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

#include "Reserva.h"

class ReservaIndividual:public Reserva{
	private:
		Estadia* estadia;
	public:
		ReservaIndividual(int, DTFecha, DTFecha);
		Estadia* getEstadia(string);
		float calcularCosto();
		void asignarEstadia(Estadia*, string);
		void finalizar(DTFecha, string);
		void calificar(string, int, string);
		void borrarEstadias();
		DataReserva* getDataReserva();
		DataEstadia* getDataEstadia(string, string);
		DataCalificacion* getCalificacion(string);
};

#endif
