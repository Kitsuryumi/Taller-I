#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "comando.h"
#include "string.h"

typedef struct nodoP
{
    String info;
    nodoP * sig;
} nodoParser;

typedef nodoParser * parser;

//Crear lista vacia del parser
void crearParser(parser &par);

//Dados un parser y un string, carga cada nodo del parser con una palabra(cualquier grupo de caracteres entre espacios)
void cargarParser ( parser &par , String texto);

//Muestra el contenido del parser
void mostrarParser(parser par);

//Analiza el primer nodo del parser y devuelve un valor enumerado de tipo comando según lo ingresado
comando asignComando ( parser par );

//Destruir parser
void destruirParser (parser &par);

//Devuelve el largo de la lista parser
int largoParser(parser par);

//Dado una lista parser, un entero y un string, carga el string con el contenido del nodo n del parser
//PRECONDICION: n != 0 && n <= largoParser(par)
void darInfo(parser par, int n, String &str);


//VALIDACION DE COMANDOS :

//Devuelve TRUE si la lista cumple con los requisitos dados del comando CREAR
boolean validarCrear (parser par);

//Devuelve TRUE si la lista cumple con los requisitos dados del comando AGREGAR
boolean validarAgregar (parser par );

//Devuelve TRUE si la lista cumple con los requisitos dados del comando IGUALES
boolean validarIguales (parser par);

//Devuelve TRUE si la lista cumple con los requisitos dados del comando UNION
boolean validarUnion (parser par);

//Devuelve TRUE si la lista cumple con los requisitos dados del comando INTERSECCION
boolean validarInterseccion (parser par);

//Devuelve TRUE si la lista cumple con los requisitos dados del comando MOSTRAR
boolean validarMostrar (parser par);

//Devuelve TRUE si la lista cumple con los requisitos dados por el comando GUARDAR
boolean validarGuardar (parser par);

//Devuelve TRUE si la lista cumple con los requisitos dados por el comando RECUPERAR
boolean validarRecuperar (parser par);

//Devuelve TRUE si la lista cumple con los requisitos dados por el comando SALIR
boolean validarSalir (parser par);


#endif // PARSER_H_INCLUDED
