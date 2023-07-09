#ifndef DATAHABITACION
#define DATAHABITACION

#include <string>
using std::string;

class DataHabitacion{
    private:
        int numero, capacidad;
        float precio;
    public:
        DataHabitacion(int, int, float);
        int getNumero();
        int getCapacidad();
        float getPrecio();
};

#endif
