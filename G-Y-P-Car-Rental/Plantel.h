#pragma once
#include <iostream>	
#include <string>
#include <sstream>
#include "EspacioEstacionamiento.h"
using namespace std;

class Plantel
{
	private :
		string id;
		int filas; 
		int columnas;
		EspacioEstacionamiento*** espacio; 
public:
	Plantel(string,int,int);
		string getId();
		int getCapacidadMaxima();
		string* getTipoVehiculo();
		string toString();
};

