#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class EspacioEstacionamiento{
private:
	string idEspacio;
	bool disponible;
public:
	EspacioEstacionamiento(string idEspacio);
	string getIdEspacio();
	bool isDisponible();
	void setDisponible(bool disponible);
	string toString();

};

