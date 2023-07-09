#ifndef CALIFICACION
#define CALIFICACION

#include <set>
using namespace std;

#include "Suscriptor.h"

#include "../dataTypes/DTFecha.h"
#include "../dataTypes/DataCalificacion.h"

class Calificacion {
    private:
			string autor;
            int puntaje;
            DTFecha fecha;
            string comentario;
            bool conRespuesta;
            static set<Suscriptor*> suscriptores;
    public:
            Calificacion(string, int, DTFecha, string);
            string getAutor();
            int getPuntaje();
            DTFecha getFecha();
            string getComentario();
            bool getConRespuesta();
            void setConRespuesta();
            void agregarEmpleadoSuscripto(Suscriptor*);
            void eliminarEmpleadoSuscripto(Suscriptor*);
            void notificarSuscriptores();
};


#endif
