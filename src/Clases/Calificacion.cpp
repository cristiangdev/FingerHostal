#include "../../Include/Clases/Calificacion.h"

set<Suscriptor*> Calificacion::suscriptores;

Calificacion::Calificacion(string autor, int puntaje, DTFecha fecha, string comentario): fecha{fecha}{
	this->autor = autor;
	this->puntaje = puntaje;
	this->comentario = comentario;
	conRespuesta = false;
	if(autor != "not_calificacion")
		notificarSuscriptores();
}

string Calificacion::getAutor(){
	return autor;
}

int Calificacion::getPuntaje(){
	return puntaje;
}

DTFecha Calificacion::getFecha(){
	return fecha;
}

string Calificacion::getComentario(){
	return comentario;
}

bool Calificacion::getConRespuesta(){
	return conRespuesta;
}

void Calificacion::setConRespuesta(){
	conRespuesta = true;
}

void Calificacion::agregarEmpleadoSuscripto(Suscriptor* sus){
	suscriptores.insert(sus);
}

void Calificacion::eliminarEmpleadoSuscripto(Suscriptor* sus){
	suscriptores.erase(sus);
}

void Calificacion::notificarSuscriptores(){
	set<Suscriptor*>::iterator it;
	for(it = suscriptores.begin(); it != suscriptores.end(); it++)
		(*it)->notificar(autor, puntaje, comentario, fecha);
}
