#pragma once
#include <string>
#include <sstream>
using namespace std;
#include "ContenedorBitacoras.h"
class Carro {
private:
	string placa;
	int modelo;
	string marca;
	string categoria;
	string tipoLicencia; 
	string estado; 
	ContenedorBitacoras* bitacorasDelCarro; 
public:
	Carro(string,int,string,string,string);
	void setPlaca(string);
	void setModelo(int);
	void setMarca(string);
	void setCategoria(string);
	void setEstado(string); 
	void setTipoLicencia(string); 
	string getPlaca();
	int getModelo();
	string getMarca();
	string getCategoria();
	string getEstado(); 
	string getTipoLicencia(); 
	void mostrarEstadosParaPlantel(); 
	ContenedorBitacoras* getBitacora(); 
	void cambiarEstado(string,string,string,string); 
	string toString();
};

