#pragma once
#include"Carro.h"

class NodoCarro
{
	private :
		Carro* carro;
		NodoCarro* siguiente;
public:
	NodoCarro(Carro*,NodoCarro*);
	~NodoCarro();
	Carro* getCarro();
	Carro* setCarro(Carro* carro);
	NodoCarro* getSiguiente();
	NodoCarro* setSiguiente(NodoCarro* siguiente);

};

