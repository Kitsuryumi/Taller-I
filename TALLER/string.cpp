#include "string.h"

//Reserva espacio en memoria para almacenar un char y lo asigna a '\0'
void strcrear(String &str)
{
    str = new char[1];
    *str = '\0';
}

//Destruye el string liberando espacio en memoria
void strdestruir(String &str)
{
    delete []str;
    str = NULL;
}

//Devuelve el largo del string
int strlar(String str)
{
    int j = 0;
    while(str[j] != '\0')
    {
        j++;
    }
    return j;
}

//Muestra el string por pantalla
void print(String str)
{
    int j = 0;
    while(str[j] != '\0')
    {
        printf("%c", str[j]);
        j++;
    }
}

//Dados dos strings, copia el contenido del segundo y lo carga en el primero
void strcop(String &str, String str2)
{
    int j = 0;
    strdestruir(str);
    str = new char[strlar(str2) + 1];
    while(str2[j] != '\0')
    {
       str[j] = str2[j];
       j++;
    }
    str[j] = '\0';
}

//Carga el string
void scan(String &str)
{
    int j = 0;
    String aux = new char[MAX];
    char c;
    fflush(stdin);
    scanf("%c", &c);
    while(c != '\n' && j < MAX - 1)
    {
        aux[j] = c;
        scanf("%c", &c);
        j++;
    }
    aux[j] = '\0';
    strcop(str, aux);
    strdestruir(aux);
}

//Dados dos strings, devuelve TRUE si son iguales
boolean streq(String str, String str2)
{
    boolean eq = TRUE;
    int j = 0;
    if(strlar(str) != strlar(str2))
    {
        eq = FALSE;
    }
    else
    {
        while((str[j] != '\0' && str2[j] != '\0')  && eq == TRUE)
        {
            if(str[j] != str2[j])
            {
                eq = FALSE;
            }
            else
            {
                j++;
            }
        }
    }
    return eq;
}

//Dados dos strings, devuelve TRUE si el primer string es menor alfabéticamente que el segundo
boolean strmen (String str, String str2)
{
    boolean men = TRUE;
    int j = 0;
    if(streq(str, str2))
    {
        men = FALSE;
    }
    else
    {
        while((str[j] != '\0' && str2[j] != '\0') && str[j] == str2[j])
        {
            j++;
        }
        if(str[j] > str2[j])
        {
            men = FALSE;
        }
    }
    return men;
}

//Dados dos strings, concatena el contenido del segundo en el primero
void strcon(String &str, String str2)
{
    int j = 0, k = 0;
    String aux = new char[MAX];
    while(str[j] != '\0' && j < MAX - 1)
    {
        aux[j] = str[j];
        j++;
    }
    while(str2[k] != '\0' && j < MAX - 1)
    {
        aux[j] = str2[k];
        j++;
        k++;
    }
    aux[j] = '\0';
    strcop(str, aux);
    strdestruir(aux);
}

//Dados dos strings, se intercambia el contenido entre ellos
void strswp (String &str, String &str2)
{
    String aux;
    aux = str;
    str = str2;
    str2 = aux;
}

//Dado un string, devuelve TRUE si contiene solo letras
boolean soloLetras(String str)
{
    boolean x = TRUE;
    int i = 0;
    while(str[i] != '\0' && x == TRUE)
    {
        if (str[i] < 'A' || str[i] > 'Z')
        {
            if (str[i] < 'a' || str[i] > 'z')
            {
              x=FALSE;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return x;
}

//Dado un string, devuelve TRUE si contiene solo dígitos
boolean soloDigitos(String str)
{
    boolean x = TRUE;
    int i = 0;
    while(str[i] != '\0' && x == TRUE)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            x = FALSE;
        }
        else
        {
            i++;
        }
    }
    return x;
}

//Dados dos strings y un entero, copia una palabra de origen a str a partir de la posición x
//(Procedimiento auxiliar a la carga del módulo parser)
void copiarPalabra (String & str , String origen , int &x)
{
    String buffer;
    buffer = new char [MAX];
    int j = 0;
    while(origen[x] != '\0' && origen[x] != ' ')
    {
        buffer[j] = origen[x];
        j++;
        x++;
    }
    buffer[j] = '\0';
    strcop(str,buffer);
    strdestruir(buffer);
}

//Dado un string, convierte los caracteres de minusculas a mayusculas
void convertMay(String &str)
{
    int i= 0;
    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] -32;
            i++;
        }
        else
        {
            i++;
        }
    }
}

// Escribe en el archivo los caracteres del string s (incluido '\0')
// PRECONDICION: El archivo viene abierto para escritura.
void bajarString (String s, FILE * f)
{
    int i = 0;
    while(s[i] != '\0')
    {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, f);
}

// Lee desde el archivo los caracteres del string s.
// PRECONDICION: El archivo viene abierto para lectura y existe.
void levantarString (String &s, FILE * f)
{
    int i = 0;
    String aux = new char[MAX];
    fread(&aux[i], sizeof(char), 1, f);
    while(!feof(f) && aux[i] != '\0')
    {
        i++;
        fread(&aux[i], sizeof(char), 1, f);
    }
    strcop(s, aux);
    delete [] aux;
}
