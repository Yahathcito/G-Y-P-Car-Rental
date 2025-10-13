#include "NodoCliente.h"

NodoCliente::NodoCliente(Cliente* cliente, NodoCliente* siguiente) {
    this->cliente = cliente;
    this->siguiente = siguiente;
}

NodoCliente::~NodoCliente(){
    delete cliente; 
}

void NodoCliente::setCliente(Cliente* cliente) {
    this->cliente = cliente;
}

void NodoCliente::setSiguiente(NodoCliente* siguiente) {
    this->siguiente = siguiente;
}

Cliente* NodoCliente::getCliente() {
    return cliente;
}

NodoCliente* NodoCliente::getSiguiente() {
    return siguiente;
}
