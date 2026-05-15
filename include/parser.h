#ifndef __PARSER_H__
#define __PARSER_H__

#include "cola.h"

#define MAX_VARIABLES 26
#define MAX_EXPR 256

typedef struct {
    char nombre;
    float valor;
} Variable;

void cargarArchivo(
    const char* nombreArchivo,
    Variable variables[],
    int* totalVariables,
    char expresion[]
);

int precedencia(char op);

int esOperador(char c);

Cola* infijaAPostfija(char* expresion);

#endif
