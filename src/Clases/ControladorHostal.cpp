#include "../../Include/Clases/ControladorHostal.h"

//----------Singleton
ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal(){};

ControladorHostal* ControladorHostal::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorHostal();
	return instancia;
}
//----------Singleton


//Si retorna 0, almaceno el dataHostal.
int ControladorHostal::ingresarDatosHostal(DataHostal dataHostal){
	ColHostales* colHos = ColHostales::getInstance();
	bool existe = colHos->existeHos(dataHostal.getNombre());
	if(!existe)
		dataHostalRegistrar = new DataHostal(dataHostal.getNombre(), dataHostal.getDireccion(), dataHostal.getTelefono(), dataHostal.getPromedioCalif());
		
	return existe;
}

void ControladorHostal::confirmarAltaHostal(){
	string nombre = dataHostalRegistrar->getNombre();
	string direccion = dataHostalRegistrar->getDireccion();
	int telefono = dataHostalRegistrar->getTelefono();
	Hostal* hos = new Hostal(nombre, direccion, telefono);
	ColHostales* colHos = ColHostales::getInstance();
	colHos->registrarHostal(hos);
}

set<DataHostal*> ControladorHostal::listarHostales(){
	ColHostales* colHos = ColHostales::getInstance();
	return colHos->listarHostales();
}

int ControladorHostal::seleccionarHostal(string nombre){
	ColHostales* colHos = ColHostales::getInstance();
	bool existe = colHos->existeHos(nombre);
	if(existe)
		hostalGuardado = nombre;
		
	return !existe;
}

set<DataReserva*> ControladorHostal::listarReservas(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	return h->listarReservas();
}

int ControladorHostal::ingresarDatosHabitacion(DataHabitacion dataHab){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	bool existeHab = h->HabitacionEnHostal(dataHab.getNumero());
	if(!existeHab){
		DataHabitacion* hab = new DataHabitacion(dataHab.getNumero(), dataHab.getCapacidad(), dataHab.getPrecio());
		dataHabitacionRegistrar = hab;
	}
		
	return existeHab;
}

void ControladorHostal::cancelarAltaHabitacion(){
	delete dataHabitacionRegistrar;
}

void ControladorHostal::confirmarAltaHabitacion(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	h->registrarHabitacion(*dataHabitacionRegistrar);
}

set<DataUsuario*> ControladorHostal::listarEmpleadosNoAsignadosHostal(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	map<string, Empleado*> emps = h->getEmpleados();
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	return colUsr->listarOtrosEmpleados(emps);
}

int ControladorHostal::seleccionarEmpleadoAsignar(string email, DTCargo cargo){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	bool existe = colUsr->existeUsr(email);
	if(existe){
		empleadoGuardado = email;
		Empleado* e = dynamic_cast<Empleado*>(colUsr->getUsuario(email));
		e->setCargo(cargo);
	}
		
	return !existe;
}

void ControladorHostal::cancelarAsignarEmpleadoHostal(){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	Empleado* e = dynamic_cast<Empleado*>(colUsr->getUsuario(empleadoGuardado));
	e->setCargo(DTCargo::Desocupado);
}

void ControladorHostal::confirmarAsignarEmpleadoHostal(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	h->asignarEmpleado(colUsr->getUsuario(empleadoGuardado));
}

list<DataHostal> ControladorHostal::listarTop3Hostales(){
	ColHostales* colHos = ColHostales::getInstance();
	set<DataHostal*> todos = colHos->listarHostales();
	
	list<DataHostal> todosOrdenados;
	set<DataHostal*>::iterator it;
	
	for(it = todos.begin(); it != todos.end(); it++){
		DataHostal actual = *(*it);
		todosOrdenados.push_back(actual);
	}
	
	todosOrdenados.sort();
	
	return todosOrdenados;
}

set<DataHabitacion*> ControladorHostal::listarHabitaciones(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	return h->listarHabitaciones();
}

set<DataCalificacion*> ControladorHostal::listarCalificaciones(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	return h->listarCalificaciones();
}

//
// 		getters por las dudas
//

DataHostal* ControladorHostal::getDataHostalRegistrar(){
	return dataHostalRegistrar;
}

DataHabitacion* ControladorHostal::getDataHabitacionRegistrar(){
	return dataHabitacionRegistrar;
}

string ControladorHostal::getHostalGuardado(){
	return hostalGuardado;
}

string ControladorHostal::getEmpleadoGuardado(){
	return empleadoGuardado;
}
