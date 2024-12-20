#include <iostream>
using namespace std;

/*
-promedio del primer parcial
-saber cuantos alumnos desaprobaron
-saber cuantos alumnos sacaron mas de 8
-quien obtuvo la mayor nota
*/

struct alumno{

    int legajo;
    int nota;
};

int masNota(alumno vector[], int len);

int main(){

    int len=10;
    alumno vector[len]; //doy por hecho que el vector ya esta inicializado 
    int sumatoria = 0; 
    int desaprobados = 0;
    int promocionado = 0;
    int mejor = 0;

    for(int i=0; i<< len;i++){
        sumatoria += vector[i].nota;
        
        if(vector[i].nota < 6){
            desaprobados++;
        }

        if(vector[i].nota >= 8){
            promocionado++;
        }
    }

    mejor = masNota(vector, len); 

    int promedio = sumatoria / len; 

    cout << "El promedio es: " << promedio << endl;
    cout << "Desaprobaron: " << desaprobados << endl;
    cout << "Promocionados: " << promocionado << endl;
    cout << "El de mas nota es" << vector[mejor].legajo << "con un: " << vector[mejor].nota << endl; 

    return 0; 
}


int masNota(alumno vector[], int len){
    int base = vector[0].nota;
    int pos = 0;

    for(int i = 1; i < len; i++){
        if(vector[i].nota > base){
            base = vector[i].nota;
            pos = i; 
        }
    }

    return pos; 
}