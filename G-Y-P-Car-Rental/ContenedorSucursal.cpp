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
	ppio = new NodoSucursal(s, ppio);
	return true; 
	
}

bool ContenedorSucursal::eliminarSucursal(string codigoUnico){
	if (estaVacio()) return false;

	NodoSucursal* actual = ppio; 
	NodoSucursal* anterior = nullptr; 

	while (actual != nullptr && actual->getSucursal()->getNumUnico() != codigoUnico) {
		anterior = actual; 
		actual = actual->getSiguiente(); 
	}
	if (actual == nullptr) return false; 
	if (anterior == nullptr) {
		ppio = actual->getSiguiente();
	}
	else {
		anterior->setSiguiente(actual->getSiguiente());
	}
	delete actual; 
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

bool ContenedorSucursal::validarSucursal(string codigoUnico){
	if (estaVacio()) return true; 
	NodoSucursal* aux = ppio;
	while (aux != nullptr) {
		if (aux->getSucursal()->getNumUnico() == codigoUnico) return false;
		aux = aux->getSiguiente();
	}
	return true;
	
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

Sucursal* ContenedorSucursal::getSucursalActual()
{
	return ppio->getSucursal();
}
