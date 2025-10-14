#include "ContenedorBitacoras.h"

ContenedorBitacoras::ContenedorBitacoras()
{
	this->cabeza = nullptr;
}

ContenedorBitacoras::~ContenedorBitacoras()
{
	NodoBitacorasEstadoDelCarro* actual = cabeza;
	while (actual != nullptr) {
		NodoBitacorasEstadoDelCarro* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
}


bool ContenedorBitacoras::estaVacio()
{
	return cabeza == nullptr;
}

