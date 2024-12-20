#include <iostream>
using namespace std;

/*
- Promedio de notas del primer parcial
- Quién obtuvo la mayor nota
- Quién obtuvo la menor nota
*/

struct alumno {
    int legajo;
    int nota1;
};

// Función que devuelve el índice del alumno con la menor nota
int menorVector(alumno vector[], int len);
int mayorvector(alumno vector[], int len); 

int main() {
    const int len = 10;
    alumno vector[len];

    int sumatoria = 0;
    int mejor = 0; 
    int peor = 0; 

    for (int i = 0; i < len; i++) {
        sumatoria += vector[i].nota1; //voy sumando todas las notas
    }

    mejor = mayorNota(vector, len);
    peor = menorVector(vector, len); 

    int promedio = sumatoria / len;

    // Mostrar resultados
    cout << "El promedio de las notas es: " << promedio << endl;
    cout << "La mejor nota fue: " << vector[mejor].legajo << endl;
    cout << "La peor nota fue: " << vector[peor].legajo << endl;

    return 0;
}


int mayorNota(alumno vector[], int len){

    int pos = 0;
    int mayor = vector[0].nota1;

    for (int i = 1; i < len; i++) { 
        if (vector[i].nota1 > mayor) {
            mayor = vector[i].nota1;
            pos = i; //me tengo que guardar la posicon para saber quien es tipo el nombre 
        }
    }
    return pos;
}

int menorVector(alumno vector[], int len) {
    int pos = 0;
    int menor = vector[0].nota1;

    for (int i = 1; i < len; i++) { // Empezar desde el segundo elemento
        if (vector[i].nota1 < menor) {
            menor = vector[i].nota1;
            pos = i;
        }
    }
    return pos; 
}
