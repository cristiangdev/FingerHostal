#include <iostream>
//#include "Include/Clases/ColUsuarios.h"
//#include "Include/Clases/Usuario.h"
//#include "Include/Clases/Empleado.h"
//#include "Include/Clases/Huesped.h"
//#include "Include/Clases/ColHostales.h"
//#include "Include/Clases/Hostal.h"
//#include "Include/Clases/Habitacion.h"
//#include "Include/Clases/Reserva.h"
//#include "Include/Clases/ReservaIndividual.h"
//#include "Include/Clases/ReservaGrupal.h"
//#include "Include/Clases/Estadia.h"
//#include "Include/Clases/Calificacion.h"
//#include "Include/Clases/Suscriptor.h"

#include "Include/Clases/Fabrica.h"
#include "Include/Clases/IControladorHostal.h"
#include "Include/Clases/IControladorUsuario.h"
#include "Include/Clases/IControladorReserva.h"
#include "Include/Clases/IControladorEstadia.h"

#include "Include/Clases/HoraDelSistema.h"
//#include "Include/Clases/Respuesta.h"


#include "Include/dataTypes/DTFecha.h"
#include "Include/dataTypes/DTEstado.h"
#include "Include/dataTypes/DTCargo.h"
#include "Include/dataTypes/DataUsuario.h"
#include "Include/dataTypes/DataHuesped.h"
#include "Include/dataTypes/DataEmpleado.h"
#include "Include/dataTypes/DataHostal.h"
#include "Include/dataTypes/DataHabitacion.h"
#include "Include/dataTypes/DataReserva.h"
#include "Include/dataTypes/DataReservaIndividual.h"
#include "Include/dataTypes/DataReservaGrupal.h"
#include "Include/dataTypes/DataEstadia.h"
#include "Include/dataTypes/DataCalificacion.h"
#include "Include/dataTypes/DataNotificacion.h"


// Estilos:
// Sobrecargas de << FECHA
ostream& operator<<(ostream& o, DTFecha& f){
	o << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << " @ " << f.getHora() << "hs.";
	return o;
}

ostream& operator<<(ostream& o, DTCargo& d){
	d = DTCargo::Desocupado;
	switch (d)
	{
	case (DTCargo::Administrativo) :
		o << "Administrativo";
		break;
	case (DTCargo::Desocupado) :
		o << "Desocupado";
		break;
	case (DTCargo::Infraestructura) :
		o << "Infraestructura";
		break;
	case (DTCargo::Limpieza) :
		o << "Limpieza";
		break;
	case (DTCargo::Recepcion) :
		o << "Recepcion";
		break;
	default:
		o << "Error";
		break;
	}
	return o;
}

ostream& operator<<(ostream& o, DTEstado& d){
	switch (d)
	{
	case DTEstado::Abierta :
		o << "Abierta";
		break;
	case (DTEstado::Cancelada) :
		o << "Cancelada";
		break;
	case (DTEstado::Cerrada) :
		o << "Cerrada";
		break;
	default:
		o << "Error";
		break;
	}
	return o;
}


ostream& operator<<(ostream& o, DataUsuario* d){
	bool esEmpleado = dynamic_cast<DataEmpleado*>(d) != NULL;
	o << "TipoUsuario: " << (esEmpleado ? "Empleado":"Huesped") << endl <<
		 "Nombre: " << d->getNombre() << endl <<
		 "Email: " << d->getEmail() << endl <<
		 "Pswd: " << d->getPass() << endl;
	if(esEmpleado){
		DTCargo cargo = dynamic_cast<DataEmpleado*>(d)->getCargo();
		o << "Cargo: " << cargo << endl;
	}
	else
		o << "Es Finger: " << ((dynamic_cast<DataHuesped*>(d)->getEsFinger()) ? "Si":"No") << endl;
	return o;
}


ostream& operator<<(ostream& o, DataReserva* d){
	bool esIndividual = dynamic_cast<DataReservaIndividual*>(d) != NULL;
	DTEstado estado =  d->getEstado();
	DTFecha fechaIn = d->getCheckIn();
	DTFecha fechaOut = d->getCheckOut();
	o << "Tipo de Reserva: " << (esIndividual ? "Individual":"Grupal") << endl <<
		 "Codigo: " << d->getCodigo() << endl <<
		 "Estado: " << estado << endl <<
		 "Check-In: " << fechaIn << endl <<
		 "Check-Out: " << fechaOut << endl <<
		 "Habitacion: " << d->getHabitacion() << endl <<
		 "Huesped Ppal.: " << d->getHuesped() << endl <<
		 "Costo: " << d->getCosto()<< endl;
	if(!esIndividual){
		set<string> huespedes = dynamic_cast<DataReservaGrupal*>(d)->getHuespedes();
		o << "Otros Huespedes: ";
		set<string>::iterator it;
		for(it = huespedes.begin(); it != huespedes.end(); ++it) 
			o << *it << ", ";
		o << "." << endl;
	}
	return o;
}

ostream& operator<<(ostream& o, DataHostal* d){
	o << "Nombre: " << d->getNombre() << endl <<
		 "Calificacion: " << d->getPromedioCalif() << endl <<
		 "Direccion: " << d->getDireccion() << endl <<
		 "Telefono: " << d->getTelefono() << endl;
	return o;
}

//ostream& operator<<(ostream& o, DataHostal d){
	//return o;
//}

ostream& operator<<(ostream& o, DataHabitacion* d){
	o << "Numero: " << d->getNumero() << endl <<
	     "Capacidad: " << d->getCapacidad() << endl <<
	     "Precio: " << d->getPrecio() << endl;
	     
	return o;
}

ostream& operator<<(ostream& o, DataEstadia* d){
	DTFecha checkIn = d->getCheckIn();
	o << "Hostal: " << d->getHostal() << endl <<
	     "Codigo: " << d->getReserva() << endl <<
	     "Habitacion: " << d->getHabitacion() << endl <<
	     "Huesped: " << d->getHuesped() << endl <<
	     "Check-In: " << checkIn << endl <<
	     "Check-Out: ";
	DTFecha* checkOut = d->getCheckOut();
	if(checkOut != NULL)
		o << *checkOut << endl;
	else
		o <<"Estadia aun sin finalizar."<<endl;
	
	return o;
}

