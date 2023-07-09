#include "../../Include/Clases/Usuario.h"

Usuario::Usuario(string nombre, string email, string pass){
	this->nombre = nombre;
	this->email = email;
	this->pass = pass;
}

string Usuario::getNombre(){
	return nombre;
}

string Usuario::getEmail(){
	return email;
}

string Usuario::getPass(){
	return pass;
}
