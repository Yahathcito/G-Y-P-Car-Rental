#include "NodoSolicitudAlquiler.h"

NodoSolicitudAlquiler::NodoSolicitudAlquiler(SolicitudAlquiler* solicitudAlquiler, NodoSolicitudAlquiler* siguiente) {
	this->solicitudAlquiler = solicitudAlquiler;
	this->siguiente = siguiente;
}
NodoSolicitudAlquiler::~NodoSolicitudAlquiler() {
	delete solicitudAlquiler;
}
SolicitudAlquiler* NodoSolicitudAlquiler::getSolicitudAlquiler() {
	return solicitudAlquiler;
}
NodoSolicitudAlquiler* NodoSolicitudAlquiler::getSiguiente() {
	return siguiente;
}
NodoSolicitudAlquiler* NodoSolicitudAlquiler::setSiguiente(NodoSolicitudAlquiler* siguiente) {
	return this->siguiente = siguiente;
}
