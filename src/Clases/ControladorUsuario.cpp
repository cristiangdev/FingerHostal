#include "../../Include/Clases/ControladorUsuario.h"

//----------Singleton
ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){};

ControladorUsuario* ControladorUsuario::getInstance(){
	if(instancia == NULL)
		instancia = new ControladorUsuario();
	return instancia;
}
//----------Singleton

set<DataUsuario*> ControladorUsuario::listarUsuarios(){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	return colUsr->listarUsuarios();
}

int ControladorUsuario::ingresarDatosUsuario(DataUsuario* dataUsuario){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	bool existe = colUsr->existeUsr(dataUsuario->getEmail());
	if(!existe)
		dataUsuarioRegistrar = dataUsuario;
		
	return existe;
}

void ControladorUsuario::cancelarAltaUsuario(){
	delete dataUsuarioRegistrar;
}

void ControladorUsuario::confirmarAltaUsuario(){
	string nombre = dataUsuarioRegistrar->getNombre();
	string email = dataUsuarioRegistrar->getEmail();
	string pass = dataUsuarioRegistrar->getPass();
	Usuario* u;
	if(dynamic_cast<DataHuesped*>(dataUsuarioRegistrar) != NULL)
		u = new Huesped(nombre, email, pass, (dynamic_cast<DataHuesped*>(dataUsuarioRegistrar))->getEsFinger());
	else
		u = new Empleado(nombre, email, pass);
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	colUsr->registrarUsuario(u);
	delete dataUsuarioRegistrar;
}

int ControladorUsuario::seleccionarUsuario(string email){
	ColUsuarios* colUsr = ColUsuarios::getInstance();
	bool existe = colUsr->existeUsr(email);
	if(existe)
		usuarioGuardado = email;

	return !existe;
}

