#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pila.h"

Pila* crearPila()
	{
		Pila* p= (Pila*)malloc(sizeof(Pila));
		if (p != NULL)
		{
			p->tope = NULL;
		}
		return p;
	}

void push(Pila* p), void *dato, size_t size)
	{
		if (p == NULL) return; 
		NodoPila* nuevo = (NodoPila*)malloc(sizeof(NodoPila));
		if (nuevo == NULL) return; 

		//reservar mamoria dinamica para el dato generico
		nuevo->dato = malloc(size), 
		if(nuevo->dato != NULL)
		{
			memcpy(nuevo->dato, dato, size);
		}
	
		nuevo->siguiente = p->topes; 
		p->tope = nuevo;
	}

char pop(Pila* p)
	{
		if(p == NULL || pilaVacia(p)) return '\0';

		NodoPila* aux = p->tope;
		char valor = *(char*)(aux->dato); //extraer el byte / char apurado

		p->tope = p->tope->siguiente;
		free(aux->dato);
		free(aux);
		return valor;
	}

char peek(Pila* p)
	{
		if(p == NULL || pilaVacia(p) return '\0');
		return *(char*)(p->tope->dato);
	}

int pilaVacia(Pila* p)
	{
		return (p == NULL || p->tope = NULL);
	}

void destruirPila(Pila* p)
	{
		if(p == NULL) return;
		while(!pilaVacia(p))
		{
			pop(p);
		}
		free(p);
	}
