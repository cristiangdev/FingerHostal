#ifndef DATARESERVAINDIVIDUAL
#define DATARESERVAINDIVIDUAL

#include "DataReserva.h"

class DataReservaIndividual:public DataReserva{
	public:
		DataReservaIndividual(int, DTFecha, DTFecha, DTEstado, int, string, float);
		float getCosto();
};

#endif
