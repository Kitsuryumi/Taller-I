/*boolean listaIguales(listaElementos lista1, listaElementos lista2)
{
    if(cardinalidad(lista1) == cardinalidad(lista2))
    {
        if(listaElementosVacia(lista1))
        {
            return TRUE;
        }
        else
        {
            if(lista1->info != lista2->info)
            {
                if(lista2->sig == NULL)
                {
                    return FALSE;
                }
                else
                {
                    listaIguales(lista1, lista2->sig);
                }
            }
            else
            {
                listaIguales(lista1->sig, lista2->sig);
            }

        }
    }
}
*/
