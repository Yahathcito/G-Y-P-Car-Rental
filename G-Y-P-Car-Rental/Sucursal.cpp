#include "Sucursal.h"

Sucursal::Sucursal(string numUnicoSucursal, string provincia) {
	this->numUnicoSucursal = numUnicoSucursal;
	this->provincia = provincia;

}
string Sucursal::toString() {
	stringstream s;
	s << "Número Único de Sucursal: " << numUnicoSucursal << endl;
	s << "Provincia: " << provincia << endl;
	return s.str();
}
