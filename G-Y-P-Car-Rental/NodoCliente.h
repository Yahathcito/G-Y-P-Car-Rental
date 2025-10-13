#pragma once
#include "Cliente.h"
class NodoCliente{
	private: 
		Cliente* cliente; 
		NodoCliente* siguiente; 
	public: 
		NodoCliente(Cliente*, NodoCliente*); 
		virtual ~NodoCliente(); 
		void setCliente(Cliente*); 
		void setSiguiente(NodoCliente*); 
		Cliente* getCliente(); 
		NodoCliente* getSiguiente(); 
};

