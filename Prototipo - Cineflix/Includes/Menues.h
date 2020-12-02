#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

#include "Clases/cSala.h"
#include "Clases/cPelicula.h"
#include "Clases/cFuncion.h"

///Menues principales:
void MenuPrincipal(){
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
    case 80: //ABAJO
    pos++;
    if(pos>3){pos=1;}
    break;
    case 72: //ARRIBA
    pos--;
    if(pos<1){pos=3;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            passVerificador();
        break;
        case 2:
            menuUsuario();
        break;
        case 3:
            exit (0);
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,15,70,2);
        gotoxy(60,16); cout << "ADMINISTRADOR";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,19,60,2);
        gotoxy(63,20); cout << "USUARIO";
        recuadro(36,28,60,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,15,60,2);
        gotoxy(60,16); cout << "ADMINISTRADOR";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,19,70,2);
        gotoxy(63,20); cout << "USUARIO";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,15,60,2);
        gotoxy(60,16); cout << "ADMINISTRADOR";
        recuadro(36,19,60,2);
        gotoxy(63,20); cout << "USUARIO";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,28,60,2);
        gotoxy(57,29);cout <<  "SALIR DEL PROGRAMA";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        }
        opc = getch();
    }
}
void passVerificador(){
    system("cls");
    password pass;
    int pp;
    ShowConsoleCursor(true);
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39,7);
    SetConsoleTextAttribute(hConsole, 7);
    recuadro(36,30,60,4);
    recuadro(38,31,26,2);
    gotoxy(47,32); cout << "CANCELAR";
    recuadro(67,31,26,2);
    gotoxy(75,32); cout << "VERIFICAR";
    gotoxy(36,18); cout << "INGRESE EL 'PASSWORD'";
    recuadro(36,20,60,2);
    gotoxy(38,21);
    cin >> pp;
    int opc, pos=1;
    ShowConsoleCursor(false);
    while(true){
        switch(opc){
        case 75: //IZQUIERDA
        pos++;
        if(pos>2){pos=1;}
        break;
        case 77: //DERECHA
        pos--;
        if(pos<1){pos=2;}
        break;
        case 13: //ENTER
        switch(pos){
        case 1:
        MenuPrincipal();
        break;
        case 2:
        FILE *f;
        f = fopen("PP/pass.txt","rb");
        if(f==NULL){
        fclose(f);
        }
        while(fread(&pass, sizeof pass,1,f)==1){
        if(pass.cc == pp){
        fclose(f);
        SetConsoleTextAttribute(hConsole, 2);
        gotoxy(36,19); cout << "PASSWORD CORRECTO";
        system("pause>NULL");
        menuAdmin();
        }
        }
        fclose(f);
        SetConsoleTextAttribute(hConsole, 4);
        gotoxy(36,19); cout << "PASSWORD ERRONEO";
        system("pause>NULL");
        MenuPrincipal();
        break;
        }
        }
        switch(pos){
        case 1:
        SetConsoleTextAttribute(hConsole, 6);
        recuadro(38,31,26,2);
        gotoxy(47,32); cout << "CANCELAR";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(67,31,26,2);
        gotoxy(75,32); cout << "VERIFICAR";
        break;
        case 2:
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(38,31,26,2);
        gotoxy(47,32); cout << "CANCELAR";
        SetConsoleTextAttribute(hConsole, 6);
        recuadro(67,31,26,2);
        gotoxy(75,32); cout << "VERIFICAR";
        break;
        }
        opc = getch();
    }
}
void menuAdmin(){
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
        switch(opc){
        case 80: //ABAJO
        pos++;
        if(pos>6){pos=1;}
        break;
        case 72: //ARRIBA
        pos--;
        if(pos<1){pos=6;}
        break;
        case 13: //ENTER
        switch(pos){
        case 1:
        adminSalas();
        break;
        case 2:
        adminPeliculas();
        break;
        case 3:
        adminFunciones();
        break;
        case 4:
        adminVentas();
        break;
        case 5:
        passConf();
        break;
        case 6:
        MenuPrincipal();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(65,15); cout << "SALAS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "PELICULAS";
        recuadro(36,20,60,2);
        gotoxy(63,21); cout << "FUNCIONES";
        recuadro(36,23,60,2);
        gotoxy(64,24); cout << "VENTAS";
        recuadro(36,26,60,2);
        gotoxy(63,27);cout <<  "CONFIGURAR";
        recuadro(36,29,60,2);
        gotoxy(61,30);cout <<  "VOLVER  ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(65,15); cout << "SALAS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(63,18); cout << "PELICULAS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(63,21); cout << "FUNCIONES";
        recuadro(36,23,60,2);
        gotoxy(64,24); cout << "VENTAS";
        recuadro(36,26,60,2);
        gotoxy(63,27);cout <<  "CONFIGURAR";
        recuadro(36,29,60,2);
        gotoxy(61,30);cout <<  "VOLVER  ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(65,15); cout << "SALAS";
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "PELICULAS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(63,21); cout << "FUNCIONES";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,23,60,2);
        gotoxy(64,24); cout << "VENTAS";
        recuadro(36,26,60,2);
        gotoxy(63,27);cout <<  "CONFIGURAR";
        recuadro(36,29,60,2);
        gotoxy(61,30);cout <<  "VOLVER  ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(65,15); cout << "SALAS";
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "PELICULAS";
        recuadro(36,20,60,2);
        gotoxy(63,21); cout << "FUNCIONES";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,23,70,2);
        gotoxy(64,24); cout << "VENTAS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,26,60,2);
        gotoxy(63,27);cout <<  "CONFIGURAR";
        recuadro(36,29,60,2);
        gotoxy(61,30);cout <<  "VOLVER  ATRAS";
        break;
        case 5:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(65,15); cout << "SALAS";
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "PELICULAS";
        recuadro(36,20,60,2);
        gotoxy(63,21); cout << "FUNCIONES";
        recuadro(36,23,60,2);
        gotoxy(64,24); cout << "VENTAS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,26,60,2);
        gotoxy(63,27);cout <<  "CONFIGURAR";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,29,60,2);
        gotoxy(61,30);cout <<  "VOLVER  ATRAS";
        break;
        case 6:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(65,15); cout << "SALAS";
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "PELICULAS";
        recuadro(36,20,60,2);
        gotoxy(63,21); cout << "FUNCIONES";
        recuadro(36,23,60,2);
        gotoxy(64,24); cout << "VENTAS";
        recuadro(36,26,60,2);
        gotoxy(63,27);cout <<  "CONFIGURAR";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,29,60,2);
        gotoxy(61,30);cout <<  "VOLVER  ATRAS";
        break;
        }
        opc = getch();
    }
}
void menuUsuario(){
    pelicula p;
    funcion f;
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
    case 80: //ABAJO
    pos++;
    if(pos>5){pos=1;}
    break;
    case 72: //ARRIBA
    pos--;
    if(pos<1){pos=5;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
        p.leePos();
        break;
        case 2:
        f.leePos();
        break;
        case 3:
        ///comprar entradas
        break;
        case 4:
        MenuPrincipal();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(60,15); cout << "VER  CARTELERA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(59,18); cout << "FUNCIONES DE HOY";
        recuadro(36,23,60,2);
        gotoxy(59,24); cout << "COMPRAR ENTRADA";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "VER  CARTELERA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(59,18); cout << "FUNCIONES DE HOY";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,23,60,2);
        gotoxy(59,24); cout << "COMPRAR ENTRADA";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "VER  CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(59,18); cout << "FUNCIONES DE HOY";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,23,60,2);
        gotoxy(59,24); cout << "COMPRAR ENTRADA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        recuadro(36,14,60,2);
        gotoxy(60,15); cout << "VER  CARTELERA";
        recuadro(36,17,60,2);
        gotoxy(59,18); cout << "FUNCIONES DE HOY";
        recuadro(31,23,70,2);
        gotoxy(59,24); cout << "COMPRAR ENTRADA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER  ATRAS";
        SetConsoleTextAttribute(hConsole, 7);
        break;
        }
        opc = getch();
    }
}

