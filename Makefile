
output: main.o Hostal.o Reserva.o ReservaGrupal.o ReservaIndividual.o Huesped.o Habitacion.o Calificacion.o ColHostales.o ColUsuarios.o IControladorEstadia.o IControladorHostal.o IControladorReserva.o IControladorUsuario.o ControladorEstadia.o ControladorHostal.o ControladorReserva.o ControladorUsuario.o Empleado.o Estadia.o Fabrica.o HoraDelSistema.o Respuesta.o Suscriptor.o Usuario.o DataCalificacion.o DataEmpleado.o DataEstadia.o DataHabitacion.o DataHostal.o DataHuesped.o DataNotificacion.o DataReserva.o DataReservaGrupal.o DataReservaIndividual.o DataUsuario.o DTFecha.o
	g++ -std=c++11 main.o Hostal.o Reserva.o ReservaGrupal.o ReservaIndividual.o Huesped.o Habitacion.o Calificacion.o ColHostales.o ColUsuarios.o IControladorEstadia.o IControladorHostal.o IControladorReserva.o IControladorUsuario.o ControladorEstadia.o ControladorHostal.o ControladorReserva.o ControladorUsuario.o Empleado.o Estadia.o Fabrica.o HoraDelSistema.o Respuesta.o Suscriptor.o Usuario.o DataCalificacion.o DataEmpleado.o DataEstadia.o DataHabitacion.o DataHostal.o DataHuesped.o DataNotificacion.o DataReserva.o DataReservaGrupal.o DataReservaIndividual.o DataUsuario.o DTFecha.o -o main
	rm -f *.o
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
Reserva.o: src/Clases/Reserva.cpp Include/Clases/Reserva.h
	g++ -std=c++11 -c src/Clases/Reserva.cpp
	
ReservaGrupal.o: src/Clases/ReservaGrupal.cpp Include/Clases/ReservaGrupal.h
	g++ -std=c++11 -c src/Clases/ReservaGrupal.cpp
	
ReservaIndividual.o: src/Clases/ReservaIndividual.cpp Include/Clases/ReservaIndividual.h
	g++ -std=c++11 -c src/Clases/ReservaIndividual.cpp
	
Huesped.o: src/Clases/Huesped.cpp Include/Clases/Huesped.h
	g++ -std=c++11 -c src/Clases/Huesped.cpp
	
Habitacion.o: src/Clases/Habitacion.cpp Include/Clases/Habitacion.h
	g++ -std=c++11 -c src/Clases/Habitacion.cpp
	
Hostal.o: src/Clases/Hostal.cpp Include/Clases/Hostal.h
	g++ -std=c++11 -c src/Clases/Hostal.cpp
	
Calificacion.o: src/Clases/Calificacion.cpp Include/Clases/Calificacion.h
	g++ -std=c++11 -c src/Clases/Calificacion.cpp

ColHostales.o: src/Clases/ColHostales.cpp Include/Clases/ColHostales.h
	g++ -std=c++11 -c src/Clases/ColHostales.cpp

ColUsuarios.o: src/Clases/ColUsuarios.cpp Include/Clases/ColUsuarios.h
	g++ -std=c++11 -c src/Clases/ColUsuarios.cpp
	
IControladorEstadia.o: src/Clases/IControladorEstadia.cpp Include/Clases/IControladorEstadia.h
	g++ -std=c++11 -c src/Clases/IControladorEstadia.cpp

IControladorHostal.o: src/Clases/IControladorHostal.cpp Include/Clases/IControladorHostal.h
	g++ -std=c++11 -c src/Clases/IControladorHostal.cpp

IControladorReserva.o: src/Clases/IControladorReserva.cpp Include/Clases/IControladorReserva.h
	g++ -std=c++11 -c src/Clases/IControladorReserva.cpp

IControladorUsuario.o: src/Clases/IControladorUsuario.cpp Include/Clases/IControladorUsuario.h
	g++ -std=c++11 -c src/Clases/IControladorUsuario.cpp

ControladorEstadia.o: src/Clases/ControladorEstadia.cpp Include/Clases/ControladorEstadia.h
	g++ -std=c++11 -c src/Clases/ControladorEstadia.cpp

