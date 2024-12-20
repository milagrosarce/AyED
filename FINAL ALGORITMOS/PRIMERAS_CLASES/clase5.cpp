#include <iostream>

using namespace std;

struct datosAlumno{

    char nombre[50];
    int nota1;
    int nota2;
};

int main(){

    datosAlumno alumno;

    cout << "ingrese el nombre del alumno" << endl;
    cin >> alumno.nombre;
    cout << "ingrese la nota 1" << endl;
    cin >> alumno.nota1;
    cout << "ingrese la nota 2" << endl;
    cin >> alumno.nota2;

    cout << "El alumno " << alumno.nombre << " tiene un promedio de " << alumno.nota1 + alumno.nota2 / 2 << endl;
 


}