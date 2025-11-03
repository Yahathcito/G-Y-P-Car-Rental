#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BitacoraEstadosDelCarro
{
private: 
	
	string estadoAnterior;
	string estadoNuevo;
	string colaboradorId;
	string fecha;
public:
	BitacoraEstadosDelCarro(string, string, string, string);
	string getEstadoAnterior();
	string getEstadoNuevo();
	string getColaboradorId();
	string getFecha();
	string toString();
};
