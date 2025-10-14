#include "NodoCarro.h"

NodoCarro::NodoCarro(Carro* carro, NodoCarro* siguiente) {
	this->carro = carro;
	this->siguiente = siguiente;
}
NodoCarro::~NodoCarro() {
	delete carro;
}
Carro* NodoCarro::getCarro() {
	return carro;
}
Carro* NodoCarro::setCarro(Carro* carro) {
	return this->carro = carro;
}
NodoCarro* NodoCarro::getSiguiente() {
	return siguiente;
}
NodoCarro* NodoCarro::setSiguiente(NodoCarro* siguiente) {
	return this->siguiente = siguiente;
}
