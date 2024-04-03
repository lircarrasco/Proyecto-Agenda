#ifndef CONTACTOEMPRESA_H
#define CONTACTOEMPRESA_H

#include "Contacto.h"
#include <string>

using namespace std;
class ContactoEmpresa : public Contacto {
private:
    string nombreEmpresa;

public:
    ContactoEmpresa(string nombre,string telefono,string correo,string nombreEmpresa);
    string getNombreEmpresa() const;
    void setNombreEmpresa(string nuevoNombre);

    void mostrarContacto() const override;
};

#endif // CONTACTOEmpresa_H
