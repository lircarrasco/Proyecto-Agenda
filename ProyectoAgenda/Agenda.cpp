
#include <iostream>
#include <vector>
#include "Contacto.h"           // Incluimos la clase Contacto
#include "ContactoFamiliar.h"  // Incluimos la clase ContactoFamiliar
#include <algorithm>
#include "Agenda.h"

using namespace std;


    Agenda::Agenda() {
}

    Agenda::~Agenda() {
    for (auto& contacto : contactos) {
        delete contacto;
    }
}

    // M�todo para agregar un nuevo contacto a la agenda
        void Agenda::agregarContacto(Contacto* nuevoContacto) {
            bool exist = false;
            for(const auto& contacto : contactos){
                if(*contacto== *nuevoContacto){
                exist = true;
           }
                   }
                   if(!exist){
                        contactos.push_back(nuevoContacto);
                   }else{
                        std::cout << "El n�mero ya existe en la agenda" << std::endl;

                   }
        }

    // M�todo para mostrar todos los contactos en la agenda
         void Agenda::mostrarContactos() const {
            if (contactos.empty()) {
                std::cout << "La agenda est� vac�a." << std::endl;
            } else {
                std::cout << "Contactos en la agenda:" << std::endl;
                for (const auto& contacto : contactos) {
                    contacto->mostrarContacto();
                    std::cout << std::endl;
                }
            }
        }
    // M�todo para buscar un contacto por nombre
         void Agenda::buscarContactoPorNombre(const std::string& nombre) const {
            bool encontrado = false;
            for (const auto& contacto : contactos) {
                if (contacto->getNombre() == nombre) {
                    encontrado = true;
                    std::cout << "Contacto encontrado:" << std::endl;
                    contacto->mostrarContacto();
                    return;
                }
            }
            std::cout << "No se encontr� ning�n contacto con el nombre especificado." << std::endl;
        }

    // M�todo para buscar un contacto por n�mero de tel�fono
        void Agenda::buscarContactoPorNumero(const std::string& telefono) const {
            bool encontrado = false;
            for (const auto& contacto : contactos) {
                if (contacto->getTelefono() == telefono) {
                    encontrado = true;
                    std::cout << "Contacto encontrado:" << std::endl;
                    contacto->mostrarContacto();
                    return;
                }
            }
            std::cout << "No se encontr� ning�n contacto con el n�mero de tel�fono especificado." << std::endl;
        }
        // M�todo para eliminar un contacto por el n�mero de tel�fono
       void Agenda::eliminarContactoPorTelefono(const std::string& telefono) {
            auto it = std::remove_if(contactos.begin(), contactos.end(),
                                      [telefono](const Contacto* contacto) {
                                          return contacto->getTelefono() == telefono;
                                      });

            if (it != contactos.end()) {
                delete *it;  // Libera la memoria del contacto eliminado
                contactos.erase(it);  // Elimina el puntero del vector
                std::cout << "---Contacto con n�mero de tel�fono " << telefono << " eliminado---" << std::endl;
            } else {
                std::cout << "No se encontr� ning�n contacto con el n�mero de tel�fono " << telefono << "." << std::endl;
            }
        }
        void Agenda::eliminarContactoPorNombre(const std::string& nombre) {
            auto it = std::remove_if(contactos.begin(), contactos.end(),
                                      [&nombre](const Contacto* contacto) {
                                         return contacto->getNombre() == nombre;
                                      });

            if (it != contactos.end()) {
                delete *it; // Libera la memoria del contacto eliminado
                contactos.erase(it, contactos.end()); // Elimina los punteros del vector
                std::cout << "---Contacto con nombre " << nombre << " eliminado---" << std::endl;
            } else {
                std::cout << "No se encontr� ning�n contacto con el nombre " << nombre << "." << std::endl;
            }
}


