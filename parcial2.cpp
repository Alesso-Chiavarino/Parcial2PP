#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

struct datosComercio {
  int numFactura, codVendedor, uniVendidas;
  char nomArticulo[30];
  float importeFacturado;
};

struct datosVendedor {
  int codVendedor;
  char nomVendedor[30];
  char directVendedor[30];
  float sueldoVendedor;
};

void datosVentas() {
  ifstream archivoVentas;
  ifstream archivoVendedor;

  archivoVentas.open("ventas.dat", ios::in | ios::binary);

  if(archivoVentas.fail()) {
    cout << "El archivo no se pudo abrir!" << endl;
    exit(1);
  }

  datosComercio listDatosComercio;

  while(!archivoVentas.eof()) { //mientras no haya finalizado el archivo
    archivoVentas.read((char *)&listDatosComercio,sizeof(datosComercio));

    if(!archivoVentas.eof()) {
      cout << "Nombre del articulo: " << listDatosComercio.nomArticulo << endl << endl;
      cout << "Unidades vendidas: " << listDatosComercio.uniVendidas << endl << endl;
      cout << "Numero de factura: " << listDatosComercio.numFactura << endl << endl;
      cout << "Importe facturado: " << listDatosComercio.importeFacturado << endl << endl;
    }
  }

  archivoVentas.close();

  archivoVendedor.open("vendedor.dat", ios::in | ios::binary);

  if(archivoVendedor.fail()) {
    cout << "El archivo no se pudo abrir!" << endl;
    exit(1);
  }

  datosVendedor listDatosVendedor;

  while(!archivoVendedor.eof()) {
    archivoVendedor.read((char *)&listDatosVendedor,sizeof(datosVendedor));

    if(!archivoVendedor.eof()) {
      cout << "Nombre del vendedor: " << listDatosVendedor.nomVendedor << endl << endl;
      cout << "Direccion del vendedor: " << listDatosVendedor.directVendedor << endl << endl;
    }
  }

  archivoVendedor.close();
  getch();

}

void cargarArchivoComercio() {
  ofstream archivo;
  int cant_datos;

  archivo.open("ventas.dat", ios::app | ios::binary);

  if(archivo.fail()) {
    cout << "el archivo no se encontró \n";
  }

  cout << "ingrese la cantidad de datos que quieres ingresar: \n";
  cin >> cant_datos;
  datosComercio listDatosComercio;

  for(int i=0; i<cant_datos; i++) {
    cout << "Ingrese nombre del articulo:" << endl;
    cin.ignore();
    cin.getline(listDatosComercio.nomArticulo,30,'\n');
    cout << "Ingrese unidades vendidas:" << endl;
    cin >> listDatosComercio.uniVendidas;
    cout << "ingrese el importe facturado:" << endl;
    cin >> listDatosComercio.importeFacturado;
    cout << "Ingrese numero de factura:" << endl;
    cin >> listDatosComercio.numFactura;
    cout << "Ingrese codigo del vendedor:" << endl;
    cin >> listDatosComercio.codVendedor;

    archivo.write((char *)&listDatosComercio,sizeof(datosComercio));

    
  
  }
  
  archivo.close();
  
}

void cargarArchivoVendedor() {
  ofstream archivo;
  int cant_datos;

  archivo.open("vendedor.dat", ios::app | ios::binary);

  if(archivo.fail()) {
    cout << "el archivo no se encontró \n";
  }

  cout << "ingrese la cantidad de datos que quieres ingresar: \n";
  cin >> cant_datos;
  datosVendedor listDatosVendedor;

  for(int i=0; i<cant_datos; i++) {
    cout << "Ingrese codigo del vendedor:" << endl;
    cin >> listDatosVendedor.codVendedor;
    cout << "Ingrese nombre del vendedor:" << endl;
    cin.ignore();
    cin.getline(listDatosVendedor.nomVendedor,30,'\n');
    cout << "Ingrese la direccion del vendedor:" << endl;
    cin.ignore();
    cin.getline(listDatosVendedor.directVendedor,30,'\n');
    cout << "ingrese el sueldo basico del vendedor:" << endl;
    cin >> listDatosVendedor.sueldoVendedor;

    archivo.write((char *)&listDatosVendedor,sizeof(datosVendedor));
  
  }
  
  archivo.close();
  
}

