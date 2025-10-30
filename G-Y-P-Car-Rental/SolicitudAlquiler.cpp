#include "SolicitudAlquiler.h"


SolicitudAlquiler::SolicitudAlquiler(string idSolicitud, string idCliente, string idColaborador, string placaVehiculo, int canDiasAlquiler, string fechaInicioAlquiler, string fechaFinAlquiler, float precioAlquiler, float precioDias, string estadoSolicitud) {
	this->idSolicitud = idSolicitud;
	this->idCliente = idCliente;
	this->idColaborador = idColaborador;
	this->placaVehiculo = placaVehiculo;
	this->canDiasAlquiler = canDiasAlquiler;
	this->fechaInicioAlquiler = fechaInicioAlquiler;
	this->fechaFinAlquiler = fechaFinAlquiler;
	this->precioAlquiler = precioAlquiler;
	this->precioDias = precioDias;
	this->estadoSolicitud = estadoSolicitud;
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
string SolicitudAlquiler::getEstadoSolicitud()
{
	return estadoSolicitud;
}


string SolicitudAlquiler::toString()
{
	stringstream s;
	s << "ID Solicitud: " << idSolicitud << "\n";
	s << "ID Cliente: " << idCliente << "\n";
	s << "ID Colaborador: " << idColaborador << "\n";
	s << "Placa Vehiculo: " << placaVehiculo << "\n";
	s << "Cantidad Dias Alquiler: " << canDiasAlquiler << "\n";
	s << "Fecha Inicio Alquiler: " << fechaInicioAlquiler << "\n";
	s << "Fecha Fin Alquiler: " << fechaFinAlquiler << "\n";
	s << "Precio Alquiler: " << precioAlquiler << "\n";
	s << "Precio Dias: " << precioDias << "\n";
	s << "Estado Solicitud: " << estadoSolicitud << "\n";
	return s.str();
}

void SolicitudAlquiler::setEstadoSolicitud( string nuevoEstado)
{
	estadoSolicitud = nuevoEstado;
}