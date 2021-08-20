#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 12
typedef float tDiscos[MAX];
typedef struct {
    tDiscos listaDiscos;
    int tope;
}tPilaDiscos;
bool pilaVacia( tPilaDiscos );
bool pilaLlena( tPilaDiscos );
float cima( tPilaDiscos );
float sumaDiscos( tPilaDiscos );
float promedio(tPilaDiscos);
int cantidadDiscos ( tPilaDiscos );
void crearPilaVacia();
void ingresarPeso();
void apilarDisco( float );
void desapilarDisco();
void visualizarUltimoDisco  (tPilaDiscos);
void mostrarPromedio( tPilaDiscos );
void visualizarElementosApilados( tPilaDiscos );
void verCantidadDeDiscos();
void menu();
tPilaDiscos pilaDiscos;


int main() {
    system("color b2"); /* Funcion para colores :D*/ 
    setlocale(LC_ALL, "spanish");/* Funcion para escribir caracteres del taclado español */ 
    crearPilaVacia();
    menu();
    return 0;
}

void menu() {
    int opcion;
    printf("****************GIMNASIO GUERREROS****************");
    printf("\n|Seleccione una opcion por favor|\n\n1-Colocar Discos\n2-Quitar ultimo disco\n3-Ver discos en el gimnasio\n4-Visualizar ultimo disco\n5-Ver cantidad de discos\n6-Mostrar promedio de peso en el gimnasio\n7-Salir\n ");
    printf("\n|Seleccione una opcion por favor|\n");
    opcion = getch();
    printf("\nOpciones\n1-Volver al menu\n2-Salir\n ");
    system("cls");
    switch ( opcion )
    {
        case 49: ingresarPeso();
   	            break;
        case 50: desapilarDisco();
                break;
        case 51: visualizarElementosApilados( pilaDiscos );
                break;
        case 52: visualizarUltimoDisco( pilaDiscos );
                break;  
        case 53: verCantidadDeDiscos();
                break;       
		case 54: mostrarPromedio( pilaDiscos );
                break;              
        case 55: printf("-HASTA LA PROXIMA-"); return ;
        break;
    }
    opcion=0;
    printf("\nOpciones\n1-Volver al menu\n2-Salir\n ");
    printf("\n|Seleccione una opcion por favor|\n");
    opcion = getch();
    system("cls");
    switch ( opcion ){
   
   		case 49: 
				menu();
                break;
        case 50: printf("----------HASTA LA PROXIMA----------"); return;
                break;}
}

void crearPilaVacia() {
	/* Crea pila vacia */ 
    pilaDiscos.tope = -1;
}

void ingresarPeso(){
	/* completar!!! solicitar al usuario */  
	float peso = 0;
	printf("Ingrese peso del disco en Kg:\n");
				scanf("%f" , &peso) ;
				if (peso>9&&peso<101){
			    apilarDisco( peso );}
			    else{
         printf("---------->Peso ingresado inexistente<----------\n");
         printf("\n|Seleccione una opcion por favor|\n");
   				 }
}

bool pilaVacia( tPilaDiscos pPila ) {   
    return ( pPila.tope == -1 ) ;  
}

bool pilaLlena( tPilaDiscos pPila ) {
    return ( pPila.tope == MAX-1 );
}

void apilarDisco( float pElemento ) {
	/* Si no esta llena la pila, agrega el elemento*/ 
    if ( !pilaLlena( pilaDiscos ) ) {
        pilaDiscos.tope = pilaDiscos.tope + 1;
        pilaDiscos.listaDiscos[pilaDiscos.tope] = pElemento;
        system("cls");
        printf("---------->Disco apilado<----------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    } else {
        printf("---------->No hay lugar para mas discos en el gimnasio<----------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }
}

void desapilarDisco() {
    /* Si la pila no esta vacia, puedo eliminar el elemento, y baja el tope */
    if( !pilaVacia( pilaDiscos ) ) {
        pilaDiscos.listaDiscos[pilaDiscos.tope] = 0;
        pilaDiscos.tope = pilaDiscos.tope - 1;
       
        printf("---------->Ultimo disco eliminado<----------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    } else {
        printf("---------->No hay discos por eliminar en el gimnasio<----------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }
}

float cima( tPilaDiscos pPila ) {
	/* regresa el valor de la cima de la pila */ 
    return pPila.listaDiscos[pilaDiscos.tope];
}

int cantidadDiscos( tPilaDiscos pPila )
/* Cuenta la cantidad de elementos en la pila*/ 
 {
return pPila.tope + 1;
}

float sumaDiscos( tPilaDiscos pPila ) 
/* Suma el total de cada elemento de la pila */ 
{
	float discosSuma = 0;
	int i;
	for ( i=0; i <= pPila.tope; i++) {
            discosSuma= discosSuma + pPila.listaDiscos[i];
        }
    return discosSuma;
}

float promedio(tPilaDiscos pPila)
/* Calcula el prmedio de la pila y devuelve resultado */ 
 {
    return (float) (sumaDiscos(pPila) /cantidadDiscos(pPila));
}

void mostrarPromedio( tPilaDiscos pPila )
/* Muestra el promedio de la pila */ 
{
	if( !pilaVacia( pPila) ) {

        printf("El promedio de peso en total es\n");
         printf("----------------------------------------------------------------------\n");

            printf("---------->%.2fKg<----------", promedio( pilaDiscos ));
        
        printf("\n----------------------------------------------------------------------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }else {
         printf("---------->No hay discos en el gimnasio<----------\n");
         printf("\n|Seleccione una opcion por favor|\n");
    }      
}


void visualizarUltimoDisco  (tPilaDiscos pPila)
/* Muestra el contenido de cima, osea el ultimo elemento */ 
{
	if( !pilaVacia( pPila) ) {
        printf("Ultimo disco ingresado\n");
         printf("----------------------------------------------------------------------\n");
        
            printf("---------->%.2fKg<----------", cima( pilaDiscos ));
        
        printf("\n----------------------------------------------------------------------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }else {
         printf("---------->No hay discos en el gimnasio<----------\n");
         printf("\n|Seleccione una opcion por favor|\n");
    }      
}
	
void visualizarElementosApilados( tPilaDiscos pPila )
/* Visualiza el contenido de todos los elementos de la pila */ 
 {
    int i;
    if( !pilaVacia( pPila) ) {
        printf("Discos en el gimnasio: \n");
         printf("----------------------------------------------------------------------\n");
        for ( i=0; i <= pPila.tope; i++) {
            printf("%.2fKg | ", pPila.listaDiscos[i]);
        }
        printf("\n----------------------------------------------------------------------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }else {
         printf("---------->No hay discos en el gimnasio<----------\n");
         printf("\n|Seleccione una opcion por favor|\n");
    }      
}

void verCantidadDeDiscos(){
	printf("----------------------------------------------------------------------\n");
		printf("La cantidad de discos son: %i\n\n", cantidadDiscos( pilaDiscos ));
	printf("----------------------------------------------------------------------\n");
        printf("\n|Seleccione una opcion por favor|\n");
}

