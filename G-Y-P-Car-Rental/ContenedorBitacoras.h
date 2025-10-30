#pragma once
#include "NodoBitacorasEstadoDelCarro.h"
class ContenedorBitacoras{
	private:
		NodoBitacorasEstadoDelCarro* ppio;
	public:
		ContenedorBitacoras();
		virtual ~ContenedorBitacoras();
		bool estaVacio();
		void registrarBitacora(BitacoraEstadosDelCarro*);
		string toString(); 

};

