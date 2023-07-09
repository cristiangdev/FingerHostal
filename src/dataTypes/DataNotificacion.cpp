#include "../../Include/dataTypes/DataNotificacion.h"

DataNotificacion::DataNotificacion(string autor, int puntaje, string comentario, DTFecha fecha)
: fecha{fecha}{
	this->autor = autor;
	this->puntaje = puntaje;
	this->comentario = comentario;
}

string DataNotificacion::getAutor(){
	return autor;
}

int DataNotificacion::getPuntaje(){
	return puntaje;
}

string DataNotificacion::getComentario(){
	return comentario;
}

DTFecha DataNotificacion::getFecha(){
	return fecha;
}
