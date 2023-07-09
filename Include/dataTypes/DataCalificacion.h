#ifndef DATACALIFICACION
#define DATACALIFICACION

#include <string>
using namespace std;

#include "../../Include/dataTypes/DTFecha.h"

class DataCalificacion {
    private:
			int codigo;
			string autor;
            int calificacion;
            string comentario;
            DTFecha fecha;
    public:
            DataCalificacion(int, string, int, string, DTFecha);
            int getCodigo();
            string getAutor();
            int getCalificacion();
            string getComentario();
            DTFecha getFecha();
            string getRespuesta(string);
};

#endif
