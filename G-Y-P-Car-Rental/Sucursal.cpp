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

string Sucursal::mostrarVehiculos(){
	stringstream s; 
	s << contenedorPlanteles->mostrarCarrosXPlantel(); 
	return s.str();
}

string Sucursal::mostrarPlantelesDisponibles(){
	stringstream s;
	s << contenedorPlanteles->toString(); 
	return s.str();
}

Plantel* Sucursal::getPlantel(char codigo){
	return contenedorPlanteles->buscarPlantel(codigo);
}

bool Sucursal::validarPlantel(char id){

	return contenedorPlanteles->validarPlantel(id);
}

bool Sucursal::NoexistePlantel(){
	return this->getContenedorPlanteles()->estaVacio(); 
}

void Sucursal::intercambiarCarro(Plantel* plantelActual, string placa, Carro* carro, EspacioEstacionamiento* espacio,Sucursal* sucursalIntercambio){
	espacio->estacionarCarro(carro); 
	sucursalIntercambio->getContenedorCarros()->agregarCarro(carro);
	plantelActual->eliminarCarro(placa);
	this->getContenedorCarros()->eliminarCarro(placa); 
}



string Sucursal::toString() {
	stringstream s;
	s << "====================================\n";
	s << "Numero Unico de Sucursal: " << numUnicoSucursal << endl;
	s << "Provincia: " << provincia << endl;
	s << "====================================\n";
	return s.str();
}
