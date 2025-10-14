#pragma once
#include "BitacoraEstadosDelCarro.h"

class NodoBitacorasEstadoDelCarro
{
	private:
	BitacoraEstadosDelCarro* bitacora;
	NodoBitacorasEstadoDelCarro* siguiente;
public:
	NodoBitacorasEstadoDelCarro(BitacoraEstadosDelCarro* bitacora, NodoBitacorasEstadoDelCarro* siguiente);
	~NodoBitacorasEstadoDelCarro();
	BitacoraEstadosDelCarro* getBitacora();
	NodoBitacorasEstadoDelCarro* getSiguiente();
	NodoBitacorasEstadoDelCarro* setSiguiente(NodoBitacorasEstadoDelCarro* siguiente);

};

