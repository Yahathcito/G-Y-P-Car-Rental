#pragma once
#include "Sucursal.h"
class NodoSucursal{
	private: 
		Sucursal* sucursal;
		NodoSucursal* siguiente;
	public:
		NodoSucursal(Sucursal*,NodoSucursal*);
		virtual ~NodoSucursal();
		Sucursal* getSucursal();
		NodoSucursal* getSiguiente();
		void setSiguiente(NodoSucursal*);
		void setSucursal(Sucursal*);
};

