#pragma once
#include "SolicitudAlquiler.h"	

class NodoSolicitudAlquiler
{
	private:
		SolicitudAlquiler* solicitudAlquiler;
		NodoSolicitudAlquiler* siguiente;
	public:
		NodoSolicitudAlquiler(SolicitudAlquiler*, NodoSolicitudAlquiler*);
		~NodoSolicitudAlquiler();
		SolicitudAlquiler* getSolicitudAlquiler();
		NodoSolicitudAlquiler* getSiguiente();
		NodoSolicitudAlquiler* setSiguiente(NodoSolicitudAlquiler*);

};

