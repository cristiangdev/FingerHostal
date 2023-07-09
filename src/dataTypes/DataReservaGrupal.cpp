#include "../../Include/dataTypes/DataReservaGrupal.h"

DataReservaGrupal::DataReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, DTEstado estado, int habitacion, string huesped, float costo, set<string> huespedes)
: DataReserva(codigo, checkIn, checkOut, estado, habitacion, huesped, costo){
	this->huespedes = huespedes;
}

set<string> DataReservaGrupal::getHuespedes(){
	return huespedes;
}

float DataReservaGrupal::getCosto(){
	return costo;
}
