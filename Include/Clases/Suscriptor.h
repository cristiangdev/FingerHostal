#ifndef SUSCRIPTOR
#define SUSCRIPTOR

#include "../dataTypes/DTFecha.h"

class Suscriptor{
	public:
		virtual void notificar(string, int, string, DTFecha) = 0;
};

#endif
