#ifndef CPELICULA_H_INCLUDED
#define CPELICULA_H_INCLUDED

class pelicula{
private:
    int         idcodigo;       ///GENERA UN CODIGO UNICO POR PELICULA
    char        titulo[40];
    char        sipnosis[400];
    int         clasificacion;
    int         genero;
    int         duracion;
    char        portada[40];
    char        director[40];
public:
    void cargar(bool _modificacion);
    bool guardar();
    void listar(int pos2);
    void leePos();
    void modificar();
    void modificarDisco(int pos);
    void generadorDeButacas(int c,int f);
    void mostrarButacas();
    void genCod();
    int  leedisco(int pos);
    int  buscar(int _num);
    int  duracionP(int _num);
    int  SeleccionClasf();
    int  SeleccionGenero();
    int  UltPos();
    char *getTitulo(){return titulo;}
};

///Funciones visuales y de uso general:
int  pelicula::duracionP(int _num){
    int pos=0;
	system("cls");
	while(leedisco(pos++)==1){
        if(_num==idcodigo){
            return duracion;
        }
    }
	if(pos==1){
    cout<<"No existen registros"<<endl;
    }
    return -1;
}
void pelicula::genCod(){
    int pos=1;
    FILE *p;
	p=fopen("Dat/peliculas.dat","rb");
	if(p==NULL){
        idcodigo = pos;
        fclose(p);
        return;
    }
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    idcodigo = pos;
    fclose(p);
}
int  pelicula::UltPos(){
    int pos=-1;
    FILE *p;
	p=fopen("Dat/peliculas.dat","rb");
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    fclose(p);
    return pos;
}
int  pelicula::SeleccionGenero(){
int opc = 0, pos=1;
while(true){
    ShowConsoleCursor(false);
    switch(opc){
    case 77:
    pos++;
    if(pos>5){pos=1;}
    break;
    case 75:
    pos--;
    if(pos<1){pos=5;}
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
        case 4:
            return 4;
        break;
        case 5:
            return 5;
        break;
        }
        }
        switch(pos){
        case 1:
            recuadro(106,16,14,2);
            gotoxy(110,17); cout << "ACCION";
        break;
        case 2:
            recuadro(106,16,14,2);
            gotoxy(110,17); cout << "TERROR";
        break;
        case 3:
            recuadro(106,16,14,2);
            gotoxy(110,17); cout << "COMEDIA";
        break;
        case 4:
            recuadro(106,16,14,2);
            gotoxy(109,17); cout << "C.FICCION";
        break;
        case 5:
            recuadro(106,16,14,2);
            gotoxy(109,17); cout << "ANIMACION";
        break;
        }
        opc = getch();
    }
}
int  pelicula::SeleccionClasf(){
int opc, pos=1;
while(true){
    ShowConsoleCursor(false);
    switch(opc){
    case 77:
    pos++;
    if(pos>4){pos=1;}
    break;
    case 75:
    pos--;
    if(pos<1){pos=4;}
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
        case 4:
            return 4;
        break;
        }
        }
        switch(pos){
        case 1:
            recuadro(90,16,14,2);
            gotoxy(96,17); cout << "ATP";
        break;
        case 2:
            recuadro(90,16,14,2);
            gotoxy(96,17); cout << "+13";
        break;
        case 3:
            recuadro(90,16,14,2);
            gotoxy(96,17); cout << "+18";
        break;
        case 4:
            recuadro(90,16,14,2);
            gotoxy(93,17); cout << " R ";
        break;
        }
        opc = getch();
    }
}

///Funciones de Busqueda:
int  pelicula::buscar(int _num){
	int pos=0;
	while(leedisco(pos)==1){
    if(_num == idcodigo){
        return pos;
    }
    pos++;
    }
	return -1;
}

