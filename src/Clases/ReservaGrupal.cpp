#include "../../Include/Clases/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut)
: Reserva(codigo, checkIn, checkOut){
	
}

Estadia* ReservaGrupal::getEstadia(string email){
	return estadias[email];
}

map<string, Estadia*> ReservaGrupal::getEstadias(){
	return estadias;
}

map<string, Huesped*> ReservaGrupal::getHuespedes(){
	return huespedes;
}

void ReservaGrupal::asignarHuespedesGrupo(map<string, Huesped*> grupo){
	huespedes = grupo;
}

void ReservaGrupal::asignarEstadia(Estadia* e, string email){
	estadias[email] = e;
}

void ReservaGrupal::finalizar(DTFecha checkOut, string email){
	estadias[email]->marcarCheckOut(checkOut);
}

void ReservaGrupal::calificar(string texto, int calificacion, string email){
	estadias[email]->asignarCalificacion(texto, calificacion);
}

void ReservaGrupal::borrarEstadias(){
	habitacion->setDisponibilidad();
	map<string, Estadia*>::iterator it;
	for(it = estadias.begin(); it != estadias.end(); it++){
		DTFecha* auxFecha = it->second->getCheckOut();
		if(auxFecha != NULL)
			delete auxFecha;
		Calificacion* auxCalif = it->second->getCalificacion();
		if(auxCalif != NULL)
			delete auxCalif;
		delete it->second;
	}
}

DataReserva* ReservaGrupal::getDataReserva(){
	set<string> grupo;
	map<string, Huesped*>::iterator it;
	for(it = huespedes.begin(); it != huespedes.end(); it++)
		grupo.insert(it->first);
		
	DataReserva* res = new DataReservaGrupal(codigo, checkIn, checkOut, estado, habitacion->getNumero(), huesped->getEmail(), calcularCosto(), grupo);
	return res;
}

DataEstadia* ReservaGrupal::getDataEstadia(string email, string nombre){
	Estadia* e = getEstadia(email);
	DTFecha checkInEstadia = e->getCheckIn();
	DTFecha* checkOutEstadia = e->getCheckOut();
	
	DataEstadia* res = new DataEstadia(nombre, email, codigo, habitacion->getNumero(), checkInEstadia, checkOutEstadia);
	return res;
}

DataCalificacion* ReservaGrupal::getCalificacion(string email){
	DataCalificacion* res = NULL;
	if(estadias.count(email) > 0)
		res = estadias[email]->getDataCalificacion();
	return res;
}

float ReservaGrupal::calcularCosto(){
	int totalHues = huespedes.size() + 1;
	int cantFingers = 0;
	
	if(huesped->getEsFinger())
		cantFingers++;
		
	map<string, Huesped*>::iterator it;
	
	for(it = huespedes.begin(); it != huespedes.end() && cantFingers < 2; it++){
		if(it->second->getEsFinger())
			cantFingers++;
	}
	
	float total;
	
	if(cantFingers == 2)
		total = (checkOut - checkIn)*totalHues*(habitacion->getPrecio())*0.7;
	else
		total = (checkOut - checkIn)*totalHues*(habitacion->getPrecio());
		
	return total;
}
