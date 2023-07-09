#include "../../Include/dataTypes/DataHabitacion.h"

DataHabitacion::DataHabitacion(int numero, int capacidad, float precio) {
    this->numero = numero;
    this->capacidad = capacidad;
    this->precio = precio;
}

int DataHabitacion::getNumero(){
    return numero;
}

int DataHabitacion::getCapacidad(){
    return capacidad;
}

float DataHabitacion::getPrecio(){
    return precio;
}
