#include "ContenedorSucursal.h"

ContenedorSucursal::ContenedorSucursal():ppio(nullptr){}

ContenedorSucursal::~ContenedorSucursal(){
	if (estaVacio()) return;
	NodoSucursal* aux;
	while (ppio!=nullptr) {
		aux = ppio;
		ppio = ppio->getSiguiente();
		delete aux;
	}
}

bool ContenedorSucursal::agregarSucursal(Sucursal* s){
	if (estaVacio()) {
		ppio = new NodoSucursal(s, nullptr);
		return true;
	}
	NodoSucursal* aux = ppio;
	while (aux != nullptr) {
		if (aux->getSucursal()->toString() == s->toString()) return false;
		aux = aux->getSiguiente();
	}
	ppio = new NodoSucursal(s, ppio);
	return true; 
	
}

Sucursal* ContenedorSucursal::buscarSucursal(string codigo){
	NodoSucursal* aux = ppio;
	while (aux != nullptr) {
		if (aux->getSucursal()->getNumUnico() == codigo) return aux->getSucursal();
		aux = aux->getSiguiente();
	}
	return nullptr;
}

bool ContenedorSucursal::estaVacio(){
	return ppio==nullptr;
}

string ContenedorSucursal::toString(){
	ostringstream s;
	NodoSucursal* aux = ppio;
	while (aux != nullptr) {
		s << aux->getSucursal()->toString() << endl;
		aux = aux->getSiguiente();
	}
	return s.str();
}
