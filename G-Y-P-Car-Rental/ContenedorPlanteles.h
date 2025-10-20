#pragma once
#include "NodoPlantel.h"
class ContenedorPlanteles{
	private: 
		NodoPlantel* ppio; 
	public:
		ContenedorPlanteles(); 
		virtual ~ContenedorPlanteles(); 
		bool agregarPlantel(Plantel*);
		bool estaVacio(); 
		Plantel* buscarPlantel(char);
		string mostrarCarrosXPlantel(); 
		bool validarPlantel(char); 
		string toString(); 
};

