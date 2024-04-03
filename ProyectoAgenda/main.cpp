#include <iostream>
#include <string>
#include "Agenda.h"
#include "Contacto.h"
#include "ContactoFamiliar.h"
#include "ContactoEmpresa.h"
using namespace std;

int main() {
    Agenda agenda;
    int opcion;

    do {
        cout << "=============================" << endl;
        cout << "=============================" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Eliminar contacto" << endl;
        cout << "3. Buscar contacto" << endl;
        cout << "4. Mostrar todos los contactos" << endl;
        cout << "5. Salir" << endl;
        cout << "=============================" << endl;
        cout << "=============================" << endl;
        cout << "Ingrese la opci�n deseada: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer del teclado

        switch (opcion) {
            case 1: {
                string nombre, telefono, correo, relacion, nombreEmpresa;
                int tipoContacto;

                cout << "Ingrese el nombre del contacto: ";
                getline(cin, nombre);
                cout << "Ingrese el n�mero de tel�fono del contacto: ";
                getline(cin, telefono);
                cout << "Ingrese el correo electr�nico del contacto: ";
                getline(cin, correo);

                cout << "Seleccione el tipo de contacto:" << endl;
                cout << "1. Normal" << endl;
                cout << "2. Familiar" << endl;
                cout << "3. Empresa" << endl;
                cout << "Ingrese la opci�n deseada: ";
                cin >> tipoContacto;
                cin.ignore(); // Limpiar el buffer del teclado

                if (tipoContacto == 1) {
                    // Agregar contacto normal
                    Contacto* nuevoContacto = new Contacto(nombre, telefono, correo);

                    agenda.agregarContacto(nuevoContacto);
                } else if (tipoContacto == 2) {
                    // Agregar contacto familiar
                    int opcionRelacion;
                    cout << "Seleccione la relaci�n con el contacto:" << endl;
                    cout << "0. Madre" << endl;
                    cout << "1. Padre" << endl;
                    cout << "2. Hermano/a" << endl;
                    cout << "3. Hijo/a" << endl;
                    cout << "4. Abuelo/a" << endl;
                    cout << "5. Primo/a" << endl;
                    cout << "6. T�o/a" << endl;
                    cout << "7. Suegro/a" << endl;
                    cout << "8. Sobrino/a" << endl;
                    cout << "9. Nieto/a" << endl;
                    cout << "10.Pareja/a" << endl;

                    // Otras relaciones...
                    cout << "Ingrese la opci�n deseada: ";
                    cin >> opcionRelacion;
                    cin.ignore(); // Limpiar el buffer del teclado

                    switch (opcionRelacion) {
                        case 0: relacion = "Madre"; break;
                        case 1: relacion = "Padre"; break;
                        case 2: relacion = "Hermano/a"; break;
                        case 3: relacion = "Hijo/a"; break;
                        case 4: relacion = "Abuelo/a"; break;
                        case 5: relacion = "Primo/a"; break;
                        case 6: relacion = "T�o/a"; break;
                        case 7: relacion = "Suegro/a"; break;
                        case 8: relacion = "Sobrino/a"; break;
                        case 9: relacion = "Nieto/a"; break;
                        case 10:relacion = "Pareja/a"; break;
                        // Otras relaciones...
                        default: relacion = "Otra";
                    }

                    ContactoFamiliar* nuevoContactoFamiliar = new ContactoFamiliar(nombre, telefono, correo, relacion);
                    agenda.agregarContacto(nuevoContactoFamiliar);
                }
                else if (tipoContacto ==3){

                    cout << "Escriba el nombre de la empresa: ";
                    getline(cin, nombreEmpresa);
                    ContactoEmpresa* nuevoContactoEmpresa = new ContactoEmpresa(nombre, telefono, correo, nombreEmpresa);
                    agenda.agregarContacto(nuevoContactoEmpresa);

                }
                    cout << "---Contacto agregado correctamente---" << endl;

                break;
            }
           case 2: {
                    int opcionEliminar;
                    cout << "Seleccione el m�todo para eliminar el contacto:" << endl;
                    cout << "1. Por nombre" << endl;
                    cout << "2. Por n�mero de tel�fono" << endl;
                    cout << "Ingrese la opci�n deseada: ";
                    cin >> opcionEliminar;
                    cin.ignore(); // Limpiar el buffer del teclado

                    if (opcionEliminar == 1) {
                        string nombreEliminar;
                        cout << "Ingrese el nombre del contacto a eliminar: ";
                        getline(cin, nombreEliminar);

                        // Llamar al m�todo de la clase Agenda para eliminar el contacto por nombre
                        agenda.eliminarContactoPorNombre(nombreEliminar);
                    } else if (opcionEliminar == 2) {
                        string telefonoEliminar;
                        cout << "Ingrese el n�mero de tel�fono del contacto a eliminar: ";
                        getline(cin, telefonoEliminar);

                        // Llamar al m�todo de la clase Agenda para eliminar el contacto por n�mero de tel�fono
                        agenda.eliminarContactoPorTelefono(telefonoEliminar);

                    } else {
                        cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
                    }
                    break;
                }
               case 3: {
                        int opcionBuscar;
                        cout << "Seleccione el m�todo para buscar el contacto:" << endl;
                        cout << "1. Por nombre" << endl;
                        cout << "2. Por n�mero de tel�fono" << endl;
                        cout << "Ingrese la opci�n deseada: ";
                        cin >> opcionBuscar;
                        cin.ignore(); // Limpiar el buffer del teclado

                        if (opcionBuscar == 1) {
                            string nombreBuscar;
                            cout << "Ingrese el nombre del contacto a buscar: ";
                            getline(cin, nombreBuscar);

                            // Buscar por nombre
                            agenda.buscarContactoPorNombre(nombreBuscar);
                        } else if (opcionBuscar == 2) {
                            string telefonoBuscar;
                            cout << "Ingrese el n�mero de tel�fono del contacto a buscar: ";
                            getline(cin, telefonoBuscar);

                            // Buscar por n�mero de tel�fono
                            agenda.buscarContactoPorNumero(telefonoBuscar);

                        } else {
                            cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
                        }
                        break;
                    }


            case 4: {
                agenda.mostrarContactos();
                break;
            }
            case 5: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
            }
        }
    } while (opcion != 5);

    return 0;
}
