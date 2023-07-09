#ifndef DATAHUESPED
#define DATAHUESPED

#include "DataUsuario.h"

class DataHuesped:public DataUsuario{
	private:
		bool esFinger;
	public:
		DataHuesped(string, string, string, bool);
		bool getEsFinger();
		int secreto();
};

#endif
