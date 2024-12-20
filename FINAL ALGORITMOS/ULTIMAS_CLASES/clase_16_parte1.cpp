#include <iostream>

using namespace std;

//dado un archivo de entero, ordenarlos 

struct Nodo{
    int info;
    Nodo *sgte;
};

void liberar(Nodo *&lista); 
void insertarOrdenado(Nodo *&lista, int valor); 

int main(){

    FILE *archivo;
    archivo = fopen("archivito.dat", "rb");

    int raux; 
    fread(&raux, sizeof(int), 1, archivo);

    Nodo *lista= NULL; 

    while(!feof(archivo)){

        insertarOrdenado(lista, raux);

        fread(&raux, sizeof(int), 1, archivo);
    }
    fclose(archivo); 

    //hasta aca digamos que ordene mi archivo en una lista
    //ahora tengo que pasar mi lista al archivo nuevamente

    archivo = fopen("archivito.dat", "wb");
    
    Nodo *aux=lista;
    while(aux != NULL){
        fwrite(&aux->info, sizeof(int), 1, archivo);
        aux=aux->sgte; 
    }
    fclose(archivo); 

    liberar(lista); 

    return 0;
}

void insertarOrdenado(Nodo *&lista, int valor){

//-------------------CREAMOS EL NODO--------------------------
    Nodo *nuevo = new Nodo();
    nuevo->info=valor;
    nuevo->sgte= NULL;

//-----------------CREAMOS LOS PUNTEROS-----------------
    Nodo *aux=lista;
    Nodo *ant=NULL;

//----------------CAMINAMOS SOBRE LA LISTA---------------------
    while(aux!=NULL && aux->info < valor){
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