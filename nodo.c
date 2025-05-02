#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

struct NodoE {
    DatoPtr dato;
    struct NodoE * siguiente;
};

// CONSTRUCTORES
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct NodoE));

    if (nodo == NULL) {
        printf("\nERROR: No se pudo asignar memoria para el nodo.");
        exit(-1);
    }

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

// GET Y SET
DatoPtr getNodoDato(NodoPtr nodo) {
    if (nodo == NULL) {
        printf("\nERROR: El nodo es NULL.");
        return NULL;
    }
    return nodo->dato;
}

NodoPtr getNodoSiguiente(NodoPtr nodo) {
    if (nodo == NULL) {
        printf("\nERROR: El nodo es NULL.");
        return NULL;
    }

    return nodo->siguiente;
}

void setNodoDato(NodoPtr nodo, DatoPtr nuevoDato) {
    if (nodo == NULL) {
        printf("\nERROR: Intentando modificar el dato de un nodo NULL.");
        return;
    }
    nodo->dato = nuevoDato;
}

void setNodoSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente) {
    if (nodo == NULL) {
        printf("\nERROR: Intentando modificar el siguiente de un nodo NULL.");
        return;
    }
    nodo->siguiente = nuevoSiguiente;
}

// MOSTRAR
void mostrarNodo(NodoPtr nodo){
    if (nodo == NULL) {
        printf("[NULL]");
        return;
    }

    printf("{ %d }", *(int*)(getNodoDato(nodo)));
};

void mostrarNodoChar(NodoPtr nodo) {
    if (nodo == NULL) {
        printf("[NULL]");
        return;
    }

    printf("{ %s }", (char*)(getNodoDato(nodo)));
}

void mostrarNodoFloat(NodoPtr nodo) {
    if (nodo == NULL) {
        printf("[NULL]");
        return;
    }

    printf("{ %.2f }", *(float*)(getNodoDato(nodo)));
}

// DESTRUCTOR
void liberarNodo(NodoPtr nodo){
    free(nodo);
};
