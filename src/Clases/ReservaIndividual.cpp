#include "../../Include/Clases/ReservaIndividual.h"

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut)
: Reserva(codigo, checkIn, checkOut){
	estadia = NULL;
}

Estadia* ReservaIndividual::getEstadia(string email){
	return estadia;
}

void ReservaIndividual::asignarEstadia(Estadia* e, string email){
	estadia = e;
}

void ReservaIndividual::finalizar(DTFecha checkOut, string email){
	estadia->marcarCheckOut(checkOut);
}

void ReservaIndividual::calificar(string texto, int calificacion, string email){
	estadia->asignarCalificacion(texto, calificacion);
}

void ReservaIndividual::borrarEstadias(){
	habitacion->setDisponibilidad();
	if(estadia != NULL){
		DTFecha* auxFecha = estadia->getCheckOut();
		if(auxFecha != NULL)
			delete auxFecha;
		Calificacion* auxCalif = estadia->getCalificacion();
		if(auxCalif != NULL)
			delete auxCalif;
		delete estadia;
	}
}

DataReserva* ReservaIndividual::getDataReserva(){
	DataReserva* res = new DataReservaIndividual(codigo, checkIn, checkOut, estado, habitacion->getNumero(), huesped->getEmail(), calcularCosto());
	return res;
}

DataEstadia* ReservaIndividual::getDataEstadia(string email, string nombre){
	Estadia* e = getEstadia(email);
	DTFecha checkInEstadia = e->getCheckIn();
	DTFecha* checkOutEstadia = e->getCheckOut();
	DataEstadia* res = new DataEstadia(nombre, huesped->getEmail(), codigo, habitacion->getNumero(), checkInEstadia, checkOutEstadia);
	return res;
}

DataCalificacion* ReservaIndividual::getCalificacion(string email){
	DataCalificacion* res = NULL;
	if(estadia != NULL)
		res = estadia->getDataCalificacion();
	return res;
}

float ReservaIndividual::calcularCosto(){
	return (checkOut - checkIn)*(habitacion->getPrecio());
}
