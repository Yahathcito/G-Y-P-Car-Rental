#pragma once
#include <iostream>
#include <string>
#include "ContenedorSucursal.h"
using namespace std;

class InterfazUsuario {
private:
    // ⚙️ Único contenedor global del sistema
    static ContenedorSucursal* contenedorSucursales;

public:
    // 🚀 Menú principal
    static void menuPrincipal();

    // ============================
    // 1️⃣ Datos Generales
    // ============================
    static void menuDatosGenerales();
    static void menuSucursales();
    static void menuClientes();
    static void menuColaboradores();

    // ============================
    // 2️⃣ Planteles y Vehículos
    // ============================
    static void menuPlantelesVehiculos();

    // ============================
    // 3️⃣ Solicitudes y Contratos
    // ============================
    static void menuSolicitudesContratos();

    // ============================
    // 4️⃣ Reportes
    // ============================
    static void menuReportesClientes();
    static void menuReportesPlantelesAlquileres();
};

