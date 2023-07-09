#include "../../Include/Clases/Habitacion.h"

Habitacion::Habitacion(int numero, int capacidad, float precio){
	disponible = true;
    this->numero = numero;
    this->capacidad = capacidad;
    this->precio = precio;
}

int Habitacion::getNumero(){
    return numero;
}

int Habitacion::getCapacidad(){
    return capacidad;
}

float Habitacion::getPrecio(){
    return precio;
}

DataHabitacion* Habitacion::getDataHabitacion(){
    DataHabitacion* dathab = new DataHabitacion(numero, capacidad, precio);
    return dathab;
}

bool Habitacion::estaDisponible(){
	return disponible;
}

void Habitacion::setDisponibilidad(){
	disponible = !disponible;
}
