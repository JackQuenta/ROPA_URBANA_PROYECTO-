#include <iostream>
#include "funciones.h"
#include "validaciones.h"
#include <cmath>
using namespace std;


void mostrarMenuVendedor() {
	login();
    char opcion;

    do {
        system("cls");
        cout << "**************************************************\n";
        cout << "*        PANEL DE VENDEDOR - TOXSTYLE            *\n";
        cout << "**************************************************\n\n";

        cout << "***Seleccione una opci�n***\n";
        cout << "A. Agregar producto.\n";
        cout << "B. Mostrar productos.\n";
        cout << "C. Buscar productos.\n";
        cout << "D. Actualizar producto.\n";
        cout << "E. Eliminar producto.\n";
        cout << "F. Realizar una venta.\n";
        cout << "G. Mostrar ventas realizadas.\n";
        cout << "H. Calcular total de ventas.\n";
        cout << "I. Salir del programa.\n";
        cout << "Opci�n: ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'A': agregarProducto(); break;
            case 'B': mostrarProductos(); break;
            case 'C': buscarProductos(); break;
            case 'D': actualizarProducto(); break;
            case 'E': eliminarProducto(); break;
            case 'F': realizarUnaVenta(); break;
            case 'G': mostrarVentasRealizadas(); break;
            case 'H': calcularTotalDeVentas(); break;
            case 'I': cout << "Saliendo...\n"; break;
            default: cout << "Opci�n no v�lida.\n"; Sleep(1000);
        }

    } while (opcion != 'I');
}


void mostrarMenuCliente() {
    char opcion;

    do {
        system("cls");
        cout << "**************************************************\n";
        cout << "*         PANEL DE CLIENTE - TOXSTYLE            *\n";
        cout << "**************************************************\n\n";

        cout << "***Seleccione una opci�n***\n";
        cout << "A. Ver productos disponibles.\n";
        cout << "B. Realizar compra.\n";
        cout << "C. Salir.\n";
        cout << "Opci�n: ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'A': mostrarProductos(); break;
            case 'B': realizarUnaVenta(); break;
            case 'C': cout << "Saliendo...\n"; break;
            default: cout << "Opci�n no v�lida.\n"; Sleep(1000);
        }

    } while (opcion != 'C');
}


Producto productos[100] = {
    {"Polo Street", 59.90, 12},
    {"Jogger Urbano", 79.50, 15},
    {"Chompa Hoodie", 149.90, 7},
    {"Casaca Denim", 129.99, 8},
    {"Short Deportivo", 49.90, 18},
    {"Mochila Urbana", 109.90, 6},
    {"Zapatillas Chunky", 219.00, 4},
    {"Chaleco Street", 119.90, 6},
    {"Cargo Pants", 139.90, 9},
    {"Zapatillas Skate", 199.90, 5},
    {"Gorra Trucker", 39.90, 15}
    
};
int totalProductos = 11; 

//Variables globales
Venta ventas[100] = {};
int totalVentas = 0;
	

//Funcion para agregar productos
void agregarProducto() {
    system("cls");
    char seguir;
    cout << "=========================================\n";
    cout << " SE AGREGAR�N PRODUCTOS AL INVENTARIO\n";
    cout << " Se requieren los siguientes datos:\n";
    cout << " - Nombre\n - Precio\n - Stock\n";
    cout << "=========================================\n\n";

    do {
        if (totalProductos < 100) {
            cin.ignore();
            
            productos[totalProductos].nombre = leerNombre("Nombre del producto: ");
            productos[totalProductos].precio = leerPrecio("Precio: ");
            productos[totalProductos].stock = leerStock("Stock: ");

            totalProductos++;
            cout << "EL producto fue agregado exitosamente." << endl;

        } else {
            cout << "Limite de productos alcanzado." << endl;
            break;
        }
       seguir = leerSN("\n�Desea agregar otro producto? (S/N): ");
    } while (seguir == 'S');

    cout << "\nRegresando al menu..." << endl;
    Sleep(1000);
    system("cls");
}


//Funcion para comparar el texto ingresado
string aMinuscula(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = tolower(texto[i]);
    }
    return texto;
}

