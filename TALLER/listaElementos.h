#ifndef LISTAELEMENTOS_H_INCLUDED
#define LISTAELEMENTOS_H_INCLUDED
#include "boolean.h"

typedef struct NodoL
{
    unsigned int info;
    NodoL * sig;
} nodolista;

typedef nodolista * listaElementos;

//Crear lista vacía (conjunto)
void crearListaElementos(listaElementos &lista);

//Dado una lista de elementos, devuelve TRUE si es vacía.
boolean listaElementosVacia(listaElementos lista);

//Dados una lista y un entero, devuelve TRUE si x pertenece a la lista
boolean existeElemento(listaElementos lista, unsigned int x);

//Dados una lista y un entero, agrega x a la lista.
//PRECONDICION: existeElemento(lista, x) == FALSE
void agregarElementoLista(listaElementos &lista, unsigned int x);

//Devuelve la cardinalidad de la lista.
int cardinalidad(listaElementos lista);

//Dadas dos listas, devuelve TRUE si son iguales.
boolean listaIguales(listaElementos lista1, listaElementos lista2);

//Procedimiento auxiliar de unionLista
void unionListaAux(listaElementos lista1, listaElementos &un);

//Dadas tres listas, se almacena el resultado de la unión entre las dos primeras en la tercera.
void unionLista(listaElementos lista1, listaElementos lista2, listaElementos &un);

//Dadas tres listas, se almacena el resultado de la intersección entre las dos primeras en la tercera.
void interseccionLista(listaElementos lista1, listaElementos lista2, listaElementos &interseccion);

//Mostrar lista
void mostrarLista(listaElementos lista);

//Destruir lista
void destruirLista(listaElementos &lista);

//Bajar lista.
void bajarLista(listaElementos lista, FILE * f);

//Levantar lista.
void levantarLista(listaElementos &lista, FILE * f);


#endif // LISTAELEMENTOS_H_INCLUDED
