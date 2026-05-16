#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../include/parser.h"
#include "../include/pila.h"


void cargarArchivo(const char* nombreArchivo, Variable variables[], int* totalVariables, char expresion[]) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", nombreArchivo);
        return;
    }

    char linea[MAX_EXPR];
    *totalVariables = 0;
    expresion[0] = '\0';

    while (fgets(linea, sizeof(linea), archivo)) {
        // Remover saltos de línea carriage return
        linea[strcspn(linea, "\r\n")] = 0;
        if (strlen(linea) == 0 || linea[0] == ' ') continue;

        if (strchr(linea, '=') != NULL) {
            char* tokenVar = strtok(linea, "=");
            char* tokenVal = strtok(NULL, "=");
            
            if (tokenVar && tokenVal) {
                while(*tokenVar == ' ') tokenVar++;
                while(*tokenVal == ' ') tokenVal++;
                
                if (*totalVariables < MAX_VARIABLES) {
                    variables[*totalVariables].nombre = tokenVar[0];
                    variables[*totalVariables].valor = atof(tokenVal);
                    (*totalVariables)++;
                }
            }
        } else {
            strcpy(expresion, linea);
        }
    }
    fclose(archivo);
}

int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

Cola* infijaAPostfija(char* expresion) {
    Cola* postfija = crearCola();
    Pila* operadores = crearPila();

    for (int i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (c == ' ' || c == '\n' || c == '\r') continue;

        if (c >= 'a' && c <= 'z') {
            enqueue(postfija, &c, sizeof(char));
        } 
        else if (c == '(') {
            push(operadores, &c, sizeof(char));
        } 
        else if (c == ')') {
            while (!pilaVacia(operadores) && peek(operadores) != '(') {
                char op = pop(operadores);
                enqueue(postfija, &op, sizeof(char));
            }
            if (!pilaVacia(operadores)) {
                pop(operadores); // Eliminar '(' de la pila
            }
        } 
        else if (esOperador(c)) {
            while (!pilaVacia(operadores) && esOperador(peek(operadores))) {
                char topOp = peek(operadores);
                // Si es potencia (asociativo derecha), requiere estrictamente precedencia menor (<)
                if ((c != '^' && precedencia(c) <= precedencia(topOp)) || 
                    (c == '^' && precedencia(c) < precedencia(topOp))) {
                    char op = pop(operadores);
                    enqueue(postfija, &op, sizeof(char));
                } else {
                    break;
                }
            }
            push(operadores, &c, sizeof(char));
        }
    }

    while (!pilaVacia(operadores)) {
        char op = pop(operadores);
        enqueue(postfija, &op, sizeof(char));
    }

    destruirPila(operadores);
    return postfija;
}
