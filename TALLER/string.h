#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"

const int MAX = 80;
typedef char * String;

//Reserva espacio en memoria para almacenar un char y lo asigna a '\0'
void strcrear(String &str);

//Destruye el string liberando espacio en memoria
void strdestruir(String &str);

//Devuelve el largo del string
int strlar(String str);

//Muestra el string por pantalla
void print(String str);

//Dados dos strings, copia el contenido del segundo y lo carga en el primero
void strcop(String &str, String str2);

//Carga el string
void scan(String &str);

//Dados dos strings, devuelve TRUE si son iguales
boolean streq(String str, String str2);

//Dados dos strings, devuelve TRUE si el primer string es menor alfabéticamente que el segundo
boolean strmen (String str, String str2);

//Dados dos strings, concatena el contenido del segundo en el primero
void strcon(String &str, String str2);

//Dados dos strings, se intercambia el contenido entre ellos
void strswp (String &str, String &str2);

//Dado un string, devuelve TRUE si contiene solo letras
boolean soloLetras(String str);

//Dado un string, devuelve TRUE si contiene solo dígitos
boolean soloDigitos(String str);

//Dados dos strings y un entero, copia una palabra de origen a str a partir de la posición x
//(Procedimiento auxiliar a la carga del módulo parser)
void copiarPalabra (String & str , String origen , int &x);

//Dado un string, convierte los caracteres de minusculas a mayusculas
void convertMay(String &str);

// Escribe en el archivo los caracteres del string s (incluido '\0')
// PRECONDICION: El archivo viene abierto para escritura.
void bajarString (String s, FILE * f);

// Lee desde el archivo los caracteres del string s.
// PRECONDICION: El archivo viene abierto para lectura y existe.
void levantarString (String &s, FILE * f);
#endif // STRING_H_INCLUDED
