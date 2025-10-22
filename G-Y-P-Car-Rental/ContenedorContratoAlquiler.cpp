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
void ContenedorContratoAlquiler::finalizarContrato(string idContrato)
{
	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getContratoAlquiler()->getIdContrato() == idContrato) {
			string* estado = actual->getContratoAlquiler()->getEstadoContrato();
			estado[0] = "Finalizado sin cargos adicionales";
			return;
		}
		actual = actual->getSiguiente();
	}
}
void ContenedorContratoAlquiler::mostrarContratosPorCliente(string idCliente)
{
	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getContratoAlquiler()->getIdCliente() == idCliente) {
			cout << actual->getContratoAlquiler()->toString() << "\n";
		}
		actual = actual->getSiguiente();
	}
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