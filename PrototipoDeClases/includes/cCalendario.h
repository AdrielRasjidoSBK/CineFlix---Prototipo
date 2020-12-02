#ifndef CCALENDARIO_H_INCLUDED
#define CCALENDARIO_H_INCLUDED

class fecha{
private:
    int         dia;
    int         mes;
    int         anio;

public:
    bool cargar(int DD,int MM, int AA);
    void mostrar();

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};

bool fecha::cargar(int DD, int MM, int AA){
    dia = DD;
    mes = MM;
    anio = AA;
return true;
}

void fecha::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


class hora{
private:
    int         horas;
    int         minutos;
public:
    bool cargar(int hh,int mm);
    void mostrar();

    int gethoras(){return horas;}
    int getminutos(){return minutos;}
};

bool hora::cargar(int hh,int mm){
    horas = hh;
    minutos = mm;
return true;
}

void hora::mostrar(){
    cout<<horas<<":"<<minutos<<endl;
}

#endif // CCALENDARIO_H_INCLUDED
