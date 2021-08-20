#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

/* Declaración de tipos de datos personalizados */
typedef int tVertice;

typedef float tPeso;

typedef struct {
	tVertice origen;
	tVertice destino;	
	tPeso peso;
} tArco;

typedef bool conjuntoVertices[N];
typedef tPeso conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
} tGrafoPonderado;

/* Declaración de los prototipos */
void inicializarGrafo( tGrafoPonderado * );
void agregarVertice( tGrafoPonderado *, tVertice ); 
void agregarArco( tGrafoPonderado *, tArco ); 
void borrarVertice( tGrafoPonderado *, tVertice ); 
void borrarArco( tGrafoPonderado *, tArco ); 

int maximoVertice( tGrafoPonderado );
void visualizarMatrizAdyacencia( tGrafoPonderado );
void visualizarMatrizPesos( tGrafoPonderado );
bool existeVertice( tGrafoPonderado, tVertice );

/* Declaración de las variables globales */
tGrafoPonderado grafo;

int main() {
	tArco arco;
					
	inicializarGrafo( &grafo );
	agregarVertice( &grafo, 2 );
	agregarVertice( &grafo, 3 );
	agregarVertice( &grafo, 4);
	
	arco.origen = 3;
	arco.destino = 2;
	arco.peso = 25.0;
	agregarArco( &grafo, arco );
	
	arco.origen = 2;
	arco.destino = 4;
	arco.peso = 7.5;
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 4;
	arco.peso = 33.75;
	agregarArco( &grafo, arco );
	
	visualizarMatrizAdyacencia( grafo );
	visualizarMatrizPesos( grafo );
	
	borrarVertice( &grafo, 2 );
	
	visualizarMatrizAdyacencia( grafo );
	visualizarMatrizPesos( grafo );
	
	borrarArco( &grafo, arco );
	
	visualizarMatrizAdyacencia( grafo );
	visualizarMatrizPesos( grafo );
	
	return 0;
}

void inicializarGrafo( tGrafoPonderado * pGrafo ) {
	int x, y;
	
	for( x=0; x<=N; x++ ) {
		pGrafo->vertices[x] = 0;		
		// ( *pGrafo ).vertices[x] = 0;				
		for( y=0; y<=N; y++ ) {
			pGrafo->arcos[x][y] = 0.0;
		}
	}
}

void agregarVertice( tGrafoPonderado * pGrafo, tVertice pVertice ) {
	( *pGrafo ).vertices[pVertice] = 1;
	printf( "Se agrego el vertice %d\n", pVertice );
} 

void agregarArco( tGrafoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1 ) {
		( *pGrafo ).arcos[pArco.origen][pArco.destino] = pArco.peso;
		printf( "Se agrego el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "No se pudo agregar - Alguno de los vertices no se encuentra activo\n" );
	}		
}

void borrarVertice( tGrafoPonderado * pGrafo, tVertice pVertice )  {
	if( pGrafo->vertices[pVertice] =! 0 ) {
		pGrafo->vertices[pVertice] = 0;
		printf( "Se desactivo el vertice %d\n", pVertice );
	} else {
		printf( "El vertice no se encuentra \n" );
	}
}

void borrarArco( tGrafoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->arcos[pArco.origen][pArco.destino] != 0.0 ) {
		pGrafo->arcos[pArco.origen][pArco.destino] = 0.0;
		printf( "Se desactivo el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "El arco no se encuentra \n" );
	}		
} 

int maximoVertice( tGrafoPonderado pGrafo )  {
	int x, max;
	max = 0;

	for( x=0; x<N; x++ ) {
		if( pGrafo.vertices[x] == 1) {
			max = x;
		}
	}	
	return max;
}

void visualizarMatrizAdyacencia( tGrafoPonderado pGrafo )  {
	int x, y, maxVer;
	bool existeArista = false;
	
	maxVer= maximoVertice( pGrafo );
	
	
	printf( "\n MATRIZ DE ADYACENCIA \n" );
	for( x=1; x<=maxVer; x++ ) {
		for( y=1; y<=maxVer; y++ ) {
			existeArista = ( pGrafo.arcos[x][y] != 0.0 ) && existeVertice( pGrafo, x ) && existeVertice( pGrafo, y );
			if( existeArista ) {
				printf("1\t");
			} else {
				printf("0\t");
			}
		}
		printf("\n");
	}
}

void visualizarMatrizPesos( tGrafoPonderado pGrafo ) {
	int x, y, maxVer;
	bool existeArista = false;
	
	maxVer= maximoVertice( pGrafo );
	
	
	printf( "\n MATRIZ DE PESOS \n" );
	for( x=1; x<=maxVer; x++ ) {
		for( y=1; y<=maxVer; y++ ) {
			existeArista = ( pGrafo.arcos[x][y] != 0.0 ) && existeVertice( pGrafo, x ) && existeVertice( pGrafo, y );
			if( existeArista ) {
				printf( "%.2f\t", pGrafo.arcos[x][y] );
			} else {
				printf( "%.2f\t", 0.0);
			}
		}
		printf("\n");
	}
}

bool existeVertice( tGrafoPonderado pGrafo, tVertice pVertice ) {
	return pGrafo.vertices[pVertice] == 1;
}

