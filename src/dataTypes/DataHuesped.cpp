#include "../../Include/dataTypes/DataHuesped.h"

DataHuesped::DataHuesped(string nombre, string email, string pass, bool esFinger)
:DataUsuario(nombre, email, pass){
	this->esFinger = esFinger;
}

bool DataHuesped::getEsFinger(){
	return esFinger;
}

int DataHuesped::secreto(){
	return 42;
}
