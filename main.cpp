#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;

#define F1 59
#define F5 63
#define F6 64
#define F9 67
#define F10 68
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESC  27
#define ENTER 13
#define TAB 9

struct SAvanzado{

    int speedstep = 0;
    int hyperthreading = 0;
    int legacy_os = 0;
    int large_disk = 0;
    int ahci = 0;
    int edb = 0;
    int lan = 0;
    int mouse = 0;
    int led = 0;
    int saving_cpu = 0;
    int fan = 0;
    int usb_s3 = 0;
    int usb_cargador = 0;
    int bateria = 0;
};

struct SSeguridad{

    char supervisor[9] = {'\0'};
    char usuario[9] = {'\0'};
    char discoduro[9] = {'\0'};
    int aliniciar = 0;
};

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void color(int X){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}

void PintarFondo(){

    ///COLOR GRIS
    for(int i=0; i<34; i++){ gotoxy(1,3 + i); color(128); cout<<"                                                      "<<endl;}
    for(int i=0; i<3; i++){ gotoxy(56, 3 + i); color(128); cout<<"                         "<<endl;}
    for(int i=0; i<30; i++){ gotoxy(56, 7 + i); color(128); cout<<"                         "<<endl;}
    ///ESQUINAS
    gotoxy(0, 2); color(128); printf("%c", 201);
    gotoxy(0, 37); color(128); printf("%c", 200);
    gotoxy(81, 37); color(128); printf("%c", 188);
    gotoxy(81, 2); color(128); printf("%c", 187);
    ///LINEAS HORIZONTALES
    for(int i=1; i<81; i++){
        gotoxy(i, 2); color(128); printf("%c", 205);
        gotoxy(i, 37); color(128); printf("%c", 205);
    }
    ///LINEAS VERTICALES
    for(int i=3; i<37; i++){
        gotoxy(0, i); color(128); printf("%c", 186);
        gotoxy(81, i); color(128); printf("%c", 186);
        gotoxy(55, i); color(128); printf("%c", 186);
    }
    ///INTERSECCIONES
    gotoxy(55, 2); color(128); printf("%c", 203);
    gotoxy(55, 37); color(128); printf("%c", 202);
    gotoxy(55, 6); color(128); printf("%c", 204);
    gotoxy(81, 6); color(128); printf("%c", 185);
    ///LINEA CORTA
    for(int i=0; i<25; i++){
        gotoxy(56 + i, 6); color(128); printf("%c", 205);
    }

}

void Cursor(bool x){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = x;
    SetConsoleCursorInfo(hcon, &cci);
}

void BorrarFondo(){

    for(int i=0; i<34; i++){ gotoxy(1,3 + i); color(128); cout<<"                                                      "<<endl;}
    for(int i=0; i<3; i++){ gotoxy(56, 3 + i); color(128); cout<<"                         "<<endl;}
    for(int i=0; i<30; i++){ gotoxy(56, 7 + i); color(128); cout<<"                         "<<endl;}
    ///TITULO SECCION DE AYUDA
    gotoxy(61,4); color(128); printf("Necesitas ayuda?");
}

void BarraDeTitulo(){

    gotoxy(0,0); color(48); printf("                                                                                   ");
    gotoxy(28,0); color(48); cout<<"IVAN PERALTA BIOS 1.0"<<endl;
}

void BarraInferior(){

    gotoxy(0,38); color(48); printf("                                                                                  ");
    gotoxy(0,39); color(48); printf("                                                                                  ");

    gotoxy(2,38); color(63); printf("F1");
    gotoxy(2,39); color(63); printf("Esc");
    gotoxy(7,38); color(48); printf("Ayuda");
    gotoxy(7,39); color(48); printf("Salir");

    gotoxy(14,38); color(63); printf("Arr/Aba");
    gotoxy(14,39); color(63); printf("Izq/Der");
    gotoxy(23,38); color(48); printf("Selec. Item");
    gotoxy(23,39); color(48); printf("Selec. Menu");

    gotoxy(36,38); color(63); printf("F5/F6");
    gotoxy(36,39); color(63); printf("Enter");
    gotoxy(43,38); color(48); printf("Cambiar Valor");
    gotoxy(43,39); color(48); printf("Selec. Sub-Menu");

    gotoxy(60,38); color(63); printf("F9");
    gotoxy(60,39); color(63); printf("F10");
    gotoxy(65,38); color(48); printf("Por Defecto");
    gotoxy(65,39); color(48); printf("Guardar y Salir");
}

void BarraMenues(){

    gotoxy(0,1); color(16); printf("                                                                                  ");
    gotoxy(2,1); color(24); printf("Principal    Avanzado    Seguridad    Arranque    Salir");
}

void VentanaAyuda(){

    ///COLOR DE FONDO
    for(int i=0; i<32; i++){gotoxy(5,3+i); color(112); printf("                                                                      ");}
    ///SOMBRA NEGRA
    for(int i=0; i<32; i++){gotoxy(75,4+i); color(0); printf(" ");}
    gotoxy(6,35); printf("                                                                      ");
    ///LINEAS HORIZONTALES
    for(int i=0; i<68; i++){
            gotoxy(6+i,3); color(112); printf("%c",196);
            gotoxy(6+i,34); printf("%c",196);
            gotoxy(6+i,5); printf("%c",196);
    }
    ///LINEAS VERTICALES
    for(int i=0; i<32; i++){
            gotoxy(5,3+i); printf("%c",179);
            gotoxy(74,3+i); printf("%c",179);
    }
    ///ESQUINAS, INTERSECCIONES
    gotoxy(5,3); color(112); printf("%c",218);
    gotoxy(5,34); printf("%c",192);
    gotoxy(74,34); printf("%c",217);
    gotoxy(74,3); printf("%c",191);
    gotoxy(5,5); printf("%c",195);
    gotoxy(74,5); printf("%c",180);
    ///TITULO
    gotoxy(34,4); printf("Ayuda General");
    ///CONTINUAR
    gotoxy(35,33); printf("[         ]");
    gotoxy(36,33); color(7); printf("Continuar");

    int tecla;

    while(true){
        if(kbhit()){

            tecla = getch();
            if(tecla == ENTER || tecla == ESC || tecla == F1) break;
        }
    }

    ///BORRAR RASTRO LINEA CORTA
    for(int i=0; i<25; i++){ gotoxy(56 + i, 6); color(128); printf("%c", 205);}
    ///BORRAR RASTRO LINEA VERTICAL
    for(int i=3; i<37; i++){gotoxy(55, i); color(128); printf("%c", 186);}
    gotoxy(55, 6); color(128); printf("%c", 204);
}

void VentanaGuardarYSalir(){

    ///COLOR DE FONDO
    for(int i=0; i<9; i++){gotoxy(12,14+i); color(112); printf("                                                        ");}
    ///SOMBRA
    for(int i=0; i<9; i++){gotoxy(68,15+i); color(0); printf(" ");}
    gotoxy(13,23); color(0); printf("                                                        ");

    gotoxy(34,15); color(113); printf("Confirmacion");
    gotoxy(13,18); printf("Desea guardar los cambios en la configuracion y salir?");
    gotoxy(25,21); printf("[Si]                      [No]");

    ///LINEAS HORIZONTALES
    for(int i=0; i<54; i++){
        gotoxy(13+i,14); printf("%c",196);
        gotoxy(13+i,16); printf("%c",196);
        gotoxy(13+i,22); printf("%c",196);
    }

    ///LINEAS VERTICALES
    for(int i=0; i<7; i++){
        gotoxy(12,15+i); printf("%c",179);
        gotoxy(67,15+i); printf("%c",179);
    }

    gotoxy(12,14); printf("%c",218);
    gotoxy(67,14); printf("%c",191);
    gotoxy(12,16); printf("%c",195);
    gotoxy(67,16); printf("%c",180);
    gotoxy(12,22); printf("%c",192);
    gotoxy(67,22); printf("%c",217);

    int tecla;
    int opcion = 0;

    gotoxy(26,21); color(7); printf("Si");///OPCION POR DEFECTO

    while(true){

        if(kbhit()){

            tecla = getch();

            if(tecla == DERECHA) opcion++;
            if(tecla == IZQUIERDA) opcion--;
            if(tecla == ENTER){
                if(opcion == 0) {gotoxy(0,40); color(8); exit(0);}
                if(opcion == 1) break;
            }

            if(opcion > 1) opcion = 0;
            if(opcion < 0) opcion = 1;

            if(opcion == 0){gotoxy(26,21); color(7); printf("Si");}
            else{gotoxy(26,21); color(113); printf("Si");}

            if(opcion == 1){gotoxy(52,21); color(7); printf("No");}
            else{gotoxy(52,21); color(113); printf("No");}
        }
    }

    ///BORRAR RASTRO LINEA VERTICAL
    for(int i=3; i<37; i++){gotoxy(55, i); color(128); printf("%c", 186);}
    gotoxy(55, 6); color(128); printf("%c", 204);
}

