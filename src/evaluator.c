#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "../include/evaluator.h"
#include "../include/pila.h"

float obtenerValorVariable(Variable variables[], int total, char nombre) {

    for (int i = 0; i < total; i++) {

        if (variables[i].nombre == nombre) {

            return variables[i].valor;

        }

    }

    printf("Error: Variable '%c' no declarada.\n", nombre);

    return 0.0f;

}

float evaluarPostfija(Cola* postfija, Variable variables[], int totalVariables) {

    Pila* operandos = crearPila();

    while (!colaVacia(postfija)) {

        char token = dequeue(postfija);

        if (token >= 'a' && token <= 'z') {

            float val = obtenerValorVariable(variables, totalVariables, token);

            push(operandos, &val, sizeof(float));

        } 

        else if (esOperador(token)) {

            NodoPila* n2 = operandos->tope;

            float op2 = (float)(n2->dato);

            pop(operandos);

            NodoPila* n1 = operandos->tope;

            float op1 = (float)(n1->dato);

            pop(operandos);

            float res = 0.0f;

            switch (token) {

                case '+':

                    res = op1 + op2;

                    break;

                case '-':

                    res = op1 - op2;

                    break;

                case '*':

                    res = op1 * op2;

                    break;

                case '/':

                    res = (op2 != 0.0f) ? (op1 / op2) : 0.0f;

                    break;

                case '^':

                    res = powf(op1, op2);

                    break;

            }

            push(operandos, &res, sizeof(float));

        }

    }

    float resultadoFinal = 0.0f;

    if (!pilaVacia(operandos)) {

        resultadoFinal = (float)(operandos->tope->dato);

    }

    destruirPila(operandos);

    return resultadoFinal;

}