ControladorHostal.o: src/Clases/ControladorHostal.cpp Include/Clases/ControladorHostal.h
	g++ -std=c++11 -c src/Clases/ControladorHostal.cpp

ControladorReserva.o: src/Clases/ControladorReserva.cpp Include/Clases/ControladorReserva.h
	g++ -std=c++11 -c src/Clases/ControladorReserva.cpp

ControladorUsuario.o: src/Clases/ControladorUsuario.cpp Include/Clases/ControladorUsuario.h
	g++ -std=c++11 -c src/Clases/ControladorUsuario.cpp

Empleado.o: src/Clases/Empleado.cpp Include/Clases/Empleado.h
	g++ -std=c++11 -c src/Clases/Empleado.cpp

Estadia.o: src/Clases/Estadia.cpp Include/Clases/Estadia.h
	g++ -std=c++11 -c src/Clases/Estadia.cpp

Fabrica.o: src/Clases/Fabrica.cpp Include/Clases/Fabrica.h
	g++ -std=c++11 -c src/Clases/Fabrica.cpp

HoraDelSistema.o: src/Clases/HoraDelSistema.cpp Include/Clases/HoraDelSistema.h
	g++ -std=c++11 -c src/Clases/HoraDelSistema.cpp

Respuesta.o: src/Clases/Respuesta.cpp Include/Clases/Respuesta.h
	g++ -std=c++11 -c src/Clases/Respuesta.cpp

Suscriptor.o: src/Clases/Suscriptor.cpp Include/Clases/Suscriptor.h
	g++ -std=c++11 -c src/Clases/Suscriptor.cpp

Usuario.o: src/Clases/Usuario.cpp Include/Clases/Usuario.h
	g++ -std=c++11 -c src/Clases/Usuario.cpp
	
DataHuesped.o: src/dataTypes/DataHuesped.cpp Include/dataTypes/DataHuesped.h
	g++ -std=c++11 -c src/dataTypes/DataHuesped.cpp
	
DTFecha.o: src/dataTypes/DTFecha.cpp Include/dataTypes/DTFecha.h
	g++ -std=c++11 -c src/dataTypes/DTFecha.cpp
	
DataHabitacion.o: src/dataTypes/DataHabitacion.cpp Include/dataTypes/DataHabitacion.h
	g++ -std=c++11 -c src/dataTypes/DataHabitacion.cpp
	
DataReserva.o: src/dataTypes/DataReserva.cpp Include/dataTypes/DataReserva.h
	g++ -std=c++11 -c src/dataTypes/DataReserva.cpp
	
DataReservaIndividual.o: src/dataTypes/DataReservaIndividual.cpp Include/dataTypes/DataReservaIndividual.h
	g++ -std=c++11 -c src/dataTypes/DataReservaIndividual.cpp
	
DataReservaGrupal.o: src/dataTypes/DataReservaGrupal.cpp Include/dataTypes/DataReservaGrupal.h
	g++ -std=c++11 -c src/dataTypes/DataReservaGrupal.cpp
	
DataCalificacion.o: src/dataTypes/DataCalificacion.cpp Include/dataTypes/DataCalificacion.h
	g++ -std=c++11 -c src/dataTypes/DataCalificacion.cpp

DataEmpleado.o: src/dataTypes/DataEmpleado.cpp Include/dataTypes/DataEmpleado.h
	g++ -std=c++11 -c src/dataTypes/DataEmpleado.cpp

DataEstadia.o: src/dataTypes/DataEstadia.cpp Include/dataTypes/DataEstadia.h
	g++ -std=c++11 -c src/dataTypes/DataEstadia.cpp

DataHostal.o: src/dataTypes/DataHostal.cpp Include/dataTypes/DataHostal.h
	g++ -std=c++11 -c src/dataTypes/DataHostal.cpp

DataNotificacion.o: src/dataTypes/DataNotificacion.cpp Include/dataTypes/DataNotificacion.h
	g++ -std=c++11 -c src/dataTypes/DataNotificacion.cpp

DataUsuario.o: src/dataTypes/DataUsuario.cpp Include/dataTypes/DataUsuario.h
	g++ -std=c++11 -c src/dataTypes/DataUsuario.cpp
	
clean:
	rm main
