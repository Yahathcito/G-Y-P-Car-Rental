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
    ss << "==Cliente Jur�dico==\n";
    ss << "Nombre: " << getNombre() << "\n";
    ss << "ID: " << getId() << "\n";
    ss << "Pa�s Residencia: " << getPaisResidencia() << "\n";
    ss << "Actividad Econ�mica: " << actividadEconomica << "\n";
    return ss.str();
}

