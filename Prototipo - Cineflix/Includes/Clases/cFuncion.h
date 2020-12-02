#ifndef CFUNCION_H_INCLUDED
#define CFUNCION_H_INCLUDED

#include "cSala.h"
#include "cCalendario.h"
#include "cPelicula.h"


class funcion{
private:
    int         codsala; ///debe existir en sala
    int         cpelicula; ///debe existir en pelicula
    int         codFuncion; ///genera un cod unico
    hora        horario;    ///horario por una sola funcion
    fecha       fechaDisponibles;   ///fecha de esa funcion
    float       precio;     ///precio para era funcion
public:
    bool guardar();
    void cargar(bool _modificacion);
    void leePos();
    void genCod();
    void listar();
    void modificarDisco(int pos);
    int  ultimaPos();
    int  recaudado();
    int  leedisco(int pos);
    void modificar();
    int  buscar(int _num);
    void xlocalidad(int _cs);
    void xfecha();

    float getPrecio(){return precio;}
};

///Funciones visuales y de uso general:
void funcion::genCod(){
    int pos=1;
    FILE *p;
	p=fopen("Dat/funciones.dat","rb");
	if(p==NULL){
        codFuncion = pos;
        fclose(p);
        return;
    }
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    codFuncion = pos;
    fclose(p);
}
int  funcion::ultimaPos(){
    int pos=-1;
    FILE *p;
	p=fopen("Dat/funciones.dat","rb");
	if(p==NULL){
        fclose(p);
        return pos;
    }
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    fclose(p);
    return pos;
}


int  funcion::buscar(int _num){
	int pos=0;
	while(leedisco(pos++)==1){
    if(_num == codFuncion){
        return pos;
    }
    }
	return -1;
}


void funcion::cargar(bool _modificacion){
    if(_modificacion==false){genCod();}
    ShowConsoleCursor(true);
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    logo(65,6);
    SetConsoleTextAttribute(hConsole, 7);
    recuadro(10,6,50,33);  /// PORTADA

    recuadro(90,13,29,2);
    gotoxy(65,14); cout << "CODIGO DE FUNCION: ";
    recuadro(90,16,29,2);
    gotoxy(65,17); cout << "CODIGO DE PELICULA: ";
    recuadro(90,19,29,2);
    gotoxy(65,20); cout << "CODIGO DE SALA: ";
    recuadro(90,22,29,2);
    gotoxy(65,23); cout << "FECHA DE FUNCION: ";
    gotoxy(103,23); cout << "/";
    gotoxy(106,23); cout << "/";
    recuadro(90,25,29,2);
    gotoxy(65,26); cout << "HORARIO: ";
    gotoxy(104,26); cout << ":";
    recuadro(90,28,29,2);
    gotoxy(65,29); cout << "FECHA DE FUNCION: ";
    recuadro(90,31,29,2);
    gotoxy(65,32); cout << "PRECIO DE FUNCION: ";
    gotoxy(100,14); cout << codFuncion;

    SetConsoleTextAttribute(hConsole, 4);
    recuadro(65,35,55,4);
    SetConsoleTextAttribute(hConsole, 7);
    if(_modificacion==false){
    gotoxy(70,37); cout << "GUARDAR FUNCION?";
    recuadro(90,36,13,2);
    gotoxy(96,37); cout << "SI";
    recuadro(105,36,13,2);
    gotoxy(111,37); cout << "NO";
    }else{
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(70,37); cout << "-COMPLETE TODOS LOS CAMPOS SOLICITADOS-";
    SetConsoleTextAttribute(hConsole, 7);
    }
    int dd,mm,aa,h,m;
    gotoxy(100,17); cin >> cpelicula;
    gotoxy(100,20); cin >> codsala;
    gotoxy(100,23); cin >> dd;
    gotoxy(104,23); cin >> mm;
    gotoxy(107,23); cin >> aa;
    fechaDisponibles.cargar(dd,mm,aa);
    gotoxy(100,26); cin >> h;
    gotoxy(106,26); cin >> m;
    horario.cargar(h,m);

    ShowConsoleCursor(false);
    if(_modificacion==false){
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
                        adminFunciones();
                    break;
                    case 2:
                        adminFunciones();
                    break;
                    }
                    }
        switch(pos){
            case 1:
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(90,36,13,2);
                gotoxy(96,37); cout << "SI";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(105,36,13,2);
                gotoxy(111,37); cout << "NO";
            break;
            case 2:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(90,36,13,2);
                gotoxy(96,37); cout << "SI";;
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(105,36,13,2);
                gotoxy(111,37); cout << "NO";
            break;
            }
        opc = getch();
}
}
SetConsoleTextAttribute(hConsole, 2);
gotoxy(70,37); cout << "----LOS DATOS DE LA FUNCION FUERON MODIFICADOS!----";
system("pause>NULL");

}
bool funcion::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/funciones.dat","ab");
    if(p==NULL){
        fclose(p);
        return false;
    }
    grabo=fwrite(this, sizeof(funcion),1,p);
    fclose(p);
return grabo;
}

///Funciones de muestra:
void funcion::leePos(){
    system("cls");
    ShowConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    logo(22,6);
    for (int i=5; i < 41; i++){ /// LÍNEA VERTICAL
        gotoxy(90,i); cout << char (186);
    }
    int pos = 0, x = 0;
    int dd,mm,aa;
    time_t tiempo;
    struct tm *tmPtr;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    dd= tmPtr->tm_mday;
    mm= tmPtr->tm_mon+1;
    aa=1900+tmPtr->tm_year;

    pelicula p;
    pos = p.buscar(cpelicula);
    p.leedisco(pos);

    while(leedisco(pos++)&& x<14){
        if(dd==fechaDisponibles.getDia()&&mm==fechaDisponibles.getMes()&&aa==fechaDisponibles.getAnio()){
        gotoxy(12,13+(x*2));
        SetConsoleTextAttribute(hConsole, 6);
        cout << char(219) << char(195) << " C" << codFuncion << " ";
        SetConsoleTextAttribute(hConsole, 7);
        cout << char(175) << " " << p.getTitulo();
        SetConsoleTextAttribute(hConsole, 6);
        gotoxy(48,13+(x*2));
        cout << char(175) << " " << fechaDisponibles.getDia() << "/";
        cout << fechaDisponibles.getMes() << "/" << fechaDisponibles.getAnio() << " ";
        SetConsoleTextAttribute(hConsole, 7);
        cout << char(175) << " Sala " << /*s.getnum(); <<*/ " - ";
        cout << horario.gethoras() << ":" << horario.getminutos() << " " << char(175) << " " << precio;
        x++;
        }
    }
    system("pause>NULL");
}

///Funciones - Manejo de archivos:
void funcion::modificar(){
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
    gotoxy(36,18); cout << "INGRESE EL 'CODIGO DE LA FUNCION'";
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
        adminFunciones();
        }else{
        SetConsoleTextAttribute(hConsole, 4);
        gotoxy(36,19); cout << "CODIGO ERRONEO";
        system("pause>NULL");
        adminFunciones();
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
int  funcion::leedisco(int pos){
	int x;
	FILE *p;
	p=fopen("Dat/funciones.dat","rb");
	if(p==NULL){
    cout<<"No existe el archivo";
    system("pause<null");
    fclose(p);
    return 0;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}
void funcion::modificarDisco(int pos){
	FILE *p;
	p=fopen("Dat/funciones.dat","rb+");
	if(p==NULL){cout<<"Error de archivo"; fclose(p); exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	system("pause");
}


#endif // CFUNCION_H_INCLUDED
