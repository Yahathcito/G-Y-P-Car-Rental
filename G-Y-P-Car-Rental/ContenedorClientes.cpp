#include "ContenedorClientes.h"

ContenedorClientes::ContenedorClientes():ppio(nullptr){}

ContenedorClientes::~ContenedorClientes(){
	if (estaVacia())return;
	NodoCliente* aux; 
	while (ppio != nullptr) {
		aux = ppio;
		ppio = ppio->getSiguiente();
		delete aux;
	}
}

bool ContenedorClientes::ingresarCliente(Cliente* cli){
	if (estaVacia()) {
		ppio = new NodoCliente(cli, ppio); 
		return true; 
	}
	NodoCliente* aux=ppio; 
	while (aux->getSiguiente() != nullptr) {
		aux = aux->getSiguiente();
		if (aux->getCliente()->getId() == cli->getId()) return false;
	}
	ppio = new NodoCliente(cli, ppio); 
}

string ContenedorClientes::toString(){
	stringstream ss; 
	NodoCliente* aux = ppio; 
	if (estaVacia()) {
		ss << "No hay clientes registrados.\n"; 
		return ss.str(); 
	}
	while (aux != nullptr) {
		ss << aux->getCliente()->toString() << "\n"; 
		aux = aux->getSiguiente(); 
	}
	return ss.str();
}

bool ContenedorClientes::estaVacia(){
	if (ppio == nullptr) return true; 
	return false;
}

Cliente* ContenedorClientes::getClienteXId(string id){
	if (estaVacia()) return nullptr; 
	NodoCliente* aux = ppio; 
	while (aux != nullptr) {
		if (aux->getCliente()->getId() == id) return aux->getCliente(); 
		aux = aux->getSiguiente(); 
	}
	return nullptr; 
}
