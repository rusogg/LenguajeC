/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

typedef char tString[30];

typedef struct {
tString fecha;
int codigoLoc;
int postivosPorDia;
}tDatos;

typedef struct nodo {
tDatos datosCovid;
struct nodo * siguiente;
} tListaCovid;

void inicializarListaCovid();
bool listaVacia( tListaCovid * );
void insertarDatos( tDatos );
void visualizarDatos( tListaCovid * );
void calcularCasos( tListaCovid * );
void eliminarK( int k );
void eliminarPrimero();
void mostrarCasosLocalidad();
void mostrarLocalidadMayor();
void solicitarDatos();
void menu();

int vector[10];
char * localidadString( int );

void calcularCasosYMostrar(tListaCovid *);

tListaCovid * listaCovid;

void inicializarListaCovid() {
listaCovid = NULL;
}

bool  listaVacia( tListaCovid * pLista ) {
return ( pLista == NULL );
}

void insertarDatos( tDatos pDatos ) {
/* Se crea el nodo que se va a insertar */
tListaCovid * nuevoNodo;

/* Se asigna memoria al nodo */
nuevoNodo = ( tListaCovid * ) malloc( sizeof( tListaCovid ) );

/* Se asigna el dato recibido al componente correspondiente al elemento */
nuevoNodo->datosCovid = pDatos;

/* Se indica que el primer nodo apunta a NULL */
if ( listaVacia( listaCovid ) ) {

nuevoNodo->siguiente = NULL;

/* Se agrega el nodo a la lista: la lista debe apuntar al  nuevo nodo */
listaCovid = nuevoNodo;
	printf("-------------------------------------------------------------" );
	printf("\n|                Primer dato insertado!                     |\n");
	printf("-------------------------------------------------------------\n" );
	}
else{

/* Como la inserción es por la parte de adelante de la lista, se indica que al nuevo nodo le sigue el resto de la lista */
nuevoNodo->siguiente = listaCovid;

/* Como en el nuevo nodo quedó la lista completa, nos queda indicar que la lista que se recibe como parámetro es igual a nuevo nodo  */
listaCovid = nuevoNodo;
	printf("-------------------------------------------------------------" );
	printf("\n|                  Dato insertado!                          |\n");
	printf("-------------------------------------------------------------\n" );

}
}


void visualizarDatos( tListaCovid * pListaCovid ) {
tListaCovid * aux;
aux = pListaCovid;

if( listaVacia(aux) ) {
	printf("-------------------------------------------------------------\n" );
	printf("|               No hay datos en la lista!                   |\n" );
	printf("-------------------------------------------------------------\n" );
}else {
printf("------------------------------------------------------------" );
printf("\n|Seguimiento de COVID-19 en las localidades de la provincia|\n" );
printf("|DIA\tLOCALIDAD\tPOSITIVOS DETECTADOS               |\n" );
while ( aux != NULL) {
printf( "|%s\t%i.%s\t\t%i                         |\n", aux->datosCovid.fecha, aux->datosCovid.codigoLoc,localidadString( aux->datosCovid.codigoLoc ),aux->datosCovid.postivosPorDia);
aux = aux->siguiente;
}
printf("------------------------------------------------------------\n" );
}
}


char * localidadString( int pCodLocalidad ) {
	char * localidad;
	
	localidad = ( char * ) malloc( sizeof( char * ) );
	
	/* 1.Capital, 2.Richuelo, 3.Santa Ana, 4.Paso de la Patria, 5.San Cosme */	
	switch ( pCodLocalidad ) {
		case 1: strcpy( localidad, "Capital");
				break;
		case 2: strcpy( localidad, "Riachuelo");
				break;
		case 3: strcpy( localidad, "Santa Ana");
				break;
		case 4: strcpy( localidad, "Paso de la Patria");
				break;
		case 5: strcpy( localidad, "San Cosme");
				break;
		default: strcpy( localidad, "error");
	}
	return localidad;
}



void calcularCasos(tListaCovid * pListaCovid ){
tListaCovid * aux;
aux = pListaCovid;
int i;
for (i = 0; i < 5; i++){
vector[i] = 0;
}


while ( aux != NULL) {





vector[aux->datosCovid.codigoLoc-1]=vector[aux->datosCovid.codigoLoc-1]+aux->datosCovid.postivosPorDia;
aux = aux->siguiente;
}





}


void mostrarCasosLocalidad(){
	int i;

	calcularCasos( listaCovid );
	
	printf("              Total de casos por localidad\n" );
	printf("-------------------------------------------------------------\n" );
	for (i = 0; i<5; i++){

	printf("|%d.%s -\t%d\t\t\t\t\t|\n", i+1,localidadString( i+1 ), vector[i]);
	}
	printf("-------------------------------------------------------------\n" );
	
}



