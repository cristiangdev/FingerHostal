#ifndef DATARESERVAGRUPAL
#define DATARESERVAGRUPAL

#include <set>
using std::set;

#include "DataReserva.h"

class DataReservaGrupal:public DataReserva{
	private:
		set<string> huespedes;
	public:
		DataReservaGrupal(int, DTFecha, DTFecha, DTEstado, int, string, float, set<string>);
		set<string> getHuespedes();
		float getCosto();
};

#endif
