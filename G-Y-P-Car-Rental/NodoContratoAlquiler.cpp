#include "NodoContratoAlquiler.h"

NodoContratoAlquiler::NodoContratoAlquiler(ContratoAlquiler* contratoAlquiler, NodoContratoAlquiler* siguiente) {
	this->contratoAlquiler = contratoAlquiler;
	this->siguiente = siguiente;
}
NodoContratoAlquiler::~NodoContratoAlquiler() {
	delete contratoAlquiler;
}
ContratoAlquiler* NodoContratoAlquiler::getContratoAlquiler() {
	return contratoAlquiler;
}
NodoContratoAlquiler* NodoContratoAlquiler::getSiguiente() {
	return siguiente;
}
NodoContratoAlquiler* NodoContratoAlquiler::setSiguiente(NodoContratoAlquiler* siguiente) {
	return this->siguiente = siguiente;
}

