#ifndef CBUTACASXVENTAS_H_INCLUDED
#define CBUTACASXVENTAS_H_INCLUDED

class butacasxVentas{
private:
    int     fila;       ///QUE FILA ELIJIO UNA SOLA PERSONA
    int     columna;    ///QUE COLUMNA ELIJIO UNA SOLA PERSONA
public:
    int getFila(){return fila;}
    int getColumna(){return columna;}

    void cargar(int f,int c){
    fila = f;
    columna = c;
    }

    bool guardar();
    int  buscar(int f,int c);
    int  leedisco(int pos);

};

bool butacasxVentas::guardar(){
    bool grabo;
    FILE *p=fopen("Dat/butacas.dat","ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(this, sizeof(cliente),1,p);
    fclose(p);
return grabo;
}

int  butacasxVentas::buscar(int f, int c){
	int pos=0;
	while(leedisco(pos++)==1){
    if(f == fila && c == columna){
        return pos;
    }
    }
	return -1;
}

int  butacasxVentas::leedisco(int pos){
	int x;
	FILE *p;
	p=fopen("Dat/butacas.dat","rb");
	if(p==NULL){
    cout<<"No existe el archivo";
    system("pause>NULL");
    return 0;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

#endif // CBUTACASXVENTAS_H_INCLUDED
