#include "Contacto.h"
#include <iostream>

Contacto::Contacto(const std::string& nombre, const std::string& telefono, const std::string& correo)
    : nombre(nombre), telefono(telefono), correo(correo) {}

std::string Contacto::getNombre() const {
    return nombre;
}

void Contacto::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

std::string Contacto::getTelefono() const {
    return telefono;
}

void Contacto::setTelefono(const std::string& telefono) {
    this->telefono = telefono;
}

std::string Contacto::getCorreo() const {
    return correo;
}

void Contacto::setCorreo(const std::string& correo) {
    this->correo = correo;
}

void Contacto::mostrarContacto() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Teléfono: " << telefono << std::endl;
    std::cout << "Correo electrónico: " << correo << std::endl;
}

