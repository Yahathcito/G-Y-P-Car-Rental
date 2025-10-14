
#include "ContenedorCarros.h"

ContenedorCarros::ContenedorCarros():cabeza(nullptr){}

ContenedorCarros::~ContenedorCarros(){
	if (estaVacio()) return;
	NodoCarro* actual;
	while (cabeza != nullptr) {
		actual = cabeza;
		cabeza = cabeza->getSiguiente();
		delete actual;
	}
}
bool ContenedorCarros::estaVacio() {
	return cabeza == nullptr;
}

bool ContenedorCarros::agregarCarro(Carro* c) {
	if (estaVacio()) {
		cabeza = new NodoCarro(c, cabeza);
		return true;
	}
	NodoCarro* aux = cabeza;
	while (aux->getSiguiente() != nullptr) {
		if (aux->getCarro()->getPlaca() == c->getPlaca()) return false;
		aux = aux->getSiguiente();
	}
	cabeza = new NodoCarro(c, cabeza);
	return true;
}
string ContenedorCarros::toString(){
	stringstream s; 
	NodoCarro* aux = cabeza;
	if (estaVacio()) {
		s << "No hay carros registrados.\n";
		return s.str();
	}
	while (aux != nullptr) {
		s << aux->getCarro()->toString() << "\n";
		aux = aux->getSiguiente();
	}

	return s.str();
}