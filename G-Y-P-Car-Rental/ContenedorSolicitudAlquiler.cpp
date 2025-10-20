#include "ContenedorSolicitudAlquiler.h"

ContenedorSolicitudAlquiler::ContenedorSolicitudAlquiler()
{
	this->cabeza = nullptr;
}
ContenedorSolicitudAlquiler::~ContenedorSolicitudAlquiler()
{
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		NodoSolicitudAlquiler* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
}
void ContenedorSolicitudAlquiler::agregarSolicitudAlquiler(SolicitudAlquiler* nuevaSolicitud)
{
	NodoSolicitudAlquiler* nuevoNodo = new NodoSolicitudAlquiler(nuevaSolicitud, cabeza);
	cabeza = nuevoNodo;

}
bool ContenedorSolicitudAlquiler::estaVacio()
{
	return cabeza == nullptr;
}

bool ContenedorSolicitudAlquiler::buscarSolicitudPorId(string idSolicitud)
{
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getSolicitudAlquiler()->getIdSolicitud() == idSolicitud) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}

string ContenedorSolicitudAlquiler::toString()
{
	stringstream s;
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		s << actual->getSolicitudAlquiler()->toString() << "\n";
		actual = actual->getSiguiente();
	}
	return s.str();
}