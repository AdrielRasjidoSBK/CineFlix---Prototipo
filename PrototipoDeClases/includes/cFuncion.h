#ifndef CFUNCION_H_INCLUDED
#define CFUNCION_H_INCLUDED

#include "cCalendario.h"

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
    void cargar();
    void leePos();
    void genCod();
    void listar();
    void modificarDisco(int pos);
    int ultimaPos();
    int recaudado();
    int leedisco(int pos);
    void modificar();
    int buscar(int _num);
    void xlocalidad(int _cs);
    void xfecha();

    float getPrecio(){return precio;}
};

void funcion::xlocalidad(int _cs){
    int pos=0;
	while(leedisco(pos++)==1){
    if(_cs == codsala){
        listar();
    }
    }
}

void funcion::xfecha(){
    system("cls");
    int DD,MM,AA,D,M,A;
    cout<<"Ingrese que fecha desea visualizar: ";
    cout<<"DIA: ";
    cin>>DD;
    cout<<"MES: ";
    cin>>MM;
    cout<<"ANIO: ";
    cin>>AA;
    int pos=0;
	while(leedisco(pos++)==1){
    if(DD == (D = fechaDisponibles.getDia()) && MM == (M = fechaDisponibles.getMes()) && AA == (A = fechaDisponibles.getAnio()) ){
        listar();
    }
    }
}


void funcion::modificar(){
	int _num,pos;
	system("cls");
	cout<<"Ingrese Cod funcion: ";
	cin>>_num;
	pos=buscar(_num);
	if(pos!=-1){
    cout<<"YA PUEDES MODIFICAR"<<endl<<endl;
    cargar();
    modificarDisco(pos);
    }
	else{
    cout<<"No existe este DNI"<<endl;
    system("pause>nul");
    }
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

void funcion::listar(){
    cout<<endl<<endl;
    cout<<"CODIGO: "<< codFuncion;
    cout<<"Codigo de sala: "<< codsala;
    cout<<"Codigo de la pelicula: "<< cpelicula;
    cout<<"Ingrese la hora de inicial: ";
    horario.mostrar();
    cout<<"fecha disponible: ";
    fechaDisponibles.mostrar();
    cout<<endl<<"Precio de la entrada: "<<precio;
}

void funcion::cargar(){
    genCod();
    cout<<"Codigo de sala: ";
    cin>>codsala;
    cout<<"Codigo de la pelicula: ";
    cin>>cpelicula;
    cout<<"Ingrese la hora de inicial: ";
    int hh,mm;
    cout<<"hora: ";
    cin>>hh;
    cout<<"minuto: ";
    cin>>mm;
    horario.cargar(hh,mm);
    cout<<"fecha disponible: ";
    int DD,MM,AA;
    cout<<"Dia: ";
    cin>>DD;
    cout<<"Mes: ";
    cin>>MM;
    cout<<"Anio: ";
    cin>>AA;
    fechaDisponibles.cargar(DD,MM,AA);
    cout<<"Precio de la entrada: ";
    cin>>precio;
    system("pause");
}

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

bool funcion::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/funcioens.dat","ab");
    if(p==NULL){
        fclose(p);
        return false;
    }
    grabo=fwrite(this, sizeof(funcion),1,p);
    fclose(p);
return grabo;
}

void funcion::leePos(){
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
