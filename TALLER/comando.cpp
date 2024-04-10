#include "comando.h"

//Carga de enumerado
void cargaComando (comando &com)
{
    int x;
    printf("Ingrese una opcion: ");
    printf("\n1-Crear");
     printf("\n2-Agregar");
     printf("\n3-Iguales");
     printf("\n4-Union");
     printf("\n5-Interseccion");
     printf("\n6-Mostrar");
     printf("\n7-Guardar");
     printf("\n8-Recuperar");
     printf("\n9-Salir");
     printf("\nOpcion: ");
     scanf("%d", &x);
     switch(x)
     {
         case 1: com = CREAR;
         break;
         case 2: com = AGREGAR;
         break;
         case 3: com = IGUALES;
         break;
         case 4: com = UNION;
         break;
         case 5: com = INTERSECCION;
         break;
         case 6: com = MOSTRAR;
         break;
         case 7: com = GUARDAR;
         break;
         case 8: com = RECUPERAR;
         break;
         case 9: com = SALIR;
         break;
         default: com = ERROR;
         break;
     }


}

//Mostrar comando
void desplegarComando(comando com)
{
    switch(com)
    {
        case CREAR: printf("\nCrear");
        break;
         case AGREGAR: printf("\nAgregar");
        break;
         case IGUALES: printf("\nIguales");
        break;
         case UNION: printf("\nUnion");
        break;
         case INTERSECCION: printf("\nInterseccion");
        break;
         case MOSTRAR: printf("\nMostrar");
        break;
         case GUARDAR: printf("\nGuardar");
        break;
         case RECUPERAR: printf("\nRecuperar");
        break;
        case SALIR: printf("\nSalir");
        break;
        case ERROR: printf("\nERROR!!!");
        break;
    }

}
