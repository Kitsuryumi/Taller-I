#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED
#include "listaElementos.h"
#include "string.h"

typedef struct
{
    String nombre;
    listaElementos lista;
} conjunto;

//Dados un conjunto y un string, crea un conjunto vacío y le asigna el nombre dado
void crearConjunto (conjunto &nuevo, String nombre);

//Dado un conjunto y un entero, agrega x a conj
//PRECONDICION: existeElementoConjunto(conj, x) == FALSE
void agregarElemento(conjunto &conj, unsigned int x);

//Dados dos conjuntos, devuelve TRUE si son iguales
boolean conjIguales(conjunto conj1, conjunto conj2);

//Dados un conjunto y un string, almacena el nombre del conjunto en el string dado
void darNombre(conjunto conj, String &nombre);

//Dado un conjunto y un valor, devuelve TRUE si existe x en conj
boolean existeElementoConjunto(conjunto conj, unsigned int x);

//Dados tres conjuntos, almacena en el tercero el resultado de la unión entre los dos primeros
void unionConjunto(conjunto conj1, conjunto conj2, conjunto &conj3);

//Dados tres conjuntos, almacena en el tercero el resultado de la unión entre los dos primeros
void interseccionConjunto(conjunto conj1, conjunto conj2, conjunto &conj3);

//Mostrar conjunto
void mostrarConjunto(conjunto conj);

//Dado un conjunto, destruye el nombre y la lista internos, liberando memoria
void resetConjunto(conjunto &conj);

//Bajar conjunto
void bajarConjunto(conjunto conj, String NomArch);

//Levantar conjunto
//PRECONDICION: El conjunto debe estar creado previamente y el archivo existe en memoria
void levantarConjunto(conjunto &conj, String NomArch);


#endif // CONJUNTO_H_INCLUDED
