#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Declaración de tipos de datos */
typedef char tString[25];

typedef struct {
	int id;
	tString descripcion;
} tElem;

typedef struct nodoArbol {
	tElem contenido;
	struct nodoArbol * hijoIzq;
	struct nodoArbol * hijoDer;
} tArbol;

/* Declaración de prototipos */
void crearArbolVacio( tArbol ** );
bool esArbolVacio( tArbol * );
void insertar( tArbol **, tElem );

tArbol * subArbolIzq( tArbol * );
tArbol * subArbolDer( tArbol * );
tElem datoRaiz( tArbol * ); 

void recorrerEnPreorden( tArbol * );
void recorrerEnInorden( tArbol * );
void recorrerEnPostorden( tArbol * );

/* Se busca un nodo con un id determinado */
bool buscarElemento( tArbol *, int );
void buscarElemento2( tArbol *, int );

int cantidadNodosPreOrden( tArbol * );

/* Eliminar un nodo del árbol */
void Eliminar( tArbol **, int );
tArbol * buscar_min( tArbol * );

/* Declaración de variables globales */
tArbol * arbol;

/* Función principal */
int main() {	
	tElem e;
	tArbol * hi, * hd, * hihd;
	
	crearArbolVacio( &arbol );
	printf( "Esta vacio? %d\n", esArbolVacio( arbol ) );
	
	e.id = 24;
	strcpy( e.descripcion, "descripcion 24" );
	insertar( &arbol, e );
		
	printf( "Esta vacio? %d\n", esArbolVacio( arbol ) );
	
	e.id = 72;
	strcpy( e.descripcion, "descripcion 72" );
	insertar( &arbol, e );
	
	e.id = 20;
	strcpy( e.descripcion, "descripcion 20" );
	insertar( &arbol, e );
	
	e.id = 80;
	strcpy( e.descripcion, "descripcion 80" );
	insertar( &arbol, e );
	
	e.id = 50;
	strcpy( e.descripcion, "descripcion 50" );
	insertar( &arbol, e );
	
	e.id = 79;
	strcpy( e.descripcion, "descripcion 79" );
	insertar( &arbol, e );
	
	e.id = 100;
	strcpy( e.descripcion, "descripcion 100" );
	insertar( &arbol, e );
	
	printf( "\n *** Contenido del arbol: Preorden *** \n" );
	recorrerEnPreorden( arbol );
	
	printf( "\n *** Contenido del arbol: Inorden *** \n" );
	recorrerEnInorden( arbol );
	
	printf( "\n *** Contenido del arbol: Postorden *** \n" );
	recorrerEnPostorden( arbol );
	
	e = datoRaiz( arbol );
	printf( "\n Dato raiz: %d-%s \n", e.id, e.descripcion  );
	
	hi = subArbolIzq( arbol );	
	printf( "\n Hijo Izquierdo: %d-%s \n", hi->contenido.id, hi->contenido.descripcion  );
	
	hd = subArbolDer( arbol );	
	printf( "\n Hijo Derecho: %d-%s \n", hd->contenido.id, hd->contenido.descripcion  );
	
	
	hihd = subArbolIzq( hd );
	printf( "\n Hijo izquierdo del hijo Derecho: %d-%s \n", hihd->contenido.id, hihd->contenido.descripcion  );
	
	printf( "\n\n Existe el 100? %d\n", buscarElemento( arbol, 100 ) );
	printf( "\n Existe el 20? %d\n", buscarElemento( arbol, 20 ) );
	
	buscarElemento2( arbol, 24 );
	buscarElemento2( arbol, 91 );
	
	printf( "\n Cantidad de nodos: %d\n", cantidadNodosPreOrden( arbol ) );
	
	Eliminar( &arbol, 72 );
	
	printf( "\n *** Contenido del arbol luego de eliminar: Preorden *** \n" );
	recorrerEnPreorden( arbol );
	printf( "\n Cantidad de nodos: %d\n", cantidadNodosPreOrden( arbol ) );
	
	return 0;
}

/* Implementación de funciones */
void crearArbolVacio( tArbol ** pArbol ) {
	*pArbol = NULL;
	printf( "Arbol inicializado\n" );
}

bool esArbolVacio( tArbol * pArbol ) {
	return pArbol == NULL;
}

void insertar( tArbol ** pArbol, tElem pElem ) {
	if ( esArbolVacio( *pArbol ) ) {
		(*pArbol) =  ( tArbol * ) malloc( sizeof( tArbol ) );
		if( (*pArbol) != NULL ) {
			(*pArbol)->contenido = pElem;
			(*pArbol)->hijoIzq = NULL;
			(*pArbol)->hijoDer = NULL;
		} else {
			printf( "No hay memoria disponible!\n" );
		}
	} else {
		if( pElem.id < (*pArbol)->contenido.id ){
			insertar( &((*pArbol)->hijoIzq), pElem );
		} else {
			if( pElem.id > (*pArbol)->contenido.id ){
				insertar( &((*pArbol)->hijoDer), pElem );
			} else {
				printf( "Valor duplicado! No es posible insertar \n" );
			}
		}
	}
}

