#pragma once
#include <iostream>
#include <string>
#include "ContenedorSucursal.h"
#include "ClienteNormal.h"
#include"ClienteJuridico.h"
using namespace std;

class InterfazUsuario {
private:
    //  Único contenedor global del sistema
    static ContenedorSucursal* contenedorSucursales;
	

public:
    //  Menú principal
    static void menuPrincipal();

    // ============================
    //  Datos Generales
    // ============================
    static void menuDatosGenerales();
    static void menuSucursales();
    static void menuClientes();
    static void menuColaboradores();

    // ============================
    // Planteles y Vehículos
    // ============================
    static void menuPlantelesVehiculos();

    // ============================
    //  Solicitudes y Contratos
    // ============================
    static void menuSolicitudesContratos();

    // ============================
    //  Reportes
    // ============================
    static void menuReportesClientes();
    static void menuReportesPlantelesAlquileres();
};

