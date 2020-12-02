#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

#include "includes/cCalendario.h"
#include "includes/factura.h"
#include "includes/cCliente.h"
#include "includes/cFuncion.h"
#include "includes/cPelicula.h"
#include "includes/cSala.h"
#include "includes/cButacas.h"
#include "includes/cButacasXventas.h"
#include "includes/cVenta.h"
#include "includes/rlutil.h"


///MENUES
void menuprincipal();
void menuUsuario();
void menuadmin();
    void adminSalas();
    void adminPeliculas();
    void adminFunciones();
    void adminVentas();



int main(){
menuprincipal();
return 0;
}




///MENUES
void menuprincipal(){
int opc;
while(1){
    system("cls");
    cout<<"1. Modo administrador"   <<endl; ///COMPLETA
    cout<<"2. Modo usuarios"        <<endl; ///COMPLETA
    cout<<"3. Salir"                <<endl; ///COMPLETA
    cout<<endl<<"ingrese su opcion: ";
    cin>>opc;
    switch(opc)
        {
        case 1: menuadmin();    break; ///ACCEDERAS AL MENU ADMINISTRADOR
        case 2: menuUsuario();  break; ///ACCEDERAS AL MENU USUARIO
        case 3: exit(0);        break; ///SALDRAS DEL PROGRAMA
        default:                cout<<"Opcion incorrecta. Presione una tecla para continuar";
        system("pause>nul");
        break;
        }
}
}

void menuadmin(){
int opc;
while(1){
    system("cls");
    cout<<"1. Salas"        <<endl; ///COMPLETA
    cout<<"2. Peliculas"    <<endl; ///COMPLETA
    cout<<"3. Funciones"    <<endl; ///COMPLETA
    cout<<"4. Ventas"       <<endl; ///COMPLETA
    cout<<"5. Volver"       <<endl; ///COMPLETA
    cout<<endl<<"ingrese su opcion: ";
    cin>>opc;
    switch(opc)
        {
        case 1: adminSalas();       break; ///ACCEDERAS AL MENU DE LAS SALAS
        case 2: adminPeliculas();   break; ///ACCEDERAS AL MENU DE LAS PELICULAS
        case 3: adminFunciones();   break; ///ACCEDERAS AL MENU DE LAS FUNCIONES
        case 4: adminVentas();      break; ///ACCEDERAS AL MENU DE LAS VENTAS
        case 5: menuprincipal();    break; ///VOLVERA AL MENU PRINCIPAL
        default:                cout<<"Opcion incorrecta. Presione una tecla para continuar";
        system("pause>nul");
        break;
        }
}
}

void menuUsuario(){
cliente c; ///PARA ACCEDER A LA CLASE CLIENTE
factura f; ///PARA ACCEDER A LA CLASE FACTURA
pelicula p;
funcion fun;
sala s;
int opc;
while(1){
    system("cls");
    cout<<"1. Ver peliculas"            <<endl; ///COMPLETA
    cout<<"2. Buscar por localidad"     <<endl; ///COMPLETA
    cout<<"3. Buscar por fecha"         <<endl; ///COMPLETA
    cout<<"4. Comprar"                  <<endl; ///SEMI COMPLETA
    cout<<"5. Volver"                   <<endl; ///COMPLETA
    cout<<endl<<"ingrese su opcion: ";
    cin>>opc;
    switch(opc)
        {
        case 1: p.leePos();                                     break; ///LISTARA TODAS LAS PELICULAS
        case 2: s.BuscarLoc();                                  break; ///LISTARA x LOCALIDAD
        case 3: fun.xfecha();                                   break;
        case 4: c.cargar();    c.guardar(); f.cargarTicket();  break; ///SE SOLICITARAN LOS DATOS DEL CLIENTE Y SE ARMARA UNA FACTURA (FALTA ELEJIR LA PELICULA Y BLA BLA BLA)
        case 5: menuprincipal();                                break; ///VOLVERA AL MENU PRINCIPAL
        default:                cout<<"Opcion incorrecta. Presione una tecla para continuar";
        system("pause>nul");
        break;
        }
}
}

