#include "../../Include/dataTypes/DTFecha.h"

DTFecha::DTFecha(int hora, int dia, int mes, int anio){
    this->hora = hora;
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTFecha::getHora(){
    return hora;
}

int DTFecha::getDia(){
    return dia;
}

int DTFecha::getMes(){
    return mes;
}

int DTFecha::getAnio(){
    return anio;
}

// Metodo Verificacion fecha 
bool DTFecha::verifica_Fecha(int dd,int mm,int aa){
	return ((dd<=31) &&  (dd>=1) && (mm>=1) && (mm<=12)&& (aa>1900));
}

// Sobrecarga de ==
bool DTFecha::operator==(const DTFecha& fecha){
	return (dia == fecha.dia && mes == fecha.mes && anio == fecha.anio);
}

// Sobrecarga de =
DTFecha& DTFecha::operator=(const DTFecha& fecha){
	if(this != &fecha){
		hora = fecha.hora;
		dia = fecha.dia;
		mes = fecha.mes;
		anio = fecha.anio;
	}
	return *this;
}

// Sobrecarga de -
int DTFecha::operator-(const DTFecha& fecha){
	int minuendo = 31*12*anio + 31*mes + dia;
	int sustraendo = 31*12*fecha.anio + 31*fecha.mes + fecha.dia;
	return minuendo-sustraendo;
}

// Sobrecarga de <=
bool DTFecha::operator<=(const DTFecha& fecha){
	int izquierda = 31*12*anio + 31*mes + dia;
	int derecha = 31*12*fecha.anio + 31*fecha.mes + fecha.dia;
	return izquierda <= derecha;
}
