#include <iostream>

using namespace std;

void agregar(Nodo *&cfte, Nodo *&cfin, int valor);
int suprimir(Nodo *&cfte, Nodo *&cfin);

struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){




    return 0;
}

void agregar(Nodo *&cfte, Nodo *&cfin, int valor){

    Nodo * nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = NULL;

    if(cfte == NULL){ //si esta vacia 
        cfte= nuevo;
    }else{
        cfin->sgte = nuevo;
    }
    cfin = nuevo;
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


