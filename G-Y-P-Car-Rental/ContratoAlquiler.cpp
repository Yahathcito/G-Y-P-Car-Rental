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
	this->estadoContrato = "";
}

ContratoAlquiler::ContratoAlquiler(string idContrato, string idCliente, string idColaborador, string placaVehiculo, string fechaInicio, string fechaEntrega, int dias, float precioDiario, float precioTotal, string estadoContrato)
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
	this->estadoContrato = estadoContrato;
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
void ContratoAlquiler::setEstadoContrato(string estadoContrato)
{
	this->estadoContrato = estadoContrato;
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

string ContratoAlquiler::getEstadoContrato()
{
	return estadoContrato;
}





string ContratoAlquiler::toString()
{
	stringstream s;
	s << "---------------------------------\n";
	s << "ID Contrato: " << idContrato << "\n";
	s << "ID Cliente: " << idCliente << "\n";
	s << "ID Colaborador: " << idColaborador << "\n";
	s << "Placa Vehiculo: " << placaVehiculo << "\n";
	s << "Fecha Inicio: " << fechaInicio << "\n";
	s << "Fecha Entrega: " << fechaEntrega << "\n";
	s << "Dias: " << dias << "\n";
	s << "Precio Diario: " << precioDiario << "\n";
	s << "Precio Total: " << precioTotal << "\n";
	s << "Estado Contrato: " << estadoContrato << "\n";
	s << "---------------------------------\n";
	return s.str();
}


