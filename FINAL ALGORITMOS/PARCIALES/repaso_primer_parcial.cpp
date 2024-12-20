#include <iostream>

using namespace std;

//----------------EJERCICIO 2--------------------------
/* Dado un vector de productos que contiene el codigo del producto, codigo de serie y la cantidad de unidades
disponible en deposito. se sabe que maximo hay 200 productos en la empresa. Determinar:
-cual es el producto que mas unidades tiene en deposito
-cuales son los productos cuyo codigo de serie es 7000
-calcular el promedio de unidades en el deposito por producto
*/

void inicializar(producto vector[], int len, producto valor); 

struct producto{
    int codigo;
    int serie;
    int cant_unidades;
};

int main(){

    producto vector[200];
    int len = 0;

    producto init;
    init.cant_unidades = 0;
    init.codigo = 0;
    init.serie = 0;

    inicializar(vector, len, init);

    int mayor = 0; 
    int thisone = 0; 
    int sumatoria = 0;
    int cont = 0;

    for(int i=0; i < len; i++){
        if(vector[i].serie == 7000){
            thisone = i; 
        }
        sumatoria += vector[i].cant_unidades;
        cont++;

    }

    mayor = masUnidades(vector, len);

    cout << "El que tiene mas unidades es: " << vector[mayor].codigo << "con: " << vector[mayor].cant_unidades << endl; 
    cout << "El producto cuyos codigos de serie es 7000 son: " << vector[thisone].codigo << endl;
    cout << "El promedio es de: " << sumatoria/cont << endl; 

    return 0; 
}

int masUnidades(producto vector[], int len){
    int base = vector[0].cant_unidades;
    int pos = 0;

    for(int i = 1; i < len; i++){
        if(vector[i].cant_unidades > base){
            base = vector[i].cant_unidades;
            pos = i; 
        }
    }
    return pos; 
}


/*----------------------------EJERCICIO 3-----------------------------------------------

se tiene un archivo de registros de tamaño fijo de proveedores con nombre Prov_AllProd.DAT. El formato
del registro de este archivo es el siguiente. 
Nro_prov: numero de proveedor/ numerico hasta 7 posiciones
Tipo_prod: tipo de producto que vende/ un caracter A;F o G;
Cpe: cantiad de productos entregados/ numerico entre 0 y 1000. 

Los registros en el archivo no tienen ningun orden especifico y se sabe que no contiene mas de 100. 

Se pide:

Realizar un programa que lea ese archivo y genere un archivo con el nombre PROV_A.DAT que contenga los
proveedores de la categoria Almacen y otro con los Gaseosas, PROV_G.DAT Ambos tienen que estar ordenados por la cantidad 
de articulos, entregados en forma descendente. 

El formato del registro de este archivo es el siguiente: 
NRO_EMPL: numero de empleado del vendedor/ Numerico de hasta 7 posiciones
CPV: Cantidad de productos vendidos/ Numerico entre 0 y 1000. 
*/

struct datos{
    int nro_prov;
    char tipo_prod;
    int cpe;
}; 

struct datosNuevos{
    int nro_empl;
    int cpv; 
}; 

void insertarOrdenado(datosNuevos vector[], int &len, datosNuevos valor); 


int main(){

    datosNuevos vectorA[100];
    int lenA= 0;
    datosNuevos vectorB[100];
    int lenB= 0;

    datosNuevos initA; 
    initA.nro_empl = 0;
    initA.cpv = 0;

    inicializar(vectorA, lenA, initA);
    inicializar(vectorB, lenB, initA); 

    FILE* archivo;
    archivo = fopen("Prov_AllProd.DAT", "rb");

    datos raux;
    datosNuevos aux;

    fread(&raux, sizeof(datos), 1, archivo);

    while(!feof(archivo)){

        if(raux.tipo_prod == 'A'){
            aux.cpv = raux.cpe;
            aux.nro_empl = raux.nro_prov; 
            insertarOrdenado(vectorA, lenA, aux);
        }

        if(raux.tipo_prod == 'G'){
            aux.cpv = raux.cpe;
            aux.nro_empl = raux.nro_prov;
            insertarOrdenado(vectorB, lenB, aux); 
        }
        fread(&raux, sizeof(datos), 1, archivo); 
    }
    fclose(archivo);

    //me quedaron dos vectores que tengan uno A y otro G, y ordenados entonces ahora tengo que crear esos archivos
    //ya los pase a una nueva estructura
    FILE* archivoA;
    archivoA = fopen("PROV_A.DAT", "wb"); 

    FILE* archivoB;
    archivoB = fopen("PROV_G.DAT", "wb");

    for(int i = 0; i < lenA; i++){
        fwrite(&vectorA[i], sizeof(datosNuevos), 1, archivoA);
    }

    for(int i=0; i< lenB; i++){
        fwrite(&vectorB[i], sizeof(datosNuevos), 1, archivoB); 
    }

    fclose(archivoA);
    fclose(archivoB); 

    return 0; 
}

