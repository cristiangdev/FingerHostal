#include "../../Include/dataTypes/DataEstadia.h"

DataEstadia::DataEstadia(string hostal, string huesped, int reserva, int habitacion, DTFecha checkIn, DTFecha* checkOut): checkIn{checkIn}{
	this->hostal = hostal;
	this->huesped = huesped;
	this->reserva = reserva;
	this->habitacion = habitacion;
	this->checkOut = checkOut;
}

string DataEstadia::getHostal(){
	return hostal;
}
string DataEstadia::getHuesped(){
	return huesped;
}
int DataEstadia::getReserva(){
	return reserva;
}
int DataEstadia::getHabitacion(){
	return habitacion;
}
DTFecha DataEstadia::getCheckIn(){
	return checkIn;
}
DTFecha* DataEstadia::getCheckOut(){
	return checkOut;
}
