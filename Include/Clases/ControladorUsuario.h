#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include <set>

#include "ColUsuarios.h"
#include "Usuario.h"
#include "Huesped.h"
#include "Empleado.h"
#include "IControladorUsuario.h"

class ControladorUsuario : public IControladorUsuario{
	private:
		static ControladorUsuario* instancia; 		//Singleton
		ControladorUsuario(); 						//Singleton
		DataUsuario* dataUsuarioRegistrar;
		string usuarioGuardado;
	public:
		static ControladorUsuario* getInstance(); 	//Singleton
		set<DataUsuario*> listarUsuarios();
		int ingresarDatosUsuario(DataUsuario*);
		void cancelarAltaUsuario();
		void confirmarAltaUsuario();
		int seleccionarUsuario(string);
};

#endif