int VentanaHabilitar(int opcion){

    for(int i=0; i<4; i++){
        gotoxy(30,15 + i); color(16); printf("                 ");
        gotoxy(47,16+i); color(0); printf(" ");
        gotoxy(31,19); color(0); printf("                 ");
    }

    for(int i=0; i<15; i++){
        gotoxy(31+i,15); color(24); printf("%c",196);
        gotoxy(31+i,18); color(24); printf("%c",196);
    }

    for(int i=0; i<2; i++){
        gotoxy(30,16+i); color(24); printf("%c",179);
        gotoxy(46,16+i); color(24); printf("%c",179);
    }

    gotoxy(30,15); color(24); printf("%c",218);
    gotoxy(46,15); color(24); printf("%c",191);
    gotoxy(30,18); color(24); printf("%c",192);
    gotoxy(46,18); color(24); printf("%c",217);

    gotoxy(32,16); color(24); printf("Deshabilitado");
    gotoxy(32,17); color(24); printf("Habilitado");

    int tecla = 0;
    bool entrar = true;

    while(tecla != ENTER){

        if(kbhit() || entrar == true){

            if(entrar == false) tecla = getch();
            entrar = false;

            if(tecla == ARRIBA) opcion--;
            if(tecla == ABAJO) opcion++;

            if(opcion < 0) opcion = 1;
            if(opcion > 1) opcion = 0;

            if(opcion == 0){gotoxy(32,16); color(31); printf("Deshabilitado");}
            else{gotoxy(32,16); color(24); printf("Deshabilitado");}

            if(opcion == 1){gotoxy(32,17); color(31); printf("Habilitado");}
            else{gotoxy(32,17); color(24); printf("Habilitado");}
        }
    }

    ///BORRAR RASTRO DE VENTANA
    for(int i=0; i<9; i++){gotoxy(20,13+i); color(128); printf("                                               ");}
    for(int i=3; i<37; i++){gotoxy(55, i); color(128); printf("%c", 186);}
    gotoxy(55, 6); color(128); printf("%c", 204);

    return opcion;
}

int VentanaDOS(int opcion){

    for(int i=0; i<4; i++){
        gotoxy(34,15 + i); color(16); printf("         ");
        gotoxy(43,16+i); color(0); printf(" ");
        gotoxy(35,19); color(0); printf("         ");
    }

    for(int i=0; i<9; i++){
        gotoxy(34+i,15); color(24); printf("%c",196);
        gotoxy(34+i,18); color(24); printf("%c",196);
    }

    for(int i=0; i<2; i++){
        gotoxy(34,16+i); color(24); printf("%c",179);
        gotoxy(42,16+i); color(24); printf("%c",179);
    }

    gotoxy(34,15); color(24); printf("%c",218);
    gotoxy(42,15); color(24); printf("%c",191);
    gotoxy(34,18); color(24); printf("%c",192);
    gotoxy(42,18); color(24); printf("%c",217);

    int tecla = 0;
    bool entrar = true;

    while(tecla != ENTER){

        if(kbhit() || entrar == true){

            if(entrar == false) tecla = getch();
            entrar = false;

            if(tecla == ARRIBA) opcion--;
            if(tecla == ABAJO) opcion++;

            if(opcion < 0) opcion = 1;
            if(opcion > 1) opcion = 0;

            if(opcion == 0){gotoxy(36,16); color(31); printf("Otro");}
            else{gotoxy(36,16); color(24); printf("Otro");}

            if(opcion == 1){gotoxy(36,17); color(31); printf("DOS");}
            else{gotoxy(36,17); color(24); printf("DOS");}
        }
    }

    return opcion;
}

int VentanaAutoManual(int opcion){

    for(int i=0; i<4; i++){
        gotoxy(33,15 + i); color(16); printf("            ");
        gotoxy(45,16+i); color(0); printf(" ");
        gotoxy(34,19); color(0); printf("            ");
    }

    for(int i=0; i<12; i++){
        gotoxy(33+i,15); color(24); printf("%c",196);
        gotoxy(33+i,18); color(24); printf("%c",196);
    }

    for(int i=0; i<2; i++){
        gotoxy(33,16+i); color(24); printf("%c",179);
        gotoxy(44,16+i); color(24); printf("%c",179);
    }

    gotoxy(33,15); color(24); printf("%c",218);
    gotoxy(44,15); color(24); printf("%c",191);
    gotoxy(33,18); color(24); printf("%c",192);
    gotoxy(44,18); color(24); printf("%c",217);

    int tecla = 0;
    bool entrar = true;

    while(tecla != ENTER){

        if(kbhit() || entrar == true){

            if(entrar == false) tecla = getch();
            entrar = false;

            if(tecla == ARRIBA) opcion--;
            if(tecla == ABAJO) opcion++;

            if(opcion < 0) opcion = 1;
            if(opcion > 1) opcion = 0;

            if(opcion == 0){gotoxy(36,16); color(31); printf("Auto");}
            else{gotoxy(36,16); color(24); printf("Auto");}

            if(opcion == 1){gotoxy(36,17); color(31); printf("Manual");}
            else{gotoxy(36,17); color(24); printf("Manual");}
        }
    }

    return opcion;
}

int VentanaTouchpadLed(int opcion){

    for(int i=0; i<5; i++){
        gotoxy(32,15 + i); color(16); printf("               ");
        gotoxy(47,16+i); color(0); printf(" ");
        gotoxy(34,20); color(0); printf("              ");
    }

    for(int i=0; i<14; i++){
        gotoxy(33+i,15); color(24); printf("%c",196);
        gotoxy(33+i,19); color(24); printf("%c",196);
    }

    for(int i=0; i<3; i++){
        gotoxy(32,16+i); color(24); printf("%c",179);
        gotoxy(46,16+i); color(24); printf("%c",179);
    }

    gotoxy(32,15); color(24); printf("%c",218);
    gotoxy(46,15); color(24); printf("%c",191);
    gotoxy(32,19); color(24); printf("%c",192);
    gotoxy(46,19); color(24); printf("%c",217);

    int tecla = 0;
    bool entrar = true;

    while(tecla != ENTER){

        if(kbhit() || entrar == true){

            if(entrar == false) tecla = getch();
            entrar = false;

            if(tecla == ARRIBA) opcion--;
            if(tecla == ABAJO) opcion++;

            if(opcion < 0) opcion = 2;
            if(opcion > 2) opcion = 0;

            if(opcion == 0){gotoxy(35,16); color(31); printf("Auto");}
            else{gotoxy(35,16); color(24); printf("Auto");}

            if(opcion == 1){gotoxy(35,17); color(31); printf("Touchpad");}
            else{gotoxy(35,17); color(24); printf("Touchpad");}

            if(opcion == 2){gotoxy(35,18); color(31); printf("Apagado");}
            else{gotoxy(35,18); color(24); printf("Apagado");}
        }
    }

    return opcion;
}

int VentanaFan(int opcion){

    for(int i=0; i<4; i++){
        gotoxy(34,15 + i); color(16); printf("         ");
        gotoxy(43,16+i); color(0); printf(" ");
        gotoxy(35,19); color(0); printf("         ");
    }

    for(int i=0; i<9; i++){
        gotoxy(34+i,15); color(24); printf("%c",196);
        gotoxy(34+i,18); color(24); printf("%c",196);
    }

    for(int i=0; i<2; i++){
        gotoxy(34,16+i); color(24); printf("%c",179);
        gotoxy(42,16+i); color(24); printf("%c",179);
    }

    gotoxy(34,15); color(24); printf("%c",218);
    gotoxy(42,15); color(24); printf("%c",191);
    gotoxy(34,18); color(24); printf("%c",192);
    gotoxy(42,18); color(24); printf("%c",217);

    int tecla = 0;
    bool entrar = true;

    while(tecla != ENTER){

        if(kbhit() || entrar == true){

            if(entrar == false) tecla = getch();
            entrar = false;

            if(tecla == ARRIBA) opcion--;
            if(tecla == ABAJO) opcion++;

            if(opcion < 0) opcion = 1;
            if(opcion > 1) opcion = 0;

            if(opcion == 0){gotoxy(36,16); color(31); printf("Bajo");}
            else{gotoxy(36,16); color(24); printf("Bajo");}

            if(opcion == 1){gotoxy(36,17); color(31); printf("Auto");}
            else{gotoxy(36,17); color(24); printf("Auto");}
        }
    }

    return opcion;
}

