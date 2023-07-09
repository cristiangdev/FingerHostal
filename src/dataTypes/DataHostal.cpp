#include "../../Include/dataTypes/DataHostal.h"

DataHostal::DataHostal(string nombre, string direccion, int telefono, float promedioCalif) {
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
    this->promedioCalif = promedioCalif;
}

string DataHostal::getNombre(){
    return nombre;
}

string DataHostal::getNombre() const{
    return nombre;
}

string DataHostal::getDireccion(){
    return direccion;
}

int DataHostal::getTelefono(){
    return telefono;
}

float DataHostal::getPromedioCalif(){
	return promedioCalif;
}

float DataHostal::getPromedioCalif() const{
	return promedioCalif;
}

// Sobrecarga de =
DataHostal& DataHostal::operator=(const DataHostal& hostal){
	if(this != &hostal){
		nombre = hostal.nombre;
		direccion = hostal.direccion;
		telefono = hostal.telefono;
		promedioCalif = hostal.promedioCalif;
	}
	return *this;
}

// Sobrecarga de <
bool DataHostal::operator<(const DataHostal& hostal) const{
	return promedioCalif < hostal.promedioCalif;
}
