#pragma once
#include"NodoCarro.h"
class ContenedorCarros
{
	private:
		NodoCarro* cabeza;
		
	public: 
		ContenedorCarros();
		~ContenedorCarros();
		bool estaVacio();	
};

