#ifndef VISUALES_H_INCLUDED
#define VISUALES_H_INCLUDED



void gamaColores(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for(int k = 1; k < 255; k++){
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " I want to be nice today!" << endl;
  }
}

void logo(int x, int y){

gotoxy(x, y);
cout << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << char(219) << char(219);
cout << char(187) << char(219) << char(219) << char(219) << char(187) << " " << " " << char(219) << char(219) << char(187);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(187) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(187) << char(219) << char(219) << char(187);
cout << " " << " " << char(219) << char(219) << char(187) << endl;

gotoxy(x, y+1);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219);
cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219) << char(186) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(186) << char(200) << char(219) << char(219);
cout << char(187) << char(219) << char(219) << char(201) << char(188) << endl;

gotoxy(x, y+2);
cout << char(219) << char(219) << char(186) << " " << " " << char(200) << char(205) << char(188) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(201) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << " " << char(219) << char(219);
cout << char(219) << char(219) << char(219) << char(187) << " " << " " << char(219) << char(219) << char(186) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(186) << " " << char(200) << char(219);
cout << char(219) << char(219) << char(201) << char(188) << " " << endl;

gotoxy(x, y+3);
cout << char(219) << char(219) << char(186) << " " << " " << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(186) << char(200) << char(219) << char(219) << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << " " << " " << char(219) << char(219);
cout << char(201) << char(205) << char(205) << char(188) << " " << " " << char(219) << char(219) << char(186) << " ";
cout << " " << " " << " " << " " << char(219) << char(219) << char(186) << " " << char(219) << char(219);
cout << char(201) << char(219) << char(219) << char(187) << " " << endl;

gotoxy(x, y+4);
cout << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219);
cout << char(186) << char(219) << char(219) << char(186) << " " << char(200) << char(219) << char(219) << char(219) << char(186);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219);
cout << char(186) << " " << " " << " " << " " << " " << char(219) << char(219) << char(219) << char(219);
cout << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201);
cout << char(188) << char(200) << char(219) << char(219) << char(187) << endl;

gotoxy(x, y+5);
cout << " " << char(200) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(200) << char(205);
cout << char(188) << char(200) << char(205) << char(188) << " " << " " << char(200) << char(205) << char(205) << char(188);
cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205);
cout << char(188) << " " << " " << " " << " " << " " << char(200) << char(205) << char(205) << char(205);
cout << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(188) << char(200) << char(205) << char(188);
cout << " " << " " << char(200) << char(205) << char(188) << endl;

}
void logoChico(int x, int y){
gotoxy(x, y);
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << " " << " ";
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187);
gotoxy(x,y+1);
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) <<" ";
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188);
gotoxy(x,y+2);
cout << char(219) << char(219) << char(186) << " " << " " << char(200) << char(205) << char(188) << " ";
cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(187);
gotoxy(x,y+3);
cout << char(219) << char(219) << char(186) << " " << " " << char(219)<< char(219) << char(187) << " ";
cout << char(219) << char(219) << char(201) << char(205) << char(205) << char(188);
gotoxy(x,y+4);
cout << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201);
cout << char(188) << " " << char(219) << char(219) << char(186);
gotoxy(x,y+5);
cout << " " << char(200) << char(205) << char(205) << char(205);
cout << char(205) << char(188) << " " << " "<<  char(200) << char(205) << char(188);
}

void ShowConsoleCursor(bool showFlag){                                          //MOSTRARA DONDE SE ENCUENTRA EL CURSOR EN LA CONSOLA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void recuadro(short iniX, short iniY, short ancho, short alto){                 //CON ESTA FUNCION NOS PERMITIRA CREAR UN RECUADRO
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            if(i==iniX && j==iniY){cout << (char) 201;                          ///ARRIBA  - IZQUIERDA
            }
            else if(i==iniX+ancho && j==iniY){cout << (char) 187;               ///ARRIBA  - DERECHA
            }
            else if(i==iniX && j==iniY+alto){cout << (char) 200;                ///ABAJO   - IZQUIERDA
            }
            else if(i==iniX+ancho && j==iniY+alto){cout << (char) 188;          ///ABAJO   - DERECHA
            }
            else if(j==iniY || j==iniY+alto){cout << (char) 205;                ///ARRIBA  - ABAJO
            }
            else if(i==iniX || i==iniX+ancho){cout << (char) 186;               ///DERECHA - IZQUIERDA
            }
            else{cout << " ";                                                   ///DENTRO DEL RECUADRO
            }
        }
    }
}










#endif // VISUALES_H_INCLUDED
