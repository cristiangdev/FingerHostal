#include "../../Include/dataTypes/DataUsuario.h"

DataUsuario::DataUsuario(string nombre, string email, string pass){
	this->nombre = nombre;
	this->email = email;
	this->pass = pass;
}

string DataUsuario::getNombre(){
	return nombre;
}

string DataUsuario::getEmail(){
	return email;
}

string DataUsuario::getPass(){
	return pass;
}
