#include <iostream>

using namespace std;
//dado un archivo de registro [codigo, tipo] genere 2 archivos ordenados (segun el tipo de producto A o B)
//por codigo de producto 

struct dato{
    int codigo;
    char tipo; // A o B 
};

struct Nodo{
    dato info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, dato valor);

int main(){

    FILE *archivo;
    archivo = fopen("archivoPrincipal.dat", "rb");

    FILE *archivoA;
    FILE *archivoB;

    Nodo *listaA = NULL;
    Nodo *listaB = NULL;

    dato raux;
    fread(&raux, sizeof(dato), 1, archivo);

    while(!feof(archivo)){

        if(raux.tipo == 'A'){
            insertarOrdenado(listaA, raux); 
        }else if(raux.tipo == 'B'){
            insertarOrdenado(listaB, raux);
        }

        fread(&raux, sizeof(dato), 1, archivo);
    }
    fclose(archivo);

    //bien hasta aca cree dos listas ordenada una para A y otra para B 

    archivoA = fopen("archivoA.dat", "wb");
    archivoB = fopen("archivoB.dat", "wb");

    Nodo *auxA = listaA;
    while(auxA != NULL){
        fwrite(&auxA->info, sizeof(dato), 1, archivoA);
        auxA = auxA->sgte;
    }
    fclose(archivoA);
    liberar(listaA);

    Nodo *auxB = listaB;
    while(auxB != NULL){
        fwrite(&auxB->info, sizeof(dato), 1, archivoB);
        auxB = auxB->sgte;
    }
    fclose(archivoB);
    liberar(listaB);

    return 0;
}

void insertarOrdenado(Nodo *&lista, dato valor){

//-------------------CREAMOS EL NODO--------------------------
    Nodo *nuevo = new Nodo();
    nuevo->info=valor;
    nuevo->sgte= NULL;

//-----------------CREAMOS LOS PUNTEROS-----------------
    Nodo *aux=lista;
    Nodo *ant=NULL;

//----------------CAMINAMOS SOBRE LA LISTA---------------------
    while(aux!=NULL && aux->info.codigo < valor.codigo){
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