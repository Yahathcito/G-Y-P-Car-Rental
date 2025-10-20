
#include "ContenedorCarros.h"

ContenedorCarros::ContenedorCarros():cabeza(nullptr){}

ContenedorCarros::~ContenedorCarros(){
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

Carro* ContenedorCarros::obtenerCarro(string placa){
	if (estaVacio())return nullptr; 
	NodoCarro* aux = cabeza; 
	while (aux != nullptr) {
		if (aux->getCarro()->getPlaca() == placa)
			return aux->getCarro(); 
	}

	return nullptr;
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
bool ContenedorCarros::eliminarCarro(string placa ){ 
	if (estaVacio()) return false;

	NodoCarro* actual = cabeza;
	NodoCarro* anterior = nullptr;
	while (actual != nullptr && actual->getCarro()->getPlaca() != placa) {
		anterior = actual; 
		actual = actual->getSiguiente(); 
	}
	if (actual == nullptr || actual->getCarro()->getEstado() == "Alquilado") return false;
	if (anterior == nullptr) {
		cabeza->setSiguiente(actual->getSiguiente()); 
	}
	else {
		anterior->setSiguiente(actual->getSiguiente()); 
	}
	delete actual; 
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

string ContenedorCarros::mostrarTipoDeCarros(){
	string tipo[4] = { "Economico","Estandar","Lujo","4x4" };
	stringstream s; 
	s << "Tipos de carros disponibles:\n";
	for (int i = 0; i < 4; i++) {
		s << i + 1 << ". " << tipo[i] << endl;
	}
	return s.str();
}

