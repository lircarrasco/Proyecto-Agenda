#include "ContactoEmpresa.h"
#include <iostream>
using namespace std;

ContactoEmpresa::ContactoEmpresa(string nombre,string telefono, string correo, string nombreEmpresa)
    : Contacto(nombre, telefono, correo), nombreEmpresa(nombreEmpresa) {}

string ContactoEmpresa::getNombreEmpresa() const {
    return nombreEmpresa;
}

void ContactoEmpresa::setNombreEmpresa(string nuevoNombre) {
    nombreEmpresa = nuevoNombre;
}

void ContactoEmpresa::mostrarContacto() const {
    Contacto::mostrarContacto();
    std::cout << "Nombre Empresa: " << nombreEmpresa << std::endl;
}
