#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

///visuales
void ShowConsoleCursor(bool);
void logoChico();
void logo();

void gamaColores();
void recuadro();

int clasificacion();
int genero();
void codVerificador();


///menues
void MenuPrincipal();
void passVerificador();
void menuAdmin();
void adminSalas();
void cargarSala();
void modificarSala();
void listarSala();
void adminPeliculas();
void adminFunciones();
void adminVentas();
void menuUsuario();
void passConf();

struct password{
int     cc;
};

void Pverificador();


#endif // DECLARACIONES_H_INCLUDED
