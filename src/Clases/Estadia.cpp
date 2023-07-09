#include "../../Include/Clases/Estadia.h"

Estadia::Estadia(int codigo, DTFecha checkIn): checkIn{checkIn}{
	this->codigo = codigo;
	checkOut = NULL;
	huesped = NULL;
	calificacion = NULL;
}

DTFecha Estadia::getCheckIn(){
	return checkIn;
}

DTFecha* Estadia::getCheckOut(){
	return checkOut;
}

Calificacion* Estadia::getCalificacion(){
	return calificacion;
}

bool Estadia::conCalificacion(){
	return calificacion != NULL;
}

bool Estadia::califConRespuesta(){
	bool res = false;
	if(calificacion != NULL)
		res = calificacion->getConRespuesta();
	return res;
}

void Estadia::asignarHuesped(Huesped* huesped){
	this->huesped = huesped;
}

void Estadia::asignarCalificacion(string texto, int calificacion){
	HoraDelSistema* horaSys = HoraDelSistema::getInstance();
	DTFecha fecha = horaSys->getFechaSistema();
	this->calificacion = new Calificacion(huesped->getEmail(), calificacion, fecha, texto);
	huesped->agregarCalificacion(codigo, this->calificacion);
}

DataCalificacion* Estadia::getDataCalificacion(){
	DataCalificacion* res = NULL;
	if(calificacion != NULL)
		res = new DataCalificacion(codigo, huesped->getEmail(), calificacion->getPuntaje(), calificacion->getComentario(), calificacion->getFecha());
	return res;
}

void Estadia::marcarCheckOut(DTFecha checkOut){
	DTFecha* aux = new DTFecha(checkOut.getHora(), checkOut.getDia(), checkOut.getMes(), checkOut.getAnio());
	this->checkOut = aux;
}