void PintarVC1(){

    for(int i=0; i<6; i++){gotoxy(20,13+i); color(16); printf("                                             ");} ///fondo azul

        gotoxy(21,19); color(0); printf("                                             "); ///sombra horizontal

        for(int i=0; i<45; i++){
            gotoxy(20+i,13); color(24); printf("%c",196); ///lineas horizontales
            gotoxy(20+i,15); color(24); printf("%c",196);
            gotoxy(20+i,18); color(24); printf("%c",196);
        }

        for(int i=0; i<5; i++){
            gotoxy(20,13+i); color(24); printf("%c",179); ///lineas verticales
            gotoxy(64,13+i); color(24); printf("%c",179);
            gotoxy(65,14+i); color(0); printf(" "); ///sombra vertical
        }

        gotoxy(20,13); color(24); printf("%c",218); ///intersecciones
        gotoxy(64,13); color(24); printf("%c",191);
        gotoxy(20,18); color(24); printf("%c",192);
        gotoxy(64,18); color(24); printf("%c",217);
        gotoxy(20,15); color(24); printf("%c",195);
        gotoxy(64,15); color(24); printf("%c",180);


        gotoxy(23,16); color(24); printf("Ingrese nueva contrase%ca      [        ]",164);
        gotoxy(22,17); color(24); printf("Confirme nueva contrase%ca      [        ]",164);

        gotoxy(54,16); color(0); printf("        ");
        gotoxy(54,17); color(0); printf("        ");
}

void PintarVC2(){

    for(int i=0; i<6; i++){gotoxy(20,13+i); color(16); printf("                                             ");} ///fondo azul

    gotoxy(21,20); color(0); printf("                                             "); ///sombra horizontal

    for(int i=0; i<45; i++){
        gotoxy(20+i,13); color(24); printf("%c",196); ///lineas horizontales
        gotoxy(20+i,15); color(24); printf("%c",196);
        gotoxy(20+i,19); color(24); printf("%c",196);
    }

    for(int i=0; i<7; i++){
        gotoxy(20,13+i); color(24); printf("%c",179); ///lineas verticales
        gotoxy(64,13+i); color(24); printf("%c",179);
        gotoxy(65,14+i); color(0); printf(" "); ///sombra vertical
    }

    gotoxy(20,13); color(24); printf("%c",218); ///intersecciones
    gotoxy(64,13); color(24); printf("%c",191);
    gotoxy(20,19); color(24); printf("%c",192);
    gotoxy(64,19); color(24); printf("%c",217);
    gotoxy(20,15); color(24); printf("%c",195);
    gotoxy(64,15); color(24); printf("%c",180);

    gotoxy(22,16); color(24); printf("Ingrese actual contrase%ca      [        ]",164);
    gotoxy(22,17); color(24); printf("Ingrese nueva contrase%ca       [        ]",164);
    gotoxy(22,18); color(24); printf("Confirmar nueva contrase%ca     [        ]",164);

    gotoxy(54,16); color(0); printf("        ");
    gotoxy(54,17); color(0); printf("        ");
    gotoxy(54,18); color(0); printf("        ");
}

void VentanaInformacion(int opcion){

    for(int i=0; i<8; i++){
            gotoxy(26,13+i); color(112); printf("                                  "); ///COLOR FONDO
            gotoxy(27,21); color(0); printf("                                  "); ///SOMBRA HORIZONTAL
    }

    for(int i=0; i<7; i++){ ///LINEAS VERTICALES
        gotoxy(60,14+i); color(0); printf(" "); ///SOMBRA VERTICAL
        gotoxy(26,14+i); color(120); printf("%c",179);
        gotoxy(59,14+i); color(120); printf("%c",179);
    }

    for(int i=0; i<32; i++){ ///LINEAS HORIZONTALES
        gotoxy(27+i,13); color(120); printf("%c",196);
        gotoxy(27+i,15); color(120); printf("%c",196);
        gotoxy(27+i,20); color(120); printf("%c",196);
    }

    ///INTERSECCIONES
    gotoxy(26,13); color(120); printf("%c",218);
    gotoxy(59,13); color(120); printf("%c",191);
    gotoxy(26,20); color(120); printf("%c",192);
    gotoxy(59,20); color(120); printf("%c",217);
    gotoxy(26,15); color(120); printf("%c",195);
    gotoxy(59,15); color(120); printf("%c",180);


    gotoxy(37,14); color(120); printf("Informacion");
    if(opcion == 0){gotoxy(29,16); color(120); printf("Las contrase%cas no coinciden",164);}
    if(opcion == 1){gotoxy(29,16); color(120); printf("Contrase%ca cambiada con exito",164);}
    if(opcion == 2){gotoxy(29,16); color(120); printf("   Contrase%ca incorrecta",164);}
    gotoxy(37,19); color(120); printf("[Continuar]");
    gotoxy(38,19); color(7); printf("Continuar");

}

