#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Tipos de datos personalizados */

typedef char tString [50];

typedef struct {
	int dni;
	tString nombreApellido;
	tString email;
	int codigoCat;
	float montoAbonado;
	
}tDatos;

typedef struct nodo {
	tDatos data;
	struct nodo * siguiente;
}tPilaEstudiantes;

/* Declaración de prototipos */

void inicializarPila();
bool pilaVacia( tPilaEstudiantes * );
void apilar( tDatos );
void desapilar();
void visualizarElementos( tPilaEstudiantes * );

tPilaEstudiantes * cima2( tPilaEstudiantes * );

/* Declaración de variables */

tPilaEstudiantes * pila;
int totalInscriptos( tPilaEstudiantes * );
int cantProfesionales( tPilaEstudiantes * );
float montoEstudiantes( tPilaEstudiantes * );
float totalRecaudado( tPilaEstudiantes * );

/* Bloque principal */

int main() {
	
	tPilaEstudiantes * datosCima2;
	tDatos datos;
	
	inicializarPila();	
	
	datos.dni = 11111111;
	datos.codigoCat = 1;
	datos.montoAbonado = 200;
	strcpy( datos.nombreApellido, "Gomez VIctor" );
	strcpy( datos.email, "aaa@gmail.com" );
	apilar( datos );
	
	datos.dni = 11111111;
	datos.codigoCat = 2;
	datos.montoAbonado = 350;
	strcpy( datos.nombreApellido, "Vallejos oscar" );
	strcpy( datos.email, "fssss@gmail.com" );
	apilar( datos );
	
	datos.dni = 33333333;
	datos.codigoCat = 3;
	datos.montoAbonado = 350;
	strcpy( datos.nombreApellido, "cosme fulanito" );
	strcpy( datos.email, "ddddddd@gmail.com" );
	apilar( datos );
	
	visualizarElementos( pila );
	printf("El total de inscriptos es %d\n", totalInscriptos( pila ) );	
		printf("La cantidad de profesionales son %d que representa el %.2f%% por sobre el total de inscriptos\n", cantProfesionales( pila ), (float)cantProfesionales( pila )/totalInscriptos( pila  )*100);	
			printf("Monto recaudado de estudiantes %.2f\n", montoEstudiantes( pila ) );	
				printf("Monto recaudado total %.2f\n", totalRecaudado( pila ) );	
	
	/* cómo usar la función cima2 */
	datosCima2 = cima2( pila );
	printf("Elemento en la cima: %d - %s", datosCima2->data.dni, datosCima2->data.nombreApellido );
	
	desapilar();
	
	visualizarElementos( pila );
	
	/* cómo usar la función cima2 */
	datosCima2 = cima2( pila );
	printf("Elemento en la cima: %d - %s", datosCima2->data.dni, datosCima2->data.nombreApellido );
	
	return 0;
}

/* Implementación de funciones */
void inicializarPila() {
	pila = NULL;
	printf("Pila creada!\n");
}

bool pilaVacia( tPilaEstudiantes * pPila ) {
	return ( pPila == NULL );
}

void apilar( tDatos pData ) {
	tPilaEstudiantes * nuevoNodo;
	
	nuevoNodo = ( tPilaEstudiantes * ) malloc( sizeof( tPilaEstudiantes ) );
	
	nuevoNodo->data = pData;
	
	nuevoNodo->siguiente = pila;
	
	pila = nuevoNodo;
	
	printf("\nElemento insertado!\n");
}


void desapilar() {
	tPilaEstudiantes * nodoSuprimir;
	
	if ( !pilaVacia( pila ) ) {
		nodoSuprimir = pila;
	
		pila = pila->siguiente;
		
		printf("\nElemento eliminado: %d - %s\n", nodoSuprimir->data.dni, nodoSuprimir->data.nombreApellido );
	
		free( nodoSuprimir );
		
		nodoSuprimir = NULL;
	} else {
		printf("\nNo hay elementos por eliminar!\n"); 
	}
	

}

void visualizarElementos( tPilaEstudiantes * pPila ) {
	tPilaEstudiantes * aux;
	aux = pPila;
	
	if( pilaVacia( aux ) ) {
		printf("\nNo hay datos para mostrar!\n");
	}else{
		printf("\n*** Elementos apilados ***\n");
		printf("\tID\tDESCRIPCION\n");
		while ( aux != NULL ) {
			printf("\t%d\t%s\n", aux->data.dni, aux->data.nombreApellido );
			aux = aux->siguiente;
		}
	}		
}

tPilaEstudiantes * cima2( tPilaEstudiantes * pPila) {
	return pPila;
}

int totalInscriptos( tPilaEstudiantes * pPila ) {
	tPilaEstudiantes * aux;
	int inscriptos = 0;
	aux = pPila;
	
		while ( aux != NULL ) {
			inscriptos++;
			aux = aux->siguiente;
		}
	return inscriptos;
}

int cantProfesionales( tPilaEstudiantes * pPila ) {
	tPilaEstudiantes * aux;
	int profesionales = 0;
	aux = pPila;
	
		while ( aux != NULL ) {
			if (aux->data.codigoCat == 2){
			profesionales++;}
			aux = aux->siguiente;
		}
	return profesionales;
}

float montoEstudiantes( tPilaEstudiantes * pPila ) {
	tPilaEstudiantes * aux;
	float parcial = 0;
	aux = pPila;
	
		while ( aux != NULL ) {
			if (aux->data.codigoCat == 1){
			parcial = parcial + aux->data.montoAbonado;}
			aux = aux->siguiente;
		}
	return parcial;
}

float totalRecaudado( tPilaEstudiantes * pPila ) {
	tPilaEstudiantes * aux;
	float total = 0;
	aux = pPila;
	
		while ( aux != NULL ) {
			
			total = total + aux->data.montoAbonado;
			aux = aux->siguiente;
		}
	return total;
}


