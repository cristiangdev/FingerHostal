#ifndef DATANOTIFICACION
#define DATANOTIFICACION

#include "DTFecha.h"

class DataNotificacion{
	private:
		string autor;
		int puntaje;
		string comentario;
		DTFecha fecha;
	public:
		DataNotificacion(string autor, int puntaje, string comentario, DTFecha fecha);
		string getAutor();
		int getPuntaje();
		string getComentario();
		DTFecha getFecha();
};


#endif