void VentanaContrasenia(int tipo, SSeguridad *contrasenias, bool agregada){

    char nuevacontrasenia1[9];
    char nuevacontrasenia2[9];
    char viejacontrasenia[9];

    if(!agregada){ ///Si no hay contraseña agregada

        PintarVC1(); ///Pintar ventana

        if(tipo == 0){ ///SI ES SUPERVISOR

            gotoxy(28,14); color(24); printf("Agregar Contrase%ca Supervisor",164);

            ///Ingresar contraseña
            Cursor(true);
            gotoxy(54,16); color(15); cin.getline(nuevacontrasenia1,9);
            if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,16); color(15); printf("%c",177);}}

            ///Reingresar contraseña
            gotoxy(54,17); color(15); cin.getline(nuevacontrasenia2,9);
            if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,17); color(15); printf("%c",177);}}
            Cursor(false);

            if(strcmp(nuevacontrasenia1,nuevacontrasenia2) == 0){ ///Si las contraseñas coinciden...
                strcpy(contrasenias->supervisor,nuevacontrasenia1);
                VentanaInformacion(1);
            }
            else{ ///si no coinciden...
                VentanaInformacion(0);
            }
        }

        if(tipo == 1){ ///USUARIO
            gotoxy(28,14); color(24); printf("Agregar Contrase%ca Usuario",164);

            Cursor(true);
            ///Ingresar contraseña
            gotoxy(54,16); color(15); cin.getline(nuevacontrasenia1,9);
            if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,16); color(15); printf("%c",177);}}

            ///Reingresar contraseña
            gotoxy(54,17); color(15); cin.getline(nuevacontrasenia2,9);
            if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,17); color(15); printf("%c",177);}}
            Cursor(false);

            if(strcmp(nuevacontrasenia1,nuevacontrasenia2) == 0){ ///Si las contraseñas coinciden...
                strcpy(contrasenias->usuario,nuevacontrasenia1);
                VentanaInformacion(1);
            }
            else{ ///si no coinciden...
                VentanaInformacion(0);
            }
        }

        if(tipo == 2){ ///DISCODURO
            gotoxy(28,14); color(24); printf("Agregar Contrase%ca Disco Duro",164);

            Cursor(true);
            ///Ingresar contraseña
            gotoxy(54,16); color(15); cin.getline(nuevacontrasenia1,9);
            if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,16); color(15); printf("%c",177);}}

            ///Reingresar contraseña
            gotoxy(54,17); color(15); cin.getline(nuevacontrasenia2,9);
            if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,17); color(15); printf("%c",177);}}
            Cursor(false);

            if(strcmp(nuevacontrasenia1,nuevacontrasenia2) == 0){ ///Si las contraseñas coinciden...
                strcpy(contrasenias->discoduro,nuevacontrasenia1);
                VentanaInformacion(1);
            }
            else{ ///si no coinciden...
                VentanaInformacion(0);
            }
        }
    }
    else{ ///SI YA EXISTE UNA CONTRASEÑA

        PintarVC2(); ///pintar ventana

        if(tipo == 0){
            gotoxy(28,14); color(24); printf("Cambiar Contrase%ca Supervisor",164);

            ///Ingresar contraseña vieja
            Cursor(true);
            gotoxy(54,16); color(15); cin.getline(viejacontrasenia,9);
            if(strcmp(viejacontrasenia,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,16); color(15); printf("%c",177);}}
            Cursor(false);

            if(strcmp(viejacontrasenia, contrasenias->supervisor) != 0){ ///SI LA CONTRASEÑA ACTUAL NO COINCIDE...
                VentanaInformacion(2);
            }
            else{

                ///Ingresar contraseña
                Cursor(true);
                gotoxy(54,17); color(15); cin.getline(nuevacontrasenia1,9);
                if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,17); color(15); printf("%c",177);}}

                ///Reingresar contraseña
                gotoxy(54,18); color(15); cin.getline(nuevacontrasenia2,9);
                if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,18); color(15); printf("%c",177);}}
                Cursor(false);

                if(strcmp(nuevacontrasenia1,nuevacontrasenia2) == 0){ ///Si las contraseñas coinciden...
                    strcpy(contrasenias->supervisor,nuevacontrasenia1);
                    VentanaInformacion(1);
                }
                else{ ///si no coinciden...
                    VentanaInformacion(0);
                }
            }
        }

        if(tipo == 1){
            gotoxy(28,14); color(24); printf("Agregar Contrase%ca Usuario",164);

            ///Ingresar contraseña vieja
            Cursor(true);
            gotoxy(54,16); color(15); cin.getline(viejacontrasenia,9);
            if(strcmp(viejacontrasenia,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,16); color(15); printf("%c",177);}}
            Cursor(false);

            if(strcmp(viejacontrasenia, contrasenias->usuario) != 0){ ///SI LA CONTRASEÑA ACTUAL NO COINCIDE...
                VentanaInformacion(2);
            }
            else{

                ///Ingresar contraseña
                Cursor(true);
                gotoxy(54,17); color(15); cin.getline(nuevacontrasenia1,9);
                if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,17); color(15); printf("%c",177);}}

                ///Reingresar contraseña
                gotoxy(54,18); color(15); cin.getline(nuevacontrasenia2,9);
                if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,18); color(15); printf("%c",177);}}
                Cursor(false);

                if(strcmp(nuevacontrasenia1,nuevacontrasenia2) == 0){ ///Si las contraseñas coinciden...
                    strcpy(contrasenias->usuario,nuevacontrasenia1);
                    VentanaInformacion(1);
                }
                else{ ///si no coinciden...
                    VentanaInformacion(0);
                }
            }
        }

        if(tipo == 2){
            gotoxy(28,14); color(24); printf("Agregar Contrase%ca Disco Duro",164);

            ///Ingresar contraseña vieja
            Cursor(true);
            gotoxy(54,16); color(15); cin.getline(viejacontrasenia,9);
            if(strcmp(viejacontrasenia,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,16); color(15); printf("%c",177);}}
            Cursor(false);

            if(strcmp(viejacontrasenia, contrasenias->discoduro) != 0){ ///SI LA CONTRASEÑA ACTUAL NO COINCIDE...
                VentanaInformacion(2);
            }
            else{

                ///Ingresar contraseña
                Cursor(true);
                gotoxy(54,17); color(15); cin.getline(nuevacontrasenia1,9);
                if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,17); color(15); printf("%c",177);}}

                ///Reingresar contraseña
                gotoxy(54,18); color(15); cin.getline(nuevacontrasenia2,9);
                if(strcmp(nuevacontrasenia1,"\0") != 0){for(int i=0; i<8; i++){gotoxy(54+i,18); color(15); printf("%c",177);}}
                Cursor(false);

                if(strcmp(nuevacontrasenia1,nuevacontrasenia2) == 0){ ///Si las contraseñas coinciden...
                    strcpy(contrasenias->discoduro,nuevacontrasenia1);
                    VentanaInformacion(1);
                }
                else{ ///si no coinciden...
                    VentanaInformacion(0);
                }
            }
        }
    }


    system("pause > null");

    ///BORRAR RASTRO DE VENTANA
    for(int i=0; i<9; i++){gotoxy(20,13+i); color(128); printf("                                               ");}
    for(int i=3; i<37; i++){gotoxy(55, i); color(128); printf("%c", 186);}
    gotoxy(55, 6); color(128); printf("%c", 204);
}

void MenuPrincipal(int *num_menu, tm *tiempo){

    gotoxy(1,1); color(129); printf(" Principal ");

    gotoxy(3,6); printf("Hora Sistema");
    gotoxy(3,7); printf("Fecha Sistema");

    gotoxy(3,9); printf("Puerto SATA 1      Hitachi HTS54505B9A300-(S1)");
    gotoxy(3,10); printf("Puerto SATA 2      HSSTcorp CDDVDW TS-L633C-(S2)");

    gotoxy(3,12); printf("CPU Tipo           Intel (R) Core (TM) i5 CPU M 450");
    gotoxy(3,13); printf("CPU Velocidad      2.40 GHz");
    gotoxy(3,14); printf("CPU VT (VT-x)      Soportado");

    gotoxy(3,16); printf("Memoria Total      4096 MB");
    gotoxy(3,17); printf("Memoria Slot 1     2048 MB");
    gotoxy(3,18); printf("Memoria Slot 2     2048 MB");

    gotoxy(3,20); printf("BIOS Version       10SZ");
    gotoxy(3,21); printf("MICOM Version      10SZ");

    gotoxy(57,8); color(128); printf("<TAB> o <ENTER> para");
    gotoxy(57,9); printf("cambiar a otro campo.");

    ///MOSTRAR HORA CORRECTAMENTE
    if(tiempo->tm_hour < 10) {gotoxy(22,6); color(128); cout<<"[0"<<tiempo->tm_hour;}
    else {gotoxy(22,6); color(128); cout<<"["<<tiempo->tm_hour;}

    if(tiempo->tm_min < 10) {gotoxy(25,6); color(128); cout<<":0"<<tiempo->tm_min;}
    else {gotoxy(25,6); color(128); cout<<":"<<tiempo->tm_min;}

    if(tiempo->tm_sec < 10) {gotoxy(28,6); color(128); cout<<":0"<<tiempo->tm_sec<<"]";}
    else {gotoxy(28,6); color(128); cout<<":"<<tiempo->tm_sec<<"]";}

    if(tiempo->tm_mday < 10) {gotoxy(22,7); color(128); cout<<"[0"<<tiempo->tm_mday;}
    else {gotoxy(22,7); color(128); cout<<"["<<tiempo->tm_mday;}

    if(tiempo->tm_mon < 10) {gotoxy(25,7); color(128); cout<<"/0"<<tiempo->tm_mon<<"/"<<tiempo->tm_year<<"]";}
    else {gotoxy(25,7); color(128); cout<<"/"<<tiempo->tm_mon<<"/"<<tiempo->tm_year<<"]";}

    int tecla = 0;
    int num_item = 0;
    int num_subitem = 0;
    int valor = 0;

    ///PINTAR OPCION POR DEFECTO
    gotoxy(3,6); color(143); printf("Hora Sistema");
    if(tiempo->tm_hour < 10) {gotoxy(23,6); color(8); cout<<"0"<<tiempo->tm_hour;}
    else {gotoxy(23,6); color(8); cout<<tiempo->tm_hour;}

    while(tecla != IZQUIERDA && tecla != DERECHA){

        if(kbhit()){

            tecla = getch();
            if(tecla == ARRIBA) {num_item--; num_subitem = 0; valor = 0;}
            if(tecla == ABAJO) {num_item++; num_subitem = 0; valor = 0;}
            if(tecla == ENTER || tecla == TAB) {num_subitem++; valor = 0;}
            if(tecla == F10) {VentanaGuardarYSalir(); break;}
            if(tecla == F1) {VentanaAyuda(); break;}
            if(tecla == F5){
                if(num_item == 0 && num_subitem == 0) tiempo->tm_hour--;
                if(num_item == 0 && num_subitem == 1) tiempo->tm_min--;
                if(num_item == 0 && num_subitem == 2) tiempo->tm_sec--;
                if(num_item == 1 && num_subitem == 0) tiempo->tm_mday--;
                if(num_item == 1 && num_subitem == 1) tiempo->tm_mon--;
                if(num_item == 1 && num_subitem == 2) tiempo->tm_year--;
            }
            if(tecla == F6){
                if(num_item == 0 && num_subitem == 0) tiempo->tm_hour++;
                if(num_item == 0 && num_subitem == 1) tiempo->tm_min++;
                if(num_item == 0 && num_subitem == 2) tiempo->tm_sec++;
                if(num_item == 1 && num_subitem == 0) tiempo->tm_mday++;
                if(num_item == 1 && num_subitem == 1) tiempo->tm_mon++;
                if(num_item == 1 && num_subitem == 2) tiempo->tm_year++;
            }

            ///FILTROS
            if(num_item < 0) num_item = 1;
            if(num_item > 1) num_item = 0;
            if(num_subitem > 2) num_subitem = 0;
            if(tiempo->tm_hour > 24) tiempo->tm_hour = 0;
            if(tiempo->tm_hour < 0) tiempo->tm_hour = 24;
            if(tiempo->tm_min > 59) tiempo->tm_min = 0;
            if(tiempo->tm_min < 0) tiempo->tm_min = 59;
            if(tiempo->tm_sec > 59) tiempo->tm_sec = 0;
            if(tiempo->tm_sec < 0) tiempo->tm_sec = 59;
            if(tiempo->tm_mday > 31) tiempo->tm_mday = 1;
            if(tiempo->tm_mday < 1) tiempo->tm_mday = 31;
            if(tiempo->tm_mon > 12) tiempo->tm_mon = 1;
            if(tiempo->tm_mon < 1) tiempo->tm_mon = 12;

            ///PINTAR OPCION SELECCIONADA
            ///HORA
            if(num_item == 0){gotoxy(3,6); color(143); printf("Hora Sistema");}
            else {gotoxy(3,6); color(129); printf("Hora Sistema");}

            if(num_item == 0 && num_subitem == 0){
                if(tiempo->tm_hour < 10) {gotoxy(23,6); color(8); cout<<"0"<<tiempo->tm_hour;}
                else {gotoxy(23,6); color(8); cout<<tiempo->tm_hour;}
            }
            else{
                if(tiempo->tm_hour < 10) {gotoxy(23,6); color(128); cout<<"0"<<tiempo->tm_hour;}
                else {gotoxy(23,6); color(128); cout<<tiempo->tm_hour;}
            }

            if(num_item == 0 && num_subitem == 1){
                if(tiempo->tm_min < 10) {gotoxy(26,6); color(8); cout<<"0"<<tiempo->tm_min;}
                else {gotoxy(26,6); color(8); cout<<tiempo->tm_min;}
            }
            else{
                if(tiempo->tm_min < 10) {gotoxy(26,6); color(128); cout<<"0"<<tiempo->tm_min;}
                else {gotoxy(26,6); color(128); cout<<tiempo->tm_min;}
            }

            if(num_item == 0 && num_subitem == 2){
                if(tiempo->tm_sec < 10) {gotoxy(29,6); color(8); cout<<"0"<<tiempo->tm_sec;}
                else {gotoxy(29,6); color(8); cout<<tiempo->tm_sec;}
            }
            else{
                if(tiempo->tm_sec < 10) {gotoxy(29,6); color(128); cout<<"0"<<tiempo->tm_sec;}
                else {gotoxy(29,6); color(128); cout<<tiempo->tm_sec;}
            }

            ///FECHA
            if(num_item == 1){gotoxy(3,7); color(143); printf("Fecha Sistema");}
            else {gotoxy(3,7); color(129); printf("Fecha Sistema");}

            if(num_item == 1 && num_subitem == 0){
                if(tiempo->tm_mday < 10) {gotoxy(23,7); color(8); cout<<"0"<<tiempo->tm_mday;}
                else {gotoxy(23,7); color(8); cout<<tiempo->tm_mday;}
            }
            else{
                if(tiempo->tm_mday < 10) {gotoxy(23,7); color(128); cout<<"0"<<tiempo->tm_mday;}
                else {gotoxy(23,7); color(128); cout<<tiempo->tm_mday;}
            }

            if(num_item == 1 && num_subitem == 1){
                if(tiempo->tm_mon < 10) {gotoxy(26,7); color(8); cout<<"0"<<tiempo->tm_mon;}
                else {gotoxy(26,7); color(8); cout<<tiempo->tm_mon;}
            }
            else{
                if(tiempo->tm_mon < 10) {gotoxy(26,7); color(128); cout<<"0"<<tiempo->tm_mon;}
                else {gotoxy(26,7); color(128); cout<<tiempo->tm_mon;}
            }

            if(num_item == 1 && num_subitem == 2){
                gotoxy(29,7); color(8); cout<<tiempo->tm_year;
            }
            else{
                gotoxy(29,7); color(128); cout<<tiempo->tm_year;
            }
        }
    }

    if(tecla == DERECHA) *num_menu = *num_menu + 1;
    if(tecla == IZQUIERDA) *num_menu = *num_menu - 1;
}

