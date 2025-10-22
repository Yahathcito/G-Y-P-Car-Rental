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
	NodoSolicitudAlquiler* nuevoNodo = new NodoSolicitudAlquiler(nuevaSolicitud, nullptr);
	if (estaVacio()) {
		cabeza = nuevoNodo;
	}
	else {
		NodoSolicitudAlquiler* actual = cabeza;
		while (actual->getSiguiente() != nullptr) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevoNodo);
	}

}
void ContenedorSolicitudAlquiler::eliminarSolicitud(string idSolicitud)
{
	NodoSolicitudAlquiler* actual = cabeza;
	NodoSolicitudAlquiler* anterior = nullptr;
	while (actual != nullptr) {
		if (actual->getSolicitudAlquiler()->getIdSolicitud() == idSolicitud) {
			if (anterior == nullptr) {
				cabeza = actual->getSiguiente();
			}
			else {
				anterior->setSiguiente(actual->getSiguiente());
			}
			delete actual;
			return;
		}
		anterior = actual;
		actual = actual->getSiguiente();
	}
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

SolicitudAlquiler* ContenedorSolicitudAlquiler::obtenerSolicitudPorId(string idSolicitud)
{
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getSolicitudAlquiler()->getIdSolicitud() == idSolicitud) {
			return actual->getSolicitudAlquiler();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
}

void ContenedorSolicitudAlquiler::aprobarSolicitud(string idSolicitud)
{
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getSolicitudAlquiler()->getIdSolicitud() == idSolicitud) {
			actual->getSolicitudAlquiler()->setEstadoSolicitud( "aprobada");
			return;
		}
		actual = actual->getSiguiente();
	}
}
void ContenedorSolicitudAlquiler::rechazarSolicitud(string idSolicitud)
{
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getSolicitudAlquiler()->getIdSolicitud() == idSolicitud) {
			actual->getSolicitudAlquiler()->setEstadoSolicitud( "rechazada");
			return;
		}
		actual = actual->getSiguiente();
	}
}

void ContenedorSolicitudAlquiler::mostrarSolicitudesPorCliente(string idCliente)
{
	NodoSolicitudAlquiler* actual = cabeza;
	while (actual != nullptr) {
		if (actual->getSolicitudAlquiler()->getIdCliente() == idCliente) {
			cout << actual->getSolicitudAlquiler()->toString() << "\n";
		}
		actual = actual->getSiguiente();
	}
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