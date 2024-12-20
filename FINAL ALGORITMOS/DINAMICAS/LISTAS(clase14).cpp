#include <iostream>

using namespace std;

//-----------------------------------------LISTAS----------------------------------------------

struct Nodo{
    int info;
    Nodo *sgte;
};

void agregarPrimero(Nodo *&lista, int valor);
int eliminarPrimero(Nodo *&lista);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista); 

void insertarOrdenado(Nodo *&lista, int valor);
Nodo *buscar(Nodo *lista, int valor); 
void buscarYMostrar(Nodo *lista, int valor);

int main(){

    Nodo* lista=NULL;  //defini la lista

    return 0;
}

void agregarPrimero(Nodo *&lista, int valor){ //agrego al principio de la lista

    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = lista;
    lista = nuevo; 
}

int eliminarPrimero(Nodo *&lista){ //eliminarPrimero 

    int retorno;  //variable de retorno 
    retorno = lista->info; //la lleno con lo que tengo que devolver
    
    Nodo *aux = lista; //armo una flecha que apunte igual hacia adonde apunta lista el puntero principal 
    lista = aux->sgte;  

    delete(aux);
    return retorno;
}

void mostrar(Nodo *lista){

    //recorrer la lista e ir mostrando los nodos

    Nodo *aux= lista;

    while(aux != NULL){
        cout << aux->info << endl;
        aux = aux->sgte; //para ir recorriendo 
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

Nodo *buscar(Nodo *lista, int valor){
    Nodo *aux=lista;

    while(aux!=NULL && aux->info != valor){
        aux = aux->sgte;
    } 

    return aux; //cuando salga de ese bucle de while listo voy a quedarme con ese aux
}

void buscarYMostrar(Nodo *lista, int valor){

    Nodo* aux= lista; 

    while(aux != NULL && aux->info != valor){
        aux = aux->sgte;
    }

    if(aux == NULL){
        cout << "No esta" << endl;
    }else{
        cout << aux->info << endl;
    }
}

