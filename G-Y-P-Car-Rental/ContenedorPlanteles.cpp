#include "ContenedorPlanteles.h"

ContenedorPlanteles::ContenedorPlanteles():ppio(nullptr){}

ContenedorPlanteles::~ContenedorPlanteles(){
	if (estaVacio()) return; 
	NodoPlantel* aux; 
	while (ppio != nullptr) {
		aux = ppio;
		ppio = ppio->getSiguiente();
		delete aux;
	}
}

bool ContenedorPlanteles::agregarPlantel(Plantel* p){
	NodoPlantel* aux=ppio; 
	while (aux != nullptr) {
		if (aux->getPlantel()->getId() == p->getId()) return false; 
		aux = aux->getSiguiente(); 
	}
	ppio = new NodoPlantel(p, ppio); 
	return true; 
}

bool ContenedorPlanteles::estaVacio(){
	return ppio == nullptr;
}

Plantel* ContenedorPlanteles::buscarPlantel(char codigo){
	NodoPlantel* aux = ppio;
	while (aux != nullptr) {
		if (aux->getPlantel()->getId() == codigo) {
			return aux->getPlantel();
		}
		aux = aux->getSiguiente();
	}
	return nullptr;
}

string ContenedorPlanteles::mostrarCarrosXPlantel() {
	stringstream s;
	NodoPlantel* aux = ppio; 
	while (aux != nullptr) {
		s << aux->getPlantel()->mostrarCarrosXPlantel(); 
		aux = aux->getSiguiente(); 
	}
	return s.str();
}

bool ContenedorPlanteles::validarPlantel(char id){
	NodoPlantel* aux = ppio; 
	while (aux != nullptr) {
		if (aux->getPlantel()->getId() == id) return true; 
	}
	return false;
}

string ContenedorPlanteles::toString(){
	stringstream s; 
	NodoPlantel* aux = ppio; ;
	while (aux != nullptr) {
		s << aux->getPlantel()->toString(); 
		s << endl; 
		aux = aux->getSiguiente(); 
	}
	return s.str();
}