void MenuAvanzado(int *num_menu, SAvanzado *A){

    gotoxy(14,1); color(129); printf(" Avanzado ");

    int tecla = 0;
    int num_item = 0;
    bool entrar = true; ///Bool para entrar al IF solo en la primera ejecucion y mostrar las opciones

    while(tecla != IZQUIERDA && tecla != DERECHA){

        if(kbhit() || entrar == true){

            if(entrar == false){tecla = getch();}
            entrar = false; ///El bool vuelve a ser falso para siempre y solo continuar si se presiona una tecla

            if(tecla == ARRIBA) {num_item--;}
            if(tecla == ABAJO) {num_item++;}
            if(tecla == F10) {VentanaGuardarYSalir(); break;}
            if(tecla == F1) {VentanaAyuda(); break;}
            if(tecla == ENTER){
                if(num_item == 0){A->speedstep = VentanaHabilitar(A->speedstep);}
                if(num_item == 1){A->hyperthreading = VentanaHabilitar(A->hyperthreading);}
                if(num_item == 2){A->legacy_os = VentanaHabilitar(A->legacy_os);}
                if(num_item == 3){A->large_disk = VentanaDOS(A->large_disk);}
                if(num_item == 4){A->ahci = VentanaAutoManual(A->ahci);}
                if(num_item == 5){A->edb = VentanaHabilitar(A->edb);}
                if(num_item == 6){A->lan = VentanaHabilitar(A->lan);}
                if(num_item == 7){A->mouse = VentanaHabilitar(A->mouse);}
                if(num_item == 8){A->led = VentanaTouchpadLed(A->led);}
                if(num_item == 9){A->saving_cpu = VentanaHabilitar(A->saving_cpu);}
                if(num_item == 10){A->fan = VentanaFan(A->fan);}
                if(num_item == 11){A->usb_s3 = VentanaHabilitar(A->usb_s3);}
                if(num_item == 12){A->usb_cargador = VentanaHabilitar(A->usb_cargador);}
                if(num_item == 13){A->bateria = VentanaHabilitar(A->bateria);}
            }

            if(num_item > 13) num_item = 0;
            if(num_item < 0) num_item = 13;

            ///Borrar residuos de ventanas de seleccion
            for(int i=0; i<5; i++){gotoxy(30,15+i); color(128); printf("      ");}
            gotoxy(34,20); color(128); printf("  ");

            ///Borrar ayuda para dibujar una nueva
            for(int i=0; i<14; i++){gotoxy(57,8+i); color(128); printf("                        ");}

            if(num_item == 0){
                    gotoxy(3,6); color(143); printf("Intel (R) SpeedStep(tm)");
                    gotoxy(36,6); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->speedstep == 0){gotoxy(36,6); color(128); printf("[             ]"); gotoxy(37,6); color(8); printf("Deshabilitado");}
                    if(A->speedstep == 1){gotoxy(36,6); color(128); printf("[          ]"); gotoxy(37,6); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("Permite que mas de dos");
                    gotoxy(57,9); color(128); printf("rangos de frecuencia");
                    gotoxy(57,10); color(128); printf("sean soportados.");
            }
            else{
                    gotoxy(3,6); color(129); printf("Intel (R) SpeedStep(tm)");
                    gotoxy(36,6); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->speedstep == 0){gotoxy(36,6); color(128); printf("[Deshabilitado]");}
                    if(A->speedstep == 1){gotoxy(36,6); color(128); printf("[Habilitado]");}
            }

            if(num_item == 1){
                    gotoxy(3,7); color(143); printf("HyperThreading");
                    gotoxy(36,7); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->hyperthreading == 0){gotoxy(36,7); color(128); printf("[             ]"); gotoxy(37,7); color(8); printf("Deshabilitado");}
                    if(A->hyperthreading == 1){gotoxy(36,7); color(128); printf("[          ]"); gotoxy(37,7); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("Habilitar hyperthreading");
                    gotoxy(57,9); color(128); printf("activa subprocesos de");
                    gotoxy(57,10); color(128); printf("CPU adicionales. Estos");
                    gotoxy(57,11); color(128); printf("subprocesos pueden");
                    gotoxy(57,12); color(128); printf("aparecer como");
                    gotoxy(57,13); color(128); printf("procesadores adicionales");
                    gotoxy(57,14); color(128); printf("pero compartiran algunos");
                    gotoxy(57,15); color(128); printf("recursos con los otros");
                    gotoxy(57,16); color(128); printf("subprocesos dentro del");
                    gotoxy(57,17); color(128); printf("paquete fisico.");
            }
            else{
                    gotoxy(3,7); color(129); printf("HyperThreading");
                    gotoxy(36,7); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->hyperthreading == 0){gotoxy(36,7); color(128); printf("[Deshabilitado]");}
                    if(A->hyperthreading == 1){gotoxy(36,7); color(128); printf("[Habilitado]");}
            }

            if(num_item == 2){
                    gotoxy(3,8); color(143); printf("Arranque Legacy OS");
                    gotoxy(36,8); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->legacy_os == 0){gotoxy(36,8); color(128); printf("[             ]"); gotoxy(37,8); color(8); printf("Deshabilitado");}
                    if(A->legacy_os == 1){gotoxy(36,8); color(128); printf("[          ]"); gotoxy(37,8); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("Seleccione Habilitado");
                    gotoxy(57,9); color(128); printf("para intentar solamente");
                    gotoxy(57,10); color(128); printf("el arranque Legacy OS.");
                    gotoxy(57,12); color(128); printf("Seleccione Deshabilitado");
                    gotoxy(57,13); color(128); printf("para intentar el");
                    gotoxy(57,14); color(128); printf("arranque EFI primero.");
                    gotoxy(57,15); color(128); printf("Legacy OS arranca en");
                    gotoxy(57,16); color(128); printf("segundo lugar.");
            }
            else{
                    gotoxy(3,8); color(129); printf("Arranque Legacy OS");
                    gotoxy(36,8); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->legacy_os == 0){gotoxy(36,8); color(128); printf("[Deshabilitado]");}
                    if(A->legacy_os == 1){gotoxy(36,8); color(128); printf("[Habilitado]");}
            }

            if(num_item == 3){
                    gotoxy(3,9); color(143); printf("Modo Acceso Disco Grande");
                    gotoxy(36,9); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->large_disk == 0){gotoxy(36,9); color(128); printf("[    ]"); gotoxy(37,9); color(8); printf("Otro");}
                    if(A->large_disk == 1){gotoxy(36,9); color(128); printf("[   ]"); gotoxy(37,9); color(8); printf("DOS");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("UNIX, Novell NetWare u");
                    gotoxy(57,9); color(128); printf("otros sistemas");
                    gotoxy(57,10); color(128); printf("operativos, seleccione");
                    gotoxy(57,11); color(128); printf("'Otro'. Si esta");
                    gotoxy(57,12); color(128); printf("instalando un nuevo");
                    gotoxy(57,13); color(128); printf("software y la unidad");
                    gotoxy(57,14); color(128); printf("falla, cambie esta");
                    gotoxy(57,15); color(128); printf("seleccion e intente");
                    gotoxy(57,16); color(128); printf("nuevamente.");
                    gotoxy(57,17); color(128); printf("Los diferentes sistemas");
                    gotoxy(57,18); color(128); printf("operativos requieren");
                    gotoxy(57,19); color(128); printf("diferentes");
                    gotoxy(57,20); color(128); printf("representaciones de las");
                    gotoxy(57,21); color(128); printf("geometrias de la unidad.");
            }
            else{
                    gotoxy(3,9); color(129); printf("Modo Acceso Disco Grande");
                    gotoxy(36,9); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->large_disk == 0){gotoxy(36,9); color(128); printf("[Otro]");}
                    if(A->large_disk == 1){gotoxy(36,9); color(128); printf("[DOS]");}
            }

            if(num_item == 4){
                    gotoxy(3,11); color(143); printf("Control De Modo AHCI");
                    gotoxy(36,11); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->ahci == 0){gotoxy(36,11); color(128); printf("[    ]"); gotoxy(37,11); color(8); printf("Auto");}
                    if(A->ahci == 1){gotoxy(36,11); color(128); printf("[      ]"); gotoxy(37,11); color(8); printf("Manual");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("[Auto]");
                    gotoxy(57,9); color(128); printf("El modo AHCI se habilita");
                    gotoxy(57,10); color(128); printf("cuando el sistema");
                    gotoxy(57,11); color(128); printf("operativo es Microsoft");
                    gotoxy(57,12); color(128); printf("Windows Vista / Win7,");
                    gotoxy(57,13); color(128); printf("de lo contrario, cuando");
                    gotoxy(57,14); color(128); printf("el sistema operativo es");
                    gotoxy(57,15); color(128); printf("Microsoft Windows XP,");
                    gotoxy(57,16); color(128); printf("AHCI se desactiva");
                    gotoxy(57,17); color(128); printf("automaticamente.");
                    gotoxy(57,19); color(128); printf("[Manual]");
                    gotoxy(57,20); color(128); printf("Seleccione el modo AHCI");
                    gotoxy(57,21); color(128); printf("manualmente.");
            }
            else{
                    gotoxy(3,11); color(129); printf("Control De Modo AHCI");
                    gotoxy(36,11); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->ahci == 0){gotoxy(36,11); color(128); printf("[Auto]");}
                    if(A->ahci == 1){gotoxy(36,11); color(128); printf("[Manual]");}
            }

            if(num_item == 5){
                    gotoxy(3,12); color(143); printf("EDB (Ejecutar Desactivar Bit)");
                    gotoxy(36,12); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->edb == 0){gotoxy(36,12); color(128); printf("[             ]"); gotoxy(37,12); color(8); printf("Deshabilitado");}
                    if(A->edb == 1){gotoxy(36,12); color(128); printf("[          ]"); gotoxy(37,12); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("'Habilitado' es");
                    gotoxy(57,9); color(128); printf("compatible con la");
                    gotoxy(57,10); color(128); printf("funcion Prevencion De");
                    gotoxy(57,11); color(128); printf("Ejecucion De Datos (DEP)");
                    gotoxy(57,13); color(128); printf("DEP es un conjunto de");
                    gotoxy(57,14); color(128); printf("tecnologias de H/W y S/W");
                    gotoxy(57,15); color(128); printf("que realizan");
                    gotoxy(57,16); color(128); printf("comprobaciones");
                    gotoxy(57,17); color(128); printf("adicionales en la");
                    gotoxy(57,18); color(128); printf("memoria para ayudar a");
                    gotoxy(57,19); color(128); printf("evitar que codigo");
                    gotoxy(57,20); color(128); printf("malicioso se ejecute en");
                    gotoxy(57,21); color(128); printf("un sistema.");
            }
            else{
                    gotoxy(3,12); color(129); printf("EDB (Ejecutar Desactivar Bit)");
                    gotoxy(36,12); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->edb == 0){gotoxy(36,12); color(128); printf("[Deshabilitado]");}
                    if(A->edb == 1){gotoxy(36,12); color(128); printf("[Habilitado]");}
            }

            if(num_item == 6){
                    gotoxy(3,13); color(143); printf("LAN Interno");
                    gotoxy(36,13); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->lan == 0){gotoxy(36,13); color(128); printf("[             ]"); gotoxy(37,13); color(8); printf("Deshabilitado");}
                    if(A->lan == 1){gotoxy(36,13); color(128); printf("[          ]"); gotoxy(37,13); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("Establecer el elemento");
                    gotoxy(57,9); color(128); printf("en 'Habilitado'");
                    gotoxy(57,10); color(128); printf("permitira que el LAN");
                    gotoxy(57,11); color(128); printf("interno funcione");
                    gotoxy(57,12); color(128); printf("correctamente.");
                    gotoxy(57,14); color(128); printf("Si configura el elemento");
                    gotoxy(57,15); color(128); printf("como 'Deshabilitado', se");
                    gotoxy(57,16); color(128); printf("eliminara el LAN interno");
                    gotoxy(57,17); color(128); printf("del espacio de");
                    gotoxy(57,18); color(128); printf("configuracion de PCI.");
            }
            else{
                    gotoxy(3,13); color(129); printf("LAN Interno");
                    gotoxy(36,13); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->lan == 0){gotoxy(36,13); color(128); printf("[Deshabilitado]");}
                    if(A->lan == 1){gotoxy(36,13); color(128); printf("[Habilitado]");}
            }

            if(num_item == 7){
                    gotoxy(3,14); color(143); printf("Mouse Touch Pad");
                    gotoxy(36,14); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->mouse == 0){gotoxy(36,14); color(128); printf("[             ]"); gotoxy(37,14); color(8); printf("Deshabilitado");}
                    if(A->mouse == 1){gotoxy(36,14); color(128); printf("[          ]"); gotoxy(37,14); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("'Deshabilitado' impide");
                    gotoxy(57,9); color(128); printf("que el mouse tactil");
                    gotoxy(57,10); color(128); printf("instalado funcione, pero");
                    gotoxy(57,11); color(128); printf("libera el IRQ 12.");
                    gotoxy(57,13); color(128); printf("'Habilitado' obliga a");
                    gotoxy(57,14); color(128); printf("que el mouse tactil se");
                    gotoxy(57,15); color(128); printf("active.");
            }
            else{
                    gotoxy(3,14); color(129); printf("Mouse Touch Pad");
                    gotoxy(36,14); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->mouse == 0){gotoxy(36,14); color(128); printf("[Deshabilitado]");}
                    if(A->mouse == 1){gotoxy(36,14); color(128); printf("[Habilitado]");}
            }

            if(num_item == 8){
                    gotoxy(3,15); color(143); printf("LED Touch Pad");
                    gotoxy(36,15); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->led == 0){gotoxy(36,15); color(128); printf("[    ]"); gotoxy(37,15); color(8); printf("Auto");}
                    if(A->led == 1){gotoxy(36,15); color(128); printf("[        ]"); gotoxy(37,15); color(8); printf("Touchpad");}
                    if(A->led == 2){gotoxy(36,15); color(128); printf("[       ]"); gotoxy(37,15); color(8); printf("Apagado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("'Auto' significa que el");
                    gotoxy(57,9); color(128); printf("LED se encendera cuando");
                    gotoxy(57,10); color(128); printf("toques el pad.");
                    gotoxy(57,12); color(128); printf("'Touchpad' significa que");
                    gotoxy(57,13); color(128); printf("el LED funciona de");
                    gotoxy(57,14); color(128); printf("acuerdo con el estado");
                    gotoxy(57,15); color(128); printf("del Touchpad.");
                    gotoxy(57,17); color(128); printf("'Apagado' significa que");
                    gotoxy(57,18); color(128); printf("el LED siempre estara");
                    gotoxy(57,19); color(128); printf("apagado.");
            }
            else{
                    gotoxy(3,15); color(129); printf("LED Touch Pad");
                    gotoxy(36,15); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->led == 0){gotoxy(36,15); color(128); printf("[Auto]");}
                    if(A->led == 1){gotoxy(36,15); color(128); printf("[Touchpad]");}
                    if(A->led == 2){gotoxy(36,15); color(128); printf("[Apagado]");}
            }

            if(num_item == 9){
                    gotoxy(3,16); color(143); printf("Modo De Ahorro CPU");
                    gotoxy(36,16); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->saving_cpu == 0){gotoxy(36,16); color(128); printf("[             ]"); gotoxy(37,16); color(8); printf("Deshabilitado");}
                    if(A->saving_cpu == 1){gotoxy(36,16); color(128); printf("[          ]"); gotoxy(37,16); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("'Habilitado' disminuira");
                    gotoxy(57,9); color(128); printf("el consumo de energia");
                    gotoxy(57,10); color(128); printf("del sistema.");
                    gotoxy(57,12); color(128); printf("'Deshabilitado'");
                    gotoxy(57,13); color(128); printf("aumentara el consumo de");
                    gotoxy(57,14); color(128); printf("energia del sistema,");
                    gotoxy(57,15); color(128); printf("pero el tiempo de");
                    gotoxy(57,16); color(128); printf("respuesta es ligeramente");
                    gotoxy(57,17); color(128); printf("mas rapido que");
                    gotoxy(57,18); color(128); printf("'Habilitado'.");
            }
            else{
                    gotoxy(3,16); color(129); printf("Modo De Ahorro CPU");
                    gotoxy(36,16); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->saving_cpu == 0){gotoxy(36,16); color(128); printf("[Deshabilitado]");}
                    if(A->saving_cpu == 1){gotoxy(36,16); color(128); printf("[Habilitado]");}
            }

            if(num_item == 10){
                    gotoxy(3,17); color(143); printf("Ventilacion Silenciosa");
                    gotoxy(36,17); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->fan == 0){gotoxy(36,17); color(128); printf("[    ]"); gotoxy(37,17); color(8); printf("Bajo");}
                    if(A->fan == 1){gotoxy(36,17); color(128); printf("[    ]"); gotoxy(37,17); color(8); printf("Auto");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("'Bajo' hara girar el");
                    gotoxy(57,9); color(128); printf("ventilador del sistema a");
                    gotoxy(57,10); color(128); printf("baja velocidad y");
                    gotoxy(57,11); color(128); printf("minimizara la frecuencia");
                    gotoxy(57,12); color(128); printf("de detencion.");
                    gotoxy(57,14); color(128); printf("'Auto' repetira girar");
                    gotoxy(57,15); color(128); printf("y parar.");
            }
            else{
                    gotoxy(3,17); color(129); printf("Ventilacion Silenciosa");
                    gotoxy(36,17); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->fan == 0){gotoxy(36,17); color(128); printf("[Bajo]");}
                    if(A->fan == 1){gotoxy(36,17); color(128); printf("[Auto]");}
            }

            if(num_item == 11){
                    gotoxy(3,18); color(143); printf("USB S3 Wake-up");
                    gotoxy(36,18); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->usb_s3 == 0){gotoxy(36,18); color(128); printf("[             ]"); gotoxy(37,18); color(8); printf("Deshabilitado");}
                    if(A->usb_s3 == 1){gotoxy(36,18); color(128); printf("[          ]"); gotoxy(37,18); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("Seleccione 'Habilitado'");
                    gotoxy(57,9); color(128); printf("para permitir que el");
                    gotoxy(57,10); color(128); printf("sistema pueda ser");
                    gotoxy(57,11); color(128); printf("activado desde el estado");
                    gotoxy(57,12); color(128); printf("ACPI S3 mediante");
                    gotoxy(57,13); color(128); printf("actividades USB.");
                    gotoxy(57,15); color(128); printf("Seleccione Deshabilitado");
                    gotoxy(57,16); color(128); printf("para no usar la");
                    gotoxy(57,17); color(128); printf("capacidad de activacion");
                    gotoxy(57,18); color(128); printf("desde el USB.");
                    gotoxy(57,19); color(128); printf("(Vista / Win7 solamente)");
            }
            else{
                    gotoxy(3,18); color(129); printf("USB S3 Wake-up");
                    gotoxy(36,18); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->usb_s3 == 0){gotoxy(36,18); color(128); printf("[Deshabilitado]");}
                    if(A->usb_s3 == 1){gotoxy(36,18); color(128); printf("[Habilitado]");}
            }

            if(num_item == 12){
                    gotoxy(3,19); color(143); printf("Cargador USB En Modo Reposo");
                    gotoxy(36,19); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->usb_cargador == 0){gotoxy(36,19); color(128); printf("[             ]"); gotoxy(37,19); color(8); printf("Deshabilitado");}
                    if(A->usb_cargador == 1){gotoxy(36,19); color(128); printf("[          ]"); gotoxy(37,19); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("'Habilitado' significa");
                    gotoxy(57,9); color(128); printf("que el sistema admite la");
                    gotoxy(57,10); color(128); printf("funcion de carga USB en");
                    gotoxy(57,11); color(128); printf("el puerto que tiene el");
                    gotoxy(57,12); color(128); printf("icono especial, en el");
                    gotoxy(57,13); color(128); printf("modo de suspension.");
                    gotoxy(57,15); color(128); printf("'Desactivado' significa");
                    gotoxy(57,16); color(128); printf("que el sistema no admite");
                    gotoxy(57,17); color(128); printf("la funcion de carga USB");
                    gotoxy(57,18); color(128); printf("en el modo de suspension");
            }
            else{
                    gotoxy(3,19); color(129); printf("Cargador USB En Modo Reposo");
                    gotoxy(36,19); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->usb_cargador == 0){gotoxy(36,19); color(128); printf("[Deshabilitado]");}
                    if(A->usb_cargador == 1){gotoxy(36,19); color(128); printf("[Habilitado]");}
            }

            if(num_item == 13){
                    gotoxy(3,20); color(143); printf("Extension Ciclo De Vida Bateria");
                    gotoxy(36,20); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->bateria == 0){gotoxy(36,20); color(128); printf("[             ]"); gotoxy(37,20); color(8); printf("Deshabilitado");}
                    if(A->bateria == 1){gotoxy(36,20); color(128); printf("[          ]"); gotoxy(37,20); color(8); printf("Habilitado");}

                    ///Ayuda
                    gotoxy(57,8); color(128); printf("'Habilitado' significa");
                    gotoxy(57,9); color(128); printf("que el sistema cargara");
                    gotoxy(57,10); color(128); cout<<"la bateria hasta 80%";
                    gotoxy(57,11); color(128); printf("para extender el ciclo");
                    gotoxy(57,12); color(128); printf("de vida de la bateria.");
                    gotoxy(57,14); color(128); printf("'Deshabilitado'");
                    gotoxy(57,15); color(128); printf("significa que el sistema");
                    gotoxy(57,16); color(128); printf("cargara la bateria hasta");
                    gotoxy(57,17); color(128); cout<<"el 100%";
            }
            else{
                    gotoxy(3,20); color(129); printf("Extension Ciclo De Vida Bateria");
                    gotoxy(36,20); color(128); printf("               "); ///Borra residuos antes de dibujar
                    if(A->bateria == 0){gotoxy(36,20); color(128); printf("[Deshabilitado]");}
                    if(A->bateria == 1){gotoxy(36,20); color(128); printf("[Habilitado]");}
            }
        }
    }

    if(tecla == DERECHA) *num_menu = *num_menu + 1;
    if(tecla == IZQUIERDA) *num_menu = *num_menu - 1;
}

