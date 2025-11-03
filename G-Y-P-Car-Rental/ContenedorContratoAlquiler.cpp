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

ContratoAlquiler* ContenedorContratoAlquiler::obtenerContratoAlquiler(string idContrato)
{
	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getContratoAlquiler()->getIdContrato() == idContrato) {
			return actual->getContratoAlquiler();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
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
			actual->getContratoAlquiler()->setEstadoContrato("Finalizado");
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
string ContenedorContratoAlquiler::mostrarContratosPorCarro(string placa){
	bool bandera = false; 
	NodoContratoAlquiler* aux = cabeza; 
	stringstream s; 
	while (aux != nullptr) {
		if (aux->getContratoAlquiler()->getPlacaVehiculo()==placa) {
			s << aux->getContratoAlquiler()->toString(); 
			bandera = true; 
		}
		aux = aux->getSiguiente(); 
	}
	if (!bandera) return "Este carro no posee contratos.\n";
	else return s.str(); 
}
void ContenedorContratoAlquiler::contarContratosPorCliente(string idCliente, int& contador)
{
	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getContratoAlquiler()->getIdCliente() == idCliente) {
			contador++;
		}
		actual = actual->getSiguiente();
	}

}
NodoContratoAlquiler* ContenedorContratoAlquiler::getCabeza()
{
	return cabeza;
}
void ContenedorContratoAlquiler::reporteContratosPorSucursal()
{
	NodoContratoAlquiler* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->getContratoAlquiler()->toString() << "\n";
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