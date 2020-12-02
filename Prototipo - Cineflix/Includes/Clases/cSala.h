#ifndef CSALA_H_INCLUDED
#define CSALA_H_INCLUDED

#include "cFuncion.h"

class sala{
private:
    int         codSala;
    int         num; ///NUMERO DE LA SALA?
    int         cantColumna; ///CANTIDAD DE COLUMNAS QUE HABRA
    int         cantFila; ///CANTIDAD DE FILAS QUE HABRA
    int         cap; ///columna * fila
    int         tipo; /// 2D , 3D, XD
    char        localidad[50];
    int         **butacas; ///duda existencial - ¿SE PODRA HACER UN VECTOR DINAMICO?
public:
    void        cargar(bool _modificacion);
    bool        guardar();
    void        listar(int pos2);
    void        leePos();
    void        modificar();
    void        modificarDisco(int pos);
    void        mostrarButacas();
    int         leedisco(int pos);
    int         buscar(int _num);
    int         ElejirTipo();
    void        BuscarLoc();
    void        buscarxLoc(char _loc[50]);
    void        genCod();
    int         UltPos();

    ///gets
    int         getnum(){return num;}
    int         getcantColumna(){return cantColumna;}
    int         getcantFila(){return cantFila;}
    int         getcap(){return cap;}
    int         gettipo(){return tipo;}
    int         **getbutacas(){return butacas;}
    char        *getlocalidad(){return localidad;}
};

///Funciones visuales y de uso general:
int  sala::ElejirTipo(){
int opc, pos=1;
while(true){
    ShowConsoleCursor(false);
    switch(opc){
    case 77:
    pos++;
    if(pos>3){pos=1;}
    break;
    case 75:
    pos--;
    if(pos<1){pos=3;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            return 1;
        break;
        case 2:
            return 2;
        break;
        case 3:
            return 3;
        break;
        }
        }
        switch(pos){
        case 1:
            recuadro(47,26,19,2);
            gotoxy(49,27); cout << "2.D";
        break;
        case 2:
            recuadro(47,26,19,2);
            gotoxy(49,27); cout << "3.D";
        break;
        case 3:
            recuadro(47,26,19,2);
            gotoxy(49,27); cout << "X.D";
        break;
        }
        opc = getch();
    }
}
void sala::genCod(){
    int pos=1;
    FILE *p;
	p=fopen("Dat/salas.dat","rb");
	if(p==NULL){
        codSala = pos;
        fclose(p);
        return;
    }
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    codSala = pos;
    fclose(p);
}
int  sala::UltPos(){
    int pos=-1;
    FILE *p;
	p=fopen("Dat/salas.dat","rb");
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    fclose(p);
    return pos;
}
int  sala::buscar(int _num){
	int pos=0;
	while(leedisco(pos)==1){
    if(codSala == _num){
        return pos;
    }pos++;
    }return -1;
}



///Funciones de carga:
void sala::modificar(){
    int _cod,pos2;
    system("cls");
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
    gotoxy(36,18); cout << "INGRESE EL 'NUMERO EL CODIGO DE SALA'";
    recuadro(36,20,60,2);
    gotoxy(38,21); cin >> _cod;
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
        adminSalas();
        break;
        case 2:
        pos2=buscar(_cod);
        if(pos2!=-1){
        SetConsoleTextAttribute(hConsole,2);
        gotoxy(36,19); cout << "CODIGO CORRECTO";
        system("pause>NULL");
        cargar(true);
        modificarDisco(pos2);
        adminSalas();
        }else{
        SetConsoleTextAttribute(hConsole, 4);
        gotoxy(36,19); cout << "CODIGO ERRONEO";
        system("pause>NULL");
        adminSalas();
        }
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
void sala::cargar(bool _modificacion){
    system("cls");
    if(_modificacion==false){genCod();}
    ShowConsoleCursor(true);
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(8,4,116,37); /// RECUADRO PRINCIPAL
    logo(12,6);
    gotoxy(18,12); cout << "----- EL CODIGO DE SALA ES: " << codSala << " -----";
    SetConsoleTextAttribute(hConsole, 7);
    recuadro(70,6,50,33);  /// PORTADA
    recuadro(47,14,19,2);
    gotoxy(12,15); cout << "NUMERO DE SALA:";
    recuadro(47,17,19,2);
    gotoxy(12,18); cout << "CANTIDAD DE FILAS:";
    recuadro(47,20,19,2);
    gotoxy(12,21); cout << "CANTIDAD DE COLUMNAS:";
    recuadro(47,23,19,2);
    gotoxy(12,24); cout << "CAPACIDAD:";
    recuadro(47,26,19,2);
    gotoxy(12,27); cout << "TIPO DE SALA:";
    recuadro(47,29,19,2);
    gotoxy(12,30); cout << "LOCALIDAD:";
    recuadro(12,35,54,4);
    if(_modificacion == false){
    gotoxy(14,37); cout << "QUE HACER CON LA SALA";
    recuadro(51,36,12,2);
    gotoxy(55,37); cout << "CREAR";
    recuadro(37,36,12,2);
    gotoxy(39,37); cout << "CANCELAR";
    }else{
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(20,37); cout << "-COMPLETE TODOS LOS CAMPOS SOLICITADOS-";
    SetConsoleTextAttribute(hConsole, 7);
    }
    gotoxy(49,15); cin >> num;
    gotoxy(49,18); cin >> cantFila;
    gotoxy(49,21); cin >> cantColumna;
    cap=cantColumna*cantFila;
    gotoxy(49,24); cout << cap;
    tipo = ElejirTipo();
    ShowConsoleCursor(true);
    gotoxy(49,30);
    cin.ignore();
    cin.getline(localidad,50);
    if(_modificacion == false){
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
                guardar();
                adminSalas();
                return;
                break;
                case 2:
                adminSalas();
                break;
                }
            }
            switch(pos){
                case 1:
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(51,36,12,2);
                gotoxy(55,37); cout << "CREAR";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(37,36,12,2);
                gotoxy(39,37); cout << "CANCELAR";
                break;
                case 2:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(51,36,12,2);
                gotoxy(55,37); cout << "CREAR";
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(37,36,12,2);
                gotoxy(39,37); cout << "CANCELAR";
                break;
            }
            opc = getch();
    }
}
SetConsoleTextAttribute(hConsole, 2);
gotoxy(14,37); cout << "-LOS DATOS DE LA SALA FUERON MODIFICADOS CON EXITO-";
system("pause>NULL");
}
bool sala::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/salas.dat","ab");
    if(p==NULL){return false;
    }
    grabo=fwrite(this, sizeof(sala),1,p);
    fclose(p);
