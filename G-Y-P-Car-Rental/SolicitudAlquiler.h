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
	string placaVehiculo;
	int canDiasAlquiler;
	string fechaInicioAlquiler;
	string fechaFinAlquiler;
	float precioAlquiler;
	float precioDias;
	string estadoSolicitud[4];
public:

	SolicitudAlquiler(string, string, string, string, int, string, string, float, float, string[]);

	string getIdSolicitud();
	string getIdCliente();
	string getIdColaborador();
	int getCanDiasAlquiler();
	string getFechaInicioAlquiler();
	string getFechaFinAlquiler();
	float getPrecioAlquiler();
	float getPrecioDias();
	string getPlacaVehiculo();

	string* getEstadoSolicitud();
	string toString();
	void setEstadoSolicitud(int, string);




};

