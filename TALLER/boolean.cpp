#include "boolean.h"
//Carga boolean
void cargaBoolean (boolean &b)
{
    int x;
    printf("\nUsuario, ingrese una opcion:");
    printf("\n[0] FALSE\n[1] TRUE");
    printf("\nOPCION: ");
    scanf("%d", &x);
    if(x == 0)
    {
        b = FALSE;
    }
    else
    {
        b = TRUE;
    }
}

//Muestra por pantalla el boolean cargado
void despliegueBoolean (boolean b)
{
    if(b == FALSE)
    {
        printf("\nFALSE");
    }
    else
    {
        printf("\nTRUE");
    }
}
