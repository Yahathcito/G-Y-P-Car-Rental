#pragma once
#include "NodoSolicitudAlquiler.h"

class ContenedorSolicitudAlquiler
{
	private:
		NodoSolicitudAlquiler* cabeza;
	public:
		ContenedorSolicitudAlquiler();
		~ContenedorSolicitudAlquiler();
		void agregarSolicitudAlquiler(SolicitudAlquiler* nuevaSolicitud);
		bool estaVacio();
		bool buscarSolicitudPorId(string idSolicitud);
		string toString();

};

