#include <iostream>

using namespace std;

struct alumno{

    int legajo;
    int nota1;
    int nota2;
};

int main(){

    FILE* archivo;
    archivo= fopen("archivitos.dat", "wb");

    alumno raux;

    cout << "Ingresar legajo: " << endl;
    cin >> raux.legajo; 

    while(raux.legajo !=0){

        cout << "Ingresar la nota 1:" << endl;
        cin >> raux.nota1;
        cout << "Ingresar la nota 2: " << endl;
        cin >> raux.nota2; 

        fwrite(&raux, sizeof(alumno), 1, archivo);

        cout << "Ingresar legajo: " << endl;
        cin >> raux.legajo; 
    }

    fclose(archivo); 

    return 0;
}