//Funcion para mostrar los productos 
void mostrarProductos() {
	char RetornoMenu;
	if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        system("pause");
        return;
    }
    
	char respuesta;
	do {
		system("cls");
    	cout << "\n�Desea ver los productos ordenados? (S/N): ";
    	cin >> respuesta;
    	respuesta = toupper(respuesta);
    	if (respuesta != 'S' && respuesta != 'N') {
        	cout << "\n---------------------------------------------------" << endl;
        	cout << "Opci�n inv�lida. Debe digitar S o N." << endl;
        	cout << "---------------------------------------------------" << endl;
        	system("pause");
    	}
	} while (respuesta != 'S' && respuesta != 'N');

    if (respuesta == 'S') {
		char opcionChar;
		int opcion;
		do {
			system("cls");
    		cout << "\n�C�mo desea ordenarlos?" << endl;
    		cout << "1. Por nombre (A-Z)" << endl;
    		cout << "2. Por precio (menor a mayor)" << endl;
   			cout << "3. Por stock (menor a mayor)" << endl;
    		cout << "Ingrese una opci�n (1-3): ";
    		cin >> opcionChar;
			
			if(opcionChar == '1' || opcionChar == '2' || opcionChar == '3'){
				opcion = opcionChar - '0';
				break;
			}else{
				cout << "\n---------------------------------------------------" << endl;
				cout << "Opci�n inv�lida, vuelva a digitar un n�mero (1-3)" << endl;
				cout << "---------------------------------------------------" << endl;
				system("pause");
    
			}
   			
		} while (true);

        for (int i = 0; i < totalProductos - 1; i++) {
            for (int j = 0; j < totalProductos - i - 1; j++) {
            	
                bool debeIntercambiar = false;

                if (opcion == 1 && aMinuscula(productos[j].nombre) > aMinuscula(productos[j + 1].nombre)) {
                    debeIntercambiar = true;
                } else if (opcion == 2 && productos[j].precio > productos[j + 1].precio) {
                    debeIntercambiar = true;
                } else if (opcion == 3 && productos[j].stock > productos[j + 1].stock) {
                    debeIntercambiar = true;
                }

                if (debeIntercambiar) {
                    
                    Producto temp;
                    temp.nombre = productos[j].nombre;
                    temp.precio = productos[j].precio;
                    temp.stock = productos[j].stock;

                    productos[j].nombre = productos[j + 1].nombre;
                    productos[j].precio = productos[j + 1].precio;
                    productos[j].stock = productos[j + 1].stock;

                    productos[j + 1].nombre = temp.nombre;
                    productos[j + 1].precio = temp.precio;
                    productos[j + 1].stock = temp.stock;
                }
            }
        }
    }
    system("cls");
    cout << "\n========== PRODUCTOS DISPONIBLES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: S/ " << productos[i].precio << endl;
        cout << "Stock: " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }
    
    string Retorno;
    cout<<"\nRegresar al menu principal.......[1]"<<endl;
    cin.ignore();
    do{
    	getline(cin, Retorno);
    	if(Retorno != "1"){
    		cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
    	}
    }while(Retorno != "1");
    
	
    cout<<"\nRegresando al menu..."<<endl;
	Sleep(1000);
	system("cls");
	
}

//Funcion para buscar los productos 
void buscarProductos() {
	//char Retorno;
	string nombreBuscar;
	system("cls");
    cout << "\n=== BUSCAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin.ignore();
	getline(cin, nombreBuscar);	
    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            cout << "\nProducto encontrado:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "Stock: " << productos[i].stock << endl;
            encontrado = true;
            break;
        }
    }
    if (encontrado == false) {
        cout << "\n-----------------------------------" << endl;
        cout << "�Error! Producto no encontrado." << endl;
        cout << "-----------------------------------" << endl;
    }
    
    string Retorno;
    cout<<"\nRegresar al menu principal.......[1]"<<endl;
    
    do{
    	cout<<"> ";
    	getline(cin, Retorno);
    	if(Retorno != "1"){
    		cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
    	}
    }while(Retorno != "1");
    
	
    cout<<"\nRegresando al menu..."<<endl;
	Sleep(1000);
	system("cls");
}

//Funcion para actualizar los productos 
void actualizarProducto() {
	string nombreBuscar;
	system("cls");
    cout << "\n=== ACTUALIZAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    getline(cin, nombreBuscar);
    
    bool buscado = false;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
        	cout << endl;
            cout << "***Producto encontrado***"<<endl; 
			cout << "Datos actuales:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "Stock: " << productos[i].stock << endl;
            
            cout << "\nIngrese los nuevos datos:" << endl;
            cout << "Nuevo nombre: ";
            getline(cin, productos[i].nombre);
            cout << "Nuevo precio: ";
            cin >> productos[i].precio;
            cout << "Nuevo stock: ";
            cin >> productos[i].stock;
            cin.ignore();
            cout << "Producto actualizado exitosamente!" << endl;
       		buscado = true;
       		break;
	    }
	}
	if (buscado == false) {
    cout << "\n-----------------------------------" << endl;
    cout << "�Error! Producto no encontrado." << endl;
    cout << "-----------------------------------" << endl;
	}
	
	string Retorno;
    cout<<"\nRegresar al menu principal.......[1]"<<endl;
    //cin.ignore();
    do{
    	getline(cin, Retorno);
    	if(Retorno != "1"){
    		cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
    	}
    }while(Retorno != "1");
    
	
    cout<<"\nRegresando al menu..."<<endl;
	Sleep(1000);
	system("cls");
}

