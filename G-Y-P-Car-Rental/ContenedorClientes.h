#pragma once
#include "NodoCliente.h"
#include "Cliente.h"
#include "ContenedorContratoAlquiler.h"


class ContenedorClientes{
	private: 
		NodoCliente* ppio; 
	public:
		ContenedorClientes(); 
		virtual ~ContenedorClientes();
		void ingresarCliente(Cliente*);
		string toString();
		bool estaVacia(); 
		Cliente* getClienteXId(string);
		bool buscarCliente(string);
		void eliminarCliente(string);
		void reporteClientesPorCantidadContratos(ContenedorContratoAlquiler* contenedorContratos);
};