return grabo;
}

///Funciones de muestra:
void sala::listar(int pos2){
    system("cls");
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(8,4,116,37); /// RECUADRO PRINCIPAL
    logo(12,6);
    gotoxy(18,12); cout << "----- EL CODIGO DE SALA ES: " << codSala << " -----";
    gotoxy(49,15); cout << num;
    gotoxy(49,18); cout << cantFila;
    gotoxy(49,21); cout << cantColumna;
    gotoxy(49,24); cout << cap;
    switch(tipo){
    case 1:
        gotoxy(49,27); cout << "2.D";
    break;
    case 2:
        gotoxy(49,27); cout << "3.D";
    break;
    case 3:
        gotoxy(49,27); cout << "X.D";
    break;
    }
    gotoxy(49,30); cout << localidad;
    SetConsoleTextAttribute(hConsole, 7);
    recuadro(70,6,50,33);  /// PORTADA
    gotoxy(12,15); cout << "NUMERO DE SALA:";
    gotoxy(12,18); cout << "CANTIDAD DE FILAS:";
    gotoxy(12,21); cout << "CANTIDAD DE COLUMNAS:";
    gotoxy(12,24); cout << "CAPACIDAD:";
    gotoxy(12,27); cout << "TIPO DE SALA:";
    gotoxy(12,30); cout << "LOCALIDAD:";
    recuadro(12,35,54,4);
    recuadro(14,36,16,2);
    gotoxy(19,37); cout << "ANTERIOR";
    recuadro(31,36,16,2);
    gotoxy(35,37); cout << "SIGUIENTE";
    recuadro(48,36,16,2);
    gotoxy(54,37); cout << "SALIR";
    ShowConsoleCursor(false);
    int opc, pos=1;
    while(true){
        switch(opc){
            case 77: //IZQUIERDA
            pos++;
            if(pos>3){pos=1;}
            break;
            case 75: //DERECHA
            pos--;
            if(pos<1){pos=3;}
            break;
            case 13: //ENTER
            switch(pos){
                case 1:
                pos2--;
                if(pos2==-1){
                pos2 = UltPos();
                leedisco(pos2);
                listar(pos2);
                }
                leedisco(pos2);
                listar(pos2);
                break;
                case 2:
                pos2++;
                if(leedisco(pos2)==1){
                    listar(pos2);
                }else{
                leedisco(0);
                listar(0);
                }
                break;
                case 3:
                adminSalas();
                break;
                }
            }
            switch(pos){
                case 1:
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(14,36,16,2);
                gotoxy(19,37); cout << "ANTERIOR";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(31,36,16,2);
                gotoxy(35,37); cout << "SIGUIENTE";
                recuadro(48,36,16,2);
                gotoxy(54,37); cout << "SALIR";
                break;
                case 2:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(14,36,16,2);
                gotoxy(19,37); cout << "ANTERIOR";
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(31,36,16,2);
                gotoxy(35,37); cout << "SIGUIENTE";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(48,36,16,2);
                gotoxy(54,37); cout << "SALIR";
                break;
                case 3:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(14,36,16,2);
                gotoxy(19,37); cout << "ANTERIOR";
                recuadro(31,36,16,2);
                gotoxy(35,37); cout << "SIGUIENTE";;
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(48,36,16,2);
                gotoxy(54,37); cout << "SALIR";
                break;
            }
            opc = getch();
    }
}

///Funciones - manejo de archivos:
void sala::leePos(){
	int pos2=0;
	system("cls");
	if(leedisco(pos2)==1){
        listar(pos2);
	}
}
int  sala::leedisco(int pos){
	int x;
	FILE *p;
	p=fopen("Dat/salas.dat","rb");
	if(p==NULL){
    cout<<"No existe el archivo";
    system("pause<null");
    return 0;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}
void sala::modificarDisco(int pos){
	FILE *p;
	p=fopen("Dat/salas.dat","rb+");
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
}






#endif // CSALA_H_INCLUDED
