#pragma once
#include "NodoBitacorasEstadoDelCarro.h"

class ContenedorBitacoras
{
	private:
		NodoBitacorasEstadoDelCarro* cabeza;
	public:
		ContenedorBitacoras();
		~ContenedorBitacoras();
		bool estaVacio();

};

