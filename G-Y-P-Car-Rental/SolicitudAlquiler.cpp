#include "SolicitudAlquiler.h"


SolicitudAlquiler::SolicitudAlquiler(string idSolicitud, string idCliente, string idColaborador, string placaVehiculo, int canDiasAlquiler, string fechaInicioAlquiler, string fechaFinAlquiler, float precioAlquiler, float precioDias, string estadoSolicitud[]) {
	this->idSolicitud = idSolicitud;
	this->idCliente = idCliente;
	this->idColaborador = idColaborador;
	this->placaVehiculo = placaVehiculo;
	this->canDiasAlquiler = canDiasAlquiler;
	this->fechaInicioAlquiler = fechaInicioAlquiler;
	this->fechaFinAlquiler = fechaFinAlquiler;
	this->precioAlquiler = precioAlquiler;
	this->precioDias = precioDias;
	for (int i = 0; i < 4; i++) {
		this->estadoSolicitud[i] = estadoSolicitud[i];
	}
}
string SolicitudAlquiler::getIdSolicitud()
{
	return idSolicitud;
}
string SolicitudAlquiler::getIdCliente()
{
	return idCliente;
}
string SolicitudAlquiler::getIdColaborador()
{
	return idColaborador;
}
int SolicitudAlquiler::getCanDiasAlquiler()
{
	return canDiasAlquiler;
}
string SolicitudAlquiler::getFechaInicioAlquiler()
{
	return fechaInicioAlquiler;
}
string SolicitudAlquiler::getFechaFinAlquiler()
{
	return fechaFinAlquiler;
}
float SolicitudAlquiler::getPrecioAlquiler()
{
	return precioAlquiler;
}
float SolicitudAlquiler::getPrecioDias()
{
	return precioDias;
}
string SolicitudAlquiler::getPlacaVehiculo()
{
	return placaVehiculo;
}
string* SolicitudAlquiler::getEstadoSolicitud()
{
	return estadoSolicitud;
}

string SolicitudAlquiler::toString()
{
	stringstream s;
	s << "ID: " << idSolicitud << endl;
	s << "ID Cliente: " << idCliente << endl;
	s << "ID Colaborador: " << idColaborador << endl;
	s << "Cantidad Dias Alquiler: " << canDiasAlquiler << endl;
	s << "Fecha Inicio Alquiler: " << fechaInicioAlquiler << endl;
	s << "Fecha Fin Alquiler: " << fechaFinAlquiler << endl;
	s << "Precio Alquiler: " << precioAlquiler << endl;
	s << "Estado Solicitud: ";
	for (int i = 0; i < 4; i++) {
		s << estadoSolicitud[i];
		if (i < 3) {
			s << ", ";
		}
	}
	s << endl;
	return s.str();
}
void SolicitudAlquiler::setEstadoSolicitud(int indice, string nuevoEstado)
{
	if (indice >= 0 && indice < 4) {
		estadoSolicitud[indice] = nuevoEstado;
	}
}