#include "Colaborador.h"

Colaborador::Colaborador(string nombre, string id, string fechaIngreso) {
	this->nombre = nombre;
	this->id = id;
	this->fechaIngreso = fechaIngreso;
}

string Colaborador::getNombre() {
	return nombre;
}
string Colaborador::getId() {
	return id;
}
string Colaborador::getFechaIngreso() {
	return fechaIngreso;
}
string Colaborador::toString() {
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << id << endl;
	s << "Fecha Ingreso: " << fechaIngreso << endl;
	return s.str();
}
