#include "ContenedorBitacoras.h"

ContenedorBitacoras::ContenedorBitacoras():ppio(nullptr){}

ContenedorBitacoras::~ContenedorBitacoras(){
	NodoBitacorasEstadoDelCarro* actual = ppio;
	while (ppio != nullptr) {
		actual = ppio;
		ppio = ppio->getSiguiente();
		delete actual;
	}
}


bool ContenedorBitacoras::estaVacio(){ return ppio == nullptr; }

void ContenedorBitacoras::registrarBitacora(BitacoraEstadosDelCarro* bitacora){
	ppio = new NodoBitacorasEstadoDelCarro(bitacora, ppio); 
}

string ContenedorBitacoras::toString(){
	stringstream s; 
	NodoBitacorasEstadoDelCarro* aux = ppio; 
	while (aux != nullptr) {
		s << aux->getBitacora()->toString(); 
		aux = aux->getSiguiente(); 
	}
	return s.str();
}

