#include "../../Include/Clases/Huesped.h"

Huesped::Huesped(string nombre, string email, string pass, bool esFinger)
:Usuario(nombre, email, pass){
	this->esFinger = esFinger;
}

bool Huesped::getEsFinger(){
	return esFinger;
}

void Huesped::agregarCalificacion(int codigo, Calificacion* calif){
	calificaciones[codigo] = calif;
}

Calificacion* Huesped::getCalificacion(int codigo){
	return calificaciones[codigo];
}

DataUsuario* Huesped::getDataUsuario(){
	DataUsuario* res = new DataHuesped(nombre, email, pass, esFinger);
	return res;
}
