#pragma once
#include <string>
#include <sstream>
using namespace std;
class Carro {
private:
	string placa;
	int modelo;
	string marca;
	string categoria;
	string tipoLicencia; 
	string estado; 
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
	string toString();
	string getEstado(); 
	string getTipoLicencia(); 
	bool verificarDisponibilidad();
};

