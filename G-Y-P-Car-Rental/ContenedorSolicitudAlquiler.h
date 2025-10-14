#pragma once
#include "NodoSolicitudAlquiler.h"

class ContenedorSolicitudAlquiler
{
	private:
		NodoSolicitudAlquiler* cabeza;
	public:
		ContenedorSolicitudAlquiler();
		~ContenedorSolicitudAlquiler();
		bool estaVacio();

};

