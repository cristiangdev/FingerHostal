#include "IControladorUsuario.h"
#include "ControladorUsuario.h"
#include "IControladorHostal.h"
#include "ControladorHostal.h"
#include "ControladorReserva.h"
#include "IControladorReserva.h"
#include "ControladorEstadia.h"
#include "IControladorEstadia.h"

#ifndef FABRICA
#define FABRICA

class Fabrica {
	private:
		static Fabrica* instancia;		//Singleton
		Fabrica();						//Singleton
		
	public:
		static Fabrica* getInstance();	//Singleton
        IControladorUsuario* getIControladorUsuario();
		IControladorHostal* getIControladorHostal();
		IControladorReserva* getIControladorReserva();
		IControladorEstadia* getIControladorEstadia();
};


#endif
