#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include "conjunto.h"

typedef struct NodoA
{
    conjunto info;
    NodoA *hizq;
    NodoA *hder;
} nodoABB;

typedef nodoABB * arbolConjuntos;


//Crear ABB
void crearABB(arbolConjuntos &a);

//Dado un ABB, devuelve TRUE si está vacío
boolean ABBvacio(arbolConjuntos a);

//Dados un ABB y un conjunto, agrega al ABB el conjunto.
//PRECONDICION: existeConjunto(a, conj) == FALSE.
void agregarConjunto(arbolConjuntos &a, conjunto conj);

//Dado un ABB y un string, devuelve TRUE si existe un conjunto en el ABB con el nombre dado
boolean existeConjunto(arbolConjuntos a, String nombre);

//Dado un ABB, un string y un entero, agrega al conjunto almacenado con el nombre dado el valor de x
//PRECONDICION: existeConjunto(a, nombre) == TRUE
void agregarElementoABB(arbolConjuntos &a, String nombre, unsigned int x);

//Dado un ABB, muestra todos sus elementos
void mostrarABB(arbolConjuntos a);

//Dados un ABB y un string, devuelve el conjunto con el nombre dado
//PRECONDICION: existeConjunto(a, nombre) == TRUE
conjunto devolverConjunto(arbolConjuntos a, String nombre);

//Destruir árbol
void destruirABB(arbolConjuntos &a);



#endif // ABB_H_INCLUDED
