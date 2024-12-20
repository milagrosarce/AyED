//Dado un archivo llamado notas.dat hacer un archivo para los aprobados y otro para los desaprobados 

#include <iostream>

using namespace std;

struct Alumno{
	int legajo;
	int nota1;
	int nota2; 
};

int main(){
	 
	FILE* archivo; //archivo principal 
	FILE* aprobados; //archivo 1 
	FILE* desaprobados; //archivo 2 
	
	archivo= fopen("notas.dat", "rb");
	aprobados= fopen("notas.dat", "wb"); 
	desaprobados= fopen("notas.dat", "wb"); 
	
	Alumno raux; 
	fread(&raux, sizeof(Alumno),1,archivo); 
	
	while(!feof(archivo)){
		
		if(raux.nota1 <6 || raux.nota2 < 6){
			fwrite(&raux, sizeof(Alumno),1,desaprobados); 
		}
		else{
			fwrite(&raux, sizeof(Alumno),1,aprobados); 
		}
		
	    fread(&raux, sizeof(Alumno),1,archivo); 
	}

	fclose(archivo); 
	fclose(aprobados);
	fclose(desaprobados); 
	
	return 0; 
}
