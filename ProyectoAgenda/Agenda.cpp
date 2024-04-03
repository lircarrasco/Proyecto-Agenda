
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

    // Método para agregar un nuevo contacto a la agenda
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
                        std::cout << "El número ya existe en la agenda" << std::endl;

                   }
        }

    // Método para mostrar todos los contactos en la agenda
         void Agenda::mostrarContactos() const {
            if (contactos.empty()) {
                std::cout << "La agenda está vacía." << std::endl;
            } else {
                std::cout << "Contactos en la agenda:" << std::endl;
                for (const auto& contacto : contactos) {
                    contacto->mostrarContacto();
                    std::cout << std::endl;
                }
            }
        }
    // Método para buscar un contacto por nombre
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
            std::cout << "No se encontró ningún contacto con el nombre especificado." << std::endl;
        }

    // Método para buscar un contacto por número de teléfono
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
            std::cout << "No se encontró ningún contacto con el número de teléfono especificado." << std::endl;
        }
        // Método para eliminar un contacto por el número de teléfono
       void Agenda::eliminarContactoPorTelefono(const std::string& telefono) {
            auto it = std::remove_if(contactos.begin(), contactos.end(),
                                      [telefono](const Contacto* contacto) {
                                          return contacto->getTelefono() == telefono;
                                      });

            if (it != contactos.end()) {
                delete *it;  // Libera la memoria del contacto eliminado
                contactos.erase(it);  // Elimina el puntero del vector
                std::cout << "---Contacto con número de teléfono " << telefono << " eliminado---" << std::endl;
            } else {
                std::cout << "No se encontró ningún contacto con el número de teléfono " << telefono << "." << std::endl;
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
                std::cout << "No se encontró ningún contacto con el nombre " << nombre << "." << std::endl;
            }
}


