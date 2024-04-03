#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>
using namespace std;

class Contacto {
private:
    string nombre;
    string telefono;
    string correo;

public:
    Contacto(const string& nombre, const string& telefono, const string& correo);

    string getNombre() const;
    void setNombre(const string& nombre);
    string getTelefono() const;
    void setTelefono(const std::string& telefono);
    string getCorreo() const;
    void setCorreo(const string& correo);
    virtual void mostrarContacto() const; // Marcar como virtual

// sobrecarga de operador
    bool operator==(const Contacto& other) const {
        return this->telefono == other.telefono;
    }


};

#endif // CONTACTO_H
