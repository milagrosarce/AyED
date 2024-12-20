#include <iostream>

using namespace std;


int main(){

    return 0;
}

/*-----------------------EJERCICIO 1--------------------------

Desarrolle los siguientes subprogramas:

a)-Una funcion que retorna una lista ordenada de la union de una pila y una cola.

b)-Un procedimiento que genere una lista sin orden de la interseccion de 2 listas. 

*/

struct Nodo{
    int info;
    Nodo *sgte;
};

Nodo *unionPilaCola(Nodo* cfte, Nodo*cfin, Nodo *pila){

    int valor;
    Nodo * lista = NULL;

    while(cfte !=NULL){
        valor = suprimir(cfte,cfin);
        insertarOrdenado(lista, valor);
    }

    while(pila!=NULL){
        valor = pop(pila);
        insertarOrdenado(lista, valor); 
    }
}

void interseccionDe2Listas(Nodo *listaA, Nodo *listaB, Nodo*&listaC){

    Nodo *auxB = listaB; 
    while(listaA !=NULL){
        auxB = listaB; //reinicio el aux de B 
        while(auxB !=NULL){ //recorro la lista b 
            if(listaA->info == auxB->info){ //hasta que encuentre el valor
                int valor = listaA->info;
                insertar(listaC, valor); 
            }
        auxB= auxB->sgte;
        }
    listaA = listaA->sgte;
    }
}

/* ----------------------------EJERCICIO 2-----------------------------------

Se tiene un vector de Reservas de los hoteles de Pinamar para el verano 2024, que contiene el detalle
de las reservas de cada hotel con los siguientes campos:
-Codigo de hotel
-Cantidad de reservas
-Cantidad de dias disponibles en la temporada
 
Ademas, se cuenta con una lista ordenada que contiene las ultimas reservas realizadas por un sitio web de
viajes, cada nodo de la lista contiene:
-Codigo de hotel
-Cantidad de dias reservados

Se pide, actualizar el vector de Reservas con la informacion que hay en la lista, incrementando la cantidad
de reservas por cada una que aparezca en la lista, como asi actualizando la cantidad de dias disponibles en base
a los dias reservados. 
Ejemplo: si en la lista el hotel 23 tiene 2 dias reservados, esos 2 dias se deben restar en el campo de Cantidad 
de dias disponibles del Vector. Se sabe que como Maximo hay 50 hoteles.

*/

struct datosVector{
    int codigo;
    int cant_reservas;
    int dias_disponibles;
};

struct datosLista{
    int codigo;
    int dias_reservados;
};

struct Nodo{
    datosLista info;
    Nodo *sgte;
};

int main(){

    datosVector vector[50];
    Nodo* lista; 

    Nodo *aux=lista;
    while(aux !=NULL){

        for(int i=0; i < 50; i++){
            if(aux->info.codigo == vector[i].codigo){
                vector[i].cant_reservas += 1; //incremento la cantidad de reservas 
                vector[i].dias_disponibles = vector[i].dias_disponibles - aux->info.dias_reservados; //actualizo vector de dias disponibles reservando los que ya se reservaron
            }
        }
        aux = aux->sgte;
    }
}

//-------------------------------------EJERCICIO 3----------------------------------------------

/*
Se tiene un archivo de registros de bultos de productos almacenados en un deposito, con el nombre 
STOCK.dat (sin orden), que posee el siguiente formato:

-Codigo de producto:
-Peso por bulto:
-Tipo: A or B
-Cantidad de bultos en stock: 

se pide:

a)- Ordenar el archivo STOCK.dat por codigo de producto
b)- Generar dos listas y mostrarlas por pantalla:

a- La primera con los productos que NO TIENEN UNIDADES EN STOCK
b- La segunda con los productos PESADOS (peso mayor a 100) y Bebidas (B). 

*/

struct datos{
    int codigo;
    int peso;
    char tipo;
    int cant;
};

struct Nodo{
    datos info;
    Nodo *sgte;
}; 

//Ordenar el archivo stock.dat por codigo de producto 
void insertarOrdenado(Nodo *&lista, datos valor);

int main(){

    FILE *archivo;
    archivo = fopen("stock.dat", "rb");

    datos raux;
    fread(&raux, sizeof(datos), 1, archivo);

    Nodo *aux=NULL;
    Nodo *listaA = NULL;
    Nodo *listaB = NULL;

    while(!feof(archivo)){ //a medida que leo el archivo 

        insertarOrdenado(aux, raux); //paso el archivo a una lista 

        if(raux.cant == 0){
            insertarOrdenado(listaA, raux); //LA PRIMERA CON LOS PRODUCTOS QUE NO TIENEN UNIDADES EN STOCK
        }

        if(raux.peso >= 100 && raux.tipo == 'B'){
            insertarOrdenado(listaB, raux);
        }

        fread(&raux, sizeof(datos), 1, archivo); 
    }
    fclose(archivo);

    archivo = fopen("stock.dat", "wb");

    while(aux!=NULL){
        fwrite(&aux->info, sizeof(datos), 1, archivo);
        aux = aux->sgte;
    }
    fclose(archivo);

    return 0;
}


void insertarOrdenado(Nodo *&lista, datos valor){

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


//generar dos listas y mostrarlas por pantalla:

//a. La primera con los productos que no tienen unidades en stock. 

