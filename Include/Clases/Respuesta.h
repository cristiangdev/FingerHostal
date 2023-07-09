#ifndef RESPUESTA
#define RESPUESTA

#include "Calificacion.h"

class Respuesta{
	private:
		string respuesta;
		Calificacion* calificacion;
	public:
		Respuesta(string, Calificacion*);
		bool respAComentario(string);
		string getRespuesta();
};

#endif
