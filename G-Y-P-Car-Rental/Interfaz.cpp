#include "Interfaz.h"
#include <cstdlib>

// =====================================================
//  Inicialización del contenedor raíz
// =====================================================
ContenedorSucursal* InterfazUsuario::contenedorSucursales = new ContenedorSucursal();

// =====================================================
//  MENÚ PRINCIPAL
// =====================================================
void InterfazUsuario::menuPrincipal() {
    int opcion;
    do {
        system("cls");
        cout << "=============================================\n";
        cout << "     SISTEMA D-R-T CAR RENTAL - MENÚ PRINCIPAL\n";
        cout << "=============================================\n";
        cout << "1. Datos Generales\n";
        cout << "2. Planteles, Parqueos y Vehículos\n";
        cout << "3. Solicitudes y Contratos\n";
        cout << "4. Reportes de Clientes\n";
        cout << "5. Reportes de Planteles y Alquileres\n";
        cout << "0. Salir\n";
        cout << "---------------------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuDatosGenerales(); break;
        case 2: menuPlantelesVehiculos(); break;
        case 3: menuSolicitudesContratos(); break;
        case 4: menuReportesClientes(); break;
        case 5: menuReportesPlantelesAlquileres(); break;
        case 0: cout << "\nSaliendo del sistema...\n"; break;
        default: cout << "\nOpción inválida.\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  DATOS GENERALES
// =====================================================
void InterfazUsuario::menuDatosGenerales() {
    int opcion;
    do {
        system("cls");
        cout << "=============================================\n";
        cout << "        MÓDULO: DATOS GENERALES\n";
        cout << "=============================================\n";
        cout << "1. Gestionar Sucursales\n";
        cout << "2. Gestionar Clientes\n";
        cout << "3. Gestionar Colaboradores\n";
        cout << "0. Volver al menú principal\n";
        cout << "---------------------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuSucursales(); break;
        case 2: menuClientes(); break;
        case 3: menuColaboradores(); break;
        case 0: break;
        default: cout << "\nOpción inválida.\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  Sucursales
// =====================================================
void InterfazUsuario::menuSucursales() {
    int opcion;
    do {
        system("cls");
        cout << "-------- Gestión de Sucursales --------\n";
        cout << "1. Registrar nueva sucursal\n";
        cout << "2. Eliminar sucursal\n";
        cout << "3. Mostrar todas las sucursales\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Ejemplo:
            // contenedorSucursales->registrarSucursal();
            break;
        case 2:
            // contenedorSucursales->eliminarSucursal();
            break;
        case 3:
            // contenedorSucursales->mostrarSucursales();
            break;
        case 0: break;
        default: cout << "Opción inválida\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  Clientes
// =====================================================
void InterfazUsuario::menuClientes() {
    int opcion;
    do {
        system("cls");
        cout << "-------- Gestión de Clientes --------\n";
        cout << "1. Registrar cliente normal\n";
        cout << "2. Registrar cliente jurídico\n";
        cout << "3. Eliminar cliente\n";
        cout << "4. Mostrar todos los clientes\n";
        cout << "0. Volver\n";
        cout << "-------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // contenedorSucursales->getSucursalActual()->getContenedorClientes()->agregarClienteNormal();
            break;
        case 2:
            // contenedorSucursales->getSucursalActual()->getContenedorClientes()->agregarClienteJuridico();
            break;
        case 3:
            // contenedorSucursales->getSucursalActual()->getContenedorClientes()->eliminarCliente();
            break;
        case 4:
            // contenedorSucursales->getSucursalActual()->getContenedorClientes()->mostrarClientes();
            break;
        case 0: break;
        default: cout << "Opción inválida\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  Colaboradores
// =====================================================
void InterfazUsuario::menuColaboradores() {
    int opcion;
    do {
        system("cls");
        cout << "-------- Gestión de Colaboradores --------\n";
        cout << "1. Registrar colaborador\n";
        cout << "2. Eliminar colaborador\n";
        cout << "3. Mostrar colaboradores\n";
        cout << "0. Volver\n";
        cout << "------------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // contenedorSucursales->getSucursalActual()->getContenedorColaboradores()->agregarColaborador();
            break;
        case 2:
            // contenedorSucursales->getSucursalActual()->getContenedorColaboradores()->eliminarColaborador();
            break;
        case 3:
            // contenedorSucursales->getSucursalActual()->getContenedorColaboradores()->mostrarColaboradores();
            break;
        case 0: break;
        default: cout << "Opción inválida\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  PLANTELES Y VEHÍCULOS
// =====================================================
void InterfazUsuario::menuPlantelesVehiculos() {
    int opcion;
    do {
        system("cls");
        cout << "=============================================\n";
        cout << "     MÓDULO: PLANTELES, PARQUEOS Y VEHÍCULOS\n";
        cout << "=============================================\n";
        cout << "1. Crear plantel en sucursal\n";
        cout << "2. Mostrar distribución de espacios\n";
        cout << "3. Ingresar nuevo vehículo\n";
        cout << "4. Eliminar vehículo\n";
        cout << "5. Cambiar estado de vehículo\n";
        cout << "6. Reubicar vehículo dentro de la sucursal\n";
        cout << "0. Volver al menú principal\n";
        cout << "---------------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->crearPlantel();
            break;
        case 2:
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->mostrarDistribucion();
            break;
        case 3:
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->registrarVehiculo();
            break;
        case 4:
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->eliminarVehiculo();
            break;
        case 5:
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->cambiarEstadoVehiculo();
            break;
        case 6:
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->reubicarVehiculo();
            break;
        case 0: break;
        default: cout << "Opción inválida\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  SOLICITUDES Y CONTRATOS
// =====================================================
void InterfazUsuario::menuSolicitudesContratos() {
    int opcion;
    do {
        system("cls");
        cout << "=============================================\n";
        cout << "       MÓDULO: SOLICITUDES Y CONTRATOS\n";
        cout << "=============================================\n";
        cout << "1. Crear solicitud de alquiler\n";
        cout << "2. Mostrar solicitudes\n";
        cout << "3. Aprobar o rechazar solicitud\n";
        cout << "4. Crear contrato (desde solicitud aprobada)\n";
        cout << "5. Finalizar contrato (devolución de vehículo)\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // contenedorSucursales->getSucursalActual()->getContenedorSolicitudes()->crearSolicitud();
            break;
        case 2:
            // contenedorSucursales->getSucursalActual()->getContenedorSolicitudes()->mostrarSolicitudes();
            break;
        case 3:
            // contenedorSucursales->getSucursalActual()->getContenedorSolicitudes()->aprobarRechazarSolicitud();
            break;
        case 4:
            // contenedorSucursales->getSucursalActual()->getContenedorContratos()->crearContrato();
            break;
        case 5:
            // contenedorSucursales->getSucursalActual()->getContenedorContratos()->finalizarContrato();
            break;
        case 0: break;
        default: cout << "Opción inválida\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  REPORTES DE CLIENTES
// =====================================================
void InterfazUsuario::menuReportesClientes() {
    int opcion;
    do {
        system("cls");
        cout << "=============================================\n";
        cout << "           MÓDULO: REPORTES DE CLIENTES\n";
        cout << "=============================================\n";
        cout << "1. Historial de cliente (solicitudes y contratos)\n";
        cout << "2. Reporte de clientes por cantidad de contratos\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // contenedorSucursales->getSucursalActual()->reporteHistorialCliente();
            break;
        case 2:
            // contenedorSucursales->getSucursalActual()->reporteClientesPorContratos();
            break;
        case 0: break;
        default: cout << "Opción inválida\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  REPORTES DE PLANTELES Y ALQUILERES
// =====================================================
void InterfazUsuario::menuReportesPlantelesAlquileres() {
    int opcion;
    do {
        system("cls");
        cout << "=============================================\n";
        cout << "   MÓDULO: REPORTES DE PLANTELES Y ALQUILERES\n";
        cout << "=============================================\n";
        cout << "1. Bitácora de estados de un vehículo\n";
        cout << "2. Contratos de un vehículo específico\n";
        cout << "3. Porcentaje de ocupación de planteles\n";
        cout << "4. Contratos por sucursal (recientes primero)\n";
        cout << "5. Reporte de alquileres por colaborador\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // contenedorSucursales->getSucursalActual()->bitacoraVehiculo();
            break;
        case 2:
            // contenedorSucursales->getSucursalActual()->contratosPorVehiculo();
            break;
        case 3:
            // contenedorSucursales->getSucursalActual()->porcentajeOcupacion();
            break;
        case 4:
            // contenedorSucursales->contratosPorSucursal();
            break;
        case 5:
            // contenedorSucursales->reporteAlquileresPorColaborador();
            break;
        case 0: break;
        default: cout << "Opción inválida\n"; system("pause");
        }
    } while (opcion != 0);
}

