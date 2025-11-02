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
        cout << "     SISTEMA D-R-T CAR RENTAL - MENU PRINCIPAL\n";
        cout << "=============================================\n";
        cout << "1. Datos Generales\n";
        cout << "2. Planteles, Parqueos y Vehiculos\n";
        cout << "3. Solicitudes y Contratos\n";
        cout << "4. Reportes de Clientes\n";
        cout << "5. Reportes de Planteles y Alquileres\n";
        cout << "0. Salir\n";
        cout << "---------------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuDatosGenerales(); break;
        case 2: menuPlantelesVehiculos(); break;
        case 3: menuSolicitudesContratos(); break;
        case 4: menuReportesClientes(); break;
        case 5: menuReportesPlantelesAlquileres(); break;
        case 0: cout << "\nSaliendo del sistema...\n"; break;
        default: cout << "\nOpcion invalida.\n"; system("pause");
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
        cout << "        MODULO: DATOS GENERALES\n";
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
        default: cout << "\nOpcion invalida.\n"; system("pause");
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

           /* cout << "Ingrese el codigo unico de la sucursal: "; cin >> codigo;
            cout << "Ingrese la provincia de la sucursal: "; cin >> provincia;
            if (!contenedorSucursales->validarSucursal(codigo)) {
                cout << "Error: Ya existe una sucursal con ese codigo.\n";
                system("pause");
                break;
            }
            Sucursal* nuevaSucursal = new Sucursal(codigo, provincia);*/
			// Datos de prueba para facilitar la evaluacion
			Sucursal* nuevaSucursal = new Sucursal("123", "San Jose");
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
        cout << "-------- Gestion de Clientes --------\n";
        cout << "1. Registrar cliente normal\n";
        cout << "2. Registrar cliente juridico\n";
        cout << "3. Eliminar cliente\n";
        cout << "4. Mostrar todos los clientes\n";
        cout << "0. Volver\n";
        cout << "-------------------------------------\n";
        cout << "Opcion: ";
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

				//cout << "Ingrese el ID del cliente: "; cin >> id;
				//if (sucursalActual->getContenedorClientes()->getClienteXId(id)) {
				//	cout << "Error: Ya existe un cliente con esa ID.\n";
				//	system("pause");
				//	continue; // Volver al inicio del bucle para intentar de nuevo
				//}
				//cin.ignore(); // Limpiar el buffer de entrada
				//cout << "Ingrese el nombre del cliente: "; getline(cin, nombre);
				//cout << "Ingrese el país de residencia del cliente: "; cin >> pais;

				// Datos de prueba para facilitar la evaluacion
                id = "3";
                nombre = "Juan Perez";
				pais = "Costa Rica";
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
				//cout << "Ingrese el ID del cliente: "; cin >> id;
				//if (sucursalActual->getContenedorClientes()->getClienteXId(id)) {
				//	cout << "Error: Ya existe un cliente con esa ID.\n";
				//	system("pause");
				//	continue; // Volver al inicio del bucle para intentar de nuevo
				//}
				//cin.ignore(); 

				/*cout << "Ingrese el nombre del cliente: "; getline(cin, nombre);
               cout << "Ingrese el país de residencia del cliente: "; cin >> pais;
               cout << "Ingrese la actividad economica del cliente: "; cin >> actividadEconomica;
               cliente = new ClienteJuridico(nombre, id, pais, actividadEconomica);*/
	
                cliente = new ClienteJuridico("Roberto", "1", "Costa Rica", "Panadero");
				sucursalActual->getContenedorClientes()->ingresarCliente(cliente);
				cout << "Cliente agregado exitosamente!" << endl;
				cout << "Desea ingresar otro cliente? (s/n): ";
				char seguir;
				cin >> seguir;
				if (seguir != 's' && seguir != 'S') {
                    break;
				}
			} while (true);
			
           

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
        default: cout << "Opcion invalida\n"; system("pause");
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
        cout << "-------- Gestion de Colaboradores --------\n";
        cout << "1. Registrar colaborador\n";
        cout << "2. Eliminar colaborador\n";
        cout << "3. Mostrar colaboradores\n";
        cout << "0. Volver\n";
        cout << "------------------------------------------\n";
        cout << "Opcion: ";
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
				//cout << "Ingrese el nombre del colaborador: "; cin >> nombre;
				//cout << "Ingrese el ID del colaborador: "; cin >> id;
				//cout << "Ingrese la fecha de ingreso del colaborador (DD/MM/AAAA): "; cin >> fechaIngreso;

    //            if (sucursalActual->getContenedorColaboradores()->buscarColaborador(id)) {
    //                cout << "Error: Ya existe un colaborador con esa ID.\n";
    //                system("pause");
    //                continue; // Volver al inicio del bucle para intentar de nuevo
				//}
				//Colaborador* colaborador = new Colaborador(nombre, id, fechaIngreso);
                // Datos de prueba para facilitar la evaluacion
                nombre = "Ana Gomez";
                id = "C123";
                fechaIngreso = "01/01/2022";
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
        default: cout << "Opcion invalida\n"; system("pause");
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
    int opcion,filas,columnas,modelo,tipoOpcion,estadoNuevo;
    char codigoPlantel,codigoPlantelIntercambio;
    string codigo,placa, marca,codigoEspacio,licenciaRequerida,codigoIntercambio,IdColaborador;
    string tipo[4] = { "Economico","Estandar","Lujo","4x4" };
    string estadosDisponibles[3] = { "Disponible","Revision", "Lavado" };
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
        cout << "     MODULO: PLANTELES, PARQUEOS Y VEHÍCULOS\n";
        cout << "=============================================\n";
        cout << "1. Crear plantel en sucursal\n";
        cout << "2. Mostrar distribucion de espacios\n";
        cout << "3. Ingresar nuevo vehiculo\n";
        cout << "4. Eliminar vehiculo\n";
        cout << "5. Cambiar estado de vehiculo\n";
        cout << "6. Reubicar vehiculo dentro de la sucursal\n";
        cout << "7. Mostrar vehiculos de la sucursal\n";
        cout << "8. Intercambiar vehiculo entre sucursales\n";
        cout << "0. Volver al menu principal\n";
        cout << "---------------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            //cout << "Ingrese la letra que va a identificar su plantel: "; cin >> codigoPlantel; 
            //cout << "Ingrese la cantidad de filas que desea en su plantel: "; cin >> filas; 
            //cout << "Ingrese la cantidad de columnas que desea en su plantel: "; cin >> columnas; 
            //Plantel* plantel = new Plantel(codigoPlantel, filas, columnas);


			// Datos de prueba para facilitar la evaluacion
			
			Plantel* plantel = new Plantel('A', 3, 4);
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
            }/*
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

            carro = new Carro(placa, modelo, marca, tipo[tipoOpcion - 1], licenciaRequerida);*/

			carro = new Carro("ABC123", 2020, "Toyota", "Estandar", "B1");
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
            cout << p->recomendarEspacios() << endl; 
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
            cout << "Ingrese la placa del vehículo: "; cin >> placa;
            Carro* carro = sucursal->getContenedorCarros()->obtenerCarro(placa);
            if (!carro || carro->getEstado()=="Alquilado") {
                cout << "Error: No coincide la placa o se encuentra alquilado.\n";
                system("pause");
                break;
            }
            cout << "Ingrese el ID del colaborador: "; cin >> IdColaborador;
            Colaborador* colaborador = sucursal->getContenedorColaboradores()->buscarColaborador(IdColaborador); 
            if (!colaborador) {
                cout << "Error: El cliente no existe.\n";
                system("pause");
                break; 
            }
            string estadoActual =  carro->getEstado(); 
            cout << "Estado actual: "<< estadoActual << endl;
            carro->mostrarEstadosParaPlantel(); 
            cout << "Ingrese el nuevo estado: "; cin >> estadoNuevo; 
            if (estadoNuevo<1||estadoNuevo>3) {
                cout << "Error: Opcion incorrecta.\n"; 
                break; 
            }
            if ((estadoActual == "Disponible" || estadoActual == "Devuelto") && (estadosDisponibles[estadoNuevo - 1] == "Revision" || estadosDisponibles[estadoNuevo - 1] == "Lavado")) {
                cout << "Ingrese la fecha actual: "; string fecha; cin >> fecha; 
                carro->cambiarEstado(carro->getEstado(),estadosDisponibles[estadoNuevo-1],colaborador->getId(), fecha);
                cout << "Trancision de estado exitosa!\n";
                system("pause");
                break; 
            }
            if (estadoActual == "Revision" && estadosDisponibles[estadoNuevo - 1] == "Lavado") {
                cout << "Ingrese la fecha actual: "; string fecha; cin >> fecha;
                carro->cambiarEstado(carro->getEstado(), estadosDisponibles[estadoNuevo - 1], colaborador->getId(), fecha);
                cout << "Trancision de estado exitosa!\n";
                system("pause");
                break;
            }
            if (estadoActual == "Lavado" && estadosDisponibles[estadoNuevo - 1] == "Disponible" || estadosDisponibles[estadoNuevo - 1] == "Revision") {
                cout << "Ingrese la fecha actual: "; string fecha; cin >> fecha;
                carro->cambiarEstado(carro->getEstado(), estadosDisponibles[estadoNuevo - 1], colaborador->getId(), fecha);
                cout << "Trancision de estado exitosa!\n"; 
                system("pause");
                break;
            }
            cout << "Transicion de estado invalida.\n"; 
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
                sucursal->intercambiarCarro(plantelActual, placa, carro, espacio,sucursalIntercambio);
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
                sucursal->intercambiarCarro(plantelActual, placa, carro, espacio,sucursalIntercambio);
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
    // PASO 0: Selección de sucursal donde operar
    string idCliente, idColaborador, placa, fechaInicio, fechaEntrega, idSolicitud;
    int dias = 0;
    float precioTotal = 0.0f, precioDias = 0.0f;

    string codigoSucursal;
	Sucursal* sucursal = nullptr;
    // debe verificarse que hayan sucursales creadas
    if(!contenedorSucursales || contenedorSucursales->estaVacio()) {
        cout << "Error: No hay sucursales disponibles. Por favor, ingrese una sucursal primero." << endl;
        system("pause");
        return; // salir del método si no hay sucursales
	}
    int opcion;
    do {
        system("cls");
        cout << "       MODULO: SOLICITUDES Y CONTRATOS\n";
        cout << "=============================================\n";
        cout << "1. Crear solicitud de alquiler\n";
        cout << "2. Mostrar solicitudes\n";
        cout << "3. Aprobar o rechazar solicitud\n";
        cout << "4. Crear contrato (desde solicitud aprobada)\n";
        cout << "5. Finalizar contrato (devolucion de vehiculo)\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            do {
                system("cls");
                cout << "Ingrese el codigo de la sucursal en la que desea operar: ";
                cin >> codigoSucursal;
                 sucursal = contenedorSucursales->buscarSucursal(codigoSucursal);
                if (!sucursal) {
                    cout << "Error: Sucursal no encontrada.\n";
                    system("pause");
                    continue; // volver a intentar dentro del ciclo interno
                }
				cout << "===== CREAR SOLICITUD DE ALQUILER EN LA SUCURSAL " << sucursal->getNumUnico() << " =====\n";
				cout << "===== LISTA DE SOLICITUDES EN LA SUCURSAL " << sucursal->getNumUnico() << " =====\n";
                cout << sucursal->getContenedorSolicitudAlquiler()->toString();
               
				cout << "Ingrese el ID de la solicitud: "; cin >> idSolicitud;
                //la de clientes 
                if (sucursal->getContenedorSolicitudAlquiler()->buscarSolicitudPorId(idSolicitud)) {
                    cout << "Error: Ya existe una solicitud con esa ID.\n";
                    system("pause");
					continue; // volver a intentar dentro del ciclo interno
				}
				// muestra los clientes disponibles en la sucursal
				cout << "===== LISTA DE CLIENTES EN LA SUCURSAL " << sucursal->getNumUnico() << " =====\n";
				cout << sucursal->getContenedorClientes()->toString();


				cout << "Ingrese el ID del cliente: "; cin >> idCliente;
				//comprobar si el cliente existe
                if (!sucursal->getContenedorClientes()->getClienteXId(idCliente)) {
                    cout << "Error: No existe un cliente con esa ID.\n";
                    system("pause");
                    continue; // volver a intentar dentro del ciclo interno
				}
				// muestra los colaboradores disponibles en la sucursal
				cout << "===== LISTA DE COLABORADORES EN LA SUCURSAL " << sucursal->getNumUnico() << " =====\n";
				cout << sucursal->getContenedorColaboradores()->toString();

				cout << "Ingrese el ID del colaborador que atiende la solicitud: "; cin >> idColaborador;
                //comprobar si el colaborador existe
                if (!sucursal->getContenedorColaboradores()->buscarColaborador(idColaborador)) {
                    cout << "Error: No existe un colaborador con esa ID.\n";
                    system("pause");
                    continue; // volver a intentar dentro del ciclo interno
				}
				cout << "Ingrese la placa del vehiculo a alquilar: "; cin >> placa;
				//comprobar si el vehiculo existe y compruebe que el carro esta disponible

                Carro* carroAlquiler = sucursal->getContenedorCarros()->buscarCarroPorPlaca(placa);
                if (!carroAlquiler) {
                    cout << "Error: No existe un vehiculo con esa placa.\n";
                    system("pause");
                    continue; 
                }
                if (!carroAlquiler->verificarDisponibilidad()) {
                    cout << "Error: El vehiculo no está disponible para alquiler.\n";
                    system("pause");
                    continue;
				}
				cout << "Ingrese la fecha de inicio del alquiler (DD/MM/AAAA): "; cin >> fechaInicio;
				cout << "Ingrese la fecha de entrega del vehiculo (DD/MM/AAAA): "; cin >> fechaEntrega;
				cout << "Ingrese la cantidad de dias de alquiler: "; cin >> dias;
				cout << "Ingrese el precio por dia de alquiler: "; cin >> precioDias;
				precioTotal = dias * precioDias;

				// Estado inicial de la solicitud

				string estado = "Pendiente";


				system("cls");
                // Solicitud usando los valores ya declarados
				SolicitudAlquiler* nuevaSolicitud = new SolicitudAlquiler(idSolicitud, idCliente, idColaborador, placa, dias, fechaInicio, fechaEntrega, precioTotal, precioDias, estado);
                sucursal->getContenedorSolicitudAlquiler()->agregarSolicitudAlquiler(nuevaSolicitud);
                cout << "Solicitud de alquiler creada exitosamente!\n";
                cout << nuevaSolicitud->toString() << endl;
				system("pause");
                cout << "Desea crear otra solicitud? (s/n): ";
                char seguir;
                cin >> seguir;
                if (seguir != 's' && seguir != 'S') {
                    break;
                }
            } while (true);
            break;
        }
        case 2: {
            do {
                system("cls");
                cout << "Ingrese el codigo de la sucursal en la que desea operar: ";
                cin >> codigoSucursal;
                 sucursal = contenedorSucursales->buscarSucursal(codigoSucursal);
                if (!sucursal) {
                    cout << "Error: Sucursal no encontrada.\n";
                    system("pause");
                    continue; // volver a intentar dentro del ciclo interno
                }
                cout << "===== LISTA DE SOLICITUDES EN LA SUCURSAL " << sucursal->getNumUnico() << " =====\n";
                cout << sucursal->getContenedorSolicitudAlquiler()->toString();
                cout << "Desea ver las solicitudes de otra sucursal? (s/n): ";



                char seguir;
                cin >> seguir;
                if (seguir != 's' && seguir != 'S') {
                    break;
                }
            } while (true);
            system("pause");
            break;
        }
        case 3: {
             system("cls");
            cout << "Digite el codigo de la sucursal en la que desea operar: ";
            cin >> codigoSucursal;
             sucursal = contenedorSucursales->buscarSucursal(codigoSucursal);
            if (!sucursal) {
                cout << "Error: Sucursal no encontrada.\n";
                system("pause");
                break;
            }

            cout << "Digite el ID de la solicitud que desea aprobar/rechazar: ";
            cin >> idSolicitud;
            if (!sucursal->getContenedorSolicitudAlquiler()->buscarSolicitudPorId(idSolicitud)) {
                cout << "Error: Solicitud no encontrada.\n";
                system("pause");
                break;
            }

            cout << "1- Aprobar solicitud.\n";
            cout << "2- Rechazar solicitud.\n";
            cout << "Digite la opcion deseada: ";
            int opcionSolicitud;
            cin >> opcionSolicitud;
            switch (opcionSolicitud) {
            case 1:
                sucursal->getContenedorSolicitudAlquiler()->aprobarSolicitud(idSolicitud);
                cout << "Solicitud aprobada exitosamente!\n";
                break;
            case 2:
                sucursal->getContenedorSolicitudAlquiler()->rechazarSolicitud(idSolicitud);
                cout << "Solicitud rechazada exitosamente!\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
            }
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            cout << "Digite el codigo de la sucursal en la que desea operar: ";
            cin >> codigoSucursal;
            sucursal = contenedorSucursales->buscarSucursal(codigoSucursal);
            if (!sucursal) {
                cout << "Error: Sucursal no encontrada.\n";
                system("pause");
                break;
            }

            if (!sucursal->getContenedorSolicitudAlquiler()) {
                cout << "Error: El contenedor de solicitudes no existe.\n";
                system("pause");
                break;
            }

            cout << "Digite el ID de la solicitud aprobada para crear el contrato: ";
            cin >> idSolicitud;

            SolicitudAlquiler* solicitud = sucursal->getContenedorSolicitudAlquiler()->obtenerSolicitudPorId(idSolicitud);
            if (!solicitud) {
                cout << "Error: Solicitud no encontrada.\n";
                system("pause");
                break;
            }

            if (solicitud->getEstadoSolicitud() != "aprobada") {
                cout << "Error: La solicitud no ha sido aprobada.\n";
                system("pause");
                break;
            }

            string estadoContrato[2] = { "Aprobado en alquiler", "Aprobado pendiente de ejecucion" };
            cout << "Seleccione el estado del contrato:\n";
            for (int i = 0; i < 2; i++) {
                cout << i + 1 << ". " << estadoContrato[i] << endl;
            }

            int estadoSeleccionado;
            cout << "Ingrese el numero correspondiente al estado del contrato: ";
            cin >> estadoSeleccionado;
            if (estadoSeleccionado < 1 || estadoSeleccionado > 2) {
                cout << "Error: Opcion de estado invalida.\n";
                system("pause");
                break;
            }

            string estadoSeleccionadoStr = estadoContrato[estadoSeleccionado - 1];

            ContratoAlquiler* nuevoContrato = new ContratoAlquiler(
                solicitud->getIdSolicitud(),
                solicitud->getIdCliente(),
                solicitud->getIdColaborador(),
                solicitud->getPlacaVehiculo(),
                solicitud->getFechaInicioAlquiler(),
                solicitud->getFechaFinAlquiler(),
                solicitud->getCanDiasAlquiler(),
                solicitud->getPrecioDias(),
                solicitud->getPrecioAlquiler(),
                estadoSeleccionadoStr
            );
            if(!nuevoContrato) {
                cout << "Error: No se pudo crear el contrato.\n";
                system("pause");
                break;
			}
            sucursal->getContenedorContratoAlquiler()->agregarContratoAlquiler(nuevoContrato);
            cout << "Contrato creado exitosamente desde la solicitud aprobada!\n";

            Carro* carroAlquilado = sucursal->getContenedorCarros()->buscarCarroPorPlaca(solicitud->getPlacaVehiculo());
            if (carroAlquilado) {
                carroAlquilado->cambiarEstado(carroAlquilado->getEstado(), "Alquilado", solicitud->getIdColaborador(), solicitud->getFechaInicioAlquiler());
            }
            else {
                cout << "Error: No se encontro el vehiculo para cambiar su estado a 'Alquilado'.\n";
            }

            sucursal->getContenedorSolicitudAlquiler()->eliminarSolicitud(idSolicitud);
            cout << "Solicitud eliminada del contenedor.\n";

            system("pause");
            break;
        }

        case 5: {
			system("cls");
			//aca se va a finalizar el contrato, ver que tipo de devolucion debe hacerse y luego se va a colocar el carro en devueto // realizado //


			cout << "Digite el codigo de la sucursal en la que desea operar: ";
			cin >> codigoSucursal;
			sucursal = contenedorSucursales->buscarSucursal(codigoSucursal);
            if (!sucursal) {
                cout << "Error: Sucursal no encontrada.\n";
            }
			cout << "Digite el ID del contrato a finalizar: ";
			cin >> idSolicitud;
            if (!sucursal->getContenedorContratoAlquiler()->buscarContratoAlquiler(idSolicitud)) {
                cout << "Error: Contrato no encontrado.\n";
            }
           
			cout << "Ingrese la cantidad de dias que se utilizo el vehiculo: "; int diasUtilizados; cin >> diasUtilizados;
			ContratoAlquiler* contratoFinalizar = sucursal->getContenedorContratoAlquiler()->obtenerContratoAlquiler(idSolicitud);

            if (diasUtilizados < contratoFinalizar->getDias()) {
                int diasNoUtilizados = contratoFinalizar->getDias() - diasUtilizados;
                float reintegro = diasNoUtilizados * contratoFinalizar->getPrecioDiario() * 0.7f;
                cout << "El contrato se finaliza de manera anticipada. Reintegro por dias no utilizados: $" << reintegro << endl;
            }
            else if (diasUtilizados > contratoFinalizar->getDias()) {
                int diasAtraso = diasUtilizados - contratoFinalizar->getDias();
                float multa = diasAtraso * contratoFinalizar->getPrecioDiario() * 1.3f;
                cout << "El contrato se finaliza con atraso. Multa por dias de atraso: $" << multa << endl;
            }
            else {
                cout << "El contrato se finaliza sin cargos adicionales." << endl;
            }
			// Cambiar estado del carro a "Devuelto"
			Carro* carroDevuelto = sucursal->getContenedorCarros()->buscarCarroPorPlaca(contratoFinalizar->getPlacaVehiculo());

            if (carroDevuelto) {
                carroDevuelto->cambiarEstado(carroDevuelto->getEstado(), "Devuelto", contratoFinalizar->getIdColaborador(), contratoFinalizar->getFechaEntrega());
            } else {
                cout << "Error: No se encontró el vehículo para cambiar su estado a 'Devuelto'.\n";
            }

            sucursal->getContenedorContratoAlquiler()->eliminarContratoAlquiler(idSolicitud);
			cout << "Contrato finalizado y eliminado del contenedor.\n";

            system("pause");
            break;
        }
        case 0:
            break;
        default:
            cout << "Opción inválida\n";
            system("pause");
            break;
        }
    } while (opcion != 0);
}


