#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include "cFuncion.h"
#include "cCliente.h"

class factura : public cliente {

private:
    int     cantT;
    int     codFuncion;
    int     NumFactura;
    float   precio;
    fecha   fechaActual;
public:
    bool guardar();
    void cargarTicket();
    void leePos();
    void genCod();
    void listar();
    void modificarDisco(int pos);
    int ultimaPos();
    int recaudado();
    int leedisco(int pos);
};





void factura::listar(){
    cout<<endl<<endl;
    cout<<"NUM DE FACTURA: "<<NumFactura<<endl;
    cout<<"CLIENTE: "<<nombre<<" "<<apellido<<endl;
    cout<<"FECHA DE LA FACTURA: ";
    fechaActual.mostrar();
    cout<<"FUNCION: "<<codFuncion;
    cout<<endl<<"CANTIDAD COMPRADA: "<<cantT;
    cout<<"COSTO: $"<<precio;
}


void factura::cargarTicket(){
    system("cls");
    int pos;
    genCod();
    pos = ultimaPos();
    if(pos==-1){
        FILE *f;
        f = fopen("Dat/facturas.dat","wb");
        fclose(f);
        pos=0;
    }

	FILE *p;
	p=fopen("Dat/facturas.dat","rb");
	fseek(p,pos*sizeof *this,0);
	fread(this,sizeof *this,1,p);
    fclose(p);

    leerUltimaPos();
	cout<<endl<<"CLIENTE: "<< getnombre() <<" "<< getapellido();
    cout<<endl<<"NUM DE FACTURA: "<<NumFactura<<endl;


    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    printf("FECHA DE LA FACTURA: %d/%d/%d ", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year);

    int dd,mm,aa;

    dd= tmPtr->tm_mday;
    mm= tmPtr->tm_mon+1;
    aa=1900+tmPtr->tm_year;

    fechaActual.cargar(dd,mm,aa);


    cout<<endl<<"NUMERO DE FUNCION: ";
    cin>>codFuncion;
    cout<<"CANTIDAD DE ENTRADAS: ";
    cin>>cantT;

    int pos2;
    funcion f;
    pos = f.buscar(codFuncion);
    f.leedisco(pos);
    precio = f.getPrecio();

    precio = precio * cantT;

    cout<<"COSTO: $"<<precio;

    modificarDisco(pos);
    system("pause>NULL");
}

void factura::genCod(){
    int pos=1;
    FILE *p;
	p=fopen("Dat/facturas.dat","rb");
	if(p==NULL){
        NumFactura = pos;
        fclose(p);
        return;
    }
    while(fread(this, sizeof *this,1,p)==1){
        pos++;
    }
    NumFactura = pos;
    fclose(p);
}

int  factura::ultimaPos(){
    int pos=-1;
    FILE *p;
	p=fopen("Dat/facturas.dat","rb");
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

bool factura::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/facturas.dat","ab");
    if(p==NULL){
        fclose(p);
        return false;
    }
    grabo=fwrite(this, sizeof(factura),1,p);
    fclose(p);
return grabo;
}

void factura::leePos(){
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

int  factura::leedisco(int pos){
	int x;
	FILE *p;
	p=fopen("Dat/facturas.dat","rb");
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

void factura::modificarDisco(int pos){
	FILE *p;
	p=fopen("Dat/facturas.dat","rb+");
	if(p==NULL){cout<<"Error de archivo"; fclose(p); exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	system("pause");
}

int  factura::recaudado(){
    float acu=0;
    FILE *p;
	p=fopen("Dat/facturas.dat","rb");
	if(p==NULL){
        fclose(p);
        return 0;
    }
    while(fread(this, sizeof *this,1,p)==1){
        acu += precio;
    }
    fclose(p);
    return acu;
}



#endif // FACTURA_H_INCLUDED
