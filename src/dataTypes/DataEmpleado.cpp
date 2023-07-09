#include "../../Include/dataTypes/DataEmpleado.h"

DataEmpleado::DataEmpleado(string nombre, string email, string pass, DTCargo cargo)
:DataUsuario(nombre, email, pass){
	this->cargo = cargo;
}

DTCargo DataEmpleado::getCargo(){
	return cargo;
}

int DataEmpleado::secreto(){
	return 22;
}
