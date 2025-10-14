#pragma once
#include <iostream>	
#include <string>
#include <sstream>
using namespace std;

class Plantel
{
	private :
		string id;
		int capacidadMaxima;
		string tipoVehiculo[4];

public:
	Plantel(string, int, string[]);
		string getId();
		int getCapacidadMaxima();
		string* getTipoVehiculo();
		string toString();
};

