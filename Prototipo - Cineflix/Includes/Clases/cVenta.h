#ifndef CVENTA_H_INCLUDED
#define CVENTA_H_INCLUDED

void cierre(){

cliente c;
factura f;

float recaudado;
int cantidad;

system("cls");

recaudado = f.recaudado();
cantidad  = c.cantidad();

cout<<"CIERRE DE CAJA"<<endl<<endl;
if(cantidad==0){
    cout<<"NO HUBO INGRESOS DE VENTAS"<<endl;
}
else{
if(cantidad==1){
    cout<<"HUBO UN CLIENTE"<<endl;
}else{
    cout<<"HUBO "<<cantidad<<" CLIENTES"<<endl;
}
cout<<"SE RECAUDO UN TOTAL DE: $"<<recaudado;

remove("Dat/facturas.dat");
remove("Dat/clientes.dat");
}
system("pause>NULL");
}

#endif // CVENTA_H_INCLUDED
