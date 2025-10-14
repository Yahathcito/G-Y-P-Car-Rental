#pragma once
#include <string>
#include <sstream>
using namespace std;
class Carro {
private:
	string placa;
	int modelo;
	string marca;
	string tipo;
public:
	Carro(string,int,string,string);
	void setPlaca(string);
	void setModelo(int);
	void setMarca(string);
	void setTipo(string);
	string getPlaca();
	int getModelo();
	string getMarca();
	string getTipo();
	string toString();
};

