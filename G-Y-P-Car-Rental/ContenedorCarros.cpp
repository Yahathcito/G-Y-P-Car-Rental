
#include "ContenedorCarros.h"

ContenedorCarros::ContenedorCarros()
{
	this->cabeza = nullptr;

}

ContenedorCarros::~ContenedorCarros()
{
	NodoCarro* actual = cabeza;
	while (actual != nullptr) {
		NodoCarro* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
}


