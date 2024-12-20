#include <iostream>
using namespace std;

/*

dado un vector de registros acerca las estadisticas de los jugadores que participaron en la Copa America 2021 y 
marcaron goles, que contiene el codigo del jugador,inicial de seleccion a la que pertenecen y la cantidad de goles
convertidos. se sabe que hay como maximo 276 jugadores, se pide determinar:

-cual es el jugador que mas goles convirtio?
-cual es el jugador que menos goles convirtio
-promedio de goles convertidos
*/



struct jugador{
    int codigo;
    char inicial[2];
    int goles;
};

void inicializar (jugador vector[], int len, jugador valor); //inicializo el vector 
int buscarMasGoles(jugador vector[], int len);
int buscarMenosGoles(jugador vector[], int len); 

int main(){

    int len= 276;
    jugador vector[len]; 
    int sumatoria = 0; 
    int masGoles = 0;
    int menosGoles = 0;

    for(int i=0; i < len; i++){ //voy recorriendo el vector
       sumatoria += vector[i].goles;
    }

    masGoles = buscarMasGoles(vector, len); 
    menosGoles = buscarMenosGoles(vector, len); 

    int promedio = sumatoria / len; 

    cout << "El promedio es de: " << promedio << endl;
    cout << "El jugador: " << vector[masGoles].codigo << "fue el que mas goles metio, con un total de:" << vector[masGoles].goles << endl; 
    cout << "El jugador: " << vector[menosGoles].codigo << "fue el que menos goles metio, con un total de:" << vector[menosGoles].goles << endl; 
    
}

int buscarMasGoles(jugador vector[], int len){
    int base = vector[0].goles;
    int pos = 0;

    for(int i = 1; i < len; i++){
        if(vector[i].goles > base){
            base = vector[i].goles;
            pos = i; 
        }
    }

    return pos; 
}

int buscarMenosGoles(jugador vector[], int len){
    int base = vector[0].goles;
    int pos = 0;

    for(int i = 1; i < len; i++){
        if(vector[i].goles < base){
            base = vector[i].goles;
            pos = i; 
        }
    }

    return pos; 
}