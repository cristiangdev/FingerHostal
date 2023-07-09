#include "../../Include/Clases/Respuesta.h"

Respuesta::Respuesta(string respuesta, Calificacion* calificacion){
	this->respuesta = respuesta;
	this->calificacion = calificacion;
	this->calificacion->setConRespuesta();
}

bool Respuesta::respAComentario(string comentario){
	return calificacion->getComentario() == comentario;
}

string Respuesta::getRespuesta(){
	return respuesta;
}
