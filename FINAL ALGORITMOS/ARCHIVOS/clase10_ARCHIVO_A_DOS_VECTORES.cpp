//UN ARCHIVO HACER DOS VECTORES

#include <iostream>

using namespace std;

struct alumno{
	
	int legajo;
	int nota1;
	int nota2; 
};

void insertarOrdenado(alumno vector[], int &len, alumno valor);
void insertar(alumno vec[], int &len, alumno valor, int pos);  

int main(){
	
	alumno vec1[10]; 
	alumno vec2[10]; 
	int len1=0; 
	int len2=0;
	
	FILE* archivo; 
	archivo = fopen("notas.dat", "rb");
	
	alumno raux;
	fread(&raux, sizeof(alumno),1,archivo); 
	
	while(!feof(archivo)){
		
	if(raux.nota1 <6  || raux.nota2 < 6){
			insertarOrdenado(vec1,len1,raux); 
		}
		else{
			insertarOrdenado(vec2,len2,raux);
		}
		
	fread(&raux, sizeof(alumno),1,archivo);
	}
	
	fclose(archivo); 
	
	for(int i=0; i<10;i++){
		cout << vec1[i].legajo << endl;
		cout << vec1[i].nota1 << endl;
		cout << vec1[i].nota2 << endl; 
	}
	
	for(int i=0;i<10;i++){
		cout << vec2[i].legajo << endl;
		cout << vec2[i].nota1 << endl;
		cout << vec2[i].nota2 << endl; 
	}
	
	return 0; 
}