#include "listaElementos.h"

//Crear lista vacía (conjunto)
void crearListaElementos(listaElementos &lista)
{
    lista = NULL;
}

//Dado una lista de elementos, devuelve TRUE si es vacía.
boolean listaElementosVacia (listaElementos lista)
{
    boolean vacia = FALSE;
    if(lista == NULL)
    {
        vacia = TRUE;
    }
    return vacia;
}

//Dados una lista y un entero, devuelve TRUE si x pertenece a la lista
boolean existeElemento (listaElementos lista, unsigned int x)
{
    if(lista == NULL)
    {
        return FALSE;
    }
    else
    {
        if(x == lista->info)
        {
            return TRUE;
        }
        else
        {
            return existeElemento(lista->sig, x);
        }
    }
}

//Dados una lista y un entero, agrega x a la lista.
//PRECONDICION: existeElemento(lista, x) == FALSE
void agregarElementoLista (listaElementos &lista, unsigned int x)
{
    if(lista == NULL)
    {
        lista = new nodolista;
        lista->info = x;
        lista->sig = NULL;
    }
    else
    {
        agregarElementoLista(lista->sig, x);
    }
}

//Devuelve la cardinalidad de la lista.
int cardinalidad (listaElementos lista)
{
    if(lista == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + (cardinalidad(lista->sig));
    }
}

//Dadas dos listas, devuelve TRUE si son iguales.
boolean listaIguales(listaElementos lista1, listaElementos lista2)
{
    boolean iguales;
    listaElementos aux = lista2;
    if(cardinalidad(lista1) == cardinalidad(lista2))
    {
        if(listaElementosVacia(lista1))
        {
            iguales = TRUE;
        }
        else
        {
            iguales = TRUE;
            do
            {
                if(!existeElemento(lista1, aux->info))
                {
                    iguales = FALSE;
                }
                else
                {
                    aux = aux->sig;
                }
            }
            while(aux != NULL && iguales == TRUE);
        }
    }
    else
    {
        iguales = FALSE;
    }
    return iguales;
}

//Procedimiento auxiliar de unionLista
void unionListaAux(listaElementos lista1, listaElementos &un)
{
    if(lista1 != NULL)
    {
        if(!existeElemento(un, lista1->info))
        {
            agregarElementoLista(un, lista1->info);

        }

        unionListaAux(lista1->sig, un);
    }
}

//Dadas tres listas, se almacena el resultado de la unión entre las dos primeras en la tercera.
void unionLista(listaElementos lista1, listaElementos lista2, listaElementos &un)
{
    unionListaAux(lista1, un);
    unionListaAux(lista2, un);
}

//Dadas tres listas, se almacena el resultado de la intersección entre las dos primeras en la tercera.
void interseccionLista(listaElementos lista1, listaElementos lista2, listaElementos &interseccion)
{
    if(listaIguales(lista1,lista2))
    {
        unionListaAux(lista1, interseccion);
    }
    else
    {
        if(!listaElementosVacia(lista1)&& !listaElementosVacia(lista2))
        {
            listaElementos aux = lista2;
            do
            {
                if(existeElemento(lista1, aux->info))
                {
                    agregarElementoLista(interseccion,aux->info);
                }
                aux = aux->sig;
            }
            while(aux != NULL);
        }
    }
}

//Mostrar lista
void mostrarLista(listaElementos lista)
{
    if(lista == NULL)
    {
        printf(" ");
    }
    else
    {
        if(lista != NULL)
        {
            printf("%d", lista->info);
            if(lista->sig != NULL)
            {
                printf(" ");
                mostrarLista(lista->sig);
            }
        }
    }
}

//Destruir lista
void destruirLista(listaElementos &lista)
{
    if ( lista != NULL)
    {
        destruirLista(lista->sig);
        delete  lista;
        lista = NULL;
    }

}

//Bajar lista
//PRECONDICION: el archivo debe estar abierto en modo wb.
void bajarLista(listaElementos lista, FILE * f)
{
    while(lista != NULL)
    {
        fwrite(&lista->info, sizeof(unsigned int), 1, f);
        lista = lista->sig;
    }
}

//Levantar lista.
//PRECONDICION: el archivo debe estar abierto en modo rb y existir.
void levantarLista(listaElementos &lista, FILE * f)

{
    unsigned int n;
    fread(&n,sizeof (unsigned int),1,f);
    while(!feof(f))
    {
        agregarElementoLista(lista, n);
        fread(&n, sizeof(unsigned int), 1, f);
    }

}
