#include "../../Include/Clases/ColHostales.h"
#include <stdio.h>

//----------Singleton
ColHostales* ColHostales::instancia = NULL;

ColHostales::ColHostales(){};

ColHostales* ColHostales::getInstance(){
	if(instancia == NULL)
		instancia = new ColHostales();
	return instancia;
}
//----------Singleton

set<DataHostal*> ColHostales::listarHostales(){
	set<DataHostal*> res;
	map<string, Hostal*>::iterator it;
	
	for(it = hostales.begin(); it != hostales.end(); it++){
		DataHostal* actual = it->second->getDataHostal();
		res.insert(actual);
	}
	
	return res;
}

Hostal* ColHostales::getHostal(string nombre){
	Hostal* h = hostales[nombre];
	return h;
}


// Si el empleado no trabaja para ningun hostal, retorna NULL
Hostal* ColHostales::getHostalEmpleado(string email){
	Hostal* h = NULL;
	bool encontrado = false;
	map<string, Hostal*>::iterator it;
	for(it = hostales.begin(); it != hostales.end() && !encontrado; it++){
		map<string, Empleado*> emps = it->second->getEmpleados();
		if(emps[email] != NULL){
			h = it->second;
			encontrado = true;
		}
	}
	
	return h;
}

bool ColHostales::existeHos(string nombre){
	return hostales.count(nombre) > 0;
}

void ColHostales::registrarHostal(Hostal* h){
	hostales[h->getNombre()] = h;
}

int ColHostales::getCantidad(){
	return hostales.size();
}
