#ifndef HUESPED
#define HUESPED

#include "Usuario.h"
#include "Calificacion.h"
#include <map>

class Huesped:public Usuario{
	private:
		bool esFinger;
		map<int, Calificacion*> calificaciones;
		
	public:
		Huesped(string, string, string, bool);
		bool getEsFinger();
		void agregarCalificacion(int, Calificacion*);
		Calificacion* getCalificacion(int);
		DataUsuario* getDataUsuario();
};

#endif
