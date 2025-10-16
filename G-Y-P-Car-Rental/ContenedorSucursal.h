#pragma once
#include "NodoSucursal.h"
class ContenedorSucursal{
	private:
		NodoSucursal* ppio;
	public: 
		ContenedorSucursal(); 
		virtual ~ContenedorSucursal();
		bool agregarSucursal(Sucursal*);
		bool eliminarSucursal(string);
		Sucursal* buscarSucursal(string);
		bool validarSucursal(string);
		bool estaVacio(); 
		string toString();
};

