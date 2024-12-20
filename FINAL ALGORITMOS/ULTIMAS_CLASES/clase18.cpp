#include <iostream>

using namespace std;

//dado 2 vectores enteros, (A[10]) y (B[10])
//generar la UNION de ambos en C[20]

int main(){

    int A[10];
    int B[10];
    int C[20];


    for(int i=0; i<10; i++){
        C[i]=A[i];
    }

    for(int i=0; i<10;i++){
        C[i+10]=B[i];
    }

    return 0;
}

//Dadas 2 colas de enteros(Cola A y Cola B) genere la UNION
//de ambas en Cola C. 

struct Nodo{
    int info;
    Nodo *sgte;
};

void unionColas(Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB, Nodo *&cfteC, Nodo *&cfinC); 
void agregar(Nodo *&cfte, Nodo *&cfin, int valor); //procedimiento predeterminado de una cola
int suprimir(Nodo *&cfte, Nodo *&cfin); //funcion predetermina de una cola 

void UnionColas(Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB, Nodo *&cfteC, Nodo *&cfinC){

    int valor;

    while(cfteA != NULL){
        valor = suprimir(cfteA, cfinA);
        agregar(cfteC, cfinC, valor);
    }

    while(cfteB != NULL){
        valor = suprimir(cfteB, cfinB);
        agregar(cfteC, cfinC, valor);
    }
}

