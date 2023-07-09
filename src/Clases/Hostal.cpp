#include "../../Include/Clases/Hostal.h"

Hostal::Hostal(string nombre, string direccion, int telefono){
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
}

string Hostal::getNombre(){
	return nombre;
}

string Hostal::getDireccion(){
	return direccion;
}

int Hostal::getTelefono(){
	return telefono;
}

bool Hostal::HabitacionEnHostal(int numero){
	return habitaciones.count(numero) > 0;
}

bool Hostal::existeRes(int codigo){
	return reservas.count(codigo) > 0;
}

void Hostal::registrarHabitacion(DataHabitacion dataHab){
	int numero = dataHab.getNumero();
	int capacidad = dataHab.getCapacidad();
	float precio = dataHab.getPrecio();
	Habitacion* hab = new Habitacion(numero, capacidad, precio);
	habitaciones[dataHab.getNumero()] = hab;
}

map<string, Empleado*> Hostal::getEmpleados(){
	map<string, Empleado*> res;
	map<string, Empleado*>::iterator it;
	
	for(it = empleados.begin(); it != empleados.end(); it++){
		res[it->first] = it->second;
	}
	
	return res;
	
}

void Hostal::asignarEmpleado(Usuario* e){
	Empleado* emp = dynamic_cast<Empleado*>(e);
	empleados[emp->getEmail()] = emp;
}

set<DataReserva*> Hostal::listarReservas(){
	set<DataReserva*> res;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it != reservas.end(); it++){
		res.insert(it->second->getDataReserva());
	}
	return res;
}

void Hostal::calificarEstadia(string texto, int calificacion, int codigo, string email){
	Reserva* res = reservas[codigo];
	res->calificar(texto, calificacion, email);
}

set<DataHabitacion*> Hostal::getHabitacionesDisponibles(DTFecha checkIn, DTFecha checkOut){
	set<DataHabitacion*> res;
	set<int> aux;
	
	map<int, Habitacion*>::iterator it;
	for(it = habitaciones.begin(); it != habitaciones.end(); it++)
		aux.insert(it->second->getNumero());
		
	map<int, Reserva*>::iterator i;
	for(i = reservas.begin(); i != reservas.end(); i++){
		if(i->second->habitacionOcupadaEntre(checkIn, checkOut)){
			if(aux.count(i->second->getNroHabitacion())){
				aux.erase(i->second->getNroHabitacion());
			}
		}
	}
	
	set<int>::iterator j;
	for(j = aux.begin(); j != aux.end(); j++)
		res.insert(habitaciones[*j]->getDataHabitacion());
	
	return res;
}

Habitacion* Hostal::getHabitacion(int numero){
	return habitaciones[numero];
}

void Hostal::registrarReserva(Reserva* r){
	reservas[r->getCodigo()] = r;
}

void Hostal::borrarReserva(int codigo){
	Reserva* aBorrar = reservas[codigo];
	reservas.erase(codigo);
	aBorrar->borrarEstadias();
	delete aBorrar;
}

void Hostal::registrarEstadia(int codigo, Estadia* e, string email){
	Reserva* reserva = reservas[codigo];
	reserva->asignarEstadia(e, email);
	reserva->cerrarReserva();
}

void Hostal::finalizarEstadia(DTFecha checkOut, int codigoRes, string email){
	Reserva* res = reservas[codigoRes];
	res->finalizar(checkOut, email);
}

set<DataReserva*> Hostal::listarReservasHuesped(string email){
	set<DataReserva*> res;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it!= reservas.end(); it++){
		if(it->second->getHuesped()->getEmail() == email)
			res.insert(it->second->getDataReserva());
		else{
			ReservaGrupal* actual = dynamic_cast<ReservaGrupal*>(it->second);
			if(actual != NULL){
				map<string, Huesped*> huespedes = actual->getHuespedes();
				if(huespedes.count(email) > 0)
					res.insert(it->second->getDataReserva());
			}
		}
	}
	
	return res;
}

set<DataEstadia*> Hostal::listarEstadiasFinalizadasHuesped(string email){
	set<DataEstadia*> res;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it != reservas.end(); it++){
		if(it->second->getEstado() == DTEstado::Cerrada){
			if(it->second->getHuesped()->getEmail() == email){
				Estadia* e = it->second->getEstadia(email);
				if(e->getCheckOut() != NULL)
					res.insert(it->second->getDataEstadia(email, nombre));
			}
			else{
				ReservaGrupal* actual = dynamic_cast<ReservaGrupal*>(it->second);
				if(actual != NULL){
					map<string, Estadia*> estadias = actual->getEstadias();
					if(estadias.count(email) > 0 && estadias[email]->getCheckOut() != NULL)
						res.insert(it->second->getDataEstadia(email, nombre));
				}
			}
		}
	}
	return res;
}

set<DataEstadia*> Hostal::listarEstadiasSinFinalizarHuesped(string email){
	set<DataEstadia*> res;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it != reservas.end(); it++){
		if(it->second->getEstado() == DTEstado::Cerrada){
			if(it->second->getHuesped()->getEmail() == email){
				Estadia* e = it->second->getEstadia(email);
				if(e->getCheckOut() == NULL)
					res.insert(it->second->getDataEstadia(email, nombre));
			}
			else{
				ReservaGrupal* actual = dynamic_cast<ReservaGrupal*>(it->second);
				if(actual != NULL){
					map<string, Estadia*> estadias = actual->getEstadias();
					if(estadias.count(email) > 0 && estadias[email]->getCheckOut() == NULL)
						res.insert(it->second->getDataEstadia(email, nombre));
				}
			}
		}
	}
	return res;
}

