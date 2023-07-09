#ifndef DATAHOSTAL
#define DATAHOSTAL

#include <string>
using std::string;

class DataHostal {
    private:
            string nombre, direccion;
            int telefono;
            float promedioCalif;
    public:
        DataHostal(string, string, int, float);
        string getNombre();
        string getNombre() const;
        string getDireccion();
        int getTelefono();
        float getPromedioCalif();
        float getPromedioCalif() const;
        DataHostal& operator=(DataHostal const&);
        bool operator<(DataHostal const&) const;
};

#endif
