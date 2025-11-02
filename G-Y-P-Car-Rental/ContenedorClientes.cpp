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

void ContenedorClientes::reporteClientesPorCantidadContratos(ContenedorContratoAlquiler* contenedorContratos)
{
	/////*Reporte de clientes por cantidad de contratos : Ordena en la lista los
	////	clientes por cantidad de alquileres realizados, iniciando por el cliente
	////	que más alquileres haya hecho.Debe incluir el id y el nombre del
	////	cliente, así como el código de los contratos de alquiler realizados.*/
	if (estaVacia()) {
		cout << "No hay clientes registrados.\n";
		return;
	}
	NodoCliente* actual = ppio;
	while (actual != nullptr) {
		int contador = 0;
		contenedorContratos->contarContratosPorCliente(actual->getCliente()->getId(), contador);
		cout << "Cliente ID: " << actual->getCliente()->getId() << ", Nombre: " << actual->getCliente()->getNombre() << ", Cantidad de contratos: " << contador << "\n";
		actual = actual->getSiguiente();
	}

}
