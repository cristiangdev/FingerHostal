#include "../../Include/Clases/Empleado.h"

Empleado::Empleado(string nombre, string email, string pass)
:Usuario(nombre, email, pass){
	this->cargo = DTCargo::Desocupado;
}

DTCargo Empleado::getCargo(){
	return cargo;
}

void Empleado::nuevaRespuesta(Respuesta* respuesta){
	respuestas.insert(respuesta);
}

void Empleado::setCargo(DTCargo cargo){
	this->cargo = cargo;
}

DataUsuario* Empleado::getDataUsuario(){
	DataUsuario* res = new DataEmpleado(nombre, email, pass, cargo);
	return res;
}

string Empleado::getRespuesta(string comentario){
	string res = "";
	set<Respuesta*>::iterator it;
	for(it = respuestas.begin(); it != respuestas.end(); it++)
		if((*it)->respAComentario(comentario))
			res = (*it)->getRespuesta();
	
	return res;
}

set<DataNotificacion*> Empleado::getNotificaciones(){
	set<DataNotificacion*> aux = notificaciones;
	notificaciones.clear();
	return aux;
}

void Empleado::notificar(string autor, int puntaje, string comentario, DTFecha fecha){
	DataNotificacion* nueva = new DataNotificacion(autor, puntaje, comentario, fecha);
	notificaciones.insert(nueva);
}
