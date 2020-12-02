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
    bool        estado;         ///LA PELICULA AUN EXISTE?
public:
    bool cargar();
    bool guardar();
    void listar();
    void leePos();
    void modificar();
    void modificarDisco(int pos);
    void generadorDeButacas(int c,int f);
    void mostrarButacas();
    void genCod();
    int  leedisco(int pos);
    int  buscar(int _num,char _t[40]);
    int  duracionP(int _num);

};

int pelicula::duracionP(int _num){
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

bool pelicula::cargar(){
    system("cls");
    genCod();
    cout<<"Titulo: ";
    cin.ignore();
    cin.getline(titulo,40);
    cout<<"Sipnosis: ";
    cin.getline(sipnosis,400);
    cout<<"Clasificacion: ";
    cin>>clasificacion;
    cout<<"Genero: ";
    cin>>genero;
    cout<<"Duracion: ";
    cin>>duracion;
    cout<<"Director: ";
    cin.getline(director,40);
    cout<<"Ruta de la portada: ";
    cin.getline(portada,40);
    estado = true;

    system("pause");
    return true;
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

void pelicula::leePos(){
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

int  pelicula::leedisco(int pos){
	int x;
	FILE *p;
	p=fopen("Dat/peliculas.dat","rb");
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

void pelicula::listar(){
    char opc;
    cout<<endl<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Sipnosis: "<<sipnosis<<endl;
    cout<<"Clasificacion: "<<clasificacion<<endl;
    cout<<"Genero: "<<genero<<endl;
    cout<<"Duracion: "<<duracion<<endl;
    cout<<"Director: "<<director<<endl;
    cout<<endl<<endl;
}

void pelicula::modificar(){
	int _num,pos;
	char _t[40];
	system("cls");
	cout<<"Ingrese el Num de pelicula: ";
	cin>>_num;
	cout<<"Ingrese el titulo: ";
	cin.ignore();
	cin.getline(_t,40);
	pos=buscar(_num,_t);
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

int  pelicula::buscar(int _num, char _t[40]){
	int pos=0;
	while(leedisco(pos)==1){
    if(_num == idcodigo && stricmp(_t,titulo)==0){
        return pos;
    }
    pos++;
    }
	return -1;
}

void pelicula::modificarDisco(int pos){
	FILE *p;
	p=fopen("Dat/peliculas.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";fclose(p);exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	system("pause");
}

#endif // CPELICULA_H_INCLUDED
