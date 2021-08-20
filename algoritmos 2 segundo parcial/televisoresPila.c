#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 20
typedef float tTeles[MAX];
typedef struct {
    tTeles listaTeles;
    int tope;
}tPilaTeles;

bool pilaVacia( tPilaTeles );
bool pilaLlena( tPilaTeles );
int cantidadTeles ( tPilaTeles );
float maximaPulgada = 100;
float cima( tPilaTeles );
void crearPilaVacia();
void ingresarPulgada();
void apilarTeles( float );
void desapilarTelesYMostrarUltimo(  );
void visualizarTelevisoresApilados( tPilaTeles );
void visualizarTelevisoresXPulgada( tPilaTeles );
void menu();
tPilaTeles pilaTeles;


int main() {
    system("color b2"); /* Funcion para colores :D*/ 
    setlocale(LC_ALL, "spanish");/* Funcion para leer normalmente caracteres del taclado español */ 
    crearPilaVacia();
    menu();
    return 0;
}

void menu() {
    int opcion;
    printf("****************Fabrica de televisores SANYO****************");
    printf("\n|Seleccione una opcion por favor|\n\n1-Colocar Televisor\n2-Quitar ultimo Televisor\n3-Ver todos los televisores\n4-Busqueda avanzada\n5-Salir\n ");
    printf("\n|Seleccione una opcion por favor|\n");
    opcion = getch();
    system("cls");
    switch ( opcion )
    {
        case 49: ingresarPulgada();
   	            break;
        case 50: desapilarTelesYMostrarUltimo(  );
                break;
        case 51: visualizarTelevisoresApilados( pilaTeles );
                break;
        case 52: visualizarTelevisoresXPulgada( pilaTeles );
                break;              
        case 53: printf("-HASTA LA PROXIMA-"); return ;
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
    pilaTeles.tope = -1;
}

void ingresarPulgada(){
	/* completar!!! solicitar al usuario */  
	float pulgada = 0;
	printf("Ingrese el tamaño del televisor en pulgadas:\n");
				scanf("%f" , &pulgada) ;
				system("cls");
			    apilarTeles( pulgada  );
         printf("|Seleccione una opcion por favor|\n");
}


bool pilaVacia( tPilaTeles pPila ) {   
    return ( pPila.tope == -1 ) ;  
}


bool pilaLlena( tPilaTeles pPila ) {
    return ( pPila.tope == MAX-1 );
}


void apilarTeles( float pElemento) {
	
	/* Si no esta llena la pila, agrega el elemento(MIENTRAS ESTE NO SEA MAYOR AL ANTERIOR))*/ 
    if ( !pilaLlena( pilaTeles ) ) {if (pElemento<=maximaPulgada){
    
        pilaTeles.tope = pilaTeles.tope + 1;
        pilaTeles.listaTeles[pilaTeles.tope] = pElemento;
        maximaPulgada = pElemento;
        printf("---------->Televisor apilado<----------\n");}
        else {
        printf("---------->No puede ingresar una caja mas grande que la anterior<----------\n");
    }
    } else {
        printf("---------->No hay lugar para mas televisores en la fabrica<----------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }
}


void desapilarTelesYMostrarUltimo() {
    /* Si la pila no esta vacia, puedo eliminar el elemento, baja el tope, y muestra ultimo elemento nuevo*/
    if( !pilaVacia( pilaTeles ) ) {
        pilaTeles.listaTeles[pilaTeles.tope] = 0;
        pilaTeles.tope = pilaTeles.tope - 1;
       
        printf("---------->Ultima television retirada<----------\n");
        printf("Ahora el ultimo televisor es el siguiente\n");
         printf("----------------------------------------------------------------------\n");
            printf("---------->%.2fPulgadas<----------", cima( pilaTeles ));
         printf("\n----------------------------------------------------------------------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    } else {
        printf("---------->No hay mas televisores para eliminar en la fabrica<----------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }
    
    
}


float cima( tPilaTeles pPila ) {
	/* regresa el valor de la cima de la pila */ 
    return pPila.listaTeles[pPila.tope];
}
int cantidadTeles( tPilaTeles pPila )
/* Cuenta la cantidad de elementos en la pila*/ 
 {
	int cantTeles;
	int i;
	for ( i=0; i <= pPila.tope; i++) {
            cantTeles++;
        }
    return cantTeles;
}

void visualizarTelevisoresXPulgada(tPilaTeles pPila){
	/* Muestra televisores mayores en pulgadas, recibe instruccion del usuario */  
	float pulgada = 0;
	int cantidad = 0;
	int i;
	printf("||||||||||||||||||||||||||||||INSTRUCTIVO||||||||||||||||||||||||||||||\n");
	printf("Aqui usted puede buscar televisores por encima de la pulgada que desee\n");
	printf("||||||||||||||||||||||||||||||INSTRUCTIVO||||||||||||||||||||||||||||||\n");
	printf("\nIngrese numero de pulgadas:");
				scanf("%f" , &pulgada) ;
				system("cls");
				printf("Los televisores mayores a %.2fPulgadas: \n", pulgada);
				printf("----------------------------------------------------------------------\n");
				for ( i=0; i <= pPila.tope; i++) {
					if(pPila.listaTeles[i]>pulgada){
					
            printf("%.2fPulgadas | ", pPila.listaTeles[i]);
            cantidad++;}
        }
   			   	printf("\n----------------------------------------------------------------------\n");
   			   	printf("Son un total de %i televisores", cantidad);
        printf("\n");
	
}

	
void visualizarTelevisoresApilados( tPilaTeles pPila )
/* Visualiza el contenido de todos los elementos de la pila */ 
 {
    int i;
    if( !pilaVacia( pPila) ) {
        printf("Televisores en la fabrica: \n");
         printf("----------------------------------------------------------------------\n");
        for ( i=0; i <= pPila.tope; i++) {
            printf("%.2fPulgadas | ", pPila.listaTeles[i]);
        }
        printf("\n----------------------------------------------------------------------\n");
        printf("\n|Seleccione una opcion por favor|\n");
    }else {
         printf("---------->No hay televisores en la fabrica<----------\n");
         printf("\n|Seleccione una opcion por favor|\n");
    }      
}

