#ifndef DATAUSUARIO
#define DATAUSUARIO

#include <string>
using std::string;

class DataUsuario{
	private:
		string nombre, email, pass;
	public:
		DataUsuario(string, string, string);
		string getNombre();
		string getEmail();
		string getPass();
		virtual int secreto() = 0;
};

#endif
