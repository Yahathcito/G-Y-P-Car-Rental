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
		void eliminarSolicitud(string idSolicitud);
		bool estaVacio();
		bool buscarSolicitudPorId(string idSolicitud);
		SolicitudAlquiler* obtenerSolicitudPorId(string idSolicitud);
		void aprobarSolicitud(string idSolicitud);
		void rechazarSolicitud(string idSolicitud);
		void mostrarSolicitudesPorCliente(string idCliente);
		string toString();

};

