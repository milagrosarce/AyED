#include <iostream>

using namespace std;

//dadas 2 LISTAS DE ENTEROS A Y B
//genere la UNION de ambas en lista C

struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){

    return 0;
}

void agregarPrimero(Nodo *&lista, int valor);


void unionListas(Nodo *&listaA, Nodo *&listaB, Nodo *&listaC){

    //tendria que hacer un while recorrido de la lista con un aux
    //y eliminar primero y agregar primero
    int valor;

    Nodo *auxA = listaA;
    while(auxA != NULL){
        valor = auxA->info;
        agregarPrimero(listaC, valor);
        auxA = auxA->sgte;
    }

    Nodo *auxB = listaB;
    while(auxB != NULL){ //recorremos c
        valor = auxB->info;
        agregarPrimero(listaC, valor);
        auxB = auxB->sgte;
    }

}

void unionList(Nodo *listaA, Nodo*listaB, Nodo *&listaC){

    while(listaA !=NULL){
        agregarPrimero(listaC, listaA->info);
        listaA = listaA->sgte;
    }

    while(listaB != NULL){
        agregarPrimero(listaC, listaA->info);
        listaB = listaB->sgte;
    }
}

void agregarPrimero(Nodo *&lista, int valor){

    Nodo* nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte=lista;
    lista=nuevo;
}