//Funcion para eliminar un productos
void eliminarProducto() {
	
    string Nombre;
    system("cls");
    cout << "\n========== PRODUCTOS ACTUALES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: S/ " << productos[i].precio << endl;
        cout << "Stock: " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }
    cout << "\n=== ELIMINAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a eliminar: ";
    cin.ignore();
    getline(cin, Nombre);

    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == Nombre) {
            //Confirmar eliminar producto
            char confirmar;
            do {
                cout << "�Est� seguro de eliminar el producto '" << Nombre << "'? (S/N): ";
                cin >> confirmar;
                confirmar = toupper(confirmar);
                if (confirmar != 'S' && confirmar != 'N') {
                    cout << "Opci�n inv�lida. Debe ingresar S o N.\n";
                }
            } while (confirmar != 'S' && confirmar != 'N');
            
            if (toupper(confirmar) != 'S') {
                cout << "Eliminaci�n cancelada." << endl;
                cout<<"Regregando al MENU principal....";
                Sleep(1800);
                system("cls");
                return;
            }

            for (int j = i; j < totalProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            totalProductos--;
            cout << "Producto eliminado." << endl;
            
            string Retorno;
            cout<<"\nRegresar al menu principal.......[1]"<<endl;
            cin.ignore();
            do{
            	getline(cin, Retorno);
    			if(Retorno != "1"){
    				cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
    			}
            }while(Retorno != "1");
            
            cout<<"\nRegresando al menu..."<<endl;
			Sleep(1000);
			system("cls");
            
            return;
        }
    }
    cout << "\n-----------------------------------" << endl;
    cout << "�Error! Producto no encontrado." << endl;
    cout << "-----------------------------------" << endl;
    
    string Retorno;
    cout<<"\nRegresar al menu principal.......[1]"<<endl;
    
    do{
    	cout<<"> ";
    	getline(cin, Retorno);
    	if(Retorno != "1"){
    		cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
    	}
    }while(Retorno != "1");
    
	
    cout<<"\nRegresando al menu..."<<endl;
	Sleep(1000);
	system("cls");
}

//Funcion para realizar una venta
void realizarUnaVenta() {
    cin.ignore();  // Limpiar buffer
    string nombreBuscado;
    int cantidad;

    if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        system("pause");
        return;
    }
	system("cls");
    cout << "\n========== PRODUCTOS ACTUALES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: S/ " << productos[i].precio << endl;
        cout << "Stock: " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }
	cout << "\n=== VENTA DE PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a vender: ";
    getline(cin, nombreBuscado);
    bool encontrado = false;

    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreBuscado) {
            encontrado = true;
            cout << "Stock disponible: " << productos[i].stock << endl;
            
            float cantidadTemp;
            do {
                cout << "Ingrese cantidad a vender: ";
                if (!(cin >> cantidadTemp)) {
                    cout << "Entrada inv�lida. Debe ingresar un n�mero entero positivo. Intente de nuevo.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (cantidadTemp <= 0 || fmod(cantidadTemp, 1) != 0) {
                    cout << "La cantidad debe ser un n�mero entero positivo. Intente de nuevo.\n";
                    continue;
                }

                cantidad = cantidadTemp;
                break;

            } while (true);
            
            cin.ignore();

            if (cantidad <= productos[i].stock) {
                productos[i].stock -= cantidad;
                float total = cantidad * productos[i].precio;
                ventas[totalVentas].producto = productos[i].nombre;
                ventas[totalVentas].cantidad = cantidad;
                ventas[totalVentas].total = total;
                totalVentas++;

                cout << "\nVenta realizada con �xito." << endl;
                cout << "Total a pagar: S/ " << total << endl;

                // BOLETA VISUAL
                cout << "\n------------------------------------------\n";
                cout << "              *** BOLETA ***              \n";
                cout << "------------------------------------------\n";
                cout << "Tienda     : TOXO URBANO" << endl;
                cout << "Direcci�n  : Av. Comercial #123, Tacna - Per�" << endl;
                cout << "RUC        : 12345678901" << endl;
                cout << "------------------------------------------\n";
                cout << "Producto        : " << productos[i].nombre << endl;
                cout << "Cantidad        : " << cantidad << endl;
                cout << "Precio unitario : S/ " << productos[i].precio << endl;
                cout << "------------------------------------------\n";
                cout << "TOTAL RECIBIDO  : S/ " << total << endl;
                cout << "------------------------------------------\n";
                cout << "�Gracias por vender en nuestra tienda!" << endl;
                cout << "Valoramos mucho tu preferencia." << endl;
                cout << "------------------------------------------\n\n";
            } else {
                cout << "Stock insuficiente." << endl;
                cin.ignore();
            }

           	string Retorno;
		    cout<<"\nRegresar al menu principal.......[1]"<<endl;
		    
		    do{
		    	cout<<"> ";
		    	getline(cin, Retorno);
		    	if(Retorno != "1"){
		    		cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
		    	}
		    }while(Retorno != "1");
			    cout<<"\nRegresando al menu..."<<endl;
				Sleep(1000);
				system("cls");
				return;
			}
        }
        
    if (!encontrado) {
    	system("cls");
        cout << "\n-----------------------------------" << endl;
        cout << "�Error! Producto no encontrado." << endl;
        cout << "-----------------------------------" << endl;
        
		string Retorno;
		cout<<"\nRegresar al menu principal.......[1]"<<endl;	    
	    
		do{
			cout<<">";
			getline(cin, Retorno);
			if(Retorno != "1"){
			   	cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
			}
		}while(Retorno != "1");
		
		cout<<"\nRegresando al menu..."<<endl;
		Sleep(1000);
		system("cls");
	}
}

