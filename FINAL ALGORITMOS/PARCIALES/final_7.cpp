#include <iostream>

using namespace std;



int main(){

    return 0;
}

/*-----------------EJERCICIO 2------------------------------------------

una funcion que retorne una lista ordenada a partir de la union de 2 colas

*/

struct Nodo{
    int info;
    Nodo *sgte;
};

Nodo *unionDeDosColas(Nodo *cfteA , Nodo *cfinA, Nodo *cfteB, Nodo *cfinB){

    Nodo *lista =NULL;
    int valor;

    while(cfteA !=NULL){

        valor = suprimir(cfteA ,cfinA);
        insertarOrdenado(lista, valor);
    }

    while(cfteB !=NULL){
        valor = suprimir(cfteB, cfinB);
        insertarOrdenado(lista, valor);
    }

    return lista;
}

void generadorDeLista(Nodo *cfteA, Nodo *cfinA, Nodo *lista){

    Nodo * listaA = NULL;

    int valor;

    Nodo *aux = lista;

    while(cfteA !=NULL){
        valor = suprimir(cfteA, cfinA);
        aux = lista;
        while(aux !=NULL){

            if(valor == aux->info){
                insertarOrdenado(listaA, valor);
            }

        aux = aux->sgte;
        }
    }
}

/*------------------------EJERCICIO 3--------------------------------------

Dado un vector de Ballotage que indica los votos en la Argentina por provincia (23 y la CABA) para 
presidente. El vector contiene el codigo de la provincia, codigo de partido politico(A y B) y la cantidad de votos.
Se sabe que el vector muestra por cada provincia y por cada partido los siguientes resultado:

*/

/*
--------------------------------EJERCICIO 4------------------------------------------

Se tiene un vector de Reservas de cabañas de la Patagonia, en las que se aplico un beneficio para turistas
argentinos con los siguientes campos:
-codigo de la cabaña
-cantidad de reservas de turistas argentinos
-cantidad de huespedes
-monto abonado 

Ademas, se cuenta con una lista ordenada que contiene las ultimas reservas realizadas, cada nodo de la lista contiene:
-codigo de la cabaña
-aplica beneficios de turismo S o N
-cantidad de huespedes
-monto abonado 

Se pide actualizar el vector de RESERVAS con la informacion que hay en la lista. Por cada reserva en la que si 
haya aplicado el beneficio, debe actualizar la cantidad de huespedes en el vector, incrementar en 1 la cant de 
reservas y acumular el monto abonado. Se sabe que como maximo hay 100 cabañas
*/

struct datosVector{
    int codigo_cabaña;
    int cant_reservas_argentinos;
    int cant_huespedes;
    int monto;
};

struct datosLista{
    int codigo_cabaña;
    char aplica;
    int cant_huespedes;
    int monto;
};

struct Nodo{
    datosLista info;
    Nodo *sgte;
};

void actualizarReservas(datosVector reservas[], int len, Nodo *lista){

    Nodo *aux= lista;
    while(aux !=NULL){

        for(int i=0;i<len;i++){
            if(aux->info.codigo_cabaña == reservas[i].codigo_cabaña && aux->info.aplica == 'S'){
                reservas[i].cant_huespedes += aux->info.cant_huespedes;
                reservas[i].cant_reservas_argentinos++;
                reservas[i].monto += aux->info.monto;
            }
        }
        aux = aux->sgte;
    }
}

/*--------------------------------------EJERCICIO 5-----------------------------------------

Se tiene un archivo de disponibilidad de pasajes en tren viajes2024.dat (sin orden)
-id del tramo
-tipo de reserva: P E S 
-precio

Se pide:
a) ordenar el archivo viaje2024.dat por el ID del tramo
b) armar una lista y mostrarla por pantalla, ordenada por precio, si el tipo de reserva es P o E y 
el precio supera los 2500. Solo puede leer 1 vez el archivo

*/

struct dato{
    int id;
    char tipo;
    int precio;
};

struct Nodo{
    dato info;
    Nodo *sgte;
};

int main(){

    FILE* archivo;
    archivo = fopen("viajes2024.dat", "rb");
    Nodo *lista = NULL;
    Nodo *listaA = NULL;

    dato raux;
    fread(&raux, sizeof(dato), 1, archivo);

    while (!feof(archivo)){

        insertarOrdenado(lista, raux);

        if(raux.tipo == 'P' && raux.tipo == 'E' && raux.precio >= 2500){
            insertarOrdenado(listaA, raux);
        }

        fread(&raux,sizeof(dato), 1, archivo);
    }
    fclose(archivo);

    archivo = fopen("viajes2024.dat", "wb");

    while(lista !=NULL){

        fwrite(&lista->info, sizeof(dato), 1, archivo);
        lista = lista->sgte;
    }
    fclose(archivo);

    Nodo *auxa=listaA;

    while(auxa !=NULL){
        cout << auxa->info.id << endl;
        auxa= auxa->sgte;
    }

    return 0; 
}

void insertarOrdenado(Nodo *&lista, dato valor){

    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = NULL;

    Nodo *aux= lista;
    Nodo *ant = NULL;

    while(aux!=NULL && aux->info.id < valor.id){
        ant= aux;
        aux=aux->sgte;
    }

    if(aux==NULL){
        nuevo->sgte = lista;
        lista = nuevo;
    }else{
        ant->sgte= nuevo;
        nuevo->sgte= aux;
    }

}

//b) armar una lista y mostrarla por pantalla, ordenada por precio 