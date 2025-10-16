#include "Plantel.h"

Plantel::Plantel(string id, int filas,int columnas) {
	this->id = id;
	this->filas = filas; 
	this->columnas = columnas; 
	string codigo; 
	int numero; 
	espacio = new EspacioEstacionamiento **[filas]; 
	for (int i = 0; i < filas; i++) {
		espacio[i] = new EspacioEstacionamiento * [columnas]; 
		for (int j = 0; j < columnas;j++) {
			numero = i * columnas + j; 
			codigo = id + (numero < 10 ? "0" : "") + to_string(numero); 
			espacio[i][j] = new EspacioEstacionamiento(codigo);
		}
	}
}
Plantel::~Plantel() {
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++)
				delete espacio[i][j];
			delete[] espacio[i];
		}
		delete[] espacio;
}

string Plantel::getId() {
	return id;
}
int Plantel::getCapacidadMaxima() {
	return filas*columnas;
}

EspacioEstacionamiento* Plantel::buscarEspacio(string codigo){
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas;j++) {
			if (espacio[i][j]->getIdEspacio() == codigo) return espacio[i][j];
		}
	}
	return nullptr;
}

string Plantel::toString() {
	stringstream s;
	s << "---------------------------------------\n";
	s << "ID del Plantel: " << id << endl;
	s << "Capacidad Maxima: " << filas*columnas << endl;
	s << "---------------------------------------\n";
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas;j++) {
			s << "[" << (espacio[i][j]->isDisponible() ? espacio[i][j]->getIdEspacio() : "X") << "]";
		}
		s << endl; 
	}
	return s.str();
}
