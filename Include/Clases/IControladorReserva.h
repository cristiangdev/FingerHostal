#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include <set>
#include <string>
using namespace std;

#include "../dataTypes/DataReserva.h"
#include "../dataTypes/DTFecha.h"
#include "../dataTypes/DataHabitacion.h"
#include "../dataTypes/DataHostal.h"
#include "../dataTypes/DataUsuario.h"

class IControladorReserva{
	public:
		virtual set<DataReserva*> listarReservas() = 0;
		virtual set<DataHostal*> listarHostales() = 0;
		virtual int seleccionarHostal(string) = 0;
		virtual int seleccionarReserva(int) = 0;
		virtual void ingresarDatosReserva(int, DTFecha, DTFecha, bool) = 0;
		virtual set<DataHabitacion*> listarHabitacionesDisponibles() = 0;
		virtual int seleccionarHabitacion(int) = 0;
		virtual set<DataUsuario*> listarHuespedes() = 0;
		virtual int seleccionarHuesped(string) = 0;
		virtual int incluirHuespedEnReservaGrupal(string) = 0;
		virtual void confirmarReserva() = 0;
		virtual void confirmarBaja() = 0;
};




#endif
