#include "ContratoAlquiler.h"


ContratoAlquiler::ContratoAlquiler()
{
	this->idContrato = "";
	this->idSolicitud = "";
	this->idCliente = "";
	this->idColaborador = "";
	this->placaVehiculo = "";
	this->fechaInicio = "";
	this->fechaEntrega = "";
	this->dias = 0;
	this->precioDiario = 0.0;
	this->precioTotal = 0.0;
	for (int i = 0; i < 3; i++) {
		this->estadoContrato[i] = "";
	}
}

ContratoAlquiler::ContratoAlquiler(string idContrato, string idCliente, string idColaborador, string placaVehiculo, string fechaInicio, string fechaEntrega, int dias, float precioDiario, float precioTotal, string estadoContrato[])
{
	this->idContrato = idContrato;
	this->idCliente = idCliente;
	this->idColaborador = idColaborador;
	this->placaVehiculo = placaVehiculo;
	this->fechaInicio = fechaInicio;
	this->fechaEntrega = fechaEntrega;
	this->dias = dias;
	this->precioDiario = precioDiario;
	this->precioTotal = precioTotal;
	for (int i = 0; i < 3; i++) {
		this->estadoContrato[i] = estadoContrato[i];
	}
}


string ContratoAlquiler::getIdContrato()
{
	return idContrato;
}
string ContratoAlquiler::getIdSolicitud()
{
	return idSolicitud;
}
string ContratoAlquiler::getIdCliente()
{
	return idCliente;
}
string ContratoAlquiler::getIdColaborador()
{
	return idColaborador;
}
string ContratoAlquiler::getPlacaVehiculo()
{
	return placaVehiculo;
}
string ContratoAlquiler::getFechaInicio()
{
	return fechaInicio;
}
string ContratoAlquiler::getFechaEntrega()
{
	return fechaEntrega;
}
int ContratoAlquiler::getDias()
{
	return dias;
}
float ContratoAlquiler::getPrecioDiario()
{
	return precioDiario;
}
float ContratoAlquiler::getPrecioTotal()
{
	return precioTotal;
}
string* ContratoAlquiler::getEstadoContrato()
{
	return estadoContrato;
}
string ContratoAlquiler::toString()
{
	stringstream s;
	s << "ID Contrato: " << idContrato << endl;
	s << "ID Solicitud: " << idSolicitud << endl;
	s << "ID Cliente: " << idCliente << endl;
	s << "ID Colaborador: " << idColaborador << endl;
	s << "Placa Vehiculo: " << placaVehiculo << endl;
	s << "Fecha Inicio: " << fechaInicio << endl;
	s << "Fecha Entrega: " << fechaEntrega << endl;
	s << "Dias: " << dias << endl;
	s << "Precio Diario: " << precioDiario << endl;
	s << "Precio Total: " << precioTotal << endl;
	s << "Estado Contrato: ";
	for (int i = 0; i < 3; i++) {
		s << estadoContrato[i];
		if (i < 2) {
			s << ", ";
		}
	}
	s << endl;
	return s.str();
}


