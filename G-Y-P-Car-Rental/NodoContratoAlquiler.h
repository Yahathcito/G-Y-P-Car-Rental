#pragma once
#include "ContratoAlquiler.h"
class NodoContratoAlquiler
{
private:
	ContratoAlquiler* contratoAlquiler;
	NodoContratoAlquiler* siguiente;

public:
	NodoContratoAlquiler(ContratoAlquiler* contratoAlquiler, NodoContratoAlquiler* siguiente);
	~NodoContratoAlquiler();
	ContratoAlquiler* getContratoAlquiler();
	NodoContratoAlquiler* getSiguiente();
	NodoContratoAlquiler* setSiguiente(NodoContratoAlquiler* siguiente);


};