void adminVentas(){
cliente c; ///PARA ACCEDER A LA CLASE CLIENTE
factura f; ///PARA ACCEDER A LA CLASE FACTURA
int opc;
while(1){
    system("cls");
    cout<<"1. Clientes"     <<endl; ///COMPLETA
    cout<<"2. Facturas"     <<endl; ///COMPLETA
    cout<<"3. Cerrar caja"  <<endl; ///COMPLETA
    cout<<"4. Volver"       <<endl; ///COMPLETA
    cout<<endl<<"ingrese su opcion: ";
    cin>>opc;
    switch(opc)
        {
        case 1: c.leePos();     break; ///SE LISTARA LOS CLIENTES
        case 2: f.leePos();     break; ///SE LISTARA LAS FACTURAS
        case 3: cierre();       break; ///SE MOSTRARA LA CANTIDAD DE CLIENTES Y LO RECAUDADO
        case 4: menuadmin();    break; ///VOLVERA AL MENU ADMINISTRADOR
        default:                cout<<"Opcion incorrecta. Presione una tecla para continuar";
        system("pause>nul");
        break;
        }
}
}

void adminSalas(){
sala s;
int opc;
while(1){
    system("cls");
    cout<<"1. Cargar una sala"      <<endl; ///COMPLETA
    cout<<"2. Modificar una sala"   <<endl; ///COMPLETA
    cout<<"3. Listar salas"         <<endl; ///COMPLETA
    cout<<"4. Volver"               <<endl; ///COMPLETA
    cout<<endl<<"ingrese su opcion: ";
    cin>>opc;
    switch(opc)
        {
        case 1: s.cargar();     s.guardar();    break; ///SE CARGARA UNA SALA
        case 2: s.modificar();                  break; ///SE MODIFICARA UNA SALA
        case 3: s.leePos();                     break; ///SE LISTARA LAS SALAS
        case 4: menuadmin();                    break; ///VOLVERA AL MENU ADMINISTRADOR
        default:                cout<<"Opcion incorrecta. Presione una tecla para continuar";
        system("pause>nul");
        break;
        }
}
}

void adminPeliculas(){
pelicula p;
int opc;
while(1){
    system("cls");
    cout<<"1. Cargar una pelicula"      <<endl; ///COMPLETA
    cout<<"2. Modificar una pelicula"   <<endl; ///COMPLETA
    cout<<"3. Listar Peliculas"         <<endl; ///COMPLETA
    cout<<"4. Volver"                   <<endl; ///COMPLETA
    cout<<endl<<"ingrese su opcion: ";
    cin>>opc;
    switch(opc)
        {
        case 1: p.cargar(); p.guardar();    break; ///SE CARGARA UNA PELICULA
        case 2: p.modificar();              break; ///SE MODIFICARA UNA PELICULA
        case 3: p.leePos();                 break; ///SE LISTARA LAS PELICULAS
        case 4: menuadmin();                break; ///VOLVERA AL MENU ADMINISTRADOR
        default:                cout<<"Opcion incorrecta. Presione una tecla para continuar";
        system("pause>nul");
        break;
        }
}
}

void adminFunciones(){
funcion f;
int opc;
while(1){
    system("cls");
    cout<<"1. Cargar una Funcion"       <<endl; ///COMPLETA
    cout<<"2. Modificar una Funcion"    <<endl; ///COMPLETA
    cout<<"3. Listar funciones"         <<endl; ///COMPLETA
    cout<<"4. Volver"                   <<endl; ///COMPLETA
    cout<<endl<<"ingrese su opcion: ";
    cin>>opc;
    switch(opc)
        {
        case 1: f.cargar();     f.guardar();    break; ///SE CARGARA UNA FUNCION
        case 2: f.modificar();                  break; ///SE MODIFICARA UNA FUNCION
        case 3: f.leePos();                     break; ///SE LISTARA UNA FUNCION
        case 4: menuadmin();                    break; ///VOLVERA AL MENU ADMINISTRADOR
        default:                cout<<"Opcion incorrecta. Presione una tecla para continuar";
        system("pause>nul");
        break;
        }
}
}









