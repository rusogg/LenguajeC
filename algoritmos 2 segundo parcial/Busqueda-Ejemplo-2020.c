#include <stdio.h>	
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

typedef int tVectorInt [MAX];
int busquedaSecuencial( tVectorInt, int );
int busquedaSecuencialOrdenada( tVectorInt, int );
int busquedaBinaria( tVectorInt, int );
int buscarMayor( tVectorInt );
int buscarMenor( tVectorInt );

void cargarVectorOrdenado( tVectorInt );
void cargarVectorDesordenado( tVectorInt );
void cargarVectorDesordenadoRandom( tVectorInt );
void mostrarElementos( tVectorInt );

tVectorInt v1, v2, v3, v4;

int main() {
	/* Prueba Busqueda Secuencial */
	printf("\n----------------------------------\n");
	printf("*** Prueba Busqueda Secuencial ***\n");
	printf("----------------------------------\n");
	cargarVectorDesordenadoRandom( v1 );	
	mostrarElementos( v1 );
	printf("Posicion del elemento buscado (200): %d\n\n", busquedaSecuencial( v1, 200)); 	
	printf("Posicion del elemento buscado (5): %d\n\n", busquedaSecuencial( v1, 5 )); 
	
	/* Prueba Busqueda Secuencial Ordenada	*/ 	 	
	printf("\n-------------------------------------------\n");
	printf("*** Prueba Busqueda Secuencial Ordenada ***\n");
	printf("-------------------------------------------\n");
 	cargarVectorOrdenado( v2 );
 	mostrarElementos( v2 );
 	printf("Posicion del elemento buscado (30): %d\n\n", busquedaSecuencialOrdenada( v2, 30));
 	printf("Posicion del elemento buscado (35): %d\n\n", busquedaSecuencialOrdenada( v2, 35)); 
 	
 	/* Prueba Busqueda Binaria	*/
 	printf("\n-------------------------------\n");
 	printf("*** Prueba Busqueda Binaria ***\n");
 	printf("-------------------------------\n");
 	cargarVectorOrdenado( v3 );
 	mostrarElementos( v3 );
 	printf("Posicion del elemento buscado (30): %d\n\n", busquedaBinaria( v3, 30));
 	printf("Posicion del elemento buscado (35): %d\n\n", busquedaBinaria( v3, 35)); 
 	
 	/* Prueba Busqueda del valor maximo y minimo elemento*/
 	printf("\n--------------------------------------------\n");
 	printf("*** Prueba Busqueda valor maximo y minimo ***\n");
 	printf("--------------------------------------------\n");
	cargarVectorDesordenadoRandom( v4 );
 	mostrarElementos( v4 ); 	
 	printf("Posicion del mayor elemento: %d\n\n", buscarMayor( v4 ));
 	printf("Posicion del menor elemento: %d\n\n", buscarMenor( v4 )); 
 	 	 	 	
	 return 0;
 }

void cargarVectorOrdenado( tVectorInt pVector ) {
	pVector[0]= 10;
	pVector[1]= 20;
	pVector[2]= 30;
	pVector[3]= 40;
	pVector[4]= 50;	
}

void cargarVectorDesordenado( tVectorInt pVector ) {
	pVector[0]= 80;
	pVector[1]= 2;
	pVector[2]= 25;
	pVector[3]= 14;
	pVector[4]= 78;	
}

void cargarVectorDesordenadoRandom( tVectorInt pVector ) {
	int i;
	int limite_inferior = 0;
	int limite_superior = 10;
	/*  la función srand recibe como parámetro un número que se utilizará 
		como semilla del inicial para las cuentas de los números aleatorios. 
		A esta función sólo debemos llamarla una vez en nuestro programa. */
	srand(time(NULL));
	for ( i=0; i<MAX; i++) {
		/*  numeros aleatorios entre M y N: 
			M + (N+1-M) ó dicho de otra manera:
			limite_inferior + rand() % (limite_superior + 1 - limite_inferior)*/
		pVector[i] = limite_inferior + rand() % (limite_superior + 1 - limite_inferior); 
	}
}

