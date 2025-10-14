#pragma once
#include "Colaborador.h"

class NodoColaborador
{
	private:
	Colaborador* colaborador;
	NodoColaborador* siguiente;
	public:
		NodoColaborador(Colaborador*, NodoColaborador*);
		~NodoColaborador();
		Colaborador* getColaborador();
		NodoColaborador* getSiguiente();
		NodoColaborador* setSiguiente(NodoColaborador*);

};

