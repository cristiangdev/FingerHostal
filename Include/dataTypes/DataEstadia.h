#ifndef DATAESTADIA
#define DATAESTADIA

#include <string>
using std::string;

#include "../dataTypes/DTFecha.h"

class DataEstadia{
	private:
		string hostal, huesped;
		int reserva, habitacion;
		DTFecha checkIn;
		DTFecha* checkOut;
	public:
		DataEstadia(string, string, int, int, DTFecha, DTFecha*);
		string getHostal();
		string getHuesped();
		int getReserva();
		int getHabitacion();
		DTFecha getCheckIn();
		DTFecha* getCheckOut();
};

#endif
