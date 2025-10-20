#include "Interfaz.h"


// =====================================================
//  Inicialización del contenedor raíz
// =====================================================
ContenedorSucursal* InterfazUsuario::contenedorSucursales = new ContenedorSucursal();

// =====================================================
//  MENÚ PRINCIPAL
// =====================================================
void InterfazUsuario::menuPrincipal() {
    int opcion;
    if (!contenedorSucursales) {
        contenedorSucursales = new ContenedorSucursal();
	}


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
    string nombre, id, pais, codigo, actividadEconomica;
	Cliente* cliente = nullptr;
	Sucursal* sucursalActual = nullptr;
    
    do {
        system("cls");
        cout << "-------- Gestión de Clientes --------\n";
        cout << "1. Registrar cliente normal\n";
        cout << "2. Registrar cliente juridico\n";
        cout << "3. Eliminar cliente\n";
        cout << "4. Mostrar todos los clientes\n";
        cout << "0. Volver\n";
        cout << "-------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            
			
			do {
				system("cls");
                if (!contenedorSucursales || contenedorSucursales->estaVacio()) {
                    cout << "No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
                    system("pause");
					break; // Salir del bucle do-while y volver al menú principal
                }
				cout << "Ingrese el codigo de la sucursal donde desea registrar el cliente: "; cin >> codigo;
				sucursalActual = contenedorSucursales->buscarSucursal(codigo);
                if (!sucursalActual) {
                    cout << "Sucursal no encontrada. Asegurese de ingresar un codigo valido." << endl;
                    system("pause");
					continue; // Volver al inicio del bucle para intentar de nuevo
                }

				cout << "Ingrese el ID del cliente: "; cin >> id;
				if (sucursalActual->getContenedorClientes()->getClienteXId(id)) {
					cout << "Error: Ya existe un cliente con esa ID.\n";
					system("pause");
					continue; // Volver al inicio del bucle para intentar de nuevo
				}
				cin.ignore(); // Limpiar el buffer de entrada
				/*cout << "Ingrese el nombre del cliente: "; getline(cin, nombre);
				cout << "Ingrese el país de residencia del cliente: "; cin >> pais;*/
				nombre = "Cliente1";
				pais = "CostaRica";

				
				cliente = new ClienteNormal(nombre, id, pais);
				sucursalActual->getContenedorClientes()->ingresarCliente(cliente);
				cout << "Cliente agregado exitosamente!" << endl;
				cout << "Desea ingresar otro cliente? (s/n): ";
				char seguir;
				cin >> seguir;
				if (seguir != 's' && seguir != 'S') {
					break;
				}
			} while (true);
            system("pause");
			break;


        case 2:
			//Registar Cliente Juridico
			do {
				system("cls");
				if (!contenedorSucursales || contenedorSucursales->estaVacio()) {
					cout << "No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
					system("pause");
					break; // Salir del bucle do-while y volver al menú principal
				}
				cout << "Ingrese el codigo de la sucursal donde desea registrar el cliente: "; cin >> codigo;
				sucursalActual = contenedorSucursales->buscarSucursal(codigo);
				if (!sucursalActual) {
					cout << "Sucursal no encontrada. Asegurese de ingresar un codigo valido." << endl;
					system("pause");
					continue; // Volver al inicio del bucle para intentar de nuevo
				}
				cout << "Ingrese el ID del cliente: "; cin >> id;
				if (sucursalActual->getContenedorClientes()->getClienteXId(id)) {
					cout << "Error: Ya existe un cliente con esa ID.\n";
					system("pause");
					continue; // Volver al inicio del bucle para intentar de nuevo
				}
				cin.ignore(); 

				/*cout << "Ingrese el nombre del cliente: "; getline(cin, nombre);
               cout << "Ingrese el país de residencia del cliente: "; cin >> pais;
               cout << "Ingrese la actividad economica del cliente: "; cin >> actividadEconomica;
               cliente = new ClienteJuridico(nombre, id, pais, actividadEconomica);*/
	
                cliente = new ClienteJuridico("Roberto", id, "Costa Rica", "Panadero");
				sucursalActual->getContenedorClientes()->ingresarCliente(cliente);
				cout << "Cliente agregado exitosamente!" << endl;
				cout << "Desea ingresar otro cliente? (s/n): ";
				char seguir;
				cin >> seguir;
				if (seguir != 's' && seguir != 'S') {
                    break;
				}
			} while (true);
			system("pause");
           

            break;
        case 3:
			// eliminar cliente
			cout << "Ingrese el codigo de la sucursal donde desea eliminar el cliente: "; cin >> codigo;
			sucursalActual = contenedorSucursales->buscarSucursal(codigo);
			if (!sucursalActual) {
				cout << "Sucursal no encontrada. Asegurese de ingresar un codigo valido." << endl;
				system("pause");
				break; // Salir del bucle do-while y volver al menú principal
			}
			cout << "Ingrese el ID del cliente que desea eliminar: "; cin >> id;
            if (!sucursalActual->getContenedorClientes()->getClienteXId(id)) {
                cout << "Error: No existe un cliente con esa ID.\n";
                system("pause");
            }
            else {
                sucursalActual->getContenedorClientes()->eliminarCliente(id);
                cout << "Cliente eliminado exitosamente!\n";
                system("pause");
			}

            break;
        case 4:
			// mostrar clientes
			cout << "Ingrese el codigo de la sucursal cuyos clientes desea ver: "; cin >> codigo;
			sucursalActual = contenedorSucursales->buscarSucursal(codigo);
			if (!sucursalActual) {
				cout << "Sucursal no encontrada. Asegurese de ingresar un codigo valido." << endl;
				system("pause");
				break; // Salir del bucle do-while y volver al menú principal
			}
			cout << "===== LISTA DE CLIENTES =====\n";
			cout << sucursalActual->getContenedorClientes()->toString();
			system("pause");

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
	string nombre, id, codigo, fechaIngreso;
   
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

            do
            {
				system("cls");
                if (!contenedorSucursales || contenedorSucursales->estaVacio()) {
                    cout << "No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
                    system("pause");
                    break; // Salir del bucle do-while y volver al menú principal
                }
				cout << "Ingrese el codigo de la sucursal donde desea registrar el colaborador: "; cin >> codigo;
                Sucursal* sucursalActual = contenedorSucursales->buscarSucursal(codigo);
                if (!sucursalActual) {
                    cout << "Sucursal no encontrada. Asegurese de ingresar un codigo valido." << endl;
                    system("pause");
                    continue; // Volver al inicio del bucle para intentar de nuevo
				}
				cout << "Ingrese el nombre del colaborador: "; cin >> nombre;
				cout << "Ingrese el ID del colaborador: "; cin >> id;
				cout << "Ingrese la fecha de ingreso del colaborador (DD/MM/AAAA): "; cin >> fechaIngreso;

                if (sucursalActual->getContenedorColaboradores()->buscarColaborador(id)) {
                    cout << "Error: Ya existe un colaborador con esa ID.\n";
                    system("pause");
                    continue; // Volver al inicio del bucle para intentar de nuevo
				}
				Colaborador* colaborador = new Colaborador(nombre, id, fechaIngreso);
				sucursalActual->getContenedorColaboradores()->agregarColaborador(colaborador);
				cout << "Colaborador agregado exitosamente!" << endl;
				system("pause");
                cout << "Desea ingresar otro colaborador? (s/n): ";
                char seguir;
                cin >> seguir;
                if (seguir != 's' && seguir != 'S') {
                    break;
				}

            } while (true);
            break;
        case 2:
			//eliminar colaborador
            do
            {
                system("cls");
                if (!contenedorSucursales || contenedorSucursales->estaVacio()) {
                    cout << "No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
                    system("pause");
                    break; // Salir del bucle do-while y volver al menú principal
				}
                cout << "Ingrese el codigo de la sucursal donde desea eliminar el colaborador: "; cin >> codigo;
                Sucursal* sucursalActual = contenedorSucursales->buscarSucursal(codigo);
                if (!sucursalActual) {
                    cout << "Sucursal no encontrada. Asegurese de ingresar un codigo valido." << endl;
                    system("pause");
					continue; // Volver al inicio del bucle para intentar de nuevo
                    }
                cout << "Ingrese el ID del colaborador que desea eliminar: "; cin >> id;
                if (!sucursalActual->getContenedorColaboradores()->buscarColaborador(id)) {
                    cout << "Error: No existe un colaborador con esa ID.\n";
                    system("pause");
                }
                else {
                    sucursalActual->getContenedorColaboradores()->eliminarColaborador(id);
                    cout << "Colaborador eliminado exitosamente!\n";
					system("pause");

                    }
                cout << "Desea eliminar otro colaborador? (s/n): ";
                char seguir;
                cin >> seguir;
                if (seguir != 's' && seguir != 'S') {
                    break;
                }


            } while (true);
            break;
        case 3:
			// mostrar colaboradores
            do
            {
				system("cls");
                if (!contenedorSucursales || contenedorSucursales->estaVacio()) {
                    cout << "No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
                    system("pause");
                    break; // Salir del bucle do-while y volver al menú principal
                }
                cout << "Ingrese el codigo de la sucursal cuyos colaboradores desea ver: "; cin >> codigo;
                Sucursal* sucursalActual = contenedorSucursales->buscarSucursal(codigo);
                if (!sucursalActual) {
                    cout << "Sucursal no encontrada. Asegurese de ingresar un codigo valido." << endl;
                    system("pause");
                    continue; // Volver al inicio del bucle para intentar de nuevo
                }
                cout << "===== LISTA DE COLABORADORES =====\n";
                cout << sucursalActual->getContenedorColaboradores()->toString();
                system("pause");
                cout << "Desea ver los colaboradores de otra sucursal? (s/n): ";
                char seguir;
                cin >> seguir;
                if (seguir != 's' && seguir != 'S') {
                    break;
				}


            } while (true);
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
    //Plantel* plantel = nullptr; 
    Carro* carro = nullptr;
	EspacioEstacionamiento* espacio = nullptr;
    int opcion,filas,columnas,modelo,tipoOpcion;
    char codigoPlantel,codigoPlantelIntercambio;
    string codigo,placa, marca,codigoEspacio,licenciaRequerida,codigoIntercambio;
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
        cout << "2. Mostrar distribucion de espacios\n";
        cout << "3. Ingresar nuevo vehículo\n";
        cout << "4. Eliminar vehiculo\n";
        cout << "5. Cambiar estado de vehiculo\n";
        cout << "6. Reubicar vehiculo dentro de la sucursal\n";
        cout << "7. Mostrar vehiculos de la sucursal\n";
        cout << "8. Interacmbiar vehiculo entre sucursales\n";
        cout << "0. Volver al menu principal\n";
        cout << "---------------------------------------------\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Ingrese la letra que va a identificar su plantel: "; cin >> codigoPlantel; 
            cout << "Ingrese la cantidad de filas que desea en su plantel: "; cin >> filas; 
            cout << "Ingrese la cantidad de columnas que desea en su plantel: "; cin >> columnas; 
            Plantel* plantel = new Plantel(codigoPlantel, filas, columnas);
            sucursal->getContenedorPlanteles()->agregarPlantel(plantel);
            cout << "---Plantel creado exitosamente---" << endl; 
            system("pause");
            break;
        }
        case 2: {
            int opcAux; 
            cout << "1- Visualizar un campo especifico de un plantel.\n";
            cout << "2- Visualizar SOLO la distribucion de los planteles,\n";
            cout << "3- Salir.\n";
            cout << "Digite la opcion deseada: "; cin >> opcAux;
            {
                switch (opcAux) {
                case 1: {
                    cout << "PLANTELES DE LA SUCURSAL = " << sucursal->getNumUnico() << " =\n";
                    cout << sucursal->getContenedorPlanteles()->toString();
                    cout << "Digite el Id del plantel deseado: "; cin >> codigoPlantel;
                    Plantel* plantel = sucursal->getPlantel(codigoPlantel);
                    system("cls");
                    cout << plantel->toString();
                    cout << "Digite el espacio que desea visualizar: "; cin >> codigoEspacio;
                    cout << plantel->mostrarEspacioEspecifico(codigoEspacio);
                    break;
                }
                case 2: {
                    cout << "PLANTELES DE LA SUCURSAL = " << sucursal->getNumUnico() << " =\n";
                    cout << sucursal->getContenedorPlanteles()->toString();
                    break;
                }
                case 3: {
                    cout << "Saliendo...\n";
                    break;
                }
                default:
                    break;
                }
            }
            system("pause");
            break;
        }
        case 3: {
            cout << "Ingrese el codigo del plantel para verificar que existe: "; cin >> codigoPlantel; 
            Plantel* p = sucursal->getContenedorPlanteles()->buscarPlantel(codigoPlantel); 
            if (!p) {
                cout << "Plantel no existente en la sucursal." << endl; 
                break; 
            }
			cout << "Ingrese la placa del vehiculo: "; cin >> placa;
			cout << "Ingrese el modelo del vehiculo (annio): "; cin >> modelo;
			cout << "Ingrese la marca del vehiculo: "; cin >> marca;
			cout <<sucursal->getContenedorCarros()->mostrarTipoDeCarros();
			cout << "Seleccione el tipo de vehiculo (1-4): "; cin >> tipoOpcion;
			if (tipoOpcion < 1 || tipoOpcion > 4) {
				cout << "Error: Opcion de tipo invalida.\n";
                break; 
			}
            cout << "Ingrese el tipo de licencia requerida: "; cin >> licenciaRequerida; 
            carro = new Carro(placa, modelo, marca, tipo[tipoOpcion - 1], licenciaRequerida);
			if (!sucursal->getContenedorCarros()->agregarCarro(carro)) {
				cout << "Error: Ya existe un vehículo con esa placa.\n";
				break;
			}
            if (p->recomendarEspacios() == "Espacios recomendados: ") {
                cout << p->toString();
                cout << "Ingrese el codigo del espacio donde desea estacionar el vehiculo: "; cin >> codigoEspacio;
                espacio = p->buscarEspacio(codigoEspacio);
                if (!espacio->isDisponible()) {
                    cout << "Error: El espacio ya esta ocupado.\n";
                    sucursal->getContenedorCarros()->eliminarCarro(placa);
                    break;
                }
                espacio->estacionarCarro(carro);
                cout << "Vehiculo ingresado y estacionado exitosamente!\n";
                cout << espacio->getCarro()->toString();
                cout << p->toString();
                break; 
            }
            cout << p->recomendarEspacios(); 
            cout << "Ingrese el codigo del espacio donde desea estacionar el vehiculo: "; cin >> codigoEspacio;
            espacio = p->buscarEspacio(codigoEspacio);
            if (!espacio->isDisponible()) {
                cout << "Error: El espacio ya esta ocupado.\n";
                sucursal->getContenedorCarros()->eliminarCarro(placa);
                break;
            }
            espacio->estacionarCarro(carro);
            cout << "Vehiculo ingresado y estacionado exitosamente!\n";
            cout << espacio->getCarro()->toString();
            cout << p->toString();
            system("pause");
            
            break;
        }
        case 4: {
           cout << "Ingrese el plantel donde desea realizar el proceso:"; cin >> codigoPlantel;
            Plantel* plantel = sucursal->getPlantel(codigoPlantel); 
            if (!plantel) {
                cout << "Plantel no existente en la sucursal." << endl;
                break;
            }
            cout << plantel->mostrarCarrosXPlantel(); cout << endl; 
			cout << "Ingrese la placa del vehículo que desea eliminar: "; cin >> placa;
			if (!plantel->eliminarCarro(placa)) {
				cout << "Error: No se puede eliminar un vehiculo 'inexistente' o 'alquilado'.\n";
				system("pause");
				break;
			}
            
            sucursal->getContenedorCarros()->eliminarCarro(placa);
			cout << "Vehiculo eliminado exitosamente!\n";
            system("pause");
            break;
        }
        case 5: {

            // Creo que este case es innceseario y no cumple con el flujo de trabajo 
            system("pause");
            break;
        }
        case 6: {
            cout << "Digite el codigo del plantel actual: "; cin >> codigoPlantel; 
            Plantel* plantel = sucursal->getPlantel(codigoPlantel); 
            if (!sucursal->validarPlantel(codigoPlantel)) {
                cout << "Error: El codigo digitado no coincide.\n";
                system("pause");
                break;
            }
            cout << plantel->mostrarCarrosXPlantel();
            cout << "Digite la placa del carro a reubicar: "; cin >> placa; 
             carro = plantel->getCarro(placa); 
            cout << sucursal->mostrarPlantelesDisponibles(); 
            cout << "Digite el codigo del plantel a reubicar el carro: "; cin >> codigoPlantel; 
            Plantel* plantelReubicar = sucursal->getPlantel(codigoPlantel); 
            if (!sucursal->validarPlantel(codigoPlantel)) {
                cout << "Error: El codigo digitado no coincide.\n";
                break;
            }
            if (plantelReubicar->recomendarEspacios()=="Espacios recomendados: ") {
                cout << plantelReubicar->toString(); 
                cout << "Digite un espacio para estacionar su carro: "; cin >> codigoEspacio; 
                if (plantelReubicar->buscarEspacio(codigoEspacio)) {
                    plantel->eliminarCarro(placa); 
                    plantelReubicar->buscarEspacio(codigoEspacio)->estacionarCarro(carro);
                    cout << "El carro con placa: " << placa << "ha sido reubicado exitosamente." << endl; 
                    break; 
                }
                cout << "Espacio ocupado.\n"; break; 
            }
            cout << plantelReubicar->recomendarEspacios(); 
            cout << "Digite un espacio para estacionar su carro: "; cin >> codigoEspacio;
            if (plantelReubicar->buscarEspacio(codigoEspacio)) {
                plantel->eliminarCarro(placa);
                plantelReubicar->buscarEspacio(codigoEspacio)->estacionarCarro(carro);
                cout << "El carro con placa: " << placa << "ha sido reubicado exitosamente." << endl;
                break;
            }
            cout << "Espacio ocupado.\n";
            system("pause");
            break;
        }
        case 7: {
            cout << sucursal->mostrarVehiculos();
            system("pause");
            break; 
        }
        case 8: {
           /* if (!contenedorSucursales->haySucursalesSuficientes()) {
                cout << "Error: No existen las sucursales suficientes.\n"; 
                break; 
            }
            cout << sucursal->mostrarPlantelesDisponibles(); 
            cout << "Digite el plantel donde desea obtener el carro: "; cin >> codigoPlantel; 
            Plantel* plantelActual = sucursal->getPlantel(codigoPlantel); 
            if (!plantelActual || !plantelActual->existenCarros()) {
                cout << "Error: Plantel o existencia de carros no encontrados.\n";
                break; 
            }
            cout << plantelActual->mostrarCarrosXPlantel(); 
            cout << "Digite la placa del carro que desea intercambiar: "; cin >> placa; 
            carro = plantelActual->getCarro(placa); 
            if (!carro) {
                cout << "Error: La placa digitada no existe.\n"; 
                break; 
            }
            cout << contenedorSucursales->mostrarSucursalesExceptoActual(codigo); 
            cout << "Digite el codigo de la sucursal deseada: "; cin >> codigoIntercambio; 
            Sucursal* sucursalIntercambio = contenedorSucursales->buscarSucursal(codigoIntercambio); 
            if (sucursalIntercambio->NoexistePlantel()) {
                cout << "Error: La sucursal digitado no tiene planteles.\n"; 
                break; 
            }
            cout << sucursalIntercambio->mostrarPlantelesDisponibles(); 
            cout << "Digite el codigo del plantel deseado: "; cin >> codigoPlantelIntercambio; 
            Plantel* plantelIntercambio = sucursalIntercambio->getPlantel(codigoPlantelIntercambio); 
            if (!plantelIntercambio) {
                cout << "Error: El codigo digitado no existe.\n"; 
                break; 
            }
            if (plantelIntercambio->recomendarEspacios() == "Espacios recomendados: ") {
                cout << plantelIntercambio->toString();
                cout << "Ingrese el codigo del espacio donde desea estacionar el vehiculo: "; cin >> codigoEspacio;
                espacio = plantelIntercambio->buscarEspacio(codigoEspacio);
                if (!espacio->isDisponible()) {
                    cout << "Error: El espacio ya esta ocupado.\n";
                    break;
                }
                sucursal->intercambiarCarro(plantelActual, placa, carro, espacio);
                cout << "El carro con placa: " << placa << "se ha intercambiado exitosamente.\n";
                break; 
            }
            else {
                cout << plantelIntercambio->recomendarEspacios();
                cout << "Ingrese el codigo del espacio donde desea estacionar el vehiculo: "; cin >> codigoEspacio;
                espacio = plantelIntercambio->buscarEspacio(codigoEspacio);
                if (!espacio->isDisponible()) {
                    cout << "Error: El espacio ya esta ocupado.\n";
                    break;
                }
                sucursal->intercambiarCarro(plantelActual, placa, carro, espacio);
                cout << "El carro con placa: " << placa << "se ha intercambiado exitosamente.\n";
            }
            system("pause");*/
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

