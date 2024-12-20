#include <iostream>

using namespace std;

struct alumno{
	int legajo;
	int nota1;
	int nota2;
};

//COMO PASAR UN ARCHIVO A UN VECTOR 

void insertarOrdenado(alumno vector[], int &len, alumno valor);
void insertar(alumno vec[], int &len, alumno valor, int pos); 
void inicializar(alumno vector[], int len, alumno valor);

int main(){
	
	//----------------------------VECTOR---------------------------
	alumno vector[10]; 
	int len=0;                           //DECLARE EL VECTOR
	
    alumno valor;
    valor.nota1;
    valor.legajo;
    valor.nota2;

    inicializar(vector, 10, valor); 

	//------------------------ARCHIVO-----------------------------------

	FILE* archivo;                       

	archivo= fopen("datos.dat", "rb");  
	
	alumno raux;  
	fread(&raux,sizeof(alumno),1,archivo); 

	//--------------------LEO EL ARCHIVO Y LO PASO A VECTOR------------------

	while(!feof(archivo)){     //ACA LEELO EL ARCHIVO Y A MEDIDA QUE SE VA LEYENDO EL PROCEDIMIENTO DE INSERTARORDENADO VA A PASARLO A UN VECTOR DESDE EL RAUX 
		
		insertarOrdenado(vector,len,raux); 
		
		fread(&raux,sizeof(alumno),1,archivo); 
	}
	fclose(archivo); 
	
	//HASTA ESTE MOMENTO TENGO EN UN VECTOR YA TODOS LOS VALORES SACADOS DEL ARCHIVO CON AYUDA DEL RAUX QUE ES FUNDAMENTAL 
	
	//----------------------------DE VECTOR A ARCHIVO OTRA VEZ---------------------------------------

	archivo=fopen("datos.dat", "wb");  //ABRO OTRA VEZ EL ARCHIVO PARA CAMBIAR SUS VALORES
	
	for(int i=0;i<10;i++){                            //ACA LO QUE ESTOY HACIENDO ES PASAR UN VECTOR A UN ARCHIVO 
		fwrite(&vector[i],sizeof(alumno),1,archivo); 
	}
	fclose(archivo); 
	
	
	return 0; 
}


//PARA AGREGAR UN VALOR ORDENADO A UN VECTOR ORDENADO DE MENOR A MAYOR
void insertarOrdenado(int vector[], int &len, int valor){
	

 //1 donde voy a cargar el valor
 int i=0; 
 while(i<len && vector[i]<= valor){
 	i++;	
 }
 
 //2 CARGAR EL VALOR
 if(i==len){ //si llegue al final
 	vector[len]= valor;
 	len++; 
 }else insertar(vector, len, valor, i); 
}

void insertar(int vec[], int &len, int valor, int pos){

    for(int i=len; i>pos; i--){ //quiero hacer que bajen los valores
        vec[i] = vec[i-1];
    }
    vec[pos] = valor; //una vez que ya llegue a donde queria
    len++; //aumento el largo
}
