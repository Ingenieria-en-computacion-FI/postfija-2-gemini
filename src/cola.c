#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cola.h"

Cola* crearCola() {

    Cola* c = (Cola*)malloc(sizeof(Cola));

    if (c != NULL) {

        c->frente = NULL;

        c->final = NULL;

    }

    return c;

}

void enqueue(Cola* c, void *dato, size_t size) {

    if (c == NULL) return;

    NodoCola* nuevo = (NodoCola*)malloc(sizeof(NodoCola));

    if (nuevo == NULL) return;

    nuevo->dato = malloc(size);

    if (nuevo->dato != NULL) {

        memcpy(nuevo->dato, dato, size);

    }

    nuevo->siguiente = NULL;

    if (colaVacia(c)) {

        c->frente = nuevo;

    } else {

        c->final->siguiente = nuevo;

    }

    c->final = nuevo;

}

char dequeue(Cola* c) {

    if (c == NULL || colaVacia(c)) return '\0';

    NodoCola* aux = c->frente;

    char valor = (char)(aux->dato);

    c->frente = c->frente->siguiente;

    if (c->frente == NULL) {

        c->final = NULL;

    }

    free(aux->dato);

    free(aux);

    return valor;

}

int colaVacia(Cola* c) {

    return (c == NULL || c->frente == NULL);

}

void imprimirCola(Cola* c) {

    if (c == NULL) return;

    NodoCola* actual = c->frente;

    while (actual != NULL) {

        printf("%c ", (char)(actual->dato));

        actual = actual->siguiente;

    }

    printf("\n");

}

void destruirCola(Cola* c) {

    if (c == NULL) return;

    while (!colaVacia(c)) {

        dequeue(c);

    }

    free(c);

}
