#include "Plantel.h"

Plantel::Plantel(string id, int capacidadMaxima, string tipoVehiculo[4]) {
	this->id = id;
	this->capacidadMaxima = capacidadMaxima;
	for (int i = 0; i < 4; i++) {
		this->tipoVehiculo[i] = tipoVehiculo[i];
	}
}
string Plantel::getId() {
	return id;
}
int Plantel::getCapacidadMaxima() {
	return capacidadMaxima;
}
string* Plantel::getTipoVehiculo() {
	return tipoVehiculo;
}
string Plantel::toString() {
	stringstream s;
	s << "ID del Plantel: " << id << endl;
	s << "Capacidad Máxima: " << capacidadMaxima << endl;
	s << "Tipos de Vehículos Aceptados: ";
	for (int i = 0; i < 4; i++) {
		if (tipoVehiculo[i] != "") {
			s << tipoVehiculo[i];
			if (i < 3 && tipoVehiculo[i + 1] != "") {
				s << ", ";
			}
		}
	}
	s << endl;
	return s.str();
}
