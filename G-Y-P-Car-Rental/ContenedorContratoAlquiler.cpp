#include "ContenedorContratoAlquiler.h"

ContenedorContratoAlquiler::ContenedorContratoAlquiler()
{
	this->cabeza = nullptr;
}
ContenedorContratoAlquiler::~ContenedorContratoAlquiler()
{
	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		NodoContratoAlquiler* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
}
bool ContenedorContratoAlquiler::estaVacio()
{
	return cabeza == nullptr;
}
