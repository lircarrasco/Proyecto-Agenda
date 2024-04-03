#include "ContactoFamiliar.h"
#include <iostream>

ContactoFamiliar::ContactoFamiliar(std::string nombre, std::string telefono, std::string correo, std::string relacion)
    : Contacto(nombre, telefono, correo), relacion(relacion) {}

std::string ContactoFamiliar::getRelacion() const {
    return relacion;
}

void ContactoFamiliar::setRelacion(std::string nuevaRelacion) {
    relacion = nuevaRelacion;
}

void ContactoFamiliar::mostrarContacto() const {
    Contacto::mostrarContacto();
    std::cout << "Relación: " << relacion << std::endl;
}
