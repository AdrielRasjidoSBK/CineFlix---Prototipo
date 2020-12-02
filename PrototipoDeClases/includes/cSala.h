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
    bool cargar();
    bool guardar();
    void listar();
    void leePos();
    void modificar();
    void modificarDisco(int pos);
    void generadorDeButacas(int c,int f);
    void mostrarButacas();
    int  leedisco(int pos);
    int  buscar(int _num,char _loc[50]);
    void BuscarLoc();
    void buscarxLoc(char _loc[50]);
    void genCod();

    ///gets
    int getnum(){return num;}
    int getcantColumna(){return cantColumna;}
    int getcantFila(){return cantFila;}
    int getcap(){return cap;}
    int gettipo(){return tipo;}
    int **getbutacas(){return butacas;}
    char *getlocalidad(){return localidad;}
};



void sala::BuscarLoc(){
	char _loc[50];
	system("cls");
	cout<<"Ingrese la localidad: ";
	cin.ignore();
	cin.getline(_loc,50);
	buscarxLoc(_loc);
}

void sala::buscarxLoc(char _loc[50]){
	int pos=0;
    funcion f;
	while(leedisco(pos++)==1){
    if(stricmp(_loc,localidad)==0){
        f.xlocalidad(codSala);
    }
    }
}

void sala::generadorDeButacas(int c,int f){ ///x Funcion
    srand (time(NULL));
    int i,j;

    /// creamos la matriz !
    int **M = new int* [f];
    for (i = 0; i < f; i++)
        M[i] = new int[c];

    /// Comprobamos si se puede
    if (!M){
        cout<< "No se puede reservar el espacio" << endl;
    }else{
        cout<< "Se a creado las butacas con exito!"<<endl;
    }

    /// Asignamos un valor a esa matriz
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
            M[i][j] = rand()%3;

    butacas = M;
    delete(M);
}

bool sala::cargar(){
    system("cls");
    genCod();
    cout<<"Numero de la sala: ";
    cin>> num;
    cout<<"Cantidad de columnas: ";
    cin>> cantColumna;
    cout<<"Cantidad de filas: ";
    cin>> cantFila;
    cap=cantColumna*cantFila;
    generadorDeButacas(cantColumna,cantFila);
    cout<<"Capacidad: "<<cap<<endl;
    cout<<"Tipo de sala: ";
    cin>> tipo;
    cout<<"Localidad: ";
    cin.ignore();
    cin.getline(localidad,50);

    system("pause");
    return true;
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

bool sala::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/salas.dat","ab");
    if(p==NULL){return false;
    }
    grabo=fwrite(this, sizeof(sala),1,p);
    fclose(p);
return grabo;
}

void sala::leePos(){
	int pos=0;
	system("cls");
	while(leedisco(pos++)==1){
        listar();
    }
	if(pos==1){
    cout<<"No existen registros"<<endl;
    }
    system("pause>NULL");
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

void sala::listar(){
    char opc;
    cout<<endl<<endl;
    cout<<localidad<<endl;
    cout<<"Sala numero: "<<num<<"\t tipo: "<<tipo<<endl;
    cout<<"Capacidad: "<<cap<<endl;
    cout<<"Esta sala contiene "<<cantColumna<<" columnas y "<<cantFila<<" filas.";
    cout<<endl<<endl;
}

void sala::modificar(){
	int _num,pos;
	char _loc[50];
	system("cls");
	cout<<"Ingrese el Num de sala: ";
	cin>>_num;
	cout<<"Ingrese la localidad: ";
	cin.ignore();
	cin.getline(_loc,50);
	pos=buscar(_num,_loc);
	if(pos!=-1){
    cout<<"YA PUEDES MODIFICAR"<<endl<<endl;
    cargar();
    modificarDisco(pos);
    }else{
    cout<<"No existe este DNI"<<endl;
    system("pause>nul");
    }
}

int  sala::buscar(int _num, char _loc[50]){
	int pos=0;
	while(leedisco(pos)==1){
    if(_num == num && stricmp(_loc,localidad)==0){
        return pos;
    }pos++;
    }return -1;
}

void sala::modificarDisco(int pos){
	FILE *p;
	p=fopen("Dat/salas.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";fclose(p);exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	system("pause");
}






#endif // CSALA_H_INCLUDED
