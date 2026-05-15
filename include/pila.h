#ifndef __PILA_H__
#define __PILA_H__

typedef struct NodoPila {
    void *dato;
    struct NodoPila* siguiente;
} NodoPila;

typedef struct {
    NodoPila* tope;
} Pila;

Pila* crearPila();

void push(Pila* p, void *dato, size_t size);
char pop(Pila* p);
char peek(Pila* p);

int pilaVacia(Pila* p);

void destruirPila(Pila* p);

#endif
