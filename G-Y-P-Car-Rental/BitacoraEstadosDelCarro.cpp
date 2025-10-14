
#include "BitacoraEstadosDelCarro.h"

BitacoraEstadosDelCarro::BitacoraEstadosDelCarro(string estadoAnterior, string estadoNuevo, string colaboradorId, string fecha) {
	this->estadoAnterior = estadoAnterior;
	this->estadoNuevo = estadoNuevo;
	this->colaboradorId = colaboradorId;
	this->fecha = fecha;
}
string BitacoraEstadosDelCarro::getEstadoAnterior() {
	return estadoAnterior;
}
string BitacoraEstadosDelCarro::getEstadoNuevo() {
	return estadoNuevo;
}
string BitacoraEstadosDelCarro::getColaboradorId() {
	return colaboradorId;
}

string BitacoraEstadosDelCarro::getFecha() {
	return fecha;
}

string BitacoraEstadosDelCarro::toString() {
	stringstream ss;
	
	ss << "Fecha: " << getFecha() << endl;
	ss << "Estado Anterior: " << getEstadoAnterior() << endl;
	ss << "Estado Nuevo: " << getEstadoNuevo() << endl;
	ss << "ID del Colaborador : " << getColaboradorId() << endl;
	return ss.str();
}
