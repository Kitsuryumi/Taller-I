#include "parser.h"

//Crear lista vacia del parser
void crearParser(parser &par)
{
    par = NULL;
}

//Dados un parser y un string, carga cada nodo del parser con una palabra(cualquier grupo de caracteres entre espacios)
void cargarParser ( parser &par , String texto)
{
    int  i= 0;
    parser aux, aux2;
    if(texto[i] == '\0')
    {
        par = new nodoParser;
        strcrear(par->info);
        strcop(par->info, texto);
        par->sig = NULL;
    }
    else
    {
        while(texto[i] != '\0')
        {
            while(texto[i] == ' ')
            {
                i++;
            }
            if(texto[i] != '\0')
            {
                if(par == NULL)
                {
                    par = new nodoParser;
                    strcrear(par->info);
                    copiarPalabra(par->info, texto, i);
                    par->sig = NULL;
                    aux = par;
                }
                else
                {
                    aux2 = new nodoParser;
                    strcrear(aux2->info);
                    copiarPalabra(aux2->info,texto,i);
                    aux2->sig = NULL;
                    aux->sig = aux2;
                    aux = aux->sig;
                }
            }
        }
    }
}

//Muestra el contenido del parser
void mostrarParser(parser par)
{
    if(par != NULL)
    {
        print(par->info);
        printf(" ");
        mostrarParser(par->sig);
    }
}

//Analiza el primer nodo del parser y devuelve un valor enumerado de tipo comando según lo ingresado
comando asignComando ( parser par )
 {
     comando com;
     convertMay(par->info);
     char c = par->info[0];
     switch(c)
     {
    case 'C':
                    if(streq(par->info,"CREAR"))
                    {
                        com = CREAR;
                    }
                    else
                    {
                        com = ERROR;
                    }
                    break;
    case 'A':
                    if(streq(par->info,"AGREGAR"))
                    {
                        com = AGREGAR;
                    }
                    else
                    {
                        com = ERROR;
                    }
                    break;
     case 'I':
                    if(streq(par->info,"IGUALES"))
                    {
                        com = IGUALES;
                    }
                    else
                    {
                        if(streq(par->info,"INTERSECCION"))
                        {
                            com = INTERSECCION;
                        }
                        else
                        {
                            com = ERROR;
                        }
                    }
                    break;
     case 'U':
                    if(streq(par->info,"UNION"))
                    {
                        com = UNION;
                    }
                    else
                    {
                        com = ERROR;
                    }
                    break;
    case 'M':
                    if(streq(par->info,"MOSTRAR"))
                    {
                        com = MOSTRAR;
                    }
                    else
                    {
                        com = ERROR;
                    }
                    break;
     case 'G':
                    if(streq(par->info,"GUARDAR"))
                    {
                        com = GUARDAR;
                    }
                    else
                    {
                        com = ERROR;
                    }
                    break;
     case 'R':
                    if(streq(par->info,"RECUPERAR"))
                    {
                        com = RECUPERAR;
                    }
                    else
                    {
                        com = ERROR;
                    }
                    break;
     case 'S':
                    if(streq(par->info,"SALIR"))
                    {
                        com = SALIR;
                    }
                    else
                    {
                        com = ERROR;
                    }
                    break;
     default: com = ERROR;
     }
     return com;

 }

//Destruir parser
void destruirParser (parser &par)
 {
        if ( par != NULL)
    {
        destruirParser(par->sig);
        delete  par;
        par = NULL;
    }
 }

//Devuelve el largo de la lista parser
int largoParser(parser par)
{
    if (par == NULL)
    {
        return 0;
    }
    else
    {
        return 1+ largoParser(par->sig);
    }

}

//Dado una lista parser, un entero y un string, carga el string con el contenido del nodo n del parser
//PRECONDICION: n != 0 && n <= largoParser(par)
void darInfo(parser par, int n, String &str)
{
    int i;
    for(i = 1; i < n; i++)
    {
        par  = par->sig;
    }
    strcop(str, par->info);
}

//VALIDACION DE COMANDOS :

//Devuelve TRUE si la lista cumple con los requisitos dados del comando CREAR
boolean validarCrear (parser par)
{
    boolean l= FALSE;
    if (largoParser (par)==2)
    {
        if (soloLetras(par->sig->info))
        {
            l=TRUE;
        }
    }
    return l;

}

//Devuelve TRUE si la lista cumple con los requisitos dados del comando AGREGAR
boolean validarAgregar (parser par )
{
    boolean l= FALSE;
    if (largoParser (par)==3)
    {
        if (soloLetras(par->sig->info) && soloDigitos(par->sig->sig->info))
        {
            l=TRUE;
        }
    }
    return l;
}

//Devuelve TRUE si la lista cumple con los requisitos dados del comando IGUALES
boolean validarIguales (parser par)
{
     boolean l= FALSE;
    if (largoParser (par)==3)
    {
        if (soloLetras(par->sig->info) && soloLetras(par->sig->sig->info))
        {
            l=TRUE;
        }
    }
    return l;

}

//Devuelve TRUE si la lista cumple con los requisitos dados del comando UNION
boolean validarUnion (parser par)
{
    boolean l= FALSE;
    if (largoParser (par)==4)
    {
        par=par->sig;
        if (soloLetras(par->info))
        {
            par=par->sig;
            if (soloLetras(par->info))
            {
                par=par->sig;
                if (soloLetras(par->info))
                {
                    l=TRUE;
                }
            }
        }
    }
    return l;
}

//Devuelve TRUE si la lista cumple con los requisitos dados del comando INTERSECCION
boolean validarInterseccion (parser par)
{
    boolean l= FALSE;
    if (largoParser (par)==4)
    {
        par=par->sig;
        if (soloLetras(par->info))
        {
            par=par->sig;

            if (soloLetras(par->info))
            {
                par=par->sig;
                if (soloLetras(par->info))
                {
                    l=TRUE;
                }
            }
        }
    }
    return l;
}

//Devuelve TRUE si la lista cumple con los requisitos dados del comando MOSTRAR
boolean validarMostrar (parser par)
{
    boolean l=FALSE;
    if (largoParser(par)==1)
    {
        l=TRUE;
    }
    return l;
}

//Devuelve TRUE si la lista cumple con los requisitos dados por el comando GUARDAR
boolean validarGuardar (parser par)
{
    boolean l= FALSE;
    if (largoParser (par)==3)
    {
        if (soloLetras(par->sig->info) && soloLetras(par->sig->sig->info))
        {
            l=TRUE;
        }
    }
    return l;
}

//Devuelve TRUE si la lista cumple con los requisitos dados por el comando RECUPERAR
boolean validarRecuperar (parser par)
{
    boolean l= FALSE;
    if (largoParser (par)==3)
    {
        if (soloLetras(par->sig->info) && soloLetras(par->sig->sig->info))
        {
            l=TRUE;
        }
    }
    return l;
}

//Devuelve TRUE si la lista cumple con los requisitos dados por el comando SALIR
boolean validarSalir (parser par)
{
    boolean l=FALSE;
    if (largoParser(par)==1)
    {
        l=TRUE;
    }
    return l;
}



