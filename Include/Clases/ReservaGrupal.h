#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

#include <map>

#include "Reserva.h"

class ReservaGrupal:public Reserva{
	private:
		map<string, Huesped*> huespedes;
		map<string, Estadia*> estadias;
	public:
		ReservaGrupal(int, DTFecha, DTFecha);
		Estadia* getEstadia(string);
		map<string, Estadia*> getEstadias();
		map<string, Huesped*> getHuespedes();
		void asignarHuespedesGrupo(map<string, Huesped*>);
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