void MenuSeguridad(int *num_menu, SSeguridad *B){

    gotoxy(26,1); color(129); printf(" Seguridad ");

    gotoxy(3,6); printf("Contrase%ca Supervisor",164);
    gotoxy(3,7); printf("Contrase%ca Usuario",164);
    gotoxy(3,8); printf("Contrase%ca Disco Duro",164);

    int tecla = 0;
    int num_item = 0;
    bool entrar = true;
    bool supervisor = false;
    bool usuario = false;
    bool discoduro = false;

    while(tecla != IZQUIERDA && tecla != DERECHA){

        if(kbhit() || entrar == true){

            if(entrar == false) {tecla = getch();}
            entrar = false;

            if(tecla == ARRIBA){num_item--;}
            if(tecla == ABAJO){num_item++;}
            if(tecla == ENTER){
                if(num_item == 0){VentanaContrasenia(0, B, supervisor);}
                if(num_item == 1){VentanaContrasenia(1, B, usuario);}
                if(num_item == 2){VentanaContrasenia(2, B, discoduro);}
                if(num_item == 3){B->aliniciar = VentanaHabilitar(B->aliniciar);}
            }

            if(num_item > 3) num_item = 0;
            if(num_item < 0) num_item = 3;

            if(strcmp(B->supervisor,"\0") == 0){gotoxy(35,6); color(129); printf("           "); gotoxy(35,6); printf("No Agregada"); supervisor = false;}
            else{gotoxy(35,6); color(129); printf("           "); gotoxy(35,6); printf("Agregada"); supervisor = true;}

            if(strcmp(B->usuario,"\0") == 0){gotoxy(35,7); color(129); printf("           "); gotoxy(35,7); printf("No Agregada"); usuario = false;}
            else{gotoxy(35,7); color(129); printf("           "); gotoxy(35,7); printf("Agregada"); usuario = true;}

            if(strcmp(B->discoduro,"\0") == 0){gotoxy(35,8); color(129); printf("           "); gotoxy(35,8); printf("No Agregada"); discoduro = false;}
            else{gotoxy(35,8); color(129); printf("           "); gotoxy(35,8); printf("Agregada"); discoduro = true;}

            ///Borrar ayuda para dibujar una nueva
            for(int i=0; i<14; i++){gotoxy(57,8+i); color(128); printf("                        ");}

            if(num_item == 0){
                gotoxy(3,10); color(143); printf("Agregar Contrase%ca Supervisor",164);
                gotoxy(35,10); color(128); printf("[        ]");
                gotoxy(36,10); color(8); printf("Ingresar");

                ///Ayuda
                gotoxy(57,8); color(128); printf("La contrase%ca del",164);
                gotoxy(57,9); color(128); printf("supervisor controla el");
                gotoxy(57,10); color(128); printf("acceso al BIOS.");
            }
            else{
                gotoxy(3,10); color(129); printf("Agregar Contrase%ca Supervisor",164);
                gotoxy(35,10); color(128); printf("[Ingresar]");
            }

            if(num_item == 1){
                gotoxy(3,11); color(143); printf("Agregar Contrase%ca Usuario",164);
                gotoxy(35,11); color(128); printf("[        ]");
                gotoxy(36,11); color(8); printf("Ingresar");

                ///Ayuda
                gotoxy(57,8); color(128); printf("La contrase%ca del",164);
                gotoxy(57,9); color(128); printf("usuario controla el");
                gotoxy(57,10); color(128); printf("acceso al sistema al");
                gotoxy(57,11); color(128); printf("iniciar.");
            }
            else{
                gotoxy(3,11); color(129); printf("Agregar Contrase%ca Usuario",164);
                gotoxy(35,11); color(128); printf("[Ingresar]");
            }

            if(num_item == 2){
                gotoxy(3,12); color(143); printf("Agregar Contrase%ca Disco Duro",164);
                gotoxy(35,12); color(128); printf("[        ]");
                gotoxy(36,12); color(8); printf("Ingresar");

                ///Ayuda
                gotoxy(57,8); color(128); printf("Despues de guardar la");
                gotoxy(57,9); color(128); printf("configuracion, el");
                gotoxy(57,10); color(128); printf("sistema debe ser");
                gotoxy(57,11); color(128); printf("reiniciado para");
                gotoxy(57,12); color(128); printf("actualizar la contrase%ca",164);
            }
            else{
                gotoxy(3,12); color(129); printf("Agregar Contrase%ca Disco Duro",164);
                gotoxy(35,12); color(128); printf("[Ingresar]");
            }

            if(num_item == 3){
                gotoxy(3,14); color(143); printf("Contrase%ca al iniciar",164);
                if(B->aliniciar == 0){gotoxy(35,14); color(128); printf("[             ]"); gotoxy(36,14); color(8); printf("Deshabilitado");}
                if(B->aliniciar == 1){gotoxy(35,14); color(128); printf("[          ]"); gotoxy(36,14); color(8); printf("Habilitado");}

                gotoxy(57,8); color(128); printf("Habilita una contrase%ca",164);
                gotoxy(57,9); color(128); printf("al arrancar.");
            }
            else{
                gotoxy(3,14); color(129); printf("Contrase%ca al iniciar",164);
                if(B->aliniciar == 0){gotoxy(35,14); color(128); printf("[Deshabilitado]");}
                if(B->aliniciar == 1){gotoxy(35,14); color(128); printf("[Habilitado]");}
            }
        }
    }

    if(tecla == DERECHA) *num_menu = *num_menu + 1;
    if(tecla == IZQUIERDA) *num_menu = *num_menu - 1;
}