void realizarEstadistica() {

  ifstream archivoVentas;
  ifstream archivoVendedor;
  ofstream archivoEstadistica;

  archivoEstadistica.open("estadistica.dat", ios::app | ios::binary);

  if(archivoEstadistica.fail()) {
    cout << "El archivo no se pudo abrir \n";
    exit(1);
  }

  archivoVentas.open("ventas.dat", ios::in | ios::binary);

  if(archivoVentas.fail()) {
    cout << "El archivo no se pudo abrir!" << endl;
    exit(1);
  }

  datosComercio listDatosComercio;

  while(!archivoVentas.eof()) { 
    archivoVentas.read((char *)&listDatosComercio,sizeof(datosComercio));

    if(!archivoVentas.eof()) {
      if(listDatosComercio.importeFacturado > 1000) {
      
      cout << "Nombre del articulo: " << listDatosComercio.nomArticulo << endl << endl;
      cout << "Unidades vendidas: " << listDatosComercio.uniVendidas << endl << endl;
      cout << "Numero de factura: " << listDatosComercio.numFactura << endl << endl;
      cout << "Importe facturado: " << listDatosComercio.importeFacturado << endl << endl;

      archivoEstadistica.write((char *)&listDatosComercio,sizeof(datosComercio));
      }
    }
  }

  // archivoVentas.close();

  archivoVendedor.open("vendedor.dat", ios::in | ios::binary);

  if(archivoVendedor.fail()) {
    cout << "El archivo no se pudo abrir!" << endl;
    exit(1);
  }

  datosVendedor listDatosVendedor;

  while(!archivoVendedor.eof()) {
    archivoVendedor.read((char *)&listDatosVendedor,sizeof(datosVendedor));

    if(!archivoVendedor.eof()) {
      if((listDatosComercio.codVendedor == listDatosVendedor.codVendedor && listDatosComercio.importeFacturado > 1000)) {
      cout << "Nombre del vendedor: " << listDatosVendedor.nomVendedor << endl << endl;
      archivoEstadistica.write((char *)&listDatosVendedor,sizeof(datosVendedor));
      }
    }
  }

  archivoVentas.close();
  archivoVendedor.close();
  archivoEstadistica.close();
}

void estadistica() {
  ifstream archivoEstadistica;
  

  archivoEstadistica.open("estadistica.dat", ios::in | ios::binary);

  if(archivoEstadistica.fail()) {
    cout << "El archivo no se pudo abrir \n";
    exit(1);
  }

  datosVendedor listDatosVendedor;
  datosComercio listDatosComercio;

  while(!archivoEstadistica.eof()) {
    archivoEstadistica.read((char *)&listDatosVendedor,sizeof(datosVendedor));

    if(!archivoEstadistica.eof()) {
      cout << "-----  Estadisticas  -----" << endl << endl << endl;
      cout << "-----  Ventas con importe mayor a 1000:  -----" << endl << endl;
      cout << "Nombre del articulo: " << listDatosComercio.nomArticulo << endl << endl;
      cout << "Unidades vendidas: " << listDatosComercio.uniVendidas << endl << endl;
      cout << "Numero de factura: " << listDatosComercio.numFactura << endl << endl;
      cout << "Importe facturado: " << listDatosComercio.importeFacturado << endl << endl;
      cout << "Nombre del vendedor: " << listDatosVendedor.nomVendedor << endl << endl;
    }
  }

  archivoEstadistica.close();
  getch();
  archivoEstadistica.clear();
}

void menu() {
  int op ;

  do {
    cout << "1. Cargar informacion de ventas" << endl;
    cout << "2. Cargar informacion de vendedores" << endl;
    cout << "3. Mostrar datos ventas" << endl;
    cout << "4. Estadistica" << endl;
    cout << "5. Salir" << endl;
    cin >> op;

    switch(op) {
      case 1:
        cargarArchivoComercio();
        break;
      case 2:
        cargarArchivoVendedor();
        break;
      case 3:
        datosVentas();
        break;
      case 4:
        realizarEstadistica();
        estadistica();
        break;
      case 5:
        exit(1);
      default:
        cout << "Por favor, escoja una opcion correcta." << endl;
    }

    system("pause");
    system("cls");
  } while(op!=5);
  
}


int main() {
  menu();
  return 0;
}