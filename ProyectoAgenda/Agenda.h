#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include "Contacto.h"
#include "ContactoFamiliar.h"
using namespace std;

class Agenda {

private:
    vector<Contacto*> contactos;

public:
    Agenda();


    ~Agenda();

    void agregarContacto(Contacto* nuevoContacto);
    void buscarContactoPorNombre(const string& nombre) const;
    void buscarContactoPorNumero(const string& telefono) const;
    void mostrarContactos() const;
    void eliminarContactoPorNombre(const string& nombre);
    void eliminarContactoPorTelefono(const string& telefono);
};

#endif // AGENDA_H
