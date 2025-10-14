#include "NodoColaborador.h"

NodoColaborador::NodoColaborador(Colaborador* colaborador, NodoColaborador* siguiente) {
	this->colaborador = colaborador;
	this->siguiente = siguiente;
}
NodoColaborador::~NodoColaborador() {
	delete colaborador;
}
Colaborador* NodoColaborador::getColaborador() {
	return colaborador;
}
NodoColaborador* NodoColaborador::getSiguiente() {
	return siguiente;
}
NodoColaborador* NodoColaborador::setSiguiente(NodoColaborador* siguiente) {
	return this->siguiente = siguiente;
}


