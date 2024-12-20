#include <iostream>
using namespace std;

struct jugador{
    int legajo;
    int nota1;
    int nota2;
};

int main(){

    FILE* archivoA;
    FILE* archivoB;
    FILE* archivoC;

    archivoA = fopen("archivitoA.dat", "rb");
    archivoB= fopen("archivitoB.dat", "rb");
    archivoC= fopen("archivitoC.dat", "wb");

    jugador rauxA;
    jugador rauxB;

    fread(&rauxA, sizeof(jugador), 1, archivoA);
    fread(&rauxB, sizeof(jugador), 1, archivoB);

    while((!feof(archivoA)) && (!feof(archivoB))){
        if(rauxA.legajo < rauxB.legajo){
            fwrite(&rauxA, sizeof(jugador), 1, archivoC); //como es mas chico a que b entonces escribo en c 
            fread(&rauxA, sizeof(jugador), 1, archivoA); //sigo leyendo con el que recien puse
        }else{
            fwrite(&rauxB,sizeof(jugador), 1, archivoC);
            fread(&rauxB, sizeof(jugador), 1, archivoB);
        }
    }

    while(!feof(archivoA)){
        fwrite(&rauxA, sizeof(jugador),1, archivoC);
        fread(&rauxA, sizeof(jugador), 1, archivoA);
    }

    while(!feof(archivoB)){
        fwrite(&rauxB, sizeof(jugador),1, archivoC);
        fread(&rauxB, sizeof(jugador), 1, archivoB);
    }

    fclose(archivoA);
    fclose(archivoB);
    fclose(archivoC); 

    return 0; 
}