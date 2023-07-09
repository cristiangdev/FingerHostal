#include "../../Include/Clases/ColUsuarios.h"
#include <stdio.h>

//----------Singleton
ColUsuarios* ColUsuarios::instancia = NULL;

ColUsuarios::ColUsuarios(){};

ColUsuarios* ColUsuarios::getInstance(){
	if(instancia == NULL)
		instancia = new ColUsuarios();
	return instancia;
}
//----------Singleton

set<DataUsuario*> ColUsuarios::listarUsuarios(){
	set<DataUsuario*> res;
	map<string, Usuario*>::iterator it;
	for(it = usuarios.begin(); it != usuarios.end(); it++){
		res.insert(it->second->getDataUsuario());
	}
	return res;
}

set<DataUsuario*> ColUsuarios::listarHuespedes(){
	set<DataUsuario*> res;
	map<string, Usuario*>::iterator it;
	for(it = usuarios.begin(); it != usuarios.end(); it++){
		if(dynamic_cast<Huesped*>(it->second) != NULL)
			res.insert(it->second->getDataUsuario());
	}
	
	return res;
}

set<DataUsuario*> ColUsuarios::listarEmpleados(){
	set<DataUsuario*> res;
	map<string, Usuario*>::iterator it;
	for(it = usuarios.begin(); it != usuarios.end(); it++){
		if(dynamic_cast<Empleado*>(it->second) != NULL)
			res.insert(it->second->getDataUsuario());
	}
	
	return res;
}

bool ColUsuarios::existeUsr(string email){
	return usuarios.count(email) > 0;
}

void ColUsuarios::registrarUsuario(Usuario* u){
	usuarios[u->getEmail()] = u;
}

set<DataUsuario*> ColUsuarios::listarOtrosEmpleados(map<string, Empleado*> emps){
	set<DataUsuario*> res;
	map<string, Usuario*>::iterator it;
	
	for(it = usuarios.begin(); it != usuarios.end(); it++){
		Empleado* actual = dynamic_cast<Empleado*>(it->second);
		if(actual != NULL && emps[actual->getEmail()] == NULL)
			res.insert(it->second->getDataUsuario());
	}
	
	return res;
}

Usuario* ColUsuarios::getUsuario(string email){
	return usuarios[email];
}

int ColUsuarios::getCantidad(){
	return usuarios.size();
}
