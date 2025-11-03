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
		bool buscarCarro(string);
		Carro* buscarCarroPorPlaca(string);
		Carro* obtenerCarro(string); 
		string mostrarTipoDeCarros();
		Carro* copiarCarro(string);
		string toString();
};