///Menues Modo Administrador:
void adminSalas(){
    sala s;
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    recuadro(26,10,80,25); ///
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
        case 80: //ABAJO
        pos++;
        if(pos>4){pos=1;}
        break;
        case 72: //ARRIBA
        pos--;
        if(pos<1){pos=4;}
        break;
        case 13: //ENTER
        switch(pos){
        case 1:
        s.cargar(false);
        break;
        case 2:
        s.modificar();
        break;
        case 3:
        s.leePos();
        break;
        case 4:
        menuAdmin();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(57,15); cout << "CARGAR UNA NUEVA SALA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(58,18); cout << "MODIFICAR UNA SALA";
        recuadro(36,20,60,2);
        gotoxy(61,21); cout << "LISTAR SALAS";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(57,15); cout << "CARGAR UNA NUEVA SALA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(58,18); cout << "MODIFICAR UNA SALA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(61,21); cout << "LISTAR SALAS";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(57,15); cout << "CARGAR UNA NUEVA SALA";
        recuadro(36,17,60,2);
        gotoxy(58,18); cout << "MODIFICAR UNA SALA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(61,21); cout << "LISTAR SALAS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(57,15); cout << "CARGAR UNA NUEVA SALA";
        recuadro(36,17,60,2);
        gotoxy(58,18); cout << "MODIFICAR UNA SALA";
        recuadro(36,20,60,2);
        gotoxy(61,21); cout << "LISTAR SALAS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,28,70,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        }
        opc = getch();
    }
}
void adminPeliculas(){
    pelicula p;
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    recuadro(26,10,80,25); ///
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
        switch(opc){
        case 80: //ABAJO
        pos++;
        if(pos>4){pos=1;}
        break;
        case 72: //ARRIBA
        pos--;
        if(pos<1){pos=4;}
        break;
        case 13: //ENTER
        switch(pos){
        case 1:
        p.cargar(false);
        break;
        case 2:
        p.modificar();
        break;
        case 3:
        p.leePos();
        break;
        case 4:
        menuAdmin();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(55,15); cout << "CARGAR UNA NUEVA PELICULA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "LISTAR PELICULAS";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(55,15); cout << "CARGAR UNA NUEVA PELICULA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "LISTAR PELICULAS";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(55,15); cout << "CARGAR UNA NUEVA PELICULA";
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(59,21); cout << "LISTAR PELICULAS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(55,15); cout << "CARGAR UNA NUEVA PELICULA";
        recuadro(36,17,60,2);
        gotoxy(56,18); cout << "MODIFICAR UNA PELICULA";
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "LISTAR PELICULAS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        }
        opc = getch();
    }
}
void adminFunciones(){
    funcion f;
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    recuadro(26,10,80,25); ///
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
        switch(opc){
        case 80: //ABAJO
        pos++;
        if(pos>4){pos=1;}
        break;
        case 72: //ARRIBA
        pos--;
        if(pos<1){pos=4;}
        break;
        case 13: //ENTER
        switch(pos){
        case 1:
        f.cargar(false);
        break;
        case 2:
        f.modificar();
        break;
        case 3:
        f.leePos();
        break;
        case 4:
        menuAdmin();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(58,15); cout << "CARGAR UNA FUNCION";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(57,18); cout << "MODIFICAR UNA FUNCION";
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "LISTAR FUNCIONES";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(58,15); cout << "CARGAR UNA FUNCION";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(57,18); cout << "MODIFICAR UNA FUNCION";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "LISTAR FUNCIONES";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(58,15); cout << "CARGAR UNA FUNCION";
        recuadro(36,17,60,2);
        gotoxy(57,18); cout << "MODIFICAR UNA FUNCION";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(59,21); cout << "LISTAR FUNCIONES";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(58,15); cout << "CARGAR UNA FUNCION";
        recuadro(36,17,60,2);
        gotoxy(57,18); cout << "MODIFICAR UNA FUNCION";
        recuadro(36,20,60,2);
        gotoxy(59,21); cout << "LISTAR FUNCIONES";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        }
        opc = getch();
    }
}
void adminVentas(){
    system("cls");
    ShowConsoleCursor(false);
    int opc, pos=1;
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    recuadro(26,10,80,25); ///
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(27,32);
    for (int i=0; i <= 78; i++)cout << char (205);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39, 7);
    while(true){
    switch(opc){
    case 80: //ABAJO
    pos++;
    if(pos>4){pos=1;}
    break;
    case 72: //ARRIBA
    pos--;
    if(pos<1){pos=4;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            ///clientes();
        break;
        case 2:
            ///facturas();
        break;
        case 3:
            ///cerrarcaja();
        break;
        case 4:
            menuAdmin();
        break;
        }
        }
        switch(pos){
        case 1:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,14,70,2);
        gotoxy(59,15); cout << "CLIENTES";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "FACTURAS";
        recuadro(36,20,60,2);
        gotoxy(61,21); cout << "CERRAR CAJA";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 2:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(59,15); cout << "CLIENTES";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,17,70,2);
        gotoxy(63,18); cout << "FACTURAS";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,20,60,2);
        gotoxy(61,21); cout << "CERRAR CAJA";
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 3:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(59,15); cout << "CLIENTES";
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "FACTURAS";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(31,20,70,2);
        gotoxy(61,21); cout << "CERRAR CAJA";
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        case 4:
        for(int x=14;x<=30;x++){
        gotoxy(31,x); cout <<"     ";
        gotoxy(97,x); cout <<"     ";
        }
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(hConsole, 7);
        recuadro(36,14,60,2);
        gotoxy(59,15); cout << "CLIENTES";
        recuadro(36,17,60,2);
        gotoxy(63,18); cout << "FACTURAS";
        recuadro(36,20,60,2);
        gotoxy(61,21); cout << "CERRAR CAJA";
        SetConsoleTextAttribute(hConsole, 4);
        recuadro(36,28,60,2);
        gotoxy(60,29);cout <<  "VOLVER   ATRAS";
        break;
        }
        opc = getch();
    }
}

