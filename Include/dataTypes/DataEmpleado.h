#ifndef DATAEMPLEADO
#define DATAEMPLEADO

#include "DataUsuario.h"
#include "DTCargo.h"

class DataEmpleado:public DataUsuario{
	private:
		DTCargo cargo;
	public:
		DataEmpleado(string, string, string, DTCargo);
		DTCargo getCargo();
		int secreto();
};

#endif
