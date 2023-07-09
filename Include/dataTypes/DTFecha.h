#ifndef DTFECHA
#define DTFECHA

#include <string>
using std::string;

class DTFecha {
    private:
            int hora, dia, mes, anio;
    public:
            DTFecha(int, int ,int ,int);
            int getHora();
            int getDia();
            int getMes();
            int getAnio();
            bool verifica_Fecha(int, int, int);
            bool operator==(DTFecha const&);
		    DTFecha& operator=(DTFecha const&);
		    int operator-(DTFecha const&);
		    bool operator<=(DTFecha const&);
};

#endif

