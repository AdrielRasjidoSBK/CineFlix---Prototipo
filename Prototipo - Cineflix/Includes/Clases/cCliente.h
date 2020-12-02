#ifndef CCLIENTE_H_INCLUDED
#define CCLIENTE_H_INCLUDED

#include "cFactura.h"

class cliente{
protected:
    int         dni;
    char        nombre[20];
    char        apellido[40];
    fecha       fechaNac;
    bool        estado;
public:
    bool cargar();
    bool guardar();
    void listar();
    void leePos();
    void modificar();
    void modificarDisco(int pos);
    int leedisco(int pos);
    int buscar(int _dni);
    int cantidad();
    void leerUltimaPos();

    ///gets
    int getdni(){return dni;}
    char *getnombre(){return nombre;}
    char *getapellido(){return apellido;}
    bool getestado(){return estado;}

};

void cliente::leerUltimaPos(){
    int pos=-1;
    FILE *p;
	p=fopen("Dat/clientes.dat","rb");
	if(p==NULL){
        fclose(p);
    }
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    fclose(p);
    leedisco(pos);
}

bool cliente::cargar(){
    system("cls");

    int DD,MM,AA;
    cout<<"ingrese el DNI: ";
    cin>> dni;
    cout<<"ingrese el nombre: ";
    cin.ignore();
    cin.getline(nombre,20);
    cout<<"ingrese el apellido: ";
    cin.getline(apellido,40);

    cout<<"ingrese la fecha: ";
    cout<<endl<<"dia  : ";
    cin>>DD;
    cout<<"mes  : ";
    cin>>MM;
    cout<<"anio : ";
    cin>>AA;

    fechaNac.cargar(DD,MM,AA);
    estado=true;

    system("pause");
    return true;
}

bool cliente::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/clientes.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(cliente),1,p);
    fclose(p);
return grabo;
}

void cliente::leePos(){
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

int  cliente::leedisco(int pos){
	int x;
	FILE *p;
	p=fopen("Dat/cliente.dat","rb");
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

void cliente::listar(){
    cout<<endl<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Fecha de nacimiento: ";
    fechaNac.mostrar();
    cout<<"estado: ";
    if(estado==true){
        cout<<"activo";
    }else{
        cout<<"inactivo";
    }
    cout<<endl<<endl;
}

int  cliente::cantidad(){
    int acu=0;
    FILE *p;
	p=fopen("Dat/clientes.dat","rb");
	if(p==NULL){
        fclose(p);
        return 0;
    }
    while(fread(this, sizeof *this,1,p)==1){
        acu ++;
    }
    fclose(p);
    return acu;
}

#endif // CCLIENTE_H_INCLUDED
