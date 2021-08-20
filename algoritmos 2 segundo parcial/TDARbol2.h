#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char tString[25];

typedef struct {
	float numero;
}tElemento;

typedef struct nodoArbol {
	tElemento contenido;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho; 
}tArbol;

void crearArbolVacio(tArbol **, tString);
bool esArbolVacio(tArbol *);
void insertarNodo(tArbol **, float);
void eliminarNodo(tArbol **, float);
tArbol * buscarMinimo(tArbol *);
void buscarNodo(tArbol *, float);
void mostrarElementosPreorden(tArbol *);
float sumaNodos(tArbol *);

void crearArbolVacio(tArbol ** pArbol, tString pNombre) {
	(*pArbol) = NULL;
	printf("Arbol %s creado\n", pNombre);
}

bool esArbolVacio(tArbol * pArbol) {
	return pArbol == NULL;
}

void insertarNodo(tArbol ** pArbol, float pNodo) {
	if (esArbolVacio(*pArbol)) {
		(*pArbol) = (tArbol*) malloc (sizeof(tArbol));
		if ((*pArbol) != NULL) {
			(*pArbol)->contenido.numero = pNodo;
			(*pArbol)->hijoIzquierdo = NULL;
			(*pArbol)->hijoDerecho = NULL;
			printf("Nodo %.2f insertado al arbol\n", pNodo);
		} else {
			printf("No hay memoria disponible para otro nodo\n");
		}
	} else {
		if (pNodo < (*pArbol)->contenido.numero) {
			insertarNodo(&((*pArbol)->hijoIzquierdo), pNodo);
		} else {
			if (pNodo > (*pArbol)->contenido.numero) {
				insertarNodo(&((*pArbol)->hijoDerecho), pNodo);
			} else {
				printf("El nodo %.2f ya existe en el arbol, no se puede insertar nuevamente\n", pNodo);
			}
		}
	}
}

void eliminarNodo(tArbol ** pArbol, float pNodo) {
	tArbol * arbolAuxiliar;
	if (!esArbolVacio(*pArbol)) {
		if (pNodo < (*pArbol)->contenido.numero) {
			eliminarNodo(&((*pArbol)->hijoIzquierdo), pNodo);
		} else {
			if (pNodo > (*pArbol)->contenido.numero) {
				eliminarNodo(&((*pArbol)->hijoDerecho), pNodo);
			} else {
				if ((*pArbol)->hijoIzquierdo == NULL) {
					arbolAuxiliar = (*pArbol);
					(*pArbol) = (*pArbol)->hijoDerecho;
					printf("Nodo %.2f eliminado del arbol\n", pNodo);
					free(arbolAuxiliar);
				} else {
					if ((*pArbol)->hijoDerecho == NULL) {
						arbolAuxiliar = (*pArbol);
						(*pArbol) = (*pArbol)->hijoIzquierdo;
						printf("Nodo %.2f eliminado del arbol\n", pNodo);
						free(arbolAuxiliar);
					} else {
						arbolAuxiliar = buscarMinimo((*pArbol)->hijoDerecho);
						(*pArbol)->contenido.numero = arbolAuxiliar->contenido.numero;
						eliminarNodo(&((*pArbol)->hijoDerecho), (*pArbol)->contenido.numero);
					}
				}
			}
		}
	} else {
		printf("No existe el nodo %.2f en el arbol que desea eliminar\n", pNodo);
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

void buscarNodo(tArbol * pArbol, float pNodo) {
	if(!esArbolVacio(pArbol)) {
		if (pNodo < pArbol->contenido.numero) {
			buscarNodo(pArbol->hijoIzquierdo, pNodo);
		} else {
			if (pNodo > pArbol->contenido.numero) {
				buscarNodo(pArbol->hijoDerecho, pNodo);
			} else {
				if (pNodo == pArbol->contenido.numero) {
					printf("Se ha encontrado el nodo %.2f buscado en el arbol\n", pNodo);
				}
			}
		}
	} else {
		printf("No se ha encontrado el nodo %.2f en el arbol\n", pNodo);
	}
}

void mostrarElementosPreorden(tArbol * pArbol) {
	if (!esArbolVacio(pArbol)) {
		printf("%.2f - ", pArbol->contenido.numero);
		mostrarElementosPreorden(pArbol->hijoIzquierdo);
		mostrarElementosPreorden(pArbol->hijoDerecho);
	}
}

float sumaNodos(tArbol * pArbol) {
	if (!esArbolVacio(pArbol)) {
		return pArbol->contenido.numero + sumaNodos(pArbol->hijoDerecho) + sumaNodos(pArbol->hijoIzquierdo);
	}
}

