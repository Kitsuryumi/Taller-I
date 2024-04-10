#include <stdlib.h>
#include "parser.h"
#include "ABB.h"

int main()
{
    parser par;
    arbolConjuntos arbol;
    comando com;
    conjunto conj1, conj2, conj3;
    String texto;
    crearABB(arbol);
    do
    {
        system("cls");
        system("color 60");
        printf("\n------------------------------------------------");
        printf("\n                     OCN");
        printf("\n------------------------------------------------");
        printf("\nINGRESE UN COMANDO: ");
        strcrear(texto);
        scan(texto);
        crearParser(par);
        cargarParser(par, texto);
        strdestruir(texto);
        com = asignComando(par);
        switch(com)
        {
        case CREAR:
            if(validarCrear(par))
            {
                strcrear(texto);
                darInfo(par, 2, texto);
                if(existeConjunto(arbol, texto))
                {
                    printf("\nERROR! YA EXISTE UN CONJUNTO CON EL NOMBRE DADO");
                }
                else
                {
                    crearConjunto(conj1, texto);
                    agregarConjunto(arbol, conj1);
                    mostrarConjunto(conj1);
                }
                strdestruir(texto);
            }
            else
            {
                if (largoParser(par)!=2)
                {
                    printf("\nERROR! EL COMANDO CREAR SOLO ADMITE UN IDENTIFICADOR");
                }
                if (largoParser(par)>1)
                {
                    strcrear(texto);
                    darInfo(par,2,texto);
                    if(!soloLetras(texto))
                    {
                        printf("\nERROR! EL NOMBRE DEL CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                    }
                    strdestruir(texto);
                }
                printf("\nEJEMPLO: CREAR NOMBRE");
            }
            printf("\n\n");
            system("pause");
            break;

        case AGREGAR:
            if(validarAgregar(par))
            {
                strcrear(texto);
                darInfo(par, 2, texto);
                if(existeConjunto(arbol, texto))
                {
                    darInfo(par, 3, texto);
                    unsigned int valor = atoi(texto);
                    darInfo(par, 2, texto);
                    conj1 = devolverConjunto(arbol, texto);
                    if(existeElementoConjunto(conj1, valor))
                    {
                        printf("ERROR! YA EXISTE %d EN EL CONJUNTO", valor);
                    }
                    else
                    {
                        agregarElementoABB(arbol, texto, valor);
                        conj1 = devolverConjunto(arbol, texto);
                        mostrarConjunto(conj1);
                    }
                }
                else
                {
                    printf("ERROR! NO EXISTE UN CONJUNTO CON EL NOMBRE DADO");
                }
                strdestruir(texto);
            }
            else
            {
                if (largoParser(par)!=3)
                {
                    printf("\nERROR! EL COMANDO AGREGAR SOLO ADMITE UN IDENTIFICADOR Y UN VALOR");
                }
                if (largoParser(par)>1)
                {
                    strcrear(texto);
                    darInfo(par,2,texto);
                    if(!soloLetras(texto))
                    {
                        printf("\nERROR! EL NOMBRE DEL CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                    }
                    strdestruir(texto);
                    if(largoParser(par)>2)
                    {
                        strcrear(texto);
                        darInfo(par,3,texto);
                        if(!soloDigitos(texto))
                        {
                            printf("\nERROR! SOLO SE ADMITEN VALORES NUMERICOS NATURALES");
                        }
                        strdestruir(texto);
                    }
                }
                printf("\nEJEMPLO: AGREGAR NOMBRE 5");
            }
            printf("\n\n");
            system("pause");
            break;

        case IGUALES:
            if(validarIguales(par))
            {
                String aux;
                strcrear(aux);
                strcrear(texto);
                darInfo(par, 2, texto);
                darInfo(par, 3, aux);
                if(existeConjunto(arbol, texto) && existeConjunto(arbol, aux))
                {
                    conj1 = devolverConjunto(arbol, texto);
                    conj2 = devolverConjunto(arbol, aux);
                    if(conjIguales(conj1, conj2))
                    {
                        print(texto);
                        printf(" Y ");
                        print(aux);
                        printf(" SON IGUALES");
                    }
                    else
                    {
                        print(texto);
                        printf(" Y ");
                        print(aux);
                        printf(" NO SON IGUALES");
                    }
                }
                else
                {
                    if(!existeConjunto(arbol, texto))
                    {
                        printf("ERROR! ");
                        print(texto);
                        printf(" NO EXISTE\n");
                    }
                    if(!existeConjunto(arbol, aux))
                    {
                        printf("ERROR! ");
                        print(aux);
                        printf(" NO EXISTE");
                    }
                }
                strdestruir(aux);
                strdestruir(texto);
            }
            else
            {
                if (largoParser(par)!=3)
                {
                    printf("\nERROR! EL COMANDO IGUALES SOLO ADMITE DOS IDENTIFICADORES");
                }
                if (largoParser(par)>1)
                {
                    strcrear(texto);
                    darInfo(par,2,texto);
                    if(!soloLetras(texto))
                    {
                        printf("\nERROR! EL NOMBRE DEL PRIMER CONJUNTO A COMPARAR SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                    }
                    strdestruir(texto);
                    if(largoParser(par)>2)
                    {
                        strcrear(texto);
                        darInfo(par,3,texto);
                        if(!soloLetras(texto))
                        {
                            printf("\nERROR! EL NOMBRE DEL SEGUNDO CONJUNTO A COMPARAR SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                        }
                        strdestruir(texto);
                    }
                }
                printf("\nEJEMPLO: IGUALES PRIMERNOMBRE SEGUNDONOMBRE");
            }
            printf("\n\n");
            system("pause");
            break;

        case UNION:
            if(validarUnion(par))
            {
                String aux1, aux2;
                strcrear(aux1);
                strcrear(aux2);
                strcrear(texto);
                darInfo(par, 2, texto);
                darInfo(par, 3, aux1);
                darInfo(par, 4, aux2);
                if(existeConjunto(arbol, texto) && existeConjunto(arbol, aux1) && !existeConjunto(arbol, aux2))
                {
                    conj1 = devolverConjunto(arbol, texto);
                    conj2 = devolverConjunto(arbol, aux1);
                    crearConjunto(conj3, aux2);
                    unionConjunto(conj1, conj2, conj3);
                    agregarConjunto(arbol, conj3);
                    mostrarConjunto(conj3);
                }
                else
                {
                    if(!existeConjunto(arbol, texto))
                    {
                        printf("ERROR! ");
                        print(texto);
                        printf(" NO EXISTE\n");
                    }
                    if(!existeConjunto(arbol, aux1))
                    {
                        printf("ERROR! ");
                        print(aux1);
                        printf(" NO EXISTE\n");
                    }
                    if(existeConjunto(arbol, aux2))
                    {
                        printf("ERROR! ");
                        print(aux2);
                        printf(" YA EXISTE. NO SE PUEDE GENERAR UN NUEVO CONJUNTO CON UN NOMBRE YA EXISTENTE");
                    }
                }
                strdestruir(aux1);
                strdestruir(aux2);
                strdestruir(texto);
            }
            else
            {
                if (largoParser(par)!=4)
                {
                    printf("\nERROR! EL COMANDO UNION SOLO ADMITE TRES IDENTIFICADORES");
                }
                if (largoParser(par)>1)
                {
                    strcrear(texto);
                    darInfo(par,2,texto);
                    if(!soloLetras(texto))
                    {
                        printf("\nERROR! EL NOMBRE DEL PRIMER CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                    }
                    strdestruir(texto);
                    if(largoParser(par)>2)
                    {
                        strcrear(texto);
                        darInfo(par,3,texto);
                        if(!soloLetras(texto))
                        {
                            printf("\nERROR! EL NOMBRE DEL SEGUNDO CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                        }
                        strdestruir(texto);
                        if(largoParser(par)>3)
                        {
                            strcrear(texto);
                            darInfo(par,4,texto);
                            if(!soloLetras(texto))
                            {
                                printf("\nERROR! EL NOMBRE DEL TERCER CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                            }
                            strdestruir(texto);
                        }
                    }
                }
                printf("\nEJEMPLO: UNION PRIMERNOMBRE SEGUNDONOMBRE TERCERNOMBRE");
            }
            printf("\n\n");
            system("pause");
            break;

        case INTERSECCION:
            if(validarInterseccion(par))
            {
                String aux1, aux2;
                strcrear(aux1);
                strcrear(aux2);
                strcrear(texto);
                darInfo(par, 2, texto);
                darInfo(par, 3, aux1);
                darInfo(par, 4, aux2);
                if(existeConjunto(arbol, texto) && existeConjunto(arbol, aux1) && !existeConjunto(arbol, aux2))
                {
                    conj1 = devolverConjunto(arbol, texto);
                    conj2 = devolverConjunto(arbol, aux1);
                    crearConjunto(conj3, aux2);
                    interseccionConjunto(conj1, conj2, conj3);
                    agregarConjunto(arbol, conj3);
                    mostrarConjunto(conj3);
                }
                else
                {
                    if(!existeConjunto(arbol, texto))
                    {
                        printf("ERROR! ");
                        print(texto);
                        printf(" NO EXISTE\n");
                    }
                    if(!existeConjunto(arbol, aux1))
                    {
                        printf("ERROR! ");
                        print(aux1);
                        printf(" NO EXISTE\n");
                    }
                    if(existeConjunto(arbol, aux2))
                    {
                        printf("ERROR! ");
                        print(aux2);
                        printf(" YA EXISTE. NO SE PUEDE GENERAR UN NUEVO CONJUNTO CON UN NOMBRE YA EXISTENTE");
                    }
                }
                strdestruir(aux1);
                strdestruir(aux2);
                strdestruir(texto);
            }
            else
            {
                if (largoParser(par)!=4)
                {
                    printf("\nERROR! EL COMANDO INTERSECCION SOLO ADMITE TRES IDENTIFICADORES");
                }
                if (largoParser(par)>1)
                {
                    strcrear(texto);
                    darInfo(par,2,texto);
                    if(!soloLetras(texto))
                    {
                        printf("\nERROR! EL NOMBRE DEL PRIMER CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                    }
                    strdestruir(texto);
                    if(largoParser(par)>2)
                    {
                        strcrear(texto);
                        darInfo(par,3,texto);
                        if(!soloLetras(texto))
                        {
                            printf("\nERROR! EL NOMBRE DEL SEGUNDO CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                        }
                        strdestruir(texto);
                        if(largoParser(par)>3)
                        {
                            strcrear(texto);
                            darInfo(par,4,texto);
                            if(!soloLetras(texto))
                            {
                                printf("\nERROR! EL NOMBRE DEL TERCER CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                            }
                            strdestruir(texto);
                        }
                    }
                }
                printf("\nEJEMPLO: INTERSECCION PRIMERNOMBRE SEGUNDONOMBRE TERCERNOMBRE");
            }
            printf("\n\n");
            system("pause");
            break;

        case MOSTRAR:
            if(validarMostrar(par))
            {
                if(ABBvacio(arbol))
                {
                    printf("NO HAY CONJUNTOS QUE MOSTRAR");
                }
                else
                {
                    mostrarABB(arbol);
                }
            }
            else
            {
                printf("ERROR! NO SE ADMITEN PARAMETROS (SOLO EL COMANDO MOSTRAR)");
            }
            printf("\n\n");
            system("pause");
            break;

        case GUARDAR:
            if(validarGuardar(par))
            {
                String aux;
                strcrear(aux);
                strcrear(texto);
                darInfo(par, 2, texto);
                if(existeConjunto(arbol, texto))
                {
                    conj1 = devolverConjunto(arbol, texto);
                    darInfo(par, 3, aux);
                    strcon(aux, ".dat");
                    FILE * f = fopen(aux, "rb");
                    if(f == NULL)
                    {
                        bajarConjunto(conj1, aux);
                        print(texto);
                        printf(" ALMACENADO CORRECTAMENTE EN ");
                        print(aux);
                    }
                    else
                    {
                        char c;
                        print(aux);
                        printf(" YA EXISTE EN DISCO, SOBREESCRIBE? (S/N)?\nOPCION: ");
                        do
                        {
                            fflush(stdin);
                            scanf("%c", &c);
                            if(c == 'S' || c == 's')
                            {
                                bajarConjunto(conj1, aux);
                                print(texto);
                                printf(" ALMACENADO CORRECTAMENTE EN ");
                                print(aux);
                            }
                            else
                            {
                                if(c == 'N' || c == 'n')
                                {
                                    printf("EL CONJUNTO NO FUE GUARDADO. INTENTELO DE NUEVO CON UN NUEVO NOMBRE DE ARCHIVO");
                                }
                                else
                                {
                                    printf("\nERROR! LA OPCION INGRESADA NO ES CORRECTA. SOBREESCRIBE? (S/N)?\nOPCION: ");
                                }
                            }
                        }
                        while(!(c == 'S' || c == 's' || c == 'N' || c == 'n'));
                    }
                    fclose(f);
                }
                else
                {
                    printf("ERROR! ");
                    print(texto);
                    printf(" NO EXISTE\n");
                }
                strdestruir(aux);
                strdestruir(texto);
            }
            else
            {
                if (largoParser(par)!=3)
                {
                    printf("\nERROR! EL COMANDO GUARDAR SOLO ADMITE DOS IDENTIFICADORES");
                }
                if (largoParser(par)>1)
                {
                    strcrear(texto);
                    darInfo(par,2,texto);
                    if(!soloLetras(texto))
                    {
                        printf("\nERROR! EL NOMBRE DEL CONJUNTO A GUARDAR SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                    }
                    strdestruir(texto);
                    if(largoParser(par)>2)
                    {
                        strcrear(texto);
                        darInfo(par,3,texto);
                        if(!soloLetras(texto))
                        {
                            printf("\nERROR! EL NOMBRE DEL ARCHIVO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                        }
                        strdestruir(texto);
                    }
                }
                printf("\nEJEMPLO: GUARDAR NOMBRE ARCHNOMBRE");
            }
            printf("\n\n");
            system("pause");
            break;

        case RECUPERAR:
            if(validarRecuperar(par))
            {
                String aux;
                strcrear(aux);
                darInfo(par, 2, aux);
                strcon(aux, ".dat");
                FILE * f = fopen(aux, "rb");
                if(f == NULL)
                {
                    printf("ERROR! ");
                    print(aux);
                    printf(" NO EXISTE EN DISCO");
                }
                else
                {
                    strcrear(texto);
                    darInfo(par, 3, texto);
                    if(existeConjunto(arbol, texto))
                    {
                        printf("\nERROR! ");
                        print(texto);
                        printf(" YA EXISTE EN MEMORIA");
                    }
                    else
                    {
                        crearConjunto(conj1, texto);
                        levantarConjunto(conj1, aux);
                        agregarConjunto(arbol, conj1);
                        mostrarConjunto(conj1);
                    }
                    strdestruir(texto);
                }
                strdestruir(aux);
                fclose(f);
            }
            else
            {
                if (largoParser(par)!=3)
                {
                    printf("\nERROR! EL COMANDO RECUPERAR SOLO ADMITE DOS IDENTIFICADORES");
                }
                if (largoParser(par)>1)
                {
                    strcrear(texto);
                    darInfo(par,2,texto);
                    if(!soloLetras(texto))
                    {
                        printf("\nERROR! EL NOMBRE DEL ARCHIVO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                    }
                    strdestruir(texto);
                    if(largoParser(par)>2)
                    {
                        strcrear(texto);
                        darInfo(par,3,texto);
                        if(!soloLetras(texto))
                        {
                            printf("\nERROR! EL NOMBRE DEL NUEVO CONJUNTO SOLO PUEDE CONTENER CARACTERES ALFABETICOS");
                        }
                        strdestruir(texto);
                    }
                }
                printf("\nEJEMPLO: RECUPERAR ARCHNOMBRE NOMBRE");
            }
            printf("\n\n");
            system("pause");
            break;

        case SALIR:
            if(validarSalir(par))
            {
                printf("HASTA LA PROXIMA :)");
            }
            else
            {
                printf("ERROR! EL COMANDO SALIR NO ADMITE PARAMETROS");
                com = ERROR;
            }
            printf("\n\n");
            system("pause");
            break;

        case ERROR:
            printf("ERROR! COMANDO INVALIDO");
            printf("\n\n");
            system("pause");
            break;
        }
        destruirParser(par);
    }
    while(com != SALIR);

    destruirABB(arbol);
    resetConjunto(conj1);
    resetConjunto(conj2);
    resetConjunto(conj3);

    return 0;
}
