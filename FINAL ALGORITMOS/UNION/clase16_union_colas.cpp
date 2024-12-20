#include <iostream>

using namespace std;

//dadas 2 COLAS, generar una nueva con la union de ambas 
//-----------------------------------DOS COLAS A UNA SOLA COLA----------------------------

//unir es digamos poner TODO lo de la A y TODO lo de la B, en la cola C

struct Nodo{
    int info;
    Nodo *sgte;
};

void unionColas(Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB, Nodo *&cfteC, Nodo *&cfinC); 
void agregar(Nodo *&cfte, Nodo *&cfin, int valor); //procedimiento predeterminado de una cola
int suprimir(Nodo *&cfte, Nodo *&cfin); //funcion predetermina de una cola 

int main(){

    return 0;
}

void unionColas(Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB, Nodo *&cfteC, Nodo *&cfinC){
    
    int valor;

    while(cfteA!=NULL){ //recorro toda la cola de A, saco y pongo en C 
        valor = suprimir(cfteA, cfinA);
        agregar(cfteC, cfinC, valor);
    }

    while(cfteB != NULL){ //recorro toda la cola de B, saco y pongo en C
        valor =suprimir(cfteB, cfinB);
        agregar(cfteC, cfinC, valor);
    }



}