#ifndef HABITACION
#define HABITACION


#include "../dataTypes/DataHabitacion.h"

class Habitacion {
    private:
            int numero, capacidad;
            float precio;
            bool disponible;
    public:
            Habitacion(int, int, float);
            // ~Habitacion();    
            int getNumero();
            int getCapacidad();
            float getPrecio();
            DataHabitacion* getDataHabitacion();
            bool estaDisponible();
            void setDisponibilidad();
};


#endif

