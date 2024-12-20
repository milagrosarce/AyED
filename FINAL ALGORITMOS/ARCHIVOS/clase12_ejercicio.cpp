#include <iostream>

using namespace std; 

/* se tiene un archivo de registros 
de tamaño fijo de los jugadores convocados

codigo:
seleccion id:
edad:
altura:

se pide realizar un programa que lea ese archivo y genere dos archivos
un vector de sub23 con los mismo campos 
y otro vector con los jugadores que midan mas de 1,80 
pero aca la struct cambia y me quedo solo
con el ccodigo id y edad. 
*/

struct jugador{

    int codigo;
    int id;
    int edad;
    int altura;
};

struct jugadorAltos{
    int codigo;
    int id;
    int edad;
};

void inicializarA(jugador vector[], int len, jugador valor);
void inicializarB(jugadorAltos vector[], int len, jugadorAltos valor); 
void insertarOrdenadoA(jugador vector[], int &len, jugador valor); 
void insertarOrdenadoB(jugadorAltos vector[], int &len, jugadorAltos valor);
void insertarA(jugador vector[], int &len, jugador valor, int pos);
void insertarB(jugadorAltos vector[], int &len, jugadorAltos valor, int pos);

int main(){

    jugador vectorA[100];
    int lenA=0;

    jugadorAltos vectorB[100];
    int lenB=0;

    jugador initA;
    initA.altura;
    initA.codigo;
    initA.edad;
    initA.id;

    jugadorAltos initB;
    initB.codigo;
    initB.edad;
    initB.id; 

    inicializarA(vectorA, 100, initA);
    inicializarB(vectorB, 100, initB); 

    FILE* archivo;
    archivo = fopen("archivito.dat", "rb"); 

    jugador raux;
    jugadorAltos aux;

    fread(&raux, sizeof(jugador), 1, archivo);

    while(!feof(archivo)){

        if(raux.edad < 23){
            insertarOrdenadoA(vectorA, lenA, raux);
        }

        if(raux.altura >= 180){
            aux.codigo = raux.codigo; //lo paso a la estructura que corresponde para despues armar mi vector diferente 
            aux.edad = raux.edad;
            aux.id = raux.id; 
            insertarOrdenadoB(vectorB, lenB, aux);
        }

        fread(&raux, sizeof(jugador),1, archivo);
    }
    fclose(archivo);

    return 0; 
}