void mostrarLocalidadMayor(){
	int i;
	int auxMayor = 0;
	int localidad = 0;

	calcularCasos( listaCovid );
	
	for (i = 0; i <5; i++){
	
	if (vector[i] > auxMayor){
	
	auxMayor = vector[i];
	localidad = i+1; }
}
	printf("-----------------------------------------------------------------------------\n" );
	printf("|               La mayor cantidad positivos fue de %i                       |\n", auxMayor);
	printf("|                 Para el departamento %s                             |\n", localidadString( localidad ));
	printf("-----------------------------------------------------------------------------\n" );
	
	
}


void eliminarPrimero(){
		tListaCovid * datoSuprimir;
	
	datoSuprimir = listaCovid;
	
	listaCovid = listaCovid->siguiente;
	printf("-------------------------------------------------------------\n" );
	printf("|                   Dato eliminado                           |\n" );	
	printf("-------------------------------------------------------------\n" );
	free( datoSuprimir );
	datoSuprimir = NULL;
}


void eliminarK( int k ) {
/* Se debe utilizar una lista auxiliar (aux)  */
tListaCovid * aux;
tListaCovid * nodoSuprimir;
int i;

aux = listaCovid;

/*  Utilizar un bucle para avanzar aux hasta el nodo K-1  si es igual a 1 elimina el primero */
if( k==1 ) {
	
	eliminarPrimero();
	
}
else{

for ( i=1; i < k-1; i++) {
aux = aux->siguiente;
}

/* Se resguarda el nodo que se va a suprimir en una variable auxiliar  */
nodoSuprimir = aux->siguiente;

/* Se indica a qué nodo tiene que apuntar aux: al siguiente del que se va a eliminar  */
aux->siguiente = nodoSuprimir->siguiente;
	printf("-------------------------------------------------------------\n" );
	printf("|                  Dato eliminado                            |\n");                      
	printf("-------------------------------------------------------------\n" );
/* Se libera la memoria del nodo a suprimir que contenía el elemento de la posición K de la lista  */
free( nodoSuprimir );

/* Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir  */
nodoSuprimir = NULL; 
						}
}


void solicitarDatos(){
	tDatos doc;
	char opcion = 's';
	while (opcion !='n'){
	
	printf("Ingrese datosCovid por favor: \n");
	printf("\tFecha(Formato(dd/mm)): ");
	fflush(stdin);
	scanf("%[^\n]s", &doc.fecha);

	printf("\tCodigo de localidad(1.Capital, 2.Richuelo, 3.Santa Ana, 4.Paso de la Patria, 5.San Cosme)");
	scanf("%i", &doc.codigoLoc);

	printf("\tCantidad de positivos del dia:");
	scanf("%i", &doc.postivosPorDia);
	insertarDatos( doc );
	

	printf("Cargar otro? s-n: ");
	opcion=getch();
	system("cls");

	}


}


	int main() {
		system("color 03"); /* Funcion para colores :D*/
		setlocale(LC_ALL, "spanish"); /* Implementación de caracteres del teclado español */
		inicializarListaCovid();
		menu();
	
		return 0;
}

void menu() {
int opcion;
	int k = 0;
	printf("******  Diario digital noticiasYa.com ******\n\n");
	printf("|Seleccione una opcion por favor|\n");
	printf("->1- Cargar datos COVID\n->2- Eliminar Dato\n->3- Visualizar Casos\n");
	printf("->4- Visualizar Totales De Casos Por Localidad\n->5- Visualizar Localidad Con Mayor Cantidad De Casos \n->6- Salir \n");
	printf("|Seleccione una opcion por favor|\n");
	opcion = getch();
	system("cls");
	switch (opcion) {
		case 49:
			solicitarDatos();
   		break;
		case 50:  
			printf("Digite el numero del dato que desea eliminar\n");
			scanf("%i", &k);
  			eliminarK( k );
		break;
		case 51:
			visualizarDatos( listaCovid );
		break;
		case 52:
			mostrarCasosLocalidad();
		break;
		case 53:
			mostrarLocalidadMayor();
        break;
		case 54:
			printf("----------HASTA LA PROXIMA----------"); return ;
        break;
}
	opcion=0;
	printf("|Seleccione una opcion por favor|");
    printf("\n->1-Volver al menu\n->2-Salir\n ");
    printf("|Seleccione una opcion por favor|\n");
    opcion = getch();
    system("cls");
    switch ( opcion ){
   
    	case 49:
			menu();
            break;
        case 50: printf("----------HASTA LA PROXIMA----------"); return;
            break;}
}

