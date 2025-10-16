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

void ContenedorClientes::ingresarCliente(Cliente* cli)
{
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

bool ContenedorClientes::buscarCliente(string)
{
	if (estaVacia()) return false; 
	return true;

}

void ContenedorClientes::eliminarCliente(string id)
{
	if (estaVacia()) return; 
	NodoCliente* actual = ppio; 
	NodoCliente* anterior = nullptr; 
	while (actual != nullptr && actual->getCliente()->getId() != id) {
		anterior = actual; 
		actual = actual->getSiguiente(); 
	}
	if (actual == nullptr) return; 
	if (anterior == nullptr) {
		ppio = actual->getSiguiente();
	}
	else {
		anterior->setSiguiente(actual->getSiguiente());
	}
	delete actual;
}
