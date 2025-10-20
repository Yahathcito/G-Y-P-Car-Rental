#include "EspacioEstacionamiento.h"

EspacioEstacionamiento::EspacioEstacionamiento(string idEspacio) {
	this->idEspacio = idEspacio;
	this->disponible = true; 
	this->carroEstacionado = nullptr;
}
EspacioEstacionamiento::~EspacioEstacionamiento(){
	carroEstacionado = nullptr;
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

bool EspacioEstacionamiento::estacionarCarro(Carro* carro){
	if (disponible) {
		carroEstacionado = carro;
		disponible = false;
		return true;
	}
	return false;
}


Carro* EspacioEstacionamiento::getCarro()
{
	return carroEstacionado;
}

void EspacioEstacionamiento::setCarro(Carro* c){
	this->carroEstacionado = c; 
}

string EspacioEstacionamiento::toString() {
	stringstream s;
	s << "ID del Espacio de Estacionamiento: " << idEspacio << endl;
	s << "Disponible: " << (disponible ? "Sí" : "No") << endl;
	return s.str();
}
