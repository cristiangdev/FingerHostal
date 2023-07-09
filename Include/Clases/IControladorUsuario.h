#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include <set>
#include <string>
using namespace std;

#include "../dataTypes/DataUsuario.h"
#include "../dataTypes/DataHuesped.h"
#include "../dataTypes/DataEmpleado.h"

class IControladorUsuario {
    public:
        virtual int ingresarDatosUsuario(DataUsuario*) = 0;
		virtual void cancelarAltaUsuario() = 0;
		virtual void confirmarAltaUsuario() = 0;
        virtual set<DataUsuario*> listarUsuarios() = 0;  
        virtual int seleccionarUsuario(string email) = 0;    
};




#endif 
