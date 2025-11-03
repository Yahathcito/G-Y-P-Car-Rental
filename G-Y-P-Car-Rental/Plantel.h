#pragma once
#include <iostream>	
#include <string>
#include <sstream>
#include "EspacioEstacionamiento.h"
using namespace std;

class Plantel
{
	private :
		char id;
		int filas; 
		int columnas;
		EspacioEstacionamiento*** espacio; 
public:
	Plantel(char,int,int);
	virtual ~Plantel(); 
		char getId();
		int getCapacidadMaxima();
		EspacioEstacionamiento* buscarEspacio(string); 
		bool eliminarCarro(string); 
		string mostrarCarrosXPlantel();  
		Carro* getCarro(string); 
		bool existenCarros(); 
		string mostrarEspacioEspecifico(string);
		string recomendarEspacios(); 
		float calcularPorcentajeOcupacion();
		string toString();
};

