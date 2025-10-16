#pragma once
#include"NodoCarro.h"
class ContenedorCarros
{
	private:
		NodoCarro* cabeza;
		
	public: 
		ContenedorCarros();
		~ContenedorCarros();
		bool agregarCarro(Carro*);
		bool eliminarCarro(string);
		bool estaVacio();	
		string toString();
		string mostrarTipoDeCarros();
};

