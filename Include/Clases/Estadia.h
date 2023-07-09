#ifndef ESTADIA
#define ESTADIA

#include "Calificacion.h"
#include "Huesped.h"
#include "HoraDelSistema.h"

#include "../dataTypes/DTFecha.h"
#include "../dataTypes/DataEstadia.h"
#include "../dataTypes/DataCalificacion.h"

class Estadia{
	private:
		int codigo;
		DTFecha checkIn;
		DTFecha* checkOut;
		Huesped* huesped;
		Calificacion* calificacion;
	public:
		Estadia(int, DTFecha checkIn);
		DTFecha getCheckIn();
		DTFecha* getCheckOut();
		Calificacion* getCalificacion();
		bool conCalificacion();
		bool califConRespuesta();
		void asignarHuesped(Huesped*);
		void asignarCalificacion(string, int);
		DataCalificacion* getDataCalificacion();
		void marcarCheckOut(DTFecha);
};

#endif
