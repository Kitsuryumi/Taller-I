#include "ABB.h"

//Crear ABB
void crearABB(arbolConjuntos &a)
{
    a = NULL;
}

//Dado un ABB, devuelve TRUE si está vacío
boolean ABBvacio(arbolConjuntos a)
{
    boolean vacio = FALSE;
    if(a == NULL)
    {
        vacio = TRUE;
    }
    return vacio;
}

//Dados un ABB y un conjunto, agrega al ABB el conjunto.
//PRECONDICION: existeConjunto(a, conj) == FALSE.
void agregarConjunto(arbolConjuntos &a, conjunto conj)
{
    if(a == NULL)
    {
        a = new nodoABB;
        a->hizq = NULL;
        a->hder = NULL;
        a->info = conj;
    }
    else
    {
        String aux1, aux2;
        strcrear(aux1);
        strcrear(aux2);
        darNombre(conj, aux1);
        darNombre(a->info, aux2);
        if(strmen(aux1, aux2))
        {
            strdestruir(aux1);
            strdestruir(aux2);
            agregarConjunto(a->hizq, conj);
        }
        else
        {
            strdestruir(aux1);
            strdestruir(aux2);
            agregarConjunto(a->hder, conj);

        }
    }
}

//Dado un ABB y un string, devuelve TRUE si existe un conjunto en el ABB con el nombre dado
boolean existeConjunto(arbolConjuntos a, String nombre)
{
    if(a == NULL)
    {
        return FALSE;
    }
    else
    {
        String aux;
        strcrear(aux);
        darNombre(a->info, aux);
        if(streq(nombre, aux))
        {
            strdestruir(aux);
            return TRUE;
        }
        else
        {
            if(strmen(nombre, aux))
            {
                strdestruir(aux);
                existeConjunto(a->hizq, nombre);
            }
            else
            {
                strdestruir(aux);
                existeConjunto(a->hder, nombre);
            }
        }

    }
}

//Dado un ABB, un string y un entero, agrega al conjunto almacenado con el nombre dado el valor de x
//PRECONDICION: existeConjunto(a, nombre) == TRUE
void agregarElementoABB(arbolConjuntos &a, String nombre, unsigned int x)
{
    String aux;
    strcrear(aux);
    darNombre(a->info, aux);
    if(streq(nombre, aux))
    {
        strdestruir(aux);
        agregarElemento(a->info, x);
    }
    else
    {
        if(strmen(nombre, aux))
        {
            strdestruir(aux);
            agregarElementoABB(a->hizq, nombre, x);
        }
        else
        {
            strdestruir(aux);
            agregarElementoABB(a->hder, nombre, x);
        }
    }
}

//Dado un ABB, muestra todos sus elementos
void mostrarABB(arbolConjuntos a)
{
    if(a != NULL)
    {
        mostrarABB(a->hizq);
        mostrarConjunto(a->info);
        printf("\n");
        mostrarABB(a->hder);
    }
}

//Dados un ABB y un string, devuelve el conjunto con el nombre dado
//PRECONDICION: existeConjunto(a, nombre) == TRUE
conjunto devolverConjunto(arbolConjuntos a, String nombre)
{
    conjunto c;
    String aux;
    strcrear(aux);
    darNombre(a->info, aux);
    if(streq(aux, nombre))
    {
        strdestruir(aux);
        c = a->info;
    }
    else
    {
        if(strmen(nombre, aux))
        {
            strdestruir(aux);
            c = devolverConjunto(a->hizq, nombre);
        }
        else
        {
            strdestruir(aux);
            c = devolverConjunto(a->hder, nombre);
        }
    }
    return c;
}

//Destruir árbol
void destruirABB(arbolConjuntos &a)
{
    if(a != NULL)
    {
        destruirABB(a->hizq);
        destruirABB(a->hder);
        delete a;
        a = NULL;
    }
}
