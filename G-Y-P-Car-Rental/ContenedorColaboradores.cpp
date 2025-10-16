#include "ContenedorColaboradores.h"

ContenedorColaboradores::ContenedorColaboradores() {
	cabeza = nullptr;
}
ContenedorColaboradores::~ContenedorColaboradores() {
	NodoColaborador* actual = cabeza;
	while (actual) {
		NodoColaborador* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
}
void ContenedorColaboradores::agregarColaborador(Colaborador* colaborador) {
	NodoColaborador* nuevoNodo = new NodoColaborador(colaborador, cabeza);
	cabeza = nuevoNodo;
}
void ContenedorColaboradores::eliminarColaborador(const string& id) {
	if (!cabeza) return; // Lista vacía
	if (cabeza->getColaborador()->getId() == id) {
		NodoColaborador* temp = cabeza;
		cabeza = cabeza->getSiguiente();
		delete temp;
		return;
	}
	NodoColaborador* actual = cabeza;
	while (actual->getSiguiente() && actual->getSiguiente()->getColaborador()->getId() != id) {
		actual = actual->getSiguiente();
	}
	if (actual->getSiguiente()) {
		NodoColaborador* temp = actual->getSiguiente();
		actual->setSiguiente(temp->getSiguiente());
		delete temp;
	}
}
Colaborador* ContenedorColaboradores::buscarColaborador(const string& id) {
	NodoColaborador* actual = cabeza;
	while (actual) {
		if (actual->getColaborador()->getId() == id) {
			return actual->getColaborador();
		}
		actual = actual->getSiguiente();
	}
	return nullptr; // No encontrado
}
bool ContenedorColaboradores::estaVacio() const {
	return cabeza == nullptr;
}

string ContenedorColaboradores::toString() {
	stringstream ss;
	NodoColaborador* actual = cabeza;
	while (actual) {
		ss << actual->getColaborador()->toString() << "\n";
		actual = actual->getSiguiente();
	}
	return ss.str();
}