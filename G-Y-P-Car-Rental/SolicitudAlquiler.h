#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class SolicitudAlquiler
{private : 
	string idSolicitud;
	string idCliente;
	string idColaborador;
	int canDiasAlquiler;
	string fechaInicioAlquiler;
	string fechaFinAlquiler;
	float precioAlquiler;
	string estadoSolicitud[4];
public:
	SolicitudAlquiler(string, string, string, int, string, string, float, string[]);
	string getIdSolicitud();
	string getIdCliente();
	string getIdColaborador();
	int getCanDiasAlquiler();
	string getFechaInicioAlquiler();
	string getFechaFinAlquiler();
	float getPrecioAlquiler();
	string* getEstadoSolicitud();
	string toString();




};