// =====================================================
//  REPORTES DE CLIENTES
// =====================================================
void InterfazUsuario::menuReportesClientes() {
    int opcion;
    do {
		if (contenedorSucursales->estaVacio())

        {
            cout << "No hay sucursales registradas.\n";
            system("pause");
            return;
        }
		


        system("cls");

        cout << "=============================================\n";
        cout << "           MODULO: REPORTES DE CLIENTES\n";
        cout << "=============================================\n";
        cout << "1. Historial de cliente (solicitudes y contratos)\n";
        cout << "2. Reporte de clientes por cantidad de contratos\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            
            do
            {
				system("cls");
                cout << "Ingrese el codigo de la sucursal en la que desea operar: ";
                string codigoSucursal;
                cin >> codigoSucursal;
                Sucursal* sucursal = contenedorSucursales->buscarSucursal(codigoSucursal);
                if (!sucursal) {
                    cout << "Error: Sucursal no encontrada.\n";
                    system("pause");
                    continue; // volver a intentar dentro del ciclo interno
				}
				cout << "===== HISTORIAL DE CLIENTE =====\n";
				string idCliente;
                cout << "Ingrese el ID del cliente: "; cin >> idCliente;
                Cliente* cliente = sucursal->getContenedorClientes()->getClienteXId(idCliente);
                if (!cliente) {
                    cout << "Error: No existe un cliente con esa ID.\n";
                    system("pause");
					continue; // volver a intentar dentro del ciclo interno
                    }
                cout << "----- SOLICITUDES DE ALQUILER -----\n";
                sucursal->getContenedorSolicitudAlquiler()->mostrarSolicitudesPorCliente(idCliente);
                cout << "----- CONTRATOS DE ALQUILER -----\n";
                sucursal->getContenedorContratoAlquiler()->mostrarContratosPorCliente(idCliente);
                system("pause");

                cout << "Desea ver el historial de otro cliente? (s/n): ";
                char seguir;
                cin >> seguir;
                if (seguir != 's' && seguir != 'S') {
                    break;

                }

            } while (true);
            break;
        case 2:

            do
            {
				system("cls");
              
				cout << "Ingrese el codigo de la sucursal en la que desea operar: ";
				string codigoSucursal;
				cin >> codigoSucursal;
				Sucursal* sucursal = contenedorSucursales->buscarSucursal(codigoSucursal);
                if (!sucursal) {
                    cout << "Error: Sucursal no encontrada.\n";
                }
               /* Reporte de clientes por cantidad de contratos : Ordena en la lista los
                    clientes por cantidad de alquileres realizados, iniciando por el cliente
                    que más alquileres haya hecho.Debe incluir el id y el nombre del
                    cliente, así como el código de los contratos de alquiler realizados. hazlo de esta manera y logica */
				sucursal->getContenedorClientes()->reporteClientesPorCantidadContratos(sucursal->getContenedorContratoAlquiler());  




                system("pause");
                cout << "Desea ver el reporte de otra sucursal? (s/n): ";
                char seguir;
                cin >> seguir;
                if (seguir != 's' && seguir != 'S') {
                    break;
                }

            } while (true);
            break;
        case 0: break;
        default: cout << "Opcion invalida\n"; system("pause");
        }
    } while (opcion != 0);
}


