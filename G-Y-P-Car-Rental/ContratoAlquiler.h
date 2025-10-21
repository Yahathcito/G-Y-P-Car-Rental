#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ContratoAlquiler
{
	

	private:
		string idContrato;
		string idSolicitud;
		string idCliente;
		string idColaborador;
		string placaVehiculo;
		string fechaInicio;
		string fechaEntrega;
		int dias;
		float precioDiario;
		float precioTotal;
		string estadoContrato[3]; 
public:
	ContratoAlquiler();
	ContratoAlquiler(string idContrato, string idCliente, string idColaborador, string placaVehiculo, string fechaInicio, string fechaEntrega, int dias, float precioDiario, float precioTotal, string estadoContrato[]);
	string getIdContrato();
		string getIdSolicitud();
		string getIdCliente();
		string getIdColaborador();
		string getPlacaVehiculo();
		string getFechaInicio();
		string getFechaEntrega();
		int getDias();
		float getPrecioDiario();
		float getPrecioTotal();
		string* getEstadoContrato();
		string toString();
};

