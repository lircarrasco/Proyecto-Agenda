#ifndef CONTACTOFAMILIAR_H
#define CONTACTOFAMILIAR_H

#include "Contacto.h"
#include <string>
using namespace std;
class ContactoFamiliar : public Contacto {
private:
    string relacion;

public:
    ContactoFamiliar(string nombre,string telefono,string correo,string relacion);
    string getRelacion() const;
    void setRelacion(string nuevaRelacion);
    void mostrarContacto() const override;
};

#endif // CONTACTOFAMILIAR_H
