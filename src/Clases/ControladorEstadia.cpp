#include "../../Include/Clases/ControladorEstadia.h"

//----------Singleton
ControladorEstadia* ControladorEstadia::instancia = NULL;

ControladorEstadia::ControladorEstadia(){};

ControladorEstadia* ControladorEstadia::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorEstadia();
	return instancia;
}
//----------Singleton

set<DataHostal*> ControladorEstadia::listarHostales(){
	ColHostales* colHos = ColHostales::getInstance();
	return colHos->listarHostales();
}

int ControladorEstadia::seleccionarHostal(string nombre){
	ColHostales* colHos = ColHostales::getInstance();
	bool existe = colHos->existeHos(nombre);
	if(existe)
		hostalGuardado = nombre;
		
	return !existe;
}

int ControladorEstadia::seleccionarHuesped(string email){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	bool existe = colUsr->existeUsr(email);
	if(existe)
		huespedGuardado = email;
	
	return !existe;
}

int ControladorEstadia::seleccionarEmpleado(string email){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	bool existe = colUsr->existeUsr(email);
	if(existe)
		empleadoGuardado = email;
	
	return !existe;
}

set<DataEstadia*> ControladorEstadia::listarEstadiasFinalizadasHuesped(){
	set<DataEstadia*> res;
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	res = h->listarEstadiasFinalizadasHuesped(huespedGuardado);
	return res;
}

set<DataEstadia*> ControladorEstadia::listarEstadiasSinFinalizarHuesped(){
	set<DataEstadia*> res;
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	res = h->listarEstadiasSinFinalizarHuesped(huespedGuardado);
	return res;
}

set<DataEstadia*> ControladorEstadia::listarEstadias(){
	set<DataEstadia*> res;
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	res = h->listarEstadias();
	return res;
}

set<DataReserva*> ControladorEstadia::listarReservasNoCanceladasHuesped(){
	set<DataReserva*> res;
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	res = h->listarReservasNoCanceladasHuesped(huespedGuardado);
	return res;
}

set<DataCalificacion*> ControladorEstadia::listarCalificacionesSinResponder(){
	set<DataCalificacion*> res;
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostalEmpleado(empleadoGuardado);
	hostalGuardado = h->getNombre();
	res = h->listarCalificacionesSinResponder();
	return res;
}

void ControladorEstadia::responderCalificacion(string respuesta){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	Usuario* u = colUsr->getUsuario(huespedGuardado);
	Huesped* huesped = dynamic_cast<Huesped*>(u);
	Calificacion* calif = huesped->getCalificacion(reservaGuardada);
	
	Respuesta* resp = new Respuesta(respuesta, calif);

	u = colUsr->getUsuario(empleadoGuardado);
	Empleado* empleado = dynamic_cast<Empleado*>(u);
	empleado->nuevaRespuesta(resp);
}

int ControladorEstadia::seleccionarReserva(int codigo){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	bool existe = h->existeRes(codigo);
	if(existe)
		reservaGuardada = codigo;
	
	return !existe;
}

void ControladorEstadia::registrarEstadia(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	
	HoraDelSistema* horaSys = HoraDelSistema::getInstance();
	DTFecha checkIn = horaSys->getFechaSistema();
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	Usuario* u = colUsr->getUsuario(huespedGuardado);
	Huesped* huesped = dynamic_cast<Huesped*>(u);
	
	Estadia* e = new Estadia(reservaGuardada, checkIn);
	e->asignarHuesped(huesped);
	h->registrarEstadia(reservaGuardada, e, huespedGuardado);
}

void ControladorEstadia::calificarEstadia(string texto, int calificacion){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	h->calificarEstadia(texto, calificacion, reservaGuardada, huespedGuardado);
}

void ControladorEstadia::finalizarEstadia(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	HoraDelSistema* horaSys = HoraDelSistema::getInstance();
	DTFecha checkOut = horaSys->getFechaSistema();
	h->finalizarEstadia(checkOut, reservaGuardada, huespedGuardado);
}

DataCalificacion* ControladorEstadia::verCalificacion(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	DataCalificacion* res = h->verCalificacionEstadia(reservaGuardada, huespedGuardado);
	if(res != NULL)
		calificacionGuardada = res->getComentario();
	else
		calificacionGuardada = "";
	return res;
}

string ControladorEstadia::verRespuesta(){
	string res = "";
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	map<string, Empleado*> emps = h->getEmpleados();
	map<string, Empleado*>::iterator it;
	for(it = emps.begin(); it!= emps.end() && res == ""; it++){
		res = it->second->getRespuesta(calificacionGuardada);
	}
	return res;
}

DataReserva* ControladorEstadia::infoReserva(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	return h->infoReserva(reservaGuardada);
}

set<DataUsuario*> ControladorEstadia::listarEmpleados(){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	return colUsr->listarEmpleados();
}

void ControladorEstadia::suscribirEmpleado(){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	Usuario* u = colUsr->getUsuario(empleadoGuardado);
	Empleado* e = dynamic_cast<Empleado*>(u);
	Suscriptor* sus = dynamic_cast<Suscriptor*>(e);
	
	DTFecha fecha = DTFecha(0, 0, 0, 0);
	Calificacion* calif = new Calificacion("not_calificacion", 0, fecha, "");
	calif->agregarEmpleadoSuscripto(sus);
	delete calif;
}

set<DataNotificacion*> ControladorEstadia::listarNotificaciones(){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	Usuario* u = colUsr->getUsuario(empleadoGuardado);
	Empleado* e = dynamic_cast<Empleado*>(u);
	return e->getNotificaciones();
}

void ControladorEstadia::eliminarSuscripcion(){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	Usuario* u = colUsr->getUsuario(empleadoGuardado);
	Empleado* e = dynamic_cast<Empleado*>(u);
	Suscriptor* sus = dynamic_cast<Suscriptor*>(e);
	
	DTFecha fecha = DTFecha(0, 0, 0, 0);
	Calificacion* calif = new Calificacion("not_calificacion", 0, fecha, "");
	calif->eliminarEmpleadoSuscripto(sus);
	delete calif;
}
