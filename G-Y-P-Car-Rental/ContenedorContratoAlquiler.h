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
};

