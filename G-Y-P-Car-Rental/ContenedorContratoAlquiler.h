#pragma once
#include "NodoContratoAlquiler.h"
class ContenedorContratoAlquiler
{
	private:
		NodoContratoAlquiler* cabeza;
public:
		ContenedorContratoAlquiler();
		~ContenedorContratoAlquiler();
		bool estaVacio();
		bool buscarContratoAlquiler(string idContrato);
		ContratoAlquiler* obtenerContratoAlquiler(string idContrato);
		void eliminarContratoAlquiler(string idContrato);
		void agregarContratoAlquiler(ContratoAlquiler* nuevoContrato);
		void finalizarContrato(string idContrato);
		void mostrarContratosPorCliente(string idCliente);
		string mostrarContratosPorCarro(string); 
		string toString();

};

