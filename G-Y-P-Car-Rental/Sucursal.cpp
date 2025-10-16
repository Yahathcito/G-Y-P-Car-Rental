#include "Sucursal.h"

Sucursal::Sucursal(string numUnicoSucursal, string provincia) {
	this->numUnicoSucursal = numUnicoSucursal;
	this->provincia = provincia;
	contenedorCarros = new ContenedorCarros();
	contenedorClientes = new ContenedorClientes();
	contenedorColaboradores = new ContenedorColaboradores();
	contenedorPlanteles = new ContenedorPlanteles();
	contenedorContratoAlquiler = new ContenedorContratoAlquiler();
	contenedorSolicitudAlquiler = new ContenedorSolicitudAlquiler();
}
Sucursal::~Sucursal(){
	delete contenedorCarros;
	delete contenedorClientes;
	delete contenedorColaboradores;
	delete contenedorPlanteles;
	delete contenedorContratoAlquiler;
	delete contenedorSolicitudAlquiler;
}

ContenedorCarros* Sucursal::getContenedorCarros()
{
	return contenedorCarros;
}
ContenedorClientes* Sucursal::getContenedorClientes()
{
	return contenedorClientes;
}
ContenedorColaboradores* Sucursal::getContenedorColaboradores()
{
	return contenedorColaboradores;
}
ContenedorPlanteles* Sucursal::getContenedorPlanteles()
{
	return contenedorPlanteles;
}
ContenedorContratoAlquiler* Sucursal::getContenedorContratoAlquiler()
{
	return contenedorContratoAlquiler;
}
ContenedorSolicitudAlquiler* Sucursal::getContenedorSolicitudAlquiler()
{
	return contenedorSolicitudAlquiler;
}

string Sucursal::getNumUnico()
{
	return numUnicoSucursal;
}


string Sucursal::toString() {
	stringstream s;
	s << "Numero Unico de Sucursal: " << numUnicoSucursal << endl;
	s << "Provincia: " << provincia << endl;
	return s.str();
}
