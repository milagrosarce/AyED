#include <iostream>

using  namespace std;

/*
Se tienen dos archivos de la materia prima necesaria para una
cadena de comidas rapidas BurgerFastAgosto.dat y BurgerFastSeptiembre.dat
ordenado por codigo de producto
-Codigo de producto: 
-Cantidad de unidades en deposito:
-Tipo de producto: H N P 

a) Obtener un archivo BurgerFast que consolide ambos archivos.
b) generar un archivo solo para panes Pan.dat con la siguiente estructura:
-codigo 
-cantidad de unidades
*/

struct datos{
    int codigo;
    int cant_unidades;
    char tipo;
};

struct datoPan{
    int codigo;
    int cant_unidades;
};

int main(){

    FILE *archivoA;
    archivoA = fopen("BurgerFastAgosto.dat", "rb");

    FILE *archivoB;
    archivoB = fopen("BurgerFastSeptiembre.dat", "rb");

    datos rauxA;
    datos rauxB;

    FILE *archivoPan;
    archivoPan = fopen("archivoPan.dat", "wb");
    datoPan auxPan;

    FILE *archivoNuevo;
    archivoNuevo = fopen("nuevito.dat", "wb");

    fread(&rauxA, sizeof(datos), 1, archivoA);
    fread(&rauxB, sizeof(datos), 1, archivoB);

    while(!feof(archivoA) && !feof(archivoB)){

        if(rauxA.tipo == 'P'){
            auxPan.cant_unidades = rauxA.cant_unidades;
            auxPan.codigo = rauxA.codigo;
            fwrite(&auxPan, sizeof(datoPan), 1, archivoPan);
        }

        if(rauxB.tipo == 'P'){
            auxPan.cant_unidades = rauxB.cant_unidades;
            auxPan.codigo = rauxB.codigo;
            fwrite(&auxPan, sizeof(datoPan), 1, archivoPan);
        }

        if(rauxA.codigo < rauxB.codigo){
            fwrite(&rauxA, sizeof(datos), 1, archivoNuevo);
            fread(&rauxA, sizeof(datos), 1, archivoA);  
        }else{
            fwrite(&rauxB, sizeof(datos), 1, archivoNuevo);
            fread(&rauxB, sizeof(datos), 1, archivoB);    
        }
    }

    while(!feof(archivoA)){
        
        if(rauxA.tipo == 'P'){
            auxPan.cant_unidades = rauxA.cant_unidades;
            auxPan.codigo = rauxA.codigo;
            fwrite(&auxPan, sizeof(datoPan), 1, archivoPan);
        }

        fwrite(&rauxA, sizeof(datos), 1, archivoNuevo);
        fread(&rauxA, sizeof(datos), 1, archivoA);
    }

    while(!feof(archivoB)){
        
        if(rauxB.tipo == 'P'){
            auxPan.cant_unidades = rauxB.cant_unidades;
            auxPan.codigo = rauxB.codigo;
            fwrite(&auxPan, sizeof(datoPan), 1, archivoPan);
        }

        fwrite(&rauxB, sizeof(datos), 1, archivoNuevo);
        fread(&rauxB, sizeof(datos), 1, archivoB);
    }

    fclose(archivoA);
    fclose(archivoB);
    fclose(archivoNuevo);
    fclose(archivoPan);

    return 0;
}