#include <iostream>

using namespace std;

//UNION DE UNA COLA Y UNA PILA A LA LISTA

struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){

    return 0; 
}

void unirColaYPilaALista(Nodo *cfte, Nodo *cfin, Nodo *pila, Nodo *&lista){

    int valor;

    while(cfte!=NULL){
        valor = suprimir(cfte,cfin);
        agregarPrimero(lista, valor);
    }

    while(pila!=NULL){
        valor = pop(pila);
        agregarPrimero(lista, valor);
    }
}



int suprimir(Nodo *&cfte, Nodo *&cfin){

    int ret;
    ret = cfte->info;

    Nodo *aux=cfte;
    cfte=aux->sgte;

    if(cfte==NULL){
        cfin = NULL;
    }
    delete(aux);
    return ret;
}

void agregarPrimero(Nodo *&lista, int valor){ //agrego al principio de la lista

    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = lista;
    lista = nuevo; 
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

int pop(Nodo *&pila){

    //guardar el valor re retorno 
    int retorno;
    retorno=pila->info;

    Nodo *aux=pila;
    pila = aux->sgte; //pila = pila->sgte; 

    delete(aux);

    return retorno;
}