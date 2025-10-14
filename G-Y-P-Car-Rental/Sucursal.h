#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Sucursal
{
private:
	string numUnicoSucursal;
	string provincia;


public:
	Sucursal(string, string);
	string toString();
};