tArbol * subArbolIzq( tArbol * pArbol ) {
	return pArbol->hijoIzq;
}

tArbol * subArbolDer( tArbol * pArbol ) {
	return pArbol->hijoDer;
}

tElem datoRaiz( tArbol * pArbol ) {
	return pArbol->contenido;
} 

void recorrerEnPreorden( tArbol * pArbol ) {
	if( pArbol != NULL) {
		printf( "\t%d - %s \n", pArbol->contenido.id, pArbol->contenido.descripcion );
		recorrerEnPreorden( pArbol->hijoIzq );
		recorrerEnPreorden( pArbol->hijoDer );
	}
}

void recorrerEnInorden( tArbol * pArbol ) {
	if( pArbol != NULL) {
		recorrerEnInorden( pArbol->hijoIzq );
		printf( "\t%d - %s \n", pArbol->contenido.id, pArbol->contenido.descripcion );
		recorrerEnInorden( pArbol->hijoDer );
	}
}

void recorrerEnPostorden( tArbol * pArbol ) {
		if( pArbol != NULL) {
		recorrerEnPostorden( pArbol->hijoIzq );		
		recorrerEnPostorden( pArbol->hijoDer );
		printf( "\t%d - %s \n", pArbol->contenido.id, pArbol->contenido.descripcion );
	}
}

bool buscarElemento( tArbol * pArbol, int pId ) {
	if( esArbolVacio( pArbol) ) {
		return false;
	} else {
		if( pId < pArbol->contenido.id ) {
			buscarElemento( pArbol->hijoIzq, pId  );
		} else {
			if( pId > pArbol->contenido.id ) {
				buscarElemento( pArbol->hijoDer, pId  );
			} else {
				return true;
			}
		}
	}	
}

void buscarElemento2( tArbol * pArbol, int pId ) {
	if( esArbolVacio( pArbol) ) {
		printf( " No se encuentra el elemento \n" );
	} else {
		if( pId < pArbol->contenido.id ) {
			buscarElemento2( pArbol->hijoIzq, pId  );
		} else {
			if( pId > pArbol->contenido.id ) {
				buscarElemento2( pArbol->hijoDer, pId  );
			} else {
				printf( " Existe el elemento \n" );
			}
		}
	}	
}

int cantidadNodosPreOrden( tArbol * pArbol ) {
	if ( !esArbolVacio( pArbol ) ) {
		return 1 + cantidadNodosPreOrden( pArbol->hijoIzq ) + cantidadNodosPreOrden( pArbol->hijoDer );
	}
}

/* Eliminar un nodo */
void Eliminar( tArbol ** pArbol, int pId ) {
	tArbol * aux;
	
	if ( esArbolVacio( * pArbol )) {
		/* No existe el nodo que se quiere eliminar */
		printf( "\n\tEl elemento no existe! \n");
	} else {
		if( pId < (*pArbol)->contenido.id ) {
			/* Continuar recorriendo por la izquierda */
			Eliminar( &( (*pArbol)->hijoIzq ), pId );
		} else {
			if( pId > (*pArbol)->contenido.id ) {
			/* Continuar recorriendo por la derecha */
				Eliminar( &( (*pArbol)->hijoDer ), pId );
			} else {
				/* 	Se encontró el nodo por eliminar 
					Antes de eliminar, se debe buscar cuál es
					el elemento que debemos re-enlazar */
					if( (*pArbol)->hijoIzq == NULL ) {
						/* Podríamos suponer que puede tener un hijo derecho*/
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoDer;
						free(aux);
					} else {
						if( (*pArbol)->hijoDer == NULL ) {
							/* Podríamos suponer que puede tener un hijo izquierdo */
							aux = *pArbol;
							*pArbol = (*pArbol)->hijoIzq;
							free(aux);
						} else {
							/* 	el nodo por eliminar tiene 2 hijos,
								se reemplazar con el menor nodo del subarbol derecho */
							aux = buscar_min( (*pArbol)->hijoDer );
							(*pArbol)->contenido = aux->contenido;
							Eliminar( &((*pArbol)->hijoDer), (*pArbol)->contenido.id );
						}
					}
			}
		}
	}	
}

/* Devuelve el nodo del elemento menor */
tArbol * buscar_min( tArbol * pArbol ) {
	if( esArbolVacio( pArbol ) ) {
		return NULL;
	} else {
		if( !esArbolVacio( pArbol->hijoIzq ) ) {
			return buscar_min( pArbol->hijoIzq );
		} else {
		 	return pArbol;
		}
	}
}