ostream& operator<<(ostream& o, DataCalificacion* d){
	DTFecha fecha = d->getFecha();
	o << "Reserva: " << d->getCodigo() << endl <<
	     "Autor: " << d->getAutor() << endl <<
	     "Fecha: " << fecha << endl <<
	     "Calificacion: " << d->getCalificacion() << endl <<
	     "Comentario: " << d->getComentario() << endl;
	     
	return o;
}

ostream& operator<<(ostream& o, DataNotificacion* d){
	DTFecha fecha = d->getFecha();
	o << fecha << endl <<
	     "Autor: " << d->getAutor() << endl <<
	     "Calificacion: " << d->getPuntaje() << endl <<
	     "Comentario: " << d->getComentario() <<endl;
	     
	return o;
}
	

// Funciones auxiliares

void imprimirToMenu() {
	cout << endl << "***Volviendo al menu principal...***" << endl << endl;
}

void borrarAPrepo() {
	string basura;
	getline(cin,basura);
}

string solicitarString(string mensaje) {
	cout << mensaje << " --> ";
	string res;
	getline(cin, res);
	return res;
}

bool solicitarBool(string mensaje){
	cout << mensaje << " (Ingrese 1 para SI, 0 para NO) --> ";
	int infoFinger;
	cin >> infoFinger;
	cin.ignore(1,'\n');
	bool res = infoFinger == 1;
	return res;
}

int solicitarInt(string mensaje) {
	cout << mensaje << " --> ";
	int res;
	cin >> res;
	return res;
}

DTCargo solicitarCargo(string mensaje){
	cout << mensaje<<endl<<endl;
	cout << "1. Administrativo"	<<endl
		 << "2. Limpieza"		<<endl
		 << "3. Recepcion"		<<endl
		 << "4. Infraestructura"<<endl<<endl;
	int eleccion;
	cin >> eleccion;
	borrarAPrepo();
	switch(eleccion)
	{
		case 1: {
			return DTCargo::Administrativo;
		} break;
		case 2: {
			return DTCargo::Limpieza;
		} break;
		case 3: {
			return DTCargo::Recepcion;
		} break;
		case 4: {
			return DTCargo::Infraestructura;
		} break;
		default: {
			return DTCargo::Desocupado;
		} break;
	}
}

DTFecha solicitarFecha(string mensaje){
	cout << mensaje << endl;
	cout << "Dia: ";
	int dia;
	cin >> dia;
	borrarAPrepo();
	cout<< "Mes: ";
	int mes;
	cin >> mes;
	borrarAPrepo();
	cout << "Anio: ";
	int anio;
	cin >> anio;
	borrarAPrepo();
	cout << "Hora: ";
	int hora;
	cin >> hora;
	borrarAPrepo();
	DTFecha res = DTFecha(hora, dia, mes, anio);
	return res;
}

