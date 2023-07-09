#include "../../Include/dataTypes/DataReservaIndividual.h"

DataReservaIndividual::DataReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, DTEstado estado, int habitacion, string huesped, float costo)
: DataReserva(codigo, checkIn, checkOut, estado, habitacion, huesped, costo){
	
}

float DataReservaIndividual::getCosto(){
	return costo;
}
