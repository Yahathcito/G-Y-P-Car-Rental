#pragma once
#include <string>
#include <sstream>
using namespace std; 
class Cliente{
	private: 
		string nombre; 
		string id; 
		string paisResidencia; 
	public:
		Cliente(string, string, string); 
		void setNombre(string); 
		void setId(string); 
		void setPaisResidencia(string); 
		string getNombre(); 
		string getId(); 
		string getPaisResidencia(); 
		virtual string getTipo() = 0; 
		virtual string toString() = 0; 
};