//Funcion para mostrar las ventas 
void mostrarVentasRealizadas() {
	cin.ignore();
	system("cls");
    cout << "\n============================================" << endl;
    cout << "               VENTAS REALIZADAS            " << endl;
    cout << "============================================" << endl;

    if (totalVentas == 0){
        cout << "\nTodav�a no se ha realizado ninguna venta." << endl;
        cout << "============================================" << endl;
        string Retorno;
		cout<<"\nRegresar al menu principal.......[1]"<<endl;	    
	    do{
			cout<<">";
			getline(cin, Retorno);
			if(Retorno != "1"){
			   	cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
			}
		}while(Retorno != "1");
		cout<<"\nRegresando al menu..."<<endl;
		Sleep(1000);
		system("cls");
		return;
    }

    for (int i = 0; i < totalVentas; i++) {
        cout << "\nVenta #" << i + 1 << endl;
        cout << "Producto : " << ventas[i].producto << endl;
        cout << "Cantidad : " << ventas[i].cantidad << endl;
        cout << "Total    : S/ " << ventas[i].total << endl;
        cout << "--------------------------------------------" << endl;
    }
	string Retorn;
	cout<<"\nRegresar al menu principal.......[1]"<<endl;	    
    do{
		cout<<"> ";
		getline(cin, Retorn);
		if(Retorn != "1"){
		   	cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
		}
	}while(Retorn != "1");
	cout<<"\nRegresando al menu..."<<endl;
	Sleep(1000);
	system("cls");
}


//Funcion para calcular el total de ventas 
void calcularTotalDeVentas() {
    cout << "\n============================================" << endl;
    cout << "               TOTAL DE VENTAS              " << endl;
    cout << "============================================" << endl;

    if (totalVentas == 0) {
        cout << "\nNo se ha realizado ninguna venta." << endl;
        cout << "============================================" << endl;
        system("pause");
        cout<<"Regresando al menu...";
		Sleep(1800);
		system("cls");
        return;
    }

    float sumaTotal = 0;
    for (int i = 0; i < totalVentas; i++) {
        sumaTotal += ventas[i].total;
    }

    cout << "\nEl total acumulado de todas las ventas es: S/ " << sumaTotal << endl;
    cout << "============================================" << endl;
    system("pause");
    cout<<"saliendo al menu...";
    Sleep(1800);
	system("cls");
}

//funcion para iniciar sesion
void login() {
    string contrasenaReal = "toxo123";
    string intento;

    while (true) {
        system("cls");

        cout << "==========================================" << endl;
        cout << "               TOXO TIENDA                " << endl;
        cout<<  "                -LOGIN-                   " << endl;
        cout << "==========================================" << endl;
        cout << "| Ingrese la contrase�a para continuar   |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "\n> Contrase�a: ";
        getline(cin, intento);

        if (intento == contrasenaReal) {
            cout << "\n Acceso concedido. Bienvenido al sistema." << endl;
            Sleep(1000); 
            system("cls");
            return;
        } else {
            cout << "\n Contrase�a incorrecta." << endl;
            cout << " Int�ntelo nuevamente..." << endl;
            Sleep(1000);
        }
    }
}