void MenuArranque(int *num_menu){

    gotoxy(39,1); color(129); printf(" Arranque ");

    int tecla = 0;
    int num_item = 0;
    bool entrar = true;

    while(tecla != IZQUIERDA && tecla != DERECHA){

        if(kbhit() || entrar == true){

            if(entrar == false) {tecla = getch();}
            entrar = false;
        }
    }

    if(tecla == DERECHA) *num_menu = *num_menu + 1;
    if(tecla == IZQUIERDA) *num_menu = *num_menu - 1;
}

void MenuSalir(int *num_menu){

    gotoxy(51,1); color(129); printf(" Salir ");

    int tecla = 0;

    while(tecla != IZQUIERDA && tecla != DERECHA){

        if(kbhit()){

            tecla = getch();
        }
    }

    if(tecla == DERECHA) *num_menu = *num_menu + 1;
    if(tecla == IZQUIERDA) *num_menu = *num_menu - 1;
}



int main()
{
    time_t ahora = time(0); ///Variable de tiempo para menu principal
    tm *tiempo = localtime(&ahora);
    tiempo->tm_year = tiempo->tm_year + 1900;
    tiempo->tm_mon = tiempo->tm_mon + 1;

    SAvanzado variables; ///Variables para el menu avanzado
    SSeguridad contrasenias; ///Variables para el menu seguridad

    int numero_menu = 3;

    Cursor(false);
    BarraDeTitulo();
    BarraInferior();
    BarraMenues();
    PintarFondo();

    while(true){

        if(numero_menu > 4) numero_menu = 0; ///Filtro
        if(numero_menu < 0) numero_menu = 4;

        BarraMenues(); ///Limpiar antes de dibujar
        BorrarFondo();

        switch(numero_menu){
            case 0: MenuPrincipal(&numero_menu, tiempo);
            break;
            case 1: MenuAvanzado(&numero_menu, &variables);
            break;
            case 2: MenuSeguridad(&numero_menu, &contrasenias);
            break;
            case 3: MenuArranque(&numero_menu);
            break;
            case 4: MenuSalir(&numero_menu);
            break;
        }
    }


    gotoxy(0,40); color(8);
    return 0;
}