///Funciones de carga:
void pelicula::modificar(){
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
    gotoxy(36,18); cout << "INGRESE EL 'CODIGO DE LA PELICULA'";
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
void pelicula::cargar(bool _modificacion){
    system("cls");
    if(_modificacion==false){genCod();}
    ShowConsoleCursor(true);
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    logo(65,6);
    SetConsoleTextAttribute(hConsole, 7);
    recuadro(10,6,50,33);
    gotoxy(14,8); cout << "TITULO: ";
    gotoxy(12,9); for (int i=0; i <= 45; i++)cout << char (205);
    gotoxy(14,10); cout << "DESCRICION: ";
    gotoxy(65,14); cout << "NOMBRE DIRECTOR: ";
    recuadro(90,13,30,2);
    gotoxy(65,17); cout << "CLASIFICACION: ";
    recuadro(90,16,14,2);
    recuadro(106,16,14,2);
    gotoxy(65,20); cout << "CODIGO DE PELICULA: ";
    recuadro(90,19,14,2);
    gotoxy(65,23); cout << "DURACION EN MINUTOS: ";
    recuadro(90,22,14,2);
    gotoxy(65,29); cout << "INGRESE EL NOMBRE DE LA RUTA PARA LA PORTADA 'NAME'";
    recuadro(65,31,55,2);
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(65,35,55,4);
    gotoxy(94,20); cout << idcodigo;
    SetConsoleTextAttribute(hConsole, 7);
    if(_modificacion==false){
    gotoxy(70,37); cout << "GUARDAR PELICULA?";
    recuadro(90,36,13,2);
    gotoxy(96,37); cout << "SI";
    recuadro(106,36,13,2);
    gotoxy(112,37); cout << "NO";
    }else{
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(70,37); cout << "-COMPLETE TODOS LOS CAMPOS SOLICITADOS-";
    SetConsoleTextAttribute(hConsole, 7);
    }
    gotoxy(22,8); cin.ignore();
    cin.getline(titulo,40);
    ///FALTA COMPROBAR
    gotoxy(14,12); cin.getline(sipnosis,400);
    gotoxy (92, 14); cin.getline(director,40);
    clasificacion = SeleccionClasf();
    genero = SeleccionGenero();
    ShowConsoleCursor(true);
    gotoxy (94, 23); cin >> duracion;
    gotoxy(67,32); cin.getline(portada,45);
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
                        adminPeliculas();
                    break;
                    case 2:
                        adminPeliculas();
                    break;
                    }
                    }
        switch(pos){
            case 1:
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(90,36,13,2);
                gotoxy(96,37); cout << "SI";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(106,36,13,2);
                gotoxy(112,37); cout << "NO";
            break;
            case 2:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(90,36,13,2);
                gotoxy(96,37); cout << "SI";;
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(106,36,13,2);
                gotoxy(112,37); cout << "NO";
            break;
            }
        opc = getch();
}
}
SetConsoleTextAttribute(hConsole, 2);
gotoxy(70,37); cout << "----LOS DATOS DE LA PELICULA FUERON MODIFICADOS----";
system("pause>NULL");
}
bool pelicula::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/peliculas.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(pelicula),1,p);
    fclose(p);
return grabo;
}

///Funciones de muestra:
void pelicula::listar(int pos2){
    system("cls");
    ShowConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 4);
    recuadro(8,4,116,37);  /// RECUADRO PRINCIPAL
    logo(65,6);
    SetConsoleTextAttribute(hConsole, 7);
    recuadro(10,6,50,33);  /// PORTADA
    recuadro(65,13,54,20);
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(67,15); cout << "TITULO:";
    gotoxy(67,17); cout << "SIPNOSIS:";
    gotoxy(67,30); cout << "CODIGO:";
    gotoxy(67,31); cout << "DURACION";
    gotoxy(67,28); cout << "By: " << director;
    gotoxy(95,28);
    switch(clasificacion){
        case 1:
            cout << "[ATP]";
        break;
        case 2:
            cout << "[+13]";
        break;
        case 3:
            cout << "[+18]";
        break;
        case 4:
            cout << "[ R ]";
        break;
    }
    gotoxy(101,28);
    switch(genero){
        case 1:
            cout << "GENERO: ACCION";
        break;
        case 2:
            cout << "GENERO: TERROR";
        break;
        case 3:
            cout << "GENERO: COMEDIA";
        break;
        case 4:
            cout << "GENERO: C.FICCION";
        break;
        case 5:
            cout << "GENERO: ANIMACION";
        break;
    }
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(80,15); cout << titulo;
    gotoxy(80,17); cout << sipnosis;
    gotoxy(80,30); cout << idcodigo;
    gotoxy(67,16); for (int i=0; i <= 50; i++)cout << char (205);
    gotoxy(67,29); for (int i=0; i <= 50; i++)cout << char (205);
    gotoxy(80,31); cout << duracion << " minutos";
    recuadro(65,35,54,4);
    recuadro(67,36,16,2);
    gotoxy(72,37); cout << "ANTERIOR";
    recuadro(84,36,16,2);
    gotoxy(88,37); cout << "SIGUIENTE";
    recuadro(101,36,16,2);
    gotoxy(107,37); cout << "SALIR";
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
                adminPeliculas();
                break;
                }
            }
            switch(pos){
                case 1:
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(67,36,16,2);
                gotoxy(72,37); cout << "ANTERIOR";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(84,36,16,2);
                gotoxy(88,37); cout << "SIGUIENTE";
                recuadro(101,36,16,2);
                gotoxy(107,37); cout << "SALIR";
                break;
                case 2:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(67,36,16,2);
                gotoxy(72,37); cout << "ANTERIOR";
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(84,36,16,2);
                gotoxy(88,37); cout << "SIGUIENTE";
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(101,36,16,2);
                gotoxy(107,37); cout << "SALIR";
                break;
                case 3:
                SetConsoleTextAttribute(hConsole, 7);
                recuadro(67,36,16,2);
                gotoxy(72,37); cout << "ANTERIOR";
                recuadro(84,36,16,2);
                gotoxy(88,37); cout << "SIGUIENTE";
                SetConsoleTextAttribute(hConsole, 6);
                recuadro(101,36,16,2);
                gotoxy(107,37); cout << "SALIR";
                break;
            }
            opc = getch();
    }

}

///Funciones - Manejo de archivos:
void pelicula::leePos(){
    int pos2=0;
	system("cls");
	if(leedisco(pos2)==1){
        listar(pos2);
	}
}
int  pelicula::leedisco(int pos){
	int x;
	FILE *p;
	p=fopen("Dat/peliculas.dat","rb");
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}
void pelicula::modificarDisco(int pos){
	FILE *p;
	p=fopen("Dat/peliculas.dat","rb+");
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
}


#endif // CPELICULA_H_INCLUDED
