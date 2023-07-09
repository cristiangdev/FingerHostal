#include "../../Include/dataTypes/DataReserva.h"

DataReserva::DataReserva(int codigo, DTFecha checkIn, DTFecha checkOut, DTEstado estado, int habitacion, string huesped, float costo)
: checkIn{checkIn}, checkOut{checkOut}{
	this->codigo = codigo;
	this->estado = estado;
	this->habitacion = habitacion;
	this->huesped = huesped;
	this->costo = costo;
}

int DataReserva::getCodigo(){
	return codigo;
}

DTFecha DataReserva::getCheckIn(){
	return checkIn;
}

DTFecha DataReserva::getCheckOut(){
	return checkOut;
}

DTEstado DataReserva::getEstado(){
	return estado;
}

int DataReserva::getHabitacion(){
	return habitacion;
}

string DataReserva::getHuesped(){
	return huesped;
}
