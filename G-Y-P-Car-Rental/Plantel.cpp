#include "Plantel.h"

Plantel::Plantel(char id, int filas,int columnas) {
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
			codigo = string(1,id) + (numero < 10 ? "0" : "") + to_string(numero); 
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

 char Plantel::getId() {
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

bool Plantel::eliminarCarro(string placa){
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas;j++) {
			if (espacio[i][j]->getCarro()!=nullptr && espacio[i][j]->getCarro()->getPlaca()==placa&&espacio[i][j]->getCarro()->getEstado()!="Alquilado") {
				espacio[i][j]->setCarro(nullptr); 
				espacio[i][j]->setDisponible(true); 
				return true; 
			}
		}
	}
	return false;
}

string Plantel::mostrarCarrosXPlantel() {
	stringstream s;
	s << "--------------------------\n";
	s << "VEHICULOS DEL PLANTEL '" << id << "'\n";
	s << "--------------------------\n";

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (espacio[i][j] != nullptr && !espacio[i][j]->isDisponible()) {
				Carro* carro = espacio[i][j]->getCarro();
				if (carro != nullptr) {
					s << carro->toString() << endl;
				}
			}
		}
	}

	return s.str();
}


Carro* Plantel::getCarro(string placa) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (!espacio[i][j]->isDisponible()) {
				Carro* c = espacio[i][j]->getCarro();
				if (c != nullptr && c->getPlaca() == placa)
					return c;
			}
		}
	}
	return nullptr;
}

bool Plantel::existenCarros(){
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas;j++) {
			if (espacio[i][j]->getCarro() != nullptr) return true; 
		}
	}
	return false;
}

string Plantel::mostrarEspacioEspecifico(string codigoEspacio){
	EspacioEstacionamiento* e = this->buscarEspacio(codigoEspacio);
	Carro* carro = e->getCarro(); 
	if (carro) {
		return "Este espacio posee al carro : \n" + this->buscarEspacio(codigoEspacio)->getCarro()->toString();
	}
	return "Este espacio no posee un carro.\n"; 
}

string Plantel::recomendarEspacios(){
	int MAXrecomendados = 3; 
	int contadorRecomendados = 0; 
	stringstream s;
	s << "Espacios recomendados: "; 
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas;j++) {
			if (espacio[i][j]->isDisponible()) {
				bool vecinosDisponibles = true; 
				if (i - 1 >= 0) {
					if (!espacio[i - 1][j]->isDisponible())
						vecinosDisponibles = false; 
				}
				if (i + 1 < filas) {
					if (!espacio[i + 1][j]->isDisponible())
						vecinosDisponibles = false;
				}
				if (j-1 >= 0) {
					if (!espacio[i][j-1]->isDisponible())
						vecinosDisponibles = false;
				}
				if (j + 1 < columnas) {
					if (!espacio[i][j+1]->isDisponible())
						vecinosDisponibles = false;
				}
				if (vecinosDisponibles) {
					s << espacio[i][j]->getIdEspacio() << ", "; 
					contadorRecomendados++; 
				}
				if (contadorRecomendados == MAXrecomendados) return s.str(); 
			}
		}
	}
	return s.str(); 
}

float Plantel::calcularPorcentajeOcupacion(){
	int cont = 0; 
	int espaciosTotales = filas * columnas; 
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas;j++) {
			if (!espacio[i][j]->isDisponible())
				cont++; 
		}
	}
	return (static_cast<float>(cont)/espaciosTotales)*100.0f;
}

string Plantel::toString() {
	stringstream s;
	s << "---------------------------------------\n";
	s << "ID del Plantel: " << id << endl;
	s << "Capacidad Maxima: " << filas*columnas << endl;
	s << "---------------------------------------\n";
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas;j++) {
			s << "[" << (espacio[i][j]->isDisponible() ? espacio[i][j]->getIdEspacio() : " X ") << "]";
		}
		s << endl; 
	}
	return s.str();
}
