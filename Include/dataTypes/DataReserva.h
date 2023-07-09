#ifndef DATARESERVA
#define DATARESERVA

#include "DTFecha.h"
#include "DTEstado.h"

class DataReserva{
	protected:
		int codigo, habitacion;
		DTFecha checkIn, checkOut;
		DTEstado estado;
		string huesped;
		float costo;
	public:
		DataReserva(int, DTFecha, DTFecha, DTEstado, int, string, float);
		int getCodigo();
		DTFecha getCheckIn();
		DTFecha getCheckOut();
		DTEstado getEstado();
		int getHabitacion();
		string getHuesped();
		virtual float getCosto() = 0;
};

#endif
