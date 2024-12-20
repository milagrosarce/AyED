#include <iostream>
//--------------------CORTE DE CONTROL--------------------------------
using namespace std;

struct multa{
    int dominio;
    int tipo;
    int importe;
};

int main(){

    FILE* archivo;
    archivo=fopen("archivito.dat", "rb");

    multa raux;
    int anterior; //va a ser la "clave" que se repite digamos 
    int sumaMultas; //el contador 

    fread(&raux, sizeof(multa), 1, archivo); //leo el archivo 

    while(!feof(archivo)){ //lo mantengo abierto 
        anterior=raux.dominio; //lo asocio al dominio 
        sumaMultas=0; 

        while((!feof(archivo)) && anterior==raux.dominio){ //mientras la clave sea la misma entonces sigo sumando

            sumaMultas = sumaMultas + raux.importe; //es un simple contador 
            fread(&raux, sizeof(multa),1,archivo); //voy a tener que seguir leyendolo 
        }

        cout << "Dominio:" << anterior << "tiene un total de multad de: " << sumaMultas << endl;
    }

    fclose(archivo); 

    return 0; 
}



int main(){

    FILE *archivo;
    archivo = fopen();
    multa raux;

    fread(&raux, sizeof(multa), 1, archivo);
    int anterior;
    int suma;

    while(!feof(archivo)){
        anterior = raux.dominio;
        suma = 0;

        while(!feof(archivo) && raux.dominio == anterior){

            suma += raux.importe;

            fread(&raux, sizeof(multa), 1, archivo);
        }

        

    }
}