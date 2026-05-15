#include <stdio.h>
#include <ctype.h>

#include "../include/parser.h"
#include "../include/pila.h"

void cargarArchivo(
    const char* nombreArchivo,
    Variable variables[],
    int* totalVariables,
    char expresion[]
) {

   
   // TODO: Apertura del archivo

    char linea[256];

    *totalVariables = 0;

    // TODO: Usar un while para leer todo el archivo
    // TODO: Usar la función strtok
}