int main() {

	cout << "---------- HOSTEL FING ---------" << endl << endl;
	Fabrica* fab = Fabrica::getInstance();
	IControladorUsuario* IUsuario = fab->getIControladorUsuario();
	IControladorHostal* IHostal = fab->getIControladorHostal();
	IControladorReserva* IReserva = fab->getIControladorReserva();
	IControladorEstadia* IEstadia = fab->getIControladorEstadia();
	/*
	Sistema sys = Sistema();
	cout << "*** Sistema Iniciado ***" << endl << endl;
	*/
	bool salir = false;
	int codigoReserva = 0;
	bool datosCargados = false;

	while (!salir)
	{
		cout << "---------- MENU PRINCIPAL ---------" << endl << endl;
		cout << "Ingrese el numero correspondiente a la accion que desea realizar:" << endl;
		cout << "A.  Alta de Usuario" << endl <<
				"B.  Alta de Hostal" << endl <<
				"C.  Alta de Habitación" << endl <<
				"D.  Asignar Empleado a Hostal" << endl <<
				"E.  Realizar Reserva" << endl <<
				"F.  Consultar top 3 de Hostales " << endl <<
				"G.  Registrar Estadía" << endl <<
				"H.  Finalizar Estadía" << endl <<
				"I.  Calificar Estadía" << endl <<
				"J. Comentar Calificación" << endl <<
				"K. Consulta de Usuario" << endl <<
				"L. Consulta de Hostal" << endl <<
				"M. Consulta de Reserva" << endl <<
				"N. Consulta de Estadía" << endl <<
				"O. Baja de Reserva" << endl <<
				"P. Suscribirse a Notificaciones" << endl <<
				"Q. Consulta de Notificaciones" << endl <<
				"R. Eliminar Suscripción" << endl <<
				"S. Modificar Fecha del sistema" << endl <<
				"T. Cargar datos" << endl <<
				"U. Salir" << endl << endl;
		char COMANDO = 0;
		bool fin = false;
		cin >> COMANDO; // Va a haber que cambiarlo, solo sirve para 1 caracter
		borrarAPrepo();
		switch (COMANDO)
		{
		case 'A': {
			cout << endl;
			cout << "---------- ALTA DE USUARIO ---------" << endl << endl;
			bool CANCELAR = false;
			while(!fin){
					DataUsuario* infoUsuario = NULL;
					string nombre = solicitarString("Ingrese el nombre");
					string email = solicitarString("Ingrese email");
					string password = solicitarString("Ingrese contraseña");

					bool esEmpleado = solicitarBool("Desea Registrar un empleado? ");
					if (esEmpleado){
						DTCargo cargo = DTCargo::Administrativo; // para probar, falta resolver el solicitarCargo() de la linea comentada abajo
						//DTCargo cargo = solicitarCargo("Ingrese el cargo del empleado a registrar");
						infoUsuario = new DataEmpleado(nombre, email, password, cargo);
					}
					else {
						bool esFinger = solicitarBool("El huésped es finger?");
						infoUsuario = new DataHuesped(nombre, email, password, esFinger);
					}
					int error = IUsuario->ingresarDatosUsuario(infoUsuario);
					if (error == 0) {
						IUsuario->confirmarAltaUsuario();
						fin = true;
					}
					else {
						cout << "El huesped que ha intentado ingresar ya estaba registrado." << endl;
						IUsuario->cancelarAltaUsuario();
						fin = !solicitarBool("Desea Intentarlo Nuevamente?");
					}
			}
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu(); 
		}
			break;
		case 'B': {
			cout<< endl;
			cout << "---------- ALTA DE HOSTAL ---------" << endl << endl;
			string nombre = solicitarString("Ingrese el nombre");
			string direccion = solicitarString("Ingrese la direccion");
			cout<< "Ingrese el numero telefonico" << "--> ";
			int telefono;
			cin >> telefono;
			borrarAPrepo();
			DataHostal dataHos = DataHostal(nombre, direccion, telefono, 0);
			bool error = IHostal->ingresarDatosHostal(dataHos);
			if(!error){
				IHostal->confirmarAltaHostal();
				cout<<endl<<"El hostal se ha registrado correctamente."<<endl;
			}
			else
				cout<<endl<<"El hostal que ha intentado registrar ya existe en el sistema."<<endl;
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu(); 
		}
			break;
		case 'C': {
			cout << endl;
			cout << "---------- ALTA DE HABITACIÓN ---------" << endl << endl;
			set<DataHostal*> listaHostales = IHostal->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			bool error = true;
			while(error && !listaHostales.empty()){
				string nombre = solicitarString("Ingrese el NOMBRE del Hostal en el cual desea registrar la habitacion: ");
				error = IHostal->seleccionarHostal(nombre);
				if(!error){
					cout<< "Ingrese el numero de la Habitacion" << "--> ";
					int numero;
					cin >> numero;
					borrarAPrepo();
					cout<< "Ingrese la capacidad" << "--> ";
					int capacidad;
					cin >> capacidad;
					borrarAPrepo();
					cout<< "Ingrese el precio" << "--> ";
					float precio;
					cin >> precio;
					borrarAPrepo();
					DataHabitacion dataHab = DataHabitacion(numero, capacidad, precio);
					error = IHostal->ingresarDatosHabitacion(dataHab);
					if(!error){
						cout<<endl;
						bool confirmar = solicitarBool("Desea confirmar el alta de la Habitacion?");
						if(confirmar)
							IHostal->confirmarAltaHabitacion();
						else
							IHostal->cancelarAltaHabitacion();
					}
					else
						cout<<endl<<"El numero de Habitacion ingresado ya se encontraba registrado en el Hostal seleccionado, intentelo nuevamente."<<endl<<endl;
				}
					
				else
					cout<<endl<< "El Hostal que ingreso no es correcto, intentelo nuevamente."<<endl;
					
			}
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu(); 
		}
			break;
		case 'D': {
			cout << endl;
			cout << "---------- ASIGNAR EMPLEADO A HOSTAL ---------" << endl << endl;
			set<DataHostal*> listaHostales = IHostal->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			bool error = true;
			while(error && !listaHostales.empty()){
				string nombre = solicitarString("Ingrese el NOMBRE del Hostal al cual desea asignar un Empleado: ");
				error = IHostal->seleccionarHostal(nombre);
				if(!error){
					cout<<endl<<"Empleados no asignados al Hostal seleccionado: "<<endl<<endl;
					set<DataUsuario*> listaEmpleados = IHostal->listarEmpleadosNoAsignadosHostal();
					set<DataUsuario*>::iterator i;
					for(i = listaEmpleados.begin(); i!= listaEmpleados.end(); i++)
						cout<< (*i)->getNombre() << " - " << (*i)->getEmail()<<endl;
					if(!listaEmpleados.empty()){
						string email = solicitarString("Ingrese el EMAIL del empleado a asignar: ");
						DTCargo cargo = solicitarCargo("Ingrese el Cargo a desempeniar: ");
						error = IHostal->seleccionarEmpleadoAsignar(email, cargo);
						if(!error){
							cout<<endl;
							bool confirmar = solicitarBool("Desea confirmar la asignacion?");
							if(confirmar)
								IHostal->confirmarAsignarEmpleadoHostal();
							else
								IHostal->cancelarAsignarEmpleadoHostal();
						}
						else
							cout<<endl<<"El empleado que ingreso no es correcto, intentelo nuevamente."<<endl<<endl;
					}
					else{
						cout<<endl<<"No hay empleados no asignados al Hostal seleccionado."<<endl<<endl;
						error = false;
					}
				}
				else
					cout<<endl<< "El Hostal que ingreso no es correcto, intentelo nuevamente."<<endl<<endl;
			}
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'E': {
			cout << endl;
			cout << "---------- REALIZAR RESERVA ---------" << endl << endl;
			set<DataHostal*> listaHostales = IReserva->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it) << endl << endl;
			bool error = true;
			while(error && !listaHostales.empty()){
				string nombre = solicitarString("Ingrese el NOMBRE del Hostal en el cual quiere registrar una Reserva: ");
				error = IReserva->seleccionarHostal(nombre);
				if(!error){
					cout<<endl;
					DTFecha checkIn = solicitarFecha("Ingrese fecha de CheckIn para la Reserva: ");
					cout<<endl;
					DTFecha checkOut = solicitarFecha("Ingrese fecha de CheckOut para la Reserva: ");
					cout<<endl;
					bool esGrupal = solicitarBool("La reserva es Grupal?");
					IReserva->ingresarDatosReserva(codigoReserva, checkIn, checkOut, esGrupal);
					set<DataHabitacion*> listaHabitaciones = IReserva->listarHabitacionesDisponibles();
					set<DataHabitacion*>::iterator i;
					cout<<endl<< "Habitaciones disponibles: "<<endl<<endl;
					for(i = listaHabitaciones.begin(); i != listaHabitaciones.end(); i++)
						cout << (*i) << endl;
					if(!listaHabitaciones.empty()){
						cout<< "Ingrese el numero de la habitacion --> ";
						int numero;
						cin >> numero;
						borrarAPrepo();
						error = IReserva->seleccionarHabitacion(numero);
						if(!error){
							set<DataUsuario*> listaHuespedes = IReserva->listarHuespedes();
							set<DataUsuario*>::iterator j;
							cout<<endl;
							for(j = listaHuespedes.begin(); j != listaHuespedes.end(); j++)
								cout<< (*j)->getNombre() << " - " << (*j)->getEmail()<<endl;
							cout<<endl;
							string email = solicitarString("Ingrese el EMAIL del Huesped que realiza la Reserva: ");
							error = IReserva->seleccionarHuesped(email);
							if(!error){
								if(esGrupal){
									bool agregar = true;
									while(agregar && !error){
										email = solicitarString("Ingrese el nombre de otro Huesped: ");
										error = IReserva->incluirHuespedEnReservaGrupal(email);
										agregar = solicitarBool("Desea seguir agregando huespedes? ");
									}
								}
								if(!error){
									cout<<endl;
									bool confirmar = solicitarBool("Desea confirmar la Reserva? ");
									if(confirmar){
										IReserva->confirmarReserva();
										codigoReserva++;
									}
								}
								else
									cout<<endl<<"El huesped que ingreso no esta registrado en el sistema."<<endl<<endl;
							}
							else
								cout<<endl<<"El huesped que ingreso no esta registrado en el sistema."<<endl<<endl;
						}
						else
							cout<<endl<< "El numero de habitacion que ingreso no es valido."<<endl<<endl;
							
					}
					else
						cout<<endl<< "El Hostal que ingreso no tiene habitaciones disponibles."<<endl<<endl;
				}
				else
					cout<<endl<< "El Hostal que ingreso no es correcto, intentelo nuevamente."<<endl<<endl;
			}
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'F': {
			cout<<endl;
			cout << "---------- CONSULTAR TOP 3 DE HOSTALES ---------" << endl << endl;
			list<DataHostal> top3Hostales = IHostal->listarTop3Hostales();
			list<DataHostal>::reverse_iterator it;
			int imprimidos = 0;
			for(it = top3Hostales.rbegin(); it != top3Hostales.rend() && imprimidos < 3; it++){
				cout<<(*it).getNombre() << " - Calificacion: " << (*it).getPromedioCalif() << endl;
				imprimidos++;
			}
			
			if(!top3Hostales.empty()){
				cout<<endl;
				string nombre = solicitarString("Ingrese el NOMBRE del Hostal que desea consultar: ");
				bool error = IHostal->seleccionarHostal(nombre);
				if(!error){
					cout<<endl;
					cout<<"--CALIFICACIONES--"<<endl<<endl;
					set<DataCalificacion*> listaCalificaciones = IHostal->listarCalificaciones();
					set<DataCalificacion*>::iterator k;
					for(k = listaCalificaciones.begin(); k != listaCalificaciones.end(); k++)
						cout<<(*k)<<endl;
				}
				else
					cout<<endl<<"El Hostal que ingreso no es correcto, intentelo nuevamente." << endl<<endl;
			}

			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'G': {
			cout<<endl;
			cout << "---------- REGISTRAR ESTADÍA ---------" << endl << endl;
			set<DataHostal*> listaHostales = IEstadia->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			string nombre = solicitarString("Ingrese el NOMBRE del Hostal en el cual quiere registrar la Estadia: ");
			bool error = IEstadia->seleccionarHostal(nombre);
			if(!error){
				cout<<endl;
				string email = solicitarString("Ingrese el EMAIL del Huesped del cual quiere registrar la Estadia: ");
				error = IEstadia->seleccionarHuesped(email);
				if(!error){
					cout<<endl;
					set<DataReserva*> listaReservas = IEstadia->listarReservasNoCanceladasHuesped();
					set<DataReserva*>::iterator i;
					for(i = listaReservas.begin(); i != listaReservas.end(); i++)
						cout<< (*i)<<endl;
					if(!listaReservas.empty()){
						cout<< "Ingrese el CODIGO de la Reserva deseada --> ";
						int codigo;
						cin>>codigo;
						borrarAPrepo();
						error = IEstadia->seleccionarReserva(codigo);
						if(!error)
							IEstadia->registrarEstadia();
						else
							cout<<endl<<"La reserva que ingreso no existe en el Hostal seleccionado." << endl<<endl;
					}
					else
						cout<<endl<<"El huesped que ingreso no pertenece a ninguna reserva en el Hostal seleccionado." << endl<<endl;
				}
				else
					cout<<endl<<"El usuario que ingreso no es correcto, intentelo nuevamente." << endl<<endl;
			}
			else
				cout<<endl<<"El Hostal que ingreso no es correcto, intentelo nuevamente." << endl<<endl;
				
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'H': {
			cout<<endl;
			cout << "---------- FINALIZAR ESTADÍA ---------" << endl << endl;
			set<DataHostal*> listaHostales = IEstadia->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			string nombre = solicitarString("Ingrese el NOMBRE del Hostal en el cual quiere finalizar la Estadia: ");
			bool error = IEstadia->seleccionarHostal(nombre);
			if(!error){
				cout<<endl;
				string email = solicitarString("Ingrese el EMAIL del Huesped del cual quiere finalizar la Estadia: ");
				error = IEstadia->seleccionarHuesped(email);
				if(!error){
					set<DataEstadia*> listaEstadias = IEstadia->listarEstadiasSinFinalizarHuesped();
					set<DataEstadia*>::iterator i;
					cout<<endl;
					for(i = listaEstadias.begin(); i != listaEstadias.end(); i++)
						cout<< (*i)<<endl;
					if(!listaEstadias.empty()){
						cout<< "Ingrese el CODIGO de la Estadia deseada --> ";
						int codigo;
						cin>>codigo;
						borrarAPrepo();
						error = IEstadia->seleccionarReserva(codigo);
						if(!error){
							IEstadia->finalizarEstadia();
						}
						else
							cout<<endl<<"La estadia que ingreso no existe en el Hostal seleccionado." << endl<<endl;
					}
					else
						cout<<endl<<"El huesped que ingreso no tienen ninguna Estadia activa en el Hostal seleccionado." << endl<<endl;
				}
				else
					cout<<endl<<"El usuario que ingreso no es correcto, intentelo nuevamente." << endl<<endl;
			}
			else
				cout<<endl<<"El Hostal que ingreso no es correcto, intentelo nuevamente." << endl<<endl;

			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'I': {
			cout<<endl;
			cout << "---------- CALIFICAR ESTADÍA---------" << endl << endl;
			set<DataHostal*> listaHostales = IEstadia->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			string nombre = solicitarString("Ingrese el NOMBRE del Hostal al que pertenece la Estadia: ");
			bool error = IEstadia->seleccionarHostal(nombre);
			if(!error){
				cout<<endl;
				string email = solicitarString("Ingrese el EMAIL del Huesped que quiere calificar la Estadia: ");
				error = IEstadia->seleccionarHuesped(email);
				if(!error){
					set<DataEstadia*> listaEstadias = IEstadia->listarEstadiasFinalizadasHuesped();
					set<DataEstadia*>::iterator i;
					cout<<endl;
					for(i = listaEstadias.begin(); i != listaEstadias.end(); i++)
						cout<< (*i)<<endl;
					if(!listaEstadias.empty()){
						cout<< "Ingrese el CODIGO de la Estadia deseada --> ";
						int codigo;
						cin>>codigo;
						borrarAPrepo();
						error = IEstadia->seleccionarReserva(codigo);
						if(!error){
							cout<< "Puntue la Estadia del 1 al 5: ";
							int puntaje;
							cin>>puntaje;
							borrarAPrepo();
							string texto = solicitarString("Ingrese un comentario sobre la Estadia: ");
							IEstadia->calificarEstadia(texto, puntaje);
						}
						else
							cout<<endl<<"La estadia que ingreso no existe en el Hostal seleccionado." << endl<<endl;
					}
					else
						cout<<endl<<"El huesped que ingreso no tienen ninguna Estadia finalizada en el Hostal seleccionado." << endl<<endl;
				}
				else
					cout<<endl<<"El usuario que ingreso no es correcto, intentelo nuevamente." << endl<<endl;
			}
			else
				cout<<endl<<"El Hostal que ingreso no es correcto, intentelo nuevamente." << endl<<endl;
				
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'J': {
			cout<<endl;
			cout << "---------- COMENTAR CALIFICACIÓN ---------" << endl << endl;
			
			string email = solicitarString("Ingrese el EMAIL del Empleado que quiere comentar una Calificacion: ");
			bool error = IEstadia->seleccionarEmpleado(email);
			if(!error){
				set<DataCalificacion*> listaCalificaciones = IEstadia->listarCalificacionesSinResponder();
				set<DataCalificacion*>::iterator it;
				cout<<endl;
				for(it = listaCalificaciones.begin(); it != listaCalificaciones.end(); it++)
					cout<< (*it) << endl;
				if(!listaCalificaciones.empty()){
					cout<< "Ingrese el CODIGO de la Calificacion deseada --> ";
					int codigo;
					cin>>codigo;
					borrarAPrepo();
					error = IEstadia->seleccionarReserva(codigo);
					if(!error){
						string email = solicitarString("Ingrese el EMAIL del Huesped al que pertenece la Calificacion: ");
						error = IEstadia->seleccionarHuesped(email);
						if(!error){
							string respuesta = solicitarString("Ingrese la respuesta: ");
							IEstadia->responderCalificacion(respuesta);
						}
						else
							cout<<endl<<"El usuario que ingreso no es correcto." << endl<<endl;
					}
					else
						cout<<endl<<"La Calificacion que ingreso no existe en el Hostal seleccionado." << endl<<endl;
				}
				else
					cout<<endl<<"El Hostal del empleado seleccionado no tiene ninguna calificacion sin responder." << endl<<endl;
			}
			else
				cout<<endl<<"El usuario que ingreso no es correcto, intentelo nuevamente." << endl<<endl;
				
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'K': {
			cout << endl;
			cout << "---------- CONSULTA DE USUARIO ---------" << endl << endl;
			set<DataUsuario*> listaUsuarios = IUsuario->listarUsuarios();
			set<DataUsuario*>::iterator it;
			for(it = listaUsuarios.begin(); it != listaUsuarios.end(); it++)
				cout << (*it)->getNombre()<< " - " <<(*it)->getEmail() << endl << endl;
			bool error = true;
			while(error && !listaUsuarios.empty()){
				string email = solicitarString("Ingrese el EMAIL del usuario a seleccionar: ");
				error = IUsuario->seleccionarUsuario(email);
				if(!error){
					for(it = listaUsuarios.begin(); it != listaUsuarios.end(); it++){
						if((*it)->getEmail() == email)
							cout<< (*it);
					}
				}
				else
					cout<<endl<<"El usuario que ingreso no es correcto, intentelo nuevamente." << endl;
			}
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'L': {
			cout << endl;
			cout << "---------- CONSULTA DE HOSTAL ---------" << endl << endl;
			set<DataHostal*> listaHostales = IHostal->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			bool error = true;
			while(error && !listaHostales.empty()){
				string nombre = solicitarString("Ingrese el NOMBRE del hostal a seleccionar: ");
				error = IHostal->seleccionarHostal(nombre);
				if(!error){
					cout<<endl<<"--INFORMACION--"<<endl<<endl;
					for(it = listaHostales.begin(); it != listaHostales.end(); it++){
						if((*it)->getNombre() == nombre)
							cout<<(*it)<<endl;
					}
					
					cout<<"--CALIFICACIONES--"<<endl<<endl;
					set<DataCalificacion*> listaCalificaciones = IHostal->listarCalificaciones();
					set<DataCalificacion*>::iterator k;
					for(k = listaCalificaciones.begin(); k != listaCalificaciones.end(); k++)
						cout<<(*k)<<endl;
						
					cout<<"--HABITACIONES--"<<endl<<endl;
					set<DataHabitacion*> listaHabitaciones = IHostal->listarHabitaciones();
					set<DataHabitacion*>::iterator i;
					for(i = listaHabitaciones.begin(); i!= listaHabitaciones.end(); i++)
						cout<<(*i)<<endl;
						
					cout<<"--RESERVAS--"<<endl<<endl;
					error = IReserva->seleccionarHostal(nombre);
					set<DataReserva*> listaReservas = IReserva->listarReservas();
					set<DataReserva*>::iterator j;
					for(j = listaReservas.begin(); j != listaReservas.end(); j++)
						cout<<(*j)<<endl;
				}
					
				else
					cout<<endl<< "El Hostal que ingreso no es correcto, intentelo nuevamente." << endl;
					
			}

			//DataHostal* infoHostal = IHostal->getDataHostal();
			//cout << endl << "El Hostal:" << infoHostal->getNombre() << endl << "se ubica en:" << infoHostal->getDireccion() << endl << "y su telefono de contacto es:" << infoHostal->getTelefono() << endl;
			//set<DataReserva*> listaReservas = IHostal->listarReservas();
			//set<Datareserva*>::iterator i;
			//for (i = listaReservas.begin(); i != listReservas.end(); ++i)
				//cout << (*i)->getCodigo() << " - " << (*i)->geHabitacion() << " - " << (*i)->getHuesped() << endl;
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'M': {
			cout << endl;
			cout << "---------- CONSULTA DE RESERVA ---------" << endl << endl;
			set<DataHostal*> listaHostales = IReserva->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			string nombre = solicitarString("Ingrese el NOMBRE del Hostal del cual quiere ver las Reservas: ");
			bool error = IReserva->seleccionarHostal(nombre);
			if(!error){
				set<DataReserva*> listaReservas = IReserva->listarReservas();
				set<DataReserva*>::iterator i;
				cout<<endl;
				for(i = listaReservas.begin(); i != listaReservas.end(); i++)
					cout << *i << endl;
			}
			else
				cout<<endl<< "El Hostal que ingreso no es correcto, intentelo nuevamente."<<endl<<endl;
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'N': {
			cout<<endl;
			cout << "---------- CONSULTA DE ESTADÍA ---------" << endl << endl;
			set<DataHostal*> listaHostales = IEstadia->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			string nombre = solicitarString("Ingrese el NOMBRE del Hostal del que quiere consultar las Estadias: ");
			bool error = IEstadia->seleccionarHostal(nombre);
			if(!error){
				set<DataEstadia*> listaEstadias = IEstadia->listarEstadias();
				set<DataEstadia*>::iterator i;
				cout<<endl;
				for(i = listaEstadias.begin(); i != listaEstadias.end(); i++)
					cout<< (*i) <<endl;
				if(!listaEstadias.empty()){
					cout<< "Ingrese el CODIGO de la Estadia deseada --> ";
					int codigo;
					cin>>codigo;
					borrarAPrepo();
					error = IEstadia->seleccionarReserva(codigo);
					if(!error){
						string email = solicitarString("Ingrese el EMAIL del Huesped al que pertenece la Estadia: ");
						error = IEstadia->seleccionarHuesped(email);
						if(!error){
							cout<<endl;
							bool verCalifyResp = solicitarBool("Desea ver Calificacion y Respuesta de la Estadia seleccionada?" );
							if(verCalifyResp){
								cout<<endl;
								DataCalificacion* calif = IEstadia->verCalificacion();
								if(calif != NULL){
									string resp = IEstadia->verRespuesta();
									cout<<calif<<endl;
									cout<<"Respuesta: "<<resp<<endl<<endl;
								}
								else
									cout<<endl<<"La estadia seleccionada no tiene aun una Calificacion." << endl<< endl;
							}
							bool verReserva = solicitarBool("Desea ver la Reserva asociada a la Estadia? ");
							if(verReserva){
								cout<<endl;
								DataReserva* res = IEstadia->infoReserva();
								cout<<res<<endl;
							}
						}
						else
							cout<<endl<<"El usuario que ingreso no es correcto." << endl<<endl;
					}
					else
						cout<<endl<<"La estadia que ingreso no existe en el Hostal seleccionado." << endl<<endl;
				}
				else
					cout<<endl<< "No hay ninguna Estadia en el Hostal seleccionado."<<endl<<endl;
			}
			else
				cout<<endl<< "El Hostal que ingreso no es correcto, intentelo nuevamente."<<endl<<endl;
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'O': {
			cout << endl;
			cout << "---------- BAJA DE RESERVA ---------" << endl << endl;
			set<DataHostal*> listaHostales = IReserva->listarHostales();
			set<DataHostal*>::iterator it;
			for(it = listaHostales.begin(); it != listaHostales.end(); ++it) 
				cout << (*it)->getNombre() << endl << endl;
			string nombre = solicitarString("Ingrese el NOMBRE del Hostal del cual quiere eliminar una Reservas: ");
			bool error = IReserva->seleccionarHostal(nombre);
			if(!error){
				set<DataReserva*> listaReservas = IReserva->listarReservas();
				set<DataReserva*>::iterator i;
				cout<<endl;
				for(i = listaReservas.begin(); i != listaReservas.end(); i++)
					cout<< (*i)<<endl;
				cout<< "Ingrese el CODIGO de la Reserva que desea eliminar --> ";
				int codigo;
				cin>>codigo;
				borrarAPrepo();
				error = IReserva->seleccionarReserva(codigo);
				if(!error){
					cout<<endl;
					bool confirmar = solicitarBool("Desea confirmar la baja de la Reserva? ");
					if(confirmar)
						IReserva->confirmarBaja();
				}
				else
					cout<<endl<< "La reserva que ingreso no esta registrada."<<endl<<endl;
			}
			else
				cout<<endl<< "El Hostal que ingreso no es correcto, intentelo nuevamente."<<endl<<endl;
				
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'P': {
			cout<<endl;
			cout << "---------- SUSCRIBIRSE A NOTIFICACIONES ---------" << endl << endl;
			set<DataUsuario*> listaEmpleados = IEstadia->listarEmpleados();
			set<DataUsuario*>::iterator it;
			for(it = listaEmpleados.begin(); it != listaEmpleados.end(); it++)
				cout<<(*it)->getEmail()<<endl;
			cout<<endl;
			string email = solicitarString("Ingrese EMAIL del Empleado a suscribir: ");
			bool error = IEstadia->seleccionarEmpleado(email);
			if(!error)
				IEstadia->suscribirEmpleado();
			else
				cout<<endl<<"El email que ingreso no es correcto."<<endl;
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'Q': {
			cout<<endl;
			cout << "---------- CONSULTA DE NOTIFICACIONES ---------" << endl << endl;
			set<DataUsuario*> listaEmpleados = IEstadia->listarEmpleados();
			set<DataUsuario*>::iterator it;
			for(it = listaEmpleados.begin(); it != listaEmpleados.end(); it++)
				cout<<(*it)->getEmail()<<endl;
			cout<<endl;
			string email = solicitarString("Ingrese EMAIL de Empleado: ");
			bool error = IEstadia->seleccionarEmpleado(email);
			if(!error){
				cout<<endl;
				set<DataNotificacion*> listaNotificaciones = IEstadia->listarNotificaciones();
				set<DataNotificacion*>::iterator i;
				for(i = listaNotificaciones.begin(); i != listaNotificaciones.end(); i++)
					cout<< (*i)<< endl;
			}
			else
				cout<<endl<<"El email que ingreso no es correcto."<<endl;
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'R': {
			cout << "---------- ELIMINAR SUSCRIPCIÓN ---------" << endl << endl;
			set<DataUsuario*> listaEmpleados = IEstadia->listarEmpleados();
			set<DataUsuario*>::iterator it;
			for(it = listaEmpleados.begin(); it != listaEmpleados.end(); it++)
				cout<<(*it)->getEmail()<<endl;
			cout<<endl;
			string email = solicitarString("Ingrese EMAIL de Empleado a dar de baja.");
			bool error = IEstadia->seleccionarEmpleado(email);
			if(!error)
				IEstadia->eliminarSuscripcion();
			else
				cout<<endl<<"El email que ingreso no es correcto."<<endl;

			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'S': {
			cout<<endl;
			cout << "---------- MODIFICAR FECHA DEL SISTEMA ---------" << endl << endl;
			HoraDelSistema* fechaSys = HoraDelSistema::getInstance();
			DTFecha nueva = solicitarFecha("Ingrese la nueva hora del sistema: ");
			fechaSys->setFechaSistema(nueva);
			
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			imprimirToMenu();
		}
			break;
		case 'T': {
			DataUsuario* dataUsuario = NULL;
			bool error;
			if(!datosCargados){
			//			Empleados
			dataUsuario = new DataEmpleado("Emilia", "emilia@mail.com", "123", DTCargo::Recepcion);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataEmpleado("Leonardo", "leo@mail.com", "123", DTCargo::Recepcion);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataEmpleado("Alina", "alina@mail.com", "123", DTCargo::Administrativo);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataEmpleado("Barliman", "barli@mail.com", "123", DTCargo::Recepcion);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			//			Huespedes
			dataUsuario = new DataHuesped("Sofia", "sofia@mail.com", "123", true);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataHuesped("Frodo", "frodo@mail.com", "123", true);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataHuesped("Sam", "sam@mail.com", "123", false);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataHuesped("Merry", "merry@mail.com", "123", false);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataHuesped("Pippin", "pippin@mail.com", "123", false);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			dataUsuario = new DataHuesped("Seba", "seba@mail.com", "123", true);
			error = IUsuario->ingresarDatosUsuario(dataUsuario);
			IUsuario->confirmarAltaUsuario();
			
			//			Hostels
			DataHostal dataHos = DataHostal("La posada del finger", "Av de la playa 123, Maldonado", 99111111, 0);
			error = IHostal->ingresarDatosHostal(dataHos);
			IHostal->confirmarAltaHostal();
			
			dataHos = DataHostal("Mochileros", "Rambla Costanera 333, Rocha", 42579512, 0);
			error = IHostal->ingresarDatosHostal(dataHos);
			IHostal->confirmarAltaHostal();
			
			dataHos = DataHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", 0, 0);
			error = IHostal->ingresarDatosHostal(dataHos);
			IHostal->confirmarAltaHostal();
			
			dataHos = DataHostal("Altos de Fing", "Av del Toro 1424", 99892992, 0);
			error = IHostal->ingresarDatosHostal(dataHos);
			IHostal->confirmarAltaHostal();
			
			dataHos = DataHostal("Caverna Lujosa", "Amaya 2515", 233233235, 0);
			error = IHostal->ingresarDatosHostal(dataHos);
			IHostal->confirmarAltaHostal();
			
			//			Habitaciones
			error = IHostal->seleccionarHostal("La posada del finger");
			DataHabitacion dataHab = DataHabitacion(1, 2, 40);
			error = IHostal->ingresarDatosHabitacion(dataHab);
			IHostal->confirmarAltaHabitacion();
			
			error = IHostal->seleccionarHostal("La posada del finger");
			dataHab = DataHabitacion(2, 7, 10);
			error = IHostal->ingresarDatosHabitacion(dataHab);
			IHostal->confirmarAltaHabitacion();
			
			error = IHostal->seleccionarHostal("La posada del finger");
			dataHab = DataHabitacion(3, 3, 30);
			error = IHostal->ingresarDatosHabitacion(dataHab);
			IHostal->confirmarAltaHabitacion();
			
			error = IHostal->seleccionarHostal("La posada del finger");
			dataHab = DataHabitacion(4, 12, 5);
			error = IHostal->ingresarDatosHabitacion(dataHab);
			IHostal->confirmarAltaHabitacion();
			
			error = IHostal->seleccionarHostal("Caverna Lujosa");
			dataHab = DataHabitacion(1, 2, 3);
			error = IHostal->ingresarDatosHabitacion(dataHab);
			IHostal->confirmarAltaHabitacion();
			
			error = IHostal->seleccionarHostal("El Pony Pisador");
			dataHab = DataHabitacion(1, 5, 9);
			error = IHostal->ingresarDatosHabitacion(dataHab);
			IHostal->confirmarAltaHabitacion();
			
			//			Asignacion de empleados a hostels
			error = IHostal->seleccionarHostal("La posada del finger");
			error = IHostal->seleccionarEmpleadoAsignar("emilia@mail.com", DTCargo::Recepcion);
			IHostal->confirmarAsignarEmpleadoHostal();
			
			error = IHostal->seleccionarHostal("Mochileros");
			error = IHostal->seleccionarEmpleadoAsignar("leo@mail.com", DTCargo::Recepcion);
			IHostal->confirmarAsignarEmpleadoHostal();
			
			error = IHostal->seleccionarHostal("Mochileros");
			error = IHostal->seleccionarEmpleadoAsignar("alina@mail.com", DTCargo::Administrativo);
			IHostal->confirmarAsignarEmpleadoHostal();
			
			error = IHostal->seleccionarHostal("El Pony Pisador");
			error = IHostal->seleccionarEmpleadoAsignar("barli@mail.com", DTCargo::Recepcion);
			IHostal->confirmarAsignarEmpleadoHostal();
			
			//			Reservas
			error = IReserva->seleccionarHostal("La posada del finger");
			DTFecha checkIn = DTFecha(14, 1, 5, 2022);
			DTFecha checkOut = DTFecha(10, 10, 5, 2022);
			IReserva->ingresarDatosReserva(0, checkIn, checkOut, false);
			error = IReserva->seleccionarHabitacion(1);
			error = IReserva->seleccionarHuesped("sofia@mail.com");
			IReserva->confirmarReserva();
			
			error = IReserva->seleccionarHostal("El Pony Pisador");
			checkIn = DTFecha(20, 4, 1, 1);
			checkOut = DTFecha(2, 5, 1, 1);
			IReserva->ingresarDatosReserva(1, checkIn, checkOut, true);
			error = IReserva->seleccionarHabitacion(1);
			error = IReserva->seleccionarHuesped("frodo@mail.com");
			error = IReserva->incluirHuespedEnReservaGrupal("sam@mail.com");
			error = IReserva->incluirHuespedEnReservaGrupal("merry@mail.com");
			error = IReserva->incluirHuespedEnReservaGrupal("pippin@mail.com");
			IReserva->confirmarReserva();
			
			error = IReserva->seleccionarHostal("La posada del finger");
			checkIn = DTFecha(14, 7, 6, 2022);
			checkOut = DTFecha(11, 30, 6, 2022);
			IReserva->ingresarDatosReserva(2, checkIn, checkOut, false);
			error = IReserva->seleccionarHabitacion(3);
			error = IReserva->seleccionarHuesped("sofia@mail.com");
			IReserva->confirmarReserva();
			
			error = IReserva->seleccionarHostal("Caverna Lujosa");
			checkIn = DTFecha(14, 10, 6, 2022);
			checkOut = DTFecha(11, 30, 6, 2022);
			IReserva->ingresarDatosReserva(3, checkIn, checkOut, false);
			error = IReserva->seleccionarHabitacion(1);
			error = IReserva->seleccionarHuesped("seba@mail.com");
			IReserva->confirmarReserva();
			
			codigoReserva = 4;
			
			//			Estadias
			HoraDelSistema* fechaSys = HoraDelSistema::getInstance();
			
			DTFecha fecha = DTFecha(18, 1, 5, 2022);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("La posada del finger");
			error = IEstadia->seleccionarHuesped("sofia@mail.com");
			error = IEstadia->seleccionarReserva(0);
			IEstadia->registrarEstadia();
			
			fecha = DTFecha(21, 4, 1, 1);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("El Pony Pisador");
			error = IEstadia->seleccionarHuesped("frodo@mail.com");
			error = IEstadia->seleccionarReserva(1);
			IEstadia->registrarEstadia();
			
			fecha = DTFecha(21, 4, 1, 1);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("El Pony Pisador");
			error = IEstadia->seleccionarHuesped("sam@mail.com");
			error = IEstadia->seleccionarReserva(1);
			IEstadia->registrarEstadia();
			
			fecha = DTFecha(21, 4, 1, 1);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("El Pony Pisador");
			error = IEstadia->seleccionarHuesped("merry@mail.com");
			error = IEstadia->seleccionarReserva(1);
			IEstadia->registrarEstadia();
			
			fecha = DTFecha(21, 4, 1, 1);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("El Pony Pisador");
			error = IEstadia->seleccionarHuesped("pippin@mail.com");
			error = IEstadia->seleccionarReserva(1);
			IEstadia->registrarEstadia();
			
			fecha = DTFecha(18, 7, 6, 2022);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("Caverna Lujosa");
			error = IEstadia->seleccionarHuesped("seba@mail.com");
			error = IEstadia->seleccionarReserva(3);
			IEstadia->registrarEstadia();
			
			//			Finalizacion de estadias
			fecha = DTFecha(9, 10, 5, 2022);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("La posada del finger");
			error = IEstadia->seleccionarHuesped("sofia@mail.com");
			error = IEstadia->seleccionarReserva(0);
			IEstadia->finalizarEstadia();
			
			fecha = DTFecha(2, 5, 1, 1);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("El Pony Pisador");
			error = IEstadia->seleccionarHuesped("frodo@mail.com");
			error = IEstadia->seleccionarReserva(1);
			IEstadia->finalizarEstadia();
			
			fecha = DTFecha(22, 15, 6, 2022);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("Caverna Lujosa");
			error = IEstadia->seleccionarHuesped("seba@mail.com");
			error = IEstadia->seleccionarReserva(3);
			IEstadia->finalizarEstadia();
			
			//			Calificar estadia
			fecha = DTFecha(18, 11, 5, 2022);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("La posada del finger");
			error = IEstadia->seleccionarHuesped("sofia@mail.com");
			error = IEstadia->seleccionarReserva(0);
			IEstadia->calificarEstadia("Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacia tremendo ruido) y 2 pesas, la piscina parecia el lago del Parque Rodo y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.", 3);
			
			fecha = DTFecha(3, 5, 1, 1);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("El Pony Pisador");
			error = IEstadia->seleccionarHuesped("frodo@mail.com");
			error = IEstadia->seleccionarReserva(1);
			IEstadia->calificarEstadia("Se pone peligroso de noche, no recomiendo. Ademas no hay caja fuerte para guardar anillos.", 2);
			
			fecha = DTFecha(23, 15, 6, 2022);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarHostal("Caverna Lujosa");
			error = IEstadia->seleccionarHuesped("seba@mail.com");
			error = IEstadia->seleccionarReserva(3);
			IEstadia->calificarEstadia("Habia pulgas en la habitacion. Que lugar mas mamarracho!!", 1);
			
			//			Comentar calificacion
			fecha = DTFecha(15, 6, 1, 1);
			fechaSys->setFechaSistema(fecha);
			error = IEstadia->seleccionarEmpleado("barli@mail.com");
			set<DataCalificacion*> listaCalificaciones = IEstadia->listarCalificacionesSinResponder();
			error = IEstadia->seleccionarReserva(1);
			error = IEstadia->seleccionarHuesped("frodo@mail.com");
			IEstadia->responderCalificacion("Desaparecio y se fue sin pagar.");
			
			datosCargados = true;
			cout<<endl<<"Datos cargados correctamente"<<endl;
			cout<<endl<<"Presione Enter para volver al Menu Principal.";
			string enter;
			getline(cin, enter);
			} // end if
			else
				cout<<endl<<"Los datos han sido cargados previamente."<<endl<<endl;
		} // en case
			break;
		case 'U':
				salir = true;
			break;
		default:
				cout << "Comando no Valido." << endl;
			break;
		} // end case
	} // end while

	cout << endl << "El programa ha terminado correctamente." << endl;

	return 0;
}
