#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>

typedef enum {FALSE, TRUE} boolean;

//Carga boolean
void cargaBoolean (boolean &b);

//Muestra por pantalla el boolean cargado
void despliegueBoolean (boolean b);

#endif // BOOLEAN_H_INCLUDED
