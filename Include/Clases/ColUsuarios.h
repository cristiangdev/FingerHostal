#ifndef COLUSUARIOS
#define COLUSUARIOS

#include <set>
#include <map>
using namespace std;

#include "Usuario.h"
#include "Huesped.h"
#include "Empleado.h"

#include "../dataTypes/DataUsuario.h"
#include "../dataTypes/DataHuesped.h"
#include "../dataTypes/DataEmpleado.h"

class ColUsuarios{
	private:
		static ColUsuarios* instancia;		//Singleton
		ColUsuarios();						//Singleton
		map<string, Usuario*> usuarios;
	public:
		static ColUsuarios* getInstance();	//Singleton
		set<DataUsuario*> listarUsuarios();
		set<DataUsuario*> listarHuespedes();
		set<DataUsuario*> listarEmpleados();
		bool existeUsr(string);
		void registrarUsuario(Usuario*);
		set<DataUsuario*> listarOtrosEmpleados(map<string, Empleado*>);
		Usuario* getUsuario(string);
		int getCantidad();
};

#endif
