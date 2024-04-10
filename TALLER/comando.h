#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED
#include <stdio.h>

typedef enum {CREAR, AGREGAR, IGUALES, UNION, INTERSECCION, MOSTRAR, GUARDAR, RECUPERAR, SALIR, ERROR} comando;

//Carga de enumerado
void cargaComando (comando &com);

//Mostrar comando
void desplegarComando(comando com);





#endif // COMANDO_H_INCLUDED
