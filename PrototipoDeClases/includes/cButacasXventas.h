#ifndef CBUTACASXVENTAS_H_INCLUDED
#define CBUTACASXVENTAS_H_INCLUDED

class butacasxVentas{
private:
    int     fila;       ///QUE FILA ELIJIO UNA SOLA PERSONA
    int     columna;    ///QUE COLUMNA ELIJIO UNA SOLA PERSONA
};

class precios{
private:
    float   precio;
public:
    void cargar(float _p);
    void mostrar();
};

void precios::cargar(float _p){
    precio = _p;
}

void precios::mostrar(){
    cout<<precio<<endl;
}


#endif // CBUTACASXVENTAS_H_INCLUDED