// =====================================================
//  REPORTES DE PLANTELES Y ALQUILERES
// =====================================================
void InterfazUsuario::menuReportesPlantelesAlquileres() {
    string codigoS, codigoSucursal;
    int opcionSucursal;
    Sucursal* sucursalReporte;
    char seguir;
    cout << "Ingrese el codigo de la sucursal en la que desea ingresar: "; cin >> codigoS;
    Sucursal* sucursal = contenedorSucursales->buscarSucursal(codigoS);
    if (!sucursal) {
        cout << "El codigo ingresado no pertenece a ninguna sucursal.\n";
        system("pause");
        return;
    }
    int opcion;
    string placaCarro; 
    do {
        system("cls");
        cout << "=============================================\n";
        cout << "   MODULO: REPORTES DE PLANTELES Y ALQUILERES\n";
        cout << "=============================================\n";
        cout << "1. Bitacora de estados de un vehiculo\n";
        cout << "2. Contratos de un vehiculo especifico\n";
        cout << "3. Porcentaje de ocupacion de planteles\n";
        cout << "4. Contratos por sucursal (recientes primero)\n";
        cout << "5. Reporte de alquileres por colaborador\n";
        cout << "0. Volver\n";
        cout << "---------------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout <<sucursal->getContenedorPlanteles()->mostrarCarrosXPlantel();
            cout << "Digite la placa del carro deseado: "; cin >> placaCarro;
            Carro* c = sucursal->getContenedorCarros()->obtenerCarro(placaCarro);
            cout << c->getBitacora()->toString();
            system("pause");
            break;
        }
        case 2:
            // contenedorSucursales->getSucursalActual()->contratosPorVehiculo();
            break;
        case 3:
            // contenedorSucursales->getSucursalActual()->porcentajeOcupacion();
            break;
        case 4:
			system("cls");


			cout << "Desea seguir en la sucursal actual o ver otra sucursal?\n";
			cout << "1. Sucursal actual\n";
			cout << "2. Otra sucursal\n";
			
			cin >> opcionSucursal;
			sucursalReporte = sucursal;
            if (opcionSucursal == 2) {
               
                cout << "Ingrese el codigo de la sucursal que desea ver: ";
                cin >> codigoSucursal;
                sucursalReporte = contenedorSucursales->buscarSucursal(codigoSucursal);
                if (!sucursalReporte) {
                    cout << "Error: Sucursal no encontrada.\n";
                    system("pause");
                    break;
                }
			}
			sucursalReporte->getContenedorContratoAlquiler()->reporteContratosPorSucursal();
            cout << "Desea ver el reporte de otra sucursal? (s/n): ";
           
            cin >> seguir;
            if (seguir != 's' && seguir != 'S') {
                break;
			}
			system("pause");

			break;
        case 5:
           
			system("cls");

            cout << "Desea seguir en la sucursal actual o ver otra sucursal?\n";
            cout << "1. Sucursal actual\n";
            cout << "2. Otra sucursal\n";

            cin >> opcionSucursal;
            sucursalReporte = sucursal;
            if (opcionSucursal == 2) {

                cout << "Ingrese el codigo de la sucursal que desea ver: ";
                cin >> codigoSucursal;
                sucursalReporte = contenedorSucursales->buscarSucursal(codigoSucursal);
                if (!sucursalReporte) {
                    cout << "Error: Sucursal no encontrada.\n";
                    system("pause");
                    break;
                }
            }
			sucursalReporte->getContenedorColaboradores()->reporteAlquileresPorColaborador(sucursalReporte->getContenedorContratoAlquiler());
			cout <<"Desea ver el reporte de otra sucursal? (s/n): ";
            
            cin >> seguir;
            if (seguir != 's' && seguir != 'S') {
                break;
			}

			system("pause");
            break;
        case 0: break;
        default: cout << "Opción invalida\n"; system("pause");
        }
    } while (opcion != 0);
}

