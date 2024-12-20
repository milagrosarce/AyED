#include <iostream>

using namespace std;

//dadas 2 colas, generar una pila con la union de ambas

int suprimir(Nodo *&cfte, Nodo *&cfin);
void push(Nodo *&pila, int valor);

struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){

    return 0; 
}

//------------------------------------DOS COLAS A UNA PILA------------------------------------------

void unionColasAPilas(Nodo *cfteA, Nodo *cfinA,Nodo *cfteB, Nodo *cfinB, Nodo *&pila){
    
    int valor;

    while(cfteA!=NULL){
        valor = suprimir(cfteA, cfinA);
        push(pila, valor);
    }

    while(cfteB!=NULL){
        valor = suprimir(cfteB, cfinB);
        push(pila, valor);
    }

}













void push(Nodo *&pila, int valor){

    Nodo *nuevo = new Nodo(); //creamos digamos el bloquecito
    nuevo->info = valor; //cargamos el bloquecito
    nuevo->sgte = pila; //hacemos que apunte al que antes tenia pila 
    pila = nuevo; //y ahora hacmemos que el puntero "principal" apunte a este que recien lelgo 
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