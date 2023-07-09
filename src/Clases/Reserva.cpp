#include "../../Include/Clases/Reserva.h"

Reserva::Reserva(int codigo, DTFecha checkIn, DTFecha checkOut)
: checkIn{checkIn}, checkOut{checkOut}{
	this->codigo = codigo;
	estado = DTEstado::Abierta;
	huesped = NULL;
	habitacion = NULL;
}

int Reserva::getCodigo(){
    return codigo;
}

DTFecha Reserva::getCheckIn(){
    return checkIn;
}
DTFecha Reserva::getCheckOut(){
    return checkOut;
}

DTEstado Reserva::getEstado(){
	return estado;
}

Huesped* Reserva::getHuesped(){
	return huesped;
}

void Reserva::asignarHabitacion(Habitacion* hab){
	habitacion = hab;
	habitacion->setDisponibilidad();
}

void Reserva::asignarHuesped(Huesped* hue){
	huesped = hue;
}

void Reserva::cerrarReserva(){
	estado = DTEstado::Cerrada;
}

bool Reserva::habitacionOcupadaEntre(DTFecha fechaIn, DTFecha fechaOut){
	return 	(checkIn <= fechaIn && fechaIn <= checkOut) ||
			(fechaIn <= checkIn && checkIn <= fechaOut);
}

int Reserva::getNroHabitacion(){
	return habitacion->getNumero();
}
