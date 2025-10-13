#include "ClienteNormal.h"

ClienteNormal::ClienteNormal(string nombre, string id, string paisResidencia)
    : Cliente(nombre, id, paisResidencia) {
}

string ClienteNormal::toString() {
    stringstream ss;
    ss << "==Cliente Normal==\n";
    ss << "Nombre: " << getNombre() << "\n";
    ss << "ID: " << getId() << "\n";
    ss << "País Residencia: " << getPaisResidencia() << "\n";
    return ss.str();
}

string ClienteNormal::getTipo(){
    return "Normal";
}

