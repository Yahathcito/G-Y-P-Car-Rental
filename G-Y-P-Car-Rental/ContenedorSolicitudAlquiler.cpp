#include "ContenedorSolicitudAlquiler.h"

ContenedorSolicitudAlquiler::ContenedorSolicitudAlquiler()
{
	this->cabeza = nullptr;
}
ContenedorSolicitudAlquiler::~ContenedorSolicitudAlquiler()
{
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		NodoSolicitudAlquiler* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
}
bool ContenedorSolicitudAlquiler::estaVacio()
{
	return cabeza == nullptr;
}
