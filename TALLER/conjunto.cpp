#include "conjunto.h"

//Dados un conjunto y un string, crea un conjunto vacío y le asigna el nombre dado
void crearConjunto (conjunto &nuevo, String nombre)
{
    strcrear(nuevo.nombre);
    strcop(nuevo.nombre, nombre);
    crearListaElementos(nuevo.lista);
}

//Dado un conjunto y un entero, agrega x a conj
//PRECONDICION: existeElementoConjunto(conj, x) == FALSE
void agregarElemento(conjunto &conj, unsigned int x)
{
    agregarElementoLista(conj.lista,x);
}

//Dados dos conjuntos, devuelve TRUE si son iguales
boolean conjIguales(conjunto conj1, conjunto conj2)
{
    return listaIguales(conj1.lista,conj2.lista);
}

//Dados un conjunto y un string, almacena el nombre del conjunto en el string dado
void darNombre(conjunto conj, String &nombre)
{
    strcop(nombre,conj.nombre);
}

//Dado un conjunto y un valor, devuelve TRUE si existe x en conj
boolean existeElementoConjunto(conjunto conj, unsigned int x)
{
    return existeElemento(conj.lista, x);
}

//Dados tres conjuntos, almacena en el tercero el resultado de la unión entre los dos primeros
void unionConjunto(conjunto conj1, conjunto conj2, conjunto &conj3)
{
    unionLista(conj1.lista,conj2.lista,conj3.lista);
}

//Dados tres conjuntos, almacena en el tercero el resultado de la unión entre los dos primeros
void interseccionConjunto(conjunto conj1, conjunto conj2, conjunto &conj3)
{
    interseccionLista(conj1.lista,conj2.lista,conj3.lista);
}

//Mostrar conjunto
void mostrarConjunto(conjunto conj)
{
    print(conj.nombre);
    printf(" = {");
    mostrarLista(conj.lista);
    printf("}");
}

//Dado un conjunto, destruye el nombre y la lista internos, liberando memoria
void resetConjunto(conjunto &conj)
{
    strdestruir(conj.nombre);
    destruirLista(conj.lista);
}

//Bajar conjunto
void bajarConjunto(conjunto conj, String NomArch)
{
    FILE * f = fopen(NomArch , "wb");
    bajarLista(conj.lista,f);
    fclose(f);
}

//Levantar conjunto
//PRECONDICION: El conjunto debe estar creado previamente y el archivo existe en memoria
void levantarConjunto(conjunto &conj, String NomArch)
{
     FILE * f = fopen ( NomArch , "rb");
     levantarLista(conj.lista,f);
     fclose(f);
}
