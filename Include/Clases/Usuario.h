#ifndef USUARIO
#define USUARIO

#include <string>
using std::string;

#include "../dataTypes/DataUsuario.h"
#include "../dataTypes/DataHuesped.h"
#include "../dataTypes/DataEmpleado.h"
#include "../dataTypes/DTCargo.h"

class Usuario{
	protected:
		string nombre, email, pass;
	public:
		Usuario(string, string, string);
		string getNombre();
		string getEmail();
		string getPass();
		virtual DataUsuario* getDataUsuario() = 0;
};

#endif
