#ifndef COLHOSTALES
#define COLHOSTALES

#include <map>
#include <set>
using namespace std;

#include "Hostal.h"

#include "../dataTypes/DataHostal.h"

class ColHostales{
	private:
		static ColHostales* instancia;		//Singleton
		ColHostales();						//Singleton
		map<string, Hostal*> hostales;
	public:
		static ColHostales* getInstance();	//Singleton
		set<DataHostal*> listarHostales();
		Hostal* getHostal(string);
		Hostal* getHostalEmpleado(string);
		bool existeHos(string);
		void registrarHostal(Hostal*);
		int getCantidad();
};

#endif