set<DataEstadia*> Hostal::listarEstadias(){
	set<DataEstadia*> res;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it != reservas.end(); it++){
		if(it->second->getEstado() == DTEstado::Cerrada){
			ReservaIndividual* resI = dynamic_cast<ReservaIndividual*>(it->second);
			if(resI != NULL && resI->getEstadia("dummy") != NULL)
				res.insert(it->second->getDataEstadia("dummy", nombre));
			else{
				ReservaGrupal* resG = dynamic_cast<ReservaGrupal*>(it->second);
				map<string, Estadia*> estadias = resG->getEstadias();
				map<string, Estadia*>::iterator i;
				for(i = estadias.begin(); i != estadias.end(); i++)
					res.insert(it->second->getDataEstadia(i->first, nombre));
			}
		}
	}
	return res;
}

set<DataReserva*> Hostal::listarReservasNoCanceladasHuesped(string email){
	set<DataReserva*> res;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it!= reservas.end(); it++){
		if(it->second->getHuesped()->getEmail() == email)
			if(it->second->getEstado() == DTEstado::Abierta)
				res.insert(it->second->getDataReserva());
		else{
			ReservaGrupal* actual = dynamic_cast<ReservaGrupal*>(it->second);
			if(actual != NULL){
				map<string, Huesped*> huespedes = actual->getHuespedes();
				if(huespedes.count(email) > 0)
					if(it->second->getEstado() == DTEstado::Abierta)
						res.insert(it->second->getDataReserva());
			}
		}
	}
	
	return res;
}

set<DataCalificacion*> Hostal::listarCalificacionesSinResponder(){
	set<DataCalificacion*> res;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it != reservas.end(); it++){
		if(it->second->getEstado() == DTEstado::Cerrada){
			ReservaIndividual* resI = dynamic_cast<ReservaIndividual*>(it->second);
			if(resI != NULL){
				Estadia* e = resI->getEstadia("dummy");
				if(e->conCalificacion() && !e->califConRespuesta())
					res.insert(e->getDataCalificacion());
			}
			else{
				ReservaGrupal* resG = dynamic_cast<ReservaGrupal*>(it->second);
				map<string, Estadia*> estadias = resG->getEstadias();
				map<string, Estadia*>::iterator i;
				for(i = estadias.begin(); i != estadias.end(); i++){
					if(i->second->conCalificacion() && !i->second->califConRespuesta())
						res.insert(i->second->getDataCalificacion());
				}
			}
		}
	}
	
	return res;
}

DataCalificacion* Hostal::verCalificacionEstadia(int codigo, string email){
	Reserva* res = reservas[codigo];
	return res->getCalificacion(email);
}

DataHostal* Hostal::getDataHostal(){
	DataHostal* res = new DataHostal(nombre, direccion, telefono, calcularPromedioCalif());
	return res;
}

DataReserva* Hostal::infoReserva(int codigo){
	return reservas[codigo]->getDataReserva();
}

float Hostal::calcularPromedioCalif(){
	float suma = 0;
	int cantidad = 0;
	DataCalificacion* actual;
	map<int, Reserva*>::iterator it;
	
	for(it = reservas.begin(); it != reservas.end(); it++){
		if(it->second->getEstado() == DTEstado::Cerrada){
			ReservaIndividual* resI = dynamic_cast<ReservaIndividual*>(it->second);
			if(resI != NULL){
				actual = resI->getCalificacion("dummy");
				if(actual != NULL){
					suma += actual->getCalificacion();
					cantidad++;
					delete actual;
				}
			}
			else{
				ReservaGrupal* resG = dynamic_cast<ReservaGrupal*>(it->second);
				map<string, Estadia*> estadias = resG->getEstadias();
				map<string, Estadia*>::iterator i;
				for(i = estadias.begin(); i != estadias.end(); i++){
					actual = i->second->getDataCalificacion();
					if(actual != NULL){
						suma += actual->getCalificacion();
						cantidad++;
						delete actual;
					}
				}
			}
		}
	}
	
	float res = 0;
	
	if(cantidad > 0)
		res = suma/cantidad;
	
	return res;
}

set<DataHabitacion*> Hostal::listarHabitaciones(){
	set<DataHabitacion*> res;
	map<int, Habitacion*>::iterator it;
	for(it = habitaciones.begin(); it!=habitaciones.end(); it++)
		res.insert(it->second->getDataHabitacion());
		
	return res;
}

set<DataCalificacion*> Hostal::listarCalificaciones(){
	set<DataCalificacion*> res;
	DataCalificacion* actual;
	map<int, Reserva*>::iterator it;
	for(it = reservas.begin(); it != reservas.end(); it++){
		if(it->second->getEstado() == DTEstado::Cerrada){
			ReservaIndividual* resI = dynamic_cast<ReservaIndividual*>(it->second);
			if(resI != NULL){
				actual = resI->getCalificacion("dummy");
				if(actual != NULL)
					res.insert(actual);
			}
			else{
				ReservaGrupal* resG = dynamic_cast<ReservaGrupal*>(it->second);
				map<string, Estadia*> estadias = resG->getEstadias();
				map<string, Estadia*>::iterator i;
				for(i = estadias.begin(); i != estadias.end(); i++){
					actual = i->second->getDataCalificacion();
					if(actual != NULL)
						res.insert(actual);
				}
			}
		}
	}
	
	return res;
}
