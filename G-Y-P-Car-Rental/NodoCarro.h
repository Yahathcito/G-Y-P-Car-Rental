#pragma once
#include"Carro.h"

class NodoCarro
{
	private :
		Carro* carro;
		NodoCarro* siguiente;
public:
	NodoCarro(Carro*,NodoCarro*);
	virtual ~NodoCarro();
	Carro* getCarro();
	Carro* setCarro(Carro*);
	NodoCarro* getSiguiente();
	NodoCarro* setSiguiente(NodoCarro*);

};

