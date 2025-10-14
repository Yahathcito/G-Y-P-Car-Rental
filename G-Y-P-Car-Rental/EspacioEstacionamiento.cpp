#include "EspacioEstacionamiento.h"

EspacioEstacionamiento::EspacioEstacionamiento(string idEspacio) {
	this->idEspacio = idEspacio;
	this->disponible = true; // Inicialmente, el espacio est� disponible
}
string EspacioEstacionamiento::getIdEspacio() {
	return idEspacio;
}
bool EspacioEstacionamiento::isDisponible() {
	return disponible;
}
void EspacioEstacionamiento::setDisponible(bool disponible) {
	this->disponible = disponible;
}

string EspacioEstacionamiento::toString() {
	stringstream s;
	s << "ID del Espacio de Estacionamiento: " << idEspacio << endl;
	s << "Disponible: " << (disponible ? "S�" : "No") << endl;
	return s.str();
}
