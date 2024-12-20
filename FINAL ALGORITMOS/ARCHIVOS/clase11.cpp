#include <iostream>

using namespace std;

/* 
Se tiene un archivo de peliculas infantiles en una plataforma digital con los titulos disponibles para la A:
- codigo de pelicula: 999999
- cantidad de opiniones positivas: 99999
- cantidad de vistas: 9999999

Se pide: 
- ordenar el archivo por opiniones positivas.
- listar las 10 peliuclas que mas tuvieron. 
- se sabe que no hay mas de 50 peliculas. 
*/

struct pelicula{
    int codigo;
    int cant_opiniones;
    int cant_visitas;
};

void inicializar(pelicula vector[], int len, pelicula valor);
void insertar(pelicula vector[], int &len, pelicula valor, int pos);
void insertarOrdenadoA(pelicula vector[], int &len, pelicula valor);
void insertarOrdenadoB(pelicula vector[], int &len, pelicula valor); 


int main(){

//---------------VECTOR----------------------
    pelicula vector[50];
    pelicula vectorB[50];
    int lenA=0;
    int lenB=0;

    pelicula ini;
    ini.codigo=0;
    ini.cant_visitas=0;
    ini.cant_opiniones=0;

    inicializar(vector, 50, ini);
    inicializar(vectorB, 50, ini); 
//-----------------------------------------

    FILE* archivo;
    archivo = fopen("peliculas.dat", "rb");

    pelicula raux;

    fread(&raux, sizeof(pelicula), 1, archivo); 

    while(!feof(archivo)){

        insertarOrdenadoA(vector, lenA,raux);
        insertarOrdenadoB(vectorB, lenB, raux);

        fread(&raux, sizeof(pelicula),1, archivo);
    }
    
    fclose(archivo); 

    //ahora que ya tenemos el vector, lo pasamos a archivo

    archivo= fopen("peliculas.dat", "wb"); // lo vuelvo a abrir

    for(int i=0; i < lenA; i++){ //recorro el vector y lo paso al archvo
        fwrite(&vector[i], sizeof(pelicula),1,archivo);
    } 
    fclose(archivo);

    for(int i=0; i < 10; i++){ //recorro el vector B y lo paso en pantalla
        cout << vectorB[i].codigo << endl;
    }

    return 0;
}