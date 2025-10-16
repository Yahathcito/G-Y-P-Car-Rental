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
        cout << "0. Volver al menu principal\n";
        cout << "---------------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuSucursales(); break;
        case 2: menuClientes(); break;
        case 3: menuColaboradores(); break;
        case 0: break;
        default: cout << "\nOpción invalida.\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  Sucursales
// =====================================================
void InterfazUsuario::menuSucursales() {
    int opcion;
    string codigo, provincia;
    do {
        system("cls");
        cout << "-------- Gestion de Sucursales --------\n";
        cout << "1. Registrar nueva sucursal\n";
        cout << "2. Eliminar sucursal\n";
        cout << "3. Mostrar todas las sucursales\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
        case 1: {
            cout << "Ingrese el codigo unico de la sucursal: "; cin >> codigo;
            cout << "Ingrese la provincia de la sucursal: "; cin >> provincia;
            if (!contenedorSucursales->validarSucursal(codigo)) {
                cout << "Error: Ya existe una sucursal con ese codigo.\n";
                system("pause");
                break;
            }
            Sucursal* nuevaSucursal = new Sucursal(codigo, provincia);
            contenedorSucursales->agregarSucursal(nuevaSucursal);
            cout << "Sucursal agregada exitosamente!\n"; 
            system("pause");
            break;

        }
        case 2: {
            cout << "Ingrese el codigo de la sucursal que desea eliminar: "; cin >> codigo; 
            if (contenedorSucursales->validarSucursal(codigo)) {
                cout << "Error: No existe una sucursal con este codigo.\n";
                system("pause");
                break;
            }
            contenedorSucursales->eliminarSucursal(codigo); 
            cout << "Sucursal eliminada exitosamente!\n";
            system("pause");
            break;
        }
        case 3: {
            cout << "===== LISTA DE SUCURSALES =====\n"; 
            cout << contenedorSucursales->toString(); 
            system("pause");
            break;
        }
        case 0: break;
        default: cout << "Opción invalida\n"; system("pause");
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
        default: cout << "Opción invalida\n"; system("pause");
        }
    } while (opcion != 0);
}

// =====================================================
//  PLANTELES Y VEHÍCULOS
// =====================================================
void InterfazUsuario::menuPlantelesVehiculos() {
    Plantel* plantel = nullptr; 
    Carro* carro = nullptr;
	EspacioEstacionamiento* espacio = nullptr;
    int opcion,filas,columnas,modelo,tipoOpcion;
    string codigo,codigoPlantel,placa, marca;
    string tipo[4] = { "Economico","Estandar","Lujo","4x4" };
    cout << "Ingrese el codigo de la sucursal en la que desea ingresar: "; cin >> codigo; 
    Sucursal* sucursal = contenedorSucursales->buscarSucursal(codigo); 
    if (!sucursal) {
        cout << "El codigo ingresado no pertenece a ninguna sucursal.\n"; 
        system("pause"); 
        return; 
    }
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
        case 1: {
            cout << "Ingrese la letra que va a identificar su plantel: "; cin >> codigoPlantel; 
            cout << "Ingrese la cantidad de filas que desea en su plantel: "; cin >> filas; 
            cout << "Ingrese la cantidad de columnas que desea en su plantel: "; cin >> columnas;
            plantel = new Plantel(codigoPlantel, filas, columnas); 
            sucursal->getContenedorPlanteles()->agregarPlantel(plantel); 
            cout << "---Plantel creado exitosamente---" << endl; 
            system("pause");
            break;
        }
        case 2: {
            cout << "PLANTELES DE LA SUCURSAL = " << sucursal->getNumUnico() << " =\n"; 
            cout << sucursal->getContenedorPlanteles()->toString(); 
            system("pause");
            break;
        }
        case 3: {
			/*cout << "Ingrese la placa del vehiculo: "; cin >> placa;
			cout << "Ingrese el modelo del vehiculo: "; cin >> modelo;
			cout << "Ingrese la marca del vehiculo: "; cin >> marca;
			cout << sucursal->getContenedorCarros()->mostrarTipoDeCarros();
			cout << "Ingrese el tipo de vehiculo (numero): "; cin >> tipoOpcion;
			if (tipoOpcion < 1 || tipoOpcion > 4) {
				cout << "Tipo de vehiculo invalido.\n";
				system("pause");
				break;
			}
			carro = new Carro(placa, modelo, marca, tipo[tipoOpcion - 1]);
			if (!sucursal->getContenedorCarros()->agregarCarro(carro)) {
				cout << "Error: Ya existe un vehiculo con esa placa.\n";
				system("pause");
				break;
			}
			cout << "Vehiculo agregado exitosamente!\n";
            //ahora vamos a estacionar el vehiculo en un plantel y en un espacio que seleccione el usuario 
			if (!sucursal->getContenedorPlanteles()->estaVacio()) {
				cout << "Ingrese el ID del plantel donde desea estacionar el vehículo: "; cin >> codigoPlantel;
				plantel = sucursal->getContenedorPlanteles()->buscarPlantel(codigoPlantel);
				if (!plantel) {
					cout << "Error: No existe un plantel con ese ID.\n";
					system("pause");
					break;
				}
				cout << plantel->toString();
				cout << "Ingrese el ID del espacio donde desea estacionar el vehículo: "; cin >> codigoPlantel;
				espacio = plantel->buscarEspacio(codigo);
				if (!espacio) {
					cout << "Error: No existe un espacio con ese ID.\n";
					system("pause");
					break;
				}
				if (!espacio->estacionarCarro(carro)) {
					cout << "Error: El espacio no está disponible.\n";
					system("pause");
					break;
				}
				cout << "Vehículo estacionado exitosamente en el espacio " << espacio->getIdEspacio() << " del plantel " << plantel->getId() << ".\n";
			}
			else {
				cout << "No hay planteles disponibles en esta sucursal. Por favor, cree un plantel primero.\n";
			}

            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->registrarVehiculo();
            system("pause");*/
            break;
        }
        case 4: {
			cout << "Ingrese la placa del vehículo que desea eliminar: "; cin >> placa;
			if (!sucursal->getContenedorCarros()->eliminarCarro(placa)) {
				cout << "Error: No existe un vehículo con esa placa.\n";
				system("pause");
				break;
			}
			cout << "Vehículo eliminado exitosamente!\n";
            system("pause");
            break;
        }
        case 5: {
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->cambiarEstadoVehiculo();
            system("pause");
            break;
        }
        case 6: {
            // contenedorSucursales->getSucursalActual()->getContenedorPlanteles()->reubicarVehiculo();
            system("pause");
            break;
        }
        case 0: break;
        default: cout << "Opción invalida\n"; system("pause");
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

