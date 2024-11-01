/*
programa que permita ingresar los datos de los trabajardores n en una estructura con los siguientes datos nombvre apellido paterno apellido materno sueldo

debe permitir el ingreso de n trabajadores, calcular el promnedio de sueldo de los trabajadores e indicar cuantos trabajadores reciben un sueldo sobbre el promedio
y cuantos reciben bajo el promedio
*/

#include<stdio.h>

#define MAXC 50

struct trabajador{
	char nombre[100];
	char apellido_paterno[MAXC];
	char apellido_materno[MAXC];
	int sueldo;
};

// ingresar datos de los trabajadores
void info_trabajador(struct trabajador t[],int n, int indice){
	
	
	printf("ingresando datos...\n");
	
	printf("\n  NOMBRE: ");
	scanf("%s",&t[indice].nombre);
	
		printf("\n  APELLIDO PATERNO: ");
	scanf("%s",&t[indice].apellido_paterno);
	
		printf("\n  APELLIDO MATERNO: ");
	scanf("%s",&t[indice].apellido_materno);
	
		printf("\n  SUELDO: ");
	scanf("%d",&t[indice].sueldo);
}


//promedio suieldo
void promedio_sueldo(struct trabajador t[],int n){ //total trabajadores = contador
	int i;
	/*
	if(total_trabajadores>n){
		printf("")
	}
	*/
	
	int suma=0;
	float promedio;
	for(i=0;i<n;i++){
		suma+=t[i].sueldo;
	}
	promedio = suma/n;
	printf("el promedio del sueldo es : %.f", promedio);
}

// sueldo sobre y bajo el promedio
void sueldo_sobreybajo(struct trabajador t[],int n){

int i;
int contador1=0;
int contador2=0;
int suma=0;
	float promedio;
	for(i=0;i<n;i++){
		suma+=t[i].sueldo;
	}
	promedio = suma/n;
	for(i=0;i<n;i++){
		
		if(promedio>t[i].sueldo){
		//	printf("\n el sueldo esta sobre el promedio");
			contador1++;
		}else{
			//printf("\n el sueldo esta bajo el promedio");
			contador2++;
		}
		
	}
	printf("\n la cantidad de sueldos sobre el promedio es: %d",contador1);
	printf("\n la cantidad de sueldos bajo el promedio es: %d",contador2);
}

int main(){
	int n,i;
	int contador =0;
	printf("\ningrese la cantidad de trabajadores: ");
	scanf("%d",&n);
	struct trabajador t[n];
	contador=0;
	for(i=0;i<n;i++){
	
	info_trabajador(t,n,contador);
	contador++;
}
	promedio_sueldo(t,n);
	sueldo_sobreybajo(t,n);
	return 0;
}























