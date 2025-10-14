#pragma once
#include "Plantel.h"
class NodoPlantel{
	private: 
		Plantel* plantel; 
		NodoPlantel* siguiente; 
	public: 
		NodoPlantel(Plantel*,NodoPlantel*); 
		virtual ~NodoPlantel(); 
		Plantel* getPlantel(); 
		NodoPlantel* getSiguiente(); 
		void setPlantel(Plantel*); 
		void setSiguiente(NodoPlantel*); 
};

