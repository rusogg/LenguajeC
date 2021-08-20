#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char tString[25];

typedef struct nodoArbol {
	int contenido;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho; 
}tArbol;

void crearArbolVacio(tArbol **, tString);
bool esArbolVacio(tArbol *);
void insertarNodo(tArbol **, int);
void eliminarNodo(tArbol **, int);
tArbol * buscarMinimo(tArbol *);
void buscarNodo(tArbol *, int);
void mostrarElementosInorden(tArbol *);

void crearArbolVacio(tArbol ** pArbol, tString pNombre) {
	(*pArbol) = NULL;
	printf("Arbol %s creado\n", pNombre);
}

bool esArbolVacio(tArbol * pArbol) {
	return pArbol == NULL;
}

void insertarNodo(tArbol ** pArbol, int pNodo) {
	if (esArbolVacio(*pArbol)) {
		(*pArbol) = (tArbol*) malloc (sizeof(tArbol));
		if ((*pArbol) != NULL) {
			(*pArbol)->contenido = pNodo;
			(*pArbol)->hijoIzquierdo = NULL;
			(*pArbol)->hijoDerecho = NULL;
			printf("Nodo %d insertado al arbol\n", pNodo);
		} else {
			printf("No hay memoria disponible para otro nodo\n");
		}
	} else {
		if (pNodo < (*pArbol)->contenido) {
			insertarNodo(&((*pArbol)->hijoIzquierdo), pNodo);
		} else {
			if (pNodo > (*pArbol)->contenido) {
				insertarNodo(&((*pArbol)->hijoDerecho), pNodo);
			} else {
				printf("El nodo %d ya existe en el arbol, no se puede insertar nuevamente\n", pNodo);
			}
		}
	}
}

void eliminarNodo(tArbol ** pArbol, int pNodo) {
	tArbol * arbolAuxiliar;
	if (!esArbolVacio(*pArbol)) {
		if (pNodo < (*pArbol)->contenido) {
			eliminarNodo(&((*pArbol)->hijoIzquierdo), pNodo);
		} else {
			if (pNodo > (*pArbol)->contenido) {
				eliminarNodo(&((*pArbol)->hijoDerecho), pNodo);
			} else {
				if ((*pArbol)->hijoIzquierdo == NULL) {
					arbolAuxiliar = (*pArbol);
					(*pArbol) = (*pArbol)->hijoDerecho;
					printf("Nodo %d eliminado del arbol\n", pNodo);
					free(arbolAuxiliar);
				} else {
					if ((*pArbol)->hijoDerecho == NULL) {
						arbolAuxiliar = (*pArbol);
						(*pArbol) = (*pArbol)->hijoIzquierdo;
						printf("Nodo %d eliminado del arbol\n", pNodo);
						free(arbolAuxiliar);
					} else {
						arbolAuxiliar = buscarMinimo((*pArbol)->hijoDerecho);
						(*pArbol)->contenido = arbolAuxiliar->contenido;
						eliminarNodo(&((*pArbol)->hijoDerecho), (*pArbol)->contenido);
					}
				}
			}
		}
	} else {
		printf("No existe el nodo %d en el arbol que desea eliminar\n", pNodo);
	}
}

tArbol * buscarMinimo(tArbol * pArbol) {
	if (esArbolVacio(pArbol)) {
		return NULL;
	} else {
		if (!esArbolVacio(pArbol->hijoIzquierdo)) {
			return buscarMinimo(pArbol->hijoIzquierdo);
		} else {
			return pArbol;
		}
	}
}

void buscarNodo(tArbol * pArbol, int pNodo) {
	if(!esArbolVacio(pArbol)) {
		if (pNodo < pArbol->contenido) {
			buscarNodo(pArbol->hijoIzquierdo, pNodo);
		} else {
			if (pNodo > pArbol->contenido) {
				buscarNodo(pArbol->hijoDerecho, pNodo);
			} else {
				if (pNodo == pArbol->contenido) {
					printf("Se ha encontrado el nodo %d buscado en el arbol\n", pNodo);
				}
			}
		}
	} else {
		printf("No se ha encontrado el nodo %d en el arbol\n", pNodo);
	}
}

void mostrarElementosInorden(tArbol * pArbol) {
	if (!esArbolVacio(pArbol)) {
		mostrarElementosInorden(pArbol->hijoIzquierdo);
		printf("%d - ", pArbol->contenido);
		mostrarElementosInorden(pArbol->hijoDerecho);
	}
}

