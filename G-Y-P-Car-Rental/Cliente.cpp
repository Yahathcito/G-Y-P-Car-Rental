#include "Cliente.h"

Cliente::Cliente(string nombre, string id, string paisResidencia) {
    this->nombre = nombre;
    this->id = id;
    this->paisResidencia = paisResidencia;
}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setId(string id) {
    this->id = id;
}

void Cliente::setPaisResidencia(string paisResidencia) {
    this->paisResidencia = paisResidencia;
}

string Cliente::getNombre() {
    return nombre;
}

string Cliente::getId() {
    return id;
}

string Cliente::getPaisResidencia() {
    return paisResidencia;
}

