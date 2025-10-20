#pragma once
#include"NodoCarro.h"
class ContenedorCarros
{
	private:
		NodoCarro* cabeza;
		
	public: 
		ContenedorCarros();
		virtual ~ContenedorCarros();
		bool agregarCarro(Carro*);
		bool eliminarCarro(string);
		bool estaVacio();
		Carro* obtenerCarro(string); 
		string mostrarTipoDeCarros();
		string toString();
};

