#pragma once
#include "NodoCliente.h"
class ContenedorClientes{
	private: 
		NodoCliente* ppio; 
	public:
		ContenedorClientes(); 
		virtual ~ContenedorClientes();
		bool ingresarCliente(Cliente*);
		string toString();
		bool estaVacia(); 
		Cliente* getClienteXId(string);


};

