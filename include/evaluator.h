#ifndef __EVALUATOR_H__
#define __EVALUATOR_H__

#include "cola.h"
#include "parser.h"

float obtenerValorVariable(
    Variable variables[],
    int total,
    char nombre
);

float evaluarPostfija(
    Cola* postfija,
    Variable variables[],
    int totalVariables
);

#endif
