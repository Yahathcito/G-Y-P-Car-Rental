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

bool ContenedorContratoAlquiler::buscarContratoAlquiler(string idContrato)
{

	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getContratoAlquiler()->getIdContrato() == idContrato) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}

void ContenedorContratoAlquiler::eliminarContratoAlquiler(string idContrato)
{
	if (estaVacio()) return;
	NodoContratoAlquiler* actual = cabeza;
	NodoContratoAlquiler* anterior = nullptr;
	while (actual != nullptr && actual->getContratoAlquiler()->getIdContrato() != idContrato) {
		anterior = actual;
		actual = actual->getSiguiente();
	}
	if (actual == nullptr) return;
	if (anterior == nullptr) {
		cabeza = actual->getSiguiente();
	}
	else {
		anterior->setSiguiente(actual->getSiguiente());
	}
	delete actual;
}
void ContenedorContratoAlquiler::agregarContratoAlquiler(ContratoAlquiler* nuevoContrato)
{
	NodoContratoAlquiler* nuevoNodo = new NodoContratoAlquiler(nuevoContrato, cabeza);
	cabeza = nuevoNodo;
}
string ContenedorContratoAlquiler::toString()
{
	stringstream s;
	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		s << actual->getContratoAlquiler()->toString() << "\n";
		actual = actual->getSiguiente();
	}
	return s.str();
}