#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ContenedorCarros.h"
#include "ContenedorClientes.h"
#include "ContenedorColaboradores.h"
#include "ContenedorPlanteles.h"
#include "ContenedorContratoAlquiler.h"
#include "ContenedorSolicitudAlquiler.h"
using namespace std;

class Sucursal{
private:
	string numUnicoSucursal;
	string provincia;
	ContenedorCarros* contenedorCarros;
	ContenedorClientes* contenedorClientes;
	ContenedorColaboradores* contenedorColaboradores;
	ContenedorPlanteles* contenedorPlanteles;
	ContenedorContratoAlquiler* contenedorContratoAlquiler;
	ContenedorSolicitudAlquiler* contenedorSolicitudAlquiler;

public:
	Sucursal(string, string);
	virtual ~Sucursal(); 
	ContenedorCarros* getContenedorCarros();
	ContenedorClientes* getContenedorClientes();
	ContenedorColaboradores* getContenedorColaboradores();
	ContenedorPlanteles* getContenedorPlanteles();
	ContenedorContratoAlquiler* getContenedorContratoAlquiler();
	ContenedorSolicitudAlquiler* getContenedorSolicitudAlquiler();
	string getNumUnico();
	string mostrarVehiculos(); 
	string mostrarPlantelesDisponibles(); 
	Plantel* getPlantel(char); 
	bool validarPlantel(char); 
	bool NoexistePlantel(); 
	void intercambiarCarro(Plantel*,string,Carro* ,EspacioEstacionamiento* );
	string toString();
};

