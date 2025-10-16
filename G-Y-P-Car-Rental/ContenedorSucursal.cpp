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
	if (ppio->getSucursal()->getNumUnico() == codigoUnico) {
		NodoSucursal* aux = ppio; 
		ppio = ppio->getSiguiente(); 
		delete aux; 
		return true; 
	}
	NodoSucursal* aux = ppio; 
	while (aux->getSiguiente()!=nullptr && aux->getSiguiente()->getSucursal()->getNumUnico() != codigoUnico) {
		aux = aux->getSiguiente(); 
	}
	if (aux->getSiguiente() == nullptr) return false;
	NodoSucursal* nodoEliminar = aux->getSiguiente(); 
	aux->setSiguiente(nodoEliminar->getSiguiente());
	delete nodoEliminar; 
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
