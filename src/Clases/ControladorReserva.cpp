#include "../../Include/Clases/ControladorReserva.h"

//----------Singleton
ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::ControladorReserva(){};

ControladorReserva* ControladorReserva::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorReserva();
	return instancia;
}
//----------Singleton

set<DataReserva*> ControladorReserva::listarReservas(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	set<DataReserva*> res = h->listarReservas();
	return res;
}

set<DataHostal*> ControladorReserva::listarHostales(){
	ColHostales* colHos = ColHostales::getInstance();
	return colHos->listarHostales();
}

int ControladorReserva::seleccionarHostal(string nombre){
	ColHostales* colHos = ColHostales::getInstance();
	bool existe = colHos->existeHos(nombre);
	if(existe)
		hostalGuardado = nombre;
		
	return !existe;
}

int ControladorReserva::seleccionarReserva(int codigo){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	bool existe = h->existeRes(codigo);
	if(existe)
		reservaGuardada = codigo;
	
	return !existe;
}

void ControladorReserva::ingresarDatosReserva(int codigo, DTFecha checkIn, DTFecha checkOut, bool esGrupal){
	codigoRegistrar = codigo;
	checkInRegistrar = new DTFecha(checkIn.getHora(), checkIn.getDia(), checkIn.getMes(), checkIn.getAnio());
	checkOutRegistrar = new DTFecha(checkOut.getHora(), checkOut.getDia(), checkOut.getMes(), checkOut.getAnio());
	esGrupalRegistrar = esGrupal;
}

set<DataHabitacion*> ControladorReserva::listarHabitacionesDisponibles(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	set<DataHabitacion*> res = h->getHabitacionesDisponibles(*checkInRegistrar, *checkOutRegistrar);
	return res;
}

int ControladorReserva::seleccionarHabitacion(int numero){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	bool existe = h->HabitacionEnHostal(numero);
	if(existe)
		habitacionGuardada = numero;
	
	return !existe;
}

set<DataUsuario*> ControladorReserva::listarHuespedes(){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	set<DataUsuario*> res = colUsr->listarHuespedes();
	return res;
}

int ControladorReserva::seleccionarHuesped(string email){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	bool existe = colUsr->existeUsr(email);
	if(existe)
		huespedGuardado = email;
	
	return !existe;
}

int ControladorReserva::incluirHuespedEnReservaGrupal(string email){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	bool existe = colUsr->existeUsr(email);
	if(existe){
		Usuario* u = colUsr->getUsuario(email);
		Huesped* hue = dynamic_cast<Huesped*>(u);
		grupoRegistrar[email] = hue;
	}
	
	return !existe;
}

void ControladorReserva::confirmarReserva(){
	Reserva* res;
	ReservaGrupal* aux;
	if(!esGrupalRegistrar)
		res = new ReservaIndividual(codigoRegistrar, *checkInRegistrar, *checkOutRegistrar);
	else{
		res = new ReservaGrupal(codigoRegistrar, *checkInRegistrar, *checkOutRegistrar);
		aux = dynamic_cast<ReservaGrupal*>(res);
		aux->asignarHuespedesGrupo(grupoRegistrar);
	}
		
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	Usuario* u = colUsr->getUsuario(huespedGuardado);
	Huesped* hue = dynamic_cast<Huesped*>(u);
	Habitacion* hab = h->getHabitacion(habitacionGuardada);
	res->asignarHabitacion(hab);
	res->asignarHuesped(hue);
	
	h->registrarReserva(res);
}

void ControladorReserva::confirmarBaja(){
	ColHostales* colHos = ColHostales::getInstance();
	Hostal* h = colHos->getHostal(hostalGuardado);
	h->borrarReserva(reservaGuardada);
}
