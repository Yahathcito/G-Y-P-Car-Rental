#include "ClienteJuridico.h"

ClienteJuridico::ClienteJuridico(string nombre, string id, string paisResidencia, string actividadEconomica)
    : Cliente(nombre, id, paisResidencia) {
    this->actividadEconomica = actividadEconomica;
}

void ClienteJuridico::setActividadEconomica(string actividadEconomica) {
    this->actividadEconomica = actividadEconomica;
}

string ClienteJuridico::getActividadEconomica() {
    return actividadEconomica;
}

string ClienteJuridico::getTipo(){
    return "Juridico";
}

string ClienteJuridico::toString() {
    stringstream ss;
    ss << "==Cliente Jurídico==\n";
    ss << "Nombre: " << getNombre() << "\n";
    ss << "ID: " << getId() << "\n";
    ss << "País Residencia: " << getPaisResidencia() << "\n";
    ss << "Actividad Económica: " << actividadEconomica << "\n";
    return ss.str();
}

