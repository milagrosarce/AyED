#include <iostream>

using namespace std;

/* Se tiene un archivo de disponibilidad para las habitaciones de un hotel en la costa Verano2021.dat (sin orden):
- Numero de habitacion : 999999
- Tipo: "S", "D", "T" o "C" (single, doble, triple, cuadruple)
- Dias disponibles de la temporada: 999
- Precio por dia de la habitacion: 999 
- Se pide:
a) Ordenar el archivo Verano2021.dat por precio de habitacion...
b) Armar una lista, ordenada por Numero de habitacion, y mostrarla por pantalla si el numero de dias
disponibles es menor a 50 y son habitaciones singles o dobles.
*/

struct dato{
    int numero;
    char tipo; //S D T C
    int dia;
    int precio; 
}; 

struct Nodo{
    dato info;
    Nodo *sgte;
}; 

void insertarOrdenadoA(Nodo *&lista, dato valor);
void insertarOrdenadoB(Nodo *&lista, dato valor);
void liberar(Nodo *&lista); 

int main(){

    FILE *archivo;
    archivo = fopen("Verano2021.dat", "rb");

    dato raux;

    fread(&raux, sizeof(dato), 1, archivo);

    Nodo *lista = NULL;
    Nodo *listaB = NULL; 

    while(!feof(archivo)){

        insertarOrdenadoA(lista, raux); //armo una lista para el A

        if((raux.dia < 50 && raux.tipo == 'S') && (raux.dia < 50 && raux.tipo == 'D')){
            insertarOrdenadoB(listaB, raux);  //armo una lista para el B si cumple todas esas condiciones 
        }
        
        fread(&raux, sizeof(dato), 1, archivo);
    }
    fclose(archivo);

    //hasta aca ordene todo a una lista

    archivo = fopen("Verano2021.dat", "wb");
    Nodo* aux= lista;
    while(aux!=NULL){ //recorro la lista y voy agregando al archivo
        fwrite(&aux->info, sizeof(dato), 1, archivo);
        aux = aux->sgte;
    }
    fclose(archivo);
    //mostrar(listaB);
    liberar(lista);

    return 0; 
}



void insertarOrdenadoA(Nodo *&lista, dato valor){

//-------------------CREAMOS EL NODO--------------------------
    Nodo *nuevo = new Nodo();
    nuevo->info=valor;
    nuevo->sgte= NULL;

//-----------------CREAMOS LOS PUNTEROS-----------------
    Nodo *aux=lista;
    Nodo *ant=NULL;

//----------------CAMINAMOS SOBRE LA LISTA---------------------
    while(aux!=NULL && aux->info.precio < valor.precio){
        ant=aux;
        aux=aux->sgte;
    }

//-----------------------ENLAZARLO-----------------------------
    if(ant==NULL){ //si entra a la lista como primer nodo 
        lista = nuevo;
        nuevo->sgte = lista;
    }else{ //si hay que buscarle un lugar, 
        ant->sgte = nuevo;
        nuevo->sgte = aux; 
    }
}

void insertarOrdenadoB(Nodo *&lista, dato valor){

//-------------------CREAMOS EL NODO--------------------------
    Nodo *nuevo = new Nodo();
    nuevo->info=valor;
    nuevo->sgte= NULL;

//-----------------CREAMOS LOS PUNTEROS-----------------
    Nodo *aux=lista;
    Nodo *ant=NULL;

//----------------CAMINAMOS SOBRE LA LISTA---------------------
    while(aux!=NULL && aux->info.numero < valor.numero){
        ant=aux;
        aux=aux->sgte;
    }

//-----------------------ENLAZARLO-----------------------------
    if(ant==NULL){ //si entra a la lista como primer nodo 
        lista = nuevo;
        nuevo->sgte = lista;
    }else{ //si hay que buscarle un lugar, 
        ant->sgte = nuevo;
        nuevo->sgte = aux; 
    }
}


void liberar(Nodo *&lista){

    Nodo *aux;

    while(lista!=NULL){
        aux=lista;
        lista=lista->sgte;
        delete(aux); 
     }
}