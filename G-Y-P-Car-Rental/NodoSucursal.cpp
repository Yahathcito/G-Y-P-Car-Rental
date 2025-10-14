#include "NodoSucursal.h"

NodoSucursal::NodoSucursal(Sucursal* sucursal, NodoSucursal* siguiente){
	this->sucursal = sucursal;
	this->siguiente = siguiente;
}

NodoSucursal::~NodoSucursal(){
	delete sucursal;
}

Sucursal* NodoSucursal::getSucursal(){

	return sucursal;
}

NodoSucursal* NodoSucursal::getSiguiente(){
	return siguiente;
}

void NodoSucursal::setSiguiente(NodoSucursal* siguiente){
	this->siguiente = siguiente;
}

void NodoSucursal::setSucursal(Sucursal* sucursal){
	this->sucursal = sucursal;
}
