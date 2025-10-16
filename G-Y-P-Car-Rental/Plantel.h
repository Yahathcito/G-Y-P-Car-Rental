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
	virtual ~Plantel(); 
		string getId();
		int getCapacidadMaxima();
		EspacioEstacionamiento* buscarEspacio(string); 
		string toString();
};

