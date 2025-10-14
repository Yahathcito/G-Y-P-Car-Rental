#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Colaborador
{
	private: 
		string id;
		string nombre;
		string fechaIngreso;
	public:
		Colaborador(string id, string nombre, string fechaIngreso);
		string getId();
		string getNombre();
		string getFechaIngreso();
		string toString();
};

