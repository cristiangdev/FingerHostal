#include "../../Include/dataTypes/DataCalificacion.h"

DataCalificacion::DataCalificacion(int codigo, string autor, int calificacion, string comentario, DTFecha fecha): fecha{fecha}{
	this->codigo = codigo;
	this->autor = autor;
    this->calificacion = calificacion;
    this->comentario = comentario;
}

int DataCalificacion::getCodigo(){
	return codigo;
}

string DataCalificacion::getAutor(){
	return autor;
}

int DataCalificacion::getCalificacion(){
    return calificacion;
}

string DataCalificacion::getComentario(){
    return comentario;
}

DTFecha DataCalificacion::getFecha(){
    return fecha;
}
