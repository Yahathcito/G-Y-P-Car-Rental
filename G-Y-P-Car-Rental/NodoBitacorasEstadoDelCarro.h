#pragma once
#include "BitacoraEstadosDelCarro.h"
class NodoBitacorasEstadoDelCarro{
	private:
		BitacoraEstadosDelCarro* bitacora;
		NodoBitacorasEstadoDelCarro* siguiente;
	public:
		NodoBitacorasEstadoDelCarro(BitacoraEstadosDelCarro*, NodoBitacorasEstadoDelCarro*);
		~NodoBitacorasEstadoDelCarro();
		BitacoraEstadosDelCarro* getBitacora();
		NodoBitacorasEstadoDelCarro* getSiguiente();
		void setSiguiente(NodoBitacorasEstadoDelCarro*);

};

