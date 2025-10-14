#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "Carro.h"
class EspacioEstacionamiento{
private:
	string idEspacio;
	bool disponible;
	Carro* carroEstacionado; 
public:
	EspacioEstacionamiento(string);
	virtual ~EspacioEstacionamiento(); 
	string getIdEspacio();
	bool isDisponible();
	void setDisponible(bool);
	bool estacionarCarro(Carro*);
	string toString();

};