///Configuracion:
void passConf(){
    int ps1;
    int ps2;
    system("cls");
    ShowConsoleCursor(true);
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(8,4,116,37);
    recuadro(26,10,80,25);
    SetConsoleTextAttribute(hConsole, 4);
    logo(39,7);
    gotoxy(36,18); cout << "PUEDE CONTENER UN MAXIMO DE 15 CARACTERES LETRAS Y NUMEROS";
    SetConsoleTextAttribute(hConsole, 7);
    password pass;
    recuadro(36,30,60,4);
    recuadro(38,31,26,2);
    gotoxy(47,32); cout << "CANCELAR";
    recuadro(67,31,26,2);
    gotoxy(73,32); cout << "GUARDAR CAMBIOS";
    gotoxy(36,17); cout << "INGRESE SU NUEVA 'PASSWORD'";
    recuadro(36,20,60,2);
    gotoxy(36,23); cout << "INGRESE NUEVAMENTE SU 'PASSWORD'";
    recuadro(36,25,60,2);
    gotoxy(38,21);
    cin >> ps1;
    gotoxy(38,26);
    cin >> ps2;
    if(ps1 == ps2){
        pass.cc = ps1;
    }
    ShowConsoleCursor(false);
    int opc, pos=1;
    while(true){
        switch(opc){
            case 75: //IZQUIERDA
                pos++;
                if(pos>2){pos=1;}
            break;
            case 77: //DERECHA
                pos--;
                if(pos<1){pos=2;}
            break;
            case 13: //ENTER
                switch(pos){
                    case 1:
                        menuAdmin();
                    break;
                    case 2:
                        remove("PP/pass.txt");
                        FILE *f;
                        f = fopen("PP/pass.txt","ab");
                        if(f == NULL){
                            fclose(f);
                        }
                        fwrite(&pass, sizeof(password),1,f);
                        fclose(f);
                        menuAdmin();
                    break;
                    }
                }
        switch(pos){
            case 1:
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(38,31,26,2);
                gotoxy(47,32); cout << "CANCELAR";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(67,31,26,2);
                gotoxy(73,32); cout << "GUARDAR CAMBIOS";
            break;
            case 2:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(38,31,26,2);
                gotoxy(47,32); cout << "CANCELAR";
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(67,31,26,2);
                gotoxy(73,32); cout << "GUARDAR CAMBIOS";
            break;
        }
        opc = getch();
    }

}



#endif // MENUES_H_INCLUDED