void mostrarElementos( tVectorInt pVector ) {
	int i;
	for ( i=0; i<MAX; i++ ) {
 		printf( "%d\t", pVector[i] );
 	}
 	printf( "\n" );
}

int busquedaSecuencial( tVectorInt pVector, int elem ) {
/* 	result se usará para guardar la posición del 
	valor encontrado ó -1 en caso contrario */
	int result = -1; 
	int i = 0; 
	while( ( pVector[i] != elem ) && ( i != MAX ) ){
		i = i + 1;	
	}	
	if( pVector[i] == elem ) { 
	/*	significa que se ha encontrado el elemento elem, 
		entonces se devuelve la posición del elemento 
		en el vector */
		result = i;
	}
	return result;
}

int busquedaSecuencialOrdenada( tVectorInt pVector, int elem ) {	
/* 	Pre-Condicion: pVector ordenado crecientemente */
/* 	result se usará para guardar la posición del 
	valor encontrado ó -1 en caso contrario */
	int result = -1; 
	int i = 0; 
	while ( ( pVector[i] < elem ) && ( i <= MAX ) ){
		i = i + 1;
	}
	if ( pVector[i] == elem ) {
		/*	significa que se ha encontrado el elemento elem, 
		entonces se devuelve la posición del elemento 
		en el vector */
		result = i;
	}
	return result;
}

int busquedaBinaria( tVectorInt pVector, int elem ) {	
	/* 	Pre-Condicion: pVector ordenado crecientemente 
		Devuelve -1 (si elem no esta en pVector) ó la posición i (si pVector[i] = elem) */
	int extInf, extSup; /* extremos del intervalo */
	int posMed; 		/* posicion central del intervalo */
	bool encontrado;

	/* 	result se usará para guardar la posición del valor encontrado ó -1 en caso contrario */	
	int result = -1; 
	extInf = 0;
	extSup = MAX;
	encontrado = false;
	while ( ( !encontrado ) && ( extSup >= extInf ) ) {
		posMed = ( extSup + extInf ) / 2;
		if ( elem == pVector[posMed] ) {
			encontrado = true;
		} 
		else {
			/* se actualizan los extremos del intervalo */
			if ( elem > pVector[posMed] ) {
				/* se actualiza el extremo inferior del intervalo */
				extInf = posMed + 1;
			} else {
				/* se actualiza el extremo superior del intervalo */
				extSup= posMed - 1;
			}			
		}	
	} 
	
	if ( encontrado ) {
		result = posMed;
	}
	
	return result;
}

/* 	Se busca el mayor valor y se devuelve la posición 
	en la cual se encuentra - Supuesto o prepo */
int buscarMayor( tVectorInt pVector )  {
	int i, mayor, posMayor;
	mayor = 0; 	
	posMayor = -1;
	/* 	también se puede suponer que el mayor es el 
		primer elemento del arreglo:
		mayor = pVector[0]; 	
		posMayor = 0; */		
	for ( i = 0; i<MAX; i++ ) {
		if ( pVector[i] > mayor ) {
			mayor = pVector[i];
			posMayor = i;
		}
	}
	return posMayor;
} 

/* 	Se busca el menor valor y se devuelve la posición 
	en la cual se encuentra - Supuesto o prepo */
int buscarMenor( tVectorInt pVector )  {
	int i, menor, posMenor;
	menor = 99999;
	posMenor = -1;
	/* 	también se puede suponer que el menor es el 
		primer elemento del arreglo:
		menor = pVector[0]; 	
		posMenor = 0; */
	for ( i = 0; i<MAX; i++) {
		if ( pVector[i] < menor ) {
			menor = pVector[i];
			posMenor = i;
		}
	}
	return posMenor;
} 





